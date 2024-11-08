#include <iostream>
#include <memory>
#include <unordered_map>

class Person {
 public:
  explicit Person(const int age) : age_(age){};

  Person() = delete;

  virtual void Work(const std::string& task) = 0;

  virtual void Learn(const std::string& knowledges) = 0;

 protected:
  virtual void Think(const std::string& task, const std::string& news,
                     const std::string& book) = 0;

 private:
  int age_ = 0;
  std::unordered_map<std::string, std::string> cognition_;
};

enum class Gender : unsigned int { kBoy, kGirl };

class Student : public Person {
 public:
  Student(const int age, const Gender& gender) : Person(age), gender_(gender) {}

  void Work(const std::string& task) override {
    std::cout << "working with task: " << task << std::endl;
  };

  void Learn(const std::string& knowledges) override {
    std::cout << "learning knowledges: " << knowledges << std::endl;
  };

 protected:
  void Think(const std::string& task, const std::string& news,
             const std::string& book) override {
    (void)task;
    (void)news;
    (void)book;
    std::cout << "Begin to think: " << std::endl;
  };

 private:
  Gender gender_;
};

int main() {
  int age = 10;
  Gender gender = Gender::kBoy;
  std::unique_ptr<Student> student_a = std::make_unique<Student>(age, gender);
  std::string task_content = "Make pratice with Math work";
  student_a->Work(task_content);

  return 0;
}
