/*
파일명 : Array.cpp
작성일자 : 2018년 04월 15일
작성자 : 서유라
기능 : 배열 라이브러리 메인
수정 : -
*/
//Array.cpp
#include "Array.h"
#include <iostream>
using namespace std;
int CompareIntegers(void *one, void*other);

//int main(int argc, char *argv[]) {
//	Array<int> array(2);
//	Long index;
//	index = array.Store(0, 10);		//1
//	cout << array.GetAt(index) << endl;
//	index = array.Store(1, 20);		//2
//	cout << array.GetAt(index) << endl;
//	index = array.Insert(2, 30);	//3
//	cout << array.GetAt(index) << endl;
//	index = array.AppendFromFront(40);	//4
//	cout << array.GetAt(index) << endl;
//	index = array.AppendFromRear(50);	//5
//	cout << array.GetAt(index) << endl;
//	index = array.Delete(2);	//6
//	if (index==-1) {
//		cout << "삭제되었습니다" << endl;
//	}
//	index = array.DeleteFromFront();	//7
//	if (index == -1) {
//		cout << "삭제되었습니다" << endl;
//	}
//	index = array.DeleteFromRear();		//8
//	if (index == -1) {
//		cout << "삭제되었습니다" << endl;
//	}
//	index = array.Modify(1, 60);	//9
//	cout << array.GetAt(index) << endl;
//	index = array.AppendFromFront(60);		//10
//	cout << array.GetAt(index) << endl;
//	Long(*indexes);
//	Long count = 0;
//	Long i = 0;
//	Long key = 50;
//	array.LinearSearchDuplicate(&key,&indexes, &count, CompareIntegers);
//	cout << "배열 시작" << endl;	//11
//	while (i < count) {
//		cout << array[indexes[i]] << endl;
//		i++;
//	}
//	if (indexes != 0) {
//		delete[] indexes;
//		indexes = 0;
//	}
//	cout << "배열 시작" << endl;
//	array.BubbleSort(CompareIntegers);	//12
//	i = 0;
//	while (i < array.GetLength()) {
//		cout << array[i] << endl;
//		i++;
//	}
//	cout << "배열 끝" << endl;
//	index = array.Modify(1, 50);	//13
//	cout << array.GetAt(index) << endl;
//	key = 50;
//	index = array.BinarySearchUnique(&key, CompareIntegers);	//14
//	cout << array.GetAt(index) << endl;
//	index = array.AppendFromRear(50);		//15
//	cout << array.GetAt(index) << endl;
//	array.SelectionSort(CompareIntegers);	//16
//	i = 0;
//	cout << "배열 시작" << endl;
//	while (i < array.GetLength()) {
//		cout << array[i] << endl;
//		i++;
//	}
//	key = 50;
//	array.BinarySearchDuplicate(&key, &indexes, &count, CompareIntegers);	//17
//	cout << "배열 시작" << endl;
//	while (i < count) {
//		cout << array[indexes[i]] << endl;
//		i++;
//	}
//	if (indexes != 0) {
//		delete[] indexes;
//		indexes = 0;
//	}
//	index = array.Modify(2, 40);	//18
//	cout << array.GetAt(index) << endl;
//	cout << "배열 시작" << endl;
//	array.InsertionSort(CompareIntegers);	//19
//	i = 0;
//	while (i < array.GetLength()) {
//		cout << array[i] << endl;
//		i++;
//	}
//	cout << "배열 끝" << endl;
//	Array<int> one(2);
//	index = one.Store(0, 10);		//20
//	cout << array.GetAt(index) << endl;
//	index = one.Store(1, 20);		//21
//	cout << array.GetAt(index) << endl;
//	Array<int> other(2);
//	index = other.Store(0, 30);		//22
//	cout << array.GetAt(index) << endl;
//	index = other.Store(1, 40);		//23
//	cout << array.GetAt(index) << endl;
//	cout << "배열 시작" << endl;
//	array.MergeSort(one, other, CompareIntegers);	//24
//	i = 0;
//	while (i < array.GetLength()) {
//		cout << array[i] << endl;
//		i++;
//	}
//	key = 40;
//	index = array.LinearSearchUnique(&key, CompareIntegers);	//25
//	cout << array.GetAt(index) << endl;
//
//	return 0;
//}

int CompareIntegers(void *one, void *other) {
	int ret;
	if (*(static_cast<int*>(one)) > *(static_cast<int*>(other))) {
		ret = 1;
	}else if(*(static_cast<int*>(one)) == *(static_cast<int*>(other))) {
		ret = 0;
	}else if (*(static_cast<int*>(one)) < *(static_cast<int*>(other))) {
		ret = -1;
	}
	return ret;
}