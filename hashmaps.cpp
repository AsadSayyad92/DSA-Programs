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


// class Solution {
// public:
//     int findLucky(vector<int>& arr) {
//         unordered_map<int,int>freq;
//         int result = -1;

//         // for counting the frequency
//         for(int num:arr){
//             freq[num]++;
//         }

//         //check for lucky number
//         for(const auto& entry :freq){
//             int num = entry.first;
//             int count = entry.second;

//             if(num==count){
//                 result = max(result,num);
//             }
//         }
//         return result;
//     }
// };