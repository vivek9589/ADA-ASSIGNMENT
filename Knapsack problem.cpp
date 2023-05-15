// A Dynamic Programming based
// solution for 0-1 Knapsack Problem: Greedy algorithm
#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }


int knapSack(int W, int wt[], int val[], int n)
{
	int i, w;
	int K[n + 1][W + 1];

	for (i = 0; i <= n; i++) {
		for (w = 0; w <= W; w++) {
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1]
								+ K[i - 1][w - wt[i - 1]],
							K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}

	return K[n][W];
}

int main()
{
	int profit[] = { 60, 100, 120 };
	int weight[] = { 10, 20, 30 };
	int W = 50;
	int n = sizeof(profit) / sizeof(profit[0]);
	printf("%d", knapSack(W, weight, profit, n));
	return 0;
}

Time Complexity: O(N * W). where ‘N’ is the number of elements and ‘W’ is capacity. 
Auxiliary Space: O(N * W). The use of a 2-D array of size ‘N*W’.


Knapsack Problem Greedy algorithm :

The complexity of the algorithm:

If using a simple sort algorithm (selection, bubble…) then the complexity of the whole problem is O(n2).
If using quick sort or merge sort then the complexity of the whole problem is O(nlogn).
