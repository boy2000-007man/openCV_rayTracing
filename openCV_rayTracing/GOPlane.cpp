#include "stdafx.h"
#include "GOPlane.h"
using namespace sdk;

IntersectionPoint* GOPlane::ray_intersection_ptr(const Ray &ray) const {
    const Vertex &Ro = ray.first;
    const Vector &Rd = ray.second;
    FLOAT t = (n * (P - Ro)) / (n * Rd);
    if (equal0(n * Rd) || t < 0)
        return NULL;
    IntersectionPoint *ip = new IntersectionPoint;
    ip->bgra = bgra;
    FLOAT rfi = Rd * n < 0 ? refraction_index : 1 / refraction_index;
    Vector I = 1 / sqrt(Rd * Rd) * Rd,
           N = 1 / sqrt(n * n) * n,
           R = I - 2 * (I * N) * N,
           T = - 1 / rfi * I + (1 / rfi * (I * N) - sqrt(1 - (1 - (I * N) * (I * N)) / (rfi * rfi))) * N;
    ip->t_vec.push_back(t * (1 - ZERO));
    ip->modulus_vec.push_back(reflection_coefficient);
    ip->direction_vec.push_back(R);
    ip->t_vec.push_back(t * (1 + ZERO));
    ip->modulus_vec.push_back(refraction_coefficient);
    ip->direction_vec.push_back(T);
    /*Vector T = I - 2 * (I * N) * N;
    cerr << "begin" << endl;
    cerr << Rd[0] << ", " << Rd[1] << ", " << Rd[2] << endl;
    cerr << I[0] << ", " << I[1] << ", " << I[2] << endl;
    cerr << n[0] << ", " << n[1] << ", " << n[2] << endl;
    cerr << N[0] << ", " << N[1] << ", " << N[2] << endl;
    cerr << T[0] << ", " << T[1] << ", " << T[2] << endl;*/
    return ip;
}

GOPlane::GOPlane(void) {
}
GOPlane::~GOPlane(void) {
}