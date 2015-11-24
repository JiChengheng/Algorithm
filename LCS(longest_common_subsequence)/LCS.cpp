#include "st.h"
#define N 7
#define M 6
/*
*		动态规划查找最长公共子序列，基因相似度匹配
*		最优子结构 C[i][j]		按条件	依赖于：
*		 C[i-1][j-1]		OR		C[i][j-1]		OR		C[i-1][j]
*		子问题重叠    C[i][j-1] AND C[i-1][j] 可能依赖于 C[i-1][j-1]
*		子问题无关
*/

int findLSC(vector<vector<int>>& c, vector<vector<int>>& b, vector<char>& seq1, vector<char>& seq2) {

	for (int i = 1; i <= seq1.size(); i++) {
		for (int j = 1; j <= seq2.size(); j++) {
			if (seq1[i - 1] == seq2[j - 1]) {
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 0;
			} else if (c[i][j - 1] > c[i - 1][j]) {
				c[i][j] = c[i][j - 1];
				b[i][j] = -1;
			} else {

				c[i][j] = c[i - 1][j];
				b[i][j] = 1;
			}
		}
	}




	return c[seq1.size()][seq2.size()];

}
void printLCS(vector<vector<int>>& b, vector<char>& seq1, vector<char>& seq2) {
	int i = seq1.size();
	int j = seq2.size();
	vector < char > LCS;

	while (i != 0 && j != 0) {
		if (b[i][j] == 0) {
			LCS.push_back(seq1[i - 1]);
			i--;
			j--;
		} else if (b[i][j] == -1)j--;
		else i--;
	}
	for (int i = LCS.size(); i > 0; i--) {
		cout << LCS[i - 1] << " ";
	}
	cout << endl<<endl;


}
void main() {
	vector<char> seq1 = { 'A','B','C','B','D','A','B', };
	vector<char> seq2 = { 'B','D','C','A','B','A' };
	vector<vector<int>> c(N + 1, vector<int>(M + 1, 0));
	vector<vector<int>> b(N + 1, vector<int>(M + 1, 0));           //初始化二维数组
	findLSC(c, b, seq1, seq2);
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) cout << setw(2)<<c[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) cout << setw(2) << b[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	printLCS(b, seq1, seq2);
}