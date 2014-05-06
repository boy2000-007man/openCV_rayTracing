#pragma once
#include "goplane.h"
namespace sdk {
class GOPolygon :
    public GOPlane {
public:
    std::vector<Vertex> vertex_vec;
    IntersectionPoint* ray_intersection_ptr(const Ray &ray) const;
    GOPolygon(void);
    ~GOPolygon(void);
};
}