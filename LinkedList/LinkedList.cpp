#include <iostream>
using namespace std;

struct Node {
  int value;
  struct Node *next;
  Node() {
    value = 0;
    next = nullptr;
  }
  Node(int value) {
    this->value = value;
    this->next = nullptr;
  }
};

class LinkedList {
private:
  Node *head;

public:
  LinkedList() { head = nullptr; }

  void append(int value) {
    Node *newNode = new Node(value);

    if (head == nullptr) {
      head = newNode;
      return;
    }
    newNode->next = this->head;
    this->head = newNode;
  }

  void print() {
    Node *temp = head;

    if (head == nullptr) {
      cout << "List Empty" << endl;
      return;
    }

    while (temp != nullptr) {
      cout << temp->value << " ";
      temp = temp->next;
    }
  }
};

int main() {

  LinkedList list;
  list.append(5);
  list.append(10);
  list.append(15);
  list.append(20);
  list.append(25);

  list.print();

  return 0;
}
