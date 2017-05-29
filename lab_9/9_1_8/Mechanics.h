#include "Physics.h"
#include <string>
#pragma once
class Mechanics: public Physics
{
    public:
        Mechanics(string team,  string c = "3,14", int n = 80, string name = "Ahramenko"):
                Physics(n, name, c), teamProject_(team){}
       Mechanics(const Mechanics &temp):
                 Physics(temp.numberOfHours_, temp.nameOfProf_, temp.Constants_), teamProject_(temp.teamProject_){}
        ~Mechanics() {}

        void setProject(string n){teamProject_ = n;}
        string getProject(){return teamProject_;}

        virtual void Print(){cout<<"Subject takes "<<numberOfHours_<<" hours. Professor: "<<nameOfProf_<<endl;
        cout<<"Team project: "<<teamProject_<<endl;}



    private:
        string teamProject_;
};
