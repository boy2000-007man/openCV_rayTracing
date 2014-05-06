// openCV_rayTracing.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include "Camera.h"
#include "GOScene.h"
#include "GOSphere.h"
#include "GOTriangle.h"

const int WIDTH = 400,
		  HEIGHT = 200;
const char TITLE[] = "OpenCV_rayTracing";
cv::Mat screen = cv::Mat::zeros(HEIGHT, WIDTH, CV_8UC3);
void draw_pixel(int x, int y, cv::Scalar color) {
    //printf("drawPixel(%d, %d)\n", x, y);
	circle(screen, cv::Point(x, y), 0, color);
}

sdk::Vector xmul(const sdk::Vector &u, const sdk::Vector &v) {
    assert(u.size() == 3 && v.size() == 3);
    return sdk::Vector(u[1]*v[2]-u[2]*v[1],u[2]*v[0]-u[0]*v[2],u[0]*v[1]-u[1]*v[0]);
}

int _tmain(int argc, _TCHAR* argv[])
{

    sdk::Camera *camera = new sdk::Camera;
    camera->scene = new sdk::GOScene;

    /*sdk::GOSphere *sphere = new sdk::GOSphere;
    sphere->Pc = sdk::Vertex(200,30,-10*sdk::sqrt(3));
    sphere->reflection_coefficient = 0.6;
    sphere->r = 40;
    sphere->bgra = sdk::BGRa(0, 255, 0);
    sphere->transparency = 0.9;
    sphere->refraction_index = 1.414;
    sphere->refraction_coefficient = 0.2;
    camera->scene->geometric_object_ptr_vec.push_back(sphere);

    sdk::GOSphere *sphere2 = new sdk::GOSphere;
    sphere2->Pc = sdk::Vertex(200,-30,-10*sdk::sqrt(3));
    sphere2->reflection_coefficient = 0.6;
    sphere2->r = 40;
    sphere2->bgra = sdk::BGRa(255, 0, 0);
    sphere2->transparency = 0.9;
    sphere2->refraction_index = 1.414;
    sphere2->refraction_coefficient = 0.2;
    camera->scene->geometric_object_ptr_vec.push_back(sphere2);
    sdk::GOSphere *sphere3 = new sdk::GOSphere;
    sphere3->Pc = sdk::Vertex(200,0,20*sdk::sqrt(3));
    sphere3->reflection_coefficient = 0.6;
    sphere3->r = 40;
    sphere3->bgra = sdk::BGRa(0, 0, 255);
    sphere3->transparency = 0.9;
    sphere3->refraction_index = 1.414;
    sphere3->refraction_coefficient = 0.2;
    camera->scene->geometric_object_ptr_vec.push_back(sphere3);
    sdk::GOSphere *light = new sdk::GOSphere;
    light->Pc = sdk::Vertex(0,100,700);
    light->reflection_coefficient = 0.0;
    light->r = 100;
    light->bgra = sdk::BGRa(255, 255, 255);
    light->transparency = 0;
    light->refraction_index = 1;
    light->refraction_coefficient = 0;
    camera->scene->geometric_object_ptr_vec.push_back(light);*/

    /*sdk::GOTriangle *triangle = new sdk::GOTriangle;
    triangle->P0 = sdk::Vertex(1000,0,0);//WIDTH/2,WIDTH,0);
    triangle->P1 = sdk::Vertex(1000,4000,0);//WIDTH/2, 10*WIDTH, 0);
    triangle->P2 = sdk::Vertex(1000,0,2000);//WIDTH/2, 0, 10*HEIGHT);
    triangle->P = triangle->P0;
    triangle->n = xmul(triangle->P1 - triangle->P0, triangle->P2 - triangle->P0);
    triangle->reflection_coefficient = 0.9;
    triangle->bgra = sdk::BGRa(10, 10, 10);
    camera->scene->geometric_object_ptr_vec.push_back(triangle);*/
    /*sdk::GOPlane *plane1 = new sdk::GOPlane;
    plane1->P = sdk::Vertex(500, 0, 0);
    plane1->n = sdk::Vector(1, 1, 0);
    plane1->bgra = sdk::BGRa(0, 0, 0);
    plane1->reflection_coefficient = 0.9;
    plane1->refraction_coefficient = 0.0;
    plane1->refraction_index = 1.414;
    plane1->transparency = 0.2;
    camera->scene->geometric_object_ptr_vec.push_back(plane1);
    sdk::GOPlane *plane2 = new sdk::GOPlane;
    plane2->P = sdk::Vertex(500, 0, 0);
    plane2->n = sdk::Vector(1, -1, 0);
    plane2->bgra = sdk::BGRa(0, 0, 0);
    plane2->reflection_coefficient = 0.9;
    plane2->refraction_coefficient = 0.0;
    plane2->refraction_index = 1.414;
    plane2->transparency = 0.2;
    camera->scene->geometric_object_ptr_vec.push_back(plane2);
    sdk::GOPlane *plane = new sdk::GOPlane;
    plane->P = sdk::Vertex(0, 0, -HEIGHT/2);
    plane->n = sdk::Vector(0, 0, 1);
    plane->bgra = sdk::BGRa(0, 0, 0);
    plane->reflection_coefficient = 0.9;
    plane->refraction_coefficient = 0.0;
    plane->refraction_index = 1.414;
    plane->transparency = 0.2;
    camera->scene->geometric_object_ptr_vec.push_back(plane);*/

    sdk::Vertex observer(0, 0, HEIGHT/4);
    sdk::Rectangle window;
    window.P = sdk::Vertex(110,-WIDTH/2,HEIGHT/2);
    window.xy_vec.push_back(sdk::Vector(0, WIDTH, 0));
    window.xy_vec.push_back(sdk::Vector(0, 0, -HEIGHT));

    cv::namedWindow(TITLE);
    std::vector<std::vector<sdk::BGRa> > image(WIDTH, std::vector<sdk::BGRa>(HEIGHT));
    camera->get_image(observer, window, image);
    for (int x = 0; x < WIDTH; x++)
        for (int y = 0; y < HEIGHT; y++)
            draw_pixel(x, y, image[x][y]);
    imshow(TITLE, screen);
    cv::waitKey(0);

	return 0;
}