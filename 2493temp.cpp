#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> tower;
    int N;
    cin >> N;

    for(int i=0;i<N;i++) {
        int height;
        cin >> height;
        tower.push(height);
        
    }

    stack<int> sendLaser;
    stack<int> answer;
    sendLaser = tower;

    while(tower.empty() == false) {
        if(sendLaser.empty() == true) {
            answer.push(0);
            tower.pop();
        }
        //  신호를 받는 타워의 높이가 적을 때
        else if(tower.top()>=sendLaser.top() && sendLaser.empty() == false)  {  
            sendLaser.pop();
        }
        else if(tower.top()<sendLaser.top() && sendLaser.empty() == false) {
            tower.pop();
            answer.push(sendLaser.size());
            sendLaser = tower;
        }
    }


    for(int i=0;i<N;i++) {
        cout <<answer.top() << " ";
        answer.pop();
    }

    return 0;

}