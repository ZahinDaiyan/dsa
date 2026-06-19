#include<iostream>
#include<cstddef>

template <typename T, std::size_t N>
class MyArray
{
	private:
		// A raw blMyArrayock of bytes. We allocate exactly enogh bytes: (Size of Type * Number of Elements)
		char m_rawMemory[sizeof(T) * N];


public:
	MyArray(){
		// In a production lib, we might run "placement new" to construct objects
		// but for raw ints, the bytes are just sitting there waitging to be used
	}

	// This is where the magic happens : Recreating the arr[index] math!
	T& operator[](std::size_t index){
		// 1. Get the starting address of our raw byte block
		char* baseAddress = m_rawMemory;

		// 2. Do the manual pointer math: Jump forward by (index * size of the type)
		char* elementAddress = baseAddress + (index * sizeof(T));

		// 3. "Cast" the raw byte pointer back into a pointer of our actual Type (T*)
		T* typedPointer = reinterpret_cast<T*>(elementAddress);

		// 4 Defrence it to return to the actual value / slot.
		return *typedPointer;

	}

	// A handy function to return the fixed size
	std::size_t size() const {return N;}
};

int main(){
	MyArray<int, 5> arr;

	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 40;
	arr[4] = 50;

	// Print
	for (std::size_t i = 0; i < arr.size(); ++i){
		std::cout<<"arr["<<i<<"] = "<<arr[i] << "\n";
	}

	// Let's Look  at the memory address!
	std::cout << "\n Memory Address \n";
	for(std::size_t i = 0 ; i < arr.size(); ++i){
		std::cout<<"Address of arr["<<i<<"]:" << &arr[i] << "\n";
	}

	return 0;
}
