#include <iostream>   
#include <string> // 문자열을 사용하기 위한 헤더파일
using namespace std;// std 네임스페이스 사용 
//여러번 define되는 것을 방지합니다.
#ifndef FRIEND_H 
#define FRIEND_H

class Friend {
private:
    string name;
    int age;
    float gpa;
    string phoneNumber;

public:
    Friend(const string& initName = "", int initAge = 0, float initGpa = 0.0, const string& initPhoneNumber = "");
    ~Friend();// 소멸자 정의
    //set함수들 모음
    void setName(const string& newName);
    void setAge(int newAge);
    void setGpa(float newGPA);
    void setPhoneNumber(const string& newPhoneNumber);
    //get함수들 모음
    string getName() const;
    int getAge() const;
    float getGPA() const;
    string getPhoneNumber() const;
};

#endif

