#include <iostream>
using namespace std;

int main() {
  // Array storing 5 integer marks
  int marks[5] = {78, 82, 91, 67, 88};

  // For loop runs from index 0 to 4
  for (int i = 0; i < 5; i++) {
    // Print each element with space
    cout << marks[i] << " ";
  }

  return 0;
}