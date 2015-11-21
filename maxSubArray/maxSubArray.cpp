#include "st.h"
//查找最长子数组    
//分治法 递归方法 分三部分看，左，右，横跨
void maxCross(const vector<int>& vec, int& sum, int& l, int& r, int mid) {  //利用引用返回多个返回值
	int left = l, right = r;
	l  = mid;
	r = mid + 1;//这里是为了使返回结果左闭右开

	if (mid < 0 || mid >= vec.size() || left>right || left<0 || right>vec.size())
		return;
	int lmax = 0;
	int rmax = 0;
	for (int tmp = 0, i = mid - 1; i >= left; i--) {
		tmp += vec[i];
		if (tmp > lmax) {
			lmax = tmp;//这里是为了使返回结果左闭
			l = i;
		}

	}
	for (int tmp = 0, i = mid + 1; i < right; i++) {
		tmp += vec[i];
		if (tmp > rmax) {
			rmax = tmp;
			r = i+1;//这里是为了使返回结果右开
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
	maxSubArray(vec, sum1, ll, lr);  //利用引用返回多个返回值 在递归时，内部一定要递归定义局部变量
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