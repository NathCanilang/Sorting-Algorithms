#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Sort
{
public:
	int swapCount = 0;
	int iterationSwapCount = 0;

	void getArray(vector<int>& userArrayElements, int& userArrayLength)
	{
		cout << "What is the size of your array? ";
		cin >> userArrayLength;
		cout << "Enter your array (non-negative integers only)" << endl;

		for (int i = 0; i < userArrayLength; ++i) {
			int element;

			do {
				cout << "Element " << i + 1 << ": ";
				cin >> element;

				if (element < 0) {
					cout << "Please enter a non-negative integer." << endl;
				}
			} while (element < 0);

			userArrayElements.push_back(element);
		}
	}

	void BubbleSortAscending(int arrayLength, int arrayElements[])
	{
		int iterations = 0;
		int totalSwaps = 0;

		for (int i = 0; i < arrayLength; i++)
		{
			bool swapped = false;

			for (int j = 0; j < arrayLength - 1; j++)
			{
				if (arrayElements[j] > arrayElements[j + 1])
				{
					int temp = arrayElements[j];
					arrayElements[j] = arrayElements[j + 1];
					arrayElements[j + 1] = temp;

					swapped = true;
					totalSwaps++;
				}
			}

			iterations++;

			if (!swapped)
			{
				cout << "Array is already sorted. Exiting early." << endl;
				break;
			}
		}

		cout << "Sorted array in ascending order: ";
		for (int i = 0; i < arrayLength; i++)
		{
			cout << arrayElements[i] << " ";
		}
		cout << endl;

		cout << "Total iterations: " << iterations << endl;
		cout << "Total swaps (steps): " << totalSwaps << endl;
	}

	void BubbleSortDescending(int arrayLength, int arrayElements[])
	{
		int iterations = 0;
		int totalSwaps = 0;

		for (int i = 0; i < arrayLength; i++)
		{
			bool swapped = false;

			for (int j = 0; j < arrayLength - 1; j++)
			{
				if (arrayElements[j] < arrayElements[j + 1])
				{
					int temp = arrayElements[j];
					arrayElements[j] = arrayElements[j + 1];
					arrayElements[j + 1] = temp;

					swapped = true;
					totalSwaps++;
				}
			}

			iterations++;

			if (!swapped)
			{
				cout << "Array is already sorted. Exiting early." << endl;
				break;
			}
		}

		cout << "Sorted array in descending order: ";
		for (int i = 0; i < arrayLength; i++)
		{
			cout << arrayElements[i] << " ";
		}
		cout << endl;

		cout << "Total iterations: " << iterations << endl;
		cout << "Total swaps (steps): " << totalSwaps << endl;
	}

	void SelectionSortAscending(int arrayLength, int arrayElements[])
	{
		int iteration = 0;
		int totalSwaps = 0;
		int minIndexChanges = 0;

		for (int i = 0; i < arrayLength - 1; i++)
		{
			int minPosition = i;
			for (int j = i + 1; j < arrayLength; j++)
			{
				if (arrayElements[j] < arrayElements[minPosition])
				{
					minPosition = j;
					minIndexChanges++;
				}
			}

			if (minPosition != i)
			{
				int temp = arrayElements[i];
				arrayElements[i] = arrayElements[minPosition];
				arrayElements[minPosition] = temp;

				totalSwaps++;
			}

			iteration++;
		}

		cout << "Sorted array in ascending order: ";
		for (int i = 0; i < arrayLength; i++)
		{
			cout << arrayElements[i] << " ";
		}
		cout << endl;

		cout << "Total iterations: " << iteration << endl;
		cout << "Total steps (swaps): " << minIndexChanges << endl;
	}

	void SelectionSortDescending(int arrayLength, int arrayElements[])
	{
		int iteration = 0;
		int totalSwaps = 0;
		int maxIndexChanges = 0;

		for (int i = 0; i < arrayLength - 1; i++)
		{
			int maxPosition = i;
			for (int j = i + 1; j < arrayLength; j++)
			{
				if (arrayElements[j] > arrayElements[maxPosition])
				{
					maxPosition = j;
					maxIndexChanges++;
				}
			}

			if (maxPosition != i)
			{
				int temp = arrayElements[i];
				arrayElements[i] = arrayElements[maxPosition];
				arrayElements[maxPosition] = temp;

				totalSwaps++;
			}

			iteration++;
		}

		cout << "Sorted array in descending order: ";
		for (int i = 0; i < arrayLength; i++)
		{
			cout << arrayElements[i] << " ";
		}
		cout << endl;

		cout << "Total iterations: " << iteration << endl;
		cout << "Total steps(swaps):  " << maxIndexChanges << endl;
	}

	void heapify(int arr[], int n, int i, int& iteration, int& steps)
	{
		int largest = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;

		if (left < n && arr[left] > arr[largest])
		{
			largest = left;
		}


		if (right < n && arr[right] > arr[largest])
		{
			largest = right;
		}


		if (largest != i)
		{
			swap(arr[i], arr[largest]);
			steps++;
			iteration++;


			heapify(arr, n, largest, iteration, steps);
		}
	}
	void HeapSortAscending(int n, int arr[])
	{
		int iteration = 0;
		int steps = 0;


		for (int i = n / 2 - 1; i >= 0; i--)
		{
			heapify(arr, n, i, iteration, steps);
		}

		for (int i = n - 1; i > 0; i--)
		{
			swap(arr[0], arr[i]);
			steps++;
			iteration++;

			heapify(arr, i, 0, iteration, steps);
		}

		cout << "Sorted array in ascending order: ";
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;

		cout << "Total iterations: " << n - 1 << endl;
		cout << "Total steps: " << steps << endl;
	}

	void HeapSortDescending(int n, int arr[])
	{
		int iteration = 0;
		int steps = 0;

		for (int i = n / 2 - 1; i >= 0; i--)
		{
			heapify(arr, n, i, iteration, steps);
		}

		for (int i = n - 1; i > 0; i--)
		{
			swap(arr[0], arr[i]);
			steps++;
			iteration++;

			heapify(arr, i, 0, iteration, steps);
		}

		cout << "Sorted array in descending order: ";
		for (int i = n - 1; i >= 0; i--)
		{
			cout << arr[i] << " ";
		}
		cout << endl;

		cout << "Total iterations: " << n - 1 << endl;
		cout << "Total steps: " << steps << endl;
	}

	void MergeSortAscending(std::vector<int>& arr)
	{
		int steps = 0;
		int iterations = 0;

		int n = arr.size();
		if (n < 2) {
			std::cout << "Array is already sorted. Exiting early." << std::endl;
			return;
		}

		mergeSort(arr, 0, n - 1, steps, iterations);

		std::cout << "Sorted array in ascending order: ";
		for (int i = 0; i < n; i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;

		std::cout << "Total iterations: " << iterations << std::endl;
		std::cout << "Total swaps (steps): " << steps << std::endl;
	}

	void mergeSort(std::vector<int>& arr, int low, int high, int& steps, int& iterations) {
		if (low < high) {
			iterations++;
			int mid = low + (high - low) / 2;
			mergeSort(arr, low, mid, steps, iterations);
			mergeSort(arr, mid + 1, high, steps, iterations);

			merge(arr, low, mid, high, steps);
		}
	}

	void merge(std::vector<int>& arr, int left, int mid, int right, int& steps) {
		int n1 = mid - left + 1;
		int n2 = right - mid;

		std::vector<int> L(n1);
		std::vector<int> R(n2);

		for (int i = 0; i < n1; i++)
			L[i] = arr[left + i];
		for (int j = 0; j < n2; j++)
			R[j] = arr[mid + 1 + j];

		int i = 0;
		int j = 0;
		int k = left;

		while (i < n1 && j < n2) {
			steps++;
			if (L[i] <= R[j]) {
				arr[k] = L[i];
				i++;
			}
			else {
				arr[k] = R[j];
				j++;
			}
			k++;
		}

		while (i < n1) {
			arr[k] = L[i];
			i++;
			k++;
		}

		while (j < n2) {
			arr[k] = R[j];
			j++;
			k++;
		}
	}
	void MergeSortDescending(std::vector<int>& arr)
	{
		int steps = 0;
		int iterations = 0;

		int n = arr.size();
		if (n < 2) {
			std::cout << "Array is already sorted. Exiting early." << std::endl;
			return;
		}

		mergeSortDesc(arr, 0, n - 1, steps, iterations);

		std::cout << "Sorted array in descending order: ";
		for (int i = 0; i < n; i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;

		std::cout << "Total iterations: " << iterations << std::endl;
		std::cout << "Total swaps (steps): " << steps << std::endl;
	}

	void mergeSortDesc(std::vector<int>& arr, int low, int high, int& steps, int& iterations) {
		if (low < high) {
			iterations++;
			int mid = low + (high - low) / 2;
			mergeSortDesc(arr, low, mid, steps, iterations);
			mergeSortDesc(arr, mid + 1, high, steps, iterations);

			mergeDesc(arr, low, mid, high, steps);
		}
	}

	void mergeDesc(std::vector<int>& arr, int left, int mid, int right, int& steps) {
		int n1 = mid - left + 1;
		int n2 = right - mid;

		std::vector<int> L(n1);
		std::vector<int> R(n2);

		for (int i = 0; i < n1; i++)
			L[i] = arr[left + i];
		for (int j = 0; j < n2; j++)
			R[j] = arr[mid + 1 + j];

		int i = 0;
		int j = 0;
		int k = left;

		while (i < n1 && j < n2) {
			steps++;
			if (L[i] >= R[j]) { // This line is changed to sort in descending order
				arr[k] = L[i];
				i++;
			}
			else {
				arr[k] = R[j];
				j++;
			}
			k++;
		}

		while (i < n1) {
			arr[k] = L[i];
			i++;
			k++;
		}

		while (j < n2) {
			arr[k] = R[j];
			j++;
			k++;
		}
	}
};

int main()
{
	int userResponseForSortType;
	int userResponseForOperationRepeat;
	int userArrayLength;
	int userResponseForPattern;
	vector<int> userArrayElements;
	bool invalidInput = false;
	bool invalidInputForPattern = false;
	Sort sorter;
	do
	{
		invalidInput = false;
		cout << "Menu!" << endl;
		cout << "[1] Merge Sort" << endl;
		cout << "[2] Bubble Sort" << endl;
		cout << "[3] Selection Sort" << endl;
		cout << "[4] Heap Sort\n"
			<< endl;
		cout << "What type of sorting would you use?" << endl;

		do
		{
			invalidInputForPattern = false;
			cin >> userResponseForSortType;
			switch (userResponseForSortType)
			{
			case 1:
				cout << "You have selected Merge Sort." << endl;
				sorter.getArray(userArrayElements, userArrayLength);
				do
				{
					cout << "[1] Ascending Pattern" << endl;
					cout << "[2] Descending Pattern" << endl;
					cout << "Select Sorting Arrangement:";
					cin >> userResponseForPattern;

					switch (userResponseForPattern)
					{
					case 1:
						sorter.MergeSortAscending(userArrayElements);
						break;

					case 2:
						sorter.MergeSortDescending(userArrayElements);
						break;

					default:
						cout << "Invalid Input. Try Again" << endl;
						invalidInputForPattern = true;
						break;
					}
				} while (invalidInputForPattern);
				break;

			case 2:
				cout << "You have selected Bubble Sort." << endl;
				sorter.getArray(userArrayElements, userArrayLength);
				do
				{
					cout << "[1] Ascending Pattern" << endl;
					cout << "[2] Descending Pattern" << endl;
					cout << "Select Sorting Arrangement:";
					cin >> userResponseForPattern;

					switch (userResponseForPattern)
					{
					case 1:
						sorter.BubbleSortAscending(userArrayLength, userArrayElements.data());
						break;

					case 2:
						sorter.BubbleSortDescending(userArrayLength, userArrayElements.data());
						break;

					default:
						cout << "Invalid Input. Try Again" << endl;
						invalidInputForPattern = true;
						break;
					}
				} while (invalidInputForPattern);
				break;

			case 3:
				cout << "You have selected Selection Sort." << endl;
				sorter.getArray(userArrayElements, userArrayLength);
				do
				{
					cout << "[1] Ascending Pattern" << endl;
					cout << "[2] Descending Pattern" << endl;
					cout << "Select Sorting Arrangement:";
					cin >> userResponseForPattern;

					switch (userResponseForPattern)
					{
					case 1:
						sorter.SelectionSortAscending(userArrayLength, userArrayElements.data());
						break;

					case 2:
						sorter.SelectionSortDescending(userArrayLength, userArrayElements.data());
						break;

					default:
						cout << "Invalid Input. Try Again" << endl;
						invalidInputForPattern = true;
						break;
					}
				} while (invalidInputForPattern);
				break;

			case 4:
				cout << "You have selected Heap Sort." << endl;
				sorter.getArray(userArrayElements, userArrayLength);
				do
				{
					cout << "[1] Ascending Pattern" << endl;
					cout << "[2] Descending Pattern" << endl;
					cout << "Select Sorting Arrangement:";
					cin >> userResponseForPattern;

					switch (userResponseForPattern)
					{
					case 1:
						sorter.HeapSortAscending(userArrayLength, userArrayElements.data());
						break;

					case 2:
						sorter.HeapSortDescending(userArrayLength, userArrayElements.data());
						break;

					default:
						cout << "Invalid Input. Try Again" << endl;
						invalidInputForPattern = true;
						break;
					}
				} while (invalidInputForPattern);
				break;

			default:
				cout << "Input Error. Try Again" << endl;
				invalidInput = true;
				break;
			}
		} while (invalidInput);
		if (!invalidInput)
		{
			cout << "Do you want to try again? (1 for Yes, 0 for No)" << endl;
			cin >> userResponseForOperationRepeat;
		}
	} while (userResponseForOperationRepeat == 1);
	return 0;
}