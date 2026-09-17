#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1. LINEAR SEARCH
// Time Complexity: O(n) | Space Complexity: O(1)
// Works on both sorted and unsorted arrays.
int linearSearch(const vector<int> &arr, int target)
{
    for (size_t i = 0; i < arr.size(); ++i)
    {
        if (arr[i] == target)
        {
            return i; // Target found, return index
        }
    }
    return -1; // Target not found
}

// 2. BINARY SEARCH (Iterative)
// Time Complexity: O(log n) | Space Complexity: O(1)
// Requires a SORTED array.
int binarySearch(const vector<int> &arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2; // Prevents potential integer overflow
        if (arr[mid] == target)
        {
            return mid; // Target found
        }
        else if (arr[mid] < target)
        {
            low = mid + 1; // Target is in the right half
        }
        else
        {
            high = mid - 1; // Target is in the left half
        }
    }
    return -1; // Target not found
}

// 3. INTERPOLATION SEARCH
// Time Complexity: O(log(log n)) average, O(n) worst-case | Space Complexity: O(1)
// Requires a SORTED and UNIFORMLY DISTRIBUTED array.
int interpolationSearch(const vector<int> &arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;

    // Target must be within the bounds of the array elements
    while (low <= high && target >= arr[low] && target <= arr[high])
    {
        if (low == high)
        {
            if (arr[low] == target)
                return low;
            return -1;
        }

        // Estimating the position using interpolation formula
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]));

        if (arr[pos] == target)
        {
            return pos; // Target found
        }
        else if (arr[pos] < target)
        {
            low = pos + 1; // Target lies higher in the array
        }
        else
        {
            high = pos - 1; // Target lies lower in the array
        }
    }
    return -1; // Target not found
}

// Helper function to print search results cleanly
void printResult(const string &searchName, int index)
{
    if (index != -1)
    {
        cout << "[" << searchName << "] Element found at index: " << index << "\n";
    }
    else
    {
        cout << "[" << searchName << "] Element not found.\n";
    }
}

int main()
{
    // Input array (Must be sorted for Binary and Interpolation search)
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int target = 70;

    cout << "Array: ";
    for (int val : arr)
        cout << val << " ";
    cout << "\nTarget to search: " << target << "\n\n";

    // Perform Searches
    int linearIdx = linearSearch(arr, target);
    printResult("Linear Search", linearIdx);

    int binaryIdx = binarySearch(arr, target);
    printResult("Binary Search", binaryIdx);

    int interpIdx = interpolationSearch(arr, target);
    printResult("Interpolation Search", interpIdx);

    return 0;
}