#include <iostream>

using namespace std;
void compactMatrix(int matrix[][100], int& k, int& n) {
    
    for (int i = 0; i < k; i++) {
        bool allZeros = true;
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                allZeros = false;
                break;
            }
        }
        if (allZeros) {
            for (int x = i; x < k - 1; ++x) {
                for (int y = 0; y < n; ++y) {
                    matrix[x][y] = matrix[x + 1][y];
                }
            }
            --k;
            --i; 
        }
    }

   
    for (int j = 0; j < n; ++j) {
        bool allZeros = true;
        for (int i = 0; i < k; ++i) {
            if (matrix[i][j] != 0) {
                allZeros = false;
                break;
            }
        }
        if (allZeros) {
            for (int x = 0; x < k; ++x) {
                for (int y = j; y < n - 1; ++y) {
                    matrix[x][y] = matrix[x][y + 1];
                }
            }
            --n;
            --j; 
        }
    }
}


int findRowWithPositiveElement(const int matrix[][100], int k, int n) {
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] > 0) {
                return i + 1; 
            }
        }
    }
    return -1; 
}

int main() {
    int k, n;

   
    cout << "Введіть кількість рядків: ";
    cin >> k;
    cout << "Введіть кількість стовпців: ";
    cin >> n;

    
    int matrix[100][100];
    cout << "Введіть елементи матриці:" << std::endl;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

   
    cout << "Матриця до ущільнення:" << endl;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << ' ';
        }
          cout << endl;
    }

    
    compactMatrix(matrix, k, n);

    
    cout << "Матриця після ущільнення:" << endl;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }

    int rowWithPositiveElement = findRowWithPositiveElement(matrix, k, n);

    
    cout << "Номер першого рядка з додатнім елементом: " << rowWithPositiveElement << endl;

    return 0;
}
