/* Modificado por Mariano M. Chouza */
/* 
2d and 3d Vector C Library 
by Andrew Glassner
from "Graphics Gems", Academic Press, 1990
*/

#include <math.h>
#include <stdlib.h>
#include "math3d.h"

/* Suma los vectores a y b, poniendo el resultado en c */
Vector3* V3Add(const Vector3* a, const Vector3* b, Vector3* c)
{
	c->x = a->x + b->x;
	c->y = a->y + b->y;
	c->z = a->z + b->z;
	return c;
}

/* Resta los vectores a y b, poniendo el resultado en c */
Vector3* V3Sub(const Vector3* a, const Vector3* b, Vector3* c)
{
	c->x = a->x - b->x;
	c->y = a->y - b->y;
	c->z = a->z - b->z;
	return c;
}

/* Multiplica un vector por un escalar */
Vector3* V3ScalarMult(Vector3* a, double lambda)
{
	a->x *= lambda;
	a->y *= lambda;
	a->z *= lambda;
	return a;
}

/* returns squared length of input vector */	
double V3SquaredLength(const Vector3* a) 
{
	return((a->x * a->x)+(a->y * a->y)+(a->z * a->z));
}

/* returns length of input vector */
double V3Length(const Vector3* a) 
{
	return(sqrt(V3SquaredLength(a)));
}

/* normalizes the input vector and returns it */
Vector3* V3Normalize(Vector3* v) 
{
	double len = V3Length(v);
	if (len != 0.0) { v->x /= len;  v->y /= len; v->z /= len; }
	return(v);
}

/* return the dot product of vectors a and b */
double V3Dot(const Vector3* a, const Vector3* b)
{
	return((a->x*b->x)+(a->y*b->y)+(a->z*b->z));
}

/* return the cross product c = a cross b */
Vector3* V3Cross(const Vector3* a, const Vector3* b, Vector3* c)
{
	c->x = (a->y*b->z) - (a->z*b->y);
	c->y = (a->z*b->x) - (a->x*b->z);
	c->z = (a->x*b->y) - (a->y*b->x);
	return(c);
}

double intersectRaySphere(const Point3& rayO, const Vector3& rayD, 
    Point3 sphereC, double sphereR) {
    Vector3 dst;
    V3Sub(&rayO, &sphereC, &dst);
    
    double b = V3Dot(&dst, &rayD);
    double c = V3Dot(&dst, &dst) - sphereR;
    double d = sqr(b) - c;
    
    return (d > 0.0) ? -b - sqrt(d) : std::numeric_limits<double>::infinity();
}

