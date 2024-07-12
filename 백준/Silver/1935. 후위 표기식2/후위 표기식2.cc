#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main() {

	int N;
	string s;
	stack<double> cal;
	vector<int> v;

	cin >> N;
	cin >> s;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		v.push_back(num);
	}

	for (int i = 0; i < s.size(); i++) {

		int pos = (int)s[i] - 65;

		if(pos >= 0)
		{
			cal.push(v[pos]);
		}
		else {
			double b = cal.top();
			cal.pop();
			double a = cal.top();
			cal.pop();

			if (s[i] == '+') {
				cal.push(a + b);
			}
			else if (s[i] == '-') {
				cal.push(a - b);
			}
			else if (s[i] == '*') {
				cal.push(a * b);
			}
			else if (s[i] == '/') {
				cal.push(a / b);
			}
		}
	}
	
	cout << fixed;
	cout.precision(2);

	cout << cal.top();

	return 0;
}