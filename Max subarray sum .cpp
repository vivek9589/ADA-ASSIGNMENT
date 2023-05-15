#include <stdio.h>
const int INT_MIN = -1e9;
int maximumSubarraySum(int arr[], int n) {
 int maxSum = INT_MIN;
 int currSum = 0;
 int i = 0;
 for (; i <= n - 1; i++) {
   currSum += arr[i];
 
   if (currSum > maxSum) {
     maxSum = currSum;
   }
 
   if (currSum < 0) {
     currSum = 0;
   }
 }
 
 return maxSum;
 
}
int main() {
   // Your code goes here
   int a[] = {1, 3, 8, -2, 6, -8, 5};
   printf("%d", maximumSubarraySum(a, 7));
   return 0;
}

Time complexity: O(N), Where N is the size of the array.
Space complexity: O(1)

Brute force approach: 

Time Complexity: O(n^3) 

Space Complexity: O(1)
