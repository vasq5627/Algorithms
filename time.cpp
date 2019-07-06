#include <iostream>
using namespace std;

int get_hours(int seconds) {
  int hours = 0;
  while(seconds >= 3600) {
    hours++;
    seconds -= 3600;
  }

  return hours;
}

bool isAM(int seconds) {        
  int hours = seconds / 3600;
  int flips = 0;
  while (hours >= 12) {
    hours -= 12;
    flips++;
  }
  if (flips % 2 == 0) {
    return true;
  }
  return false;
}

// get and format minutes
int get_minutes(int seconds) {
  while(seconds >= 3600) {
    seconds -= 3600;
  }
  
  return seconds/60;
}

// format seconds for time
int get_seconds(int seconds) {
  while (seconds >= 60) {
    seconds %= 60;
  }
  return seconds;
}

void display_time(int seconds) {
  cout << get_hours(seconds);
  
  // format minutes
  cout << ":";
  if (get_minutes(seconds) < 10) {
    cout << "0" << get_minutes(seconds);
  }
  else {
    cout << get_minutes(seconds);
  }
  
  // format seconds
  cout << ":";
  if (get_seconds(seconds) < 10) {
    cout << "0";
  }
  cout << get_seconds(seconds);
  
  if (isAM(seconds)) {
    cout << " am" << endl;
  }
  else {
    cout << " pm" << endl;
  }
}

int main() {
  for (;;) {
    int seconds;
    cin >> seconds;
    if (seconds == -1) {
      break;
    }
    display_time(seconds);
  }
  return 0;
}
