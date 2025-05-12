#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
	int n; cin >> n;
	vector<int> arr(n);
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ans = 0;
	stack<int> st;
	for (auto u : arr) {
		while (!st.empty() && st.top() < u) {
			st.pop();
			ans++;
		}
		if (!st.empty()) ans++;
		st.push(u);
	}
	cout << ans;
	return 0;
}