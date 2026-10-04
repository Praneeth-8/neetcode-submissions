class Solution:
    import heapq 
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        heap = []
        ans=[]

        for i,point in enumerate(points):
            dist = (point[0]**2 + point[1]**2)
            heapq.heappush(heap,(dist,str(i)))

        while k :
            minp = heapq.heappop(heap)
            ans.append(points[int(minp[1])])
            k-=1
        return ans
        