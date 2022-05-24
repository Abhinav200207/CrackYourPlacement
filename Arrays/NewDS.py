# Insert Delete GetRandom O(1) - Duplicates allowed

import random

mp = {}
l = []


class RandomizedCollection:
    def __init__(self):
        pass

    def insert(self, val: int) -> bool:
        if (val in mp):
            return False
        l.append(val)
        mp[val] = len(l) - 1
        return True

    def remove(self, val: int) -> bool:
        if val not in mp:
            return False
        index = mp[val]
        l[index] = l[-1]
        mp[l[-1]] = index
        l.pop()
        mp.pop(val)
        return True

    def getRandom(self) -> int:
        return l[random.randint(0, len(l))]

        # Your RandomizedCollection object will be instantiated and called as such:
        # obj = RandomizedCollection()
        # param_1 = obj.insert(val)
        # param_2 = obj.remove(val)
        # param_3 = obj.getRandom()
