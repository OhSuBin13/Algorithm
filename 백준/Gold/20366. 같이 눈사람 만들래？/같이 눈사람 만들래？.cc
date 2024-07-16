#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

#define endl "\n"

using namespace std;

int N;
int arr[606];

void Solve() {
    cin>>N;
    int left, right, sumA, sumB, result, answer = INT_MAX;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }

    sort(arr, arr+N);

    for(int i=0; i<N-2; i++){
        for(int j= i+3; j<N; j++){
            
            left = i+1; right = j-1;
            sumA = arr[i] + arr[j];
            while(left<right){
                sumB = arr[left]+arr[right];
                result = abs(sumA-sumB);
                answer = min(answer, result);
                
                if(answer == 0) {cout<<answer; return;}
                
                if(sumA>sumB) left++;
                else right--;
            }
        }
    }

    cout<<answer;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}