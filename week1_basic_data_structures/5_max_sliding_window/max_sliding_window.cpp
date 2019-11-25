#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <deque>

using namespace std;

void max_sliding_window_naive(vector<int> const& A, int m) {
	deque<int> Q;
	int i;
	for (i = 0; i < m; i++) {
		while ((!Q.empty()) && A[i] > Q.back()) {
			Q.pop_back();
		}
		Q.push_back(A[i]);
	}
	for ( ; i < A.size(); i++) {
		cout << Q.front() << " ";
		while ((!Q.empty()) && A[i] > Q.back()) {
			Q.pop_back();
		}
		if ((!Q.empty()) && A[i - m] == Q.front()) {
			Q.pop_front();
		}
		Q.push_back(A[i]);
	}
	cout << Q.front() << endl;
	return;
}


int main() {
	int n = 0;
	cin >> n;

	vector<int> A(n);
	for (size_t i = 0; i < n; ++i)
		cin >> A.at(i);

	int m = 0;
	cin >> m;

	max_sliding_window_naive(A, m);

	return 0;
}
