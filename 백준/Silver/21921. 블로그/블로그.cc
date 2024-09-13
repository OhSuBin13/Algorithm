#include <iostream>
#include <vector>

using namespace std;

int N, X; 
vector<int> blog;
int maxVisitor = 0;

void Input() {
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;

		blog.push_back(a);
	}
}

void TwoPointer() {
	int start = 0;
	int end = X - 1;
	int sum = 0;

	for (int i = start; i <= end; i++) {
		sum += blog[i];
	}

	maxVisitor = (maxVisitor < sum) ? sum : maxVisitor;

	while (end != blog.size()-1) {
		sum -= blog[start];
		start++;
		end++;
		sum += blog[end];

		maxVisitor = (maxVisitor < sum) ? sum : maxVisitor;
	}

	if (maxVisitor == 0) cout << "SAD";
	else {
		cout << maxVisitor << "\n";

		int cnt = 0;

		start = 0;
		end = X - 1;
		sum = 0;

		for (int i = start; i <= end; i++) {
			sum += blog[i];
		}
		
		if (sum == maxVisitor) cnt++;
		while (end != blog.size() - 1) {
			sum -= blog[start];
			start++;
			end++;
			sum += blog[end];

			if (sum == maxVisitor) cnt++;
		}

		cout << cnt;
	}

}

void Solve() {
	TwoPointer();
}

void Solution() {
	Input();
	Solve();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Solution();

	return 0;
}