#include <iostream>
#include <vector>

/*
    Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

    The overall run time complexity should be O(log (m+n)).
*/

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    double median = 0;
    double sum1 = 0;
    double sum2 = 0;
    int max = std::max(nums1.size(), nums2.size());

    for (int i = 0; i < max; i++) {
        if (i < nums1.size()) {
            sum1 += nums1[i];
        }

        if (i < nums2.size()) {
            sum2 += nums2[i];
        }
    }

    median = (sum1 + sum2) / (nums1.size() + nums2.size());
    return median;
}

int main()
{
    std::vector<int> numbers1 = { 1, 3 , 7, 11, 5};
    std::vector<int> numbers2 = { 2, 7, 3 };

    std::cout << findMedianSortedArrays(numbers1, numbers2) << std::endl;
}
