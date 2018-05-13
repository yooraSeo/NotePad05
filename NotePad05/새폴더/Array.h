/*
파일명 : Array.h
작성일자 : 2018년 04월 15일
작성자 : 서유라
기능 : 배열 라이브러리 선언과 정의
수정 : -
*/
//Array.h
#ifndef _ARRAY_H
#define _ARRAY_H

typedef signed long int Long;

template <typename T>

class Array {
public:
	Array(Long capacity = 256);
	Array(const Array&source);
	~Array();
	Long Store(Long index, T object);
	Long Insert(Long index, T object);
	Long AppendFromFront(T object);
	Long AppendFromRear(T object);
	Long Delete(Long index);
	Long DeleteFromFront();
	Long DeleteFromRear();
	void Clear();
	Long Modify(Long index, T object);
	Long LinearSearchUnique(void *key, int(*compare)(void*, void*));
	void LinearSearchDuplicate(void *key, Long* (*indexes), Long *count, int(*compare)(void*, void*));
	Long BinarySearchUnique(void *key, int(*compare)(void*, void*));
	void BinarySearchDuplicate(void *key, Long* (*indexes), Long *count, int(*compare)(void*, void*));
	void BubbleSort(int(*compare)(void*, void*));
	void SelectionSort(int(*compare)(void*, void*));
	void InsertionSort(int(*compare)(void*, void*));
	void MergeSort(const Array &one, const Array &other, int(*compare)(void*, void*));
	T& GetAt(Long index);
	Long GetCapacity() const;
	Long GetLength() const;
	Array<T>& operator= (const Array& source);
	T& operator[](Long index);
	T* operator+(Long index);

private:
	T(*front);
	Long capacity;
	Long length;
};

template<typename T>
inline Long Array<T>::GetCapacity() const {
	return this->capacity;
}

template<typename T>
inline Long Array<T>::GetLength() const {
	return this->length;
}

template<typename T>
Array<T>::Array(Long capacity) {
	this->front = new T[capacity];
	this->capacity = capacity;
	this->length = 0;
}

template<typename T>
Array<T>::Array(const Array&source) {
	Long i = 0;
	this->front = new T[source.capacity];
	this->capacity = source.capacity;
	while (i < source.length) {
		this->front[i] = source.front[i];
		i++;
	}
	this->length = source.length;
}

template<typename T>
Array<T>::~Array() {
	if (this->front != 0) {
		delete[] this->front;
		this->front = 0;
	}
}

template<typename T>
Long Array<T>::Store(Long index, T object) {
	this->front[index] = object;
	this->length++;
	return index;
}

template<typename T>
Long Array<T>::Insert(Long index, T object) {
	Long i = 0;
	Long j = 0;
	T(*temp);
	temp = new T[this->capacity + 1];
	while (i < index) {
		temp[j] = this->front[i];
		j++;
		i++;
	}
	j++;
	while (i < this->length) {
		temp[j] = this->front[i];
		j++;
		i++;
	}
	if (this->front != 0) {
		delete[] this->front;
	}
	this->front = temp;
	this->capacity++;
	this->front[index] = object;
	this->length++;

	return index;
}

template<typename T>
Long Array<T>::AppendFromFront(T object) {
	Long index = 0;
	T(*temp);
	Long i = 0;
	Long j = 1;
	if (this->length >= this->capacity) {
		temp = new T[this->capacity + 1];
		this->capacity++;
	}else {
		temp = new T[this->capacity];
	}	
	while (i < this->length) {
		temp[j] = this->front[i];
		j++;
		i++;
	}
	if (this->front != 0) {
		delete[]this->front;
	}
	this->front = temp;
	this->front[0] = object;
	this->length++;
	return index;
}

template<typename T>
Long Array<T>::AppendFromRear(T object) {
	Long index;
	Long i = 0;
	T(*temp);
	if (this->length >= this->capacity) {
		temp = new T[this->capacity + 1];
		this->capacity++;
	}
	else {
		temp = new T[this->capacity];
	}
	while (i < this->length) {
		temp[i] = this->front[i];
		i++;
	}
	if (this->front != 0) {
		delete[]this->front;
	}
	this->front = temp;
	index = this->length;
	this->front[index] = object;
	this->length++;
	return index;
}

