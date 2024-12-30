#include <bits/stdc++.h>
using namespace std;

const int INT_SIZE=8;

struct TrieNode{
    int value;
    TrieNode *arr[2];
};

TrieNode *newNode(){
    TrieNode *temp = new TrieNode;
    temp->value = 0;
    temp->arr[0] = temp->arr[1] = NULL;
    return temp;
}

void insert(TrieNode *root, int pre_xor){
    TrieNode *temp = root;
    for (int i=INT_SIZE-1; i>=0; i--){
        bool val = pre_xor & (1<<i);
        if (temp->arr[val] == NULL)
            temp->arr[val] = newNode();
        temp = temp->arr[val];
    }
    temp->value = pre_xor;
}

int query(TrieNode *root, int pre_xor){
    TrieNode *temp = root;
    for (int i=INT_SIZE-1; i>=0; i--){
        bool val = pre_xor & (1<<i);
        if (temp->arr[1-val]!=NULL)
            temp = temp->arr[1-val];
        else if (temp->arr[val] != NULL)
            temp = temp->arr[val];
    }
    return pre_xor^(temp->value);
}

void solve(){
    int n;
    vector<int> arr;
    cin>>n;
    arr.resize(n);
    for(int i=0; i<n; ++i)
        cin>>arr[i];
    TrieNode *root = newNode();
    insert(root, 0);
    int result = INT_MIN, pre_xor =0;
    for (int i=0; i<n; i++){
        pre_xor = pre_xor^arr[i];
        insert(root, pre_xor);
        result = max(result, query(root, pre_xor));
    }
    cout<<result<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }
}