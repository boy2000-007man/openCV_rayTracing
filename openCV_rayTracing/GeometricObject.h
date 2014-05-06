#pragma once
#include "sdk.h"
namespace sdk {
class GeometricObject {
public:
    FLOAT reflection_coefficient,
          refraction_coefficient,
          refraction_index,
          transparency;
    virtual IntersectionPoint* ray_intersection_ptr(const Ray &ray) const = 0;
    GeometricObject(void);
    virtual ~GeometricObject(void) = 0;
};
}