#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

// Base class representing generic Media[cite: 3]
class Media {
protected:
  string title;
  double sizeInMB;

public:
  Media(string t, double s) : title(t), sizeInMB(s) {}

  // Pure virtual functions for polymorphic playback controls[cite: 3]
  virtual void play() const = 0;
  virtual void pause() const = 0;
  virtual void stop() const = 0;

  // Virtual function to display general details
  virtual void showDetails() const {
    cout << "Title: " << title << " | Size: " << sizeInMB << " MB";
  }

  // Virtual destructor for safe cleanup through base pointers[cite: 3]
  virtual ~Media() = default;
};

// Derived class for Audio files[cite: 3]
class Audio : public Media {
private:
  string artist;

public:
  Audio(string t, double s, string a) : Media(t, s), artist(a) {}

  void play() const override {
    cout << "Playing audio track: " << title << " by " << artist << endl;
  }

  void pause() const override { cout << "Audio paused: " << title << endl; }

  void stop() const override { cout << "Audio stopped: " << title << endl; }

  void showDetails() const override {
    cout << "[Audio] ";
    Media::showDetails();
    cout << " | Artist: " << artist << endl;
  }
};

// Derived class for Video files[cite: 3]
class Video : public Media {
private:
  string resolution;

public:
  Video(string t, double s, string res) : Media(t, s), resolution(res) {}

  void play() const override {
    cout << "Playing video: " << title << " in " << resolution << endl;
  }

  void pause() const override { cout << "Video paused: " << title << endl; }

  void stop() const override { cout << "Video stopped: " << title << endl; }

  void showDetails() const override {
    cout << "[Video] ";
    Media::showDetails();
    cout << " | Resolution: " << resolution << endl;
  }
};

// Derived class for Image files[cite: 3]
class Image : public Media {
private:
  string format;

public:
  Image(string t, double s, string fmt) : Media(t, s), format(fmt) {}

  void play() const override {
    // "Playing" an image means opening/viewing it
    cout << "Displaying image: " << title << " on screen" << endl;
  }

  void pause() const override {
    // Pausing an image can freeze preview or slideshow
    cout << "Image slideshow paused: " << title << endl;
  }

  void stop() const override {
    cout << "Closing image viewer: " << title << endl;
  }

  void showDetails() const override {
    cout << "[Image] ";
    Media::showDetails();
    cout << " | Format: " << format << endl;
  }
};

int main() {
  // Collection of base-class smart pointers managing different media
  // types[cite: 3]
  vector<unique_ptr<Media>> playlist;

  // Adding different media objects to the playlist
  playlist.push_back(make_unique<Audio>("Believer", 7.5, "Imagine Dragons"));
  playlist.push_back(
      make_unique<Video>("Inception_Trailer", 150.0, "1080p FHD"));
  playlist.push_back(make_unique<Image>("Sunset", 4.2, "JPEG"));

  cout << "== Media Player Playlist Details ==" << endl;
  for (const auto &item : playlist) {
    item->showDetails();
  }
  cout << endl;

  cout << "== Executing Controls on All Media ==" << endl;
  for (const auto &item : playlist) {
    item->play();
    item->pause();
    item->stop();
    cout << "----------------------------------------" << endl;
  }

  return 0;
}