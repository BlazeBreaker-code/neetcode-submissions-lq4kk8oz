class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> *A = &nums1, *B = &nums2;
        if (B->size() < A->size()) std::swap(A, B);
        int m = A->size(), n = B->size();
        int total = m + n;
        int half = (total + 1) / 2; // total number that should be on both sides to be considered half

        int left = 0, right = m;
        while (left <= right) {
            int aMid = left + (right - left) / 2;
            int bMid = half - aMid;

            int Aleft   = (aMid == 0) ? INT_MIN : (*A)[aMid - 1];
            int Aright  = (aMid == m) ? INT_MAX : (*A)[aMid];
            int Bleft   = (bMid == 0) ? INT_MIN : (*B)[bMid - 1];
            int Bright  = (bMid == n) ? INT_MAX : (*B)[bMid];

            if (Aleft <= Bright && Bleft <= Aright) {
                if (total % 2 != 0) return std::max(Aleft, Bleft);
                return (std::max(Aleft, Bleft) + std::min(Aright, Bright)) / 2.0;
            } else if (Aleft > Bleft) {
                right = aMid - 1;
            } else {
                left = aMid + 1;
            }
        }

        return -1;
    }
};
