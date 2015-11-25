#pragma once
#include "st.h"

//公司聚会名单问题
class CCompanyParty {
public:
	class EmployeeTreeNode {
	public:
		EmployeeTreeNode(string name, double conviviality) :name(name), conviviality(conviviality) {}
		string name;
		double conviviality;
		double max__with_me;
		double max__without_me;
		EmployeeTreeNode* child;
		EmployeeTreeNode* sibling;
	};
	CCompanyParty(EmployeeTreeNode* root) :root(root) {};
	void solve(EmployeeTreeNode* x);
	void invite(vector<EmployeeTreeNode>& list, EmployeeTreeNode* x);
private:
	EmployeeTreeNode* root;
};

//最长回文子串问题
class CPalinDrome {
public:
	CPalinDrome(char* str, int size);
	void	searchPD();
	void printPD();
private:
	char* input;
	int** s;
	int** pb;
	int N;
};

//0-1背包问题
class C_0_1_Bag {
public:
	C_0_1_Bag(vector<int>& v,vector<int>& w,int m):value(v),weight(w),max_weight(m) {};
	void decide();
	void print();


private:
	vector<int>& value;
	vector<int>& weight;
	int max_weight;
	int** c;
	int** b;
};
