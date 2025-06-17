#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        int count[26] = {0};  // Frequency array for a-z

        for (int i = 0; i < s.length(); ++i) {
            count[s[i] - 'a']++;  // increment for s
            count[t[i] - 'a']--;  // decrement for t
        }

        for (int i = 0; i < 26; ++i) {
            if (count[i] != 0) return false;
        }

        return true;
    }
};

int main() {
    Solution sol;

    string s1 = "anagram";
    string t1 = "nagaram";
    string s2 = "rat";
    string t2 = "car";

    cout << boolalpha;  // Show true/false instead of 1/0
    cout << "Is Anagram (\"" << s1 << "\", \"" << t1 << "\"): " << sol.isAnagram(s1, t1) << endl;
    cout << "Is Anagram (\"" << s2 << "\", \"" << t2 << "\"): " << sol.isAnagram(s2, t2) << endl;

    return 0;
}
