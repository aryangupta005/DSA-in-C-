class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int begin1 = 0;
        int end1 = m;

        while (begin1 <= end1) {
            int i1 = (begin1 + end1) / 2;
            int i2 = (m + n + 1) / 2 - i1;

            int min1 = INT_MAX;
            if (i1 < m) {
                min1 = nums1[i1];
            }

            int max1 = INT_MIN;
            if (i1 > 0) {
                max1 = nums1[i1 - 1];
            }

            int min2 = INT_MAX;
            if (i2 < n) {
                min2 = nums2[i2];
            }

            int max2 = INT_MIN;
            if (i2 > 0) {
                max2 = nums2[i2 - 1];
            }

            if (max1 <= min2 && max2 <= min1) {
                if ((m + n) % 2 == 0) {
                    return (double)(max(max1, max2) + min(min1, min2)) / 2;
                } else {
                    return (double)max(max1, max2);
                }
            } else if (max1 > min2) {
                end1 = i1 - 1;
            } else {
                begin1 = i1 + 1;
            }
        }
        return 0.0;
    }
};
