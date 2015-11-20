#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

/*
*
build:建立一个空堆；
insert : 向堆中插入一个新元素；
update：将新元素提升使其符合堆的性质；
get：获取当前堆顶元素的值；
delete：删除堆顶元素；
heapify：使删除堆顶元素的堆再次成为堆。

*/

template<typename T>
class HE {
private:
	vector<T> vec;
	int size = 0;
	void minHeapFixup() {
		for (int futher = (size - 1) / 2, child = size - 1; child != 0; child = futher, futher /= 2) {
			if (vec[futher] > vec[child])
				swap(vec[futher], vec[child]);
			else break;

		}
	}
	void minHeapFixdown() {
		int futher = 0;
		int child_left = futher * 2 + 1;
		int child_right = futher * 2 + 2;
		int max_child = child_left;
		while (child_left < size) {
			if (child_right < size)
				max_child = vec[child_left] < vec[child_right] ? child_left : child_right;
			if (vec[futher] > vec[max_child])
				swap(vec[futher], vec[max_child]);
			futher = max_child;
			child_left = futher * 2 + 1;
			child_right = futher * 2 + 2;
		}
	}



public:
	void insert(T item) {
		vec.push_back(item);
		size++;
		minHeapFixup();
	}
	const T& pop() {
		swap(vec[0], vec[size - 1]);
		size--;
		minHeapFixdown();
		T temp = vec[size];
		vec.erase(vec.begin() + size);
		return temp;

	}
	 T& getMax() {
		return *vec.begin();
	}
	void buildMinHeap(const vector<T> &data) {
		for (vector<T>::const_iterator it = data.begin(); it != data.end(); it++) {
			T tmp = *it;
			insert(tmp);

		}
	}
	int getSize() {
		return size;
	}
	const vector<T>& sort(vector<T> &vec_to_sort) {
		this->vec.clear();
		this->size = 0;
		buildMinHeap(vec_to_sort);
		vec_to_sort.clear();
		while(size>0)
		{
			T t = this->pop();
			vec_to_sort.push_back(t);
		}
		return vec_to_sort;
	
	
	}
};





void main() {


	vector<int> vecs = { 16,7,3,20,17,8 };
	/*
		for (vector<int>::iterator it = vecs.begin(); it < vecs.end(); it++)
			*it = rand()%50;*/

	HE<int> heap;
	vector<int> sorted=heap.sort(vecs);


	cout << endl;
		for (int i = 0; i < 6; i++) {
			
			cout << sorted[i] << endl;
		}


}




