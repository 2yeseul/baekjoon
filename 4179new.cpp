#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;
    string str[1002];
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    queue<pair<int, int>> exodus;
    queue<pair<int, int>> fire;
    int fDist[1002][1002];
    int jDist[1002][1002];
    for(int i=0;i<r;i++) {
        fill(fDist[i], fDist[i]+c, -1);
        fill(jDist[i], jDist[i]+c, -1);
    }
    for(int i=0;i<r;i++) cin >> str[i];

    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++){
            if(str[i][j] == 'J') {
                exodus.push({i, j});
                jDist[i][j] = 0;
            }
            if(str[i][j] == 'F') { 
                fire.push({i, j});
                fDist[i][j] = 0;
            }
        }
    }


    while(!fire.empty()) {
        pair<int, int> curF = fire.front();
        fire.pop();
        for(int i=0;i<4;i++) {
            int fx = curF.first + dx[i];
            int fy = curF.second + dy[i];
            // 불 움직이기
            // 1) 불이 가지 못하는 곳
            if(fx < 0 || fx >= r || fy < 0 || fy >=c) continue;
            // 벽이거나 이미 갔던 곳
            if(str[fx][fy] == '#' || fDist[fx][fy] >=0) continue;
            fDist[fx][fy] = fDist[curF.first][curF.second] + 1;
            fire.push({fx, fy});
        }
    }
    while(!exodus.empty()) {
        pair<int, int> curJ = exodus.front();
        exodus.pop(); 
        for(int i=0;i<4;i++) {
            int jx = curJ.first + dx[i];
            int jy = curJ.second + dy[i];
            if(jx < 0 || jx >= r || jy < 0 || jy >=c) {
                cout << jDist[curJ.first][curJ.second] + 1;
                return 0;
            }
            // 지훈이 움직이기
            // 1) 지훈이가 가지 못하는 곳
            if(str[jx][jy] == '#' || jDist[jx][jy] >= 0) continue;
            // 이미 fire가 다녀간 곳이거나, 도착한 시점에 불이 동시에 도착하거나, 혹은 자신보다 불이 더 빨리 도착하는 자리에 갈 수 없음.
            if(fDist[jx][jy]!=-1 && fDist[jx][jy] <= jDist[curJ.first][curJ.second]+1) continue;
            jDist[jx][jy] = jDist[curJ.first][curJ.second] + 1;
            exodus.push({jx, jy});
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}