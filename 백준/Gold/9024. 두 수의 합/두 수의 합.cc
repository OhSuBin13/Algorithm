#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

#define MAX 200000000 // 2억

int t, n, K;
int x;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--)
	{
		cin >> n >> K;

		for (int i = 0; i < n; i++)
		{
			cin >> x;
			v.push_back(x);
		}

		sort(v.begin(), v.end()); // 배열 정렬

		int left, right, mid, sum, mini, cnt;
		cnt = 0;
		mini = MAX;

		for (int i = 0; i <= v.size() - 2; i++)
		{

			left = i + 1;
			right = v.size() - 1;

			while (left <= right)
			{
				mid = (left + right) / 2;
				sum = v[i] + v[mid];

				if (sum > K)
				{
					right = mid - 1;
				}
				else if (sum <= K)
				{
					left = mid + 1;
				}
					
				if (abs(K - (sum)) < mini)
				{
					cnt = 1;
					mini = abs(K - (sum));
				}
				else if (abs(K - (sum)) == mini)
				{
					cnt++;
				}

			}
		}

		cout << cnt << '\n';
		v.clear(); // 배열 비우기
	}

	
}