#include <iostream>   
#include <string> // ���ڿ��� ����ϱ� ���� �������
using namespace std;// std ���ӽ����̽� ��� 

#include "Friend.h" //Friend ��������� inclue

    Friend::Friend(const string& initName , int initAge , float initGpa , const string& initPhoneNumber ) {
        // �Ű������� ���� ������ ��� ������ �Ҵ��մϴ�. �迭�� ��ü�� ��ġ�� ũ�ϱ� & ���۷����� ����
        //
        setName(initName);
        setAge(initAge);
        setGpa(initGpa);
        setPhoneNumber(initPhoneNumber);
    }
    Friend::~Friend() {} // �Ҹ��� ����
    //set�Լ��� ����
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
    //get�Լ��� ����
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

