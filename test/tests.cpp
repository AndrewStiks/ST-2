// Copyright 2024 Derun Andrey

#include <gtest/gtest.h>

#include <cmath>
#include <cstdint>

#include "circle.h"
#include "tasks.h"

const double PI = 3.14159265358979323846;

TEST(CircleTest, ConstructorInitializesRadiusCorrectly) {
  double radius = 3.0;
  Circle c(radius);
  ASSERT_DOUBLE_EQ(radius, c.GetRadius());
}

TEST(CircleTest, ConstructorInitializesCircumferenceCorrectly) {
  double radius = 3.0;
  Circle c(radius);
  ASSERT_DOUBLE_EQ(2 * PI * radius, c.GetFerence());
}

TEST(CircleTest, ConstructorInitializesAreaCorrectly) {
  double radius = 3.0;
  Circle c(radius);
  ASSERT_DOUBLE_EQ(PI * radius * radius, c.GetArea());
}

TEST(CircleTest, GetRadiusReturnsCorrectValue) {
  double radius = 3.0;
  Circle c(radius);
  ASSERT_DOUBLE_EQ(radius, c.GetRadius());
}

TEST(CircleTest, GetFerenceReturnsCorrectValue) {
  double radius = 3.0;
  Circle c(radius);
  ASSERT_DOUBLE_EQ(2 * PI * radius, c.GetFerence());
}

TEST(CircleTest, GetAreaReturnsCorrectValue) {
  double radius = 3.0;
  Circle c(radius);
  ASSERT_DOUBLE_EQ(PI * radius * radius, c.GetArea());
}

TEST(CircleTest, SetRadiusUpdatesRadiusCorrectly) {
  Circle c;
  double radius = 3.0;
  c.SetRadius(radius);
  ASSERT_DOUBLE_EQ(radius, c.GetRadius());
}

TEST(CircleTest, SetRadiusUpdatesCircumferenceCorrectly) {
  Circle c;
  double radius = 3.0;
  c.SetRadius(radius);
  ASSERT_DOUBLE_EQ(2 * PI * radius, c.GetFerence());
}

TEST(CircleTest, SetRadiusUpdatesAreaCorrectly) {
  Circle c;
  double radius = 3.0;
  c.SetRadius(radius);
  ASSERT_DOUBLE_EQ(PI * radius * radius, c.GetArea());
}

TEST(CircleTest, SetFerenceUpdatesCircumferenceCorrectly) {
  Circle c;
  double circumference = 6.0 * PI;
  c.SetFerence(circumference);
  ASSERT_DOUBLE_EQ(circumference, c.GetFerence());
}

TEST(CircleTest, SetFerenceUpdatesRadiusCorrectly) {
  Circle c;
  double circumference = 6.0 * PI;
  c.SetFerence(circumference);
  ASSERT_DOUBLE_EQ(3.0, c.GetRadius());
}

TEST(CircleTest, SetFerenceUpdatesAreaCorrectly) {
  Circle c;
  double circumference = 6.0 * PI;
  c.SetFerence(circumference);
  ASSERT_DOUBLE_EQ(9.0 * PI, c.GetArea());
}

TEST(CircleTest, SetAreaUpdatesAreaCorrectly) {
  Circle c;
  double area = 9.0 * PI;
  c.SetArea(area);
  ASSERT_DOUBLE_EQ(area, c.GetArea());
}

TEST(CircleTest, SetAreaUpdatesRadiusCorrectly) {
  Circle c;
  double area = 9.0 * PI;
  c.SetArea(area);
  ASSERT_DOUBLE_EQ(3.0, c.GetRadius());
}

TEST(CircleTest, SetAreaUpdatesCircumferenceCorrectly) {
  Circle c;
  double area = 9.0 * PI;
  c.SetArea(area);
  ASSERT_DOUBLE_EQ(6.0 * PI, c.GetFerence());
}

TEST(TasksTest, SolveEarthAndRope_PositiveValues) {
  double earthRadius = 6378.1 * 1e3;  // Earth's radius in meters
  double ropeLength = 1.0;            // 1 meter rope length
  double expectedResult =
      (earthRadius * 2 * PI + ropeLength) / (2 * PI) - earthRadius;

  ASSERT_DOUBLE_EQ(expectedResult, SolveEarthAndRope(earthRadius, ropeLength));
}

TEST(TasksTest, SolveEarthAndRope_ZeroRopeLength) {
  double earthRadius = 6378.1 * 1e3;
  double ropeLength = 0.0;
  double expectedResult = 0.0;

  ASSERT_DOUBLE_EQ(expectedResult, SolveEarthAndRope(earthRadius, ropeLength));
}

TEST(TasksTest, SolveEarthAndRope_NegativeRopeLength) {
  double earthRadius = 6378.1 * 1e3;
  double ropeLength = -1.0;
  double expectedResult =
      (earthRadius * 2 * PI - std::abs(ropeLength)) / (2 * PI) - earthRadius;

  ASSERT_DOUBLE_EQ(expectedResult, SolveEarthAndRope(earthRadius, ropeLength));
}

TEST(TasksTest, SolveSwimmingPool_PositiveValues) {
  double poolRadius = 3.0;
  double areaWidth = 1.0;
  double areaPricePerSquareMeter = 1000.0;
  double fencePricePerMeter = 2000.0;

  double expectedCircumference = 2 * PI * (poolRadius + areaWidth);
  double expectedArea = PI * areaWidth * (areaWidth + 2 * poolRadius);
  double expectedResult = expectedCircumference * fencePricePerMeter +
                          expectedArea * areaPricePerSquareMeter;

  ASSERT_DOUBLE_EQ(expectedResult, SolveSwimmingPool(poolRadius, areaWidth,
                                                     areaPricePerSquareMeter,
                                                     fencePricePerMeter));
}

TEST(TasksTest, SolveSwimmingPool_ZeroAreaWidth) {
  double poolRadius = 3.0;
  double areaWidth = 0.0;
  double areaPricePerSquareMeter = 1000.0;
  double fencePricePerMeter = 2000.0;

  double expectedCircumference = 2 * PI * poolRadius;
  double expectedArea = PI * poolRadius * poolRadius;
  double expectedResult = expectedCircumference * fencePricePerMeter +
                          expectedArea * areaPricePerSquareMeter;

  ASSERT_DOUBLE_EQ(expectedResult, SolveSwimmingPool(poolRadius, areaWidth,
                                                     areaPricePerSquareMeter,
                                                     fencePricePerMeter));
}
