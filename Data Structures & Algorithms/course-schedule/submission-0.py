class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        courses = {d:[] for d in range(numCourses)}
        indeg={d:0 for d in range(numCourses)}
        for preq,crs in prerequisites:
            courses[preq].append(crs)
            indeg[crs]+=1
        

        q = deque([i for i in indeg if indeg[i] == 0])

        while q:
            i = q.popleft()

            for j in courses[i]:
                indeg[j] -= 1
                if indeg[j] == 0:
                    q.append(j)
        
        for i in indeg:
            if indeg[i]!=0:
                return False
        return True

            