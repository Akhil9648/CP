k=int(input())
while k:
    n=int(input())
    s=input()
    if len(s)<3:
        print("NO")
    a=s[0]
    b=s[1]
    c=s[2:]
    if s==a+b+c and b in a+c:
        print("YES")
    else:
        print("NO")
    k=k-1