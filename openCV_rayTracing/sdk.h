#pragma once
#include <vector>
#include <cassert>
#include <cmath>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <cstdio>
#include <ctime>
namespace sdk {
using std::cerr;
using std::endl;
using std::getchar;
typedef double FLOAT;
static FLOAT (*sqrt)(FLOAT) = std::sqrt;
static FLOAT (*cos)(FLOAT) = std::cos;
struct Vec3 : public std::vector<FLOAT> {
    Vec3(void) {
    }
    Vec3(FLOAT x, FLOAT y, FLOAT z) : std::vector<FLOAT>(0) {
        this->push_back(x);
        this->push_back(y);
        this->push_back(z);
    }
    Vec3(const std::vector<FLOAT> &v) : std::vector<FLOAT>(v) {
    }
};
typedef Vec3 Vertex;
typedef Vec3 Vector;
//typedef std::vector<FLOAT> Vertex;
//typedef std::vector<FLOAT> Vector;
struct Rectangle {
    Vertex P;
    std::vector<Vector> xy_vec;
};
typedef std::pair<Vertex, Vector> Ray;
typedef cv::Scalar BGRa;
/*struct RGB : public std::vector<int> {
    RGB(void) {
    }
    RGB(int r, int g, int b) : std::vector<int>(0) {
        this->push_back(r);
        this->push_back(g);
        this->push_back(b);
    }
    RGB(const std::vector<int> &v) : std::vector<int>(v) {
    }
};*/
//typedef std::vector<char> RGB;
template <class T>
T operator*(const std::vector<T> &v1, const std::vector<T> &v2) {
    assert(v1.size() == v2.size());
    T res = 0;
    for (int i = 0; i < v1.size(); i++)
        res += v1[i] * v2[i];
    return res;
}
template <class T>
std::vector<T> operator*(const T &t, const std::vector<T> &v) {
    std::vector<T> res(v.size());
    for (int i = 0; i < res.size(); i++)
        res[i] = t * v[i];
    return res;
}
static const FLOAT ZERO = 1e-6;
static bool equal0(FLOAT f) {
    return abs(f) < ZERO;
}
template <class T>
std::vector<T> operator+(const std::vector<T> &v1, const std::vector<T> &v2) {
    assert(v1.size() == v2.size());
    std::vector<T> res(v1.size());
    for (int i = 0; i < res.size(); i++)
        res[i] = v1[i] + v2[i];
    return res;
}
template <class T>
std::vector<T> operator-(const std::vector<T> &v1, const std::vector<T> &v2) {
    assert(v1.size() == v2.size());
    std::vector<T> res(v1.size());
    for (int i = 0; i < res.size(); i++)
        res[i] = v1[i] - v2[i];
    return res;
}
struct IntersectionPoint {
    BGRa bgra;
    std::vector<FLOAT> t_vec, modulus_vec;
    std::vector<Vector> direction_vec;
    /*IntersectionPoint(const BGRa &r, const std::vector<std::pair<FLOAT, Vector> > &mdv) {
        t = _t;
        bgra = r;
        modulus_direction_vec = mdv;
    }*/
};  // struct IntersectionPoint
static FLOAT det(const Vector &v0, const Vector &v1, const Vector &v2) {
    return v0[0] * v1[1] * v2[2] + v0[1] * v1[2] * v2[0] + v0[2] * v1[0] * v2[1]
         - v2[0] * v1[1] * v0[2] - v2[1] * v1[2] * v0[0] - v2[2] * v1[0] * v0[1];
}
static bool in01(const FLOAT &x) {
    return 0 <= x && x <= 1;
}
}   // namespace sdk