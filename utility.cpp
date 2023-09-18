#include "distribution.h"

double uniformDistributionGetNumber(int include_borders) {
  double res = (double)std::rand() / RAND_MAX;
  // didn't use fabs() here because  0 <= res <= 1
  if ((res <= EPSILON || (1 - res) <= EPSILON) || !include_borders) {
    res = (double)std::rand() / RAND_MAX;
  }
  return res;
}

double standardDistributionFunction(double x) {
  return 0.5 * (1 + std::erf(x / std::sqrt(2)));
}

double standardDistributionDensity(double x) {
  return std::exp(-0.5 * pow(x, 2.0)) / std::sqrt(2 * M_PI);
}