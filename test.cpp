//과제 번호:2 학번: 12222367 이름: 이경민
/*
문제상황
친구 관리 프로그램을 배열과 함수를 사용하여 개선한다.
실습한 친구 파일 입력 배열 저장 프로그램에서 데이터 파일로부터 친구 정보를 입력하여 각 정보를 저장하는 배열 name[i[, age[i], gpa[i], mobile[i]에 저장하는 함수 정의 사용
배열에 저장된 친구 정보를 아래와 같이 출력하는 함수 정의, 사용
출력 형식: cout << quoted(name[i]) << "," << age[i] << ", " << gpa[i] << "," << mobile[i] << endl;
main 함수에서 위의 정의 함수들을 호출해서 데이터를 읽고 출력하고, 최종적으로 몇 명의 친구 정보가 처리되었는지 함께 출력한다.
단, 친구를 저장할 수 있는 배열의 최대 크기는 MAXNO는 100으로 지정한다.

후기

*/
//myfriend txt파일이 생성된다. 

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

#define MAXNOS 100

string name[MAXNOS];
int age[MAXNOS];
float gpa[MAXNOS];
string mobile[MAXNOS];
static int count = 0;

void fileToArray() {
    fstream inFile("myFriends.txt", ios::in);
    if (!inFile) {
        cout << "입력 파일 없음" << endl;
        exit(-1);
    }


    while (inFile >> quoted(name[count]) >> age[count] >> gpa[count] >> mobile[count]) {
        cout << quoted(name[count]) << ", " << age[count] << ", " << gpa[count] << ", " << mobile[count] << endl;
        count++;
    }
    inFile.close();
}

void display() {
    for (int i = 0; i < count; i++) {
        cout << quoted(name[i]) << ", " << age[i] << ", " << gpa[i] << ", " << mobile[i] << endl;

    }
}

int main() {
    fileToArray();
    display();
    return 0;
}