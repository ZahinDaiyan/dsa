#include <iostream>
#include <stdexcept>

class Array {
private:
    // =========================================================================
    // PRIVATE MEMBERS & HELPERS
    // =========================================================================
    int* dataPtr;           // Pointer to our dynamically allocated block of RAM
    int currentCapacity;    // The total amount of slots available in memory
    int length;             // The number of slots currently occupied by user data

    // Internal helper to double the size of the array when it runs out of space
    void resize() {
        reserve(currentCapacity * 2);
    }

public:
    // =========================================================================
    // LIFECYCLE (Constructor & Destructor)
    // =========================================================================
    
    // Constructor: Allocates initial memory block based on requested capacity
    Array(int capacity) {
        this->currentCapacity = capacity;
        this->length = 0;
        this->dataPtr = new int[capacity];
    }

    // Destructor: Cleans up memory when the object dies to prevent memory leaks
    ~Array() {
        delete[] dataPtr;
    }

    // =========================================================================
    // BASIC UTILITIES & STATE CHECKS
    // =========================================================================
    
    // Returns true if there are zero elements in the array
    bool isEmpty() { 
        return length == 0; 
    }
    
    // Returns how many items are actively stored inside
    int size() { 
        return length; 
    }
    
    // Returns total memory slots currently allocated
    int capacity() { 
        return currentCapacity; 
    }
    
    // Hands over the raw pointer to the memory block (for low-level C compatibility)
    int* data() { 
        return dataPtr; 
    }
    
    // Returns the very last item in the array without removing it
    int peek() {
        if (isEmpty()) throw std::runtime_error("Array is empty!");
        return dataPtr[length - 1]; // Elements are 0-indexed, so last is length - 1
    }

    // =========================================================================
    // MEMORY MANAGEMENT OPERATIONS
    // =========================================================================
    
    // Instantly drops length to 0. Fast because we don't clear memory, just ignore it.
    void clear() { 
        length = 0; 
    }

    // Pre-allocates a specific block of memory upfront to avoid future resizing lags
    void reserve(int newCapacity) {
        if (newCapacity <= currentCapacity) return; // Can't reserve less than we have

        int* newData = new int[newCapacity];       // Allocate larger room
        for (int i = 0; i < length; ++i) {
            newData[i] = dataPtr[i];               // Move data to new room
        }
        delete[] dataPtr;                          // Destroy the old, small room
        dataPtr = newData;                         // Point to the new room
        currentCapacity = newCapacity;
    }

    // Reclaims unused capacity back to the computer RAM, matching capacity to size
    void shrink_to_fit() {
        if (length == currentCapacity) return;     // Already perfectly fitting
        
        int newCap = (length == 0) ? 1 : length;   // Don't shrink down to 0 capacity
        
        int* newData = new int[newCap];
        for (int i = 0; i < length; ++i) {
            newData[i] = dataPtr[i];
        }
        delete[] dataPtr;
        dataPtr = newData;
        currentCapacity = newCap;
    }

    // =========================================================================
    // DATA MODIFIERS & ALGORITHMS
    // =========================================================================
    
    // Adds a new element to the very end of our active array
    void push_back(int value) {
        if (length == currentCapacity) {
            resize(); // Automatically grow if we hit the ceiling
        }
        dataPtr[length] = value;
        length++;
    }

    // Removes the very last element by dropping the length boundary down by 1
    void pop() {
        if (!isEmpty()) {
            length--;
        }
    }

    // Overwrites all currently active elements with a single value
    void fill(int value) {
        for (int i = 0; i < length; ++i) {
            dataPtr[i] = value;
        }
    }

    // Shifts elements right to force-insert a value at a specific index
    void insert_at(int index, int value) {
        if (index < 0 || index > length) {
            throw std::out_of_range("Index out of bounds!");
        }
        if (length == currentCapacity) {
            resize();
        }
        // Loop backwards, moving elements right, until we make a gap
        for (int i = length; i > index; --i) {
            dataPtr[i] = dataPtr[i - 1];
        }
        dataPtr[index] = value;
        length++;
    }

    // Overwrites an item by shifting all elements to its right one slot left
    void remove_at(int index) {
        if (index < 0 || index >= length) {
            throw std::out_of_range("Index out of bounds!");
        }
        // Close the gap by pulling elements left
        for (int i = index; i < length - 1; ++i) {
            dataPtr[i] = dataPtr[i + 1];
        }
        length--;
    }

    // =========================================================================
    // QUEUE BEHAVIOR
    // =========================================================================
    
    // Removes the front-most element (First In, First Out)
    void pop_front() {
        if (isEmpty()) throw std::runtime_error("Queue empty!");
        remove_at(0); // Shifting everything left takes O(N) time
    }

    // =========================================================================
    // OPERATOR OVERLOADING & ITERATORS
    // =========================================================================
    
    // Bracket operator for writing/reading: e.g., arr[0] = 5;
    int& operator[](int index) {
        if (index < 0 || index >= length) throw std::out_of_range("Index out of bounds!");
        return dataPtr[index];
    }

    // Read-only bracket operator used when the Array object itself is marked 'const'
    const int& operator[](int index) const {
        if (index < 0 || index >= length) throw std::out_of_range("Index out of bounds!");
        return dataPtr[index];
    }

    // Iterators: Provide memory markers so native range-based loops work flawlessly
    int* begin() { return dataPtr; }
    int* end()   { return dataPtr + length; }
};

int main(){

    return 0;
}
