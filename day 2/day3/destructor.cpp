#include<iostream>
using namespace std;

class Resource {
   private:
    int* data;
    int id;
    public:
    Resource(int i,int val): id(i){
        data = new int[100]; // Allocate some resource (e.g., an array)
        cout << "Resource " << id << " acquired(value: " << *data <<")"<< endl;
    }

    Resource() {
        delete data;
        cout<<"Resource " << id << " released" << endl;
    }

    void show() {
        cout << "Resource " << id << ";"<<*data<< endl;
    }
};

void function() {
    Resource local(2,200);
    local.show();

}

int main(){
    Resource r1(1,100);
    r1.show();

    function();

    Resource* r3=new Resource(3,300);
    r3->show();
    delete r3;

    cout<<"End of main()" << endl;
    return 0;

}