#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
int main(){
    vector<pair<int,int> > conf; // 회의 시작 - 끝
    int num; // 회의수
	cin>>num;
    for(int i=0;i<num;i++) {
        int start,end;
        cin>>start>>end;
        conf.push_back(make_pair(end, start));
    }
    sort(conf.begin(), conf.end());
    int index = 0;
    int count = 1;
    int pivotValue = conf[0].first;
    for(int i=1;i<num;i++) {
        if(conf[index].first <= conf[i].second) {
            index = i;
            count++;
        } 
    }
    cout<<count<<"\n";
	return 0;
}
