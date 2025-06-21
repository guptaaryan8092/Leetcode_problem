#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0;  // Position to write compressed characters
        int read = 0;   // Position to read characters

        while (read < chars.size()) {
            char currentChar = chars[read];
            int count = 0;

            // Count how many times the current character repeats
            while (read < chars.size() && chars[read] == currentChar) {
                read++;
                count++;
            }

            // Write the character
            chars[write++] = currentChar;

            // If count > 1, write the digits of count
            if (count > 1) {
                string countStr = to_string(count);
                for (char c : countStr) {
                    chars[write++] = c;
                }
            }
        }

        return write; // New length of the compressed array
    }
};
