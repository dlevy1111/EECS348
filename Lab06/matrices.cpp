#include <iostream>
#include <fstream>

using namespace std;

/*Lab 6*/

/*This function reads the matrices in*/
void input_matrix(int &size, int matrixA[100][100], int matrixB[100][100]){
    
    std::ifstream inFile;
    inFile.open("matrices.txt");

    inFile >> size;

    for(int m = 0; m < 2; m++){ // looping over the matrices
        for(int i = 0; i < size; i++){ // looping over rows
            for(int j = 0; j < size; j++){ // looping over columns
                if(m == 0){
                    inFile >> matrixA[i][j];
                }
                if(m == 1){
                    inFile >> matrixB[i][j];
                }
            }
        }
    }
    inFile.close();
}

/*This function prints matrices*/
void print_matrix(int size, int matrixA[100][100], int matrixB[100][100]){
    std::cout << "\nMatrix A:\n";
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            std::cout << matrixA[i][j] << " ";
        }
        std::cout  << std::endl;
    }
    std::cout << "\nMatrix B:\n";
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            std::cout << matrixB[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

/*This function adds the two matrices*/
void add_matrices(int size, int matrixA[100][100], int matrixB[100][100]){
    int matrixC[100][100];
    std::cout << "\nMatrix Sum (A + B):\n";
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
            std::cout << matrixC[i][j] << " ";
        }
        std::cout  << std::endl;
    }
}

/*This function multiplies the two matrices*/
void multiply_matrices(int size, int matrixA[100][100], int matrixB[100][100]){
    int matrixC[100][100];
    std::cout << "\nMatrix Product (A * B):\n";
    for(int i = 0; i < size; i++){ // looping over c's rows
        for(int j = 0; j < size; j++){ // looping over c's columns
	          matrixC[i][j] = 0;
	          for(int m = 0; m < size; m++){ // looping over a and b's rows
	              matrixC[i][j] += matrixA[i][m] * matrixB[m][j];
            }
	          std::cout << matrixC[i][j] << " ";
	      }
	      std::cout << endl;
    }
}

/*This function subtracts the two matrices*/
void subtract_matrices(int size, int matrixA[100][100], int matrixB[100][100]){
    int matrixC[100][100];
    std::cout << "\nMatrix Difference (A - B):\n";
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            matrixC[i][j] = matrixA[i][j] - matrixB[i][j];
            std::cout << matrixC[i][j] << " ";
        }
        std::cout  << std::endl;
    }
}

/*Main function*/
int main()
{
    /*File I/O*/
    int size = 0;
    int matrixA[100][100];
    int matrixB[100][100];
    input_matrix(size, matrixA, matrixB);

    // std::cout << "Size = " << size << "\n";

    std::cout << "David Levy\nLab #6: Matrix Manipulation\n";
    print_matrix(size, matrixA, matrixB);
    add_matrices(size, matrixA, matrixB);
    multiply_matrices(size, matrixA, matrixB);
    subtract_matrices(size, matrixA, matrixB);

    return 0;
}
