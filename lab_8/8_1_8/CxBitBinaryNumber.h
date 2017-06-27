#define NUMBER_OF_BITS 64

class CxBitBinaryNumber
{
 public:

  char operator [] (const int);

  //CxBitBinaryNumber decToBin(int n);

  CxBitBinaryNumber();
  CxBitBinaryNumber(int);
  CxBitBinaryNumber(const CxBitBinaryNumber &);
  ~CxBitBinaryNumber();

  bool isMore(CxBitBinaryNumber &, CxBitBinaryNumber &);
  bool isEqual(CxBitBinaryNumber &, CxBitBinaryNumber &);
  void makesZerosAndOnes(char* );
  void printNumber();


  CxBitBinaryNumber operator >> (int);
  CxBitBinaryNumber operator << (int);
  bool operator > (CxBitBinaryNumber &);
  bool operator < (CxBitBinaryNumber &);
  bool operator == (CxBitBinaryNumber &);
  bool operator != (CxBitBinaryNumber &);
  bool operator <= (CxBitBinaryNumber &);
  friend bool operator >= (CxBitBinaryNumber &, CxBitBinaryNumber &);


 private:
  char bitsNumber_[NUMBER_OF_BITS];


};
