#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int arr[1005] = {0};
    int dp[10005] = {0};

    for(int i=0;i<n;i++) cin >> arr[i];
    dp[0] = 1;

    for(int i=0;i<n;i++) {
        for(int j=arr[i];j<=k;j++) {
            if(j-arr[i]>=0) dp[j] += dp[j-arr[i]];
        }
    }

    cout << dp[k];
    return 0;
}