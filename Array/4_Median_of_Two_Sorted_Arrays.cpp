#include <iostream>
#include <vector>
#include <climits> // For INT_MIN and INT_MAX
#include <stdexcept> // For invalid_argument
using namespace std;

class Solution {
public:
    // Function to find the median of two sorted arrays
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1); // Make sure nums1 is the smaller one
        }

        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;

        while (low <= high) {
            int partition1 = (low + high) / 2;
            int partition2 = (m + n + 1) / 2 - partition1;

            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];

            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];

            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                if ((m + n) % 2 == 0) {
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                } else {
                    return static_cast<double>(max(maxLeft1, maxLeft2));
                }
            } else if (maxLeft1 > minRight2) {
                high = partition1 - 1;
            } else {
                low = partition1 + 1;
            }
        }

        throw invalid_argument("Input arrays are not sorted or invalid");
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    // Call the function
    double median = solution.findMedianSortedArrays(nums1, nums2);

    // Print the result
    cout << "Median is: " << median << endl;

    return 0;
}
