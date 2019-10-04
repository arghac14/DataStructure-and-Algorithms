l=[1,2,3,4,5,5]
print(any(i==j for i,j in zip(l,l[1:])))
