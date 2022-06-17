def matchReplacement(s: str, sub: str, mp: list[list[str]]) -> bool:
    temp = ""
    for i in range(len(sub)):
        temp = temp + sub[i]
        if (temp in s):
            pass
        else:
            for j in mp:
                if (j[0] == sub[i]):
                    temp = temp[:-1]
                    temp += j[1]
                if (temp in s):
                    break
            else:
                print(temp)
                print(0)
                return False
    return 1



s = "f178d2vdlwpycfmqgzd55fvfyamxx3owptoik8q52uy5ssteeboauki5x3zcl4gax53lurcpvs2jdju14a9115dk9q8adb7j31a07leiy4af57szw4xqwdnpcq8qj5nrkeb30lasl80kewhn987fvorke2rwg98bntfu2cxwkte509h8iweq85s3l47ayywf8dgesoy23e4qpjmrosmh0za6heoxd6fp8onv2dgumk6vkxy72cjwzkq139qecvnvihczb29uhsv0be7ftuxtzjetgfej0ijmnoej627z0vad5ghu22hnzhpyfasuy5l9kub2bmye2qxa4k4lnt15l7i916rilgbhbcifpjn3"
sub = "iu14at1j5dk9a8a3bzj3jb07leiycb0qzszw4xqr35omawaj5nzkjv3flb6l8fuerhnt8z0v1zkj2zwgt8vno0u2c1wuoj5f9hwireq8qs3ac7ay9wfw3sj61y23e4aojpz1"
l = [["r", "4"], ["z", "r"], ["5", "c"], ["t", "y"], ["f", "0"], ["3", "8"], ["7", "1"], ["j", "1"], ["s", "u"], ["o", "e"], ["f", "l"], ["7", "g"], ["5", "x"], ["o", "d"], ["k", "u"], ["x", "w"], ["z", "c"], ["8", "j"], ["s", "x"], ["j", "p"], ["9", "8"], ["h", "k"], ["o", "p"], ["w", "8"], ["i", "j"], ["c", "s"], ["r", "5"], ["1", "x"], ["i", "k"], ["u", "s"], ["q", "m"], ["j", "l"], ["k", "e"], ["i", "4"], ["a", "q"], ["1", "3"], ["d", "i"], ["w","a"], ["0", "3"], ["4", "v"], ["p", "m"], ["s", "c"], ["c", "i"], ["e", "w"], ["m", "f"], ["0", "f"], ["6", "w"], ["i", "v"], ["z", "7"], ["8", "a"], ["o", "c"], ["a", "l"], ["s", "g"], ["r", "b"], ["o", "t"], ["n", "a"], ["v", "c"], ["5", "n"], ["i", "c"], ["p", "d"], ["9", "y"], ["u", "k"], ["j", "e"], ["3", "d"], ["q", "5"], ["m", "c"], ["1", "o"], ["r", "w"], ["u", "6"], ["b", "a"], ["t", "9"], ["6", "s"], ["v", "b"], ["1", "i"], ["c", "4"]]

matchReplacement(s,sub,l)