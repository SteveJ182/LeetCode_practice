//the expected optimal answer

#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int lengthOfLongestSubstring(const string& s) {
    unordered_map<char, int> lastSeen;
    int maxLen = 0;
    int start = 0;  // Start index of current window

    for (int end = 0; end < s.length(); ++end) {
        char c = s[end];

        // If character is already in map and is within the current window
        if (lastSeen.count(c) && lastSeen[c] >= start) {
            start = lastSeen[c] + 1;  // Move start to the right of duplicate
        }

        lastSeen[c] = end;  // Update last seen index of character
        maxLen = max(maxLen, end - start + 1);  // Update max length
    }

    return maxLen;
}

int main() {
    string s = "abcabcbb";
    cout << "Length of longest substring without repeating characters: "
         << lengthOfLongestSubstring(s) << endl;

    return 0;
}
