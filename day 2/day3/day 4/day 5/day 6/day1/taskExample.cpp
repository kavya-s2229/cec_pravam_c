#include <iostream>
using namespace std;

// Create class
class Superhero {
public:
    string name;
    string power;
    int powerLevel;

    // Method to use power
    void usePower() {
        cout << name << " uses " << power << "!" << endl;
    }

    // Method to train
    void train() {
        powerLevel = powerLevel + 10;
        cout << name << " trained! Power is now "
             << powerLevel << "." << endl;
    }
};

int main() {

    // First superhero
    Superhero hero1;
    hero1.name = "Thunder Boy";
    hero1.power = "Lightning Strike";
    hero1.powerLevel = 50;

    // Second superhero
    Superhero hero2;
    hero2.name = "Shadow Girl";
    hero2.power = "Invisible Attack";
    hero2.powerLevel = 60;

    // Use powers
    hero1.usePower();
    hero2.usePower();

    // Train
    hero1.train();
    hero2.train();

    return 0;
}