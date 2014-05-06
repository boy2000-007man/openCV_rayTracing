#include "stdafx.h"
#include "GOTriangle.h"
using namespace sdk;

IntersectionPoint* GOTriangle::ray_intersection_ptr(const Ray &ray) const {
    IntersectionPoint *res = GOPlane::ray_intersection_ptr(ray);
    if (!res)
        return res;
    const Vertex &Ro = ray.first;
    const Vector &Rd = ray.second;
    Vector E1 = P0 - P1, E2 = P0 - P2, S = P0 - Ro;
    FLOAT b = det(Rd, S, E2) / det(Rd, E1, E2),
          y = det(Rd, E1, S) / det(Rd, E1, E2);
    //cerr << res->t << ", " << det(S, E1, E2) / det(Rd, E1, E2) << endl;
    if (in01(b) && in01(y) && in01(b + y))
        return res;
    delete res;
    return NULL;
}

GOTriangle::GOTriangle(void) {
}


GOTriangle::~GOTriangle(void) {
}
