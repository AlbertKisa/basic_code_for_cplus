#include <iostream>
#include <memory>
#include <vector>

class Shape {
 public:
  virtual ~Shape() = default;
  virtual void Draw() const = 0;
};

class Circle : public Shape {
 public:
  void Draw() const override { std::cout << "Drawing a Circle\n"; }
};

class Rectangle : public Shape {
 public:
  void Draw() const override { std::cout << "Drawing a Rectangle\n"; }
};

void render(const std::vector<std::shared_ptr<Shape>>& shapes) {
  for (const auto& shape : shapes) {
    shape->Draw();
  }
}

int main() {
  std::vector<std::shared_ptr<Shape>> shapes;
  shapes.push_back(std::make_shared<Circle>());
  shapes.push_back(std::make_shared<Rectangle>());

  render(shapes);

  return 0;
}
