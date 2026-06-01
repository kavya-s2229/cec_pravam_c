#include <iostream>
#include <string>
using namespace std;

class person {
protected:
    string name;
    int age;

public:
    person(string n, int a) : name(n), age(a) {}

    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class student : virtual public person {
protected:
    int rollno;

public:
    student(string n, int a, int r)
        : person(n, a), rollno(r) {}

    void display() {
        person::display();
        cout << "Roll No: " << rollno << endl;
    }
};

class Graduatestudent : public student {
private:
    string thesisTopic;

public:
    Graduatestudent(string n, int a, int r, string t)
        : person(n, a), student(n, a, r), thesisTopic(t) {}

    void display() {
        student::display();
        cout << "Thesis: " << thesisTopic << endl;
    }
};

class Teacher : virtual public person {
private:
    double salary;

public:
    Teacher(string n, int a, double s)
        : person(n, a), salary(s) {}

    void display() {
        person::display();
        cout << "Salary: $" << salary << endl;
    }
};

class TeachingAssistant : public student, public Teacher {
public:
    TeachingAssistant(string n, int a, int r, double s)
        : person(n, a), student(n, a, r), Teacher(n, a, s) {}

    void display() {
        cout << "Teaching Assistant" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll No: " << rollno << endl;
    }
};

int main() {
    cout << "=== Single Inheritance ===" << endl;
    student s1("Alice", 20, 101);
    s1.display();

    cout << "\n=== Multilevel Inheritance ===" << endl;
    Graduatestudent gs("Bob", 25, 102, "AI Research");
    gs.display();

    cout << "\n=== Hierarchical Inheritance ===" << endl;
    Teacher t1("Charlie", 35, 50000);
    t1.display();

    cout << "\n=== Multiple Inheritance ===" << endl;
    TeachingAssistant ta("David", 28, 103, 30000);
    ta.display();

    return 0;
}