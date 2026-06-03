#include<iostream>
#include<string>
using namespace std;

template<typename T>
class Pair {
private:
    T first;
    T second;
public:
    Pair(T f, T s) : first(f), second(s) {}

    T getFirst() const { return first; }
    T getSecond() const { return second; }

    T getMax() const { return (first > second) ? first : second;}

    void display() const {
        cout << "(" << first << ", " << second << ")" << endl;
    }
};

template<typename T, typename U>
class keyValue {
private:
    T key;
    U value;
public:
    keyValue(T k, U v) : key(k), value(v) {}

    void display() const {
        cout << "[" << key << "] => " << value << endl;
    }
};
int main() {
    Pair<int> p1(10, 20);
    Pair<double> p2(3.14, 2.71);
    Pair<string> p3("Apple", "Mango");

    cout <<"int Pair: "; p1.display();
    cout<< "Min: " << p1.getMax() << endl;   

    cout <<"double Pair: ";p2.display();
    cout << "Min: " << p2.getMax() << endl;

    cout <<"string Pair: ";p3.display();
    cout << "Min: " << p3.getMax() << endl;

    keyValue<int, string> kv(101,"kumuu");
    keyValue<string, double> kv2("pi", 3.14159);

    cout<< "\nkey-Value Pairs:" << endl;
    kv.display();  
    kv2.display();

    return 0;

}

