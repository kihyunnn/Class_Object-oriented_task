// 6week_����4_12211736_�����
/* �ı� :
* �̹� ������ �ϳ��� �����Ǿ��ִ� cpp������ Ŭ���� ��� ����, Ŭ���� ���� ����, ����̹� ���� 3���� �и��߽��ϴ�. ���Ŀ� Ŭ������ �����ؾ� �� ��,
* �� ���� �� �� �����ϴ�. �ϴ� ���߿� 2���� ������ ������µ�, ���� ������ϰ� Ŭ���� ���� ���Ͽ� �Ҹ��ڸ� ���� �����ߴٰ� ������ ��������ϴ�.
* �� ������ �ذ��ϸ鼭 �ٸ� �Լ��� �޸� �Ҹ��ڴ� ��������̳� Ŭ���� ���� ���� �� �ϳ����� �����ϸ���� �˰� �Ǿ����ϴ�. �ι� °��, Ŭ������ �����ؼ�
* ���δ��� �����ϴٺ���, Ŭ���� ���� ���Ͽ��� �⺻ �Ķ���� ���� �־��µ�, �⺻ �Ķ���� ���� �ѱ����� ������ �Ǳ⶧���� Ŭ���� ���� ���Ͽ�
* ����Ʈ ���� ���ּ� ������ �ذ��߽��ϴ�. ������ ���α׷��� �ƴ϶� ������ ������ �и��ϴ°� �ͼ����� �ʾ� ���������, ���� ������ ���α׷��� ¥�ٺ���
* �̷��� �и��ؼ� �����ϴ� ���� �ξ� ȿ������ �� �����ϴ�.
*/
#include <iostream>   
#include <string> // ���ڿ��� ����ϱ� ���� �������
#include <fstream> // ���� ������� ���� �������
#include <iomanip> // quoted�� ����ϱ� ���� �������
using namespace std;// std ���ӽ����̽� ��� 
#define MAXSIZE 100 // �迭�� �ִ� ũ��
#include "Friend.h" //Frriend ������� include 

// �����Լ� ����
int readAndSaveArray(Friend friends[], fstream& inFile);
void printArray(Friend friends[], int n);
void bubbleSortFriends(Friend friends[], int n);

int main() {
    int count = 0;
    Friend myfriend[MAXSIZE]; // ģ�� ��ü �迭 ����

    fstream inFile("myFriends.txt", ios::in); // inFile�̶�� ���� �Է� ��Ʈ�� ��ü ����
    if (!inFile) { // ���� ���� ���н�
        cout << "���� ���� ���� ���� �߻�. ���α׷��� �����մϴ�.;";
        exit(-1);
    } // ���� ���� ���н� ���� �޽��� ��� �� ���α׷� ����

    cout << "<ģ�� ���� ���α׷�>" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    count = readAndSaveArray(myfriend, inFile); // ���Ͽ��� �����͸� �о�ͼ� �迭�� ����, �Ķ���� ģ�� ��ü ���
    bubbleSortFriends(myfriend, count); // �̸��� �������� ����
    printArray(myfriend, count); // �迭�� ����� ������ ���, �Ķ���� ģ�� ��ü ���
    return 0;
}


int readAndSaveArray(Friend friends[], fstream& inFile) {
    int count = 0;
    string name, phoneNumber;
    int age;
    float gpa; //������ �ӽ� ������ ���� ���� 
    while (inFile >> quoted(name) >> age >> gpa >> phoneNumber) { // ���Ͽ��� �����͸� �о�ͼ� ������ ����
        if (count < MAXSIZE) {
            //�� count�� �°� friend�� set ��� �Լ��� ���� ���� �о ����
            friends[count].setName(name);
            friends[count].setAge(age);
            friends[count].setGpa(gpa);
            friends[count].setPhoneNumber(phoneNumber);
            count++;
        }
    }
    return count;
}


void printArray(Friend friends[], int n) {
    for (int i = 0; i < n; i++) {
        cout << friends[i].getName() << " " << friends[i].getAge() << " " << friends[i].getGPA() << " " << friends[i].getPhoneNumber() << endl;
    } // ������ �޸� get ��� �Լ��� �̿��Ͽ� �ش� �迭�� ���� ����� . ���̿��ؼ� ����Լ��� ����
    cout << "-----------------------------------------------------------------" << endl;
    cout << "����� ģ�� ���� " << n << "�� �Դϴ�." << endl;
}


//void bubbleSortFriends(Friend friends[], int n) {
//    bool swapped;
//    do {
//        swapped = false;
//        for (int i = 0; i < n - 1; i++) {
//            if (friends[i].getName() > friends[i + 1].getName()) {
//                // ��ȯ ����
//                Friend temp = friends[i];
//                friends[i] = friends[i + 1];
//                friends[i + 1] = temp;
//                swapped = true;
//            }
//        }
//    } while (swapped);
//}

void bubbleSortFriends(Friend friends[], int n) {
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < n-1; i++) {
            if (friends[i].getName() > friends[i + 1].getName()) {
                Friend temp = friends[i];
                friends[i] = friends[i + 1];
                friends[i + 1] = temp;
                swapped = true;
            }
        }
    } while (swapped);
}
