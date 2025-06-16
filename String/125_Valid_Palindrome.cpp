#include <iostream>
#include <string>
#include <cctype>  // for isalnum and tolower

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;

        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};

int main() {
    Solution sol;

    string input1 = "A man, a plan, a canal: Panama";
    string input2 = "race a car";
    string input3 = " ";

    cout << boolalpha; // prints 'true'/'false' instead of 1/0
    cout << "Input: \"" << input1 << "\" => " << sol.isPalindrome(input1) << endl;
    cout << "Input: \"" << input2 << "\" => " << sol.isPalindrome(input2) << endl;
    cout << "Input: \"" << input3 << "\" => " << sol.isPalindrome(input3) << endl;

    return 0;
}
