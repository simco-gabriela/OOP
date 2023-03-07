#include <iostream>
#include "Math.h"

using namespace std;

int main() {
  int x = 2, y = 3, z = 4;
  double a = 1.5, b = 2.5, c = 3.5;

  cout << "Math::Add(int, int): " << Math::Add(x, y) << endl;
  cout << "Math::Add(int, int, int): " << Math::Add(x, y, z) << endl;
  cout << "Math::Add(double, double): " << Math::Add(a, b) << endl;
  cout << "Math::Add(double, double, double): " << Math::Add(a, b, c) << endl;
  cout << "Math::Add(int count, ...): " << Math::Add(5, 1, 2, 3, 4, 5) << endl;

  cout << "Math::Mul(int, int): " << Math::Mul(x, y) << endl;
  cout << "Math::Mul(int, int, int): " << Math::Mul(x, y, z) << endl;
  cout << "Math::Mul(double, double): " << Math::Mul(a, b) << endl;
  cout << "Math::Mul(double, double, double): " << Math::Mul(a, b, c) << endl;

  char* str1 = "hello ";
  char* str2 = "world";
  char* result = Math::Add(str1, str2);
  if (result != nullptr) {
    cout << "Math::Add(const char*, const char*): " << result << endl;
    delete[] result;
  }


  return 0;
}
