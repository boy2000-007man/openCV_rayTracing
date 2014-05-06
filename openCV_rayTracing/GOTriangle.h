#pragma once
#include "GOPlane.h"
namespace sdk {
class GOTriangle :
    public GOPlane {
public:
    Vertex P0, P1, P2;
    IntersectionPoint* ray_intersection_ptr(const Ray &ray) const;
    GOTriangle(void);
    ~GOTriangle(void);
};
}

