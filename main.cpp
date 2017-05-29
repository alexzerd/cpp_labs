#include <iostream>
#include "Subject.h"
#include "Programming.h"
#include "Math.h"
#include "Physics.h"
#include "LinearAlgebra.h"
#include "Mechanics.h"
#include "Analysis.h"
#include <string>

using namespace std;

Subject doubleHours (Subject &a){

    int b = a.getNumberOfHours();
    b*=2;
    a.setNumberOfHours(b);
    a.Print();
    return a;
}

int main()
{
    string s1 = "Martinets", s2 = "S = pi*r^2";

    Subject a1(40, s1);
    a1.Print();

    cout<<endl;

    Programming a2;
    a2.Print();

    cout<<endl;

    Analysis a3(s2);
    a3.Print();

    cout<<endl;

    Subject a4;
    a4 = doubleHours(a2);

   // a4.Print();

    return 0;
}
