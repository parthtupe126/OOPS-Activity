#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SmartDevice {
private:
  string deviceId;
  string deviceType;
  string location;
  bool status; // true: ON, false: OFF
  string lastUpdated;

public:
  SmartDevice(string id, string type, string loc, string time,
              bool initStatus = false)
      : deviceId(id), deviceType(type), location(loc), status(initStatus),
        lastUpdated(time) {}

  void turnOn(string time) {
    status = true;
    lastUpdated = time;
  }

  void turnOff(string time) {
    status = false;
    lastUpdated = time;
  }

  void toggleStatus(string time) {
    status = !status;
    lastUpdated = time;
  }

  string getId() const { return deviceId; }

  void displayStatus() const {
    cout << "ID: " << deviceId << " | Type: " << deviceType
         << " | Location: " << location
         << " | Status: " << (status ? "ON" : "OFF")
         << " | Last Updated: " << lastUpdated << endl;
  }
};

int main() {
  vector<SmartDevice> dashboard;

  dashboard.emplace_back("D101", "Light", "Living Room", "07:00 AM", false);
  dashboard.emplace_back("D102", "Thermostat", "Bedroom", "07:00 AM", true);
  dashboard.emplace_back("D103", "Camera", "Front Door", "07:00 AM", true);
  dashboard.emplace_back("D104", "Door Lock", "Main Entrance", "07:00 AM",
                         true);

  cout << "================ SMART HOME DASHBOARD ================" << endl;
  for (const auto &device : dashboard) {
    device.displayStatus();
  }

  cout << "\n--- Updating Devices ---" << endl;
  dashboard[0].turnOn("08:15 AM");
  dashboard[1].turnOff("08:30 AM");

  cout << "\n================ UPDATED DASHBOARD ================" << endl;
  for (const auto &device : dashboard) {
    device.displayStatus();
  }

  return 0;
}