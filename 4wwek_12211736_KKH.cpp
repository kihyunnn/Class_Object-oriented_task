// 4week_task1_12211736_김기현
/* 간단한 설계 과정 :
* 후기적기
*/
#include <iostream>  
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;// std 네임스페이스 사용 
#define MAXSIZE 100 // 배열의 최대 크기
void printArray(string name[], int age[], float gpa[], string phoneNumber[], fstream& stream);

int main() {
    int friendNum; // 친구 수
    string name[MAXSIZE];
    int age[MAXSIZE];
    float gpa[MAXSIZE];
    string phoneNumber[MAXSIZE];

    fstream inFile("myFriends.txt", ios::in);
    if (!inFile) {
        cout << "파일 파일 열기 오류;";
        exit(-1);
    } // if file not exist

    printArray(name, age, gpa, phoneNumber, inFile);



    return 0;
}


void printArray(string name[], int age[], float gpa[], string phoneNumber[], fstream& stream) {
    int count = 0;
    while (stream >> quoted(name[count]) >> age[count] >> gpa[count] >> phoneNumber[count]) { // 파일의 끝까지 읽음
        cout << quoted(name[count]) << ", " << age[count] << ", " << gpa[count] << ", " << phoneNumber[count] << endl;
        count++;
    } // while
}

