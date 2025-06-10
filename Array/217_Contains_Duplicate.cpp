#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int num : nums) {
            if (seen.count(num)) {
                return true; // duplicate found
            }
            seen.insert(num);
        }

        return false; // no duplicates
    }
};

int main() {
    Solution solution;

    // Example test case
    vector<int> nums = {1, 2, 3, 4, 1}; // change this to test other cases

    if (solution.containsDuplicate(nums)) {
        cout << "Duplicate exists!" << endl;
    } else {
        cout << "No duplicates found." << endl;
    }

    return 0;
}
