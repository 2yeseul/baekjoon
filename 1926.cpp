#include<bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[502][502];
bool isVisit[502][502];
int n, m;
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> board[i][j];
        }
    }
    int picNum = 0; // 그림의 수
    int maxPic = 0; // 그림 최댓값
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            // 그림이 아니거나 방문한 적 있는 경우
            if(board[i][j] == 0 || isVisit[i][j]) continue;
            picNum++;
            queue<pair<int, int>> q;
            isVisit[i][j] = 1;
            q.push({i, j});
            int area = 0; // 그림의 넓이
            // 인접 칸을 다 돌 때 까지
            while(!q.empty()) {
                area++;
                pair<int, int> current = q.front();
                q.pop();
                for(int dir=0;dir<4;dir++) {
                    int nearX = current.first + dx[dir];
                    int nearY = current.second + dy[dir];
                    if(nearX < 0 || nearX >=n || nearY <0 || nearY >=m) continue;
                    if(isVisit[nearX][nearY] || board[nearX][nearY]!=1) continue;
                    isVisit[nearX][nearY] = 1;
                    q.push({nearX, nearY});
                }
            }
            // (i, j) 를 시작점으로 하는 BFS 종료
            maxPic = max(maxPic, area);
        }
    }
    cout << picNum << "\n" << maxPic;
    return 0;
}
