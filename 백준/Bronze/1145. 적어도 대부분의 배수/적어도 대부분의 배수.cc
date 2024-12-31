#include <iostream>
#include <vector>
#include <cmath>
#define MAX 987654321
using namespace std;

vector<int> v;
bool visited[5] = { false, };
int arr[5];
int result = MAX;

void makeCombination(int n);
int findMajorityMultiples(int num1, int num2, int num3);
int euclideanAlgorithm(int num1, int num2);
int gcd(int num1, int num2);

int main() {

	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}

	makeCombination(0);
	cout << result;
}

void makeCombination(int n) {
	if (n == 3) {
		int majorityMultiples = findMajorityMultiples(v[0], v[1], v[2]);
		result = min(result, majorityMultiples);
	}
	for (int i = 0; i < 5; i++) {
		if (visited[i] == true) continue;

		visited[i] = true;
		v.push_back(arr[i]);
		makeCombination(n + 1);
		visited[i] = false;
		v.pop_back();
	}
}

int findMajorityMultiples(int num1, int num2, int num3) {
	int a = euclideanAlgorithm(num1, num2);
	int b = euclideanAlgorithm(num1, num3);
	int c = euclideanAlgorithm(num2, num3);
	if (a == b && b == c) {
		return a;
	}
	else {
		return findMajorityMultiples(a, b, c);
	}
}

int euclideanAlgorithm(int num1, int num2) {
	return (num1 * num2) / gcd(num1, num2);
}

int gcd(int num1, int num2) {
	if (num1 < num2) {
		return gcd(num2, num1);
	}
	if (num2 == 0) {
		return num1;
	}

	int r = num1 % num2;
	return gcd(num2, r);
}

