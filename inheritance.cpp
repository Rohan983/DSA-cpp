#include <iostream>
#include <string>
using namespace std;

class Person{
public:
    string name;
    int age;

    Person(){
        cout << "Parent Constructor" << endl;
    }

    Person(string name, int age){
        this->name = name;
        this->age = age;
    }

    ~Person(){
        cout << "Parent Destructor...\n";
    }
};

class Student : public Person {
public:
    int rollno;

    Student(){
        cout << "Child Constructor" << endl;
    }

    Student(string name, int age, int rollno) : Person(name, age){
        this->rollno = rollno;
    }

    void getInfo(){
        cout << "Name: " << this->name << endl;
        cout << "Age: " << this->age << endl;
        cout << "Roll No.: " << this->rollno << endl;
    }

    ~Student(){
        cout << "Child Destructor...\n";
    }
};

int main(){
    Student s1;
    s1.name = "Rohan";
    s1.age = 24;
    s1.rollno = 45;
    s1.getInfo();

    Student s2("Mohan", 23, 39);
    s2.getInfo();

    return 0;
}