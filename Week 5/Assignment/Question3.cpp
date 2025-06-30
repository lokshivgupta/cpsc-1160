#include<iostream>
using namespace std;

int main (){
    const int maxSize = 10;
    int matrix[maxSize][maxSize];
    int sumOfRows[maxSize];
    int sumOfCols[maxSize];
    int rows, cols;

    do{
        cout << "Enter the number of rows: " <<endl;
        cin >> rows;
    }while(rows < 1 || rows > 10);

    do{
        cout << "Enter the number of cols: " <<endl;
        cin >> cols;
    }while(cols < 1 || cols > 10);

    for(int j =0; j < cols; j++){
        sumOfCols[j] = 0;
    }

    for(int i = 0; i < rows; i++){
        cout << "Enter " << cols << " values for row " << (i + 1) << ": ";
        sumOfRows[i] = 0;
        for(int j =0; j < cols; j++){
            cin >> matrix[i][j];
            sumOfRows[i] += matrix[i][j];
            sumOfCols[j] += matrix[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << "| " << sumOfRows[i] << endl;
    }

    for (int j = 0; j < cols; j++) {
        cout << "--------";
    }
    cout << "\n";

    for (int j = 0; j < cols; j++) {
        cout << sumOfCols[j] << "\t";
    }
    cout << endl;

    return 0;
}