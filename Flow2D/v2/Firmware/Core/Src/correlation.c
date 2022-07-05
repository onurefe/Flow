#include "correlation.h"
#include "config.h"
#include "interpolate.h"

/* Private constants -------------------------------------------------------*/
#define INTEGRATION_INTERVAL (((float)RESP_FUNC_PERIOD_STOP - \
                               RESP_FUNC_PERIOD_START) /      \
                              CORRELATION_INTEGRAL_INTERVALS)

#define FPERIOD_START ((float)RESP_FUNC_PERIOD_START)
#define FSAMPLING_INTERVAL ((float)RESP_FUNC_SAMPLING_INTERVAL)
#define SUMMANDS (CORRELATION_INTERVAL_SLICING * (RESP_FUNC_SAMPLE_POINTS - 1) + 1)

static void extend(float position, Complex_t *y, uint16_t len, Complex_t *r);

/**
 * @brief Calculates the correlation score between two arrays. It searches the array y2 in array y1.
 * 
 */
float Correlation_GetScore(Complex_t *y1, Complex_t *y2, float scale_shift)
{
    Complex_t mean = {.real = 0.0f, .img = 0.0f};
    Complex_t yc1, yc2;
    Complex_t diff;
    uint32_t num_of_sums = 0;

    for (uint32_t i = 0; i < SUMMANDS; i++)
    {
        float period;
        float y1_pos;
        float y2_pos;

        period = qfp_fadd(FPERIOD_START, qfp_fmul(qfp_uint2float(i), (FSAMPLING_INTERVAL / CORRELATION_INTERVAL_SLICING)));
        y1_pos = qfp_fdiv(qfp_fsub(period, FPERIOD_START), FSAMPLING_INTERVAL);
        y2_pos = qfp_fdiv(qfp_fsub(qfp_fadd(period, qfp_fmul(scale_shift, period)), FPERIOD_START), FSAMPLING_INTERVAL);

        // -1 > y2_pos, out of range. skip to next iteration.
        if (-1.0f > y2_pos)
        {
            continue;
        }

        // y2_pos > sample_points, out of range, break the loop.
        if (y2_pos > (float)RESP_FUNC_SAMPLE_POINTS)
        {
            break;
        }

        extend(y1_pos, y1, (RESP_FUNC_SAMPLE_POINTS - 1), &yc1);
        extend(y2_pos, y2, (RESP_FUNC_SAMPLE_POINTS - 1), &yc2);

        Complex_Normalize(&yc1, &yc1);
        Complex_Normalize(&yc2, &yc2);

        Complex_DividePhasors(&yc1, &yc2, &diff);

        mean.real = qfp_fadd(diff.real, mean.real);
        mean.img = qfp_fadd(diff.img, mean.img);
        num_of_sums++;

        if (num_of_sums == (int)((float)CORRELATION_INTERVAL_SLICING * CORRELATION_WINDOWED_SAMPLES - 1))
        {
            break;
        }
    }

    mean.real = qfp_fdiv(mean.real, ((float)num_of_sums));
    mean.img = qfp_fdiv(mean.img, ((float)num_of_sums));

    float score;
    score = qfp_fmul(CORRELATION_SCORE_NORM_WEIGHT, Complex_Norm(&mean));
    score = qfp_fadd(score, qfp_fmul(CORRELATION_SCORE_PHASE_WEIGHT, mean.real));

    return score;
}

void extend(float position, Complex_t *y, uint16_t maxidx, Complex_t *r)
{
    float xdiff[2] = {1.0f, 1.0f};
    float yrealdiff[2];
    float yimgdiff[2];
    float leap;
    int idx;

    idx = qfp_float2int(position);
    if (idx < 1)
    {
        idx = 1;
    }
    else if (idx > (maxidx - 1))
    {
        idx = maxidx - 1;
    }

    leap = qfp_fsub(position, qfp_int2float(idx));

    yrealdiff[0] = qfp_fsub(y[idx].real, y[idx - 1].real);
    yrealdiff[1] = qfp_fsub(y[idx + 1].real, y[idx].real);
    yimgdiff[0] = qfp_fsub(y[idx].img, y[idx - 1].img);
    yimgdiff[1] = qfp_fsub(y[idx + 1].img, y[idx].img);

    r->real = qfp_fadd(y[idx - 1].real, Interpolate_SecondOrderInterpolate(xdiff, yrealdiff, leap));
    r->img = qfp_fadd(y[idx - 1].img, Interpolate_SecondOrderInterpolate(xdiff, yimgdiff, leap));
}