from itertools import combinations
n,m=map(int,input().split())
strings=[]
for i in range(n):
  strings.append(input())
combos=list(combinations(strings,2))
or_res=[]
for i in combos:
  or_res.append(bin(int('0b' + i[0], 2) | int('0b' + i[1], 2)).count('1'))