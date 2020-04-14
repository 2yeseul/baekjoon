#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void findGroup(vector<int>space[]) {
    int now = 0;
    int numGroup = 0;
    int flag = 0;
    queue<int> q;

    for(int i=0;i<space[now].size();i++) {
        if(space[now][i] == 1) {
            int countHouse = 1;
            if(space[now][i+1] == 1 || space[now+1][i] == 1) {
                flag = 1;
                countHouse ++;
                now+=1;
            }
            else {
                flag = 0;
                numGroup ++;
            }
        }
    }
}

int main() 
{
    int N;
    cin>>N;
    vector<int>space[N];
    for(int i=0;i<N;i++) {
        for(int j=0;i<N;j++) {
            int house;
            cin>>house;
            space[i].push_back(house);
        }
    }
}
