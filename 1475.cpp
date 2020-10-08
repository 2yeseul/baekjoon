#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int checked[10] = {0};
    int N;
    cin >> N;
    int numberOfSets = 1;

    while (N > 0) {
        int parsedNumber = 0;
        parsedNumber = N % 10;
        N = N / 10;
        checked[parsedNumber]++;
    }
    int numberOfSix = 0;
    // 검사
    for(int i = 0; i < 10; i++) {
        if(i == 6 || i == 9) continue;
        if(numberOfSets < checked[i]) numberOfSets = checked[i];
    }

    if((checked[6] + checked[9]) % 2 == 0) numberOfSix = (checked[6] + checked[9]) / 2;
        else numberOfSix = ((checked[6] + checked[9]) / 2) + 1;
    
    if(numberOfSets < numberOfSix) numberOfSets = numberOfSix;

    cout << numberOfSets << "\n";

    return 0;
}
