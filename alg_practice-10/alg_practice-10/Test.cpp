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
        long long int k = 0;//���崢�����
        while (b--) {
            k += a;//�ۼ�
        }
        cout << k % p << endl;//�ܺ�ȡģ
        k = 0;//��0
    }
    return 0;
}



#include <vector>
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * ��������������
     * @param arr int����vector �����������
     * @return int����vector
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