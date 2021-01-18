#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, M;
    string board[102];
    cin >> N >> M;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
        cin >>board[i][j];
    }
    int dist[102][102];
    for(int i=0;i<N;i++) fill(dist[i], dist[i]+M, -1);
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 0;
    while(!q.empty()) {
        // 1) 새로운 pair를 만들어 가장 위에 있는 값을 대입한다
        pair<int, int> current = q.front();
        // 2) 방문을 확인한 좌표는 삭제한다.
        q.pop();
        for(int i=0;i<4;i++) {
            // 상하좌우 좌표
            int moveX = current.first + dx[i];
            int moveY = current.second + dy[i];
            // 3) 상하좌우로 움직인 좌표가 0보다 작거나, 가로 세로 최대 길이를 넘어서면 continue
            if(moveX < 0 || moveX >=N || moveY <0 || moveY >=M) continue;
            // 4) 움직인 좌표에서 0,0 부터의 거리가 -1이 아니거나(방문한 적 있음), board가 1이 아니면 continue
            if(dist[moveX][moveY] >= 0 || board[moveX][moveY]!='1') continue;
            // 인접한 행렬이므로 1만 더해줌
            dist[moveX][moveY] = dist[current.first][current.second] + 1;
            q.push({moveX, moveY});
        }

    }
    return 0;
}