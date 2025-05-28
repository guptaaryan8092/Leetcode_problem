class Solution {
public:
    // Function to find the median of two sorted arrays
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure that nums1 is the smaller array to simplify the logic
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size(); // size of nums1
        int n = nums2.size(); // size of nums2
        int low = 0, high = m; // initialize the search range for partition1

        // Perform binary search to find the partition point
        while (low <= high) {
            int partition1 = (low + high) / 2; // partition point for nums1
            int partition2 = (m + n + 1) / 2 - partition1; // partition point for nums2

            // Find the maximum element on the left side of partition1 and partition2
            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];

            // Find the minimum element on the right side of partition1 and partition2
            int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];
            int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];

            // Check if the partition is correct
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // If the total length is even, return the average of the two middle elements
                if ((m + n) % 2 == 0) {
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                } else {
                    // If the total length is odd, return the middle element
                    return static_cast<double>(max(maxLeft1, maxLeft2));
                }
            } else if (maxLeft1 > minRight2) {
                // If the partition is too far to the right, move the partition to the left
                high = partition1 - 1;
            } else {
                // If the partition is too far to the left, move the partition to the right
                low = partition1 + 1;
            }
        }
        // If the input arrays are not sorted or invalid, throw an exception
        throw invalid_argument("Input arrays are not sorted or invalid");
    }
};