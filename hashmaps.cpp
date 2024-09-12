#include <iostream>
#include <unordered_map>
#include <sstream>
using namespace std;

int main() {
    string text = "hello world hello";
    unordered_map<string, int> wordCount;
    stringstream ss(text);
    string word;

    // Count the frequency of each word
    while (ss >> word) {
        wordCount[word]++;
    }

    // Display the frequency count
    for (const auto& pair : wordCount) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}


class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>freq;
        int result = -1;

        // for counting the frequency
        for(int num:arr){
            freq[num]++;
        }

        //check for lucky number
        for(const auto& entry :freq){
            int num = entry.first;
            int count = entry.second;

            if(num==count){
                result = max(result,num);
            }
        }
        return result;
    }
};

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> freq_s;
        unordered_map<char,char> freq_t;

        if(s.size()!=t.size()){
            return false;
        }

        for(int i=0;i<s.size();i++){
            char c1 = s[i];
            char c2 = t[i];

            if(freq_s.count(c1) && freq_s[c1]!= c2 ||  freq_t.count(c2) && freq_t[c2]!=c1){
                return false;
            } 

            freq_s[c1] = c2;
            freq_t[c2] = c1;
        }
        return true;
        
    }
};
    