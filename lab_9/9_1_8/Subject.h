#include <iostream>
#include <string>

#pragma once

using namespace std;
class Subject

{
    public:

        Subject(int n = 0, string st1 ="0"): numberOfHours_(n), nameOfProf_(st1){}
        Subject(Subject &sub): numberOfHours_(sub.numberOfHours_), nameOfProf_(sub.nameOfProf_) {}
        ~Subject() {}

        void setNumberOfHours(int n){numberOfHours_ = n;}
        int getNumberOfHours(){return numberOfHours_;}

        void setNameOfProf(string st1){nameOfProf_ = st1;}
        string getNameOfProf(){return nameOfProf_;}

        virtual void Print(){cout<<"Subject takes "<<numberOfHours_<<" hours. Professor: "<<nameOfProf_<<endl;}

    protected:
        int numberOfHours_;
        string nameOfProf_;
};
