#pragma once
#include "st.h"
//哈弗曼树，构造最优前缀码
class CHuffman {
public:
	class Node {
	public:
		bool checked = false;
		char value;
		double freq = 0;
		Node* left_child;
		Node* right_child;
		Node* parent;
		Node(char v, double f) :value(v), freq(f) {}
		Node(){}
	};

	CHuffman(vector<Node*>& input) :input(input) {} //构造函数
	Node* createHuffmanTree();
	void getCodeByLastOrder(CHuffman::Node * root, vector<int>& hf);
private:
	vector<Node*>& input;
};

