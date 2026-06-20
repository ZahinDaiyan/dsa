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
  Node *tail;

public:
  List()
  {
    head = nullptr;
    tail = nullptr;
  }

  void insert(int value)
  {
    Node *newNode = new Node(value);
    if (head == nullptr)
    {
      head = newNode;
      tail = newNode;
      return;
    }
    tail->next = newNode;
    tail = newNode;
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

    Node *temp = head;
    while (temp->next->next != nullptr)
    {
      temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
    tail = temp;
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
  int getLast()
  {
    if (head == nullptr)
      return -1;
    return tail->value;
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
    return l.getHead();
  }
  void print()
  {
    l.print();
  }
};

class Queue
{
private:
  List l;

public:
  Queue() {}
  ~Queue() {}

  void append(int value)
  {
    l.insert(value);
  }

  void dequeue()
  {
    l.removeFirst();
  }

  int front()
  {
    return l.getHead();
  }
};
struct DNode
{
  int value;
  DNode *next;
  DNode *prev;

  DNode(int value)
  {
    this->value = value;
    this->next = nullptr;
    this->prev = nullptr;
  }
};

class DoublyLinkedList
{
private:
  DNode *head;
  DNode *tail;

public:
  DoublyLinkedList()
  {
    head = nullptr;
    tail = nullptr;
  }
  void insert(int value)
  {
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
