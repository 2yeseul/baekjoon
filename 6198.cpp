#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int N;
    stack<int> s;
    cin >> N;
    int building[N];
    for(int i=0;i<N;i++) cin >> building[i];

    long long answer = 0;
    for(int i=0;i<N;i++) {
       while(!s.empty() && building[i] >= s.top()) s.pop();
        s.push(building[i]);
        answer += s.size() - 1;
    }

    cout << answer;
    
    return 0;
}