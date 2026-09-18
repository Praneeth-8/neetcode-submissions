class PrefixTree:

    def __init__(self):
        self.isEnd=False
        self.child=[None]*26
        

    def insert(self, word: str) -> None:
        if(word==""):
            self.isEnd=True
            return
        ind = ord(word[0])-ord('a')
        if self.child[ind] is None:
            self.child[ind]=PrefixTree()
        self.child[ind].insert(word[1::])

    def search(self, word: str) -> bool:
        if word=="":
            return self.isEnd
        ind=ord(word[0])-ord('a')
        if self.child[ind] is None:
            return False
        return self.child[ind].search(word[1::])


        

    def startsWith(self, prefix: str) -> bool:
        if prefix=="":
            return True
        ind = ord(prefix[0])-ord('a')
        if self.child[ind] is None:
            return False
        return self.child[ind].startsWith(prefix[1::])
        
        
        