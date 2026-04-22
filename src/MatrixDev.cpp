#include "MatrixDev.h"

//!----------------------------------------------
//! Class Matrix
//!----------------------------------------------
vector<vector<double>> &Matrix::getMatrix() { return matrix; }

const vector<vector<double>> &Matrix::getMatrix() const { return matrix; }

vector<vector<int>> &Matrix::getMatrix_int() { return matrix1; }

void Matrix::enterMatrix() {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cout << "Element [" << i << "][" << j << "] = ";
      cin >> matrix[i][j];
    }
  }
}

void Matrix::enterMatrix_int(){
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cout << "Element [" << i << "][" << j << "] = ";
      cin >> matrix1[i][j];
    }
  }
}

void Matrix::printMatrix() const {
  for (auto &r : matrix) {
    for (auto val : r) {
      cout << val << "\t";
    }
    cout << "\n";
  }
}

void Matrix::printMatrix_int() const {
  for (auto &r : matrix1) {
    for (auto val : r) {
      cout << val << "\t";
    }
    cout << "\n";
  }
}

void Matrix::setMatrix(const vector<vector<double>> &m) {
  matrix = m;
  row = m.size();
  col = (row > 0 ? m[0].size() : 0);
}

void Matrix::setMatrix(const vector<vector<int>> &m) {
  matrix1 = m;
  row = m.size();
  col = (row > 0 ? m[0].size() : 0);
}

Matrix Matrix::generateMatrix(const vector<vector<double>> &matrix) const {
  int r = matrix.size();
  int c = matrix[0].size();
  vector<vector<double>> result;
  Matrix randomMatrix(r, c);
  result.resize(r, vector<double>(c, 0));

  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dis(0, 99);

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      result[i][j] = dis(gen);
    }
  }

  randomMatrix.getMatrix() = result;
  return randomMatrix;
}

int Matrix::getRow() const { return row; }

int Matrix::getCol() const { return col; }

Matrix Matrix::generateIdentity(const vector<vector<double>> &matrix) const {
  int r = matrix.size();
  int c = matrix[0].size();
  if (r != c) {
    cerr << "Error: Matrix must be square.\n";
    return Matrix();
  }
  Matrix identityMatrix(r, c);
  vector<vector<double>> result;
  result.resize(r, vector<double>(c, 0));
  for (int i = 0; i < r; i++) {
    result[i][i] = 1;
  }
  identityMatrix.setMatrix(result);
  return identityMatrix;
}

Matrix Matrix::generateIdentity(const vector<vector<int>> &matrix) const {
  int r = matrix1.size();
  int c = matrix1[0].size();
  if (r != c) {
    cerr << "Error: Matrix must be square.\n";
    return Matrix();
  }
  Matrix identityMatrix(r, c);
  vector<vector<int>> result;
  result.resize(r, vector<int>(c, 0));
  for (int i = 0; i < r; i++) {
    result[i][i] = 1;
  }
  identityMatrix.setMatrix(result);
  return identityMatrix;
}

//!----------------------------------------------
//! Class oneDimension
//!----------------------------------------------
void oneDimension::flatten() {
  int r = matrix.size();
  int c = matrix[0].size();
  length_1D = r * c;
  array_1D.resize(length_1D);
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      array_1D[i * c + j] = matrix[i][j];
    }
  }
}

void oneDimension::flatten_int() {
    int r = matrix1.size();
    int c = matrix1[0].size();
    length_1D = r * c;
    array_1D_int.resize(length_1D);
    
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            array_1D_int[i * c + j] = matrix1[i][j];
        }
    }
    cout << endl;
}

void oneDimension::printArray() const {
  cout << "(Flattened): ";
  for (int val : array_1D) {
    cout << val << " ";
  }
  cout << endl;
}

vector<double> oneDimension::getArray() const { return array_1D; }

vector<int> oneDimension::getArray_int() {
  // Return the actual data that was set, not the empty array_1D_int
  return array_1D_int;
}

void oneDimension::setArray(const vector<int> &arr) {
  array_1D_int = arr;
  length_1D = arr.size();

  // Also update the double version for compatibility
  array_1D.clear();
  for (int val : arr) {
    array_1D.push_back(static_cast<double>(val));
  }
}

