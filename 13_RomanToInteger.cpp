#include <iostream>
using namespace std;
#include <cctype>  // for toupper()


class Solution {
public:
    int char2num(char a) {
        a = toupper(a);
        switch (a) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }

    int romanToInt(string s) {
        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i + 1 < s.length() && char2num(s[i]) < char2num(s[i + 1])) {
                result -= char2num(s[i]);
            } else {
                result += char2num(s[i]);
            }
        }
        return result;
    }
};

int main() {
    string s;
    cout << "Enter the Roman numeral: ";
    cin >> s;

    Solution sol; 
    int result = sol.romanToInt(s); 
    cout << "Integer value: " << result << endl;

    return 0;
}
