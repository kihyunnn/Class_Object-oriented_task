#include <iostream>
#include <string>
using namespace std;
#ifndef FRIEND2_H
#define FRIEND2_H

class Friend2 {
private:
	string name;
	int age;
	float gpa;
	string number;

public:
	Friend2(const string& name = "", int age = 0, float gpa = 0.0, const string& number = "");
	~Friend();
	//set 함수들
	void setName(const string& name);
	void setAge(int age);
	void setGpa(float gpa);
	void setNumber(const string& number);
	//get 함수들
	string getName() const;
	int getAge() const;
	float getGpa() const;
	string getNumber() const;
};


#endif