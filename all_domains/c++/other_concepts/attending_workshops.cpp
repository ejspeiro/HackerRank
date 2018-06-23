// Copyright 2018 Eduardo Sanchez
#include<bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::sort;

// Define the structs Workshops and Available_Workshops.
// Implement the functions initialize and CalculateMaxWorkshops
struct Workshop {
  int start_time;  // Start time.
  int duration;  // Duration of the workshop.
  int end_time;  // End time of the workshop.
};

struct Available_Workshops {
  int nn;  // Number of workshops the student has signed up for.
  Workshop *signed_up_for;  // Collection of actual workshops.
};

Available_Workshops *initialize(int *start_time, int *duration, int n) {
  if (n > 1 && start_time && duration) {
    Available_Workshops *ptr{};  // Pointer to structure.

    ptr = new Available_Workshops[n];
    if (ptr != nullptr) {
      ptr->signed_up_for = new Workshop[n];
      if (ptr->signed_up_for != nullptr) {
        for (int ii = 0; ii < n; ++ii) {
          Workshop ww;  // New workshop.
          ww.start_time = start_time[ii];
          ww.duration = duration[ii];
          ww.end_time = ww.start_time + ww.duration;
          ptr->signed_up_for[ii] = ww;
        }
      }
      ptr->nn = n;
    }
    return ptr;
  }
  return nullptr;
}

int CalculateMaxWorkshops(Available_Workshops *ptr) {
  if (ptr != nullptr) {
    std::sort(ptr->signed_up_for,
              ptr->signed_up_for + ptr->nn,
              [] (Workshop &xx, Workshop &yy) {
                return xx.end_time < yy.end_time;
              });

    int maxWorkshops{};
    int currentEnd{};
    for (int i = 0; i < ptr->nn; i++) {
      if (ptr->signed_up_for[i].start_time >= currentEnd) {
        maxWorkshops++;
        currentEnd = ptr->signed_up_for[i].end_time;
      }
    }
    return maxWorkshops;
  } else {
    return -1;
  }
}

int main(int argc, char *argv[]) {
  int n;  // Number of workshops.

  cin >> n;
  // create arrays of unknown size n
  int* start_time = new int[n];
  int* duration = new int[n];

  for (int i = 0 ; i < n; i++) {
    cin >> start_time[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> duration[i];
  }

  Available_Workshops *ptr;
  ptr = initialize(start_time, duration, n);
  cout << CalculateMaxWorkshops(ptr) << endl;
  return 0;
}
