#include <iostream>
using namespace std;

struct Node
{
  int value;
  Node *next;

  Node(int value)
  {
    this->value = value;
    this->next = nullptr;
  }
};

class List
{
private:
  Node *head;

public:
  List() { head = nullptr; }

  void insert(int value)
  {
    Node *newNode = new Node(value);
    if (head == nullptr)
    {
      head = newNode;
      return;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
      temp = temp->next;
    }
    temp->next = newNode;
  }

  void insertFirst(int value)
  {
    Node *newNOde = new Node(value);
    newNOde->next = head;
    head = newNOde;
  }

  void removeLast()
  {
    if (head == nullptr)
    {
      cout << "List Empty";
      return;
    }
    if (head->next == nullptr)
    {
      delete head;
      head = nullptr;
      return;
    }

    Node *temp = head;
    while (temp->next->next != nullptr)
    {
      temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
  }

  void removeFirst()
  {
    if (head == nullptr)
    {
      cout << "List Empty";
      return;
    }

    Node *temp = head;
    head = head->next;
    delete temp;
  }

  int getHead()
  {
    if (head == nullptr)
      return -1;
    return head->value;
  }

  void print()
  {
    if (head == nullptr)
    {
      cout << "List Empty";
      return;
    }
    Node *temp = head;
    while (temp != nullptr)
    {
      cout << temp->value << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};

class Stack
{
private:
  List l;

public:
  Stack() {}
  ~Stack() {}

  void push(int value)
  {
    l.insertFirst(value);
  }
  void pop()
  {
    l.removeFirst();
  }
  int peek()
  {
    int n = l.getHead();
  }
  void print()
  {
    l.print();
  }
};

int main()
{

  List list;
  list.insert(80);
  list.insert(50);
  list.insert(60);
  list.insert(80);
  list.insert(90);
  list.print();

  list.removeLast();
  list.print();

  Stack s;
  s.push(45);
  s.push(65);
  s.push(85);
  s.push(65);
  s.peek();
  s.pop();
  s.peek();
  s.print();

  return 0;
}
