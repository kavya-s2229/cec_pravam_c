#include<iostream>
#include<string>
using namespace std;
class employee{
    private:
    int id;
    string name;
    double salary;
    string department;
    public:
    employee(int i,string n,double s,string d){
        id=i;
        setname(n);
        setsalary(s);
        department=d;
    }
    int getid()const{
        return id;
    }
    string getname()const{
        return name;
    }
    double getsalary()const{
        return salary;
    }
    string getdepartment()const{
        return department;
    }
    void setname(string n){
        if(n.length()>2){
            name=n;
        }
        else{
            cout <<"Name must be at least 2 characters long."<<endl;
            name="unknown";
        }
    }

    void setsalary(double s){
        if(s>0){
            salary=s;
        }
        else{
            cout <<"Salary must be positive."<<endl;
            salary=0;
        }
    }
    void setdepartment( const string& d){
        department=d;
    }
    void giverise(double percentage){
        if(percentage>0){
            salary+=salary*percentage/100;
            cout <<name<<"received a "<<percentage<<"% raise.new salary: $"<<salary<<endl;
        }
    }

    void display() const {
        cout << "ID: "<< id <<"|"<<name<<"|$"<<salary<<"|"<<department<<endl;
    }
};

int main(){
    employee emp(101,"kavya.s",50000,"Engineering");
    emp.display();

    emp.giverise(10);
    emp.setsalary(-100);

    cout << "\nFinal details:"<<endl;
    cout << "Name:"<<emp.getname()<<endl;
    cout << "Salary:"<<emp.getsalary()<<endl;
     return 0;

}