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
  ASSERT_DOUBLE_EQ(2 * PI * radius, c.GetCircumference());
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

TEST(CircleTest, GetCircumferenceReturnsCorrectValue) {
  double radius = 3.0;
  Circle c(radius);
  ASSERT_DOUBLE_EQ(2 * PI * radius, c.GetCircumference());
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
  ASSERT_DOUBLE_EQ(2 * PI * radius, c.GetCircumference());
}

TEST(CircleTest, SetRadiusUpdatesAreaCorrectly) {
  Circle c;
  double radius = 3.0;
  c.SetRadius(radius);
  ASSERT_DOUBLE_EQ(PI * radius * radius, c.GetArea());
}

TEST(CircleTest, SetCircumferenceUpdatesCircumferenceCorrectly) {
  Circle c;
  double circumference = 6.0 * PI;
  c.SetCircumference(circumference);
  ASSERT_DOUBLE_EQ(circumference, c.GetCircumference());
}

TEST(CircleTest, SetCircumferenceUpdatesRadiusCorrectly) {
  Circle c;
  double circumference = 6.0 * PI;
  c.SetCircumference(circumference);
  ASSERT_DOUBLE_EQ(3.0, c.GetRadius());
}

TEST(CircleTest, SetCircumferenceUpdatesAreaCorrectly) {
  Circle c;
  double circumference = 6.0 * PI;
  c.SetCircumference(circumference);
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
  ASSERT_DOUBLE_EQ(6.0 * PI, c.GetCircumference());
}
