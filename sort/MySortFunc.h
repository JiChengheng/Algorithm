#include "stdafx.h"

//count sorting
void countSorting(const vector<int> &vec, vector<int> &res) {
	int mx = *max_element(vec.begin(), vec.end());
	for (vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++) {
		if (*it > mx) mx = *it;
	}
	int counts_size = mx + 1;
	int* counts = new int[counts_size];
	memset(counts, 0, sizeof(int)*counts_size);
	for (vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++) {
		try {
			if (*it < 0) throw *it;
			counts[*it]++;

		} catch (int e) {
			cout << "hhhhhh";

		}



	}
	for (int i = 1; i < counts_size; i++) {
		counts[i] = counts[i] + counts[i - 1];
	}
	for (vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		res[counts[*it]---1] = *it;
	}
}

//quick sort
template<typename T>
void quickSort(vector<T> &vec, int left, int right) {
	if (left >= right) return;
	T key = vec[left];
	int l = left;
	int r = right;
	while (l < r) {
		while (l<r&&vec[r] > key)
			r--;
		if (l < r)
			vec[l++] = vec[r];
		while (l < r&&vec[l] < key)
			l++;
		if (l < r)
			vec[r--] = vec[l];

	}
	assert(l == r);
	vec[l] = key;
	quickSort(vec, left, l - 1);
	quickSort(vec, r + 1, right);
}

//πÈ≤¢≈≈–Ú∫Ø ˝ 
template<typename T>
void __Merge(vector<T> &vec, int n_left, int n_mid, int n_right) {
	vector<T> l_vec, r_vec;
	for (int i = n_left; i < n_mid; i++) {
		l_vec.push_back(vec[i]);
	}
	for (int i = n_mid; i < n_right; i++) {
		r_vec.push_back(vec[i]);
	}
	int i = 0, j = 0, index = n_left;
	for (; i < l_vec.size() && j < r_vec.size(); index++) {
		if (l_vec[i] > r_vec[j]) {
			vec[index] = l_vec[i];
			i++;
		} else {
			vec[index] = r_vec[j];
			j++;
		}
	}
	while (i != l_vec.size()) vec[index++] = l_vec[i++];
	while (j != r_vec.size()) vec[index++] = r_vec[j++];
}
template<typename T>
void MergeSort(vector<T> &vec, int n_left, int n_right) {
	if (n_right - n_left == 1) return;
	int n_vecMid = (n_right + n_left) / 2;
	MergeSort(vec, n_left, n_vecMid);
	MergeSort(vec, n_vecMid, n_right);
	__Merge(vec, n_left, n_vecMid, n_right);
}


//√∞≈›≈≈–Ú
template<typename T>
void BubbleSort(vector<T> vec, int(*comp)(T &a, T &b)) {
	int swap = 1;
	while (swap) {
		swap = 0;
		vector<T>::iterator it1, it2;
		it1 = vec.begin();
		1t2 = it1 + 1;
		while (it2 != vec.end()) {
			if (comp(*it1, *it2)) {
				swap++;
				swap(it1, it2);
				it1++;
				it2++;
			}
		}
	}
}
template<typename T>
void BubbleSort(vector<T> &vec) {
	int swap = 1;
	while (swap) {
		swap = 0;
		vector<T>::iterator it1, it2;
		it1 = vec.begin();
		it2 = it1 + 1;
		while (it2 != vec.end()) {
			if (*it1 > *it2) {
				swap++;
				std::swap(*it1, *it2);
			}
			it1++;
			it2++;
		}
	}
}


//œ£∂˚≈≈–Ú
template<typename T>
void ShellSort(vector<T> &vec) {
	int n_step = vec.size();
	for (n_step /= 2; n_step > 0; n_step /= 2)
		for (int i = n_step; i < vec.size(); i++)
			for (int j = i - n_step; j >= 0 && vec[j] > vec[j + n_step]; j -= n_step)
				swap(vec[j], vec[j + n_step]);   //÷±Ω”≤Â»Î≈≈–Ú

}
