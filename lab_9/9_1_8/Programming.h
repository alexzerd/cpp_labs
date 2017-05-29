#include "Subject.h"
#include <string>
#pragma once

class Programming: public Subject
{
    public:
        Programming(int n = 120, string name = "Vorotnitsky", int nL = 60, string lang = "C++"):
                Subject(n, name), numOfLab_(nL), Language_(lang){}
        Programming(const Programming &temp):
                Subject(temp.numberOfHours_, temp.nameOfProf_), numOfLab_(temp.numOfLab_), Language_(temp.Language_){}
        ~Programming() {}

        void setNumOfLab(int n){numOfLab_ = n;}
        int getNumOfLab(){return numOfLab_;}
        void setLanguage(string str){Language_ = str;}
        string getLanguage(){return Language_;}

        virtual void Print(){cout<<"Subject takes "<<numOfLab_<<" labs. Professor: "<<nameOfProf_<<endl;
        cout<<"Language: "<<Language_<<"BHJB "<<numberOfHours_<<endl;}


    protected:
        int numOfLab_;
        string Language_;
};
