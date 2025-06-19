#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int start = 0, maxLen = 1;

        for (int i = 0; i < s.length(); ++i) {
            // Odd-length palindrome
            expandAroundCenter(s, i, i, start, maxLen);
            // Even-length palindrome
            expandAroundCenter(s, i, i + 1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }

private:
    void expandAroundCenter(const string& s, int left, int right, int& start, int& maxLen) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            --left;
            ++right;
        }
    }
};

int main() {
    Solution sol;

    string input1 = "babad";
    string input2 = "cbbd";
    string input3 = "a";
    string input4 = "ac";

    cout << "Input: " << input1 << " → Longest Palindrome: " << sol.longestPalindrome(input1) << endl;
    cout << "Input: " << input2 << " → Longest Palindrome: " << sol.longestPalindrome(input2) << endl;
    cout << "Input: " << input3 << " → Longest Palindrome: " << sol.longestPalindrome(input3) << endl;
    cout << "Input: " << input4 << " → Longest Palindrome: " << sol.longestPalindrome(input4) << endl;

    return 0;
}
