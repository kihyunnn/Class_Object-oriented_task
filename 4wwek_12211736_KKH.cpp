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
void readAndPrintArray(string name[], int age[], float gpa[], string phoneNumber[], fstream& stream); // �迭�� �а� ����ϴ� �Լ� ����

int main() {
    string name[MAXSIZE]; 
    int age[MAXSIZE];
    float gpa[MAXSIZE];
    string phoneNumber[MAXSIZE];
    //�迭 ����
    fstream inFile("myFriends.txt", ios::in); // inFile�̶�� ���� �Է� ��Ʈ�� ��ü ����
    if (!inFile) {
        cout << "���� ���� ���� ���� �߻�. ���α׷��� �����մϴ�.;";
        exit(-1);
    } // ���� ���� ���н� ���� �޽��� ��� �� ���α׷� ����
    cout << "<ģ�� ���� ���α׷�>" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    readAndPrintArray(name, age, gpa, phoneNumber, inFile); // �迭�� �а� ����ϴ� �Լ� ȣ��
    return 0;
}

void readAndPrintArray(string name[], int age[], float gpa[], string phoneNumber[], fstream& stream) { // �迭�� �а� ����ϴ� �Լ� ����
    int count = 0; // �迭�� �ε���
    while (stream >> quoted(name[count]) >> age[count] >> gpa[count] >> phoneNumber[count]) { // ������ ������ ����
        cout << "�̸� : "<< quoted(name[count]) << ", ���� : " << age[count] << ", ���� : " << gpa[count] << ", ��ȭ��ȣ : " << phoneNumber[count] << endl; // ���� ������ ���
        count++;
    } // while
    cout << "-----------------------------------------------------------------" << endl;
    cout << "����� ģ�� ���� " << count << "�� �Դϴ�." << endl;
}
