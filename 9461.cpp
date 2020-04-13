#include <iostream>
using namespace std;

long long p[101];

int main()
{
    p[1] = 1; p[2] = 1; p[3] = 1; p[4] = 2; p[5] = 2;
    int T,n;
    cin>>T;
   
    for(int i=6; i<=100; i++) {
        p[i] = p[i-1] + p[i-5]; 
    }
    for(int i=0;i<T;i++) {
        cin>>n;
        cout << p[n] << "\n";
    }
    return 0;
}
