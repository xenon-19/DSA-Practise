// Question
// There are 2 sorted arrays A and B of size n each. 
// Write an algorithm to find the median of the array obtained after merging the above 2 arrays. 
// The complexity should be O(log(n)). 

//-------Code---------
#include <iostream>
using namespace std;

int find_med_2_sor_arr(int*, int*, int);

int main() {
	int a[] = { 1, 12, 15, 26, 38 };
	int b[] = { 2, 13, 17, 30, 45 };
	int n = sizeof(a) / sizeof(a[0]);
	cout << find_med_2_sor_arr(a, b, n);
	return 0;
}

int find_med_2_sor_arr(int* a, int* b, int n) {
	int start = 0, end = n - 1, idx_a, idx_b;
	while (true) {
		idx_a = (start + end) / 2;
		idx_b = n - idx_a - 1;
		if (a[idx_a] < b[idx_b]) {
			if ((idx_a == n - 1 || a[idx_a + 1] >= b[idx_b]) && (idx_b == 0 || b[idx_b - 1] <= a[idx_a])) {
				return (a[idx_a] + b[idx_b]) / 2;
			}
			else {
				start = idx_a + 1;
			}
			if (a[idx_a + 1] < b[idx_b] && b[idx_b - 1] < a[idx_a]) {
				return (a[idx_a] + a[idx_a + 1]) / 2;
			}
			else if (a[idx_a + 1] > b[idx_b] && b[idx_b - 1] > a[idx_a]) {
				return (b[idx_b] + b[idx_b - 1]) / 2;
			}
		}
		else if (a[idx_a] > b[idx_b]) {
			if ((idx_a == 0 || a[idx_a - 1] <= b[idx_b]) && (idx_b == n - 1 || b[idx_b + 1] >= a[idx_a])) {
				return (a[idx_a] + b[idx_b]) / 2;
			}
			else {
				end = idx_a - 1;
			}
		}
		else {
			return a[idx_a];
		}
	}
}
