#pragma once
#include "GOScene.h"
namespace sdk {
class Camera
{
public:
    BGRa recursion(int d, const Ray &ray) const;
    GOScene *scene;
    void get_image(const Vertex &, const Rectangle &, std::vector<std::vector<BGRa> > &) const;
    Camera(void);
    ~Camera(void);
};
}