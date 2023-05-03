#pragma once
#include "Iterator.h"

template <class T1, class T2>
class Map
{
	T1* keys;
	T2* values;
	int index;
public:

	T2& operator[](T1 key) {
		keys[index] = key;
		return values[index++];
	}

	Map() {
		keys = new T1[100];
		values = new T2[100];
		index = 0;
	}
	~Map() {
		delete keys;
		delete values;
	}

	Iterator<T1, T2> begin() {
		/*Iterator<T1, T2> it;
		it.keys = &keys[0];
		it.values = &values[0];
		it.index = 0;*/
		return { &keys[0], &values[0], 0 };
		//return it;
	}
	Iterator<T1, T2> end() {
		/*Iterator<T1, T2> it;
		it.keys = &keys[index];
		it.values = &values[index];
		it.index = index;*/
		return { &keys[index], &values[index], index };
		//return it;
	}

	void Set(T1 key, T2 value) {
		for (int i = 0; i < index; i++) {
			if (keys[i] == key) {
				values[i] = value;
				return;
			}

		}
	}
	bool find(T1 key) {
		for (int i = 0; i < index; i++) {
			if (keys[i] == key) {
				return i;
			}
		}
		return -1;
	}
	bool Get(const T1& key, T2& value) {
		if (int i = find(key)) {
			value = keys[i];
			return true;
		}
		return false;

	}
	int Count() {
		return index;
	}
	void Clear() {
		memset(keys, 0, index * sizeof(keys[0]));
		memset(values, 0, index * sizeof(values[0]));
		index = 0;
	}
	bool Delete(const T1& key) {
		int i = 0;
		if (i = find(key) == -1)
			return false;
		for (int k = i; i < index - 1; i++) {
			keys[i] = keys[k + 1];
			values[i] = values[k + 1];
		}
		return true;
	}
	bool Includes(const Map<T1, T2>& map) {
		for (auto it : map) {
			if (find(it.first) == -1)
				return false;
		}
		return true;
	}
};


