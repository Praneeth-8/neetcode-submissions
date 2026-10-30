class Solution:
    def decodeString(self, s: str) -> str:
        nums = []
        stack=[]
        i=0
        n= len(s)
        while i<n:
            if s[i].isdigit():
                num = 0
                while i < len(s) and s[i].isdigit():
                    num = num * 10 + int(s[i])
                    i += 1
                nums.append(num)
            elif s[i] == ']':
                chars = []
                while stack and stack[-1] != '[':
                    chars.append(stack.pop())
                stack.pop()
                chars.reverse()

                alpha = ''.join(chars)
                alpha *= nums.pop()
                stack.append(alpha)
                i+=1
            else:
                stack.append(s[i])
                i+=1
        return ''.join(stack)