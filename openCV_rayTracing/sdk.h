#pragma once
#include <cstdio>
#include <ctime>
#include <cmath>
#include <vector>
#include <iostream>
#include <opencv2/opencv.hpp>
namespace sdk {
using std::cerr;
using std::endl;
using std::getchar;
typedef double FLOAT;
static const FLOAT ZERO = 1e-6;
static FLOAT (*sqrt)(FLOAT) = std::sqrt;
static bool equal0(FLOAT f) {
    return abs(f) < ZERO;
}
typedef cv::Vec3d Vec3;
static FLOAT operator*(const Vec3 &v1, const Vec3 &v2) {
    return v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2];
}
/*static Vec3 operator^(const Vec3 &v1, const Vec3 &v2) {
    return Vec3(v1[1]*v2[2]-v1[2]*v2[1],v1[2]*v2[0]-v1[0]*v2[2],v1[0]*v2[1]-v1[1]*v2[0]);
}*/
typedef Vec3 Vertex;
typedef Vec3 Vector;
struct Rectangle {
    Vertex P;
    Vector x;
    Vector y;
};
typedef std::pair<Vertex, Vector> Ray;
typedef cv::Scalar BGRa;
struct IntersectionPoint {
    BGRa bgra;
    std::vector<FLOAT> t_vec, modulus_vec;
    std::vector<Vector> direction_vec;
};
static FLOAT det(const Vec3 &v0, const Vec3 &v1, const Vec3 &v2) {
    return v0[0] * v1[1] * v2[2] + v0[1] * v1[2] * v2[0] + v0[2] * v1[0] * v2[1]
         - v2[0] * v1[1] * v0[2] - v2[1] * v1[2] * v0[0] - v2[2] * v1[0] * v0[1];
}
static bool in01(const FLOAT &x) {
    return 0 <= x && x <= 1;
}
}