//!----------------------------------------------
//! Class Matrix_methods
//!----------------------------------------------
Matrix_methods Matrix_methods::transposeMatrix(const vector<vector<double>> &m) {
  int r = m.size();
  int c = m[0].size();
  Matrix_methods result(c, r); // swapped dimensions
  vector<vector<double>> trans(c, vector<double>(r));

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      trans[j][i] = m[i][j];
    }
  }
  result.getMatrix() = trans;
  return result;
}

Matrix_methods Matrix_methods::transposeMatrix(const vector<vector<int>> &m){
  int r = m.size();
  int c = m[0].size();
  Matrix_methods result(c, r); // swapped dimensions
  vector<vector<int>> trans(c, vector<int>(r));

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      trans[j][i] = m[i][j];
    }
  }
  result.getMatrix_int() = trans;
  return result;
}

int Matrix_methods::cramer2x2(const vector<vector<double>> &m) const {
  if (m.size() != 2 || m[0].size() != 2) {
    cerr << "Error: cramer2x2 expects a 2x2 matrix.\n";
    return 0;
  }
  return m[0][0] * m[1][1] - m[0][1] * m[1][0];
}

// Overloading cramer2x2
int Matrix_methods::cramer2x2(const vector<vector<int>> &m) const {
  if (m.size() != 2 || m[0].size() != 2) {
    cerr << "Error: cramer2x2 expects a 2x2 matrix.\n";
    return 0;
  }
  return m[0][0] * m[1][1] - m[0][1] * m[1][0];
}

int Matrix_methods::cramer3x3(const vector<vector<double>> &m) const {
  if (m.size() != 3 || m[0].size() != 3) {
    cerr << "Error: cramer3x3 expects a 3x3 matrix.\n";
    return 0;
  }
  return m[0][0] * pow(-1, 2) * (m[1][1] * m[2][2] - m[2][1] * m[1][2]) +
         m[0][1] * pow(-1, 3) * (m[1][0] * m[2][2] - m[2][0] * m[1][2]) +
         m[0][2] * pow(-1, 2) * (m[1][0] * m[2][1] - m[2][0] * m[1][1]);
}

// Overloading cramer3x3
int Matrix_methods::cramer3x3(const vector<vector<int>> &m) const {
  if (m.size() != 3 || m[0].size() != 3) {
    cerr << "Error: cramer3x3 expects a 3x3 matrix.\n";
    return 0;
  }
  return m[0][0] * pow(-1, 2) * (m[1][1] * m[2][2] - m[2][1] * m[1][2]) +
         m[0][1] * pow(-1, 3) * (m[1][0] * m[2][2] - m[2][0] * m[1][2]) +
         m[0][2] * pow(-1, 2) * (m[1][0] * m[2][1] - m[2][0] * m[1][1]);
}

int Matrix_methods::calcTrace(const vector<vector<double>> &m) const {
  if (m.size() != m[0].size()) {
    cerr << "Error: trace is defined only for square matrices.\n";
    return 0;
  }
  int trace = 0;
  for (int i = 0; i < m.size(); ++i)
    trace += m[i][i];
  return trace;
}

int Matrix_methods::getDeterminant() {
  if (row == 2)
    return cramer2x2(matrix);
  else if (row == 3)
    return cramer3x3(matrix);
  else {
    cerr << "Error: Determinant only implemented for 2x2 and 3x3 matrices.\n";
    return 0;
  }
}

// Overloading getDeterminant
int Matrix_methods::getDeterminant_int() {
  if (row == 2)
    return cramer2x2(matrix1);
  else if (row == 3)
    return cramer3x3(matrix1);
  else {
    cerr << "Error: Determinant only implemented for 2x2 and 3x3 matrices.\n";
    return 0;
  }
}

int Matrix_methods::getTrace() { return calcTrace(matrix); }

