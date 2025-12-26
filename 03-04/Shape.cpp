#include "Shape.h"
#include <numbers>
#include <iostream>

Circle::Circle(float radius) : radius_(radius) {}

void Circle::Size() {
   static const float pi = std::numbers::pi_v<float>;
   area_ = pi * radius_ * radius_;
}

void Circle::Draw() {
   std::cout << "Circle Area: " << area_ << std::endl;
}

Rectangle::Rectangle(float width, float height) : width_(width), height_(height) {}

void Rectangle::Size() {
   area_ = width_ * height_;
}

void Rectangle::Draw() {
   std::cout << "Rectangle Area: " << area_ << std::endl;
}
