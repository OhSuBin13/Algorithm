#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {

	string s;
	stack<char> cal;
	int cnt = 1;
	int ans = 0;
	bool open = false;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			cnt *= 2;
			cal.push(s[i]);
			open = true;
		}
		else if (s[i] == '[') {
			cnt *= 3;
			cal.push(s[i]);
			open = true;
		}
		else if (s[i] == ')') {
			if (cal.empty() || cal.top() != '(') {
				ans = 0;
				break;
			}
			if (open == true) {
				ans += cnt;
				open = false;
			}
			cnt /= 2;
			cal.pop();
		}
		else if (s[i] == ']') {
			if (cal.empty() || cal.top() != '[') {
				ans = 0;
				break;
			}
			if (open == true) {
				ans += cnt;
				open = false;
			}
			cnt /= 3;

			cal.pop();
		}
	}

	if (!cal.empty()) cout << 0;
	else {
		cout << ans;
	}

	return 0;
}