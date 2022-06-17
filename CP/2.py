class Solution:
    def discountPrices(self, sentence: str, d: int) -> str:
        ans = ""
        for i in range(len(sentence)):
            if (i == 0 and sentence[i] == "$"):
                s = ""
                j = i + 1
                while(sentence[j].isdigit() and j < len(sentence)):
                    s += sentence[j]
                    j += 1
                ans += "$"
                i = j
                if (i < len(sentence) and (sentence[i] == " ")) and (s != ""):
                    ans += str(float(int(s)*d)/100)
                continue
            if sentence[i] == "$" and sentence[i - 1].isdigit() == False:
                s = ""
                j = i + 1
                while(j < len(sentence) and sentence[j].isdigit()):
                    s += sentence[j]
                    j += 1
                i = j
                ans += "$"
                if (i < len(sentence) and (sentence[i] == " ")) and (s != ""):
                    ans += str(float(int(s)*d)/100)
                continue
            ans += sentence[i]
            
        return (ans)


# "$2 ere are $1 $2 and 5$ candies in the shop"
#                 |
obj = Solution()
obj.discountPrices("$2 here are $1 and 5 $45$23 candies$2as$ in t$23he shop $20", 20)