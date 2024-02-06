#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double* data, int rows, int cols);
void randData(double* data, int rows, int cols);
void findRowSum(const double* data, double* sum, int rows, int cols);
void findColSum(const double* data, double* sum, int rows, int cols);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}

void randData(double* data, int rows, int cols) {
    for (int i = 0; i < rows * cols; ++i) {
        data[i] = static_cast<double>(rand() % 100) / 100.0;
    }
}

void showData(double* data, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << fixed << setprecision(2) << data[i * cols + j] << " ";
        }
        cout << endl;
    }
}

void findRowSum(const double* data, double* sum, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        sum[i] = 0;
        for (int j = 0; j < cols; ++j) {
            sum[i] += data[i * cols + j];
        }
    }
}

void findColSum(const double* data, double* sum, int rows, int cols) {
    for (int j = 0; j < cols; ++j) {
        sum[j] = 0;
        for (int i = 0; i < rows; ++i) {
            sum[j] += data[i * cols + j];
        }
    }
}
