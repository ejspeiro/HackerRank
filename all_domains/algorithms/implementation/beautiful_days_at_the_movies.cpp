// Copyright 2018 Eduardo Sanchez
#include <iostream>
#include <cmath>
#include <vector>
#include <list>

class BeautifulDayDetector {
 public:
  explicit BeautifulDayDetector(int kk): kk_(kk) {}
  bool isBeautifulDay(int nn) const noexcept {
    int nn_inverse{inverseOfNumber(nn)};
    return abs(nn - nn_inverse)%kk_? false: true;
  }

 private:
  int inverseOfNumber(int nn) const noexcept {
    int kTen{10};  // Ten as a constant.
    std::list<int> reversed_number{};  // Stack to reverse the number.

    while (nn != 0) {
      int remainder{nn%kTen};  // Remainder of the division.

      reversed_number.push_front(remainder);
      nn /= kTen;
    }

    int reversion{};  // Actual reversed number.
    int exponent{};  // Exponent needed to reconstruct the inversion.

    for (auto ii : reversed_number) {
      reversion += ii*pow(kTen, exponent++);
    }
    return reversion;
  }
  int kk_;  // Beautiful constant.
};

class RefCounter {
 public:
  void AddRef() {
    count++;
  }
  int RelRef() {
    return --count;
  }
  int Count() {
    return count;
  }
 private:
  int count;
};

template <typename TObject>
class MySharedPtr {
 public:
  // Default constructor.
  MySharedPtr(): target_(nullptr), reference(nullptr) {
    reference = new RefCounter();
    reference->AddRef();
  }
  // Copy constructor.
  MySharedPtr(const MySharedPtr<TObject> &sp) : target_(sp.target_),
      reference(sp.reference) {
    reference->AddRef();
  }
  // Given target constructor.
  explicit MySharedPtr(TObject *target): target_(target),
      reference(nullptr) {
    reference = new RefCounter();
    reference->AddRef();
  }
  ~MySharedPtr() {
    if (reference->RelRef() == 0) {
      delete target_;
      delete reference;
    }
  }
  TObject& operator*() {
      return *target_;
  }
  TObject* operator->() {
      return target_;
  }
  MySharedPtr<TObject> &operator=(const MySharedPtr<TObject> &sp) {
    if (this != &sp) {
      if (reference->RelRef() == 0) {
        delete target_;
        delete reference;
      }
      target_ = sp.pData;
      reference = sp.reference;
      reference->AddRef();
    }
    return *this;
  }
  int use_count() {
    return reference->Count();
  }

 private:
  TObject *target_;  // Pointed object.
  RefCounter* reference;  // Reference count
};

int main() {
  int ii{};  // Beginning of the range.
  int jj{};  // End of the range.
  int kk{};  // Beautiful constant.

  std::cin >> ii >> jj >> kk;

  MySharedPtr<BeautifulDayDetector> ptr(new BeautifulDayDetector(kk));

  std::vector<MySharedPtr<BeautifulDayDetector>> the_days;

  for (int nn = ii; nn <= jj; ++nn) {
    the_days.push_back(ptr);
  }

  int num_beautiful_days{};  // Number of beautiful days in range.

  for (int nn = 0; nn < the_days.size(); ++nn) {
    num_beautiful_days += (the_days.at(nn))->isBeautifulDay(nn + ii);
  }
  if (ptr.use_count() == (jj - ii + 2)) {
    std::cout << num_beautiful_days << std::endl;
  }
}
