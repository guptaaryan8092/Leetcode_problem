#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;

        for (string word : strs) {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());  // sort the word

            anagramGroups[sortedWord].push_back(word);   // group by sorted word
        }

        // Extract result from map
        vector<vector<string>> result;
        for (auto& pair : anagramGroups) {
            result.push_back(pair.second);
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> output = sol.groupAnagrams(input);

    cout << "[\n";
    for (const auto& group : output) {
        cout << "  [ ";
        for (const auto& word : group) {
            cout << "\"" << word << "\", ";
        }
        cout << "],\n";
    }
    cout << "]\n";

    return 0;
}
