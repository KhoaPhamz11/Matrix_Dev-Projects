#include "main.h"

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~OTHER_FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void swap(int &a, int &b);

int gcd(int a, int b);

void printMenu();

int modInverse(int a, int m);

// Debug function to print matrices
void debugPrintMatrices(const vector<vector<int>> &key, const vector<vector<int>> &message, const vector<vector<int>> &product);

string toLowerString(const string &str);

int matrixRank(vector<vector<int>> matrix, int rows, int cols);

bool isModularInvertible(int det, int mod);