/* 
 * Adaptado  por Mariano M. Chouza de 'GraphicsGems.h'
 * Version 1.0 - Andrew Glassner
 * from "Graphics Gems", Academic Press, 1990
 */

#ifndef MATH3D_H
#define MATH3D_H

#include <numeric>
#include "mathconstants.h"

struct Point3 {
	double x, y, z;
};

typedef Point3 Vector3;


Vector3* V3Normalize(Vector3* v);
double V3Length(const Vector3* a);
double V3Dot(const Vector3* a, const Vector3* b);
Vector3* V3ScalarMult(Vector3* a, double lambda);
Vector3* V3Add(const Vector3* a, const Vector3* b, Vector3* c);
Vector3* V3Sub(const Vector3* a, const Vector3* b, Vector3* c);
Vector3* V3Cross(const Vector3* a, const Vector3* b, Vector3* c);


double intersectRaySphere(const Point3& rayO, const Vector3& rayD,
    Point3 sphereC, double sphereR);

template<typename T>
T sqr(const T& a) {
    return a * a;
}

template<typename T>
T random(T l, T h) {
    return (T(rand()) / RAND_MAX) * (h - l) + l;
}

#endif
