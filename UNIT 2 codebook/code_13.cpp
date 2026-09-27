#include <iostream>
#include <string>

using namespace std;

class SecretData {
private:
  string secretKey = "MySuperSecretKey";
  friend class KeyInspector; // Grants access
};

class KeyInspector {
public:
  void inspect(const SecretData &data) const {
    cout << "Inspecting Secret: " << data.secretKey << '\n';
  }
};

int main() {
  SecretData data;
  KeyInspector inspector;
  inspector.inspect(data);
  return 0;
}