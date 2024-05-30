// Copyright 2024 Derun Andrey

#include "tasks.h"

#include "circle.h"

double SolveEarthAndRope(double earthRadius, double ropelength) {
  Circle circleA(earthRadius);
  Circle circleB;
  circleB.SetFerence(circleA.GetFerence() + ropelength);
  auto res = circleB.GetRadius() - circleA.GetRadius();
  return res;
}

double SolveSwimmingPool(double poolRadiusMeter, double areaWidthMeter,
                         double areaPricePerSquareMeter,
                         double ferencePricePerMeter) {
  Circle pool(poolRadiusMeter);
  Circle poolwitharea(poolRadiusMeter + areaWidthMeter);
  double ferencePrice = poolwitharea.GetFerence() * ferencePricePerMeter;
  double areaPrice =
      (poolwitharea.GetArea() - pool.GetArea()) * areaPricePerSquareMeter;
  auto res = ferencePrice + areaPrice;
  return res;
}
