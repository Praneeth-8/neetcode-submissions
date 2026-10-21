class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        result=[0]*len(temperatures)
        s=[]
        for i,temp in enumerate(temperatures):
            while s and temp>s[-1][0]:
                top = s.pop()
                result[top[1]] = i-top[1]
            s.append((temp,i))
        return result

        