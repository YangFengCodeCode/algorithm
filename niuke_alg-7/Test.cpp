#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class priorityQueue
{
public:
    void adjust_up(int child)
    {
        int parent = (child - 1) / 2;
        while (child > 0)
        {
            if (_con[parent] < _con[child])
            {
                swap(_con[parent], _con[child]);
                child = parent;
                parent = (child - 1) / 2;
            }
            else
            {
                break;
            }
        }
    }

    void adjust_down(int parent)
    {
        int child = parent * 2 + 1;
        while (child < _con.size())
        {
            if (child + 1 < _con.size() && _con[child] < _con[child + 1]) child++;
            if (_con[parent] < _con[child])
            {
                swap(_con[parent], _con[child]);
                parent = child;
                child = parent * 2 + 1;
            }
            else
            {
                break;
            }
        }
    }

    void push(int& x)
    {
        _con.push_back(x);
        adjust_up(_con.size() - 1);
    }

    void pop()
    {
        if (_con.empty())
        {
            cout << "empty" << endl;
            return;
        }
        cout << _con[0] << endl;
        swap(_con[0], _con[_con.size() - 1]);
        _con.pop_back();
        adjust_down(0);
    }

    void top()
    {
        if (_con.empty()) cout << "empty" << endl;
        else cout << _con[0] << endl;
    }
private:
    vector<int> _con;
};

int main() {
    int n;
    priorityQueue pq;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string op;
        cin >> op;
        if (op == "push")
        {
            int x;
            cin >> x;
            pq.push(x);
        }

        if (op == "pop")
        {
            pq.pop();
        }

        if (op == "top")
        {
            pq.top();
        }
    }
}
// 64 位输出请用 printf("%lld")





#include <cmath>
#include <functional>
#include <iostream>
#include <unordered_map>
#include <vector>
#include<map>
#include<queue>
using namespace std;

unordered_map<int, vector<int>> Hash;
vector<int> dp(5001, -1);
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        Hash[u].push_back(v);
        Hash[v].push_back(u);
    }

    dp[1] = 0;
    bool flag = false;
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (int i = 0; i < Hash[t].size(); i++)
        {
            int pos = Hash[t][i];
            if (dp[pos] == -1)
            {
                dp[pos] = dp[t] + 1;
                if (pos == n)
                {
                    flag = true;
                    break;
                }
                q.push(pos);
            }
        }

        if (flag) break;
    }

    cout << dp[n];
    return 0;

}
// 64 位输出请用 printf("%lld")