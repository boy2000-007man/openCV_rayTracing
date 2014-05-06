#include "stdafx.h"
#include "GOBox.h"
#include "GOPlane.h"
using namespace sdk;

IntersectionPoint* GOBox::ray_intersection_ptr(const Ray &ray) const {
    IntersectionPoint *t_min = NULL, *t_max = NULL;
    for (int i = 0; i < abc_vec.size(); i++) {
        GOPlane p1, p2;
        IntersectionPoint *t1 = p1.ray_intersection_ptr(ray),
                          *t2 = p2.ray_intersection_ptr(ray);
        if (t1) {
            if (t2->t_vec[0] < t1->t_vec[0])
                std::swap(t1, t2);
            if (!t_min || t_min->t_vec[0] < t1->t_vec[0]) {
                delete t_min;
                t_min = t1;
            }
            if (!t_max || t2->t_vec[0] < t_max->t_vec[0]) {
                delete t_max;
                t_max = t2;
            }
        }
    }
    if (t_min < t_max)
        if (0 < t_min) {
            delete t_max;
            return t_min;
        } else if (0 < t_max) {
            delete t_min;
            return t_max;
        }
    delete t_min;
    delete t_max;
    return NULL;
}

GOBox::GOBox(void) {
}
GOBox::~GOBox(void) {
}