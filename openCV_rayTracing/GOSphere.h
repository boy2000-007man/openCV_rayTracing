#pragma once
#include "geometricobject.h"
namespace sdk {
class GOSphere :
    public GeometricObject {
public:
    Vertex Pc;
    FLOAT r;
    BGRa bgra;
    IntersectionPoint* ray_intersection_ptr(const Ray &ray) const;
    GOSphere(void);
    ~GOSphere(void);
};
}