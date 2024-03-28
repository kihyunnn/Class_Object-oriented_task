// 4week_task1_12211736_�����
/* ������ ���� ���� :
* �ı�����
*/
#include <iostream>  
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;// std ���ӽ����̽� ��� 
#define MAXSIZE 100 // �迭�� �ִ� ũ��
void printArray(string name[], int age[], float gpa[], string phoneNumber[], fstream& stream);

int main() {
    int friendNum; // ģ�� ��
    string name[MAXSIZE];
    int age[MAXSIZE];
    float gpa[MAXSIZE];
    string phoneNumber[MAXSIZE];

    fstream inFile("myFriends.txt", ios::in);
    if (!inFile) {
        cout << "���� ���� ���� ����;";
        exit(-1);
    } // if file not exist

    printArray(name, age, gpa, phoneNumber, inFile);



    return 0;
}


void printArray(string name[], int age[], float gpa[], string phoneNumber[], fstream& stream) {
    int count = 0;
    while (stream >> quoted(name[count]) >> age[count] >> gpa[count] >> phoneNumber[count]) { // ������ ������ ����
        cout << quoted(name[count]) << ", " << age[count] << ", " << gpa[count] << ", " << phoneNumber[count] << endl;
        count++;
    } // while
}

