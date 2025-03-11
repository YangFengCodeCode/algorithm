#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//
//
//int main() {
//    int n;
//    cin >> n;
//
//    vector<int> v;
//    for (int i = 1; i <= n; i++) {
//        v.push_back(i);
//    }
//
//    int index = 0;
//    while (v.size() > 1) {
//        index = (index + 2) % v.size(); 
//        v.erase(v.begin() + index);
//    }
//    cout << v[0]<< endl;
//    return 0;
//}

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int v;
    cin >> v;
    int n;
    cin >> n;
    vector<int> oj(n);
    vector<vector<int>> dp(31, vector<int>(20001));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) cin >> oj[i];

    for (int i = 1; i < n; i++)
    {
        for (int j = v; j >= oj[i]; j--)
        {
            dp[i][j] = dp[i - 1][j] || dp[i - 1][j - oj[i]];
        }
    }

    for (int j = v; j >= 0; j--)
    {
        if (dp[n][j])
        {
            cout << v - j;
            break;
        }
    }


    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")