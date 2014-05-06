#include "stdafx.h"
#include "GOScene.h"
using namespace sdk;

IntersectionPoint* GOScene::ray_intersection_ptr(const Ray &ray) const {
    IntersectionPoint *res = NULL, *tmp;
    for (int i = 0; i < geometric_object_ptr_vec.size(); i++) {
        if (tmp = geometric_object_ptr_vec[i]->ray_intersection_ptr(ray))
            if (!res)
                res = tmp;
            else if (tmp->t_vec[0] < res->t_vec[0]) {
                assert(0 < res->t_vec[0]);
                delete res;
                res = tmp;
            }
    }
    return res;
}

GOScene::GOScene(void) {
}
GOScene::~GOScene(void) {
}
