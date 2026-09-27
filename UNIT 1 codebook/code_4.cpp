#include <iostream>
using namespace std;

// Function prototype/declaration
int add(int, int);

int main() {
  int a = 10, b = 20;

  // Call add() function and print returned result
  cout << "Sum = " << add(a, b) << endl;

  return 0;
}

// Function definition
int add(int x, int y) {
  // Calculate and return total
  return x + y;
}