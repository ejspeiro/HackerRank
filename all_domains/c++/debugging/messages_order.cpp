// Copyright 2018 Eduardo Sanchez
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


// Class Message is required to store a text value of type std::string and
// provide a public getter const string& get_text() which is expected to return
// this text value. Besides that, it should implement the < operator that will
// be used in fix_order() method of the recipient to fix the order of received
// messages. Feel free to implement any other methods and class/instance
// variables. In particular, you can implement any additional constructors, but
// make sure that you provide an empty constructor, i.e. the one without
// arguments.
class Message {
 public:
  Message() {}
  explicit Message(const std::string in): message_(in) {}
  Message(const Message &in) = default;
  bool operator<(const Message &rhs) {
    if (index < rhs.index) {
        return true;
    }
    return false;
  }
  const string& get_text() {
    return message_;
  }
  int index;
 private:
  std::string message_;  // Message content.
};

// Class MessageFactory is required to have an empty constructor, and implement
// a method Message create_message(const string& text) that is expected to
// return a Message object storing the value of text argument. Feel free to
// implement any other methods and class/instance variables of this class.
class MessageFactory {
 public:
    MessageFactory() {}
    Message create_message(const string& text) {
      num++;
      Message output_message(text);
      output_message.index = num;
      return output_message;
    }
    static int num;
};

int MessageFactory::num = 0;

class Recipient {
 public:
  Recipient() {}
  void receive(const Message& msg) {
    messages_.push_back(msg);
  }
  void print_messages() {
    fix_order();
    for (auto& msg : messages_) {
      cout << msg.get_text() << endl;
    }
    messages_.clear();
  }
 private:
  void fix_order() {
    sort(messages_.begin(), messages_.end());
  }
  vector<Message> messages_;
};

class Network {
 public:
  static void send_messages(vector<Message> messages, Recipient& recipient) {
    // simulates the unpredictable network, where sent messages might arrive in
    // unspecified order
    random_shuffle(messages.begin(), messages.end());
    for (auto msg : messages) {
        recipient.receive(msg);
    }
  }
};

int main() {
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    while (getline(cin, text)) {
      messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}
