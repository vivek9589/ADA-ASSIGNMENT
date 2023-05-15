#include <bits/stdc++.h>
using namespace std;

// A utility function to find maximum of two integers
int max(int a, int b) {
	return (a > b) ? a : b;
}

// A utility function to find maximum of three integers
int max(int a, int b, int c) {
	return max(max(a, b), c);
}

// Find the maximum possible sum in arr[] such that arr[m]
// is part of it
int maxCrossingSum(int arr[], int l, int m, int h) {
	// Include elements on left of mid.
	int sum = 0;
	int left_sum = INT_MIN;
	for (int i = m; i >= l; i--) {
		sum = sum + arr[i];
		if (sum > left_sum)
			left_sum = sum;
	}

	// Include elements on right of mid
	sum = 0;
	int right_sum = INT_MIN;
	for (int i = m; i <= h; i++) {
		sum = sum + arr[i];
		if (sum > right_sum)
			right_sum = sum;
	}

	return max(left_sum + right_sum - arr[m], left_sum, right_sum);
}

int maxSubArraySum(int arr[], int l, int h) {
	if (l > h)
		return INT_MIN;
	// Base Case: Only one element
	if (l == h)
		return arr[l];

	// Find middle point
	int m = (l + h) / 2;

	/* Return maximum of following three possible cases
			a) Maximum subarray sum in left half
			b) Maximum subarray sum in right half
			c) Maximum subarray sum such that the subarray
	crosses the midpoint */
	return max(maxSubArraySum(arr, l, m - 1),
			maxSubArraySum(arr, m + 1, h),
			maxCrossingSum(arr, l, m, h));
}

int main() {
	int arr[] = { 2, 3, 4, 5, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int max_sum = maxSubArraySum(arr, 0, n - 1);
	cout << "Maximum contiguous sum is " << max_sum;
	return 0;
}
