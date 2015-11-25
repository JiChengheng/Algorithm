#include "CDP.h"
//动态规划实现最长回文子串


//m[i,i]=1
//m[i,i+1]=1 or 2
// 
//m[i,j]= m[i+1,j-1]+2 若 p[i]==p[j];
// m[i,j]= MAX(m[i,j-1],m[i+1,j]) 若 p[i]!=p[j];

CPalinDrome::CPalinDrome(char* str, int size):input(str) ,N(size){
	pb = new int*[N + 1];

	for (int i = 0; i <= N; i++) {
		*(pb + i) = new int[N + 1];
		memset(*(pb + i), 0, sizeof(int)*(N + 1));
	}
	s = new int*[N + 1];

	for (int i = 0; i <= N; i++) {
		*(s + i) = new int[N + 1];
		memset(*(s + i), 0, sizeof(int)*(N + 1));
	}

}
void CPalinDrome::searchPD() {

	for (int i = 1; i <= N; i++) {
		pb[i][i] = 1;
		s[i][i] = 0;
	}
	for (int i = 1, j = 2; i < N; i++, j++) {
		s[i][j] =  input[i - 1] == input[j - 1] ? 0 : 1;
		pb[i][j] = input[i - 1] == input[j - 1] ? 2 : 1;
			
	}
	for (int len = 3; len <= N; len++) {
		for (int i = 1; i <= N - len + 1; i++) {
			int j = i + len - 1;
			
			if (input[i - 1] == input[j - 1]) {
				pb[i][j] = pb[i + 1][j - 1] + 2;
				s[i][j] = 0;
			} else if (pb[i][j - 1]>pb[i + 1][j]) {
				pb[i][j] = pb[i][j - 1] ;
				s[i][j] = 1;
			} else {
				pb[i][j] = pb[i +1][j] ;
				s[i][j] = -1;

			}
		}
	}

}
void CPalinDrome::printPD() {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cout << setw(2) << pb[i][j];
			}
			cout << endl;
		}
		cout << endl;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cout << setw(2) << s[i][j];
			}
			cout << endl;
		}

		int i = 1, j = N;
		cout << endl << "the longest palindrome:" << endl;
		vector<char> ans;
		while (i<=j)
		{
			if (s[i][j]==0)
			{
				ans.push_back(input[i - 1]);
				i++;
				j--;
			}
			else if (s[i][j] == 1)
				j--;
			else i++;

		}
		for (int i = 0; i < ans.size();i++)
		{
			cout << ans[i];
		}
		if (i-j==1)
		{
			for (int i = ans.size() - 1; i >= 0;i--) {
				cout << ans[i];
			}
		} else {
			for (int i = ans.size() -2; i >= 0; i--) {
				cout << ans[i];
			}
		}

		
}




/*
void main() {
	char* a = "ABCDEFGABA";
	CPalinDrome cpd(a,10);
	
	cpd.searchPD();
	cpd.printPD();


}*/