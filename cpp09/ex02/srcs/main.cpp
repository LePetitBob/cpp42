#include "PmergeMe.hpp"

// #include <iostream>
// #include <vector>
// #include <utility>

// void merge(std::vector<int>& arr, int left, int mid, int right) {
//     std::vector<int> temp(right - left + 1);
//     int i = left, j = mid + 1, k = 0;

//     while (i <= mid && j <= right) {
//         if (arr[i] <= arr[j]) {
//             temp[k++] = arr[i++];
//         } else {
//             temp[k++] = arr[j++];
//         }
//     }

//     while (i <= mid) {
//         temp[k++] = arr[i++];
//     }
//     while (j <= right) {
//         temp[k++] = arr[j++];
//     }

//     for (int m = 0; m < k; ++m) {
//         arr[left + m] = temp[m];
//     }
// }

// void mergeInsertSort(std::vector<int>& arr, int left, int right) {
//     // Base case: if there's 1 or fewer elements
//     if (left >= right) return;

//     // Create pairs and sort them
//     std::vector<int> pairs;

//     for (int i = left; i <= right; i += 2) {
//         if (i + 1 <= right) {
//             // Store the sorted pair
//             if (arr[i] <= arr[i + 1]) {
//                 pairs.push_back(arr[i]);
//                 pairs.push_back(arr[i + 1]);
//             } else {
//                 pairs.push_back(arr[i + 1]);
//                 pairs.push_back(arr[i]);
//             }
//         } else {
//             pairs.push_back(arr[i]); // Add the last single element if the size is odd
//         }
//     }

//     // If there is only one pair, copy it back
//     if (pairs.size() == 1) {
//         arr[left] = pairs[0];
//         return;
//     }

//     // Recursively sort the pairs
//     mergeInsertSort(pairs, 0, pairs.size() - 1);

//     // Copy sorted pairs back to the original array
//     for (std::size_t i = 0; i < pairs.size(); ++i) {
//         arr[left + i] = pairs[i];
//     }

//     // Merge the sorted pairs back into the original array
//     if (pairs.size() > 1) {
//         merge(arr, left, left + pairs.size() / 2 - 1, right);
//     }
// }

// void mergeInsertSortWrapper(std::vector<int>& arr) {
//     mergeInsertSort(arr, 0, arr.size() - 1);
// }

// int main() {
//     std::vector<int> arr;
//     arr.push_back(38);
//     arr.push_back(27);
//     arr.push_back(43);
//     arr.push_back(3);
//     arr.push_back(9);
//     arr.push_back(82);
//     arr.push_back(10);

//     std::cout << "Unsorted array: ";
//     for (size_t i = 0; i < arr.size(); ++i) {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << std::endl;

//     mergeInsertSortWrapper(arr);

//     std::cout << "Sorted array: ";
//     for (size_t i = 0; i < arr.size(); ++i) {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << std::endl;

//     return 0;
// }



int main(int ac, char **av) {
    std::vector<int> vec;
    std::deque<int> deq;

    check_and_fill(ac, av, vec, deq);

    int n = vec.size();

	struct timeval tp, tp2;

    std::cout << "Before : ";
    for (int i = 0; i < n; ++i)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
    
    gettimeofday(&tp, NULL);
    mergeInsertionSort<std::vector<int> >(vec);
    gettimeofday(&tp2, NULL);

    std::cout << "After : ";
    for (int i = 0; i < n; ++i)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

	unsigned long micro = tp.tv_usec + 1000000 * tp.tv_sec, micro2 = tp2.tv_usec + 1000000 * tp2.tv_sec;
    std::cout << "Time to process a range of "<< ac - 1 <<" elements with std::vector : " << micro2 - micro << " us" << std::endl;

    gettimeofday(&tp, NULL);
    mergeInsertionSort<std::deque<int> >(deq);
    gettimeofday(&tp2, NULL);

	micro = tp.tv_usec + 1000000 * tp.tv_sec, micro2 = tp2.tv_usec + 1000000 * tp2.tv_sec;
    std::cout << "Time to process a range of "<< ac - 1 <<" elements with std::deque : " << micro2 - micro << " us" << std::endl;
    
    return 0;
}