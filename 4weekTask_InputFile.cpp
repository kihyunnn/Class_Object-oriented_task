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

int main() {
    //���� �Է��� ���� ���� ����
    int friendNum; // ģ�� ��
    string name; // �̸�
    int age; // ����
    float gpa; // ����
    string number; // ��ȭ��ȣ


    ofstream outFile("myFriends.txt", ios::out); // ���� ��� ��Ʈ�� ��ü ����
    if (!outFile) { // ���� ���� ���н�
        cerr << "������ �� �� �����ϴ�." << endl;
        exit(1);
    }

    cout << "ģ�� ���� �Է��ϼ��� : ";
    cin >> friendNum;
    cout << endl;

    for (int i = 0; i < friendNum; i++) {
        cout << "ģ�� �̸� : ";
        cin >> quoted(name);
        cout << "ģ�� ���� : ";
        cin >> age;
        cout << "ģ�� ���� : ";
        cin >> gpa;
        cout << "ģ�� ��ȭ��ȣ : ";
        cin >> quoted(number);
        cout << endl;

        outFile << quoted(name) << " " << age << " " << number << endl;
    }
    outFile.close(); // ���� �ݱ�


    return 0;
}