//!----------------------------------------------
//! Class Calculated_matrix
//!----------------------------------------------
Calculated_matrix Calculated_matrix::addMatrix(const vector<vector<double>> &m1, const vector<vector<double>> &m2) const {
  int row1 = m1.size();
  int col1 = m1[0].size();
  int row2 = m2.size();
  int col2 = m2[0].size();
  if (row1 != row2 || col1 != col2) {
    cerr << "Two matrices must have the same size!\n";
    return Calculated_matrix();
  }
  Calculated_matrix resultMatrix(row1, col1);
  vector<vector<double>> addedMatrix(row1, vector<double>(col1));
  for (int i = 0; i < row1; i++) {
    for (int j = 0; j < col1; j++) {
      addedMatrix[i][j] = m1[i][j] + m2[i][j];
    }
  }
  resultMatrix.getMatrix() = addedMatrix;
  return resultMatrix;
}

Calculated_matrix Calculated_matrix::subtractMatrix(const vector<vector<double>> &m1, const vector<vector<double>> &m2) const {
  int row1 = m1.size();
  int col1 = m1[0].size();
  int row2 = m2.size();
  int col2 = m2[0].size();
  if (row1 != row2 || col1 != col2) {
    cerr << "Two matrices must have the same size!\n";
    return Calculated_matrix();
  }
  Calculated_matrix resultMatrix(row1, col1);
  vector<vector<double>> subtractedMatrix(row1, vector<double>(col1));
  for (int i = 0; i < row1; i++) {
    for (int j = 0; j < col1; j++) {
      subtractedMatrix[i][j] = m1[i][j] - m2[i][j];
    }
  }
  resultMatrix.getMatrix() = subtractedMatrix;
  return resultMatrix;
}

Calculated_matrix Calculated_matrix::multiplyMatrix(const vector<vector<double>> &m1, const vector<vector<double>> &m2) const {
  int row1 = m1.size();
  int col1 = m1[0].size();
  int row2 = m2.size();
  int col2 = m2[0].size();
  if (col1 != row2) {
    cerr << "The col of the first matrix must be equal to the row of the second matrix!\n";
    return Calculated_matrix();
  }
  Calculated_matrix resultMatrix(row1, col2);
  vector<vector<double>> multipliedMatrix(row1, vector<double>(col2));
  for (int i = 0; i < row1; i++) {
    for (int j = 0; j < col2; j++) {
      multipliedMatrix[i][j] = 0;
      for (int k = 0; k < col1; k++) {
        multipliedMatrix[i][j] += m1[i][k] * m2[k][j];
      }
    }
  }
  resultMatrix.getMatrix() = multipliedMatrix;
  return resultMatrix;
}

Calculated_matrix Calculated_matrix::multiplyMatrix(const Calculated_matrix &m1, const Calculated_matrix &m2) const {
  int r1 = m1.getRow();
  int c1 = m1.getCol();
  int r2 = m2.getRow();
  int c2 = m2.getCol();
  if (c1 != r2) {
    cerr << "The col of the first matrix must be equal to the row of the second matrix!\n";
    return Calculated_matrix();
  }
  Calculated_matrix resultMatrix(r1, c2);
  vector<vector<double>> multipliedMatrix(r1, vector<double>(c2, 0.0));
  const vector<vector<double>> &mat1 = m1.getMatrix();
  const vector<vector<double>> &mat2 = m2.getMatrix();
  for (int i = 0; i < r1; i++) {
    for (int j = 0; j < c2; j++) {
      for (int k = 0; k < c1; ++k) {
        multipliedMatrix[i][j] += mat1[i][k] * mat2[k][j];
      }
    }
  }
  resultMatrix.setMatrix(multipliedMatrix);
  return resultMatrix;
}

Calculated_matrix Calculated_matrix::multiplyMatrix(const vector<vector<int>> &m1, const vector<vector<int>> &m2) const {
  int row1 = m1.size();
  int col1 = m1[0].size();
  int row2 = m2.size();
  int col2 = m2[0].size();
  if (col1 != row2) {
    cerr << "The col of the first matrix must be equal to the row of the second matrix!\n";
    return Calculated_matrix();
  }
  Calculated_matrix resultMatrix(row1, col2);
  vector<vector<int>> multipliedMatrix(row1, vector<int>(col2));
  for (int i = 0; i < row1; i++) {
    for (int j = 0; j < col2; j++) {
      multipliedMatrix[i][j] = 0;
      for (int k = 0; k < col1; k++) {
        multipliedMatrix[i][j] += m1[i][k] * m2[k][j];
      }
    }
  }
  resultMatrix.getMatrix_int() = multipliedMatrix;
  return resultMatrix;
}

