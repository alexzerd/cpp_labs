
class CTime
{
    public:

        CTime();
        CTime(int, int, int);
        CTime(const CTime &);
        ~CTime();


        void SetTime(int, int, int);
        void PrintTime();

        CTime operator + (int);
        CTime operator + (CTime &);
        CTime operator - (int);
        CTime operator - (CTime &);
        int howSeconds(CTime &);

        //CTime checkTime(Ctime &);




    private:

        int seconds, minutes, hours;


};
