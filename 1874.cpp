#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> s;
    vector<int> v;
    vector<char> answer;
    int isNo = 0;
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    for(int i=0;i<n;i++) {
        int lastPush;
        
        if(s.empty()) {
            for(int j = i; j < v.at(i); j++) {
                s.push(j+1);
                answer.push_back('+');
                lastPush = j+1;
            }
            if(s.top() == v.at(i)) { 
                answer.push_back('-');
                s.pop();
            }
        }

        else if(lastPush > v.at(i) && s.top() < v.at(i)) {
            isNo = 1;
            break;
        }

        else if(s.top() < v.at(i) && i > 0) {
            for(int j = lastPush; j < v.at(i); j++) {
                s.push(j+1);
                answer.push_back('+');
                lastPush = j+1;
            }
            if(s.top() == v.at(i)) { 
                answer.push_back('-');
                s.pop();
            }
        }

        else if (s.top() == v.at(i)) {
            answer.push_back('-');
            s.pop();
        }

        else if(s.top() > v.at(i)) {
            while(s.top()!=v.at(i)) {
                answer.push_back('-');
                s.pop();
            }
        }
    }

    if(isNo == 1) cout << "NO\n";
    else 
        for(int i = 0; i<answer.size(); i++) cout <<answer.at(i) << endl;
   
    return 0;
}
