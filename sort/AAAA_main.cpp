#include "stdafx.h"
#include "MySortFunc.h"


void print(int it) {
	cout << it << endl;
}
void  main() {

	cout << RAND_MAX << endl;
	vector<int> vec(150, 0);
	vector<int> res(150, 0);
	for (vector<int>::iterator it = vec.begin(); it < vec.end(); it++)
		*it = rand()%50;
//	for_each(vec.begin(), vec.end(), print);
	/*CMergeSorter::MergeSort(vec, 0, vec.size());*/
	//BubbleSort(vec);
	//quickSort(vec,0,vec.size()-1);
	countSorting(vec, res);
/*
	vector<int> t = { 3,4 };
	vector<int>::iterator it1, it2;
	it1 = t.begin();
	it2 = it1 + 1;
	//swap(it1,it2);
	swap(*it1, *it2);
	cout << *it1 << *it2 << endl;
	cout << *(it1+1) << endl;*/

for_each(res.begin(), res.end(), print);	//for_each 函数的使用

}

//sla
