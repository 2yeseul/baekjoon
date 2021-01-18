#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[1002][4];
    int dp[1002][4];
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=3;j++)
            cin >> arr[i][j];
    }
    dp[1][1] = arr[1][1];
    dp[1][2] = arr[1][2];
    dp[1][3] = arr[1][3];
    for(int i=2;i<=n;i++) {
        dp[i][1] = min(dp[i-1][2], dp[i-1][3]) + arr[i][1];
        dp[i][2] = min(dp[i-1][1], dp[i-1][3]) + arr[i][2];
        dp[i][3] = min(dp[i-1][1], dp[i-1][2]) + arr[i][3];
    }
    cout << min({dp[n][1], dp[n][2], dp[n][3]});
    return 0;
}