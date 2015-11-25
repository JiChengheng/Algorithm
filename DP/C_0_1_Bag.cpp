#include "CDP.h"


void C_0_1_Bag::decide() {
	int N = value.size();
	c = new int*[N];
	b = new int*[N];
	for (int i = 0; i < max_weight + 1; i++) {
		*(c + i) = new int[max_weight + 1];
		*(b + i) = new int[max_weight + 1];
	}
	for (int i = 0; i < N; i++)		 c[i][0] = b[i][0] = 0;

	for (int W = 1; W< max_weight + 1; W++) {
		c[0][W] = weight[0]>W ? 0 : value[0];
		b[0][W] = weight[0]>W ? 0 : 1;      //����ÿ��W��c[0][W]�����ڸ�W�ܷ����µ�һ��Ԫ��
		for (int i = 1; i <N; i++) {
			int with_i = 0;
			int without_i = c[i - 1][W];
			if (W - weight[i] >= 0) 
				with_i = value[i] + c[i - 1][W - weight[i]];		//����i>0��c[i][W]������װ�¸�Ԫ�غ������ֵwith_i��
				c[i][W] = with_i>without_i ? with_i : without_i;	//ֻװ��Ԫ����ǰ��Ԫ��ʱ����ֵwithout_i�ĸ��Ƚϴ�
			b[i][W] = with_i>without_i ? 1 : 0;						//��ʱ�����������Ԫ���Ƿ�װ����Ϊ���������Ԫ��ʱ������ͬ���ľ���
		}

	}





}
void C_0_1_Bag::print() {
	int N = value.size();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= max_weight; j++) {
			cout << setw(3) << c[i][j];
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
	for (int N = value.size(), i = 0; i < N; i++) {
		for (int j = 0; j <= max_weight; j++) {
			cout << setw(3) << b[i][j];
		}
		cout << endl;
	}
	cout << endl;

	int i = N - 1, j = max_weight;
	vector<int> ans;
	while (i >= 0) {
		if (b[i][j] == 1) {
			ans.push_back(i);
			j -= weight[i];
			i--;
			

		} else {
			i--;
			
		}
	}
	for (int i = ans.size()-1; i >=0 ; i--) cout << ans[i];
	cout << endl;
	
}

/*
void main() {
	vector<int> v = {5,10,20,100};
	vector<int> w = {3,2,2,4};
	int max_weight = 5;
	C_0_1_Bag bag(v, w, max_weight);
	bag.decide();
	bag.print();


}*/