class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> *A = &nums1, *B = &nums2;
        if (B->size() < A->size()) std::swap(A, B);
        int m = A->size(), n = B->size();
        int total = m + n;
        int half = (total + 1) / 2; // we use +1 so odd values go up 1 and become even so our division is better
                                    // this works because even if the odd number goes up one, integer division truncates it down 
        int left = 0, right = m;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int adjMid = half - mid;

            int Aleft   = mid == 0 ? INT_MIN : (*A)[mid - 1];
            int Aright  = mid == m ? INT_MAX : (*A)[mid];
            int Bleft   = adjMid == 0 ? INT_MIN : (*B)[adjMid - 1];
            int Bright  = adjMid == n ? INT_MAX : (*B)[adjMid];

            if (Aleft <= Bright && Bleft <= Aright) {
                if (total % 2 != 0) return std::max(Aleft, Bleft); // if odd length we can just take middle
                return (std::max(Aleft, Bleft) + std::min(Aright, Bright)) / 2.0; // if even we need to divide by two
            } else if (Aleft > Bright) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }
};
