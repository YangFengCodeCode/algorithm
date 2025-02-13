#include<iostream>
using namespace std;
#include<vector>
#include<stack>

int GetMid(vector<int>& a, int left, int right)
{
	int mid = (left + right) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right]) return mid;
		else if (a[left] > a[right]) return left;
		else return right;
	}

	else
	{
		if (a[mid] > a[right]) return mid;
		else if (a[left] < a[right]) return left;
		else return right;
	}
}

int part_sort(vector<int>& a, int left, int right)
{

	int mid = GetMid(a, left, right);
	swap(a[mid], a[left]);
	int key = left;
	
	while (left < right)
	{
		while (left < right && a[right] >= a[key])
		{
			right--;
		}

		while (left < right && a[left] <= a[key])
		{
			left++;
		}

		swap(a[left], a[right]);
	}

	swap(a[key], a[left]);
	return left;

}

int part_sort2(vector<int>& a, int left, int right)
{
	int key = left;
	int prev = left, cur = prev + 1;
	while (cur <= right)
	{
		if (a[cur] < a[key] && ++prev != cur)
		{
			swap(a[cur], a[prev]);
		}
		cur++;
	}

	swap(a[prev], a[key]);
	return prev;
}

void quick_sort(vector<int>& a, int begin, int end)
{
	if (begin >= end) return;

	int keyi = part_sort2(a, begin, end);
	quick_sort(a, begin, keyi - 1);
	quick_sort(a, keyi + 1, end);
}


void quick_sort2(vector<int>& a, int begin, int end)
{
	if (begin >= end) return;

	stack<int> st;
	st.push(end);
	st.push(begin);
	while (!st.empty())
	{
		int left = st.top();
		st.pop();
		int right = st.top();
		st.pop();
		int keyi = part_sort2(a, left, right);
		if (keyi + 1 < right)
		{
			st.push(right);
			st.push(keyi + 1);
		}

		if (left < keyi - 1)
		{
			st.push(keyi - 1);
			st.push(left);
		}

	}
}

int main()
{
	vector<int> v = { 1, 3, 2, 7, 4, 0 };
	quick_sort2(v, 0, v.size() - 1);
	for (auto e : v)
	{
		cout << e << " ";
	}
	return 0;
}