#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;



//#include<bits/stdc++.h>
//using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//int main(int argc, char** argv) {
//	int N, M, K;
//	cin >> N >> M >> K;
//	vector<vector<int>> grid(N+1, vector<int>(M+1));
//	vector<vector<int>> dp(N+1, vector<int>(M+1));
//	for(int i = 1; i <= N; i++)
//	{
//		for(int j = 1; j <= M; j++)
//		{
//			cin >> grid[i][j];
//			dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + grid[i][j];	
//		}	
//	}
//	
//	int sum = 0;
//	for(int x1 = 1; x1 <= N; x1++)
//	{
//		for(int y1 = 1; y1 <= M; y1++)
//		{
//			for(int x2 = x1; x2 <= N; x2++)
//			{
//				for(int y2 = y1; y2 <= M; y2++)
//				{
//					if(dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1] <= K)
//					{
//						//cout << x2 << " " << y2 << endl;
//						sum++;	
//					}
//				}
//			}
//			//cout << endl;	
//		}
//	}
//	
//	cout << sum << endl;
//	return 0;
//}

//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> nums(n);
//	int sum = 0;
//	for(int i = 0; i < n; i++)
//	{
//		cin >> nums[i];
//		sum += nums[i];
//	}
//	
//	int left = 0, right = n-1;
//	int target = sum / 2;
//	
//	sum = 0;
//	while(left < right)
//	{
//		int mid = left + (right - left)/2;
//		if()
//	}
//	
//	return 0;
//}





//int t2(int i)
//{
//	int sum = 0;
//	while(i)
//	{
//	sum += i % 2 ;
//	i /= 2;
//	
//	}
//	return sum;
//}
//
//int t4(int i)
//{
//	int sum = 0;
//	while(i)
//	{
//	sum += i % 4 ;
//	i /= 4;
//	
//	}
//	return sum;
//
//}
//
//int main()
//{
//	// 请在此输入您的代码
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	int sum = 0;
//	for(int i = 1; i <= 2024; i++)
//	{
//		if(t2(i) == t4(i)) sum++;
//	}
//	
//	cout << sum << endl;
//	return 0;
//}


//int main()
//{
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	long long n;
//	cin >> n;
//	long long count = 0;
//	for(long long i = 1; i <= n; i++)
//	{
//		int k = 1, t = i;
//		bool check = true;
//		while(t)
//		{
//			int tmp = t % 10;
//			if(k % 2 == 1 && tmp % 2 != 1)
//			{
//				check = false;
//			}
//			else if(k % 2 == 0 && tmp % 2 != 0)
//			{
//				check = false;	
//			}
//			t /= 10;
//			k++;	
//		}
//		if(check) count++;
//	}
//	
//	cout << count << endl;
//	return 0;
//	
//}



//#include <bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//  // 请在此输入您的代码
//  int n;
//  double d;
//  cin >> n >> d;
//  
//  double res = d * pow(2, n);
//  
//  string s = to_string(res);
//  //cout << "string: " << s << endl;
//  int i = 0;
//  int ans = 0;
//  for(; i < s.size(); i++)
//  {
//  		if(s[i] == '.') break;
//  		ans = ans*10 + (s[i] - '0');
//  		//cout << "ans: " << ans << endl;
//  }
//  
//  int num = s[i+1] - '0';
//  if(num >= 5) ans += 1;
//  cout << ans;
//
//  return 0;
//}


#include<algorithm>
#include <numeric>


long long sumS(int a, int b, int c)
{
	return std::gcd(a, std::gcd(b, c));
}

vector<long long> path;
vector<vector<long long>> res;
long long sum = 0;
long long pre = -1;

void dfs(vector<int>& nums, int pos)
{
	if (path.size() == 3)
	{
		int a = path[0], b = path[1], c = path[2];
		long long S = sumS(a, b, c);
		if (S >= pre)
		{
			pre= S;
			res.clear();
			sort(path.begin(), path.end());
			res.push_back(path);
		}
		return;
	}
	for (int i = pos; i < nums.size(); i++)
	{
		path.push_back(nums[i]);
		dfs(nums, i + 1);
		path.pop_back();

	}

}

int main()
{
	//	int t = LCM3(5, 11, 11);
	//	cout << t << endl;
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	dfs(nums, 0);

	for (auto e : res)
	{
		for (auto n : e)
		{
			cout << n << " ";
		}

		cout << endl;
	}

	sort(res.begin(), res.end());
	cout << res[0][0] << " " << res[0][1] << " " << res[0][2];
	return 0;
}