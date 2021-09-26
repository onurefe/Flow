#include "qfplib.h"
#include "complex.h"

void Complex_Divide(Complex_t *a, Complex_t *b, Complex_t *r)
{
    Complex_t bc;
    
    Complex_Conjugate(b, &bc);
    Complex_Multiply(a, &bc, r);

    float normbsqr;
    normbsqr = qfp_fadd(qfp_fmul(b->real, b->real), qfp_fmul(b->img, b->img));
    
    r->real = qfp_fdiv(r->real, normbsqr);
    r->img = qfp_fdiv(r->img, normbsqr); 
}

void Complex_Multiply(Complex_t *a, Complex_t *b, Complex_t *r)
{
    float temp;
    temp = qfp_fsub(qfp_fmul(a->real, b->real), qfp_fmul(a->img, b->img));
    r->img = qfp_fadd(qfp_fmul(a->real, b->img), qfp_fmul(a->img, b->real));
    r->real = temp;
}

void Complex_Normalize(Complex_t *a, Complex_t *r)
{
    float norm;
    norm = qfp_fadd(qfp_fmul(a->real, a->real), qfp_fmul(a->img, a->img));

    r->real = a->real / norm;
    r->img = a->img / norm;
}

void Complex_Conjugate(Complex_t *a, Complex_t *r)
{
    r->real = a->real;
    r->img = -a->img;    
}

void Complex_Add(Complex_t *a, Complex_t *b, Complex_t *r)
{
    r->real = qfp_fadd(a->real, b->real);
    r->img = qfp_fadd(a->img, b->img);
}

void Complex_Subtract(Complex_t *a, Complex_t *b, Complex_t *r)
{
    r->real = qfp_fsub(a->real, b->real);
    r->img = qfp_fsub(a->img, b->img);
}

float Complex_Argument(Complex_t *a)
{
    return qfp_fatan2(a->img, a->real);
}