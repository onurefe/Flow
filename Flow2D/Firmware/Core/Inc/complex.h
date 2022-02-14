#ifndef __COMPLEX_H
#define __COMPLEX_H

#include "generic.h"
#include "fast_math.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    float real;
    float img;
} Complex_t;

inline void Complex_Conjugate(Complex_t *a, Complex_t *r)
{
    r->real = a->real;
    r->img = -a->img;    
}

inline void Complex_Multiply(Complex_t *a, Complex_t *b, Complex_t *r)
{
    float temp;
    temp = qfp_fsub(qfp_fmul(a->real, b->real), qfp_fmul(a->img, b->img));
    r->img = qfp_fadd(qfp_fmul(a->real, b->img), qfp_fmul(a->img, b->real));
    r->real = temp;
}

inline void Complex_Normalize(Complex_t *a, Complex_t *r)
{
    float norm;
    norm = qfp_fsqrt(qfp_fadd(qfp_fmul(a->real, a->real), qfp_fmul(a->img, a->img)));
    
    r->real = qfp_fdiv(a->real, norm);
    r->img = qfp_fdiv(a->img, norm);
}

inline float Complex_Norm(Complex_t *a)
{
    return qfp_fsqrt(qfp_fadd(qfp_fmul(a->real, a->real), qfp_fmul(a->img, a->img)));
}

inline void Complex_Add(Complex_t *a, Complex_t *b, Complex_t *r)
{
    r->real = qfp_fadd(a->real, b->real);
    r->img = qfp_fadd(a->img, b->img);
}

inline void Complex_Subtract(Complex_t *a, Complex_t *b, Complex_t *r)
{
    r->real = qfp_fsub(a->real, b->real);
    r->img = qfp_fsub(a->img, b->img);
}

inline float Complex_Argument(Complex_t *a)
{
    return qfp_fatan2(a->img, a->real);
}

inline float Complex_FastArgument(Complex_t *a)
{   
    return FastMath_Atan2(a->img, a->real);
}

inline void Complex_DivideWithoutNormalizing(Complex_t *a, Complex_t *b, Complex_t *r)
{
    Complex_t bc;
    
    Complex_Conjugate(b, &bc);
    Complex_Multiply(a, &bc, r);
}

inline void Complex_Divide(Complex_t *a, Complex_t *b, Complex_t *r)
{
    Complex_t bc;
    
    Complex_Conjugate(b, &bc);
    Complex_Multiply(a, &bc, r);

    float normbsqr;
    normbsqr = Complex_Norm(b);
    
    r->real = qfp_fdiv(r->real, normbsqr);
    r->img = qfp_fdiv(r->img, normbsqr); 
}

#ifdef __cplusplus
}
#endif

#endif