#include <vector>
#include <iostream>
#include <cmath>

#define NUMBER_OF_BITS 64

using namespace std;

class CxBitBinaryNumber
{
 public:

  void printNumber()
  {
    cout << "\n";
    for (int i = NUMBER_OF_BITS - 1; i >= 0; i--) {
      cout << " " << bitsNumber_[i];
      if (i % 8 == 0)
        cout << "\n";
    }
  }

  char& operator [] (int i)
  {
    if (i < 0)	{
      cout << " index is too small\n";
      return bitsNumber_[NUMBER_OF_BITS - 1];
    } else if (i >= NUMBER_OF_BITS) {
      cout << " index is too high\n";
      return bitsNumber_[0];
    }
    return bitsNumber_[i];
  }


  void makesZerosAndOnes(vector <char> &bitNumber)
  {
    for (int i = 0; i < NUMBER_OF_BITS; i++)
      while (bitNumber[i] > '1') {
        bitNumber[i + 1] += 1;
        bitNumber[i] -= 2;
      }
  }

  bool operator > (CxBitBinaryNumber &second){

    return isMore(bitsNumber_, second.bitsNumber_);
}

bool operator < (CxBitBinaryNumber &second){

    return isMore(second.bitsNumber_, bitsNumber_);
}

bool operator == (CxBitBinaryNumber &second){

    return isEqual(bitsNumber_, second.bitsNumber_);
}

bool operator != (CxBitBinaryNumber &second){

    return isEqual(bitsNumber_, second.bitsNumber_) ? false : true;
}

bool operator >= (CxBitBinaryNumber &second){

    if(isMore(bitsNumber_, second.bitsNumber_) == true || isEqual(bitsNumber_, second.bitsNumber_ )== true) return true;

    else return false;
}

bool operator <= (CxBitBinaryNumber &second){

    if(isMore(second.bitsNumber_, bitsNumber_) == true || isEqual(bitsNumber_, second.bitsNumber_) == true) return true;

    else return false;
}

CxBitBinaryNumber operator >> (int n){

    CxBitBinaryNumber res(0);
    res.bitsNumber_[NUMBER_OF_BITS-1] = '0';

    for(int i = 0; i < n; i++){
    for(int l = 1; l < NUMBER_OF_BITS; l++){

        res.bitsNumber_[l-1] = bitsNumber_[l];
    }
    }

    return res;

}
CxBitBinaryNumber operator << (int n){

    CxBitBinaryNumber res(0);
    res.bitsNumber_[0] = '0';

    for(int i = 0; i < n; i++){
    for(int l = 1; l < NUMBER_OF_BITS; l++){

        res.bitsNumber_[l] = bitsNumber_[l-1];
    }
    }

    return res;
}

bool isMore(vector <char> &first, vector <char> &second)
{
    for(int i = NUMBER_OF_BITS-1; i >= 0; i--){

        if(first[i] == second[i]) continue;
        else if (first[i] > second[i]) return true;
        else return false;
    }

}

bool isEqual(vector <char> &first, vector <char> &second)
{
    bool isEq = true;

    for(int i = NUMBER_OF_BITS-1; i >= 0; i--){

        if(first[i] != second[i]) {

            isEq = false;
            break;
        }
    }

    return isEq;
}


 public:
  CxBitBinaryNumber()
    {
      for (int i = 0; i < NUMBER_OF_BITS; i++)
        bitsNumber_.push_back('0');
    }

  CxBitBinaryNumber(int n)
    {
      if (n >= 0) {
        for (int i = NUMBER_OF_BITS - 1; i >= 0; i--) {
          if (n % 2 == 0)
            bitsNumber_.push_back('0');
          else
            bitsNumber_.push_back('1');
          n /= 2;
        }
      }
    }

  CxBitBinaryNumber(const CxBitBinaryNumber &n)
    {
      for (int i = 0; i < NUMBER_OF_BITS; i++)
        bitsNumber_.push_back(n.bitsNumber_[i]);
    }

  ~CxBitBinaryNumber()
    {
      /*cout << " destructor done\n";*/
    }


 private:
  vector <char> bitsNumber_;
};




