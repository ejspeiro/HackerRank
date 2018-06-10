// Copyright 2018 Eduardo Sanchez
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>

using std::cin;
using std::cout;
using std::endl;

struct Node{
  Node* next;
  Node* prev;
  int value;
  int key;

  Node(Node* p, Node* n, int k, int val):
      prev(p), next(n), key(k), value(val) {}
  Node(int k, int val): prev(NULL), next(NULL), key(k), value(val) {}
};

class Cache{
 protected:
  map<int, Node*> mp;  // map the key to the node in the linked list
  int cp;  // capacity
  Node *tail;  // double linked list tail pointer
  Node *head;  // double linked list head pointer
  virtual void set(int, int) = 0;  // set function
  virtual int get(int) = 0;  // get function
};

class LRUCache: public Cache {
 public:
    explicit LRUCache(int capacity);
    void set(int, int);
    int get(int);
 private:
    int num_added_;  // Number of items I have added to the LRUCache.
};

LRUCache::LRUCache(int capacity) {
  cp = capacity;
  num_added_ = 0;
  head = nullptr;
  tail = nullptr;
}

void LRUCache::set(int k, int v) {
  if (mp.find(k) != mp.end()) {
    mp.at(k)->value = v;
  } else {
    Node *new_element = new Node(k, v);
    // Is the cache full?
    if (num_added_ < cp) {
      // Is list empty? (Tested)
      if (head == nullptr) {
        head = new_element;
        tail = new_element;
      } else {  // (Tested)
        head->prev = new_element;
        new_element->next = head;
        head = head->prev;
      }
      num_added_++;
    } else {
      // Discard least recently used element.
      auto tail_tmp = tail;
      tail = tail->prev;
      tail->next = nullptr;
      mp.erase(tail_tmp->key);
      delete tail_tmp;
      // Insert new element.
      new_element->next = head;
      head->prev = new_element;
      head = head->prev;
    }
    mp.insert({k, new_element});
  }
}

int LRUCache::get(int k) {
  auto pos_key = mp.find(k);
  if (pos_key != mp.end()) {
    return (pos_key->second)->value;
  }
  return -1;
}

int main() {
  int n, capacity, i;

  cin >> n >> capacity;

  LRUCache l(capacity);

  for (i = 0; i < n; i++) {
    string command;

    cin >> command;
    if (command == "get") {
      int key;

      cin >> key;
      cout << l.get(key) << endl;
    } else if (command == "set") {
      int key, value;

      cin >> key >> value;
      l.set(key, value);
    }
  }
}
