#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int num; // 사람의 수
    cin >> num;
    vector<int> time;
    for(int i=0;i<num;i++) {
        int t;
        cin >> t;
        time.push_back(t);
    }
    sort(time.begin(), time.end());
    
    int answer[num] = {0,};
    answer[0] = time[0];
    int total = answer[0];
    for(int i=1;i<num;i++) {
        int value = 0;
        value = answer[i-1] + time[i];
        answer[i] = value;
        total += answer[i];
    }

    cout<<total<<"\n";
}
