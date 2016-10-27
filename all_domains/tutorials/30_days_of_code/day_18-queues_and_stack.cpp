#include <iostream>

#include <string>
#include <queue>
#include <stack>

using namespace std;

class Solution {
  public:
    void pushCharacter(char ch) {
      stack_.push(ch);
    }
    void enqueueCharacter(char ch) {
      queue_.push(ch);
    }
    char popCharacter() {
      auto aux = stack_.top();
      stack_.pop();
      return aux;
    }
    char dequeueCharacter() {
      auto aux = queue_.front();
      queue_.pop();
      return aux;
    }

  private:
    //Write your code here
    std::queue<char> queue_;
    std::stack<char> stack_;
};

int main() {
    // read the string s.
    string s;
    getline(cin, s);

    // create the Solution class object p.
    Solution obj;

    // push/enqueue all the characters of string s to stack.
    for (int i = 0; i < s.length(); i++) {
        obj.pushCharacter(s[i]);
        obj.enqueueCharacter(s[i]);
    }

    bool isPalindrome = true;

    // pop the top character from stack.
    // dequeue the first character from queue.
    // compare both the characters.
    for (int i = 0; i < s.length() / 2; i++) {
        if (obj.popCharacter() != obj.dequeueCharacter()) {
            isPalindrome = false;

            break;
        }
    }

    // finally print whether string s is palindrome or not.
    if (isPalindrome) {
        cout << "The word, " << s << ", is a palindrome.";
    } else {
        cout << "The word, " << s << ", is not a palindrome.";
    }

    return 0;
}
