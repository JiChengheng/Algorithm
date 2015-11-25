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
		b[0][W] = weight[0]>W ? 0 : 1;      //对于每个W，c[0][W]决定于该W能否容下第一个元素
		for (int i = 1; i <N; i++) {
			int with_i = 0;
			int without_i = c[i - 1][W];
			if (W - weight[i] >= 0) 
				with_i = value[i] + c[i - 1][W - weight[i]];		//对于i>0，c[i][W]决定于装下该元素后的最大价值with_i和
				c[i][W] = with_i>without_i ? with_i : without_i;	//只装该元素以前的元素时最大价值without_i哪个比较大
			b[i][W] = with_i>without_i ? 1 : 0;						//这时无需关心其后的元素是否装，因为遍历到其后元素时，会做同样的决定
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