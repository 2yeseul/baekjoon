#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int nums[N] = {};
    for(int i=0;i<N;i++) {
        int temp;
        cin >> temp;
        nums[i] = temp;
    }
    int findInt;
    cin>>findInt;
    int count=0;
    for(int i=0;i<N;i++) {
        if(nums[i] == findInt) count++;
    }
    cout<< count;
    return 0;
}
