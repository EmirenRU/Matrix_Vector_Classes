#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

class Vector{
    int dim;
    double *v;
public:
    friend class Matrix;
    static int count;
    int num;
    Vector(int d, double *x);
    Vector(int d);
    Vector(const Vector &b);
    Vector();
    ~Vector();
    void set(int d, double *x);
    void print();
    Vector& operator= (const Vector &r);
    Vector operator+ (const Vector &r);
    double operator* (const Vector &r);
    Vector operator- (const Vector &r); // бинарная операция -
    Vector operator- (); // Унарная операция A = -A
    Vector operator* (const double k);
    double operator[] (int i);
    Vector invert();
    Vector abs();
};


class Matrix{
    int dim;
    double *m;
public:
    friend class Vector;
    static int count;
    int num;
    Matrix(int d, double *x);
    Matrix(int d);
    Matrix(const Matrix &x);
    Matrix();
    ~Matrix();
    void set(int d, double *x);
    void print();
    Matrix& operator= (const Matrix &r);
    Matrix operator+ (const Matrix &r);
    Matrix operator- (const Matrix &r);
    Matrix operator- ();
    Matrix operator* (const double k);
    double operator[] (const int i);
    Matrix operator* (const Matrix &r);
    Vector operator* (const Vector &r);
    Matrix diag ();
    Matrix identity (int len);
    Matrix invert ();
    Matrix above_diag();
    Matrix bellow_diag ();
};

int Vector::count=0;
int Matrix::count=0;

Vector::Vector(int d, double*x){
    cout << "Creating vector with array" << endl;
    this->dim = d;
    double *temp = new double[this->dim];
    for (int i = 0; i < this->dim; i++){
        temp[i] = x[i];
    }
    this->v = temp;
    count += 1;
    num = count;
    cout << "Creating vector " << this->num << " with array" << endl;
}

Vector::Vector(int d){
    this->dim = d;
    double *x = new double[d];
    for (int i = 0; i < this->dim; i++){
        x[i] = 0;
    }
    this->v = x;
    count++;
    num = count;
    cout << "Creating vector " << this->num << " with dim " << d << endl;
}

Vector::Vector(const Vector &b){

    double *tmp = new double[b.dim];
    for (int i = 0; i < b.dim; i++){
        tmp[i] = b.v[i];
    }
    this->dim = b.dim;
    this->v = tmp;
    count++;
    num = count;
    cout << "Copying vector " << b.num << " to new vector" << this->num << endl;
}

Vector Vector::abs (){
    for (int i=0; i<this->dim ; i++)
    {
        this->v[i]= fabs(this->v[i]);
    }

    return *this;
}

Vector::Vector(){
    cout << "Created Empty Vector." << endl;
    this->dim = 0;
    this->v = NULL;
    count++;
    num = count;
    cout << "Created Empty Vector " << this->num << endl;
}

Vector::~Vector(){
    cout << "Deleting vector " << this->num << endl;
    delete[] this->v;
}

void Vector::set(int d, double *x){
    this->dim = d;
    this->v = x;
}

void Matrix::set(int d, double *x){
    this->dim = d;
    this->m = x;
}

Vector& Vector::operator= (const Vector &r){
    double *tmp = new double[this->dim];
    cout << "Copying Vector in a new Vector" << endl;

    for (int i = 0; i < r.dim; i++){
        tmp[i] = r.v[i];
    }

    this->dim = r.dim;
    this->v = tmp;
    this->num = r.num;

    return *this;
}

Vector Vector::operator+ (const Vector &r){
    double *x = new double[r.dim];
    cout << "Vector " << this->num << " + Vector " << r.num << endl;
    for (int i = 0; i < r.dim; i++){
        x[i] = this->v[i] + r.v[i];
    }
    this->v = x;
    Vector temp = Vector(this->dim, this->v);
    return temp;
}

Vector Vector::operator* (const double k){
    double *x = new double[this->dim];
    cout << "Vector " << this->num << " * " << k << endl;
    for (int i = 0; i < this->dim; i++){
        x[i] = k * this->v[i];
    }
    Vector temp = Vector(this->dim, x);
    return temp;
}

