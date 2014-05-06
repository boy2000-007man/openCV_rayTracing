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
    /*cerr << "Pc = " << Pc[0] << ", " << Pc[1] << ", " << Pc[2] << endl;
    cerr << "Ro = " << Ro[0] << ", " << Ro[1] << ", " << Ro[2] << endl;
    cerr << "l = " << l[0] << ", " << l[1] << ", " << l[2] << endl;
    cerr << "Rd = " << Rd[0] << ", " << Rd[1] << ", " << Rd[2] << endl;
    cerr << "r^2 = " << r * r << ", l^2 = " << l * l << endl;
    cerr << "tp = " << tp << endl;*/
    //getchar();
    FLOAT t_apostrophe = sqrt(r * r - d * d),
          t = (l * l < r * r ? tp + t_apostrophe : tp - t_apostrophe) / sqrt(Rd * Rd);
    IntersectionPoint *ip = new IntersectionPoint;
    ip->bgra = bgra;
    Vertex P = Ro + t * Rd;
    FLOAT rfi = Rd * (P - Pc) < 0 ? refraction_index : 1 / refraction_index;
    Vector I = 1 / sqrt(Rd * Rd) * Rd,
           n = P - Pc,
           N = 1 / sqrt(n * n) * n,
           R = I - 2 * (I * N) * N,
           T = - 1 / rfi * I + (1 / rfi * (I * N) - sqrt(1 - (1 - (I * N) * (I * N)) / (rfi * rfi))) * N;
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