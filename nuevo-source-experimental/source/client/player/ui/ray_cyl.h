#ifndef RAY_CYL_H
#define RAY_CYL_H

#include "math3d.h"

bool intcyl(Point3* raybase, Vector3* raycos, Point3* base, Vector3* axis, 
			double radius, double* in, double* out);

bool clipobj(Point3* raybase, Vector3* raycos, Plane* bot, Plane* top, 
			 double* objin, double* objout, int* surfin, int* surfout);

#endif
