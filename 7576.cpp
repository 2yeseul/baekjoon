#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int box[1000][1000];
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    int dist[1000][1000];
    queue<pair<int, int>> q;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> box[i][j];
            if(box[i][j] == 1) q.push({i, j});
            if(box[i][j] == 0) dist[i][j] = -1;
        }
    }
    

    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >=m) continue;
            if(dist[nx][ny] >= 0) continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }
    int answer = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(dist[i][j] == -1) {
                cout<<-1;
                return 0;
            }
            answer = (answer, dist[i][j]);
        }
    }
    cout << answer;
}