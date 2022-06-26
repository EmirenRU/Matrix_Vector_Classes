#include <iostream>
#include "vectmatfunc.h"
#include <stdlib.h>
#include <time.h>
#define MAXIMUM 1
using namespace std;

int main(){

    // srand(time(NULL));

    int dim;
    cout << "Enter the length of Vectors and Matrices: ";
    cin >> dim;

    // dim = rand()%3+2;

    // x = B;

    double *vector = new double[dim];
    double *matrix = new double[dim * dim];

    Vector *array_of_vectors = new Vector[MAXIMUM];
    Matrix *array_of_matrices = new Matrix[MAXIMUM];
    int select_first;
    int select_second;
    double multiplier;
    int index;

    int command = 1;
    int count_vectors;
    int count_matrices;


    for (int i = 0; i < MAXIMUM; i++)
    {
        // vector = new double[dim];
        // matrix = new double[dim * dim];

        for (int j = 0; j < dim; j++)
        {
            // vector[j] = rand()%10;
            cout << "Enter number with index " << j+1 << ": ";
            cin >> vector[j];
            cout << endl;
        }

        array_of_vectors[i] = Vector(dim, vector);
        array_of_vectors[i].print();

        cout << endl;

        for (int j = 0; j < dim * dim; j++){
            cout << "Enter number with index " << j+1 << ": ";
            cin >> matrix[j];
            cout << endl;
        }

        array_of_matrices[i] = Matrix(dim, matrix);
        array_of_matrices[i].print();

        cout << endl;
    }
    while (command != 0)
    {
        cout<<"list of commands: "<<endl;
        cout<<"Type 1 to print all vectors"<<endl;
        cout<<"Type 2 to print all matrices"<<endl;
        cout<<"Type 3 to assign vector"<<endl;
        cout<<"Type 4 to sum vectors"<<endl;
        cout<<"Type 5 to subtract vectors"<<endl;
        cout<<"Type 6 to multiply vector and constant"<<endl;
        cout<<"Type 7 to multiply vectors"<<endl;
        cout<<"Type 8 to unary minus vector"<<endl;
        cout<<"Type 9 to print element of vector by index"<<endl;
        cout<<"Type 10 to assign matrix"<<endl;
        cout<<"Type 11 to sum matrices"<<endl;
        cout<<"Type 12 to substract matrices"<<endl;
        cout<<"Type 13 to unary minus matrices"<<endl;
        cout<<"Type 14 to multiply matrix and constant"<<endl;
        cout<<"Type 15 to multiply matrices"<<endl;
        cout<<"Type 16 to multiply matrix and vector"<<endl;
        cout<<"Type 17 to print element of matrix by index"<<endl;


        cout << "Enter the number: ";
        cin >> command;
        switch (command)
        {
            case 1:
                for (int i = 0; i < MAXIMUM; i++){
                    cout << array_of_vectors[i].num << "vector: ";
                    array_of_vectors[i].print();
                }
                break;
            case 2:
                for (int i = 0; i < MAXIMUM; i++){
                    cout << array_of_matrices[i].num << "vector: ";
                    array_of_matrices[i].print();
                }
                break;
            case 3:
                cout << "Type the number of vector you want to replace: ";
                cin >> select_first;
                cout << "Type the number of vector you want to use: ";
                cin >> select_second;
                array_of_vectors[select_first - 1] = array_of_vectors[select_second - 1];
                break;
            case 4:
                cout << "Type the number of first vector: ";
                cin >> select_first;
                cout << "Type the number of second vector: ";
                cin >> select_second;
                (array_of_vectors[select_first-1] + array_of_vectors[select_second-1]).print();
            case 5:
                cout << "Type the number of first vector: ";
                cin >> select_first;
                cout << "Type the number of second vector: ";
                cin >> select_second;
                (array_of_vectors[select_first-1] - array_of_vectors[select_second-1]).print();
            case 6:
                cout << "Type the number of first vector: ";
                cin >> select_first;
                cout << "Type the number to multiply: ";
                cin >> multiplier;
                (array_of_vectors[select_first-1] * multiplier).print();
                break;
            case 7:
                cout << "Type the number of first vector: ";
                cin >> select_first;
                cout << "Type the number of second vector: ";
                cin >> select_second;
                cout << (array_of_vectors[select_first-1] * array_of_vectors[select_second-1]);
                break;
            case 8:
                cout << "Type the number of vector: ";
                cin >> select_first;
                (-array_of_vectors[select_first-1]).print();
                break;
            case 9:
                cout << "Type the number of vector: ";
                cin >> select_first;
                cout << "Type the index of element you need to find: ";
                cin >> index;
                cout << array_of_vectors[select_first-1][index];
                break;
            case 10:
                cout << "Type the number of matrix you want to replace: ";
                cin >> select_first;
                cout << "Type the number of matrix you want to use: ";
                cin >> select_second;
                array_of_matrices[select_first-1] = array_of_matrices[select_second-1];
                array_of_matrices[select_first-1].print();
                break;
            case 11:
                cout << "Type the number of first matrix: ";
                cin >> select_first;
                cout << "Type the number of second matrix: ";
                cin >> select_second;
                (array_of_matrices[select_first-1] + array_of_matrices[select_second-1]).print();
                break;
            case 12:
                cout << "Type the number of first matrix: ";
                cin >> select_first;
                cout << "Type the number of second matrix: ";
                cin >> select_second;
                (array_of_matrices[select_first-1] - array_of_matrices[select_second-1]).print();
                break;
            case 13:
                cout << "Type the number of matrix: ";
                cin >> select_first;
                (-array_of_matrices[select_first-1]).print();
                break;
            case 14:
                cout << "Type the number of first matrix: ";
                cin >> select_first;
                cout << "Type the number to multiply: ";
                cin >> multiplier;
                (array_of_matrices[select_first-1] * multiplier).print();
            case 15:
                cout << "Type the number of first matrix: ";
                cin >> select_first;
                cout << "Type the number of second matrix: ";
                cin >> select_second;
                (array_of_matrices[select_first-1] * array_of_matrices[select_second-1]).print();
                break;
            case 16:
                cout << "Type the number of matrix: ";
                cin >> select_first;
                cout << "Type the number of vector: ";
                cin >> select_second;
                (array_of_matrices[select_first-1] * array_of_vectors[select_second-1]).print();
                break;
            case 17:
                cout << "Type the number of matrix: ";
                cin >> select_first;
                cout << "Type the index of element you need to find: ";
                cin >> index;
                cout << array_of_matrices[select_first-1][index];
                break;
        }
    }
    return 0;
}