#include "Math.h"
#include <string>
#pragma once
class LinearAlgebra: public Math
{
    public:
        LinearAlgebra(string c, string exam,int n = 80, string name = "Ahramenko"):
                Math(c, n, name), exDesc_(exam){}
        LinearAlgebra(const LinearAlgebra &temp):
                 Math(temp.formulas_, temp.numberOfHours_,temp.nameOfProf_), exDesc_(temp.exDesc_){}
        ~LinearAlgebra() {}

        void setExam(string n){exDesc_ = n;}
        string getExam(){return exDesc_;}

        virtual void Print(){cout<<"Subject takes "<<numberOfHours_<<" hours. Professor: "<<nameOfProf_<<endl;
        cout<<"Exam description: "<<exDesc_<<endl;}



    private:
        string exDesc_;
};
