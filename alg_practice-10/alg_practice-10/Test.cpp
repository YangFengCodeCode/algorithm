#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>


#define ll long long

long long quickpow1(long long a, long long b, long long p) {
    long long ret = 1;
    while (b) {
        if (b & 1) {
            ret = ret * a % p;
        }
        a = a * a % p;
        b >>= 1;
    }
    return ret;
}
int main()
{
    ll q;
    cin >> q;
    while (q--)
    {
        ll  a, b, p;
        cin >> a >> b >> p;
        cout << quickpow1(a, b, p) << endl;
    }
    return 0;
}


int main() {
    long long int q, a, b, p;
    cin >> q;
    while (q--) {
        cin >> a >> b >> p;
        long long int k = 0;//定义储存变量
        while (b--) {
            k += a;//累加
        }
        cout << k % p << endl;//总和取模
        k = 0;//归0
    }
    return 0;
}



#include <vector>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 将给定数组排序
     * @param arr int整型vector 待排序的数组
     * @return int整型vector
     */

    int PartSort(vector<int>& arr, int left, int right)
    {
        int key = left;
        int prev = left;
        int cur = prev + 1;
        while (cur <= right)
        {
            if (arr[cur] < arr[key] && ++prev != cur)
            {
                swap(arr[cur], arr[prev]);
            }

            cur++;
        }
        swap(arr[prev], arr[key]);
        return prev;
    }

    vector<int> quickSort(vector<int>& arr, int begin, int end)
    {
        if (begin >= end) return arr;
        int keyi = PartSort(arr, begin, end);
        quickSort(arr, begin, keyi - 1);
        quickSort(arr, keyi + 1, end);
        return arr;
    }
    vector<int> MySort(vector<int>& arr) {
        // write code here
        return quickSort(arr, 0, arr.size() - 1);
    }
};