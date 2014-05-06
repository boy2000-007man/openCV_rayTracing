#pragma once
#include "geometricobject.h"
namespace sdk {
class GOScene :
    public GeometricObject {
public:
    std::vector<GeometricObject*> geometric_object_ptr_vec;
    IntersectionPoint* ray_intersection_ptr(const Ray &ray) const;
    GOScene(void);
    ~GOScene(void);
};
}