def myfunc(x):
    return x[1]
if __name__ == "__main__":
    print("Day cac ki tu", end = ':')
    s = str(input()).split()
    list = list(map(str,s))
    list.sort()
    for x in list:
        print('"' + x + '",', end = ' ')
    print('\n')
    list.sort(key = myfunc)
    for x in list:
        print('"' + x + '",', end = ' ')
    print('\n')
