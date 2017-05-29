#include "Subject.h"
#include <iostream>
#include <string>
#include <map>
#pragma once

using namespace std;

class Physics: public Subject
{
    public:
        Physics(int n = 80, string name = "Daneyko", string c = "2,73"):
                Subject(n, name), Constants_(c){}
        Physics(const Physics &temp):
                Subject(temp.numberOfHours_, temp.nameOfProf_), Constants_(temp.Constants_){}
        ~Physics() {}

        void setConstants(string st1){Constants_ = st1;}
        string getConstants(){return Constants_;}

        virtual void Print(){cout<<"Subject takes "<<numberOfHours_<<" hours. Professor: "<<nameOfProf_<<endl;
        cout<<"Const: "<<Constants_[0]<<endl;}

    protected:
        string Constants_;
};