double Vector::operator[] (int i){
    if (i <= this->dim){
        cout << this->num << " Vector's element by index" << i << endl;
        return this->v[i];
    }
}


Vector Vector::operator- (){
    double *x = new double[this->dim];
    cout << "Vector " << this->num << " * -1" << endl;
    for (int i = 0; i < this->dim; i++){
        x[i] = -1 * this->v[i];
    }
    this->v = x;
    Vector temp = Vector(this->dim, this->v);
    return temp;
}

double Vector::operator* (const Vector &r){
    double sum;
    cout << " Scalar production of Vector " << this->num << " and " << r.num << endl;
    for (int i = 0; i < r.dim; i++){
        sum += this->v[i] * r.v[i];
    }
    return sum;
}

Vector Vector::operator- (const Vector &r){
    double *x = new double[this->dim];
    cout << "Vector " << this->num << " - Vector " << r.num << endl;
    for (int i = 0; i < this->dim; i++){
        x[i] = this->v[i] - r.v[i];
    }
    Vector temp = Vector(this->dim, x);
    return temp;
}

void Vector::print(){
    cout << endl;
    cout << "Vector: ";
    for (int i = 0; i < this->dim; i++){
        cout << this->v[i] << " ";
    }
    cout << endl;
}

Matrix::Matrix(int d, double *x){

    this->dim = d;
    double *tmp = new double[this->dim * this->dim];
    for (int i = 0; i < this->dim * this->dim; i++){
        tmp[i] = x[i];
    }
    this->m = tmp;
    count++;
    this->num = count;
    cout << "Creating matrix " << this->num << "with array " << endl;
}

Matrix::Matrix(int d){

    this->dim = d;
    double *tmp = new double[this->dim*this->dim];
    for (int i = 0; i < this->dim*this->dim; i++){
        tmp[i] = 0;
    }
    this->m = tmp;
    count++;
    this->num = count;
    cout << "Creating empty matrix " << this->num << " with dim " << this->dim << endl;
}

Matrix::Matrix(const Matrix &x){
    this->dim = x.dim;
    double *tmp = new double[this->dim*this->dim];
    for (int i = 0; i < this->dim * this->dim; i++){
        tmp[i] = x.m[i];
    }
    this->m = tmp;
    count++;
    this->num = count;
    cout << "Copying matrix " << x.num << " to new matrix " << this->num << endl;
}

Matrix::Matrix(){
    this->dim = 0;
    this->m = NULL;
    count++;
    this->num = count;
    cout << "Creating new matrix " << this->num << endl;
}

Matrix::~Matrix(){
    cout << "Deleting matrix " << this->num << endl;
    delete[] this->m;
}

Matrix& Matrix::operator=(const Matrix &r){
    double *tmp = new double[r.dim*r.dim];
    cout << "Copying Matrix in new Matrix" << endl;
    for (int i = 0; i < r.dim*r.dim; i++){
        tmp[i] = r.m[i];
    }
    this->dim = r.dim;
    this->m = tmp;
    this->num = r.num;

    return *this;
}

Vector Vector::invert(){
    double *tmp = new double[dim];
    for (int i = 0; i < dim; i++){
        tmp[i] = 1 / this->v[i];
    }
    return Vector(dim, tmp);
}

Matrix Matrix::operator+ (const Matrix &r){
    double *tmp = new double[this->dim*this->dim];
    cout << "Matrix " << this->num << " + Matrix " << r.num << endl;
    for (int i = 0; i < this->dim*this->dim; i++){
        tmp[i] = this->m[i] + r.m[i];
    }
    return Matrix(this->dim, tmp);
}

Matrix Matrix::operator- (const Matrix &r){
    double *tmp = new double[this->dim * this->dim];
    cout << "Matrix " << this->num << " - Matrix " << r.num << endl;
    for (int i = 0; i < this->dim * this->dim; i++){
        tmp[i] = this->m[i] - r.m[i];
    }
    return Matrix(this->dim, tmp);
}

Matrix Matrix::operator- (){
    double *tmp = new double[this->dim * this->dim];
    cout << "Matrix " << this->num << " * -1";
    for (int i = 0; i < this->dim * this->dim; i++){
        tmp[i] = -1 * this->m[i];
    }
    return Matrix(this->dim, tmp);
}

