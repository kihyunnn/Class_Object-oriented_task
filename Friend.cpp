#include <iostream>   
#include <string> // 문자열을 사용하기 위한 헤더파일
using namespace std;// std 네임스페이스 사용 

#include "Friend.h" //Friend 헤더파일을 inclue

    Friend::Friend(const string& initName , int initAge , float initGpa , const string& initPhoneNumber ) {
        // 매개변수로 받은 값들을 멤버 변수에 할당합니다. 배열과 객체는 덩치가 크니까 & 레퍼런스로 전달
        //
        setName(initName);
        setAge(initAge);
        setGpa(initGpa);
        setPhoneNumber(initPhoneNumber);
    }
    Friend::~Friend() {} // 소멸자 정의
    //set함수들 모음
    void Friend::setName(const string& newName) {
        name = newName;
    }
    void Friend::setAge(int newAge) {

        age = newAge;
    }
    void Friend::setGpa(float newGPA) {
        gpa = newGPA;
    }
    void Friend::setPhoneNumber(const string& newPhoneNumber) {
        phoneNumber = newPhoneNumber;
    }
    //get함수들 모음
    string Friend::getName() const {
        return name;
    }
    int Friend::getAge() const {
        return age;
    }
    float Friend::getGPA() const {
        return gpa;
    }
    string Friend::getPhoneNumber() const {
        return phoneNumber;
    }

