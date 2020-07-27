#include <iostream>

using namespace std;

int main() {

    int girl[6] = {0,};
    int boy[6] = {0, };
    int numberOfstudent = 0;
    int maxStudent = 0;
    int grade = 0;
    int sex = 0;
    cin >> numberOfstudent >> maxStudent;
    

    for(int i = 0;i<numberOfstudent;i++) {
        cin >> sex >> grade;
        // 여자 : 0 남자 : 1
        if(sex == 0) girl[grade - 1]++;
        else boy[grade - 1]++;
    }
    
    int girlCount = 0;
    for(int i = 0 ; i < 6 ; i++) {
        if(girl[i] == 0) girlCount+=0;
        else {
            girlCount += girl[i] / maxStudent;
            if(girl[i] % maxStudent != 0 ) girlCount++;
        }
    }
    
    int boyCount = 0;
    for(int i=0;i<6;i++) {
        if(boy[i] == 0) boyCount+=0;
        else {
            boyCount += boy[i] / maxStudent;
            if(boy[i] % maxStudent != 0) boyCount ++;
        }
    }
    
    cout << girlCount + boyCount << endl;
    
    
    return 0;
}
