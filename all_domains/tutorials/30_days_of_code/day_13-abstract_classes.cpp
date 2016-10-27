#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Book{
  protected:
    string title;
    string author;
  public:
    Book(string t,string a){
      title = t;
      author = a;
    }
  virtual void display() = 0;
};

//Write MyBook class
class MyBook: Book {
  public:
    explicit MyBook(string title, string author, int price);
    void display();
  private:
    int price_;
};

MyBook::MyBook(string title, string author, int price):
    Book(title, author), price_(price) {}

void MyBook::display() {

  cout << "Title: " << Book::title << endl;
  cout << "Author: " << Book::author << endl;
  cout << "Price: " << price_ << endl;
}

int main() {

    string title,author;
    int price;
    getline(cin,title);
    getline(cin,author);
    cin>>price;
    MyBook novel(title,author,price);
    novel.display();
    return 0;
}
