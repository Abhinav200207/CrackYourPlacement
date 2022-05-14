def subString(numstr: str, k: int):
    l = []
    for i in range(len(numstr) - k + 1):
        s = ""
        for j in range(i, i+k):
            s += numstr[j]
        if int(s) == 0:
            continue
        l.append(s)
    l = list(map(lambda x: int(x), l))
    return l


def divisorSubstrings(num: int, k: int) -> int:
    numstr = str(num)
    count = 0
    l = subString(numstr, k)
    print(l)
    for i in range(len(l)):
        if (int(num) % l[i] == 0):
            count += 1
    print(count)


divisorSubstrings("430043", 2)
