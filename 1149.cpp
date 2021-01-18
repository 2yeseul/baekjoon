#include <bits/stdc++.h>
using namespace std;

int dp[1002] = {0};
int arr[1002][4] = {0};

int notContinuos(int i) {
    int tempDp;
    if(dp[i-1] == arr[i-1][1]) tempDp = min(arr[i][2], arr[i][3]);
    else if(dp[i-1] == arr[i-1][2]) tempDp = min(arr[i][1], arr[i][3]);
    else if(dp[i-1] == arr[i-1][3]) tempDp = min(arr[i][1], arr[i][2]);
    return tempDp;
}
int getDP(int i) {
    int tempDp; 
    if(dp[i-2] == arr[i-2][1]) tempDp = min(arr[i][2], arr[i][3]);
    else if(dp[i-2] == arr[i-2][2]) tempDp = min(arr[i][1], arr[i][3]);
    else if(dp[i-2] == arr[i-2][3]) tempDp = min(arr[i][1], arr[i][2]);
    return tempDp;
}
int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=3;j++) 
            cin >> arr[i][j];
    }
    dp[1] = min({arr[1][1], arr[1][2], arr[1][3]});
    dp[2] = notContinuos(2);
    if(n == 3) dp[3] = notContinuos(3);
    if(n > 3) {
        for(int i=3;i<n;i++) dp[i] = getDP(i);
        dp[n] = notContinuos(n);
    }
    int m = 0;
    for(int i=1;i<=n;i++) {
        m += dp[i];
    }

    cout << m;
    return 0;
}
