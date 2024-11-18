#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<double> mass_range = {2.0, 3.0, 4.0, 5.0};
  double target = 3.0;
  auto comp = [](double query, const double& mass) { return query < mass; };
  std::vector<double>::iterator it =
      std::upper_bound(mass_range.begin(), mass_range.end(), target, comp);

  uint index = std::distance(mass_range.begin(), it);
  std::cout << "index:" << index << ", value:" << *it << std::endl;

  return 0;
}
