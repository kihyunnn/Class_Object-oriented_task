// 6week_과제4_12211736_김기현
/* 후기 :
* 이번 과제는 하나로 구현되어있던 cpp파일을 클래스 헤더 파일, 클래스 구현 파일, 드라이버 파일 3개로 분리했습니다. 차후에 클래스를 수정해야 할 때,
* 더 용이 할 것 같습니다. 하는 도중에 2가지 오류가 생겼었는데, 먼저 헤더파일과 클래스 구현 파일에 소멸자를 각각 정의했다가 오류가 생겼었습니다.
* 이 오류를 해결하면서 다른 함수와 달리 소멸자는 헤더파일이나 클래스 구현 파일 중 하나에만 선언하면됨을 알게 되었습니다. 두번 째로, 클래스를 복사해서
* 붙인다음 수정하다보니, 클래스 구현 파일에도 기본 파라미터 값이 있었는데, 기본 파라미터 값은 한군데만 있으면 되기때문에 클래스 구현 파일에
* 디폴트 값을 없애서 오류를 해결했습니다. 복잡한 프로그램은 아니라 오히려 파일을 분리하는게 익숙하지 않아 어려웠지만, 점점 복잡한 프로그램을 짜다보면
* 이렇게 분리해서 구현하는 것이 훨씬 효율적일 것 같습니다.
*/
#include <iostream>   
#include <string> // 문자열을 사용하기 위한 헤더파일
#include <fstream> // 파일 입출력을 위한 헤더파일
#include <iomanip> // quoted를 사용하기 위한 헤더파일
using namespace std;// std 네임스페이스 사용 
#define MAXSIZE 100 // 배열의 최대 크기
#include "Friend.h" //Frriend 헤더파일 include 

// 전역함수 선언
int readAndSaveArray(Friend friends[], fstream& inFile);
void printArray(Friend friends[], int n);
void bubbleSortFriends(Friend friends[], int n);

int main() {
    int count = 0;
    Friend myfriend[MAXSIZE]; // 친구 객체 배열 생성

    fstream inFile("myFriends.txt", ios::in); // inFile이라는 파일 입력 스트림 객체 생성
    if (!inFile) { // 파일 열기 실패시
        cout << "파일 파일 열기 오류 발생. 프로그램을 종료합니다.;";
        exit(-1);
    } // 파일 열기 실패시 오류 메시지 출력 후 프로그램 종료

    cout << "<친구 관리 프로그램>" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    count = readAndSaveArray(myfriend, inFile); // 파일에서 데이터를 읽어와서 배열에 저장, 파라미터 친구 객체 사용
    bubbleSortFriends(myfriend, count); // 이름을 기준으로 정렬
    printArray(myfriend, count); // 배열에 저장된 데이터 출력, 파라미터 친구 객체 사용
    return 0;
}


int readAndSaveArray(Friend friends[], fstream& inFile) {
    int count = 0;
    string name, phoneNumber;
    int age;
    float gpa; //변수를 임시 저장할 변수 선언 
    while (inFile >> quoted(name) >> age >> gpa >> phoneNumber) { // 파일에서 데이터를 읽어와서 변수에 저장
        if (count < MAXSIZE) {
            //각 count에 맞게 friend의 set 멤버 함수를 통해 값을 읽어서 넣음
            friends[count].setName(name);
            friends[count].setAge(age);
            friends[count].setGpa(gpa);
            friends[count].setPhoneNumber(phoneNumber);
            count++;
        }
    }
    return count;
}


void printArray(Friend friends[], int n) {
    for (int i = 0; i < n; i++) {
        cout << friends[i].getName() << " " << friends[i].getAge() << " " << friends[i].getGPA() << " " << friends[i].getPhoneNumber() << endl;
    } // 이전과 달리 get 멤버 함수를 이용하여 해당 배열의 값을 출력함 . 을이용해서 멤버함수에 접근
    cout << "-----------------------------------------------------------------" << endl;
    cout << "저장된 친구 수는 " << n << "명 입니다." << endl;
}


//void bubbleSortFriends(Friend friends[], int n) {
//    bool swapped;
//    do {
//        swapped = false;
//        for (int i = 0; i < n - 1; i++) {
//            if (friends[i].getName() > friends[i + 1].getName()) {
//                // 교환 로직
//                Friend temp = friends[i];
//                friends[i] = friends[i + 1];
//                friends[i + 1] = temp;
//                swapped = true;
//            }
//        }
//    } while (swapped);
//}

void bubbleSortFriends(Friend friends[], int n) {
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < n-1; i++) {
            if (friends[i].getName() > friends[i + 1].getName()) {
                Friend temp = friends[i];
                friends[i] = friends[i + 1];
                friends[i + 1] = temp;
                swapped = true;
            }
        }
    } while (swapped);
}
