#include "CTime.h"
#include <iostream>
#include <iomanip>

using namespace std;

CTime::CTime()
{
    seconds = 0;
    minutes = 0;
    hours = 0;
}

CTime::CTime(int n_h, int n_m, int n_s){

    int plusMin = 0, plusH = 0;

    if(n_s > 60){

        cout<<"Wrong number of seconds!"<<endl;
        seconds = 0;
    }
    else if(n_s == 60) {plusMin++; seconds = 0;}
    else seconds = n_s;

    if(n_m > 60){

        cout<<"Wrong number of minutes!"<<endl;
        minutes = 0;
    }
    else if(n_m == 60) {plusH++; minutes = 0;}
    else minutes = n_m;

    if(n_h > 24){

        cout<<"Wrong number of hours!"<<endl;
        hours = 0;
    }
    else if (n_h == 24) hours = 0;
    else hours = n_h;

    for(int i = 0; i < plusMin; i++){
        minutes++;
        if(minutes == 60) {minutes = 0; plusH++;}
    }

    for(int i = 0; i < plusH; i++){
        hours++;
        if(hours == 24) {hours = 0;}
    }
}

CTime::CTime(const CTime &n){

    seconds = n.seconds;
    minutes = n.minutes;
    hours = n.hours;
}

CTime::~CTime(){
    cout<<endl<<endl;
   // cout<<"destructor done"<<endl;
}



void CTime::PrintTime(){

    cout<<setw(2)<<hours<<"."<<setw(2)<<minutes<<"."<<setw(2)<<seconds<<endl;
}

CTime CTime::operator + (int n){


    seconds += n;
    if(seconds == 60) {minutes++; seconds = 0;}
    else if(seconds > 60) { minutes += seconds/60; seconds -= 60*(seconds/60);}


    if(minutes == 60) {hours++; minutes = 0;}
    else if(minutes > 60) { hours += minutes/60; minutes -= 60*(minutes/60);}


    if(hours == 24)   {hours = 0;}
    else if(hours > 24) {hours -= 24*(hours/24);}

    return *this;

}

CTime CTime::operator + (CTime &n){

    seconds += n.seconds;
    if(seconds == 60) {minutes++; seconds = 0;}
    else if(seconds > 60) { minutes += seconds/60; seconds -= 60;}

    minutes += n.minutes;
    if(minutes == 60) {hours++; minutes = 0;}
    else if(minutes > 60) { hours += minutes/60; minutes -= 60;}

    hours += n.hours;
    if(hours == 24)   {hours = 0;}
    else if(hours > 24) {hours -= 24;}

    return *this;

}

CTime CTime::operator - (int n){

    int r = n/3600, c = 0;


    hours -= n/3600;
    if(hours < 0) cout<<"Impossible to subtract!"<<endl;
    else{
        c = (n-3600*r);
        minutes -= c/60;
        if(minutes < 0) {while(minutes < 0 && hours > 0){hours--; minutes += 60;}}

        seconds -=(c-(c/60)*60);

        if(seconds < 0) {while(seconds < 0 && minutes > 0){minutes--; seconds += 60; if(minutes < 0) {while(minutes < 0 && hours > 0){hours--; minutes += 60;}}}}

    }

    return *this;
}

CTime CTime::operator - (CTime &n){

  hours -= n.hours;
    if(hours < 0) cout<<"Impossible to subtract!"<<endl;
    else{
        minutes -= n.minutes;
        if(minutes < 0) {while(minutes < 0 && hours > 0){hours--; minutes += 60;}}

        seconds -= n.seconds;
        if(seconds < 0) {while(seconds < 0 && minutes > 0){minutes--; seconds += 60; if(minutes < 0) {while(minutes < 0 && hours > 0){hours--; minutes += 60;}}}}

    }

    return *this;

}



int CTime::howSeconds(CTime &n){

     hours -= n.hours;
    if(hours < 0) cout<<"Impossible to subtract!"<<endl;
    else{
        minutes -= n.minutes;
        if(minutes < 0) {while(minutes < 0 && hours > 0){hours--; minutes += 60;}}

        seconds -= n.seconds;
        if(seconds < 0) {while(seconds < 0 && minutes > 0){minutes--; seconds += 60; if(minutes < 0) {while(minutes < 0 && hours > 0){hours--; minutes += 60;}}}}

    }

    int v = ((hours*3600)+(minutes*60)+seconds);

    return v;
}
