#include <iostream>
#include <memory>

// 定义 CollisionMarginModel 基类
struct CollisionMarginModel {
  virtual ~CollisionMarginModel() = default;  // 必须有虚函数
};

// 定义 LinearCollisionMarginModel 派生类
class LinearCollisionMarginModel : public CollisionMarginModel {
 public:
  void display() const {
    std::cout << "This is LinearCollisionMarginModel." << std::endl;
  }
};

int main() {
  // 创建一个 LinearCollisionMarginModel 对象，并将其指针存储在基类指针中
  std::unique_ptr<CollisionMarginModel> model =
      std::make_unique<LinearCollisionMarginModel>();

  // 尝试将 CollisionMarginModel* 转换为 LinearCollisionMarginModel*
  if (LinearCollisionMarginModel* linearModel =
          dynamic_cast<LinearCollisionMarginModel*>(model.get())) {
    // 转换成功
    linearModel->display();
  } else {
    // 转换失败
    std::cout << "Conversion failed." << std::endl;
  }

  return 0;
}
