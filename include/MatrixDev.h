#include "helper.h"

//!----------------------------------------------
//! Class Matrix
//!----------------------------------------------
class Matrix {
private:
protected:
  int row, col;
  vector<vector<double>> matrix;
  vector<vector<int>> matrix1;

public:
  Matrix(int row = 0, int col = 0) : row(row), col(col) { // Constructor
    matrix.resize(row, vector<double>(col, 0));
    matrix1.resize(row, vector<int>(col, 0));
  }

  friend void swap(int &a, int &b);

  vector<vector<double>> &getMatrix();             // for non-const objects
  const vector<vector<double>> &getMatrix() const; // for const objects

  vector<vector<int>> &getMatrix_int();

  void enterMatrix();
  void enterMatrix_int();

  void printMatrix() const;
  void printMatrix_int() const;

  void setMatrix(const vector<vector<double>> &m);
  void setMatrix(const vector<vector<int>> &m);

  Matrix generateMatrix(const vector<vector<double>> &matrix) const;
  int getRow() const;
  int getCol() const;

  Matrix generateIdentity(const vector<vector<double>> &matrix) const;
  Matrix generateIdentity(const vector<vector<int>> &matrix) const;
};

//!----------------------------------------------
//! Class oneDimension
//!----------------------------------------------
class oneDimension : public Matrix {
private:
  int length_1D;
  vector<double> array_1D;
  vector<int> array_1D_int;

public:
  oneDimension(int row = 0, int col = 0)
      : Matrix(row, col), length_1D(row * col) { // Constructor
    array_1D.resize(length_1D, 0);
    array_1D_int.resize(length_1D, 0);
  }

  // Copy constructor
  oneDimension(const Matrix &m) : Matrix(m) {
    int r = matrix.size();
    int c = matrix[0].size();
    length_1D = r * c;
    array_1D.resize(length_1D);
  }

  void flatten();
  void flatten_int(); 

  void printArray() const;

  vector<double> getArray() const;
  vector<int> getArray_int();

  void setArray(const vector<int> &arr);
};

//!----------------------------------------------
//! Class Matrix_methods
//!----------------------------------------------
class Matrix_methods : public Matrix {
private:
  int det, trace;
  vector<vector<double>> transpMatrix;
  vector<vector<int>> transpMatrix1;

protected:
  int cramer2x2(const vector<vector<double>> &matrix) const;
  int cramer2x2(const vector<vector<int>> &matrix) const;

  int cramer3x3(const vector<vector<double>> &matrix) const;
  int cramer3x3(const vector<vector<int>> &matrix) const;

  int calcTrace(const vector<vector<double>> &matrix) const;

  // vector<vector<double>> transposeMatrixData(const vector<vector<double>>&
  // matrix);

public:
  Matrix_methods(int row = 0, int col = 0, int det = 0, int trace = 0)
      : Matrix(row, col), det(det), trace(trace) {}

  Matrix_methods transposeMatrix(const vector<vector<double>> &matrix);
  Matrix_methods transposeMatrix(const vector<vector<int>> &matrix1);

  int getDeterminant();
  int getDeterminant_int();

  int getTrace();

  //~Matrix_methods() = default;
};

//!----------------------------------------------
//! Class Calculated_matrix
//!----------------------------------------------
class Calculated_matrix : public Matrix {
private:
  vector<vector<double>> resultMatrix;

public:
  Calculated_matrix(int row = 0, int col = 0) : Matrix(row, col) {}

  Calculated_matrix addMatrix(const vector<vector<double>> &m1, const vector<vector<double>> &m2) const;
  Calculated_matrix subtractMatrix(const vector<vector<double>> &m1, const vector<vector<double>> &m2) const;

  Calculated_matrix multiplyMatrix(const vector<vector<double>> &m1, const vector<vector<double>> &m2) const;
  // Overloading multiplyMatrix function
  Calculated_matrix multiplyMatrix(const Calculated_matrix &m1, const Calculated_matrix &m2) const;
  Calculated_matrix multiplyMatrix(const vector<vector<int>> &m1, const vector<vector<int>> &m2) const;

  Calculated_matrix powerMatrix(const Calculated_matrix &m, int power) const;

  Calculated_matrix inverseMatrix(vector<vector<double>> &m) const;
  // Overloading inverseMatrix function
  Calculated_matrix inverseMatrix(vector<vector<int>> &m) const;

  // Temporary debug version of multiplyMatrix
  Calculated_matrix debugMultiplyMatrix(const vector<vector<int>> &m1, const vector<vector<int>> &m2);
};

//!----------------------------------------------
//! Class En_Decryption
//!----------------------------------------------
class En_Decryption : public oneDimension {
private:
  string message;
  int msgLength;
  vector<int> nums;

public:
  En_Decryption(int row = 0, int col = 0, string message = "") : oneDimension(row, col), message(message) {
    msgLength = message.length();
    nums.resize(msgLength, 0);
  }

  friend int charToNum(char ch);
  friend char numToChar(int num);
  // vector<int>
  En_Decryption numStorage(const string &str);
  // vector<vector<int>>
  En_Decryption vectorToMatrix(const vector<int> &nums, int blockRow, int &blockCol) const;
  En_Decryption vectorToMatrix_1(const vector<int> &arr, int row, int col) const;

  friend int gcd(int a, int b);
  friend void swapRows(vector<vector<int>> &matrix, int row1, int row2, int cols);
  friend int matrixRank(vector<vector<int>> matrix, int row, int col);
  friend bool isModularInvertible(int det, int mod);

  En_Decryption generatePredefinedKeyMatrix(int size, int mod) const;

  En_Decryption generateInvertibleKeyMatrix(int blockSize3x3, int mod) const;
  En_Decryption generateInvertibleKeyMatrix_1(int size, int mod) const;

  En_Decryption exampleKeyMatrix(vector<vector<int>> &demo) const;

  void setMessage(const string &msg);
  string getMessage() const;
  string convertToEncryptedMessage(const vector<int> &encryptedArray) const;
  string convertToDecryptedMessage(const vector<int> &decryptedArray) const;
};
