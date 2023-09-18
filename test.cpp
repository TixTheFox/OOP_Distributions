#include <fstream>
#include <iostream>

#include "distribution.h"

int main() {
  std::srand(10);
  std::vector<double> values, other_values;
  double v, mu, lambda;
  v = 1;
  mu = 0;
  lambda = 10;
  HuberDistributionGetSet(1000000, &values, v, mu, lambda);
  statisticGetSet(&values, 1000000, &other_values);

  // ФАЙЛЫ НАДО СОЗДАТЬ

  std::fstream huber("./huber.txt");
  std::fstream emp1("./emp1.txt");
  std::fstream emp2("./emp2.txt");

  for (double x = -100; x <= 100; x++) {
    // std::cout << std::fixed << x << "\n";

    huber << std::fixed << HuberDistributionDensity(x, v, mu, lambda) << "\n";
    emp1 << std::fixed << statisticDensity(x, &values) << "\n";
    emp2 << std::fixed << statisticDensity(x, &other_values) << "\n";
  }
  std::cout << "done\n";
  huber.close();
  emp1.close();
  emp2.close();
}