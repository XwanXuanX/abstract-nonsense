#include <bits/stdc++.h>
using namespace std;

void printTree(const vector<vector<int>>& tree) {
    for (int i=0; i<tree.size(); ++i) {
        for (int j=0; j<tree[i].size(); ++j) {
            cout<<tree[i][j]<<' ';
        }
        cout<<'\n';
    }
}

// note that `tree` is copied by VALUE!
int calc(vector<vector<int>>& tree, int p, int b) {
    int chg_idx = p-1, chg_val = b;
    for (int i=0; i<tree.size(); ++i) {
        // change current layer
        tree[i][chg_idx] = chg_val;
        // push change to next layer
        if (chg_idx % 2) { // op with left
            if ((i+1) % 2) { // op = OR
                chg_val = tree[i][chg_idx] | tree[i][chg_idx-1];
            } else { // op = XOR
                chg_val = tree[i][chg_idx] ^ tree[i][chg_idx-1];
            }
        } else { // op with right
            if ((i+1) % 2) {
                chg_val = tree[i][chg_idx] | tree[i][chg_idx+1];
            } else {
                chg_val = tree[i][chg_idx] ^ tree[i][chg_idx+1];
            }
        }
        chg_idx = chg_idx / 2;
    }
    // printTree(tree);
    return tree.back().back();
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int _n, m;
    cin>>_n>>m;
    int n = 1 << _n;
    vector<int> a(n);
    for (int i=0; i<n; ++i) {
        cin>>a[i];
    }
    vector<pair<int,int>> q;
    for (int i=0; i<m; ++i) {
        int p, b;
        cin>>p>>b;
        q.push_back(make_pair(p, b));
    }

    // preproc
    int height = _n + 1;
    vector<vector<int>> tree(height); // level of O(height)
    tree[0].assign(a.begin(), a.end());
    for (int i=1; i<height; ++i) {
        for (int j=0; j<tree[i-1].size(); j+=2) {
            if (i % 2) { // do OR
                tree[i].push_back(tree[i-1][j] | tree[i-1][j+1]);
            } else { // do XOR
                tree[i].push_back(tree[i-1][j] ^ tree[i-1][j+1]);
            }
        }
    }

    // proc query
    for (int i=0; i<m; ++i) {
        cout<<calc(tree, q[i].first, q[i].second)<<'\n';
    }

    return 0;
}

/**
 * if one number changed, how much effect it will make?
 * 1 2 3 4 5 6 7 8
 *  1   3   5   7
 *    1       2
 *        1
 * so the change of one number will only affect the number immediately below it
 * thus if we can build a tree with pre processing, then we only have to process
 * O(height) time for each query.
 */