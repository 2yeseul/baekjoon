#include <iostream>
using namespace std;

int arr[1000001];

int getResult(int N) {
    arr[0] = 1;
    arr[1] = 2;
    if(arr[N]!=0) return arr[N];
    else {
        return arr[N] = ( getResult(N-1) + getResult(N-2) ) % 15746;
    }
}

int main()
{
    int n;
    cin>>n;
    getResult(n-1);
    int num =  arr[n-1];
    cout<<num<<endl;

    return 0;
}
