#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <unordered_set>

using namespace std;

bool isPalindrome(const string& word) {
    int left = 0, right = word.size() - 1;
    while (left < right) {
        if (tolower(word[left]) != tolower(word[right])) return false;
        left++; right--;
    }
    return true;
}

int countConsonants(const string& word) {
    return count_if(word.begin(), word.end(), [](char c) {
        return isalpha(c) && !strchr("aeiouAEIOU", c);
        });
}

string duplicateVowels(const string& word) {
    string result;
    for (char c : word) {
        result += c;
        if (strchr("aeiouAEIOU", c)) result += c;
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "Russian");
    string input;
    cout << "Введите текст (не более 10 кБ): ";
    getline(cin, input);

    istringstream iss(input);
    vector<string> words;
    unordered_set<string> palindromes;

    for (string word; iss >> word; ) {
        word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
        words.push_back(word);
        if (word.length() > 1 && isPalindrome(word)) palindromes.insert(word);
    }

    if (palindromes.empty()) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return countConsonants(a) > countConsonants(b);
            });
    }
    else {
        for (auto& w : words) w = duplicateVowels(w);
        sort(words.rbegin(), words.rend()); 
    }

    cout << "Результат:\n";
    for (const auto& w : words) cout << w << "\n";

    return 0;
}
