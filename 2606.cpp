#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visited[101];
vector<int>networks[101];

void findRoute(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int i=0;i<networks[now].size();i++) {
            int nextCom = networks[now][i];
            if(visited[nextCom] == false) {
                q.push(nextCom);
                visited[nextCom] = true;
            }
        }
    }
}

int main() 
{
    int n, m;
    cin>> n >> m;
    for(int i=0;i<m;i++) {
        int first, second;
        cin >> first >> second;
        networks[first].push_back(second);
        networks[second].push_back(first);
    }
    findRoute(1);
    int count = 0;

    for(int i=2;i<=n;i++) {
        if(visited[i] == true) {
            count++;
        }

    }
    cout << count;
    return 0;
}