Matrix Matrix::operator* (const double k){
    double *tmp = new double[this->dim * this->dim];

    cout << "Matrix " << this->num << " * " << k << endl;

    for (int i = 0; i < this->dim * this->dim; i++){
        tmp[i] = k * this->m[i];
    }
    return Matrix(this->dim, tmp);
}

double Matrix::operator[] (const int i){
    if (i < this->dim){
        cout << this->num <<"Matrix's element by index " << i << " is ";
        return this->m[i];
    }
}

void Matrix::print(){
    cout << endl;
    cout << "Matrix " << this->num << ": " << endl;
    for (int i = 0; i < this->dim; i++){
        for (int j = 0; j < this->dim; j++){
            cout << this->m[(this->dim * i) + j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


Matrix Matrix::operator* (const Matrix &r){
    double *tmp = new double[this->dim * this->dim];

    for (int i =0; i < dim * dim; i++){

        tmp[i] = 0;

    }

    cout << "Matrix " << this->num << " * " << r.num << endl;

    for (int i = 0; i < this->dim; i++){

        for (int j = 0; j < this->dim; j++){

            for (int k = 0; k < this->dim; k++){


                tmp[(this->dim * i) + j] = tmp[(this->dim * i) + j] + (this->m[(this->dim * i) + k] * r.m[(this->dim * k) + j]);

            }
        }
    }
    return Matrix(this->dim, tmp);
}

Vector Matrix::operator* (const Vector &r){
    double *tmp = new double[r.dim];
    cout << "Matrix " << this->num << " * Vector " << r.num << endl;

    return Vector(this->dim, tmp);
}

Matrix Matrix::diag (){
    int i,j;
    double mod = 10000;
    double div = 100;
    double *tmp = new double[this->dim*this->dim];

    for (i = 0; i < this->dim; i++){
        for (j = 0; j < this->dim; j++){
            if (i == j && this->m[(this->dim * i) + j ] != 0 ) {tmp[(this->dim * i) + j ] = this->m[(this->dim * i) + j ] ;}
            else if (i == j && this->m[(this->dim * i) + j ] == 0) {tmp[(this->dim * i) + j ] = (double) rand() ;}
            else tmp[(this->dim * i) + j ] = 0;
        }
    }
    return Matrix(this->dim, tmp);
}

Matrix Matrix::identity (int len){
    // to create matrix we need some empty matrix
    int i, j;
    this->dim = len;
    double *tmp = new double[ this->dim * this->dim ];
    for ( i = 0; i < this->dim; i++){
        for ( j = 0; j < this->dim; j++){
            if (i == j) tmp[ (this->dim * i) + j ] = 1.0;
            else tmp[ (this->dim * i) + j ] = 0;
        }
    }
    return Matrix(this->dim, tmp);
}

Matrix Matrix::invert(){
    int i, j;
    double *tmp = new double[this->dim * this->dim];
    // Only works for diagonal Matrix
    for (i = 0; i < this->dim; i++){
        for (j = 0; j < this->dim; j++){
            if  (i == j) tmp[ (this->dim * i) + j] = 1.0 / (this->m[(this->dim * i) + j]);
            else tmp[(this->dim * i) + j ] = 0;
        }
    }
    return Matrix(this->dim, tmp);
}

Matrix Matrix::above_diag(){
    int i, j;
    double *tmp = new double[this->dim * this->dim];
    for (i = 0; i < this->dim; i++){
        for (j = 0; j < this->dim; j++){
            if ((this->dim * i) + j > (this->dim * i) + i ) tmp[(this->dim * i) + j ] = this->m[(this->dim * i) + j];
            else tmp[(this->dim * i ) + j] = 0;
        }
    }
    return Matrix(this->dim, tmp);
}

Matrix Matrix::bellow_diag (){
    int i,j;
    double *tmp = new double[this->dim * this->dim];
    for (i = 0; i < this->dim; i++){
        for (j = 0; j < this->dim; j++){
            if  ((this->dim * i) + j < (this->dim * i) + i ) tmp[(this->dim * i) + j ] = this->m[(this->dim * i) + j];
            else tmp[(this->dim * i ) + j] = 0;
        }
    }
    return Matrix(this->dim, tmp);
}




