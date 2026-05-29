#include<iostream>
#include<string>
using namespace std;    

class shape {
    protected:
        string color;
public:
    shape(const string& c) : color(c) {}
    virtual double area() const = 0;
    virtual void draw() const = 0;
    string getColor() const { return color; }
    virtual ~shape() {}
};

class circle : public shape {
    private:
        double radius;
    public:
        circle(const string& c, double r) : shape(c), radius(r) {}      
        double area() const override {
            return 3.14159 * radius * radius;
        }
        void draw() const override {
            cout << "Drawing a " << color << " circle(area:"<<area()<<")"<<endl;

        }
    };
     int main() {
         shape* shapes[2];
            shapes[0] = new circle("red", 5.0);         
            shapes[1]=new Rectangle("blue",4.0,6.0);
            for (int i = 0; i < 2; ++i) {
                shapes[i]->draw();
            }

            for (int i = 0; i < 2; ++i) {
                delete shapes[i];
            }
            return 0;
     }