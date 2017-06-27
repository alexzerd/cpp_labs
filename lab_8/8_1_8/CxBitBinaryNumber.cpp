#include "CxBitBinaryNumber.h"
#include <iostream>

using namespace std;

// Public:
CxBitBinaryNumber::CxBitBinaryNumber()
{
  for (int i = 0; i < NUMBER_OF_BITS; i++)
    bitsNumber_[i] = '0';

  for(int i = 0;  i < NUMBER_OF_BITS; i++){

    cout<<bitsNumber_[i]<<" ";
  }
}

CxBitBinaryNumber::CxBitBinaryNumber(int n)
{

 if (n >= 0) {
    for (int i = NUMBER_OF_BITS - 1; i >= 0; i--) {
      if (n % 2 == 0)
        bitsNumber_[i] = '0';
      else
        bitsNumber_[i] = '1';
      n /= 2;
    }
  } else {
    bitsNumber_[0] = '1';
    for (int i = NUMBER_OF_BITS - 1; i > 0; i--) {
      if (n % 2 == 0)
        bitsNumber_[i] = '1';
      else
        bitsNumber_[i] = '0';
      n /= 2;
    }
    bitsNumber_[NUMBER_OF_BITS - 1]++;
    makesZerosAndOnes(bitsNumber_);
}
}

CxBitBinaryNumber::CxBitBinaryNumber(const CxBitBinaryNumber &n)
{
  for (int i = 0; i < NUMBER_OF_BITS; i++)
    bitsNumber_[i] = n.bitsNumber_[i];
}

CxBitBinaryNumber::~CxBitBinaryNumber()
{
  // cout << " destructor done\n";
}

// Public:

bool CxBitBinaryNumber::isMore(CxBitBinaryNumber &first, CxBitBinaryNumber &second)
{
    for(int i = NUMBER_OF_BITS-1; i >= 0; i--){

        if(first.bitsNumber_[i] == second.bitsNumber_[i]) continue;
        else if (first.bitsNumber_[i] > second.bitsNumber_[i]) return true;
        else return false;
    }

}

bool CxBitBinaryNumber::isEqual(CxBitBinaryNumber &first, CxBitBinaryNumber &second)
{
    bool isEq = true;

    for(int i = NUMBER_OF_BITS-1; i >= 0; i--){

        if(first.bitsNumber_[i] != second.bitsNumber_[i]) {

            isEq = false;
            break;
        }
    }

    return isEq;
}


char CxBitBinaryNumber::operator [] (const int i)
{
  if (i < 0) {
    cout << " index is too small\n";
    return bitsNumber_[NUMBER_OF_BITS - 1];
  } else if (i >= NUMBER_OF_BITS) {
    cout << " index is too high\n";
    return bitsNumber_[0];
  }
  return bitsNumber_[i];
}


void CxBitBinaryNumber::printNumber()
{
  cout << "\n";
  for (int i = 0; i < NUMBER_OF_BITS; i++) {
    cout << " " << bitsNumber_[i];
    if (i % 8 == 7)
      cout << "\n";
  }
}


bool CxBitBinaryNumber::operator > (CxBitBinaryNumber &second){

    return isMore(*this, second);
}

bool CxBitBinaryNumber::operator < (CxBitBinaryNumber &second){

    return isMore(second, *this);
}

bool CxBitBinaryNumber::operator == (CxBitBinaryNumber &second){

    return isEqual(*this, second);
}

bool CxBitBinaryNumber::operator != (CxBitBinaryNumber &second){

    return isEqual(*this, second);
}

bool operator >= (CxBitBinaryNumber &first, CxBitBinaryNumber &second){

    bool isEq = true, mor = true;

    for(int i = NUMBER_OF_BITS-1; i >= 0; i--){

        if(first.bitsNumber_[i] != second.bitsNumber_[i]) {

            isEq = false;
            break;
        }
    }

     for(int i = NUMBER_OF_BITS-1; i >= 0; i--){

        if(first.bitsNumber_[i] == second.bitsNumber_[i]) continue;
        else if (first.bitsNumber_[i] > second.bitsNumber_[i]) mor = true;
        else mor = false;
    }

    if(isEq || mor) return true;
    else return false;

}

bool CxBitBinaryNumber::operator <= (CxBitBinaryNumber &second){

    if(isMore(second, *this) == true || isEqual(*this, second) == true) return true;

    else return false;
}

CxBitBinaryNumber CxBitBinaryNumber::operator >> (int n){


    char prom, c;

    prom = bitsNumber_[0];
    bitsNumber_[0] = '0';

    int i = 1;

    for(int l = 0; l < NUMBER_OF_BITS-n; l++){

        c = bitsNumber_[i];
        bitsNumber_[i] = prom;
        prom = c;

        i++;

    }


}

CxBitBinaryNumber CxBitBinaryNumber::operator << (int n){

    CxBitBinaryNumber result;

    int i = NUMBER_OF_BITS-2;
    char prom, c;

    prom = bitsNumber_[NUMBER_OF_BITS-1];
    bitsNumber_[NUMBER_OF_BITS-1] = '0';

    for(int l = 0; l <= n ; l++){

        c = bitsNumber_[i];
        bitsNumber_[i] = prom;
        prom = c;

        i--;

    }

}



void CxBitBinaryNumber::makesZerosAndOnes(char* bitNumber)
{
  for (int i = NUMBER_OF_BITS - 1; i >= 0; i--)
    while (bitNumber[i] > '1') {
      bitNumber[i - 1] += 1;
      bitNumber[i] -= 2;
    }
}



















