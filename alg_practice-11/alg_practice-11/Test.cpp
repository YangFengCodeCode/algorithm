#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

struct Activity
{
    int start;
    int end;
};

bool com(Activity a, Activity b)
{
    return a.end < b.end;
}

int main() {
    int n;
    cin >> n;
    vector<Activity> ac(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ac[i].start >> ac[i].end;
    }

    sort(ac.begin(), ac.end(), com);
    int count = 1;
    int prevend = ac[0].end;

    for (int i = 1; i < ac.size(); i++)
    {
        if (ac[i].start >= prevend)
        {
            count++;
            prevend = ac[i].end;
        }
    }

    cout << count << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")


#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

long long sum = 0;

//思路1：构造链表
typedef struct tree {
    long long val;
    tree* left = NULL;
    tree* right = NULL;
    tree* parent = NULL;
}tree;

// bool cmp(tree *a, tree *b){
//     if(a->val < b->val) 
//         return true;
//     else
//         return false;
// }

struct cmp {
    bool operator()(tree* a, tree* b) const {
        return a->val > b->val;
    }
};

int getSum(tree* root, int deep) {
    // cout<<" now:"<<root->val;
    // if(root->left){
    //     cout<<" left:"<<root->left->val;
    // }
    // else{
    //     cout<<" NULL";
    // }
    // if(root->right){
    //     cout<<" right:"<<root->right->val;
    // }
    // else{
    //     cout<<" NULL";
    // }
    // cout<<" deep:"<<deep;
    // cout<<endl;
    if (root->left == NULL && root->right == NULL) {
        sum += deep * root->val;
        return 0;
    }
    if (root->left) {
        getSum(root->left, deep + 1);
    }
    if (root->right) {
        getSum(root->right, deep + 1);
    }
    return 0;


}

int main() {
    int n;
    cin >> n;
    // vector<tree*> list(n);
    priority_queue<tree*, vector<tree*>, cmp> list;


    for (int i = 0; i < n; i++) {
        tree* t = new tree;
        cin >> t->val;
        list.push(t);
    }
    // sort(list.begin(),list.end(),cmp);
    while (1) {
        // cout<<"list.size:"<<list.size()<<" ";
        // for(auto i=0;i<list.size();i++){
        //     cout<<list[i]->val<<" ";
        // }
        // cout<<endl;
        // cout<<list.top()->val<<" ";

        if (list.size() == 1) {
            break;
        }
        tree* now = new tree;
        tree* a = list.top();
        list.pop();

        // cout<<list.top()->val<<" ";
        // cout<<endl;

        tree* b = list.top();
        list.pop();
        // for(int i=0;i<list.size();i++){
        //     cout<<list[i]->val<<" ";
        // }
        // cout<<endl;

        now->val = a->val + b->val;
        now->left = a;
        now->right = b;
        list.push(now);
        // if(now->val==75){
        //     cout<<"-----------";
        // }
        // sort(list.begin(),list.end(),cmp);
    }
    getSum(list.top(), 0);
    cout << sum;
    //329 232  


}



#include <climits>
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int l = 0, r = 1;
    int ret = 1;
    while (r < n)
    {
        if (v[r] - v[l] <= k)
        {
            ret = max(ret, r - l + 1);
            r++;
        }
        else l++;
    }

    cout << ret << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")