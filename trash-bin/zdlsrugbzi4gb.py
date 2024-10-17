# #include <bits/stdc++.h>
# using namespace std;
# #define int long long

# signed main(){
#     cin.tie(0)->sync_with_stdio(0);
#     string s;
#     cin>>s;
#     // simply find the number of ways to fill each slot, and times together
#     // each character must map to one digit and one digit must map to one character
#     // if there are 3 char, then # of ways = 3 * 2 * 1 = 3!
#     set<char> unq;
#     int ans=1ll;
#     for(int i=0;i<s.size();++i){
#         if(s[i]=='?'){
#             if(i==0) ans*=9;
#             else ans*=10;
#         }else if(s[i]>='A' && s[i]<='J'){
#             unq.insert(s[i]);
#         }
#     }

#     int arrange=1ll;
#     for(int i=1;i<unq.size();++i){
#         arrange*=(10-i);
#     }
#     if(unq.size()>0 && s[0]>='A' && s[0]<='J') arrange*=9;
#     else if(unq.size()>0) arrange*=10;

#     cout<<ans*arrange<<endl;
#     return 0;
# }
# // AZDSLKRJGBLZDKJGBZLDSKRGZDRUGBZDG

# below is the python version
import sys
input = sys.stdin.readline

s = input()
unq = set()
ans = 1
for i in range(len(s)):
    if s[i]=='?':
        if i==0:
            ans=ans*9
        else:
            ans=ans*10
    elif ord(s[i])>=ord('A') and ord(s[i])<=ord('J'):
        unq.add(s[i])

arrange = 1
for i in range(1, len(unq)):
    arrange=arrange*(10-i)
if len(unq)>0 and ord(s[0])>=ord('A') and ord(s[0])<=ord('J'):
    arrange*=9
elif len(unq)>0:
    arrange*=10

print(arrange * ans)
