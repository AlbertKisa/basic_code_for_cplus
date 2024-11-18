#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<double> vec = {1.0, 3.0, 5.0, 7.0, 9.0, 11.0};
  double target = 11.1;

  // 使用 std::upper_bound 找到第一个大于 target 的元素
  auto it = std::lower_bound(vec.begin(), vec.end(), target);

  if (it != vec.end()) {
    // 获取元素的值
    int value = *it;

    // 计算元素的顺序（即索引位置）
    int index = std::distance(vec.begin(), it);

    std::cout << "第一个大于 " << target << " 的元素是 " << value
              << "，位于顺序 " << index << "\n";
  } else {
    std::cout << "没有找到大于 " << target << " 的元素\n";
  }

  return 0;
}
