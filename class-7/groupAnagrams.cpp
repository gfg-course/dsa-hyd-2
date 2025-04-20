#include<bits/stdc++.h>
using namespace std;

string getFrequencyString(string &s) {
    vector<int> freq(26, 0);

    for (int i = 0; i < s.length(); i++) {
        freq[s[i] - 'a']++;
    }

    string key = "";
    for (int i = 0; i < 26; i++) {
        key.append(to_string(freq[i]));
        key.append("#");
    }

    return key;
}

// TC: O(nm)
// AS: O(nm) // TODO -> O(n)
vector<vector<string>> groupAnagrams(vector<string> arr) {

    unordered_map<string, vector<string>> map;

    int n = arr.size();
    for (int i = 0; i < n; i++) {
        string key = getFrequencyString(arr[i]);

        // If the key is not present in the map, initialize an empty list
        // for that key.
        if (map.find(key) == map.end()) {
            map[key] = {};
        }

        map[key].push_back(arr[i]);
    }

    vector<vector<string>> result;
    for (auto entry : map) {
        result.push_back(entry.second);
    }

    return result;
}

int main() {
    
    vector<vector<string>> res = groupAnagrams({"act", "cat", "god", "tac", "dog"});
    for (auto i : res) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
} 