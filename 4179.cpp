#include<bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[1002][1002];
int dist[1002][1002];

int main()
{
    int n, m;
    cin >> n >> m;
    queue<pair<int, int>> q;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            char c;
            cin >> c;
            if(c == '#' || c == 'F') board[i][j] == 0;
            else if(c == '.') board[i][j] == 1;
            else if(c == 'J') {
                board[i][j] == 1;
                q.push({i, j});
            }
        }
    }
    
}