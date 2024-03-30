#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
    string modifyString(string s) {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '?')
            {
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    if ((i == 0 || ch != s[i - 1]) && (i == s.size() - 1 || ch != s[i + 1]))
                    {
                        s[i] = ch;
                        break;
                    }
                }
            }
        }
        return s;
    }
};



class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ret = 0;
        for (int i = 0; i < timeSeries.size() - 1; i++)
        {
            int x = timeSeries[i + 1] - timeSeries[i];
            if (x >= duration) ret += duration;
            else ret += x;
        }
        ret += duration;
        return ret;
    }
};



class Solution {
public:
    string convert(string s, int numRows) {
        string ret;
        if (numRows == 1) return s;
        int d = 2 * numRows - 2;
        //处理第一行
        for (int i = 0; i < s.size(); i += d)
        {
            ret.push_back(s[i]);
        }

        //处理K行
        for (int k = 1; k <= numRows - 2; k++)
        {
            for (int i = k, j = d - k; i < s.size() || j < s.size(); i += d, j += d)
            {
                if (i < s.size()) ret.push_back(s[i]);
                if (j < s.size()) ret.push_back(s[j]);
            }
        }

        //处理最后一行
        for (int i = numRows - 1; i < s.size(); i += d)
        {
            ret.push_back(s[i]);
        }

        return ret;
    }
};


class Solution {
public:
    string countAndSay(int n) {
        string ret = "1";
        for (int i = 1; i < n; i++)
        {
            string tmp;
            for (int left = 0, right = 0; right < ret.size();)
            {
                while (right < ret.size() && ret[left] == ret[right]) right++;
                tmp += to_string(right - left) + ret[left];
                left = right;
            }

            ret = tmp;
        }

        return ret;
    }
};


#include<unordered_map>
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        string t = "croak";
        int n = t.size();
        vector<int> hash(n);
        unordered_map<char, int> index;
        for (int i = 0; i < n; i++)
        {
            index[t[i]] = i;
        }

        for (auto e : croakOfFrogs)
        {
            if (e == 'c')
            {
                if (hash[n - 1] != 0) hash[n - 1]--;
                hash[0]++;
            }
            else
            {
                int i = index[e];
                if (hash[i - 1] == 0) return -1;
                hash[i - 1]--;
                hash[i]++;
            }
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (hash[i] != 0) return -1;
        }

        return hash[n - 1];

    }
};