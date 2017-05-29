#include "Math.h"
#pragma once
class Analysis: public Math
{
    public:
        Analysis(string c, float exam = 0.6,int n = 80, string name = "Ahramenko"):
                Math(c, n, name), examPerc_(exam){}
        Analysis(const Analysis &temp):
                 Math(temp.formulas_), examPerc_(temp.examPerc_){}
        ~Analysis() {}

        void setExam(float n){examPerc_ = n;}
        float getExam(){return examPerc_;}

        virtual void Print(){cout<<"Subject takes "<<numberOfHours_<<" hours. Professor: "<<nameOfProf_<<endl;
        cout<<"Exam percentage: "<<examPerc_<<endl;}


    private:
        float examPerc_;
};
