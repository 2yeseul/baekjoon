#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

// board : 격자 상태 2차원배열
// moves : 인형을 집기 위해 크레인을 작동시킨 위치가 담긴 배열
// return : 크레인을 모두 작동시킨 후 사라진 인형의 개수

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> bagooni;
    for(int i=0;i<moves.size();i++) {
         for(int j=0;j<board.size();j++) {
            int doll = board[j][moves[i]-1];
            if(doll!=0) {
                if(!bagooni.empty() && bagooni.top() == doll) {
                    bagooni.pop();
                    answer+=2;
                }
                else bagooni.push(doll);
                board[j][moves[i]-1] = 0;
                break;
            }
        } 
    }
    return answer;
}
