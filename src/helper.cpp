#include "helper.h"

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~OTHER_FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

int gcd(int a, int b) {
  if (b == 0) {
    return abs(a);
  }
  return gcd(b, a % b);
}

void printMenu() {
  cout << "--------------------------MENU------------------------\n";
  cout << "1.  Enter Matrix (A. Normal matrix || B. Square matrix)\n";
  cout << "Here are some selections for you to address your demand about matrix.\n";
  cout << "-------------------------------------------------------------------\n";
  cout << "2.  Tranposed Matrix\n";
  cout << "3.  Flattened Matrix\n";
  cout << "4.  Calculate Det (for square matrix)\n";
  cout << "5.  Calculate Trace (for square matrix)\n";
  cout << "6.  Matrix Addition or Subtraction (for matrices in the same size)\n";
  cout << "7.  Matrix Multiplication (only for right order)\n";
  cout << "8.  Matrix Power (for square matrix)\n";
  cout << "9.  Invertible Matrix (for square matrix)\n";
  cout << "10. Encryption & Decryption\n";
  cout << "0.  Quit project\n";
}

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return 1; // Should not happen for valid keys
}

// Debug function to print matrices
void debugPrintMatrices(const vector<vector<int>> &key, const vector<vector<int>> &message, const vector<vector<int>> &product) {
  cout << "=== DEBUG MATRIX MULTIPLICATION ===" << endl;
  cout << "Key Matrix (" << key.size() << "x" << key[0].size() << "):" << endl;
  for (const auto &row : key) {
    for (int val : row)
      cout << setw(4) << val << " ";
    cout << endl;
  }
  cout << "Message Matrix (" << message.size() << "x" << message[0].size()
       << "):" << endl;
  for (const auto &row : message) {
    for (int val : row)
      cout << setw(4) << val << " ";
    cout << endl;
  }
  cout << "Product Matrix (" << product.size() << "x" << product[0].size()
       << "):" << endl;
  for (const auto &row : product) {
    for (int val : row)
      cout << setw(4) << val << " ";
    cout << endl;
  }
  cout << "===================================" << endl;
}