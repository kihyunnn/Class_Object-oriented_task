//���� ��ȣ:2 �й�: 12222367 �̸�: �̰��
/*
������Ȳ
ģ�� ���� ���α׷��� �迭�� �Լ��� ����Ͽ� �����Ѵ�.
�ǽ��� ģ�� ���� �Է� �迭 ���� ���α׷����� ������ ���Ϸκ��� ģ�� ������ �Է��Ͽ� �� ������ �����ϴ� �迭 name[i[, age[i], gpa[i], mobile[i]�� �����ϴ� �Լ� ���� ���
�迭�� ����� ģ�� ������ �Ʒ��� ���� ����ϴ� �Լ� ����, ���
��� ����: cout << quoted(name[i]) << "," << age[i] << ", " << gpa[i] << "," << mobile[i] << endl;
main �Լ����� ���� ���� �Լ����� ȣ���ؼ� �����͸� �а� ����ϰ�, ���������� �� ���� ģ�� ������ ó���Ǿ����� �Բ� ����Ѵ�.
��, ģ���� ������ �� �ִ� �迭�� �ִ� ũ��� MAXNO�� 100���� �����Ѵ�.

�ı�

*/
//myfriend txt������ �����ȴ�. 

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

#define MAXNOS 100

string name[MAXNOS];
int age[MAXNOS];
float gpa[MAXNOS];
string mobile[MAXNOS];
static int count = 0;

void fileToArray() {
    fstream inFile("myFriends.txt", ios::in);
    if (!inFile) {
        cout << "�Է� ���� ����" << endl;
        exit(-1);
    }


    while (inFile >> quoted(name[count]) >> age[count] >> gpa[count] >> mobile[count]) {
        cout << quoted(name[count]) << ", " << age[count] << ", " << gpa[count] << ", " << mobile[count] << endl;
        count++;
    }
    inFile.close();
}

void display() {
    for (int i = 0; i < count; i++) {
        cout << quoted(name[i]) << ", " << age[i] << ", " << gpa[i] << ", " << mobile[i] << endl;

    }
}

int main() {
    fileToArray();
    display();
    return 0;
}