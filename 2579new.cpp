#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    int arr[1000] = {0};
    for(int i=1;i<=n;i++) cin >> arr[n-i];
    int answer = arr[0];
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int index = q.front(); q.pop();
        cout << "선택된 계단 : " << arr[index] << endl;
        if(arr[index+2] > arr[index+3]) {
            answer += arr[index+2];
            q.push(index+2);
            continue;
        }
        else if(arr[index+2] < arr[index+3]) {
            answer += arr[index+3] + arr[index+1];
            q.push(index+3);
            continue;
        }
        if(index+1 == n-1) answer+=arr[index+1];
    }
    cout << answer;
    return 0;
}