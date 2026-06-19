#include <iostream>
#include <cstddef>
#include <stdexcept>

using namespace std;

class Array {
private:
	int* array;
	int capacity;
	int leneth;
  void resize(){
    reserve(capacity * 2);
	}

public:
	Array(int capacity){
		this->capacity = capacity;
    this->length = 0;
    this->array = new int[capacity];
	}

	~Array(){
		delete[] array;
	}

 	bool isEmpty(){
		return length==0;
	}
  
  int size() {
    return length;
  }

  int* data() {
    return array;
  }

  int* begin() { return array; }
  int* end() { return array+length; }
  
  void clear(){
    length = 0;
  }

  void reserve(int c){
    if(c <= this->capacity) return;

    int* newData = new int[c];
    for (int i = 0; i < length; ++i){
      newData[i] = array[i];
    }
    delete[] array;
    array = newData;
    capacity = c;
  }

  void shrink_to_fit(){
    if(length == capacity) return;

    int newCapacity = (length == 0) ? 1 : length;

    int * newArray = new int[newCapacity];
    for ( int i = 0;  i < newCapacity; ++i){
      newArray[i] = array[i];
    }
    delete array;
    array = newArray;
    capacity = newCapacity;
  }

  // Array Oparations 

  void push_back(int value){
    if(length == capacity) resize();
    array[length] = value;
    length++;
  }

  int peek(){
    if (isEmpty()) throw std::runtime_error("Array is Empty");
    return array[length-1];
  }

  void pop_back(){
    if(!isEmpty()) length--;
  }

  void fill(int value){
    if(isEmpty) return;
    for(int i = 0 ; i < length; ++i) array[i] = value;j
  }
  
  void insertAt(int pos , int value){
    if(pos >= length || pos < 0) 
       throw std::out_of_range("Out of bounds");
    if(length == capacity) resize();
    for(int i = length; i > pos; --i){
      array[i] = array[i-1];
    }
    array[pos] = value;
    length++;
  }

  void removeAt(int pos){
    if (pos >= length || pos < 0) throw std::out_of_range("Out of bounds");
    for(int i = pos; i < length; ++i){
      array[i] = array[i+1];
    }
    length--;
  }
  void pop_front(){
    if(isEmpty()) throw std::runtime_error("Array is Empyt");
    removeAt(0);
  }

  int& operator[](int pos){
    if(pos < 0 || pos >= length) throw std::out_of_range("Out of bounds");
    return array[pos];
  }

  const int& operator[](int pos) const {
    if (index < 0 || index >= length) throw std::out_of_range("Out of bounds");
    return array[pos];
  }







































};


