#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[1005];
    for(int i=0;i<n;i++) cin >> arr[i];
    int length[1005];
    int m = 1;
    for(int i=0;i<n;i++) {
        length[i] = 1;
        for(int j=0;j<i;j++) {
            if(arr[j] < arr[i]) length[i] = max(length[j]+1, length[i]);
        }
        m = max(m, length[i]);
    }
    cout <<m;
    return 0;
}