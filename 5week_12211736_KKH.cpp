// 5week_과제3_12211736_김기현
/* 후기 : 
* 이번 과제는 저번 과제의 이름,학번 등을 각각 배열로 선언했던 것을 class를 통해 사용자 정의 타입을 만들어 사용하는 문제였습니다.
* c언어의 Structure는 구조가 명확하여 딱 봐도 이해가 되었지만. class를 통해 사용자 정의 타입을 만드는 것은 어려웠습니다. 
* 특히 class로 사용자 정의 타입처럼 사용한다는 것 자체가 처음에는 잘 이해가 되지 않았습니다. 그래서 초반에 더 해맸던 것 같습니다.
* 직접 코드를 작성하고 생각해보면서 이해하게 된 것은, Friend라는 객체를 내가 필요한 값들의 묶음으로 선언함으로써, Friend를 호출 했을 때
* 사용자 정의 타입처럼 사용할 수 있습니다. main에서는 Friend myfriend[MAXSIZE];와 같이 배열로 생성했습니다. 처음에는 특히 생성자에 대해 이해가
* 잘 안되었습니다. main에서 선언 할 때 필요한 생성자와 실제로 계속 호출하면서 값을 넣을 때 필요한 생성자를 분리해야하나?
* 라는 고민을 했었습니다. 그래서 처음에는 friend()에 아무 것도 안넣은 생성자를 만들고, 
frien((const string& initName, int initAge, float initGpa, const string& initPhoneNumber)와 같이, 두개를 만들었습니다. 제 생각에는 틀린게 없었는데
실행에서 오류가 생기는 것을 보고, 실행이 어떻게 되고있는지 생각해보고 교수님이 말씀해주신 것을 참고하여 컴파일러는 friend라는 호출을 할 때,
이게 파라미터가 없는 1번 함수인지, 파라미터가 있는데 지금 파라미터가 없이 실행을 한건지 구분할 수 없어서 오류가 난 것 이었습니다. 그래서
한번에 이 문제를 해결하고 불필요하게 함수를 2개 만들지 않기 위해, friend 생성자를 만들 때, 디폴트 값을 모두 선언해줘서 값을 내가 대입하면
그 대입한 값으로 set함수를 이용하여 값을 추가하고, 처음에 호출하는 것은 디폴트 값을 넣어서 문제없이 실행되도록 하나의 생성자로 문제를 해결했습니다.
처음에는 클래스를 어떻게 사용자 정의 타입처럼 이용하는지도 이해가 안되었고, 생성자가 언제 선언되고 왜 오류가 나는지 몰랐지만, 이번 과제를 통해서
자세히 이해한 것 같습니다. 특히 생성자를 어떻게 선언해야하는지에 대한 이해도가 높아졌습니다. 잘 사용한다면 정말 유용할 것 같은 클래스의 구조를
좀 더 완벽히 이해해야 더 복잡한 상황에서도 제가 원하는 기능을 구현할 수 있을 것 같습니다. 클래스 부분의 깊은 공부의 필요성을 느꼈습니다
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

    Friend(const string& initName = "", int initAge = 0, float initGpa = 0.0, const string& initPhoneNumber = "") {
        // 매개변수로 받은 값들을 멤버 변수에 할당합니다.
        setName(initName);
        setAge(initAge);
        setGpa(initGpa);
        setPhoneNumber(initPhoneNumber);
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

// 전역함수 선언
int readAndSaveArray(Friend friends[], fstream& inFile); 
void printArray(Friend friends[], int n);

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