Calculated_matrix Calculated_matrix::powerMatrix(const Calculated_matrix &m, int power) const {
  int row = m.getRow();
  int col = m.getCol();
  if (row != col) {
    cerr << "Error: Matrix must be square to compute its power.\n";
    return Calculated_matrix();
  }
  if (power == 0) {
    Calculated_matrix identityMatrix(row, col);
    vector<vector<double>> tmpMatrix;
    Matrix resultMatrix;
    tmpMatrix = m.getMatrix();
    resultMatrix = generateIdentity(tmpMatrix);
    tmpMatrix = resultMatrix.getMatrix();
    identityMatrix.setMatrix(tmpMatrix);
    return identityMatrix;
  }
  Calculated_matrix resultMatrix = m;
  for (int i = 1; i < power; i++) {
    resultMatrix = multiplyMatrix(resultMatrix.getMatrix(), m.getMatrix());
  }
  return resultMatrix;
}

Calculated_matrix Calculated_matrix::inverseMatrix(vector<vector<double>> &m) const {
  int r = m.size();
  int c = m[0].size();
  double det;
  if (r != c) {
    cerr << "Error: Matrix must be square.\n";
    return Calculated_matrix();
  }
  Matrix_methods detMatrix(r, c);
  detMatrix.setMatrix(m);
  Calculated_matrix resultMatrix(r, c);
  vector<vector<double>> inverse;
  if (r == 2) {
    det = detMatrix.getDeterminant();
    if (det == 0) {
      cerr << "This matrix is not invertible (det = 0).\n";
      return Calculated_matrix();
    }
    inverse.resize(r, vector<double>(c, 0));
    inverse[0][0] = m[1][1] / det;
    inverse[0][1] = -m[0][1] / det;
    inverse[1][0] = -m[1][0] / det;
    inverse[1][1] = m[0][0] / det;
    resultMatrix.setMatrix(inverse);
    return resultMatrix;
  } 
  else if (r == 3) {
    det = detMatrix.getDeterminant();
    if (det == 0) {
      cerr << "This matrix is not invertible (det = 0).\n";
      return Calculated_matrix();
    }
    inverse.resize(r, vector<double>(c, 0));

    inverse[0][0] = (m[1][1] * m[2][2] - m[1][2] * m[2][1]) / det;
    inverse[0][1] = -(m[0][1] * m[2][2] - m[0][2] * m[2][1]) / det;
    inverse[0][2] = (m[0][1] * m[1][2] - m[0][2] * m[1][1]) / det;

    inverse[1][0] = -(m[1][0] * m[2][2] - m[1][2] * m[2][0]) / det;
    inverse[1][1] = (m[0][0] * m[2][2] - m[0][2] * m[2][0]) / det;
    inverse[1][2] = -(m[0][0] * m[1][2] - m[0][2] * m[1][0]) / det;

    inverse[2][0] = (m[1][0] * m[2][1] - m[1][1] * m[2][0]) / det;
    inverse[2][1] = -(m[0][0] * m[2][1] - m[0][1] * m[2][0]) / det;
    inverse[2][2] = (m[0][0] * m[1][1] - m[0][1] * m[1][0]) / det;

    resultMatrix.setMatrix(inverse);
    return resultMatrix;
  } 
  else {
    cerr << "Inverse for matrices larger than 3x3 is not implemented.\n";
    return Calculated_matrix();
  }
}

