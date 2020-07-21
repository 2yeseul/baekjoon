#include <bits/stdc++.h>
using namespace std;

int main() {
    int count[10] = {};
    int a, b, c;
    cin >> a >> b >> c;
    int num = a * b * c;
    string s = to_string(num);
    for(int i = 0 ; i<s.size();i++) {
        count[s[i] - '0']++;
    }
   for(int i = 0 ; i<10 ; i++) cout << count[i] << "\n";
}
