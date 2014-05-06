#pragma once
#include "geometricobject.h"
namespace sdk {
class GOBox :
    public GeometricObject {
public:
    Vertex P;
    std::vector<Vector> abc_vec;
    IntersectionPoint* ray_intersection_ptr(const Ray &ray) const;
    GOBox(void);
    ~GOBox(void);
};
}