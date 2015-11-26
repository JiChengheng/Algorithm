#include "greedy.h"
//������������
CHuffman::Node * CHuffman::createHuffmanTree() {
	while (input.size() > 1) {

		Node* parent = new Node('P', 0);
		Node* lchild = new Node();
		Node* rchild = new Node();

		lchild = input[0];
		int min_index = 0;
		for (int i = 1; i < input.size(); i++)
			if (input[i]->freq < input[min_index]->freq)
				min_index = i;
		lchild = input[min_index];
		parent->left_child = lchild;
		lchild->parent = parent;
		input.erase(input.begin() + min_index);

		rchild = input[0];
		min_index = 0;
		for (int i = 1; i < input.size(); i++)
			if (input[i]->freq < input[min_index]->freq)
				min_index = i;
		rchild = input[min_index];
		parent->right_child = rchild;
		rchild->parent = parent;
		input.erase(input.begin() + min_index);

		parent->freq = lchild->freq + rchild->freq;
		input.push_back(parent);
	}
	return *(input.begin());
}
//���պ������������������
void CHuffman::getCodeByLastOrder(CHuffman::Node* root, vector<int> &hf) {
	if (root == NULL) {  return; }
	
	if(root->left_child==NULL) {		//��ΪҶ�ڵ㣬�����ǰ����
		for (int i = 0; i < hf.size(); i++)
			cout << hf[i];
		cout << endl;
	}

	CHuffman::Node* l = root->left_child;
	hf.push_back(0);				//������չһ����pushһ��0
	getCodeByLastOrder(l, hf);
	hf.pop_back();					//�������һ����popһ��0

	CHuffman::Node* r = root->right_child;
	hf.push_back(1);				//������չһ����pushһ��1
	getCodeByLastOrder(r, hf);
	hf.pop_back();					//���һ���һ����popһ��1

	




}
void main() {
	CHuffman::Node node1('f', 5);
	CHuffman::Node node2('e', 9);
	CHuffman::Node node3('c', 12);
	CHuffman::Node node4('b', 13);
	CHuffman::Node node5('d', 16);
	CHuffman::Node node6('a', 45);

	vector < CHuffman::Node* > input = { &node1,&node2, &node3, &node4, &node5, &node6 };
	CHuffman chf(input);

	CHuffman::Node* r = chf.createHuffmanTree();
	vector<int> hf;
	chf.getCodeByLastOrder(r, hf);





}

