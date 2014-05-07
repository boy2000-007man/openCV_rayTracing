#include "stdafx.h"
#include "Camera.h"
using namespace sdk;
BGRa Camera::recursion(int d, const Ray &ray) const {
    if (!d)
        return BGRa(0, 0, 0, 0);
    IntersectionPoint *res = scene->ray_intersection_ptr(ray);
    if (!res)
        return BGRa(0, 0, 0, 0);
    BGRa bgra(res->bgra);
    for (int i = 0; i < res->t_vec.size(); i++) {
        Vertex origion = ray.first + res->t_vec[i] * ray.second;
        bgra += res->modulus_vec[i] * recursion(d - 1, std::make_pair(origion, res->direction_vec[i]));
    }
    delete res;
    return bgra;
}
void Camera::get_image(const Vertex &O, const Rectangle &window, std::vector<std::vector<BGRa> > &image) const {
    int now = clock();

    int width = image.size(), height = image[0].size();
    Vector dx = window.x / width,
           dy = window.y / height;
    for (int x = 0; x < width; x++)
        for (int y = 0; y < height; y++) {
            Vertex P = window.P + x * dx + y * dy;
            image[x][y] = recursion(3, std::make_pair(P, P - O));
        }

    printf("time = %dms\n", clock() - now);
}

Camera::Camera(void) {
}
Camera::~Camera(void) {
}