#include <iostream>
#include <vector>

#define MAX 1000001
using namespace std;

int N, M;
int A[MAX];
int B[MAX];
vector<int> AB;

void Input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	
	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}
}

void TwoPointer() {
	int aPoint = 0;
	int bPoint = 0;

	while (aPoint != N && bPoint != M) {
		if (A[aPoint] > B[bPoint]) {
			AB.push_back(B[bPoint]);
			bPoint++;
		}
		else {
			AB.push_back(A[aPoint]);
			aPoint++;
		}
	}

	if (aPoint == N) {
		while (bPoint != M) {
			AB.push_back(B[bPoint]);
			bPoint++;
		}
	}
	else if (bPoint == M) {
		while (aPoint != N) {
			AB.push_back(A[aPoint]);
			aPoint++;
		}
	}
}

void Solve() {
	TwoPointer();
	for (int i = 0; i < AB.size(); i++) {
		cout << AB[i] << " ";
	}
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