Calculated_matrix Calculated_matrix::inverseMatrix(vector<vector<int>> &m) const {
  int mod = 27;
  int r = m.size();
  int c = m[0].size();
  int det;
  if (r != c) {
    cerr << "Error: Matrix must be square.\n";
    return Calculated_matrix();
  }

  Matrix_methods detMatrix(r, c);
  detMatrix.setMatrix(m);
  det = detMatrix.getDeterminant_int();

  // Handle negative determinant for mod 27
  det = (det % mod + mod) % mod;

  if (det == 0 || gcd(det, 27) != 1) {
    cerr << "This matrix is not invertible mod 27 (det = " << det << ").\n";
    return Calculated_matrix();
  }

  int det_inv = modInverse(det, 27);
  Calculated_matrix resultMatrix(r, c);
  vector<vector<int>> inverse(r, vector<int>(c, 0));

  if (r == 2) {
    inverse[0][0] = (m[1][1] * det_inv) % 27;
    inverse[0][1] = ((-m[0][1] * det_inv) % 27 + 27) % 27;
    inverse[1][0] = ((-m[1][0] * det_inv) % 27 + 27) % 27;
    inverse[1][1] = (m[0][0] * det_inv) % 27;
  } 
  else if (r == 3) {
    // Calculate adjugate matrix with proper mod
    inverse[0][0] = ((m[1][1] * m[2][2] - m[1][2] * m[2][1]) * det_inv) % 27;
    inverse[0][1] = ((-(m[0][1] * m[2][2] - m[0][2] * m[2][1]) * det_inv) % 27 + 27) % 27;
    inverse[0][2] = ((m[0][1] * m[1][2] - m[0][2] * m[1][1]) * det_inv) % 27;
        
    inverse[1][0] = ((-(m[1][0] * m[2][2] - m[1][2] * m[2][0]) * det_inv) % 27 + 27) % 27;
    inverse[1][1] = ((m[0][0] * m[2][2] - m[0][2] * m[2][0]) * det_inv) % 27;
    inverse[1][2] = ((-(m[0][0] * m[1][2] - m[0][2] * m[1][0]) * det_inv) % 27 + 27) % 27;
        
    inverse[2][0] = ((m[1][0] * m[2][1] - m[1][1] * m[2][0]) * det_inv) % 27;
    inverse[2][1] = ((-(m[0][0] * m[2][1] - m[0][1] * m[2][0]) * det_inv) % 27 + 27) % 27;
    inverse[2][2] = ((m[0][0] * m[1][1] - m[0][1] * m[1][0]) * det_inv) % 27;
  }
    
  // Apply mod to all elements
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      inverse[i][j] = (inverse[i][j] % 27 + 27) % 27;
    }
  }
    
  resultMatrix.setMatrix(inverse);
  return resultMatrix;
}

Calculated_matrix Calculated_matrix::debugMultiplyMatrix(const vector<vector<int>> &m1, const vector<vector<int>> &m2) {
  int row1 = m1.size();
  int col1 = m1[0].size();
  int row2 = m2.size();
  int col2 = m2[0].size();

  cout << "DEBUG multiplyMatrix: " << row1 << "x" << col1 << " * " << row2
       << "x" << col2 << endl;

  if (col1 != row2) {
    cerr << "The col of the first matrix must be equal to the row of the "
            "second matrix!\n";
    return Calculated_matrix();
  }

  Calculated_matrix resultMatrix(row1, col2);
  vector<vector<int>> multipliedMatrix(row1, vector<int>(col2));

  for (int i = 0; i < row1; i++) {
    for (int j = 0; j < col2; j++) {
      multipliedMatrix[i][j] = 0;
      for (int k = 0; k < col1; k++) {
        multipliedMatrix[i][j] += m1[i][k] * m2[k][j];
        cout << "  " << m1[i][k] << " * " << m2[k][j] << " = "
             << m1[i][k] * m2[k][j] << endl;
      }
      cout << "Result[" << i << "][" << j << "] = " << multipliedMatrix[i][j]
            << endl;
    }
  }

  resultMatrix.getMatrix_int() = multipliedMatrix;
  return resultMatrix;
}
//!----------------------------------------------
//! Class En_Decryption
//!----------------------------------------------
string toLowerString(const string &str) {
  string result = str;
  for (char &ch : result) {
    if (ch >= 'A' && ch <= 'Z') {
      ch = tolower(ch);
    }
  }
  return result;
}

int charToNum(char ch) {
  if (ch == ' ') {
    return 0;
  }
  if (ch >= 'a' && ch <= 'z') {
    return ch - 'a' + 1;
  }
  return 0;
}

