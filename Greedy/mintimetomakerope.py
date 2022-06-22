class Solution:
    def minCost(self, colors: str, neededTime: list[int]) -> int:
        st = []
        temp = [neededTime[0]]
        for i in range(1, len(colors)):
            if (colors[i] == colors[i - 1]):
                temp.append(neededTime[i])
                pass
            else:
                st.append(temp)
                temp = [neededTime[i]]
        st.append(temp)
        filist = []
        for i in st:
            if len(i) >= 2:
                i.sort()
                filist.append(i)
        st.clear()
        print(filist)