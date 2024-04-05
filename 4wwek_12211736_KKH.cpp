// 4week_task1_12211736_김기현
/*
* 후기 :
*/
#include <iostream>   
#include <string> // 문자열을 사용하기 위한 헤더파일
#include <fstream> // 파일 입출력을 위한 헤더파일
#include <iomanip> // quoted를 사용하기 위한 헤더파일
using namespace std;// std 네임스페이스 사용 
#define MAXSIZE 100 // 배열의 최대 크기
int readAndSaveArray(string name[], int age[], float gpa[], string phoneNumber[], fstream& stream); // 배열을 읽고 출력하는 함수 선언
void printArray(string name[], int age[], float gpa[], string phoneNumber[], int n);



int main() {
    Friend myfriend[MAXSIZE]; // 친구 객체 배열 생성
    string name[MAXSIZE]; // 이름을 담을 배열
    int age[MAXSIZE]; // 나이를 담을 배열
    float gpa[MAXSIZE]; // 학점을 담을 배열
    string phoneNumber[MAXSIZE]; // 전화번호를 담을 배열
    int count;
    //배열 선언
    fstream inFile("myFriends.txt", ios::in); // inFile이라는 파일 입력 스트림 객체 생성
    if (!inFile) { // 파일 열기 실패시
        cout << "파일 파일 열기 오류 발생. 프로그램을 종료합니다.;";
        exit(-1);
    } // 파일 열기 실패시 오류 메시지 출력 후 프로그램 종료
    cout << "<친구 관리 프로그램>" << endl;
    cout << "-----------------------------------------------------------------" << endl;

    count = readAndSaveArray(name, age, gpa, phoneNumber, inFile); // 배열을 읽고 출력하는 함수 호출
    printArray(name, age, gpa, phoneNumber, count);
    return 0;
}

int readAndSaveArray(string name[], int age[], float gpa[], string phoneNumber[], fstream& stream) { // 배열을 읽고 출력하는 함수 정의
    int count = 0; // 배열의 인덱스
    while (stream >> quoted(name[count]) >> age[count] >> gpa[count] >> phoneNumber[count]) { // 파일의 끝까지 읽음
        //배열안의 count를 통해 인덱스에 맞는 값들을 차례대로 읽어나감
        quoted(name[count]);
        age[count];
        gpa[count];
        phoneNumber[count];
        count++; //다음 인덱스로 넘어가기 위한 연산자
    } // while문을 통해 반복
    stream.close(); // 파일 닫기

    return count;
}

void printArray(string name[], int age[], float gpa[], string phoneNumber[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "이름 : " << quoted(name[i]) << ", 나이 : " << age[i] << ", 학점 : " << gpa[i] << ", 전화번호 : " << phoneNumber[i] << endl;
    }
    cout << "-----------------------------------------------------------------" << endl;
    cout << "저장된 친구 수는 " << n << "명 입니다." << endl;
}

//수정본