#pragma once
#include "geometricobject.h"
namespace sdk {
class GOPlane :
    public GeometricObject
{
public:
    Vertex P;
    Vector n;
    BGRa bgra;
    IntersectionPoint* ray_intersection_ptr(const Ray &ray) const;
    GOPlane(void);
    ~GOPlane(void);
};
}