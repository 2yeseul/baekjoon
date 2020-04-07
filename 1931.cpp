#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;


int main(){
    vector<pair<int,int>> conf; // 회의 시작 - 끝
    int num; // 회의수
	cout<<"Enter the number of conf\n";
    cin>>num;
    for(int i=0;i<num;i++) {
        int start,end;
        cout<<"Enter the time of start and the end\n";
        cin>>start>>end;
        conf.push_back(make_pair(start, end));
    }
    sort(conf.begin(), conf.end());

    for(int i=0;i<conf.size();i++){
        cout<<conf[i].first<<" "<<conf[i].second<<endl;
    }

    int index = 0;
    int count = 1;
    for(int i=1;i<num;i++) {
        if(conf[index].second <= conf[i].first) {
            count++;
            index = i;
        } 
    }
    cout<<count<<endl;
	return 0;
}
