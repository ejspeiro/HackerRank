#include <iostream>

#include <vector>

using namespace std;

// Provided by HackerRank:

class Person{
    protected:
        string firstName;
        string lastName;
        int id;
    public:
        Person(string firstName, string lastName, int identification){
            this->firstName = firstName;
            this->lastName = lastName;
            this->id = identification;
        }
        void printPerson(){
            cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n";
        }
};

// Actual solution:

#include <numeric>

class Student: public Person{
  private:
    vector<int> testScores;
  public:
    Student(string firstName,
            string lastName,
            int identification,
            vector<int> scores);

    char calculate() const;
};

Student::Student(string firstName,
                 string lastName,
                 int identification,
                 vector<int> scores): Person(firstName, lastName, identification) {

  testScores = scores;
}

char Student::calculate() const {

  int aa = accumulate(testScores.begin(), testScores.end(), 0);
  aa = aa/testScores.size();

  if (aa < 40) {
    return 'T';
  } else if (40 <= aa && aa < 55) {
    return 'D';
  } else if (55 <= aa && aa < 70) {
    return 'P';
  } else if (70 <= aa && aa < 80) {
    return 'A';
  } else if (80 <= aa && aa < 90) {
    return 'E';
  } else if (90 <= aa && aa <= 100) {
    return 'O';
  } else {
    return '\0';
  }
}

// Provided by HackerRank:

int main() {
    string firstName;
    string lastName;
    int id;
    int numScores;
    cin >> firstName >> lastName >> id >> numScores;
    vector<int> scores;
    for(int i = 0; i < numScores; i++){
        int tmpScore;
        cin >> tmpScore;
        scores.push_back(tmpScore);
    }
    Student* s = new Student(firstName, lastName, id, scores);
    s->printPerson();
    cout << "Grade: " << s->calculate() << "\n";
    return 0;
}
