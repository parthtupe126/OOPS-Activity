#include <iostream>
#include <string>
#include <utility>

using namespace std;

class Academic {
protected:
  double gpa;

public:
  explicit Academic(double studentGpa) : gpa(studentGpa) {}
  virtual ~Academic() = default;
  void showGpa() const { cout << "GPA: " << gpa << '\n'; }
};

class Sports {
protected:
  string sportName;

public:
  explicit Sports(string sport) : sportName(move(sport)) {}
  virtual ~Sports() = default;
  void showSport() const { cout << "Sport: " << sportName << '\n'; }
};

class StudentAthlete : public Academic, public Sports {
public:
  StudentAthlete(double studentGpa, string sport)
      : Academic(studentGpa), Sports(move(sport)) {}
  void displayProfile() const {
    showGpa();
    showSport();
  }
};

int main() {
  StudentAthlete athlete(8.8, "Badminton");
  athlete.displayProfile();
  return 0;
}