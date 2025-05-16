#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int SubstringCount(const string& s){
    unordered_set<char> seen; // Set to store characters in the current window (no duplicates allowed)
    int left = 0, right = 0;  // Two pointers defining the sliding window
    int sub_size = 0;         // Keeps track of the maximum length found so far

    while (right < s.length()) { // Loop until the right pointer reaches the end of the string
        if (!seen.count(s[right])) { // If current character is not in the set (i.e., not a duplicate)
        //this piece of code accesses the character at the index before being updating to next value. a two in one solution essentially
            seen.insert(s[right++]); // Add character to set and move right pointer forward
            sub_size = max(sub_size, right - left); // Update max length if current window is larger
        } else {
            // If duplicate found, shrink window from the left by removing characters
            seen.erase(s[left++]); // Remove leftmost character and move left pointer forward
        }
    }

    return sub_size; // Return the length of the longest substring with all unique characters
}

int main() {
    string s = "abcabcbb";
    int length = SubstringCount(s);
    
    if(length){
        cout << "found a single character string of size = " << length << endl; 
    }
    else{cout << "single character not found string found: size = " << length << endl;}



    return 0;
}
