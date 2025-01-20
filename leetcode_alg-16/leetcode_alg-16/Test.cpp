#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost = INT_MAX, profit = 0;
        for (auto price : prices)
        {
            cost = min(cost, price);
            profit = max(profit, price - cost);
        }
        return profit;
    }
};


class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last[26];
        for (int i = 0; i < s.size(); i++)
        {
            last[s[i] - 'a'] = i;
        }

        vector<int> ret;
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++)
        {
            end = max(end, last[s[i] - 'a']);
            if (i == end)
            {
                ret.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return ret;
    }
};