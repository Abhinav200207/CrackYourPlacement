class Solution:
    def reverseWords(self, s: str) -> str:
        st = []
        temp = ""
        s = s + "0"
        for i in range(len(s)):
            if (s[i] == " " or i == len(s) - 1):
                if temp != "":
                    st.append(temp)
                temp = ""
                continue
            temp += s[i]
        s = ""
        st = st[::-1]
        for i in st:
            s += i
            s += " "
        return s[:-1]
        