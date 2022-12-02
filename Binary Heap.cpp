// https://www.codeabbey.com/index/wiki/binary-heap
//

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <chrono>
#include <cmath>
#include <cassert>
#include <limits>
#include <numeric>
#include <tuple>
#include <regex> 

#include "Console.h"
#include "CodeAbbey.h"
#include "LS_library.h"
#define VERSION "1.0"

using namespace std;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

class BinaryHeap {
public:
	vector<int> HEAP;

	BinaryHeap() {
		HEAP = {};
	};

	int size() {
		return HEAP.size();
	}

	int parent(int i) {
		return (i - 1) / 2;
	}

	int leftChild(int i) {
		return 2 * i + 1;
	}

	int rightChild(int i) {
		return 2 * i + 2;
	}

	void siftUp(int i) {
		while (i > 0 && this->HEAP[this->parent(i)] > this->HEAP[i]) {
			swap(this->HEAP[this->parent(i)], this->HEAP[i]);
			i = this->parent(i);
		}
	}

	void siftDown(int i) {
		int maxIndex = i;
		int L = this->leftChild(i);
		if (L < this->size() && this->HEAP[L] < this->HEAP[maxIndex]) {
			maxIndex = L;
		}
		int R = this->rightChild(i);
		if (R < this->size() && this->HEAP[R] < this->HEAP[maxIndex]) {
			maxIndex = R;
		}
		if (i != maxIndex) {
			swap(this->HEAP[i], this->HEAP[maxIndex]);
			this->siftDown(maxIndex);
		}
	}

	void insert(int value) {
		this->HEAP.push_back(value);
		this->siftUp(this->size() - 1);
	}
	int extractMin() {
		if (this->size() == 0) return -1;
		int result = this->HEAP.at(0);
		this->HEAP.at(0) = this->HEAP[this->size() - 1];
		this->HEAP.pop_back();
		this->siftDown(0);
		return result;
	}

	void display() {
		cout << joinVector(this->HEAP, " ") << endl;
	};
};

int main() {
	auto t1 = high_resolution_clock::now();
	cout << "Binary Heap v" << VERSION << "!\n\n";
	//string path = "Test.txt";
	string path = "Try.txt";
	vector<string> raw_data = loadData(path);
	//printVector(raw_data);
	/***********************/

	vector<int> data = splitToInt(raw_data[1], " ");
	//printVector(data);

	BinaryHeap BH = BinaryHeap();

	for (auto d : data) {
		if (d > 0) {
			BH.insert(d);
		}
		else {
			int i = BH.extractMin();
		}
	}

	cout << "\nSolution: " << endl;
	BH.display();
	/***********************/
	auto t2 = high_resolution_clock::now();
	auto ms_int = duration_cast<milliseconds>(t2 - t1);
	cout << "Execution time: " << ms_int.count() << " ms" << endl;
}
