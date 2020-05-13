#include <iostream>
using namespace std;

int main() 
{
    string s;
    cin >> s;
    int num[26] = {};
    for(int i=0;i<s.size();i++) {
        num[s[i]-'a']++;
    }

    for(int i=0;i<26;i++) cout<< num[i] <<" ";
    return 0;
}
