class WordDictionary:

    def __init__(self):
        self.Child=[None]*26
        self.last=False
        

    def addWord(self, word: str,pos=0) -> None:
        if pos==len(word):
            self.last = True
            return
        letter=word[pos]
        index = ord(letter) - ord('a')
        if self.Child[index] == None:
            self.Child[index] = WordDictionary()
        self.Child[index].addWord(word,pos+1)
        


    def search(self, word: str,pos=0) -> bool:
        if len(word)==pos:
            return self.last
        letter = word[pos]
        
        

        if letter =='.':
            present=False
            for i in self.Child:
                if i!=None:
                    present = present or i.search(word,pos+1)
                    if present == True:
                        break
            return present
        else:
            index = ord(letter) - ord('a')
            if self.Child[index] == None:
                return False
            else:
                return self.Child[index].search(word,pos+1)

        
