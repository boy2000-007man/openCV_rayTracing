#include "stdafx.h"
#include "GOSphere.h"
using namespace sdk;

IntersectionPoint* GOSphere::ray_intersection_ptr(const Ray &ray) const {
    const Vertex &Ro = ray.first;
    const Vector &Rd = ray.second;

    Vector l = Pc - Ro;
    FLOAT tp = l * Rd / sqrt(Rd * Rd);
    if (r * r <= l * l && tp < 0)
        return NULL;
    FLOAT d = sqrt(l * l - tp * tp);
    if (r < d)
        return NULL;
    FLOAT t_apostrophe = sqrt(r * r - d * d),
          t = (l * l < r * r ? tp + t_apostrophe : tp - t_apostrophe) / sqrt(Rd * Rd);
    IntersectionPoint *ip = new IntersectionPoint;
    ip->bgra = bgra;

    Vertex P = Ro + t * Rd;
    FLOAT rfi = Rd * (P - Pc) < 0 ? refraction_index : 1 / refraction_index;
    Vector I = Rd / sqrt(Rd * Rd),
           n = P - Pc,
           N = n / sqrt(n * n);
    FLOAT IN = I * N;
    Vector R = I - 2 * IN * N,
           T = I / rfi - (IN / rfi + sqrt(1 - (1 - IN * IN) / (rfi * rfi))) * N;
    ip->t_vec.push_back(t * (1 - ZERO));
    ip->modulus_vec.push_back(reflection_coefficient);
    ip->direction_vec.push_back(R);
    ip->t_vec.push_back(t * (1 + ZERO));
    ip->modulus_vec.push_back(refraction_coefficient);
    ip->direction_vec.push_back(T);

    return ip;
}

GOSphere::GOSphere(void) {
}
GOSphere::~GOSphere(void) {
}