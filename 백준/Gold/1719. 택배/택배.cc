#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1e9
#define MAX 201
using namespace std;

struct factory {
	int distance;
	vector<int> navigation;
};

factory arr[MAX][MAX];
int n, m;

void Input() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j].distance = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a][b].distance = c;
		arr[a][b].navigation.push_back(b);
		
		arr[b][a].distance = c;
		arr[b][a].navigation.push_back(a);
	}

}

void Floyd_Warshall() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][k].distance != INF && arr[k][j].distance != INF && i != j) {
					vector<int> tmp1 = arr[i][k].navigation;
					vector<int> tmp2 = arr[k][j].navigation;

					vector<int> tmp3 = arr[i][k].navigation;
					vector<int> tmp4 = arr[k][j].navigation;

					tmp3.pop_back();
					tmp4.pop_back();
					reverse(tmp3.begin(), tmp3.end());
					tmp3.push_back(i);
					reverse(tmp4.begin(), tmp4.end());
					tmp4.push_back(k);

					if (arr[i][j].distance > arr[i][k].distance + arr[k][j].distance) {
						arr[i][j].distance = arr[i][k].distance + arr[k][j].distance;
						arr[j][i].distance = arr[i][k].distance + arr[k][j].distance;

						tmp1.insert(tmp1.end(), tmp2.begin(), tmp2.end());
						arr[i][j].navigation = tmp1;

						tmp4.insert(tmp4.end(), tmp3.begin(), tmp3.end());
						arr[j][i].navigation = tmp4;
					}
				}
			}
		}
	}
}

void Solve() {
	Floyd_Warshall();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j].navigation.empty()) {
				cout << '-' << " ";
			}
			else {
				cout << arr[i][j].navigation[0] << " ";
			}
		}
		cout << "\n";
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