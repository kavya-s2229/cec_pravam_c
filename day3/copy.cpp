#include <iostream>
#include <cstring>   // for strlen, strcpy
using namespace std;

class Student {
public:
    char* name;
    int age;

    // Constructor
    Student(const char* n, int a) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        age = a;
    }

    // Copy Constructor
    Student(const Student& s) {
        age = s.age;
        name = new char[strlen(s.name) + 1];
        strcpy(name, s.name);
        cout << "copy constructor called!" << endl;
    }

    // Destructor
    ~Student() {
        delete[] name;
    }

    // Display function
    void display() {
        cout << name << " (" << age << ")" << endl;
    }
};

int main() {
    Student s1("Alice", 20);
    Student s2 = s1;  // invokes copy constructor

    s1.display();
    s2.display();

    s2.name[0] = 'P';  // modifies s2 only
    cout << "\nAfter modification:" << endl;
    s1.display();
    s2.display();

    return 0;
}
