#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int answer[N];
    stack<pair<int, int>> s;
    // 입력된 height가 스택 top보다 크면, stack이 empty가 될 때 까지 pop
    vector<int> height;


    for(int i=0;i<N;i++) {
        int n;
        cin >> n;
        height.push_back(n);
    }

    for(int i=0;i<N;i++) {
        if(s.empty()) answer[i] = 0; 
        // 1) 입력받은 수신탑의 크기가 기존 스택의 top 보다 클 때
        else if(height[i] > s.top().second && !s.empty()) {
            while(!s.empty()) { 
                if(s.top().second > height[i]) break;
                s.pop();
                }
            if(s.empty()) answer[i] = 0;
            else answer[i] = s.top().first;
        } 
        // 2) 입력받은 수신탑의 크기가 기존 스택의 top 보다 작을  때
        else if(height[i] < s.top().second && !s.empty()) {
            answer[i] = s.top().first;
        }
        s.push({i+1, height[i]});
    }

    for(int i=0;i<N;i++) cout << answer[i] <<" ";
}
