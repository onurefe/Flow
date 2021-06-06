#ifndef __COMPLEX_H
#define __COMPLEX_H

typedef struct
{
    float real;
    float img;
} Complex_t;

extern void Complex_Divide(Complex_t *a, Complex_t *b, Complex_t *r);
extern float Complex_Norm(Complex_t *a);
extern void Complex_Multiply(Complex_t *a, Complex_t *b, Complex_t *r);
extern void Complex_Conjugate(Complex_t *a, Complex_t *r);
extern void Complex_Add(Complex_t *a, Complex_t *b, Complex_t *r);
extern void Complex_Subtract(Complex_t *a, Complex_t *b, Complex_t *r);
extern float Complex_Argument(Complex_t *a);
#endif