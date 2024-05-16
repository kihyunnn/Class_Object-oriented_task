#include <iostream>   
#include <string> // ���ڿ��� ����ϱ� ���� �������
using namespace std;// std ���ӽ����̽� ��� 
//������ define�Ǵ� ���� �����մϴ�.
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
    ~Friend();// �Ҹ��� ����
    //set�Լ��� ����
    void setName(const string& newName);
    void setAge(int newAge);
    void setGpa(float newGPA);
    void setPhoneNumber(const string& newPhoneNumber);
    //get�Լ��� ����
    string getName() const;
    int getAge() const;
    float getGPA() const;
    string getPhoneNumber() const;
};

#endif

