#include <iostream>
#include <vector>
#include <algorithm>

int MF(std::vector<int>& A, int K);
int QuickSort(std::vector<int>& A, int M);
int rank(std::vector<int> & A,int current_key,int key);

int main() {

	std::vector<int> A = { 3,7,2,10,9,     8,5,13,20,17,    11,6,19,1,21,     15,12 };
	int key = (A.size() + 1) / 2;

	int median = MF(A, key);
	int current_key = QuickSort(A, median);
	std::cout<<rank(A, current_key, key);
}

int QuickSort(std::vector<int>& A, int M) {
	int index = 0;
	for (int i = 0; i < A.size(); ++i) {
		if (A[i] == M)
			index = i;
	}
	int l = 0, r = A.size() - 1;
	while (l < r)
	{
		if (A[l] > M)
		{

			if (A[r] < M) {
				int temp = A[l];
				A[l] = A[r];
				A[r] = temp;
				l++;
				r--;
			}
			else
				r--;
		}
		else
			l++;
	}
	if (l == r) {
		if (A[l] <= M) {
			if (l < index) {
				int temp = A[l + 1];
				A[l + 1] = M;
				A[index] = temp;
			}
			else {
				int temp = A[l];
				A[l] = M;
				A[index] = temp;
			}
		}
		else if (A[l] > M) {

		}
	}

	return r;
}

int rank(std::vector<int> & A,int current_key, int key)
{
	if (current_key > key) {
		std::vector<int> S;
		for (int i = 0; i < current_key-1; ++i)
			S.push_back(A[i]);
		int median = MF(S, key);
		int current_key = QuickSort(S, median);
		rank(S, current_key, key);
	}
	else if (current_key < key) {
		std::vector<int> L;
		for (int i = current_key; i < A.size(); ++i)
			L.push_back(A[i]);
		int median = MF(L, key - current_key);
		int current_key = QuickSort(L, median);
		rank(L, current_key, key - current_key);
	}
	else 
		return A[current_key - 1];

	return 0;
}
int MF(std::vector<int>& A, int K) {
	std::vector<std::vector<int>> arraydividedfive;
	std::vector<int> temp;
	for (int i = 0; i < A.size(); i++) {
		temp.push_back(A[i]);
		if (temp.size() == 5) {
			arraydividedfive.push_back(temp);
			temp.clear();
		}
	}
	if (!temp.empty())
		arraydividedfive.push_back(temp);

	std::vector<int> median_array;

	for (auto t : arraydividedfive) {
		std::sort(t.begin(), t.end());
		median_array.push_back(t[t.size() / 2]);
	}
	std::sort(median_array.begin(), median_array.end());
	int M_value = median_array[median_array.size() / 2];
	
	return M_value;
}
