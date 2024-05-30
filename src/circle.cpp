// Copyright 2024 Derun Andrey
#include "circle.h"

#include <cmath>
#include <stdexcept>


const double Circle::PI = 3.14159265358979323846;

double Circle::CheckingTheInputData(double value) {
  if (value < 0) {
    throw std::invalid_argument("Value must be non-negative");
  }
  return value;
}

void Circle::updateDerivedValues() {
  ference = 2 * PI * radius;
  area = PI * radius * radius;
}

Circle::Circle(double radiusValue) : radius(CheckingTheInputData(radiusValue)) {
  updateDerivedValues();
}

double Circle::GetRadius() const { return radius; }

double Circle::GetFerence() const { return ference; }

double Circle::GetArea() const { return area; }

void Circle::SetRadius(double value) {
  radius = CheckingTheInputData(value);
  updateDerivedValues();
}

void Circle::SetFerence(double value) {
  ference = CheckingTheInputData(value);
  radius = ference / (2 * PI);
  updateDerivedValues();
}

void Circle::SetArea(double value) {
  area = CheckingTheInputData(value);
  radius = std::sqrt(area / PI);
  updateDerivedValues();
}
