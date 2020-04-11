#include <iostream>
#include <vector>
#include <utility>
using namespace std;

pair<int, int> v[41];

pair<int, int> getCount(int n) {
    v[0] = pair<int, int>(1, 0);
    v[1] = pair<int, int>(0, 1);

    if(n == 0 || n == 1) {
        return v[n];
    }

    if(v[n].first!=0 && v[n].second!=0) return v[n];
    else { 
        v[n] = make_pair(getCount(n-1).first + getCount(n-2).first, 
        getCount(n-1).second + getCount(n-2).second);
    }
    return v[n];
}


int main() 
{
    getCount(40);
    int N;
    cin>>N;
   // vector<int> temp;
    for(int i=0;i<N;i++) {
        int n;
        cin>>n;
        cout<<v[n].first<<" "<<v[n].second<<"\n";
    }
    return 0;
}
