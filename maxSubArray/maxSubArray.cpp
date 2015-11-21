#include "st.h"
//�����������    
//���η� �ݹ鷽�� �������ֿ������ң����
void maxCross(const vector<int>& vec, int& sum, int& l, int& r, int mid) {  //�������÷��ض������ֵ
	int left = l, right = r;
	l  = mid;
	r = mid + 1;//������Ϊ��ʹ���ؽ������ҿ�

	if (mid < 0 || mid >= vec.size() || left>right || left<0 || right>vec.size())
		return;
	int lmax = 0;
	int rmax = 0;
	for (int tmp = 0, i = mid - 1; i >= left; i--) {
		tmp += vec[i];
		if (tmp > lmax) {
			lmax = tmp;//������Ϊ��ʹ���ؽ�����
			l = i;
		}

	}
	for (int tmp = 0, i = mid + 1; i < right; i++) {
		tmp += vec[i];
		if (tmp > rmax) {
			rmax = tmp;
			r = i+1;//������Ϊ��ʹ���ؽ���ҿ�
		}

	}
	sum = lmax + rmax + vec[mid];


}
void maxSubArray(const vector<int>&vec, int& sum, int& left, int& right) {
	if (left >= right) return;
	int mid = (right + left) / 2;
	int ll = left, lr = mid - 1;
	int rl = mid + 1, rr = right;
	int cl = left, cr = right;
	int sum1, sum2, sum3;
	maxSubArray(vec, sum1, ll, lr);  //�������÷��ض������ֵ �ڵݹ�ʱ���ڲ�һ��Ҫ�ݹ鶨��ֲ�����
	maxSubArray(vec, sum2, rl, rr);
	maxCross(vec, sum3, cl, cr, mid);
	sum = max(sum1, sum2);
	sum = max(sum, sum3);
	if (sum == sum1) {
		left = ll;
		right = lr;
	} else if (sum == sum2) {
		left = rl;
		right = rr;
	} else {
		left = cl;
		right = cr;
	}
}
void main() {
	srand(time(0));
	vector<int> vec(2, 0);
	for (vector<int>::iterator it = vec.begin(); it < vec.end(); it++) {
		int sign = rand() % 2 == 0 ? -1 : 1;
		*it = sign*rand() % 300;
	}
	int sum, l = 0, r = vec.size();
	maxSubArray(vec, sum, l, r);
	int i = 0;
	for (vector<int>::iterator it = vec.begin(); it < vec.end(); it++,i++)cout << i<<"______"<<*it << endl;
	cout << "------------------------" << endl;
	cout << l << endl << r << endl << sum << endl;
	int add=0;
	for (int k = l; k < r;k++)
	{
		add += vec[k];
	}
	cout << add << endl;

}  