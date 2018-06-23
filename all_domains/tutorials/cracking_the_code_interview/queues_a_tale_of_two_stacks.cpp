#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {

    public:
        stack<int> stack_newest_on_top, stack_oldest_on_top;
        void push(int x) {
          if (stack_newest_on_top.empty()) {
            stack_newest_on_top.push(x);
          }
          stack_oldest_on_top.push(x);
        }

        void pop() {
          if (!stack_newest_on_top.empty()) {
            // Remove from stack of newest.
            stack_newest_on_top.pop();
            // Remove from stack of oldest.
            size_t num_elems_behind_newest = stack_oldest_on_top.size() - 1;
            for (size_t ii = 1; ii <= num_elems_behind_newest; ++ii) {
              // Use the stack of newest as a buffer.
              stack_newest_on_top.push(stack_oldest_on_top.top());
              stack_oldest_on_top.pop();
            }
            stack_oldest_on_top.pop();
            // Ensure consistency of the two stacks.
            if (!stack_newest_on_top.empty()) {
              int new_newest = stack_newest_on_top.top();
              size_t stack_newest_on_top_size = stack_newest_on_top.size();
              for (size_t ii = 1; ii <= stack_newest_on_top_size; ++ii) {
                stack_oldest_on_top.push(stack_newest_on_top.top());
                stack_newest_on_top.pop();
              }
              stack_newest_on_top.push(new_newest);
            }
          }
        }

        int front() {
          return stack_newest_on_top.top();
        }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;

    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
