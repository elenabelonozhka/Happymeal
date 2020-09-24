#include <iostream>
#include <chrono>
#include <math.h>

double TestCondition(int N) {
  double result = 0;

  for (int i = 1; i <= N; i++) {
    if (i % 2 == 0)
      result += 1.0 / std::pow(i, 1.5);
    else
      result -= 1.0 / std::pow(i, 1.5);
  }

  return result;
}

double TestExceptions(int N) {
  double result = 0;

  for (int i = 1; i <= N; i++) {
    try {
      if (i % 2 == 0)
        throw 1;
      else
        throw -1;
    } catch (int sign) {
       result += sign / std::pow(i, 1.5);
    }
  }

  return result;
}


/*
int main() {
  auto start = std::chrono::steady_clock::now();
  double result = TestCondition(1000000);
  auto finish = std::chrono::steady_clock::now();

  std::cout << "Series with condition: "
            << std::chrono::duration_cast<std::chrono::milliseconds>(
                    finish - start).count() / 1000.0
            << "s" << std::endl;

  std::cout << "Result: " << result << std::endl;

  start = std::chrono::steady_clock::now();
  result = TestCondition(1000000);
  finish = std::chrono::steady_clock::now();

  std::cout << "Series with exceptions: "
            << std::chrono::duration_cast<std::chrono::milliseconds>(
                    finish - start).count() / 1000.0
            << "s" << std::endl;

  std::cout << "Result: " << result << std::endl;

 return 0;
}
*/

int main() {
  using namespace std;
  using namespace chrono;

  auto start = steady_clock::now();
  double result = TestCondition(1000000);
  auto finish = steady_clock::now();

  std::cout << "Series with condition: "
            << duration_cast<milliseconds>(finish - start).count() / 1000.0
            << "s" << std::endl;

  std::cout << "Result: " << result << std::endl;

  start = steady_clock::now();
  result = TestExceptions(1000000);
  finish = steady_clock::now();

  std::cout << "Series with exceptions: "
            << duration_cast<milliseconds>(finish - start).count() / 1000.0
            << "s" << std::endl;

  std::cout << "Result: " << result << std::endl;

 return 0;
}

