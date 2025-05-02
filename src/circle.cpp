// Copyright 2022 UNN-CS
#include <cmath>
#include <cstdint>
#include "circle.h"

Circle::Circle(double r) : radius(r) {
    calculateFromRadius();
}

void Circle::setRadius(double r) {
    radius = r;
    calculateFromRadius();
}

void Circle::setFerence(double f) {
    ference = f;
    calculateFromFerence();
}

void Circle::setArea(double a) {
    area = a;
    calculateFromArea();
}

double Circle::getRadius() const {
    return radius;
}

double Circle::getFerence() const {
    return ference;
}

double Circle::getArea() const {
    return area;
}

void Circle::calculateFromRadius() {
    ference = 2 * M_PI * radius;
    area = M_PI * radius * radius;
}

void Circle::calculateFromFerence() {
    radius = ference / (2 * M_PI);
    area = M_PI * radius * radius;
}

void Circle::calculateFromArea() {
    radius = sqrt(area / M_PI);
    ference = 2 * M_PI * radius;
}
