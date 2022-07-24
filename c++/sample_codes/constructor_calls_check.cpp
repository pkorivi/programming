/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP,
Ruby, C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS Code,
Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

class Test {
public:
  Test() : a{0}, b{0} { std::cerr << "constructor" << std::endl; }
  Test(int val) : a{val} { std::cerr << "val constructor" << std::endl; }

  int &geta() { return a; }
  const int &getbconst() { return a; }

  Test(Test &t) {
    a = t.a;
    std::cerr << "copy" << std::endl;
  }

  Test &operator=(Test const &t) {
    if (this != &t) {
      this->a = t.a;
    }
    std::cerr << "copy assignment" << std::endl;
    return *this;
  }

  Test(Test &&t) noexcept {
    a = std::move(t.a);
    std::cerr << "move constructor" << std::endl;
  }

  Test &operator=(Test const &&t) noexcept {
    if (this != &t) {
      this->a = t.a;
    }
    std::cerr << "move assignment" << std::endl;
    return *this;
  }

private:
  int a;
  int b;
};

void func(Test t) { return; }

int main() {
  Test t;
  int &a = t.geta();
  std::cerr << "1 " << a << std::endl;
  a = 10;
  std::cerr << "2 " << a << std::endl;
  std::cerr << "3 " << t.geta() << std::endl;
  const int &b = t.getbconst();
  std::cerr << "2 " << b << std::endl;
  std::cerr << "3 " << t.getbconst() << std::endl;
  auto c = t;
  c = t;
  func(5);
  std::cerr << "----------" << std::endl;
  auto d = Test();
  Test e(std::move(d));
  Test f;
  f = std::move(e);

  return 0;
}
