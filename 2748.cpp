#include <iostream>
using namespace std;

long long arr[1000] = {0,};

long long fin(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 1;
    if(arr[n]!=0) return arr[n];

    return arr[n] = fin(n - 1)+fin(n - 2);
}

int main() 
{
    int n;
    cin>>n;
    cout<<fin(n)<<"\n";
    return 0;
}
