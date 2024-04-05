// 4week_task1_12211736_�����
/* �ı� : 
*/
#include <iostream>   
#include <string> // ���ڿ��� ����ϱ� ���� �������
#include <fstream> // ���� ������� ���� �������
#include <iomanip> // quoted�� ����ϱ� ���� �������
using namespace std;// std ���ӽ����̽� ��� 
#define MAXSIZE 100 // �迭�� �ִ� ũ��


class Friend {
private:
    string name;
    int age;
    float gpa;
    string phoneNumber;

public:
    Friend() { // �⺻ ������
        // ��� ��� ������ �⺻������ �ʱ�ȭ�մϴ�.
        name = "";
        age = 0;
        gpa = 0.0;
        phoneNumber = "";
    }

    Friend(const string& initName, int initAge, float initGpa, const string& initPhoneNumber) {
        // �Ű������� ���� ������ ��� ������ �Ҵ��մϴ�.
        name = initName;
        age = initAge;
        gpa = initGpa;
        phoneNumber = initPhoneNumber;
    }

    ~Friend() {} // �Ҹ��� ����

    //set�Լ��� ����

    void setName(const string& newName) { 
        name = newName; 
    }
    void setAge(int newAge) { 
        age = newAge; 
    }
    void setGpa(float newGPA) {
        gpa = newGPA; 
    }
    void setPhoneNumber(const string& newPhoneNumber) { 
        phoneNumber = newPhoneNumber; 
    }

    //get�Լ��� ����

    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    float getGPA() const {
        return gpa;
    }

    string getPhoneNumber() const {
        return phoneNumber;
    }


};
int readAndSaveArray(Friend friends[], fstream& inFile); // ifstream ���
void printArray(Friend friends[], int n);
int main() {
    string name, phoneNumber;
    int age;
    float gpa;
    int count = 0;
    Friend myfriend[MAXSIZE]; // ģ�� ��ü �迭 ����
    
    fstream inFile("myFriends.txt", ios::in); // inFile�̶�� ���� �Է� ��Ʈ�� ��ü ����
    if (!inFile) { // ���� ���� ���н�
        cout << "���� ���� ���� ���� �߻�. ���α׷��� �����մϴ�.;";
        exit(-1);
    } // ���� ���� ���н� ���� �޽��� ��� �� ���α׷� ����
    cout << "<ģ�� ���� ���α׷�>" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    count = readAndSaveArray(myfriend, inFile); // ���Ͽ��� �����͸� �о�ͼ� �迭�� ����
    printArray(myfriend, count); // �迭�� ����� ������ ���
    return 0;
}


int readAndSaveArray(Friend friends[], fstream& inFile) {
    int count = 0;
    string name, phoneNumber;
    int age;
    float gpa; //������ �ӽ� ������ ���� ����
    while (inFile >> quoted(name) >> age >> gpa >> phoneNumber) { // ���Ͽ��� �����͸� �о�ͼ� ������ ����
        if (count < MAXSIZE) {
            friends[count] = Friend(name, age, gpa, phoneNumber);
            count++;
        }
    }
    return count;
}


void printArray(Friend friends[], int n) {
    for (int i = 0; i < n; i++) {
		cout << friends[i].getName() << " " << friends[i].getAge() << " " << friends[i].getGPA() << " " << friends[i].getPhoneNumber() << endl;
	}
    cout << "-----------------------------------------------------------------" << endl;
    cout << "����� ģ�� ���� " << n << "�� �Դϴ�." << endl;
}











