#include "stdafx.h"
#include "Camera.h"
using namespace sdk;
BGRa Camera::recursion(int d, const Ray &ray) const {
    //cerr << d << endl;
    BGRa bgra(0, 0, 0, 0);
    if (!d)
        return bgra;
    IntersectionPoint *res = scene->ray_intersection_ptr(ray);
    if (res) {
        bgra += res->bgra;
        for (int i = 0; i < res->t_vec.size(); i++) {
            Vertex origion = ray.first + res->t_vec[i] * ray.second;
            bgra = bgra * (1 - res->modulus_vec[i]) + res->modulus_vec[i] * recursion(d - 1, std::make_pair(origion, res->direction_vec[i]));
        }
        //cerr << bgra << endl;
        delete res;
    }
    return bgra;
}
void Camera::get_image(const Vertex &observer, const Rectangle &window, std::vector<std::vector<BGRa> > &image) const {
    int now = clock();
    int width = image.size(), height = image[0].size();
    Vertex origion = window.P,
           dx = 1.0 / width * window.xy_vec[0],
           dy = 1.0 / height * window.xy_vec[1];
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            origion = origion + dy;
            Ray ray = std::make_pair(origion, origion - observer);
            //image[x][y] = recursion(3, ray);
            //printf("%d %d %d\n", image[x][y][0], image[x][y][1], image[x][y][2]);
        }
        origion = window.P + dx - window.xy_vec[1];
    }
        printf("time = %dms\n", clock() - now);
}

Camera::Camera(void) {
}
Camera::~Camera(void) {
}