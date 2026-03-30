#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*
            Problem setup (standard constraints for this approach):
            - nums has length n + 1
            - nums values are in the range [1, n]
            - There is exactly one repeated number (could appear 2+ times)

            Key idea:
            Treat the array like a linked list where:
              "node" = an index i
              "next pointer" from i = nums[i]

            Example:
              i -> nums[i] -> nums[nums[i]] -> ...

            Because values are in [1, n], every "next" is a valid index (not 0 for typical inputs),
            and because there are n+1 nodes (indices 0..n) but only n possible next values (1..n),
            at least two indices must point to the same next index -> that creates a cycle.
            
            The duplicate value is exactly the "cycle entrance" in this graph.
        */

        /*
            Phase 1: Detect a meeting point inside the cycle (Floyd's Tortoise and Hare)

            We use two pointers:
            - slow moves 1 step each iteration: slow = nums[slow]
            - fast moves 2 steps each iteration: fast = nums[nums[fast]]

            If there is a cycle, slow and fast must eventually meet inside it.
        */
        int slow = 0;
        int fast = 0;

        // do-while ensures we move at least once (important because slow == fast initially at 0)
        do {
            slow = nums[slow];          // move slow one "next"
            fast = nums[nums[fast]];    // move fast two "next"s
        } while (slow != fast);

        /*
            At this point:
            - slow == fast
            - They are somewhere INSIDE the cycle (not necessarily at the cycle entrance)

            Now we need the cycle entrance.
            The cycle entrance corresponds to the duplicate number.

            Why does the entrance equal the duplicate number?
            - The duplicate value d means at least two different indices point to d
            - That "merge" forces a loop in the pointer-walk
            - The first index/value where the loop begins is the entrance, which is d
        */

        /*
            Phase 2: Find the cycle entrance (duplicate)

            Classic Floyd result:
            If you start:
            - one pointer at the meeting point (slow)
            - one pointer at the "head" (index 0)

            and move BOTH one step at a time:
              slow  = nums[slow]
              slow2 = nums[slow2]

            then they meet exactly at the cycle entrance.

            Intuition (short):
            - Let distance from head to entrance = k
            - Let distance from entrance to meeting point inside cycle = m
            - By the time they met, fast traveled twice as far as slow, forcing a multiple of cycle length.
            - That math implies that moving one pointer from head and one from meeting point at equal speed
              makes them land on the entrance at the same time.
        */
        int slow2 = 0; // starts from the beginning ("head" of our implicit linked list)

        // Move both pointers one step until they meet at the cycle entrance
        while (slow != slow2) {
            slow = nums[slow];     // advance from meeting point through the cycle
            slow2 = nums[slow2];   // advance from head toward the entrance
        }

        /*
            Now:
            - slow == slow2
            - This index/value is the cycle entrance
            - And the value at the entrance is the duplicate number itself

            In this problem mapping, the "node label" we're returning is the value (which equals the index we landed on),
            so returning slow or slow2 is correct (they are equal).
        */
        return slow2;
    }
};