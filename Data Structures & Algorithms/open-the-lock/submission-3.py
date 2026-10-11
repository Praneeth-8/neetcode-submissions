class Solution:
    def adder(self,str1,str2):
        res =""
        for i in range(len(str1)):
            num = int(str1[i]) + int(str2[i])
            num = num%10
            res+=str(num)
        return res
    def suber(self,str1,str2):
        res =""
        for i in range(len(str1)):
            num = int(str1[i]) - int(str2[i])
            if num==-1:
                num=9
            num = num%10
            res+=str(num)
        return res

    def openLock(self, deadends: List[str], target: str) -> int:
        path=["0001","0010","0100","1000"]
        
        if "0000" == target:
            return 0
        if "0000" in deadends:
            return -1
        visited = set()
        turns=0
        que =deque(["0000"])
        while que:
            for _ in range(len(que)):
                node = que.popleft()
                for neigh in path:
                    new_node_a = self.adder(node,neigh)
                    new_node_b = self.suber(node,neigh)
                    if new_node_a == target:
                        return turns+1
                    if new_node_a not in visited and new_node_a not in deadends:
                        que.append(new_node_a)
                        visited.add(new_node_a)
                    if new_node_b == target:
                        return turns+1
                    if new_node_b not in visited and new_node_b not in deadends:
                        que.append(new_node_b)
                        visited.add(new_node_b)
            turns+=1
        return -1

