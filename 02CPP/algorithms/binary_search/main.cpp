#include <iostream> 
#include <stdlib.h>
using namespace std;

int binarySearch(int* arr, int start_idx, int end_idx, int num) {
   if (start_idx <= end_idx) {
      int mid = (start_idx + end_idx)/2;
      if (arr[mid] == num)
         return mid ;
      if (arr[mid] > num)
         return binarySearch(arr, start_idx, mid-1, num);
      if (arr[mid] < num)
         return binarySearch(arr, mid+1, end_idx, num);
   }
   return -1;
}

int main() {
   int my_array[] = {1, 3, 7, 15, 18, 20, 25, 33, 36, 40};
   int* arr = my_array;
   int n = sizeof(my_array)/ sizeof(my_array[0]); //length of an array
   int num;
   cout << "Enter the number to search: ";
   cin >> num;
   
   int index = binarySearch (arr, 0, n-1, num);
   if (index == -1){
      cout<< num <<" is not present in the array";
   } else{
      cout<< num <<" is present at index "<< index <<" in the array";
   }
   return 0;
}

