#include <bits/stdc++.h>
using namespace std;


// ============================================================
// 1. REVERSE STRING
// LeetCode: https://leetcode.com/problems/reverse-string/
// ============================================================

class Solution1 {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};


// ============================================================
// 2. REVERSE WORDS IN A STRING III
// LeetCode: https://leetcode.com/problems/reverse-words-in-a-string-iii/
// ============================================================

class Solution2 {
public:
    string reverseWords(string s) {
        int start = 0;

        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }

        return s;
    }
};


// ============================================================
// 3. VALID ANAGRAM
// LeetCode: https://leetcode.com/problems/valid-anagram/
// ============================================================

class Solution3 {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        int freq[26] = {0};

        for (char c : s)
            freq[c - 'a']++;

        for (char c : t)
            freq[c - 'a']--;

        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0)
                return false;
        }

        return true;
    }
};


// ============================================================
// 4. ISOMORPHIC STRINGS
// LeetCode: https://leetcode.com/problems/isomorphic-strings/
// ============================================================

class Solution4 {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;

        int map1[256] = {0};
        int map2[256] = {0};

        for (int i = 0; i < s.size(); i++) {
            if (map1[(unsigned char)s[i]] != map2[(unsigned char)t[i]])
                return false;

            map1[(unsigned char)s[i]] = i + 1;
            map2[(unsigned char)t[i]] = i + 1;
        }

        return true;
    }
};


// ============================================================
// 5. BUDDY STRINGS
// LeetCode: https://leetcode.com/problems/buddy-strings/
// ============================================================

class Solution5 {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size())
            return false;

        if (s == goal) {
            int freq[26] = {0};

            for (char c : s) {
                freq[c - 'a']++;

                if (freq[c - 'a'] >= 2)
                    return true;
            }

            return false;
        }

        vector<int> diff;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != goal[i])
                diff.push_back(i);
        }

        if (diff.size() != 2)
            return false;

        return s[diff[0]] == goal[diff[1]] &&
               s[diff[1]] == goal[diff[0]];
    }
};


// ============================================================
// 6. DETECT CAPITAL
// LeetCode: https://leetcode.com/problems/detect-capital/
// ============================================================

class Solution6 {
public:
    bool detectCapitalUse(string word) {
        int capitalCount = 0;

        for (char c : word) {
            if (isupper(c))
                capitalCount++;
        }

        if (capitalCount == 0)
            return true;

        if (capitalCount == word.size())
            return true;

        if (capitalCount == 1 && isupper(word[0]))
            return true;

        return false;
    }
};


// ============================================================
// 7. LONG PRESSED NAME
// LeetCode: https://leetcode.com/problems/long-pressed-name/
// ============================================================

class Solution7 {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0;
        int j = 0;

        while (j < typed.size()) {

            if (i < name.size() && name[i] == typed[j]) {
                i++;
                j++;
            }
            else if (j > 0 && typed[j] == typed[j - 1]) {
                j++;
            }
            else {
                return false;
            }
        }

        return i == name.size();
    }
};


// ============================================================
// 8. GOAT LATIN
// LeetCode: https://leetcode.com/problems/goat-latin/
// ============================================================

class Solution8 {
public:
    string toGoatLatin(string sentence) {

        stringstream ss(sentence);
        string word;
        string result;

        int wordNumber = 1;

        while (ss >> word) {

            char first = tolower(word[0]);

            if (first == 'a' || first == 'e' ||
                first == 'i' || first == 'o' ||
                first == 'u') {

                // Word starts with a vowel
            }
            else {
                word = word.substr(1) + word[0];
            }

            word += "ma";

            for (int i = 0; i < wordNumber; i++)
                word += "a";

            if (!result.empty())
                result += " ";

            result += word;

            wordNumber++;
        }

        return result;
    }
};


// ============================================================
// 9. REVERSE ONLY LETTERS
// LeetCode: https://leetcode.com/problems/reverse-only-letters/
// ============================================================

class Solution9 {
public:
    string reverseOnlyLetters(string s) {

        int left = 0;
        int right = s.size() - 1;

        while (left < right) {

            if (!isalpha(s[left])) {
                left++;
            }
            else if (!isalpha(s[right])) {
                right--;
            }
            else {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }

        return s;
    }
};


// ============================================================
// 10. COUNT BINARY SUBSTRINGS
// LeetCode: https://leetcode.com/problems/count-binary-substrings/
// ============================================================

class Solution10 {
public:
    int countBinarySubstrings(string s) {

        int previousGroup = 0;
        int currentGroup = 1;
        int answer = 0;

        for (int i = 1; i < s.size(); i++) {

            if (s[i] == s[i - 1]) {
                currentGroup++;
            }
            else {
                answer += min(previousGroup, currentGroup);
                previousGroup = currentGroup;
                currentGroup = 1;
            }
        }

        answer += min(previousGroup, currentGroup);

        return answer;
    }
};


// ============================================================
// 11. VALID PALINDROME
// LeetCode: https://leetcode.com/problems/valid-palindrome/
// ============================================================

class Solution11 {
public:
    bool isPalindrome(string s) {

        int left = 0;
        int right = s.size() - 1;

        while (left < right) {

            while (left < right && !isalnum(s[left]))
                left++;

            while (left < right && !isalnum(s[right]))
                right--;

            if (tolower(s[left]) != tolower(s[right]))
                return false;

            left++;
            right--;
        }

        return true;
    }
};


// ============================================================
// 12. LONGEST COMMON PREFIX
// LeetCode: https://leetcode.com/problems/longest-common-prefix/
// ============================================================

class Solution12 {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++) {

            int j = 0;

            while (j < prefix.size() &&
                   j < strs[i].size() &&
                   prefix[j] == strs[i][j]) {
                j++;
            }

            prefix = prefix.substr(0, j);

            if (prefix.empty())
                return "";
        }

        return prefix;
    }
};


// ============================================================
// 13. STRING COMPRESSION
// LeetCode: https://leetcode.com/problems/string-compression/
// ============================================================

class Solution13 {
public:
    int compress(vector<char>& chars) {

        int write = 0;
        int i = 0;

        while (i < chars.size()) {

            char current = chars[i];
            int count = 0;

            while (i < chars.size() &&
                   chars[i] == current) {
                i++;
                count++;
            }

            chars[write++] = current;

            if (count > 1) {

                string number = to_string(count);

                for (char c : number) {
                    chars[write++] = c;
                }
            }
        }

        return write;
    }
};


// ============================================================
// 14. FIND FIRST OCCURRENCE IN A STRING
// LeetCode: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
// ============================================================

class Solution14 {
public:
    int strStr(string haystack, string needle) {

        if (needle.size() > haystack.size())
            return -1;

        for (int i = 0;
             i <= haystack.size() - needle.size();
             i++) {

            bool found = true;

            for (int j = 0; j < needle.size(); j++) {

                if (haystack[i + j] != needle[j]) {
                    found = false;
                    break;
                }
            }

            if (found)
                return i;
        }

        return -1;
    }
};


// ============================================================
// 15. BACKSPACE STRING COMPARE
// LeetCode: https://leetcode.com/problems/backspace-string-compare/
// ============================================================

class Solution15 {
public:

    string process(string s) {

        string result;

        for (char c : s) {

            if (c == '#') {

                if (!result.empty())
                    result.pop_back();

            }
            else {
                result.push_back(c);
            }
        }

        return result;
    }

    bool backspaceCompare(string s, string t) {

        return process(s) == process(t);
    }
};


