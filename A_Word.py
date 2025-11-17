s = input()
count = 0
for i in range(len(s)):
    if(s[i].isupper()):
        count+=1
if(count > len(s)/2):
    print(s.upper())
else:
    print(s.lower())