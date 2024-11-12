#include <bits/stdc++.h>
using namespace std;
#define int long long 

/*Returns true if s1 is subsequence of s2*/
bool isSubSeq(const string& s1, const string& s2)
{
    int m = s1.length(), n = s2.length();
  
    // For s1 to be subsequence, its length must
    // smaller than s2
    if (m > n) return false;
  
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (s1[i] == s2[j])
            i++;
        j++;
    }
  
   /*If i reaches end of s1,that mean we found all
    characters of s1 in s2,
    so s1 is subsequence of s2, else not*/
    return i == m;
}

signed main(){
    string s;
    cin>>s;
    string target = "CODEFORCES";
    if(!isSubSeq(target, s))
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
    return 0;
}