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
void readAndPrintArray(string name[], int age[], float gpa[], string phoneNumber[], fstream& stream); // 배열을 읽고 출력하는 함수 선언

int main() {
    string name[MAXSIZE]; 
    int age[MAXSIZE];
    float gpa[MAXSIZE];
    string phoneNumber[MAXSIZE];
    //배열 선언
    fstream inFile("myFriends.txt", ios::in); // inFile이라는 파일 입력 스트림 객체 생성
    if (!inFile) {
        cout << "파일 파일 열기 오류 발생. 프로그램을 종료합니다.;";
        exit(-1);
    } // 파일 열기 실패시 오류 메시지 출력 후 프로그램 종료
    cout << "<친구 관리 프로그램>" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    readAndPrintArray(name, age, gpa, phoneNumber, inFile); // 배열을 읽고 출력하는 함수 호출
    return 0;
}

void readAndPrintArray(string name[], int age[], float gpa[], string phoneNumber[], fstream& stream) { // 배열을 읽고 출력하는 함수 정의
    int count = 0; // 배열의 인덱스
    while (stream >> quoted(name[count]) >> age[count] >> gpa[count] >> phoneNumber[count]) { // 파일의 끝까지 읽음
        cout << "이름 : "<< quoted(name[count]) << ", 나이 : " << age[count] << ", 학점 : " << gpa[count] << ", 전화번호 : " << phoneNumber[count] << endl; // 읽은 데이터 출력
        count++;
    } // while
    cout << "-----------------------------------------------------------------" << endl;
    cout << "저장된 친구 수는" << count << "명 입니다." << endl;
}
