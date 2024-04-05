// 4week_task1_12211736_�����
/*
* �ı� :
*/
#include <iostream>   
#include <string> // ���ڿ��� ����ϱ� ���� �������
#include <fstream> // ���� ������� ���� �������
#include <iomanip> // quoted�� ����ϱ� ���� �������
using namespace std;// std ���ӽ����̽� ��� 
#define MAXSIZE 100 // �迭�� �ִ� ũ��
int readAndSaveArray(string name[], int age[], float gpa[], string phoneNumber[], fstream& stream); // �迭�� �а� ����ϴ� �Լ� ����
void printArray(string name[], int age[], float gpa[], string phoneNumber[], int n);



int main() {
    Friend myfriend[MAXSIZE]; // ģ�� ��ü �迭 ����
    string name[MAXSIZE]; // �̸��� ���� �迭
    int age[MAXSIZE]; // ���̸� ���� �迭
    float gpa[MAXSIZE]; // ������ ���� �迭
    string phoneNumber[MAXSIZE]; // ��ȭ��ȣ�� ���� �迭
    int count;
    //�迭 ����
    fstream inFile("myFriends.txt", ios::in); // inFile�̶�� ���� �Է� ��Ʈ�� ��ü ����
    if (!inFile) { // ���� ���� ���н�
        cout << "���� ���� ���� ���� �߻�. ���α׷��� �����մϴ�.;";
        exit(-1);
    } // ���� ���� ���н� ���� �޽��� ��� �� ���α׷� ����
    cout << "<ģ�� ���� ���α׷�>" << endl;
    cout << "-----------------------------------------------------------------" << endl;

    count = readAndSaveArray(name, age, gpa, phoneNumber, inFile); // �迭�� �а� ����ϴ� �Լ� ȣ��
    printArray(name, age, gpa, phoneNumber, count);
    return 0;
}

int readAndSaveArray(string name[], int age[], float gpa[], string phoneNumber[], fstream& stream) { // �迭�� �а� ����ϴ� �Լ� ����
    int count = 0; // �迭�� �ε���
    while (stream >> quoted(name[count]) >> age[count] >> gpa[count] >> phoneNumber[count]) { // ������ ������ ����
        //�迭���� count�� ���� �ε����� �´� ������ ���ʴ�� �о��
        quoted(name[count]);
        age[count];
        gpa[count];
        phoneNumber[count];
        count++; //���� �ε����� �Ѿ�� ���� ������
    } // while���� ���� �ݺ�
    stream.close(); // ���� �ݱ�

    return count;
}

void printArray(string name[], int age[], float gpa[], string phoneNumber[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "�̸� : " << quoted(name[i]) << ", ���� : " << age[i] << ", ���� : " << gpa[i] << ", ��ȭ��ȣ : " << phoneNumber[i] << endl;
    }
    cout << "-----------------------------------------------------------------" << endl;
    cout << "����� ģ�� ���� " << n << "�� �Դϴ�." << endl;
}

//������