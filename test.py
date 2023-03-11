import re
test_str = str(input())
test_sub = str(input())
res = [i.start() for i in re.finditer( test_str,test_sub)]
a = res
print(len(res), end = '\n')
for x in res:
    print(int(x) + 1, end = ' ')