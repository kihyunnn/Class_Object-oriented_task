// 4week_task1_12211736_김기현
/* 후기 : 
*/
#include <iostream>   
#include <string> // 문자열을 사용하기 위한 헤더파일
#include <fstream> // 파일 입출력을 위한 헤더파일
#include <iomanip> // quoted를 사용하기 위한 헤더파일
using namespace std;// std 네임스페이스 사용 
#define MAXSIZE 100 // 배열의 최대 크기


class Friend {
private:
    string name;
    int age;
    float gpa;
    string phoneNumber;

public:
    Friend() { // 기본 생성자
        // 모든 멤버 변수를 기본값으로 초기화합니다.
        name = "";
        age = 0;
        gpa = 0.0;
        phoneNumber = "";
    }

    Friend(const string& initName, int initAge, float initGpa, const string& initPhoneNumber) {
        // 매개변수로 받은 값들을 멤버 변수에 할당합니다.
        name = initName;
        age = initAge;
        gpa = initGpa;
        phoneNumber = initPhoneNumber;
    }

    ~Friend() {} // 소멸자 정의

    //set함수들 모음

    void setName(const string& newName) { 
        name = newName; 
    }
    void setAge(int newAge) { 
        age = newAge; 
    }
    void setGpa(float newGPA) {
        gpa = newGPA; 
    }
    void setPhoneNumber(const string& newPhoneNumber) { 
        phoneNumber = newPhoneNumber; 
    }

    //get함수들 모음

    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    float getGPA() const {
        return gpa;
    }

    string getPhoneNumber() const {
        return phoneNumber;
    }


};
int readAndSaveArray(Friend friends[], fstream& inFile); // ifstream 사용
void printArray(Friend friends[], int n);
int main() {
    string name, phoneNumber;
    int age;
    float gpa;
    int count = 0;
    Friend myfriend[MAXSIZE]; // 친구 객체 배열 생성
    
    fstream inFile("myFriends.txt", ios::in); // inFile이라는 파일 입력 스트림 객체 생성
    if (!inFile) { // 파일 열기 실패시
        cout << "파일 파일 열기 오류 발생. 프로그램을 종료합니다.;";
        exit(-1);
    } // 파일 열기 실패시 오류 메시지 출력 후 프로그램 종료
    cout << "<친구 관리 프로그램>" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    count = readAndSaveArray(myfriend, inFile); // 파일에서 데이터를 읽어와서 배열에 저장
    printArray(myfriend, count); // 배열에 저장된 데이터 출력
    return 0;
}


int readAndSaveArray(Friend friends[], fstream& inFile) {
    int count = 0;
    string name, phoneNumber;
    int age;
    float gpa; //변수를 임시 저장할 변수 선언
    while (inFile >> quoted(name) >> age >> gpa >> phoneNumber) { // 파일에서 데이터를 읽어와서 변수에 저장
        if (count < MAXSIZE) {
            friends[count] = Friend(name, age, gpa, phoneNumber);
            count++;
        }
    }
    return count;
}


void printArray(Friend friends[], int n) {
    for (int i = 0; i < n; i++) {
		cout << friends[i].getName() << " " << friends[i].getAge() << " " << friends[i].getGPA() << " " << friends[i].getPhoneNumber() << endl;
	}
    cout << "-----------------------------------------------------------------" << endl;
    cout << "저장된 친구 수는 " << n << "명 입니다." << endl;
}











