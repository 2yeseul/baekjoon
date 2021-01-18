#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int dist[100002];
    fill(dist, dist+100001, -1);
    dist[n] = 0;
    queue<int> q;
    q.push(n);
    while(dist[k] == -1) {
        int cur = q.front();
        q.pop();
        for(int next : {cur-1, cur+1, cur*2}) {
            if(next < 0 || next > 100000) continue;
            if(dist[next]!=-1) continue;
            dist[next] = dist[cur] + 1;
            q.push(next);
        }  
    }
    cout << dist[k];
    return 0;
}