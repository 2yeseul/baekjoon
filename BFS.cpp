#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}};
 bool visit[502][502];
 int n = 7, m = 10; //  n = 헹의 수, m = 열의 수
 // 상하좌우
 int dx[4] = {1, 0, -1, 0};
 int dy[4] = {0, 1, 0, -1};
 int main()
 {
    queue<pair<int, int>> q;
    visit[0][0] = 1;
    q.push({0, 0});
    while(!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        cout << "(" << current.X <<", " << current.Y <<") ->";
        for(int dir = 0; dir < 4; dir++) {
            int nearX = current.X + dx[dir];
            int nearY = current.Y + dy[dir];
            // 범위 밖일 경우 넘어감
            if(nearX < 0 || nearX >= n || nearY <0 || nearY >= m) continue;
            // 이미 방문한 칸이거나 파란 칸이 아닐 경우 
            if(visit[nearX][nearY] || board[nearX][nearY] !=1) continue;
            visit[nearX][nearY] = 1;
            q.push({nearX, nearY});
        }
    }
    return 0;
 }