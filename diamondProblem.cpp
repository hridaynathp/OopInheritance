/*
    Diamond Shape problem: Resolved through virtual keyword
*/
#include <iostream>

using namespace std;

// Base class
class Person{
    public:
        Person(){cout<<"Default Person() called!!"<<endl;}
        Person(int x){cout<<"Parameterized Person(int) called!!"<<endl;}
};
// Faculty class inheriting Person Virually
class Faculty:public virtual Person{
    public:
        Faculty():Person(){cout<<"Default Faculty() called!!"<<endl;}
        Faculty(int x):Person(x){cout<<"Parameterized Faculty(int) called!!"<<endl;}
};
// Student class inheriting Person Virually
class Student:public virtual Person{
    public:
        Student():Person(){cout<<"Default Student() called!!"<<endl;}
        Student(int x):Person(x){cout<<"Parameterized Student(int) called!!"<<endl;}
};
// Student class inheriting Person Virually
class Subject:public Faculty, public Student{
    public:
        Subject():Student(), Faculty(){cout<<"Default Subject() called!!"<<endl;}
        Subject(int x):Student(x), Faculty(x){cout<<"Parameterized Subject(int) called!!"<<endl;}
};

int main()
{
    cout << "Hello world!" << endl;


//  Will call all default constructors without duplication
//  Subject s1; 

/*  Will call all Parameterized constructors without duplication
    Point to Note: Default constructor of Base class Person is being called
    and not parameterized even we have called it explicitly */
    Subject s1(30);


    return 0;
}
