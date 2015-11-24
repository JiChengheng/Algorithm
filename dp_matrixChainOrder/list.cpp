/*
dynamic programing



p0......pn = 30 35 15 5 10 20 25    15125*/
#define  N 6
#include <limits>
#include<iostream>
using namespace std;
int p[7] = { 30,35,15,5,10,20,25 };
void MATRIX_CHAIN_ORDER(int*, int**, int**);
void print(int **s, int i, int j);
void main() {
	int **m, **s;
	m = new int*[N];
	s = new int*[N];
	for (int i = 0; i < N; i++) {
		*(m + i) = new int[N - i];
		*(s + i) = new int[N - i];
	}
	MATRIX_CHAIN_ORDER(p, m, s);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i; j++) std::cout << m[i][j] << "   ";
		std::cout << std::endl;

	}
	std::cout << "====================================" << std::endl;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i; j++) std::cout << s[i][j] << "   ";
		std::cout << std::endl;

	}



	print(s, 0, 5);
	for (int i = 0; i < N; i++) {
		delete[] * (m + i);
		delete[] * (s + i);
	}
}
void MATRIX_CHAIN_ORDER(int* p, int** m, int** s) {
	for (int i = 0; i < N; i++) {
		s[i][0] = 0;
		m[i][0] = 0;
	}

	for (int len = 2; len <= N; len++) {
		for (int i = 0; i <= N - len; i++) {
			int j = i + len - 1;
			m[i][len - 1] = INT_MAX;
			for (int k = i; k < j; k++) {
				int now = (m[i][k - i] + m[k + 1][j - k - 1] + p[i] * p[k + 1] * p[j + 1]);
				if (m[i][len - 1] >now) {
					m[i][len - 1] = now;
					s[i][len - 1] = k;
					std::cout << std::endl;
				}
			}

		}
	}


}

void print(int **s, int i, int j) {
	if (i == j)
		cout << "A" << i;
	else {
		cout << "(";
		print(s, i, s[i][j - i]);
		print(s, s[i][j - i] + 1, j);
		cout << ")";

	}

}
