#include<bits/stdc++.h>
using namespace std;

int main()
{
    int firstWordCheck[27] = {0};
    int secondWordCheck[27] = {0};

    string firstWord, secondWord;

    cin >> firstWord >> secondWord;

    // 빈도수 저장
    for(int i = 0; i < firstWord.length(); i++) firstWordCheck[firstWord.at(i) - 'a']++;
    for(int i = 0; i < secondWord.length(); i++) secondWordCheck[secondWord.at(i) - 'a']++;

    // 검사
    int answer = 0;
    for(int i = 0; i < 27; i++) if(firstWordCheck[i]!=secondWordCheck[i]) answer += abs(firstWordCheck[i] - secondWordCheck[i]) ;
    cout << answer << "\n";

    return 0;
}
