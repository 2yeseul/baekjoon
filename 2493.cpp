#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> tower;
    stack<int> answer;
    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        tower.push(temp);
    }
    
    
    int index = 0;
    while(tower.empty()==false) {
        int count = 0;

        stack<int> tempTower = tower;
        while(tower.top() >= tempTower.top()) {
            //cout << "while 문 :  tower.top() : " << tower.top() << ", tempTower.top() : " << tempTower.top() << endl;
            tempTower.pop();
            count++;
        }
        index = (tower.size() - count) ;
        if(tower.top() < tempTower.top()) {
            //cout << "index push" << endl;
            answer.push(index);
            //cout << "answer.top() : " << answer.top() << endl;
            //continue;
        }
        else if(tempTower.empty()) answer.push(0);

        //cout << "index : " << index << ", tower.top() : " << tower.top() << ", tempTower.top() : " << tempTower.top() << endl;
        tower.pop();
    }
    
    //if(answer.empty() == false) cout << "EMPTY" << endl;
     
     for(int i=0;i<answer.size();i++) {
         cout << answer.top()<<"/n";
         answer.pop();
     }

    return 0;
}