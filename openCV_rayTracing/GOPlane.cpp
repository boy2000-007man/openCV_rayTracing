#include "stdafx.h"
#include "GOPlane.h"
using namespace sdk;

IntersectionPoint* GOPlane::ray_intersection_ptr(const Ray &ray) const {
    const Vertex &Ro = ray.first;
    const Vector &Rd = ray.second;

    FLOAT nRd = n * Rd;
    if (equal0(nRd))
        return NULL;
    FLOAT t = (n * (P - Ro)) / nRd;
    if (t < 0)
        return NULL;
    IntersectionPoint *ip = new IntersectionPoint;
    ip->bgra = bgra;
    FLOAT rfi = nRd < 0 ? refraction_index : 1 / refraction_index;
    Vector I = Rd / sqrt(Rd * Rd),
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
    //cerr << N << T << endl;
    return ip;
}

GOPlane::GOPlane(void) {
}
GOPlane::~GOPlane(void) {
}