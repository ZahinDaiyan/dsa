#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> &arr, int value){
  int n = arr.size();
  int l = 0;
  int r = n - 1;
  while (l<=r) {
    int mid = (l+(r-l))/ 2;
    if(arr[mid] == value){
      cout << mid << endl;
      return mid;
    }
    else if(arr[mid] > value) {
      r = mid -1;
    }
    else {
      l = mid+1;
    }
  }
  return -1;
}

int main()
{
  vector<int> a = {5,10,15,20};
  binary_search(a,5);
}
