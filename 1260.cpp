#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stdio.h>

#define MAX_SIZE 1001

using namespace std;

int num; // 원소의 개수

vector<int> adj[10001];
int checked[1001];


void dfs(int now, int *checked) {
    if(checked[now]) return;
    checked[now] = true;
    cout << now << " ";
    for(int i=0;i<adj[now].size();i++) {
        int adjNode = adj[now][i];
        dfs(adjNode, checked);
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start); // 시작노드 삽입
    checked[start] = true; // 방문처리
    while(!q.empty()) {
        // 1) 큐에서 노드 꺼냄
        int now = q.front();
        q.pop();
        cout<< now << " ";

        // 2) 현재 노드에서 인접한 모든 노드들 중
        for(int i=0;i<adj[now].size();i++) {
            int adjNode = adj[now][i];
            // 아직 방문하지 않은 노드 (adjNode) queue에 push
            if(checked[adjNode] == 0) {
                q.push(adjNode);
                checked[adjNode] = 1;
            }
        }
    }
}


int main() 
{
    int N, M, V;
    cin >> N >> M >> V;
    for(int i=0;i<M;i++) {
        int first, second;
        cin >> first >> second;
        adj[first].push_back(second);
        adj[second].push_back(first);
    }

    for(int i=1; i<=N; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    
    int visited[1001] = {0,};
    dfs(V, visited);
    cout<<endl;
    bfs(V);

    return 0;
}
