#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class HeapBuilder {
private:
	vector<int> data_;
	vector< pair<int, int> > swaps_;

	void WriteResponse() const {
		cout << swaps_.size() << "\n";
		for (int i = 0; i < swaps_.size(); ++i) {
			cout << swaps_[i].first << " " << swaps_[i].second << "\n";
		}
	}

	void ReadData() {
		int n;
		cin >> n;
		data_.resize(n + 1);
		for (int i = 1; i <= n; ++i)
			cin >> data_[i];
	}
	int leftChild(int index) {
		return 2 * index;
	}
	int rightChild(int index) {
		return (2 * index) + 1;
	}

	void siftDown(int index) {
		int minIndex = index;
		int left = leftChild(index);
		int right = rightChild(index);
		if (left < data_.size() && data_[left] < data_[minIndex]) {
			minIndex = left;
		}
		if (right < data_.size() && data_[right] < data_[minIndex]) {
			minIndex = right;
		}
		if (index != minIndex) {
			swap(data_[index], data_[minIndex]);
			swaps_.push_back(make_pair(index - 1, minIndex - 1));
			siftDown(minIndex);
		}
	}
	void GenerateSwaps() {
		swaps_.clear();
		// The following naive implementation just sorts 
		// the given sequence using selection sort algorithm
		// and saves the resulting sequence of swaps.
		// This turns the given array into a heap, 
		// but in the worst case gives a quadratic number of swaps.
		//
		// TODO: replace by a more efficient implementation
		for (int i = 0; i < data_.size(); ++i)
			for (int j = i + 1; j < data_.size(); ++j) {
				if (data_[i] > data_[j]) {
					swap(data_[i], data_[j]);
					swaps_.push_back(make_pair(i, j));
				}
			}
		
	}
	void fastGenerateSwaps() {
		swaps_.clear();
		int size = data_.size() - 1;
		for (int i = size / 2; i > 0; i--) {
			siftDown(i);
		}
	}

public:
	void Solve() {
		ReadData();
		fastGenerateSwaps();
		WriteResponse();
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	HeapBuilder heap_builder;
	heap_builder.Solve();
	return 0;
}
