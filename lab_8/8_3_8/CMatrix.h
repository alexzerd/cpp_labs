#include <string>

class CMatrix
{
 public:
  void operator = (const CMatrix &);
  CMatrix operator + (const CMatrix &);
  CMatrix operator + (float n);
  void operator += (const CMatrix &);
  void operator += (float n);
  CMatrix operator - (const CMatrix &);
  CMatrix operator - (float n);
  void operator -= (const CMatrix &);
  void operator -= (float n);
  CMatrix operator * (const CMatrix &);
  CMatrix operator * (float n);
  void operator *= (const CMatrix &);
  void operator *= (float n);
  //CMatrix operator / (const CMatrix &);
  CMatrix operator / (float n);
  // void operator /= (const CMatrix &);
  void operator /= (float n);
  CMatrix pow (int n);// n >= 1 îáðàòíàÿ ñ÷èòàåòñÿ ïî äðóãîìó
  // CMatrix operator ÒÐÀÍÑÏÎÍÈÐÎÂÀÍÈÅ ();
  bool operator == (const CMatrix &);
  bool operator > (const CMatrix &);
  bool operator < (const CMatrix &);
  bool operator >= (const CMatrix &);
  bool operator <= (const CMatrix &);
  // int operator [][] (int i, int j);
  void printMatrix();
  void printMatrix(int, int);
  void createVector(float *vector);

 private:
  void memoryAssignment(int &, int &, const int &, const int &, float** &);
  void erase(float** &, int, int);
  void summation(float**, float**, int, int);
  void summation(float**, float, int, int);
  void subtraction(float**, float**, int, int);
  void multiplication(float**, float**, float**, int, int);
  void multiplication(float**, float, int, int);
  void printAll();

 public:
  CMatrix(int, int);
  CMatrix(int, int, int);
  CMatrix(int, int, float*);
  CMatrix(const CMatrix &);
  ~CMatrix();

 private:
  int i_;
  int j_;
  float** matrix_;
  static int counter_;
  int number_;
};

