class Solution {
public:
    bool isHappy(int n) {
        // Basically we want to see if we can keep squaring it till we get a 1
        // we would not be able to get a 1 if we have a cycle -> so we need to make sure we can
        // detect that and exit properly

        // Floyd's cycle detection 
        int slow = n, fast = getNext(n);

        while (fast != 1 && slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }

        return fast == 1;
    }

private: 
    int getNext(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        return sum;
    }
};
