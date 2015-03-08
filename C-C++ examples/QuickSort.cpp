//============================================================================
// Name        : HashTable.cpp
// Author      : Juan Micah Quinland
// Version     :
// Description : Quicksort implementation			 			
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

/**
 * Internal insertion sort routine for subarrays
 * that is used by quicksort.
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
template<typename Comparable>
void insertionSort(vector<Comparable> & a, int left, int right)
{
	for (int p = left + 1; p <= right; p++)
	{
		Comparable tmp = a[p];
		int j;

		for (j = p; j > left && tmp < a[j - 1]; j--)
			a[j] = a[j - 1];
		a[j] = tmp;
	}
}

/**
 * Internal quicksort method that makes recursive calls.
 * Uses median-of-three partitioning and a cutoff of 10.
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */


/**
 * Return median of left, center, and right.
 * Order these and hide the pivot.
 */
template<typename Comparable>
const Comparable & median3(vector<Comparable> & a, int left, int right)
{
	int center = (left + right) / 2;
	cout << "In: " << a[left] << ", " << a[center] << ", " << a[right] << endl;
	if (a[center] < a[left])
		swap(a[left], a[center]);
	if (a[right] < a[left])
		swap(a[left], a[right]);
	if (a[right] < a[center])
		swap(a[center], a[right]);

	// Place pivot at position right - 1
	swap(a[center], a[right - 1]);
	cout <<  "Out: " << a[left] << ", " << a[center] << ", " << a[right] << endl;
	return a[right - 1];
}

/**
 * Quicksort algorithm (driver).
 */


void printVector(vector<int> & h)
{
	unsigned int i;
	cout << "Start:" << endl;
	for (i = 0; i < h.size(); ++i)
	{
		cout << "h[" << i << "] = " << h[i] << endl;
	} // end for
	cout << "End." << endl;
}
template<typename Comparable>
void quicksort(vector<Comparable> & a, int left, int right)
{
	if (left + 3 <= right)
	{
		Comparable pivot = median3(a, left, right);

		// Begin partitioning
		int i = left, j = right - 1;
		for (;;)
		{
			while (a[++i] < pivot)
			{
			}
			while (pivot < a[--j])
			{
			}
			if (i < j)
				swap(a[i], a[j]);
			else
				break;
		}

		swap(a[i], a[right - 1]); // Restore pivot

		quicksort(a, left, i - 1); // Sort small elements
		quicksort(a, i + 1, right); // Sort large elements
	}
	else
		// Do an insertion sort on the subarray
		insertionSort(a, left, right);
}
template<typename Comparable>
void quicksort(vector<Comparable> & a)
{
	quicksort(a, 0, a.size() - 1);
}
int main()
{
	vector<int> h(11);

	h[0] = 3;
	h[1] = 1;
	h[2] = 4;
	h[3] = 1;
	h[4] = 5;
	h[5] = 9;
	h[6] = 2;
	h[7] = 6;
	h[8] = 5;
	h[9] = 3;
	h[10] = 5;
	

	printVector(h);
	quicksort(h);
	printVector(h);
	return 0;
}
