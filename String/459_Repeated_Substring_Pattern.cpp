#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string doubled = s + s;
        string trimmed = doubled.substr(1, doubled.size() - 2);
        return trimmed.find(s) != string::npos;
    }
};

int main() {
    Solution solution;
    
    // Test cases
    string s1 = "abab";
    string s2 = "aba";
    string s3 = "abcabcabcabc";
    
    cout << boolalpha; // Print 'true' or 'false' instead of 1/0
    cout << "Input: \"" << s1 << "\" -> " << solution.repeatedSubstringPattern(s1) << endl;
    cout << "Input: \"" << s2 << "\" -> " << solution.repeatedSubstringPattern(s2) << endl;
    cout << "Input: \"" << s3 << "\" -> " << solution.repeatedSubstringPattern(s3) << endl;

    return 0;
}
