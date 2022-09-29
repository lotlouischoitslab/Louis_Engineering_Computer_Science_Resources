#include <iostream> 
#include <stdlib.h>
using namespace std;

int linearSearch(int arr[], int num) {
    int n = sizeof(arr)/ sizeof(arr[0]); //length of an array
   for(int i = 0; i < n; i++) {
       if(arr[i] == num) {
           return i;
       }
   }
   return -1;
}

int main() {
   int arr[] = {1, 3, 7, 15, 18, 20, 25, 33, 36, 40};
   int n = sizeof(arr)/ sizeof(arr[0]); //length of an array
   int num;
   cout << "Enter the number to search: ";
   cin >> num;
   
   int index = linearSearch (arr, num);
   if (index == -1){
      cout<< num <<" is not present in the array";
   } else{
      cout<< num <<" is present at index "<< index <<" in the array";
   }
   return 0;
}

