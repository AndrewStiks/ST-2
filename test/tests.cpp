// Copyright 2024 Derun Andrey

#include <gtest/gtest.h>

#include <cmath>
#include <cstdint>

#include "circle.h"
#include "tasks.h"

const double PI = 3.14159265358979323846;

TEST(circle, setradius) {
  double radius = 10;
  Circle c;
  c.SetRadius(radius);
  ASSERT_DOUBLE_EQ(radius, c.GetRadius());
}

TEST(circle, setference) {
  double ference = 10;
  Circle c;
  c.SetFerence(ference);
  ASSERT_DOUBLE_EQ(ference, c.GetFerence());
}

TEST(circle, setarea) {
  double area = 10;
  Circle c;
  c.SetArea(area);
  ASSERT_DOUBLE_EQ(area, c.GetArea());
}

TEST(circle, cheakingradius) {
  Circle c(3);
  ASSERT_DOUBLE_EQ(3, c.GetRadius());
}

TEST(circle, checkingference) {
  Circle c(3);
  ASSERT_DOUBLE_EQ(3 * 2 * PI, c.GetFerence());
}

TEST(circle, checkingarea) {
  Circle c(3);
  ASSERT_DOUBLE_EQ(3 * 3 * PI, c.GetArea());
}

TEST(circle, createwithnegativeradius) { ASSERT_ANY_THROW(Circle(-10)); }

TEST(circle, setnegativeradius) {
  Circle c;
  ASSERT_ANY_THROW(c.SetRadius(-10));
}

TEST(circle, setnegativeference) {
  Circle c;
  ASSERT_ANY_THROW(c.SetFerence(-10));
}

TEST(circle, setnegativearea) {
  Circle c;
  ASSERT_ANY_THROW(c.SetArea(-10));
}

TEST(circle, setraduischeckferecne) {
  double radius = 3;
  Circle c;
  c.SetRadius(radius);
  ASSERT_DOUBLE_EQ(radius * 2 * PI, c.GetFerence());
}

TEST(circle, setraduischeckarea) {
  double radius = 3;
  Circle c;
  c.SetRadius(radius);
  ASSERT_DOUBLE_EQ(radius * radius * PI, c.GetArea());
}

TEST(circle, setareacheckradius) {
  double area = 3;
  Circle c;
  c.SetArea(area);
  ASSERT_DOUBLE_EQ(sqrt(area / PI), c.GetRadius());
}

TEST(CircleTest, SetAreaUpdatesCircumferenceCorrectly) {
    double area = 3.0;
    Circle c;
    c.SetArea(area);
    ASSERT_DOUBLE_EQ(std::sqrt(area / PI) * 2 * PI, c.GetCircumference());
}

TEST(CircleTest, SetCircumferenceUpdatesRadiusCorrectly) {
    double circumference = 3.0;
    Circle c;
    c.SetCircumference(circumference);
    ASSERT_DOUBLE_EQ(circumference / (2 * PI), c.GetRadius());
}

TEST(CircleTest, SetCircumferenceUpdatesAreaCorrectly) {
    double circumference = 3.0;
    Circle c;
    c.SetCircumference(circumference);
    double radius = circumference / (2 * PI);
    ASSERT_DOUBLE_EQ(PI * radius * radius, c.GetArea());
}

TEST(CircleTest, EqualRadiiResultsInEqualCircumferences) {
    Circle c1(3.0), c2(3.0);
    ASSERT_DOUBLE_EQ(c1.GetCircumference(), c2.GetCircumference());
}

TEST(CircleTest, EqualRadiiResultsInEqualAreas) {
    Circle c1(3.0), c2(3.0);
    ASSERT_DOUBLE_EQ(c1.GetArea(), c2.GetArea());
}

TEST(TasksTest, EarthAndRope) {
    double earthRadiusMeters = 6378.1 * 1e3;
    double earthCircumference = earthRadiusMeters * 2 * PI;
    double actualResultMeters = (earthCircumference + 1) / (2 * PI) - earthRadiusMeters;

    ASSERT_DOUBLE_EQ(SolveEarthAndRope(earthRadiusMeters, 1), actualResultMeters);
}

TEST(TasksTest, SwimmingPool) {
    double poolRadius = 3.0;
    double areaWidth = 1.0;

    double meterCircumferencePrice = 2000.0;
    double squareMeterAreaPrice = 1000.0;

    double circumferencePrice = 2 * PI * (poolRadius + areaWidth) * meterCircumferencePrice;
    double areaPrice = PI * areaWidth * (areaWidth + 2 * poolRadius) * squareMeterAreaPrice;

    ASSERT_DOUBLE_EQ(SolveSwimmingPool(poolRadius, areaWidth, squareMeterAreaPrice, meterCircumferencePrice),
                     circumferencePrice + areaPrice);
}