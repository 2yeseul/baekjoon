#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int arr[100005] = {0};
    for(int i=1;i<=n;i++) cin >> arr[i];
    int dp[100005] = {0};
    int m = 0;
    dp[1] = arr[1];
    m = dp[1];
    for(int i=2;i<=n;i++) {
        dp[i] = max(0, dp[i-1]) + arr[i];
        m = max(m, dp[i]);
    }
    cout << m;
    return 0;
}