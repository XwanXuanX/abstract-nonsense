s = input()
t = 'CODEFORCES'
for i in range(len(t) + 1):
  if s.startswith(t[:i]) and s.endswith(t[i:]):
    print('YES')
    exit()
print('NO')