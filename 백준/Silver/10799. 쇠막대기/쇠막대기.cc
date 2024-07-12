#include <iostream>
#include <string>
using namespace std;

int main() {

	string s;
	int count = 0;
	int ans = 0;
	cin >> s;

	
	for (int i = 0; i < s.size(); i++) {

		if (s[i] == '(') {
			count++;
		}
		else {
			count--;
			if(s[i-1] == '(')
			{
				ans += count;
			}
			else {
				ans++;
			}
		}
	}

	cout << ans;

	return 0;
}