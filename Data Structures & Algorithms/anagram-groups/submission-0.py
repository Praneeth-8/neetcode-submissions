class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res=defaultdict(list) #map charcount of string to list of anagram

        for s in strs:
            count = [0]*26

            for c in s:
                count[ord(c) - ord("a")]+=1
            res[tuple(count)].append(s)
        answ=[]
        for i in res:
            answ.append(res[i])

        return answ
