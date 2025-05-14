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
    
int SubstringCount(const string& s){
        int sub_size=0;
        //int len =1;
    //get all possible substrings    
    unordered_map<string, int> result; // Declare outside the loop
    for (int len = 0; len <= s.size(); ++len) {
        auto partialResult = countSub(s, len);
        for (const auto& pair : partialResult) {
            result[pair.first] += pair.second; // Accumulate counts
        }
    }
    
    //iterate through map
    int largest=0, current=0;
        for(const auto& pair : result){
            cout << pair.first << ": " << pair.second << endl;
            //checks if sub string is the same string
            const string& sub = pair.first;
            /*if substring is recognized repeated as many times as the size of string, then check if string consists of a single repeated character*/
                if(pair.second == s.size()){
                    return sub_size =1;
                }
           // if()
                
                
            
            
        }
return sub_size;
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
