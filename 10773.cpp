#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> s;
    int k;
    cin >> k;
    int item;
    for(int i = 0; i < k ; i++) {
        cin >> item;
        if(item == 0) {
            s.pop();
        }
        else s.push(item);
    }

    int answer = 0;

    int sizeOfStack = s.size();

    for(int i = 0; i < sizeOfStack; i++) {
        answer += s.top();
        s.pop();
    }

    cout << answer << "\n";

    return 0;
}
