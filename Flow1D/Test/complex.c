#include "math.h"
#include "complex.h"
#include "fast_math.h"

void Complex_Divide(Complex_t *a, Complex_t *b, Complex_t *r)
{
    Complex_t bc;
    
    Complex_Conjugate(b, &bc);
    Complex_Multiply(a, &bc, r);

    float normbsqr;
    normbsqr = b->real * b->real + b->img * b->img;
    
    r->real = r->real / normbsqr;
    r->img = r->img / normbsqr; 
}

float Complex_Norm(Complex_t *a)
{
    return sqrtf(a->real * a->real + a->img * a->img);
}

void Complex_Multiply(Complex_t *a, Complex_t *b, Complex_t *r)
{
    float temp;
    temp = a->real * b->real - a->img * b->img;
    r->img = a->real * b->img + a->img * b->real;
    r->real = temp;
}

void Complex_Conjugate(Complex_t *a, Complex_t *r)
{
    r->real = a->real;
    r->img = -a->img;    
}

void Complex_Add(Complex_t *a, Complex_t *b, Complex_t *r)
{
    r->real = a->real + b->real;
    r->img = a->img + b->img;
}

void Complex_Subtract(Complex_t *a, Complex_t *b, Complex_t *r)
{
    r->real = a->real - b->real;
    r->img = a->img - b->img;
}

float Complex_Argument(Complex_t *a)
{
	return FastMath_Atan2(a->img, a->real);
}