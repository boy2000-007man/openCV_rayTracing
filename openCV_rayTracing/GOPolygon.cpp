#include "stdafx.h"
#include "GOPolygon.h"
using namespace sdk;

IntersectionPoint* GOPolygon::ray_intersection_ptr(const Ray &ray) const {
    IntersectionPoint *res = GOPlane::ray_intersection_ptr(ray);
    if (!res)
        return res;
    int X, Y;
    if (!equal0(n[0])) {
        X = 1;
        Y = 2;
    } else if (!equal0(n[1])) {
        X = 0;
        Y = 2;
    } else {
        X = 0;
        Y = 1;
    }
    const Vertex &Ro = ray.first;
    const Vector &Rd = ray.second;
    Vertex p = Ro + (res->t_vec[0]) * Rd;
    bool odd = false;
    for (int i = 0; i < vertex_vec.size(); i++) {
        const Vertex &u = vertex_vec[i],
                     &v = vertex_vec[(i + 1) % vertex_vec.size()];
        if ((u[Y] - p[Y]) * (v[Y] - p[Y]) <= 0
            && !equal0(u[Y] - v[Y])
            && !(p[X] < u[X] && equal0(p[Y] - u[Y]))
            && 0 < u[X] + (p[Y] - u[Y]) * (u[X] - v[X]) / (u[Y] - v[Y]))
            odd = !odd;
    }
    if (odd)
        return res;
    delete res;
    return NULL;
}

GOPolygon::GOPolygon(void) {
}
GOPolygon::~GOPolygon(void) {
}