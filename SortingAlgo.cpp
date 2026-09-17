#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// 1. BUBBLE SORT
// Time: O(n^2) | Space: O(1)
void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // Optimization: Stop if array is already sorted
        if (!swapped)
            break;
    }
}

// 2. SELECTION SORT
// Time: O(n^2) | Space: O(1)
void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        if (minIdx != i)
        {
            swap(arr[i], arr[minIdx]);
        }
    }
}

// 3. INSERTION SORT
// Time: O(n^2) | Space: O(1)
void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        // Shift elements greater than key to one position ahead
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// 4. QUICK SORT
// Partition helper function (Lomuto partition scheme)
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; // Choosing last element as pivot
    int i = low - 1;

    for (int j = low; j < high; ++j)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Time: O(n log n) average, O(n^2) worst | Space: O(log n) stack frame
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);  // Left subarray
        quickSort(arr, pivotIndex + 1, high); // Right subarray
    }
}

// 5. MERGE SORT
// Helper function to merge two sorted halves
void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    // Copy remaining elements
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

// Time: O(n log n) | Space: O(n) auxiliary memory
void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);      // Left half
        mergeSort(arr, mid + 1, right); // Right half
        merge(arr, left, mid, right);   // Merge both halves
    }
}

// Helper to print array contents
void printArray(const vector<int> &arr)
{
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << "\n";
}

int main()
{
    vector<int> original = {64, 34, 25, 12, 22, 11, 90};

    cout << "Original Array: ";
    printArray(original);
    cout << "-------------------------------------------\n";

    // 1. Bubble Sort
    vector<int> arr1 = original;
    bubbleSort(arr1);
    cout << "Bubble Sort:    ";
    printArray(arr1);

    // 2. Selection Sort
    vector<int> arr2 = original;
    selectionSort(arr2);
    cout << "Selection Sort: ";
    printArray(arr2);

    // 3. Insertion Sort
    vector<int> arr3 = original;
    insertionSort(arr3);
    cout << "Insertion Sort: ";
    printArray(arr3);

    // 4. Quick Sort
    vector<int> arr4 = original;
    quickSort(arr4, 0, arr4.size() - 1);
    cout << "Quick Sort:     ";
    printArray(arr4);

    // 5. Merge Sort
    vector<int> arr5 = original;
    mergeSort(arr5, 0, arr5.size() - 1);
    cout << "Merge Sort:     ";
    printArray(arr5);

    return 0;
}