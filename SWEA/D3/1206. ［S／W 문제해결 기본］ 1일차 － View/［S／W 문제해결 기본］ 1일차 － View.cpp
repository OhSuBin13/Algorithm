#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//cin>>T;

	for(test_case = 1; test_case <= 10; ++test_case)
	{
		int N;
        cin >> N;
        int arr[1001];
        int res = 0;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        for (int i = 2; i < N - 2; i++) {
            int num1 = (arr[i - 1] > arr[i - 2]) ? arr[i - 1] : arr[i - 2];
            int num2 = (arr[i + 1] > arr[i + 2]) ? arr[i + 1] : arr[i + 2];
            int left = arr[i] - num1;
            int right = arr[i] - num2;
            int output = (left > right) ? right : left;
            if (output > 0) res += output;
        }
        cout << '#' << test_case << ' ' << res << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}