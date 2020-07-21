#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    string result;
    string first, second;
   
    for(int i=0;i<N;i++) {
        result = "Possible";
        int countFirst[26] = {0,};
        int countSecond[26] = {0,};
        cin >> first >> second;
        if(first.length()!=second.length()) {
            result = "Impossible";
        }
        else {
            for(int j=0; j<first.length();j++) {
                countFirst[first[j] - 'a']++;
                countSecond[second[j] - 'a']++;
            }
            for(int j=0; j<26;j++) {
                if(countFirst[j]!=countSecond[j]) {
                    result = "Impossible";
                    break;
            }
        }
      }
        cout << result << "\n";
    }
    return 0;
}
