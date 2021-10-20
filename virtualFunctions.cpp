/*
    Virtual Function: usefull to call correct version of functions
    Mechanism: Hidden pointer *_vptr is being set by compiler in base class,
    which gets inherited in child classes too.
    the *_vptr points to thier own class and point to most derived virtual function,
    which is useful to call correct version of function
*/

#include <iostream>

using namespace std;

class Animal{
    string type;
    int count;
    public:
        Animal():type("None"), count(0){
            cout<<"Animal Default..."<<endl;
        }

        virtual void speak(){
            cout<<"Sounds like an animal...!"<<endl;
        }
        int population(){
            cout<<"returning count"<<count<<endl;
            return count;
        }
};

class Cat: public Animal{
    string name;
    public:
        Cat():name("Not decided"){
            cout<<"Cat default..."<<endl;
        }

        Cat(string name):name(name){
            cout<<"Parameterized constructor..."<<endl;
        }

        virtual void speak(){
            cout<<"meouw, my name is "<<name<<endl;
        }
        void walk(){
            cout<<"walking...!"<<endl;
        }
};
int main()
{
    cout << "Hello world!" << endl;
    Cat c;
    c.speak();
    c.population();

    /* Even type of pointer is Animal (base) class
       Correct version of Speak that is Cat is called(Derived class)
       The most derived class is being used to call if we use pointer to base class*/
       
    Animal *pAnml;
    pAnml = &c;
    pAnml->speak();

    return 0;
}
