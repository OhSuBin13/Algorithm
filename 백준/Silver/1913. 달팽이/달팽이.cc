#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>

#define MAX 1000
using namespace std;

int arr[MAX][MAX];
int N;
int searchNum;

int mX[4] = {0,1,0,-1};
int mY[4] = {-1,0,1,0};

void Input() {
	cin >> N;
	cin >> searchNum;
}

void Solve() {
	int y = (N + 1) / 2;
	int x = (N + 1) / 2;
	arr[y][x] = 1;
	int priorYX = arr[y][x];

	int tmp = 1;

	while (tmp < N) {
		y = y + mY[0];
		x = x + mX[0];
		
		arr[y][x] = priorYX + 1;
		priorYX = arr[y][x];

		for (int i = 1; i <= tmp; i++) {
			x = x + 1;
			
			arr[y][x] = priorYX + 1;
			priorYX = arr[y][x];
		}
		
		for (int i = 1; i <= tmp + 1; i++) {
			y = y + 1;
			
			arr[y][x] = priorYX + 1;
			priorYX = arr[y][x];
		}
		
		for (int i = 1; i <= tmp + 1; i++) {
			x = x - 1;
			
			arr[y][x] = priorYX + 1;
			priorYX = arr[y][x];
		}
		
		for (int i = 1; i <= tmp + 1; i++) {
			y = y - 1;
			
			arr[y][x] = priorYX + 1;
			priorYX = arr[y][x];
		}

		tmp += 2;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] == searchNum) cout << i << " " << j;
		}
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