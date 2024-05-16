// 5week_����3_12211736_�����
/* �ı� : 
* �̹� ������ ���� ������ �̸�,�й� ���� ���� �迭�� �����ߴ� ���� class�� ���� ����� ���� Ÿ���� ����� ����ϴ� ���������ϴ�.
* c����� Structure�� ������ ��Ȯ�Ͽ� �� ���� ���ذ� �Ǿ�����. class�� ���� ����� ���� Ÿ���� ����� ���� ��������ϴ�. 
* Ư�� class�� ����� ���� Ÿ��ó�� ����Ѵٴ� �� ��ü�� ó������ �� ���ذ� ���� �ʾҽ��ϴ�. �׷��� �ʹݿ� �� �ظ̴� �� �����ϴ�.
* ���� �ڵ带 �ۼ��ϰ� �����غ��鼭 �����ϰ� �� ����, Friend��� ��ü�� ���� �ʿ��� ������ �������� ���������ν�, Friend�� ȣ�� ���� ��
* ����� ���� Ÿ��ó�� ����� �� �ֽ��ϴ�. main������ Friend myfriend[MAXSIZE];�� ���� �迭�� �����߽��ϴ�. ó������ Ư�� �����ڿ� ���� ���ذ�
* �� �ȵǾ����ϴ�. main���� ���� �� �� �ʿ��� �����ڿ� ������ ��� ȣ���ϸ鼭 ���� ���� �� �ʿ��� �����ڸ� �и��ؾ��ϳ�?
* ��� ����� �߾����ϴ�. �׷��� ó������ friend()�� �ƹ� �͵� �ȳ��� �����ڸ� �����, 
frien((const string& initName, int initAge, float initGpa, const string& initPhoneNumber)�� ����, �ΰ��� ��������ϴ�. �� �������� Ʋ���� �����µ�
���࿡�� ������ ����� ���� ����, ������ ��� �ǰ��ִ��� �����غ��� �������� �������ֽ� ���� �����Ͽ� �����Ϸ��� friend��� ȣ���� �� ��,
�̰� �Ķ���Ͱ� ���� 1�� �Լ�����, �Ķ���Ͱ� �ִµ� ���� �Ķ���Ͱ� ���� ������ �Ѱ��� ������ �� ��� ������ �� �� �̾����ϴ�. �׷���
�ѹ��� �� ������ �ذ��ϰ� ���ʿ��ϰ� �Լ��� 2�� ������ �ʱ� ����, friend �����ڸ� ���� ��, ����Ʈ ���� ��� �������༭ ���� ���� �����ϸ�
�� ������ ������ set�Լ��� �̿��Ͽ� ���� �߰��ϰ�, ó���� ȣ���ϴ� ���� ����Ʈ ���� �־ �������� ����ǵ��� �ϳ��� �����ڷ� ������ �ذ��߽��ϴ�.
ó������ Ŭ������ ��� ����� ���� Ÿ��ó�� �̿��ϴ����� ���ذ� �ȵǾ���, �����ڰ� ���� ����ǰ� �� ������ ������ ��������, �̹� ������ ���ؼ�
�ڼ��� ������ �� �����ϴ�. Ư�� �����ڸ� ��� �����ؾ��ϴ����� ���� ���ص��� ���������ϴ�. �� ����Ѵٸ� ���� ������ �� ���� Ŭ������ ������
�� �� �Ϻ��� �����ؾ� �� ������ ��Ȳ������ ���� ���ϴ� ����� ������ �� ���� �� �����ϴ�. Ŭ���� �κ��� ���� ������ �ʿ伺�� �������ϴ�
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

    Friend(const string& initName = "", int initAge = 0, float initGpa = 0.0, const string& initPhoneNumber = "") {
        // �Ű������� ���� ������ ��� ������ �Ҵ��մϴ�.
        setName(initName);
        setAge(initAge);
        setGpa(initGpa);
        setPhoneNumber(initPhoneNumber);
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

// �����Լ� ����
int readAndSaveArray(Friend friends[], fstream& inFile); 
void printArray(Friend friends[], int n);

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











