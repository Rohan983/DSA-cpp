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

// Single Inheritance
class Student : public Person {
public:
    int rollno;

    Student(){
        cout << "Child Constructor" << endl;
    }

    Student(string name, int age, int rollno) : Person(name,  age){
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

// Multi-Level Inheritance (Inherits student class which inherits person class)
class GradStud : public Student {
public:
    int graduationYear;

    GradStud(){
        cout << "GradStud Constructor" << endl;
    }

    GradStud(string name, int age, int rollno, int graduationYear) : Student(name,  age, rollno){
        this->graduationYear = graduationYear;
    }

    void getInfo(){
        cout << "Name: " << this->name << endl;
        cout << "Roll No.: " << this->rollno << endl;
        cout << "graduationYear: " << this->graduationYear << endl;
    }

    ~GradStud(){
        cout << "GradStud Destructor...\n";
    }
};

// Hierarchical Inheritance (As student class also inherits Person)
class Teacher : public Person{
public:
    string subject;

    Teacher(){
        cout<< "Teacher constructor" << endl;
    }

    Teacher(string name, int age, string subject) : Person(name, age){
        this->subject = subject; 
    }

    Teacher(string subject){
        this->subject = subject; 
    }

    void getInfo(){
        cout << "Name: " << this->name << endl;
        cout << "Age: " << this->age << endl;
        cout << "Subject: " << this->subject << endl;
    }

    ~Teacher(){
        cout << "Teacher Destructor...\n";
    }
};

// Multiple Inheritance
class TeacherAssistant: public Student, public Teacher{
public:
    TeacherAssistant(){
        cout<< "TeacherAssistant constructor" << endl;
    }

    TeacherAssistant(string name, int age, int rollno, string subject) : Student(name, age, rollno), Teacher(subject){
        cout<< "Parameterized TeacherAssistant constructor" << endl;
    }

    void getInfo(){
        // To resolve ambiguity issue explicitly specifying 
        // which base class' member variable i am refering to.
        cout << "Name: " << this->Student::name << endl;
        cout << "Age: " << this->Student::age << endl;
        cout << "Roll No.: " << this->rollno << endl;
        cout << "Subject: " << this->subject << endl;
    }
};

int main(){
    // Student s1;
    // s1.name = "Rohan";
    // s1.age = 24;
    // s1.rollno = 45;
    // s1.getInfo();

    // Student s2("Mohan", 23, 39);
    // s2.getInfo();

    // GradStud g1("Mohan", 23, 39, 2022);
    // g1.getInfo();

    // Teacher t1("Rohan", 29, "Machine Learning");
    // t1.getInfo();

    TeacherAssistant ta1("Rohan", 24, 56, "Machine Learning");
    ta1.getInfo();
    return 0;
}