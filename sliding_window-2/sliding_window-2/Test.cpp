#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        unordered_map<string, int> hash1;//´æwords
        for (auto& e : words)
            hash1[e]++;
        int n = words.size(), len = words[0].size();
        for (int i = 0; i < len; i++)
        {
            unordered_map<string, int> hash2;//´æs
            for (int left = i, right = i, count = 0; right + len <= s.size(); right += len)
            {
                string in = s.substr(right, len);
                if (hash1.count(in) && ++hash2[in] <= hash1[in]) count++;
                if (right - left + 1 > n * len)
                {
                    string out = s.substr(left, len);
                    if (hash1.count(out) && hash2[out]-- <= hash1[out]) count--;
                    left += len;
                }
                if (count == n) ret.push_back(left);
            }
        }
        return ret;
    }
};



class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hash1, hash2;
        int kinds = 0;
        for (auto e : t)
            if (hash1[e]++ == 0) kinds++;
        int minlen = INT_MAX, begin = -1;
        for (int left = 0, right = 0, count = 0; right < s.size(); right++)
        {
            if (++hash2[s[right]] == hash1[s[right]]) count++;
            while (count == kinds)
            {
                if (right - left + 1 < minlen)
                {
                    minlen = right - left + 1;
                    begin = left;
                }
                if (hash2[s[left]]-- == hash1[s[left]]) count--;
                left++;
            }
        }

        if (begin == -1) return "";
        else return s.substr(begin, minlen);

    }
};



