#include <iostream>
#include <string>
using namespace std;

class Animal {
    protected:
       string name;
       int age;
    public:
         Animal(string n, int a) : name(n), age(a) {}
         
         void eat() {
             cout << name << " is eating." << endl;
         }

         void sleep() {
             cout << name << " is sleeping." << endl;
         }
};

class Dog : public Animal {
    private:
        string breed;
    public:
        Dog(string n, int a, string b) : Animal(n, a), breed(b) {}

        void bark() {
            cout << name << "(the "<< breed << ") is barking!" << endl;
        }
        void display() {
            cout <<"Dog:" << name << ", Age: " << age << ", Breed: " << breed << endl;
        }
};
int main() {
    Dog myDog("Buddy", 3, "Golden Retriever");
    myDog.display();
    myDog.eat();
    myDog.sleep();
    myDog.bark();

    return 0;
}
