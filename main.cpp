#include "MatrixDev.h"

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MAIN~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int main() {
  cout << "***************************************************************\n";
  cout << "WELCOME TO THE MATRIX DEVELOPMENT PROJECT!\n";
  cout << "Here are some announcements for this project:\n";
  cout << "- Currently, this program is available for square matrices with rank 2, 3 & 4.\n";
  cout << "- Initially, you have to enter the matrix first, then you can choose next option of matrix method.\n";
  cout << "- Please be careful when entering the indexes!\n";
  cout << "- Here is the menu.\n";
  cout << endl;
  printMenu();
  cout << "***************************************************************\n";

  int opt, optA, optB, row, col, n, det, trace, row1, col1, power, blockCol, det1;
  const int mod = 27;
  const int blockRow2x2 = 2;
  const int blockRow3x3 = 3;
  const int blockRow = 3;
  char lc, cont, random, sign, add_more, multiply_more, opt10, help;
  string message, encryptedString, decryptedString;

  while (true) {
    cout << "------------------------------------------------------\n";
    cout << "Enter your selection (opt): ";
    cin >> opt;
    if (cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "------------------------------------------------------\n";
      cout << "Invalid selection, please choose again!\n";
      continue;
    }

    if (opt == 1) {
      while (1) {
        cout << "------------------------------------------------------\n";
        cout << "Which types is your matrix (A.Normal || B.Square): ";
        cin >> lc;
        switch (lc) {
          case 'A':
          case 'a': {
            cout << "------------------------------------------------------\n";
            cout << "OK, it is a normal matrix\n";
            while (true) {
              cout << "-------------------------------------------------------------------\n";
              cout << "Enter the number of rows (row > 0): ";
              cin >> row;
              cout << "Enter the number of cols (col > 0): ";
              cin >> col;
              if (row <= 0 || col <= 0) {
                cout << "-------------------------------------------------------------------\n";
                cerr << "Your matrix has an invalid size (row & col must be positive value)!\n";
                cerr << "Please enter again!\n";
                continue;
              } 
              else {
                break;
              }
            }
            Matrix normalMatrix1(row, col);
            Matrix_methods normalMatrix_1(row, col);
            Calculated_matrix normalMatrix_1_(row, col);
            Matrix randomMatrix(row, col);

            while (1) {
              cout << "Do you want to generate the matrix randomly? (y/n): ";
              cin >> random;
              if (random == 'Y' || random == 'y') {
                cout << "------------------------------------------------------\n";
                cout << "You have chosen generating the matrix randomly!\n";
                randomMatrix = normalMatrix1.generateMatrix(normalMatrix1.getMatrix());
                cout << "\nHere is your random matrix: \n";
                randomMatrix.printMatrix();
                normalMatrix_1.setMatrix(randomMatrix.getMatrix());
                normalMatrix_1_.setMatrix(randomMatrix.getMatrix());
                break;
              } 
              else if (random == 'N' || random == 'n') {
                normalMatrix1.enterMatrix();
                cout << "Your entered matrix: \n";
                normalMatrix1.printMatrix();
                normalMatrix_1.setMatrix(normalMatrix1.getMatrix());
                normalMatrix_1_.setMatrix(normalMatrix1.getMatrix());
                break;
              } 
              else {
                cerr << "Invalid selection, please choose again!\n";
                continue;
              }
            }
            while (true) {
              cout << "------------------------------------------------------\n";
              cout << "What will we do next?: ";
              cin >> optA;
              switch (optA) {
                case 1: {
                  cout << "------------------------------------------------------\n";
                  cout << "You have already entered your matrix!\n";
                  cout << "Please choose another selection!\n";
                  continue;
                }
                case 2: {
                  cout << "------------------------------------------------------\n";
                  cout << "You have choose Transposing matrix!\n";
                  Matrix_methods transposed_matrix = normalMatrix_1.transposeMatrix(normalMatrix_1.getMatrix());
                  cout << "Here is your matrix after transposed: \n";
                  transposed_matrix.printMatrix();
                  cout << "------------------------------------------------------\n";
                  cout << "\nDo you want to continue? (y/n): "; cin >> cont;
                  if (cont == 'n' || cont == 'N') {
                    cout << "------------------------------------------------------\n";
                    cout << "Thanks for your experience, goodbye!\n";
                    exit(0);
                  } 
                  else {
                    break;
                  }
                } 
                case 3: {
                  cout << "------------------------------------------------------\n";
                  cout << "You have chosen Flattening matrix!\n";
                  if (random == 'Y' || random == 'y') {
                    oneDimension array1(randomMatrix);
                    array1.flatten();
                    cout << "\nHere is your matrix after flattened: \n";
                    array1.printArray();
                  } 
                  else if (random == 'N' || random == 'n') {
                    oneDimension array1(normalMatrix1);
                    array1.flatten();
                    cout << "\nHere is your matrix after flattened: \n";
                    array1.printArray();
                  }
                  cout << "------------------------------------------------------\n";
                  cout << "\nDo you want to continue? (y/n): "; cin >> cont;
                  if (cont == 'n' || cont == 'N') {
                    cout << "------------------------------------------------------\n";
                    cout << "Thanks for your experience, goodbye!\n";
                    exit(0);
                  } 
                  else {
                    break;
                  }
                }
                case 4: {
                  cout << "------------------------------------------------------\n";
                  cout << "Sorry, Det calculation is not available for normal matrix...\n";
                  continue;
                }
                case 5: {
                  cout  << "------------------------------------------------------\n";
                  cout << "Sorry, Trace calculation is not available for normal matrix...\n";
                  continue;
                }
                case 6: {
                  cout  << "------------------------------------------------------\n";
                  cout << "You have chosen Adding or Subtracting matrices!\n";
                  while (1) {
                    cout << "Choose one method (+ / -): ";
                    cin >> sign;
                    if (sign == '+') {
                      cout << "------------------------------------------------------\n";
                      Calculated_matrix resultMatrix = normalMatrix_1_;
                      do {
                        cout << "Please enter the matrix for addition (same size as the initial one):\n";
                        Calculated_matrix normalMatrix_2(row, col);
                        normalMatrix_2.enterMatrix();

                        cout << "\nYour additionally entered matrix:\n";
                        normalMatrix_2.printMatrix();

                        resultMatrix = resultMatrix.addMatrix(resultMatrix.getMatrix(), normalMatrix_2.getMatrix());

                        cout << "------------------------------------------------------\n";
                        cout << "Do you want to add more matrices? (y/n): ";
                        cin >> add_more;
                      } while (add_more == 'y' || add_more == 'Y');
                      cout << "\n------------------------------------------------------\n";
                      cout << "Final result after addition:\n";
                      resultMatrix.printMatrix();
                      break;
                    } 
                    else if (sign == '-') {
                      cout << "------------------------------------------------------\n";
                      Calculated_matrix resultMatrix = normalMatrix_1_;
                      do {
                        cout << "Please enter the matrix for subtraction (same size as the initial one):\n";
                        Calculated_matrix normalMatrix_2(row, col);
                        normalMatrix_2.enterMatrix();

                        cout << "\nYour additionally entered matrix:\n";
                        normalMatrix_2.printMatrix();

                        resultMatrix = resultMatrix.subtractMatrix(resultMatrix.getMatrix(), normalMatrix_2.getMatrix());

                        cout << "------------------------------------------------------\n";
                        cout << "Do you want to add more matrices? (y/n): ";
                        cin >> add_more;
                      } while (add_more == 'y' || add_more == 'Y');
                      cout << "\n------------------------------------------------------\n";
                      cout << "Final result after addition:\n";
                      resultMatrix.printMatrix();
                      break;
                    } 
                    else {
                      cout << "------------------------------------------------------\n";
                      cout << "Invalid selection, please choose again!\n";
                      continue;
                    }
                  }
                  cout << "------------------------------------------------------\n";
                  cout << "\nDo you want to continue? (y/n): "; cin >> cont;
                  if (cont == 'n' || cont == 'N') {
                    cout << "------------------------------------------------------\n";
                    cout << "Thanks for your experience, goodbye!\n";
                   exit(0);
                  } 
                  else {
                    break;
                  }
                }
                case 7: {
                  cout << "------------------------------------------------------\n";
                  cout << "You have chosen Multiplying 2 or more matrices!\n";
                  cout << "\nYOU HAVE TO KHOW THAT THE QUANTITY OF ROWS OF THE FOLLOWING MATRIX "
                      << "MUST BE SAME AS THE QUANTITY OF COLS OF THE FIRST MATRIX!\n";
                  Calculated_matrix matrix_1 = normalMatrix_1_;
                  Calculated_matrix resultMatrix = matrix_1;
                  do {
                    while (true) {
                      cout << "------------------------------------------------------\n";
                      cout << "Enter the row of the next matrix to multiply (row1 > 0): "; cin >> row1;
                      cout << "Enter the col of the next matrix to multiply (col1 > 0): "; cin >> col1;
                      if (row1 <= 0 || col1 <= 0) {
                        cout << "-------------------------------------------------------------------\n";
                        cerr << "Your matrix has an invalid size (row & col must be positive value)!\n";
                        cerr << "Please enter again!\n";
                        continue;
                      } 
                      else if (matrix_1.getCol() != row1) {
                        cout << "------------------------------------------------------\n";
                        cerr << "Matrix multiplication is not possible, please enter the row and col again!\n";
                        continue;
                      }  
                      else {
                        break;
                      }
                    }
                    Calculated_matrix matrix_2(row1, col1);
                    cout << "Please enter the matrix for multiplication:\n";
                    matrix_2.enterMatrix();
                    cout << "\nYour additionally entered matrix:\n";
                    matrix_2.printMatrix();
                    resultMatrix = resultMatrix.multiplyMatrix(matrix_1.getMatrix(), matrix_2.getMatrix());
                    matrix_1 = resultMatrix;
                    cout << "------------------------------------------------------\n";
                    cout << "Do you want to multiply with another matrix? (y/n): "; cin >> multiply_more;
                  } while (multiply_more == 'y' || multiply_more == 'Y');
                  cout << "------------------------------------------------------\n";
                  cout << "Final result after multiplication:\n";
                  resultMatrix.printMatrix();

                  cout << "------------------------------------------------------\n";
                  cout << "\nDo you want to continue? (y/n): "; cin >> cont;
                  if (cont == 'n' || cont == 'N') {
                    cout << "------------------------------------------------------\n";
                    cout << "Thanks for your experience, goodbye!\n";
                    exit(0);
                  } 
                  else {
                    break;
                  }
                }
                case 8: {
                  cout << "------------------------------------------------------\n";
                  cout << "Sorry, Matrix power is not available for normal matrix...\n";
                  continue;
                }
                case 9: {
                  cout << "------------------------------------------------------\n";
                  cout << "Sorry, Invertible matrix is not available for normal matrix...\n";
                  continue;
                }
                case 0: {
                  cout << "------------------------------------------------------\n";
                  cout << "Thanks for your experience, goodbye!\n";
                  exit(0);
                }
                default: {
                  cout << "------------------------------------------------------\n";
                  cout << "Invalid selection, please choose again!\n";
                  continue;
                }
              }
              break;
            }
            break;
          }
          case 'B':
          case 'b': {
            cout << "------------------------------------------------------\n";
            cout << "OK, it is a square matrix\n";
            cout << "PLEASE NOTICE THAT WE ARE ONLY DEVELOPING RANK 2, 3 and 4 MATRICES!\n";
            while (1) {
              cout << "Enter the size of the square matrix (n x n): "; cin >> n;
              row = col = n;
              switch (n) {
                case 2: {
                  cout << "------------------------------------------------------\n";
                  cout << "OK, let enter the elements of your matrix!\n";
                  break;
                }
                case 3: {
                  cout << "------------------------------------------------------\n";
                  cout << "OK, let enter the elements of your matrix!\n";
                  break;
                }
                case 4: {
                  cout << "------------------------------------------------------\n";
                  cout << "OK, let enter the elements of your matrix!\n";
                  break;
                }
                default: {
                  cout << "------------------------------------------------------\n";
                  cout << "You have chosen an unavailable rank of matrix!\n";
                  cout << "Please choose again!\n";
                  continue;
                }
              }
              break;
            }

            Matrix squareMatrix1(row, col);
            Matrix_methods squareMatrix_1(row, col);
            Calculated_matrix squareMatrix_1_(row, col);
            Matrix randomMatrix(row, col);

            while (1) {
              cout << "Do you want to generate the matrix randomly? (y/n): "; cin >> random;
              if (random == 'Y' || random == 'y') {
                cout << "------------------------------------------------------\n";
                cout << "You have chosen generating the matrix randomly!\n";
                randomMatrix = squareMatrix1.generateMatrix(squareMatrix1.getMatrix());
                cout << "\nHere is your random matrix: \n";
                randomMatrix.printMatrix();
                squareMatrix_1.setMatrix(randomMatrix.getMatrix());
                squareMatrix_1_.setMatrix(randomMatrix.getMatrix());
                break;
              } 
              else if (random == 'N' || random == 'n') {
                squareMatrix1.enterMatrix();
                cout << "Your entered matrix: \n";
                squareMatrix1.printMatrix();
                squareMatrix_1.setMatrix(squareMatrix1.getMatrix());
                squareMatrix_1_.setMatrix(squareMatrix1.getMatrix());
                break;
              } 
              else {
                cerr << "Invalid selection, please choose again!\n";
                continue;
              }
            }
            while (true) {
              cout << "------------------------------------------------------\n";
              cout << "What will we do next?: "; cin >> optB;
              switch (optB) {
                case 1: {
                  cout << "------------------------------------------------------\n";
                  cout << "You have already entered your matrix!\n";
                  cout << "Please choose another selection!\n";
                  continue;
                }
                case 2: {
                  cout << "------------------------------------------------------\n";
                  cout << "You have choose Transposing matrix!\n";
                  Matrix_methods transposed_matrix = squareMatrix_1.transposeMatrix(squareMatrix_1.getMatrix());
                  cout << "Here is your matrix after transposed: \n";
                  transposed_matrix.printMatrix();
                  cout << "------------------------------------------------------\n";
                  cout << "\nDo you want to continue? (y/n): "; cin >> cont;
                  if (cont == 'n' || cont == 'N') {
                    cout << "------------------------------------------------------\n";
                    cout << "Thanks for your experience, goodbye!\n";
                    exit(0);
                  } 
                  else {
                    break;
                  }
                }
                case 3: {
                  cout << "------------------------------------------------------\n";
                  cout << "You have chosen Flattening matrix!\n";
                  if (random == 'Y' || random == 'y') {
                    oneDimension array1(randomMatrix);
                    array1.flatten();
                    cout << "\nHere is your matrix after flattened: \n";
                    array1.printArray();
                  } 
                  else if (random == 'N' || random == 'n') {
                    oneDimension array1(squareMatrix1);
                    array1.flatten();
                    cout << "\nHere is your matrix after flattened: \n";
                    array1.printArray();
                  }
                  cout << "------------------------------------------------------\n";
                  cout << "\nDo you want to continue? (y/n): "; cin >> cont;
                  if (cont == 'n' || cont == 'N') {
                    cout << "------------------------------------------------------\n";
                    cout << "Thanks for your experience, goodbye!\n";
                    exit(0);
                  } 
                  else {
                    break;
                  }
                }
                case 4: {
                  cout << "------------------------------------------------------\n";
                  cout << "You have chosen calculating det of matrix!\n";
                  det = 0;
                  if (n == 2) {
                    det = squareMatrix_1.getDeterminant();
                    cout << "\nYour 2x2 matrix's det = " << det << endl;
                  } 
                  else if (n == 3) {
                    det = squareMatrix_1.getDeterminant();
                    cout << "\nYour 3x3 matrix's det = " << det << endl;
                  } 
                  else if (n == 4) {
                    cout << "Sorry, it will coming soon!\n";
                  }
                  cout << "------------------------------------------------------\n";
                  cout << "\nDo you want to continue? (y/n): "; cin >> cont;
                  if (cont == 'n' || cont == 'N') {
                    cout << "------------------------------------------------------\n";
                    cout << "Thanks for your experience, goodbye!\n";
                    exit(0);
                  } 
                  else {
                    break;
                  }
                }
                case 5: {
                  cout << "------------------------------------------------------\n";
                  cout << "You have chosen calculating trace of matrix!\n";
                  trace = 0;
                  trace = squareMatrix_1.getTrace();
                  cout << "\nYour matrix's trace = " << trace << endl;
                  cout << "------------------------------------------------------\n";
                  cout << "\nDo you want to continue? (y/n): "; cin >> cont;
                  if (cont == 'n' || cont == 'N') {
                    cout << "------------------------------------------------------\n";
                    cout << "Thanks for your experience, goodbye!\n";
                    exit(0);
                  } 
                  else {
                    break;
                  }
                }
                case 6: {
                  cout << "------------------------------------------------------\n";
                  cout << "You have chosen Adding or Subtracting matrices!\n";
                  while (1) {
                    cout << "Choose one method (+ / -): "; cin >> sign;
                    if (sign == '+') {
                      cout << "------------------------------------------------------\n";
                      Calculated_matrix resultMatrix = squareMatrix_1_;
                      do {
                        cout << "Please enter the matrix for addition (same size as the initial one):\n";
                        Calculated_matrix squareMatrix_2(row, col);
                        squareMatrix_2.enterMatrix();

                        cout << "\nYour additionally entered matrix:\n";
                        squareMatrix_2.printMatrix();

                        resultMatrix = resultMatrix.addMatrix(resultMatrix.getMatrix(), squareMatrix_2.getMatrix());

                        cout << "------------------------------------------------------\n";
                        cout << "Do you want to add more matrices? (y/n): "; cin >> add_more;
                      } while (add_more == 'y' || add_more == 'Y');
                      cout << "\n------------------------------------------------------\n";
                      cout << "Final result after addition:\n";
                      resultMatrix.printMatrix();
                      break;
                    } 
                    else if (sign == '-') {
                      cout << "------------------------------------------------------\n";
                      Calculated_matrix resultMatrix = squareMatrix_1_;
                      do {
                        cout << "Please enter the matrix for subtraction (same size as the initial one):\n";
                        Calculated_matrix squareMatrix_2(row, col);
                        squareMatrix_2.enterMatrix();

                        cout << "\nYour additionally entered matrix:\n";
                        squareMatrix_2.printMatrix();

                        resultMatrix = resultMatrix.subtractMatrix(resultMatrix.getMatrix(), squareMatrix_2.getMatrix());

                        cout << "------------------------------------------------------\n";
                        cout << "Do you want to add more matrices? (y/n): "; cin >> add_more;
                      } while (add_more == 'y' || add_more == 'Y');
                      cout << "\n------------------------------------------------------\n";
                      cout << "Final result after addition:\n";
                      resultMatrix.printMatrix();
                      break;
                    } 
                    else {
                      cout << "------------------------------------------------------\n";
                      cout << "Invalid selection, please choose again!\n";
                      continue;
                    }
                  }
                  cout << "------------------------------------------------------\n";
                  cout << "\nDo you want to continue? (y/n): "; cin >> cont;
                  if (cont == 'n' || cont == 'N') {
                    cout << "------------------------------------------------------\n";
                    cout << "Thanks for your experience, goodbye!\n";
                    exit(0);
                  } 
                  else {
                    break;
                  }
                }
                case 7: {
                  cout << "------------------------------------------------------\n";
                  cout << "You have chosen Multiplying 2 or more matrices!\n";
                  cout << "\nYOU HAVE TO KHOW THAT THE QUANTITY OF ROWS OF THE FOLLOWING MATRIX "
                      << "MUST BE SAME AS THE QUANTITY OF COLS OF THE FIRST MATRIX!\n";
                  Calculated_matrix matrix_1 = squareMatrix_1_;
                  Calculated_matrix resultMatrix = matrix_1;
                  do {
                    while (true) {
                      cout << "------------------------------------------------------\n";
                      cout << "Enter the row of the next matrix to multiply (row1 > 0): "; cin >> row1;
                      cout << "Enter the col of the next matrix to multiply (col1 > 0): "; cin >> col1;
                      if (row1 <= 0 || col1 <= 0) {
                        cout << "-------------------------------------------------------------------\n";
                        cerr << "Your matrix has an invalid size (row & col must be positive value)!\n";
                        cerr << "Please enter again!\n";
                        continue;
                      } 
                      else if (matrix_1.getCol() != row1) {
                        cout << "------------------------------------------------------\n";
                        cerr << "Matrix multiplication is not possible, please enter the row and col again!\n";
                        continue;
                      } 
                      else {
                        break;
                      }
                    }
                    Calculated_matrix matrix_2(row1, col1);
                    cout << "Please enter the matrix for multiplication:\n";
                    matrix_2.enterMatrix();
                    cout << "\nYour additionally entered matrix:\n";
                    matrix_2.printMatrix();
                    resultMatrix = resultMatrix.multiplyMatrix(matrix_1.getMatrix(), matrix_2.getMatrix());
                    matrix_1 = resultMatrix;
                    cout << "------------------------------------------------------\n";
                    cout << "Do you want to multiply with another matrix? (y/n): "; cin >> multiply_more;
                  } while (multiply_more == 'y' || multiply_more == 'Y');
                  cout << "------------------------------------------------------\n";
                  cout << "Final result after multiplication:\n";
                  resultMatrix.printMatrix();

                  cout << "------------------------------------------------------\n";
                  cout << "\nDo you want to continue? (y/n): "; cin >> cont;
                  if (cont == 'n' || cont == 'N') {
                    cout << "------------------------------------------------------\n";
                    cout << "Thanks for your experience, goodbye!\n";
                    exit(0);
                  } 
                  else {
                    break;
                  }
                }
                case 8: {
                  cout << "------------------------------------------------------\n";
                  cout << "You have chosen Powering matrix!\n";
                  while (1) {
                    cout << "Enter the exponential value you want to power your matrix (power >= 0): "; cin >> power;
                    if (power < 0) {
                      cerr << "Invalid value, please enter again!\n";
                      continue;
                    } 
                    else {
                      break;
                    }
                  }
                  Calculated_matrix matrix_1 = squareMatrix_1_;
                  Calculated_matrix resultMatrix = matrix_1;
                  resultMatrix = resultMatrix.powerMatrix(matrix_1, power);
                  cout << "------------------------------------------------------\n";
                  cout << "Your matrix raised to power " << power << " is:\n";
                  resultMatrix.printMatrix();

                  cout << "------------------------------------------------------\n";
                  cout << "\nDo you want to continue? (y/n): "; cin >> cont;
                  if (cont == 'n' || cont == 'N') {
                    cout << "------------------------------------------------------\n";
                    cout << "Thanks for your experience, goodbye!\n";
                    exit(0);
                  } 
                  else {
                    break;
                  }
                }
                case 9: {
                  cout << "------------------------------------------------------\n";
                  cout << "You have chosen to calculate the inverse matrix!\n";
                  cout << "------------------------------------------------------\n";
                  if (n == 2) {
                    Calculated_matrix resultMatrix(row, col);
                    vector<vector<double>> m;
                    m = squareMatrix_1_.getMatrix();
                    resultMatrix = resultMatrix.inverseMatrix(m);
                    m = resultMatrix.getMatrix();
                    if (!(m.empty())) {
                      cout << "------------------------------------------------------\n";
                      cout << "Your inverse matrix is:\n";
                      resultMatrix.printMatrix();
                    }
                  } 
                  else if (n == 3) {
                    Calculated_matrix resultMatrix(row, col);
                    vector<vector<double>> m;
                    m = squareMatrix_1_.getMatrix();
                    resultMatrix = resultMatrix.inverseMatrix(m);
                    m = resultMatrix.getMatrix();
                    if (!(m.empty())) {
                      cout << "------------------------------------------------------\n";
                      cout << "Your inverse matrix is:\n";
                      resultMatrix.printMatrix();
                    }
                  }
                  cout << "------------------------------------------------------\n";
                  cout << "\nDo you want to continue? (y/n): "; cin >> cont;
                  if (cont == 'n' || cont == 'N') {
                    cout << "------------------------------------------------------\n";
                    cout << "Thanks for your experience, goodbye!\n";
                    exit(0);
                  } 
                  else {
                    break;
                  }
                }
                case 0: {
                  cout << "------------------------------------------------------\n";
                  cout << "Thanks for your experience, goodbye!\n";
                  exit(0);
                }
                default: {
                  cout << "------------------------------------------------------\n";
                  cout << "Invalid selection, please choose again!\n";
                  continue;
                }
              }
              break;
            }
            break;
          }
          default: {
            cout << "------------------------------------------------------\n";
            cout << "Sorry, i can't identify your matrix...\n";
            cout << "Let check your matrix again!\n";
            continue;
          }
        }
      }
    } 
    else if (opt == 10) {
      cout << "------------------------------------------------------\n";
      cout << "You have chosen Encrypting and Decrypting the matrix!\n";
      cout << "We would like to notice you that we do not encrypt or decrypt any capital letters so we will transform"
          << "your message to the non-capital message!\n"; 
      Matrix_methods detMatrix;

      Calculated_matrix productMatrix;
      Calculated_matrix inversionMatrix;

      En_Decryption encryptMatrix;
      En_Decryption decryptMatrix;
      En_Decryption keyMatrix;
      En_Decryption demoMatrix;
      En_Decryption processArray_1;

      vector<int> numArray;
      vector<int> encrytpedArray;
      vector<int> decrytpedArray;

      vector<vector<int>> key;
      vector<vector<int>> inverse_key;
      vector<vector<int>> demo;
      vector<vector<int>> encrypt;
      vector<vector<int>> decrypt;
      vector<vector<int>> product;
      
      while(1){
        cout << "\nWhich one do you choose, Encrypt or Decrypt (e/d)?: "; cin >> opt10;
        if (opt10 == 'e' || opt10 == 'E') {
          cout << "------------------------------------------------------\n";
          cout << "You have chosen Encrypting!\n";
          cout << endl;
          cout << "Enter your message: ";
          cin.ignore();
          getline(cin, message);
          message = toLowerString(message);
          cout << "------------------------------------------------------\n";
          cout << "Your entered message is: " << message << endl;
          cout << "------------------------------------------------------\n";
          // Convert message to numeric array
          processArray_1.setMessage(message);
          processArray_1 = processArray_1.numStorage(message);
          numArray = processArray_1.getArray_int();

          // Calculate blockCol based on message length
          blockCol = (numArray.size() + blockRow - 1) / blockRow; // Ceiling division

          // Convert numeric array to matrix
          encryptMatrix = encryptMatrix.vectorToMatrix_1(numArray, blockRow, blockCol);
          cout << "Here is your encrypted matrix: \n";
          encryptMatrix.printMatrix_int();
          cout << endl;

          cout << "Now, we choose the Key matrix (It must be square and invertible)\n";
          cout << "Do you have any difficulties in choosing the key matrix (y/n)?: "; cin >> help;
          if (help == 'y' || help == 'Y') {
            cout << "------------------------------------------------------\n";
            cout << "We will help you choose one!\n";
            cout << "Here it is, please keep it secret: \n";
            keyMatrix = keyMatrix.generateInvertibleKeyMatrix_1(blockRow3x3, mod);
            keyMatrix.printMatrix_int();
            key = keyMatrix.getMatrix_int();
            cout << endl;
          } 
          else {
            cout << "------------------------------------------------------\n";
            cout << "Enter the key matrix (" << blockRow << "x" << blockRow << "): \n";
            while (true) {
              keyMatrix = En_Decryption(blockRow3x3, blockRow3x3);
              keyMatrix.enterMatrix_int();
              key = keyMatrix.getMatrix_int();
              cout << endl;

              detMatrix.setMatrix(key);
              det1 = detMatrix.getDeterminant_int();
        
              int rank = matrixRank(key, blockRow, blockRow);
        
              bool detValid = isModularInvertible(det1, mod);
              bool rankValid = (rank == 3);

              if (detValid && rankValid) {
                cout << "------------------------------------------------------\n";
                cout << "Your entered key matrix is valid, here it is: \n";
                keyMatrix.printMatrix_int();
                cout << endl;
                break;
              } 
              else {
                cout << "------------------------------------------------------\n";
                cout << "Your entered key matrix is invalid, please choose another one... \n";
                cout << "We will show you a reference matrix that is valid, you can copy it! \n";
                cout << endl;
                cout << "Here it is: \n";
                demoMatrix = demoMatrix.exampleKeyMatrix(demo);
                demoMatrix.printMatrix_int();
                cout << endl;
                cout << "Enter the key matrix again: \n";
                continue;
              }
            }
          }
          cout << "We are encrypting your message, please wait for a minute...\n";
          cout << "------------------------------------------------------";
          key = keyMatrix.getMatrix_int();
          encrypt = encryptMatrix.getMatrix_int();
          // Perform matrix multiplication
          Calculated_matrix tempMatrix;
          productMatrix = tempMatrix.multiplyMatrix(key, encrypt);
          product = productMatrix.getMatrix_int();      

          // Apply modulo operation
          for (int i = 0; i < product.size(); i++) {
            for (int j = 0; j < product[0].size(); j++) {
              int original = product[i][j];
              product[i][j] = product[i][j] % mod;
              if (product[i][j] < 0) {
                product[i][j] += mod;
              }           
            }
          }
          // Store in productMatrix
          productMatrix.setMatrix(product);
          // Flatten the result and debug
          Matrix_methods transpMatrix;
          transpMatrix = transpMatrix.transposeMatrix(product);
          product = transpMatrix.getMatrix_int();
          
          oneDimension flattened(product.size(), product[0].size());
          flattened.setMatrix(product);
          flattened.flatten_int();
          encrytpedArray = flattened.getArray_int();
          encryptedString = "";
          En_Decryption encryptedMessage;
          encryptedString = encryptedMessage.convertToEncryptedMessage(encrytpedArray);
          cout << "Your encrypted message is: " << encryptedString << endl;
          // Show the user the key matrix for decryption later
          cout << "------------------------------------------------------\n";
          cout << "REMEMBER THIS KEY MATRIX FOR DECRYPTION:\n";
          keyMatrix.printMatrix_int();
          cout << "------------------------------------------------------\n";
          break;
        } 
        else if (opt10 == 'd' || opt10 == 'D') {
          cout << "------------------------------------------------------\n";
          cout << "You have chosen Decrypting!\n";
          cout << endl;
          cout << "Enter your encrypted message: ";
          cin.ignore();
          getline(cin, message);
          message = toLowerString(message);
          cout << "------------------------------------------------------\n";
          cout << "Your entered message is: " << message << endl;
          cout << "------------------------------------------------------\n";
          // Convert message to numeric array
          processArray_1.setMessage(message);
          processArray_1 = processArray_1.numStorage(message);
          numArray = processArray_1.getArray_int();

          // Calculate blockCol based on message length
          blockCol = (numArray.size() + blockRow - 1) / blockRow; // Ceiling division

          // Convert numeric array to matrix
          decryptMatrix = decryptMatrix.vectorToMatrix_1(numArray, blockRow, blockCol);

          cout << "Unless you select the same key matrix that you used to encrypt the message,"
              << " you can not properly get the original message.\n";
          cout << "------------------------------------------------------\n";
          cout << "Enter the used key matrix (" << blockRow << "x" << blockRow << "): \n";
          while (true) {
            keyMatrix = En_Decryption(blockRow3x3, blockRow3x3);
            keyMatrix.enterMatrix_int();
            key = keyMatrix.getMatrix_int();
            cout << endl;

            detMatrix.setMatrix(key);
            det1 = detMatrix.getDeterminant_int();
          
            int rank = matrixRank(key, blockRow, blockRow);
          
            bool detValid = isModularInvertible(det1, mod);
            bool rankValid = (rank == 3);

            if (detValid && rankValid) {
              cout << "------------------------------------------------------\n";
              cout << "Your entered key matrix is valid, here it is: \n";
              keyMatrix.printMatrix_int();
              cout << endl;
              break;
            } 
            else {
              cout << "------------------------------------------------------\n";
              cout << "Your entered key matrix is invalid!\n";
              cout << "You have to enter the key matrix that you used to encrypt your message.\n";
              cout << endl;
              cout << endl;
              cout << "Enter the used key matrix again: \n";
              continue;
            }
          }
          cout << "We are decrypting your message, please wait for a minute...\n";
          cout << "------------------------------------------------------";
          key = keyMatrix.getMatrix_int();
          decrypt = decryptMatrix.getMatrix_int();


          // Inverse the key matrix
          inversionMatrix = inversionMatrix.inverseMatrix(key);
          inverse_key = inversionMatrix.getMatrix_int();

          // Apply mod to inverse key
          for (int i = 0; i < inverse_key.size(); i++) {
            for (int j = 0; j < inverse_key[0].size(); j++) {
              inverse_key[i][j] = (inverse_key[i][j] % 27 + 27) % 27;
            }
          }

          // Perform matrix multiplication
          Calculated_matrix tempMatrix;
          productMatrix = tempMatrix.multiplyMatrix(inverse_key, decrypt);
          product = productMatrix.getMatrix_int();      

          // Apply modulo operation
          for (int i = 0; i < product.size(); i++) {
            for (int j = 0; j < product[0].size(); j++) {
              int original = product[i][j];
              product[i][j] = product[i][j] % mod;
              if (product[i][j] < 0) {
                product[i][j] += mod;
              }           
            }
          }

          // Store in productMatrix
          productMatrix.setMatrix(product);
          
          // Flatten the result
          Matrix_methods transpMatrix;
          transpMatrix = transpMatrix.transposeMatrix(product);
          product = transpMatrix.getMatrix_int();
          
          oneDimension flattened(product.size(), product[0].size());
          flattened.setMatrix(product);
          flattened.flatten_int();
          decrytpedArray = flattened.getArray_int();
          decryptedString = "";
          En_Decryption decryptedMessage;
          decryptedString = decryptedMessage.convertToDecryptedMessage(decrytpedArray);
          cout << "Your decrypted message is: " << decryptedString << endl;
          break;
        }
        else{
          cout << "------------------------------------------------------\n";
          cout << "Invalid selection, please choose again!\n";
          continue;
        }
      }
      cout << "------------------------------------------------------\n";
      cout << "\nDo you want to continue? (y/n): ";
      cin >> cont;
      if (cont == 'n' || cont == 'N') {
        cout << "Thanks for your experience, goodbye!\n";
        exit(0);
      }
      else{
        continue;
      }
    } 
    else if (opt == 0) {
      cout << "------------------------------------------------------\n";
      cout << "Thanks for your experience, goodbye!\n";
      break;
    } 
    else {
      cout << "------------------------------------------------------\n";
      cout << "You have to enter the matrix first!\n";
      continue;
    }
  }

  // default code (Do not change)
  return 0;
}