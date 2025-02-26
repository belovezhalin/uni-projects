#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    vector<string> words;
    unordered_set<string> words_set;
    string word;

    while (cin >> word) {
        words.push_back(word);
        words_set.insert(word);
    }

    vector<string> composite_words;

    for(const auto& w : words) {
        int len = w.size();
        for(int i = 1; i < len; i++) {
            string prefix = w.substr(0, i);
            string suffix = w.substr(i);
            if(words_set.find(prefix) != words_set.end() && words_set.find(suffix) != words_set.end()) {
                composite_words.push_back(w);
                break;
            }
        }
    }

    sort(composite_words.begin(), composite_words.end());             //wedlug alfabetu

    for(const auto& cw : composite_words) {
        cout << cw << endl;
    }

    return 0;
}
