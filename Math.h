#include <iostream>
#include <string>
#include <vector>
#include "Subject.h"
#include <iostream>
#pragma once

using namespace std;


class Math: public Subject
{
    public:
        Math(string c, int n = 80, string name = "Ahramenko"):
                Subject(n, name), formulas_(c){}
        Math(const Math &temp):
                Subject(temp.numberOfHours_, temp.nameOfProf_), formulas_(temp.formulas_){}
        ~Math() {}

        void setFormulas(char n){formulas_ = n;}
        string getFormulas(){return formulas_;}

        virtual void Print(){cout<<"Subject takes "<<numberOfHours_<<" hours. Professor: "<<nameOfProf_<<endl;
        cout<<"Formula: "<<formulas_<<endl;}


    protected:
        string formulas_;

};
