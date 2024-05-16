#include <iostream>
#include <string>
using namespace std;
#include "Friend2.h"

Friend2::Friend2(const string& name, int age, float gpa, const string& number) {
    setName(name);
    setAge(age);
    setGpa(initGpa);
    setNumber(number);
}