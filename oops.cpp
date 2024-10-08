#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Teacher{
private:
    double salary;

public:
    string name;
    string dept;
    string subject;

    // Non-parameterized
    Teacher(){
        this->dept="Computer Science";
    }

    // Parameterized
    Teacher(string name, string dept, string subject, double salary){
        this->name = name;
        this->dept = dept;
        this->subject = subject;
        this->salary = salary;
    }

    // Copy Constructor
    Teacher(Teacher &orgObj){ //pass by reference
        cout << "I am Custom Copy constructor" << endl;
        this->name = orgObj.name;
        this->dept = orgObj.dept;
        this->subject = orgObj.subject;
        this->salary = orgObj.salary;
    }

    long getSalary(){
        return this->salary;
    }

    void setSalary(long salary){
        this->salary = salary;
    }

    void getInfo(){
        cout<<"Name: "<<this->name<<endl;
        cout<<"Subject: "<<this->subject<<endl;
    }
};

// Example for Deep copy/Shallow copy and Destructor
class Student{
public:
    string name;
    double* cgpaPtr;

    Student(string name, double cgpa){
        this->name = name;
        this->cgpaPtr = new double;     // Allocate New memory
        *cgpaPtr = cgpa;
    }

    // Shallow Copy constructor
    // Student(Student &obj){
    //     this->name = obj.name;
    //     this->cgpaPtr = obj.cgpaPtr;    // Copies pointer (shallow copy)
    // }

    // Deep Copy Constructor
    Student(Student &obj){
        this->name = obj.name;
        // this->cgpaPtr = new double;         // Allocate New memory
        // *(this->cgpaPtr) = *obj.cgpaPtr;    // copy the value (deep copy)
        // Above can be done in single step
        this->cgpaPtr = new double(*obj.cgpaPtr);
    }

    void getInfo(){
        cout<<"Name: "<<this->name<<endl;
        cout<<"CGPA: "<<*(this->cgpaPtr)<<endl;
    }

    // Destructor
    ~Student(){
        delete cgpaPtr;     // Release the dynamically allocated memory
        cout << "Destructor: Memory released" << endl;
    }
};

int main(){
    Teacher t1("Rohan", "IT", "Java", 90000);
    t1.getInfo();

    Teacher t2(t1);
    t2.getInfo();

    Student s1("Rohan", 8.9);
    Student s2(s1);
    s1.getInfo();
    s2.getInfo();
    s2.name = "Sneha";
    *(s2.cgpaPtr) = 9.2;
    s1.getInfo();
    s2.getInfo();

    return 0;
}