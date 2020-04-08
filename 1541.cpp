#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
    string numbers;
    vector<int> plus;
    vector<int> minus;
    cin>>numbers;
    int flag = 1; // plus : 1 , minus : 0
    int previousIndex = 0;
    int temp = 0;

    for(int i=0;i<numbers.length();i++) {
        if(numbers.at(i) == '+' || numbers.at(i) == '-' ) {
            temp = stoi(numbers.substr(previousIndex, i));
            previousIndex = i+1;
            // 아직 minus 못만난 경우
            if(numbers.at(i) == '-' && flag == 1) {
                flag = 0;
                plus.push_back(temp);
            }
            else if(numbers.at(i) == '+' && flag == 1) {
                plus.push_back(temp);
            }
            // minus 만난 경우
            else if(flag == 0) {
                minus.push_back(temp);
            }
        }
    }
    // 마지막 숫자
    if(flag == 0) {
        temp = stoi(numbers.substr(previousIndex, numbers.length()));
        minus.push_back(temp);
    }
    else {
        temp = stoi(numbers.substr(previousIndex, numbers.length()));
        plus.push_back(temp);
    }
    int sum = 0;
    for(int i=0;i<plus.size();i++) sum += plus[i];
    for(int i=0;i<minus.size();i++) sum -= minus[i];

    cout<<sum<<endl;
    return 0;
}