template<typename T>
Long Array<T>::Delete(Long index) {
	Long i = 0;
	Long j = 0;
	T(*temp);
	if (this->capacity > 1) {
		temp = new T[this->capacity - 1];
	}
	while (i < index) {
		temp[j] = this->front[i];
		j++;
		i++;
	}
	i = index + 1;
	while (i < this->length) {
		temp[j] = this->front[i];
		j++;
		i++;
	}
	if (this->front != 0) {
		delete[] this->front;
		this->front = 0;
	}
	if (this->capacity > 1) {
		this->front = temp;
	}
	this->capacity--;
	this->length--;
	index = -1;
	return index;
}

template<typename T>
Long Array<T>::DeleteFromFront() {
	T(*temp);
	Long index;
	Long i = 1;
	Long j = 0;
	if (this->capacity > 1) {
		temp = new T[this->capacity - 1];
	}
	while (i < this->length) {
		temp[j] = this->front[i];
		j++;
		i++;
	}
	if (this->front != 0) {
		delete[] this->front;
		this->front = 0;
	}
	if (this->capacity > 1) {
		this->front = temp;
	}
	this->capacity--;
	this->length--;
	index = -1;
	return index;
}

template<typename T>
Long Array<T>::DeleteFromRear() {
	Long index;
	T(*temp);
	Long i = 0;
	if (this->capacity > 1) {
		temp = new T[this->capacity - 1];
	}
	while (i < this->length - 1) {
		temp[i] = this->front[i];
		i++;
	}
	if (this->front != 0) {
		delete[]this->front;
		this->front = 0;
	}
	if (this->capacity > 1) {
		this->front = temp;
	}
	this->capacity--;
	this->length--;
	index = -1;
	return index;
}

template<typename T>
void Array<T>::Clear() {
	if (this->front != 0) {
		delete[]this->front;
		this->front = 0;
	}
	this->capacity = 0;
	this->length = 0;
}
template<typename T>
Long Array<T>::Modify(Long index, T object) {
	this->front[index] = object;
	return index;
}

template<typename T>
Long Array<T>::LinearSearchUnique(void* key, int(*compare)(void*, void*)) {
	Long index = -1;
	Long i = 0;
	while (i < this->length && compare(this->front + i, key) != 0) {
		i++;
	}
	if (i < this->length) {
		index = i;
	}
	return index;
}

template<typename T>
void Array<T>::LinearSearchDuplicate(void* key, Long *(*indexes), Long *count, int(*compare)(void*, void*)) {
	Long i = 0;
	Long j = 0;
	*count = 0;
	while (i < this->length) {
		if (compare(this->front + i, key) == 0) {
			(*count)++;
		}
		i++;
	}
	if (*count > 0) {
		*indexes = new Long[*count];
	}
	else {
		*indexes = 0;
	}
	i = 0;
	while (j < *count && i < this->length) {
		if (compare(this->front + i, key) == 0) {
			(*indexes)[j] = i;
			j++;
		}
		i++;
	}
}

template<typename T>
Long Array<T>::BinarySearchUnique(void* key, int(*compare)(void*, void*)) {
	Long index = -1;
	Long firstIndex = 0;
	Long middleIndex;
	Long lastIndex;
	lastIndex = this->length - 1;
	middleIndex = (firstIndex + lastIndex) / 2;
	while (firstIndex <= lastIndex && compare(this->front + middleIndex, key) != 0) {
		if (compare(this->front + middleIndex, key) > 0) {
			lastIndex = middleIndex - 1;
		}
		else {
			firstIndex = middleIndex - 1;
		}
		middleIndex = (firstIndex + lastIndex) / 2;
	}
	if (firstIndex <= lastIndex) {
		index = middleIndex;
	}
	return index;
}

