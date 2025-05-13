#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, int> countSub(const string& str, int length){
        unordered_map<string, int> subCount;
        for(size_t i=0; i<=str.size() - length; i++){
            string sub = str.substr(i, length);
            subCount[sub]++;
        }
        return subCount;
    }

int main() {
    string s = "banana";
        int len =1;
    unordered_map<string, int> result; // Declare outside the loop
    for (int len = 1; len <= s.size(); ++len) {
        auto partialResult = countSub(s, len);
        for (const auto& pair : partialResult) {
            result[pair.first] += pair.second; // Accumulate counts
        }
    }
        for(const auto& pair : result){
            cout << pair.first << ": " << pair.second << endl;
            /*for(int i=0; i<= pair.first.size(); i++){
                if
            }*/
        }

    return 0;
}
