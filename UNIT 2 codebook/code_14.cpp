#include <iostream>
#include <string>

using namespace std;

class CPU {
public:
  class Core {
  private:
    int coreId;

  public:
    explicit Core(int id) : coreId(id) {}
    void display() const { cout << "Core ID: " << coreId << '\n'; }
  };

  void runCore() const {
    Core core1(1);
    core1.display();
  }
};

int main() {
  CPU cpu;
  cpu.runCore();

  CPU::Core externalCore(2);
  externalCore.display();
  return 0;
}