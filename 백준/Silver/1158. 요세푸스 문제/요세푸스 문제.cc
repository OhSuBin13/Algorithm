#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N, K; cin >> N >> K;
	queue<int> q;

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	cout << "<";

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K - 1; j++) {
			int tmp = q.front();
			q.pop();
			q.push(tmp);
		}
		cout << q.front();
		q.pop();
		if (i != N - 1) cout << ", ";
		else cout << ">";
	}


	return 0;
}