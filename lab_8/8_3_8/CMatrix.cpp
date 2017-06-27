#include "CMatrix.h"
#include <iostream>
#include <limits.h>
#include <cmath>
#include <string>

using namespace std;

int CMatrix::counter_ = 0;


//Public:

CMatrix::CMatrix(int i, int j)
{
  memoryAssignment(i_, j_, i, j, matrix_);

  for (int k = 0; k < i_; k++)
    for (int l = 0; l < j_; l++)
      matrix_[k][l] = 0;

  counter_++;
  number_ = counter_;




}

CMatrix::CMatrix(int i, int j, int k)
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


  counter_++;
  number_ = counter_;

}


else if(k == 2){

  memoryAssignment(i_, j_, i, j, matrix_);

  for (int k = 0; k < i_; k++){

		for (int l = 0; l < j_; l++){
			matrix_[k][l] = rand()%2;
		}


  }


  counter_++;
  number_ = counter_;

}


else{cout << "Wrong parameter"<<endl;}

}

CMatrix::CMatrix(int i, int j, float* array)
{
  memoryAssignment(i_, j_, i, j, matrix_);

  int index = 0;
  for (int k = 0; k < i_; k++)
    for (int l = 0; l < j_; l++)
      matrix_[k][l] = array[index++];

  counter_++;
  number_ = counter_;
}

CMatrix::CMatrix(const CMatrix &certainMat)
{
  i_ = certainMat.i_;
  j_ = certainMat.j_;

  memoryAssignment(i_, j_, certainMat.i_, certainMat.j_, matrix_);

  for (int k = 0; k < i_; k++)
    for (int l = 0; l < j_; l++)
      matrix_[k][l] = certainMat.matrix_[k][l];

  counter_++;
  number_ = counter_;
}

CMatrix::~CMatrix()
{
  erase(matrix_, i_, j_);//	cout << " destructor done\n";
}


//Public:
void CMatrix::operator = (const CMatrix &certainMat)
{
  erase(matrix_, i_, j_);
  memoryAssignment(i_, j_, certainMat.i_, certainMat.j_, matrix_);

  for (int k = 0; k < i_; k++)
    for (int l = 0; l < j_; l++)
      matrix_[k][l] = certainMat.matrix_[k][l];
}

CMatrix CMatrix::operator + (const CMatrix &certainMat)
{
  CMatrix result = certainMat;

  summation(result.matrix_, matrix_, i_, j_);

  return result;
}

CMatrix CMatrix::operator - (const CMatrix &certainMat)
{
  CMatrix result(i_, j_);

  summation(result.matrix_, matrix_, i_, j_);
  subtraction(result.matrix_, certainMat.matrix_, i_, j_);

  return result;
}

CMatrix CMatrix::operator * (const CMatrix &certainMat)
{
  CMatrix result(i_, certainMat.j_);

  multiplication(matrix_, certainMat.matrix_, result.matrix_, i_, certainMat.j_);

  return result;
}

void CMatrix::operator += (const CMatrix &certainMat)
{
  summation(matrix_, certainMat.matrix_, i_, j_);
}

void CMatrix::operator -= (const CMatrix &certainMat)
{
  subtraction(matrix_, certainMat.matrix_, i_, j_);
}

/*void CMatrix::operator *= (const CMatrix &certainMat)
{
  CMatrix buff(i_, j_);
  for (int i = 0; i < i_; i++)
    for (int j = 0; j < j_; j++)
      buff.matrix_[i][j] = matrix_[i][j];

  erase(matrix_, i_, j_);
  j_ = certainMat.j_;
  memoryAssignment(i_, j_, i_, certainMat.j_, matrix_);

  multiplication(buff.matrix_, certainMat.matrix_, matrix_, i_, certainMat.j_);
}*/

CMatrix CMatrix::operator + (float number)
{
  CMatrix result(i_, j_);
  summation(result.matrix_, matrix_, i_, j_);

  summation(result.matrix_, number, i_, j_);

  return result;
}

CMatrix CMatrix::operator * (float number)
{
  CMatrix result(i_, j_);
  summation(result.matrix_, matrix_, i_, j_);

  multiplication(result.matrix_, number, i_, j_);

  return result;
}


void CMatrix::operator += (float number)
{
  summation(matrix_, number, i_, j_);
}



/*CMatrix CMatrix::pow (int n)
{
  CMatrix result(i_, j_);
  for (int i = 0; i < i_; i++)
    for (int j = 0; j < j_; j++)
      result.matrix_[i][j] = matrix_[i][j];

  for (int k = 1; k < n; k++) {
    CMatrix intermed(i_, j_);
    for (int i = 0; i < i_; i++)
      for (int j = 0; j < j_; j++)
        intermed.matrix_[i][j] = result.matrix_[i][j];

    multiplication(matrix_, intermed.matrix_, result.matrix_, i_, j_);
  }

  return result;
}*/


void CMatrix::printMatrix()
{
  printMatrix(i_, j_);
}

void CMatrix::printMatrix(int i, int j)
{
  cout << " Matrix " << number_ << "  " << i << "x" << j << "\n";

  for (int k = 0; k < i; k++) {
    for (int l = 0; l < j; l++)
      cout << " " << matrix_[k][l];
    cout << "\n";
  }
}


//Private:
void CMatrix::memoryAssignment(int &i_, int &j_, const int &i, const int &j, float** &matrix_)
{
  i_ = i;
  j_ = j;
  matrix_ = new float*[i_];
  for (int k = 0; k < i_; k++)
    matrix_[k] = new float[j_];


  /*arr[indOfArr] = matrix_;
  indOfArr++;*/
}

void CMatrix::erase(float** &matrix, int i, int j)
{
  for (int l = 0; l < i; l++)
    delete [] matrix[l];
  delete [] matrix;
}

void CMatrix::summation(float** matrixA, float** matrixB, int k, int l)
{
  for (int i = 0; i < k; i++)
    for (int j = 0; j < l; j++)
      matrixA[i][j] += matrixB[i][j];
}

void CMatrix::summation(float** matrix, float number, int i, int j)
{
  for (int k = 0; k < i || k < j; k++)
    matrix[k][k] += number;
}

void CMatrix::subtraction(float** matrixA, float** matrixB, int k, int l)
{
  for (int i = 0; i < k; i++)
    for (int j = 0; j < l; j++)
      matrixA[i][j] -= matrixB[i][j];
}

void CMatrix::multiplication(float** matrix, float number, int k, int l)
{
  for (int i = 0; i < k; i++)
    for (int j = 0; j < l; j++)
      matrix[i][j] *= number;
}

void CMatrix::multiplication(float** matrix, float** certainMatrix, float** resultMatrix, int k, int l)
{
  for (int i = 0; i < k; i++)
    for (int j = 0; j < l; j++) {
      float result = 0;
      for (int s = 0; s < k; s++)
        result += matrix[s][j] * certainMatrix[i][s];
      resultMatrix[i][j] = result;
    }
}

/*void CMatrix::printAll(){



}*/
