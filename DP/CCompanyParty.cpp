#include "CDP.h"
void CCompanyParty::solve(EmployeeTreeNode* x) {          //����ϯ��ʼ���Զ����µݹ飬������¼
	x->max__with_me = x->conviviality;
	x->max__without_me = 0;
	EmployeeTreeNode* child = x->child;
	while (child != NULL) {
		solve(child);
		x->max__with_me += child->max__without_me;
		x->max__without_me += child->max__with_me > child->max__without_me ? child->max__with_me : child->max__without_me;
		child = child->sibling;
	}
}

void CCompanyParty::invite(vector<EmployeeTreeNode>& list, EmployeeTreeNode* x) {
	if (x->max__with_me > x->max__without_me) {
		list.push_back(*x);                    //������ˣ����������������¼�Ա��
		EmployeeTreeNode* child = x->child;
		EmployeeTreeNode* grandChild = child->child;
		while (child != NULL) {
			while (grandChild != NULL) {
				invite(list, grandChild);
				grandChild = grandChild->sibling;
			}
			child = child->sibling;
		}
	} else {
		//��������ˣ��������������¼�Ա��
		EmployeeTreeNode* child = x->child;
		while (child != NULL) {
			invite(list, child);
			child = child->sibling;
		}

	}



}