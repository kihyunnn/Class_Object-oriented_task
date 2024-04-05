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

int main() {
    //파일 입력을 위한 변수 선언
    int friendNum; // 친구 수
    string name; // 이름
    int age; // 나이
    float gpa; // 학점
    string number; // 전화번호


    ofstream outFile("myFriends.txt", ios::out); // 파일 출력 스트림 객체 생성
    if (!outFile) { // 파일 열기 실패시
        cerr << "파일을 열 수 없습니다." << endl;
        exit(1);
    }

    cout << "친구 수를 입력하세요 : ";
    cin >> friendNum; //친구수를 입려받습니다.
    cout << endl;

    for (int i = 0; i < friendNum; i++) {
        cout << "친구 이름 : ";
        cin >> quoted(name);
        cout << "친구 나이 : ";
        cin >> age;
        cout << "친구 학점 : ";
        cin >> gpa;
        cout << "친구 전화번호 : ";
        cin >> quoted(number);
        cout << endl;

        outFile << quoted(name) << " " << age << " " << gpa << "" << quoted(number) << endl;
    }
    outFile.close(); // 파일 닫기


    return 0;
}

