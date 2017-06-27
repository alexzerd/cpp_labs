#include <vector>
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

using namespace std;

template <class T>
class CMatrix
{
 public:
  void operator = (const CMatrix &certainMat)
    {
      erase(matrix_, i_, j_);
      memoryAssignment(i_, j_, certainMat.i_, certainMat.j_, matrix_);

      for (int k = 0; k < i_; k++)
        for (int l = 0; l < j_; l++)
          matrix_[k][l] = certainMat.matrix_[k][l];
    }

  CMatrix operator + (const CMatrix &certainMat)
  {
    CMatrix result = certainMat;

    summation(result.matrix_, matrix_, i_, j_);

    return result;
  }

  CMatrix operator + (T number)
  {
    CMatrix result(i_, j_);
    summation(result.matrix_, matrix_, i_, j_);

    summation(result.matrix_, number, i_, j_);

    return result;
  }

  void operator += (const CMatrix &certainMat)
  {
    summation(matrix_, certainMat.matrix_, i_, j_);
  }

  void operator += (T number)
  {
    summation(matrix_, number, i_, j_);
  }

  CMatrix operator - (const CMatrix &certainMat)
  {
    CMatrix result(i_, j_);

    summation(result.matrix_, matrix_, i_, j_);
    subtraction(result.matrix_, certainMat.matrix_, i_, j_);

    return result;
  }

  CMatrix operator - (T number)
  {
    CMatrix result(i_, j_);
    summation(result.matrix_, matrix_, i_, j_);

    summation(result.matrix_, -number, i_, j_);

    return result;
  }

  void operator -= (const CMatrix &certainMat)
  {
    subtraction(matrix_, certainMat.matrix_, i_, j_);
  }

  void operator -= (T number)
  {
    summation(matrix_, -number, i_, j_);
  }

  CMatrix operator * (const CMatrix &certainMat)
    {
      CMatrix result(i_, certainMat.j_);

      multiplication(matrix_, certainMat.matrix_, result.matrix_, i_, certainMat.j_);

      return result;
    }

  CMatrix operator * (T number)
    {
      CMatrix result(i_, j_);
      summation(result.matrix_, matrix_, i_, j_);

      multiplication(result.matrix_, number, i_, j_);

      return result;
    }

  void operator *= (const CMatrix &certainMat)
  {
    CMatrix buff(i_, j_);
    for (int i = 0; i < i_; i++)
      for (int j = 0; j < j_; j++)
        buff.matrix_[i][j] = matrix_[i][j];

    erase(matrix_, i_, j_);
    j_ = certainMat.j_;
    memoryAssignment(i_, j_, i_, certainMat.j_, matrix_);

    multiplication(buff.matrix_, certainMat.matrix_, matrix_, i_, certainMat.j_);
  }

  void operator *= (T number)
  {
    multiplication(matrix_, number, i_, j_);
  }

  // CMatrix operator / (const CMatrix &);

  CMatrix operator / (T number)
  {
    CMatrix result(i_, j_);
    summation(result.matrix_, matrix_, i_, j_);

    multiplication(result.matrix_, 1/number, i_, j_);

    return result;
  }

  // void operator /= (const CMatrix &);

  void operator /= (T number)
  {
    multiplication(matrix_, 1/number, i_, j_);
  }

  CMatrix pow (int n)// n >= 1 обратная считается по другому
  {
    CMatrix result(i_, j_);
    for (int i = 0; i < i_; i++)
      for (int j = 0; j < j_; j++)
        result.matrix_[i][j] = matrix_[i][j];

    for (int k = 1; k < n; k++)
      {
        CMatrix intermed(i_, j_);
        for (int i = 0; i < i_; i++)
          for (int j = 0; j < j_; j++)
            intermed.matrix_[i][j] = result.matrix_[i][j];

        multiplication(matrix_, intermed.matrix_, result.matrix_, i_, j_);
      }

    return result;
  }

  // CMatrix operator ТРАНСПОНИРОВАНИЕ ();

  bool operator == (const CMatrix &certainMat)// TODO: нельзя сравнивать дробные числа "влоб"
  {
    for (int i = 0; i < i_; i++)
      for (int j = 0; j < j_; j++)
        if (matrix_[i][j] != certainMat.matrix_[i][j])
          return false;

    return true;
  }

  bool operator > (const CMatrix &certainMat)
  {
    for (int i = 0; i < i_; i++)
      for (int j = 0; j < j_; j++)
        if (matrix_[i][j] <= certainMat.matrix_[i][j])
          return false;

    return true;
  }

  bool operator < (const CMatrix &certainMat)
  {
    for (int i = 0; i < i_; i++)
      for (int j = 0; j < j_; j++)
        if (matrix_[i][j] >= certainMat.matrix_[i][j])
          return false;

    return true;
  }

