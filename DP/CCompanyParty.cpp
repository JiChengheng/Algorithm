#include "CDP.h"
void CCompanyParty::solve(EmployeeTreeNode* x) {          //从主席开始，自顶向下递归，带备忘录
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
		list.push_back(*x);                    //邀请该人，并遍历其所有下下级员工
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
		//不邀请该人，并遍历其所有下级员工
		EmployeeTreeNode* child = x->child;
		while (child != NULL) {
			invite(list, child);
			child = child->sibling;
		}

	}



}