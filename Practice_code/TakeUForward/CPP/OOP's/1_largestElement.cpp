#include <iostream>
#include <string>
using namespace std;

class Student {
    private:
        string name;
        int rollNo;

    public:
        void setDetailes(string name, int rollNo) {
            this->name = name;
            this->rollNo = rollNo;
        }

        void displayDetailes() {
            cout << "Name: " << name << endl;
            cout << "Roll No: " << rollNo << endl;
        }
};

int main() {
    string name;
    int rollNo;

    // getline(cin, name);
    // cin >> rollNo;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter roll number: ";
    cin >> rollNo;

    cin.ignore();
    Student student;

    student.setDetailes(name, rollNo);
    student.displayDetailes();
}