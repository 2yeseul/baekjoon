#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    while(true) {
        getline(cin, str);
        if(str == ".") break;
        stack<char> s;
        bool isValid = true;
        for(auto c : str) {
            if(c == '(' || c == '[') s.push(c);
            else if(c == ')') {
                if(s.empty() || s.top() != '(') {
                    isValid = false;
                    break;
                }
                s.pop();
            }
            else if(c == ']') {
                if(s.empty() || s.top() != '[') {
                    isValid = false;
                    break;
                }
                s.pop();
            }
       }
       if(!s.empty()) isValid = false;
       if(isValid) cout <<"yes\n";
       else cout <<"no\n";

    }
}