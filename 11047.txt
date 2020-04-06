#include <iostream>
using namespace std;

int main(){
    int N,K;
    cin>>N>>K;
    int value[N] = {0,};
    for(int i=0;i<N;i++){
        cin>>value[i];
    }
	
    int answer = 0;
    int leftSum = K;
    for(int i=N-1;i>=0;i--){
        if(value[i] <= leftSum && leftSum != 0) {
            int tempNum = 0;
            tempNum = leftSum / value[i];
            answer += tempNum;
            leftSum = leftSum - (tempNum * value[i]);
        }
    }
	cout<<answer;
    return 0;
}