char numToChar(int num) {
    num = num % 27;  
    if (num < 0) {
      num += 27;
    }
    if (num == 0) {
        return '-';
    }
    if (num >= 1 && num <= 26) {
        return 'a' + num - 1;
    }
    return '?';
}

En_Decryption En_Decryption::numStorage(const string &str) {
  nums.clear();
  En_Decryption resultArray;
  vector<int> tempNums;
  for (char ch : str) {
    int num = charToNum(ch);
    tempNums.push_back(num);
  }
  cout << endl;
  resultArray.setArray(tempNums);
  return resultArray;
}

En_Decryption En_Decryption::vectorToMatrix(const vector<int> &nums, int blockRow, int &blockCol) const {
  int size = nums.size();
  blockCol = size / blockRow;
  if (size % blockRow != 0) {
    blockCol++;
  }
  En_Decryption resultMatrix;
  vector<vector<int>> matrix1;
  matrix1.resize(blockRow, vector<int>(blockCol, 0));
  int idx = 0;
  for (int j = 0; j < blockCol; j++) {
    for (int i = 0; i < blockRow; i++) {
      if (idx < size) {
        matrix1[i][j] = nums[idx++];
      } else {
        matrix1[i][j] = 0;
      }
    }
  }
  resultMatrix.setMatrix(matrix1);
  return resultMatrix;
}

En_Decryption En_Decryption::vectorToMatrix_1(const vector<int> &arr, int row, int col) const {
  En_Decryption result(row, col);
  vector<vector<int>> temp(row, vector<int>(col, 0));
  int idx = 0;
  for (int j = 0; j < col; ++j) {
    for (int i = 0; i < row; ++i) {
      if (idx < arr.size()) {
        temp[i][j] = arr[idx++];
      }
    }
  }
  result.setMatrix(temp);
  return result;
}

void swapRows(vector<vector<int>> &matrix, int row1, int row2, int cols) {
  for (int c = 0; c < cols; ++c) {
    swap(matrix[row1][c], matrix[row2][c]);
  }
}

int matrixRank(vector<vector<int>> matrix, int rows, int cols) {
  int rank = 0;
  for (int col = 0; col < cols && rank < rows; ++col) {
    // Tim pivot(phan tu khac 0 dau tien trong cot hien tai)
    int pivotRow = -1;
    for (int row = rank; row < rows; ++row) {
      if (matrix[row][col] != 0) {
        pivotRow = row;
        break;
      }
    }
    if (pivotRow == -1) { // Bo qua cot toan 0
      continue;
    }
    // Dua hang chua pivot len vi tri hien tai cua rank
    swapRows(matrix, rank, pivotRow, cols);
    // Khu cac hang phia duoi
    for (int row = rank + 1; row < rows; ++row) {
      if (matrix[row][col] != 0) {
        int factor = matrix[row][col] / matrix[rank][col];
        for (int c = col; c < cols; ++c) {
          matrix[row][c] -= factor * matrix[rank][c];
        }
      }
    }
    rank++;
  }
  return rank;
}

bool isModularInvertible(int det, int mod) {
  // Handle negative determinants
  det = (det % mod + mod) % mod;

  // Check if gcd(det, mod) == 1
  return gcd(det, mod) == 1;
}

En_Decryption En_Decryption::generatePredefinedKeyMatrix(int size, int mod) const {
  En_Decryption resultMatrix;
  vector<vector<int>> key;

  if (size == 2) {
    // 2x2 matrix with det = 1 (invertible mod 27)
    key = {{1, 2}, {0, 1}};
  } else if (size == 3) {
    // 3x3 matrix with det = 1 (invertible mod 27)
    key = {{1, 0, 1}, {0, 1, 1}, {1, 1, 0}};
  } else if (size == 4) {
    // 4x4 matrix with det = 1 (invertible mod 27)
    key = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
  } else {
    // Identity matrix as fallback
    key.resize(size, vector<int>(size, 0));
    for (int i = 0; i < size; i++) {
      key[i][i] = 1;
    }
  }
  cout << "Using predefined key matrix:" << endl;
  for (const auto &row : key) {
    for (int val : row) {
      cout << setw(3) << val << " ";
    }
    cout << endl;
  }
  cout << endl;

  resultMatrix.setMatrix(key);
  return resultMatrix;
}