template<typename T>
void Array<T>::BinarySearchDuplicate(void*key, Long*(*indexes), Long *count, int(*compare)(void*, void*)) {
	Long firstIndex = 0;
	Long middleIndex;
	Long lastIndex;
	Long i;
	Long j;
	Long k = 0;
	*indexes = 0;
	*count = 0;

	lastIndex = this->length - 1;
	middleIndex = (firstIndex + lastIndex) / 2;

	while (firstIndex != lastIndex && compare(this->front + middleIndex, key) != 0) {
		if (compare(this->front + middleIndex, key) > 0) {
			lastIndex = middleIndex - 1;
		}
		else {
			firstIndex = middleIndex + 1;
		}
		middleIndex = (firstIndex + lastIndex) / 2;
	}
	i = middleIndex;
	j = middleIndex + 1;
	while (i >= 0 && compare(this->front + 1, key) == 0) {
		(*count)++;
		i--;
	}
	while (j < this->length&&compare(this->front + j, key) == 0) {
		(*count)++;
		j++;
	}
	if (*count > 0) {
		*indexes = new Long[*count];
	}
	i++;
	while (i < this->length&& compare(this->front + i, key) == 0) {
		(*indexes)[k] = i;
		k++;
		i++;
	}
}

template<typename T>
void Array<T>::BubbleSort(int(*compare)(void*, void*)) {
	T temp;
	Long count;
	Long i;
	Long j;
	count = this->length - 1;
	while (count != 0) {
		i = 0;
		while (i < count) {
			j = i + 1;
			if (compare(this->front + i, this->front + j) > 0) {
				temp = this->front[j];
				this->front[i] = this->front[j];
				this->front[j] = temp;
			}
			i++;
		}
		count--;
	}
}

template<typename T>
void Array<T>::SelectionSort(int(*compare)(void*, void*)) {
	T temp;
	Long i = 0;
	Long j;
	while (i < this->length - 1) {
		j = i + 1;
		while (j < this->length) {
			if (compare(this->front + i, this->front + j) > 0) {
				temp = this->front[i];
				this->front[i] = this->front[j];
				this->front[j] = temp;
			}
			j++;
		}
		i++;
	}
}

template<typename T>
void Array<T>::InsertionSort(int(*compare)(void*, void*)) {
	T temp;
	Long i = 1;
	Long j;
	while (i < this->length) {
		temp = this->front[i];
		j = i - 1;
		while (j >= 0 && compare(this->front + j, &temp) > 0) {
			this->front[j + 1] = this->front[i];
			j++;
		}
		this->front[j + 1] = temp;
		i++;
	}
}

template<typename T>
void Array<T>::MergeSort(const Array& one, const Array& other, int(*compare)(void*, void*)) {
	Long i = 0;
	Long j = 0;
	Long k = 0;
	if (this->front != 0) {
		delete[] this->front;
		this->front = 0;
	}
	this->front = new T[one.length + other.length];
	this->capacity = one.capacity + other.capacity;
	while (i < one.length && j < other.length) {
		if (compare(one.front + i, other.front + j) < 0) {
			this->front[k] = one.front[i];
			k++;
			i++;
		}
		else {
			this->front[k] = other.front[j];
			k++;
			j++;
		}
	}
	while (i < one.length) {
		this->front[k] = one.front[i];
		k++;
		i++;
	}
	while (j < other.length) {
		this->front[k] = other.front[j];
		k++;
		j++;
	}
	this->length = one.length + other.length;
}

template<typename T>
T& Array<T>::GetAt(Long index) {
	return this->front[index];
}

template<typename T>
Array<T>& Array<T>::operator= (const Array&source) {
	Long i = 0;
	if (this->front != 0) {
		delete[] this->front;
	}
	this->front = new T[source.capacity];
	this->capacity = source.capacity;
	while (i < source.length) {
		this->front[i] = source.front[i];
		i++;
	}
	this->length = source.length;
	return *this;
}

template<typename T>
T& Array<T>::operator[] (Long index) {
	return this->front[index];
}

template<typename T>
T* Array<T>:: operator+ (Long index) {
	return this->front + index;
}

#endif//_ARRAY_H