#include <iostream>
#include <algorithm>

using namespace std;
struct maxSubarry {
	int left_index;
	int right_index;
	int maximum_value;
};

maxSubarry recursiveFunction(int A[], int left, int right) {
	if (left == right)
		return { left,right,A[left] };
	int mid = (left + right) / 2;
	maxSubarry maxLeft = recursiveFunction(A, left, mid);	//T(n/2)
	maxSubarry maxRight = recursiveFunction(A, mid + 1, right); //T(n/2)
	int maxMid = A[mid], temp = A[mid];
	int mL = mid - 1, mR = mid + 1;			
	int i = mid, j = mid;
	for (; mL >= left; --mL) {			//check max value from middle to left O(n/2)
		temp += A[mL];
		if (temp > maxMid) {
			maxMid = temp;
			i = mL;
		}
	}
	temp = maxMid;
	for (; mR <= right; ++mR) {			//check max value from middle to right O(n/2)
		temp += A[mR];
		if (temp > maxMid) {
			maxMid = temp;
			j = mR;
		}
	}
	int finalMax = max({ maxLeft.maximum_value,maxMid,maxRight.maximum_value }); //max function from algorithm API that find max value with three elements 
	if (finalMax == maxLeft.maximum_value)										//constant runtime O(1) here
		return maxLeft;
	else if (finalMax == maxRight.maximum_value)
		return maxRight;
	else
		return { i,j,maxMid };
}
//T(n) = 2T(n/2) + n ->rutime for this code 

int main() {

	int A[] = { -2,4,6,-5,-4,2,-7,8 };
	maxSubarry maxsubarry = recursiveFunction(A, 0, 7);
	cout << "( " << maxsubarry.left_index+1 << ", " << maxsubarry.right_index +1<< ", " << maxsubarry.maximum_value << " )";




	return 0;
}