/* En_Decryption En_Decryption::generateInvertibleKeyMatrix(int size, int mod)
const{ mt19937 rng(time(0)); uniform_int_distribution<int> dist(-10, 10);

  vector<vector<int>> key;
  vector<vector<int>> tmp;
  key.resize(size, vector<int>(size, 0));
  tmp.resize(size, vector<int>(size, 0));

  Matrix identity;
  Matrix_methods detMatrix(size, size);

  En_Decryption resultMatrix;

  while(1){
    identity.generateIdentity(key);
    for (int transform = 0; transform < 5 + size * 2; transform++){
      int op = rng() % 3;
      int row1 = rng() % size;
      int row2 = rng() % size;
      if(row1 == row2){
        continue;
      }
      switch (op){
        case 0:{
          for (int j = 0; j < size; j++){
            swap(key[row1][j], key[row2][j]);
          }
          break;
        }
        case 1:{
          for (int j = 0; j < size; j++){
            key[row1][j] *= -1;
          }
          break;
        }
        case 2:{
          int factor = dist(rng);
          for (int j = 0; j < size; j++){
            key[row1][j] += factor * key[row2][j];
          }
          break;
        }
      }
    }
    bool isValid = true;
    for (int i = 0; i < size; i++){
      for (int j = 0; j < size; j++){
        tmp[i][j] = (key[i][j] % mod + mod) % mod;
        if(i == j && tmp[i][j] == 0){
          isValid = false;
        }
        if(i != j && tmp[i][j] == 0){
          isValid = false;
        }
      }
      if(!isValid){
        break;
      }
    }
    if(isValid){
      detMatrix.getMatrix_int() = tmp;
      int det = detMatrix.getDeterminant();
      if(det == 1 || det == -1){
        key = tmp;
        resultMatrix.setMatrix(key);
        return resultMatrix;
      }
    }
  }
}*/

En_Decryption En_Decryption::generateInvertibleKeyMatrix_1(int size, int mod) const {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> dist(0, mod - 1);

  En_Decryption resultMatrix;
  Matrix_methods detCalculator(size, size);

  int attempts = 0;
  const int MAX_ATTEMPTS = 100; // Prevent infinite loop

  while (attempts < MAX_ATTEMPTS) {
    vector<vector<int>> key(size, vector<int>(size, 0));
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        key[i][j] = dist(gen);
      }
    }
    detCalculator.setMatrix(key);
    int det = detCalculator.getDeterminant_int();

    if (isModularInvertible(det, mod)) {
      resultMatrix.setMatrix(key);
      return resultMatrix;
    }
    attempts++;
  }
  return generatePredefinedKeyMatrix(size, mod);
}

En_Decryption En_Decryption::exampleKeyMatrix(vector<vector<int>> &demo) const {
  demo.resize(3, vector<int>(3, 0));
  En_Decryption resultMatrix;
  
  demo[0][0] = 1;
  demo[0][1] = 2;
  demo[0][2] = -1;
  demo[1][0] = 2;
  demo[1][1] = 5;
  demo[1][2] = -3;
  demo[2][0] = 3;
  demo[2][1] = 7;
  demo[2][2] = -5;

  resultMatrix.setMatrix(demo);
  return resultMatrix;
}

void En_Decryption::setMessage(const string &msg) { message = msg; }

string En_Decryption::getMessage() const { return message; }

string En_Decryption::convertToEncryptedMessage(const vector<int> &encryptedArray) const {
  string encryptedMessage = "";
  for (int num : encryptedArray) {
    encryptedMessage += numToChar(num);
  }
  return encryptedMessage;
}

string En_Decryption::convertToDecryptedMessage(const vector<int> &decryptedArray) const{
  string decryptedMessage = "";
  int sizeArray = decryptedArray.size();
  while(sizeArray > 0 && decryptedArray[sizeArray - 1] == 0){
    sizeArray--;
  }
  for (int i = 0; i < sizeArray; i++) {
    decryptedMessage += numToChar(decryptedArray[i]);
  }
  return decryptedMessage;
}