  bool operator >= (const CMatrix &certainMat)
  {
    for (int i = 0; i < i_; i++)
      for (int j = 0; j < j_; j++)
        if (matrix_[i][j] < certainMat.matrix_[i][j])
          return false;

    return true;
  }

  bool operator <= (const CMatrix &certainMat)
  {
    for (int i = 0; i < i_; i++)
      for (int j = 0; j < j_; j++)
        if (matrix_[i][j] > certainMat.matrix_[i][j])
          return false;

    return true;
  }

  void printMatrix()
  {
    printMatrix(i_, j_);
  }

  void printMatrix(int i, int j)
  {
    for (int k = 0; k < i; k++)
      {
        for (int l = 0; l < j; l++)
          cout << " " << matrix_[k][l];
        cout << "\n";
      }
  }

  void createVector(T *vect)
  {
    for (int k = -i_ + 1, h = 0; h < 2 * i_ - 1; h++, k++)
      {
        float min = INT_MAX;
        for (int i = 0; i < i_; i++)
          for (int j = 0; j < i_; j++)
            if ((i == i_ - j - 1 + k) && (min > matrix_[i][j]))
              min = matrix_[i][j];
        vect[h] = min;
      }
  }


 private:
  void memoryAssignment(int &i_, int &j_, const int &i, const int &j, vector <T> * &matrix)
  {
    i_ = i;
    j_ = j;

    matrix = new vector <T> [i_];
    for (int k = 0; k < i_; k++)
      matrix[k].resize (j_, 0);
  }

  void erase(vector <T> * &matrix, int i, int j)
  {
    for (int k = 0; k < i; k++)
      matrix[k].clear();
    delete [] matrix;
  }

  void summation(vector <T> * matrixA, vector <T> * matrixB, int k, int l)
  {
    for (int i = 0; i < k; i++)
      for (int j = 0; j < l; j++)
        matrixA[i][j] += matrixB[i][j];
  }

  void summation(vector <T> * matrix, T number, int i, int j)
  {
    for (int k = 0; k < i || k < j; k++)
      matrix[k][k] += number;
  }

  void subtraction(vector <T> * matrixA, vector <T> * matrixB, int k, int l)
  {
    for (int i = 0; i < k; i++)
      for (int j = 0; j < l; j++)
        matrixA[i][j] -= matrixB[i][j];
  }

  void multiplication(vector <T> * matrix, T number, int k, int l)
  {
    for (int i = 0; i < k; i++)
      for (int j = 0; j < l; j++)
        matrix[i][j] *= number;
  }

  void multiplication(vector <T> * matrix, vector <T> * certainMatrix, vector <T> * resultMatrix, int k, int l)
  {
    for (int i = 0; i < k; i++)
      for (int j = 0; j < l; j++)
        {
          float result = 0;
          for (int s = 0; s < k; s++)
            result += matrix[s][j] * certainMatrix[i][s];
          resultMatrix[i][j] = result;
        }
  }

 public:
  CMatrix(int i, int j)
    {
      memoryAssignment(i_, j_, i, j, matrix_);

      for (int k = 0; k < i_; k++)
        for (int l = 0; l < j_; l++)
          matrix_[k][l] = 0;
    }

  CMatrix(int i, int j, T* array)
    {
      memoryAssignment(i_, j_, i, j, matrix_);

      int index = 0;
      for (int k = 0; k < i_; k++)
        for (int l = 0; l < j_; l++)
          matrix_[k][l] = array[index++];
    }

    CMatrix(int i, int j, int k)
    {
      if(k == 1){
        memoryAssignment(i_, j_, i, j, matrix_);

    for (int k = 0; k < i_; k++){

		for (int l = 0; l < j_; l++){
			if(k == l){
			 matrix_[k][l] = 1;
			}
			else  matrix_[k][l] = 0;
		}


  }

}


else if(k == 2){

  memoryAssignment(i_, j_, i, j, matrix_);

  for (int k = 0; k < i_; k++){

		for (int l = 0; l < j_; l++){
			matrix_[k][l] = rand()%2;
		}


  }


}}

  CMatrix(const CMatrix &certainMat)
    {
      i_ = certainMat.i_;
      j_ = certainMat.j_;

      memoryAssignment(i_, j_, certainMat.i_, certainMat.j_, matrix_);

      for (int k = 0; k < i_; k++)
        for (int l = 0; l < j_; l++)
          matrix_[k][l] = certainMat.matrix_[k][l];
    }

  ~CMatrix()
    {
      erase(matrix_, i_, j_);//	cout << " destructor done\n";
    }


 private:
  int i_;
  int j_;
  vector <T> * matrix_;
};
