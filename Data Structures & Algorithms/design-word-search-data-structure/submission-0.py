class WordDictionary:

    def __init__(self):
        self.Child=[None]*26
        self.last=False
        

    def addWord(self, word: str) -> None:
        if word=="":
            self.last = True
            return
        letter=word[0]
        index = ord(letter) - ord('a')
        if self.Child[index] == None:
            self.Child[index] = WordDictionary()
        self.Child[index].addWord(word[1::])
        


    def search(self, word: str) -> bool:
        if word =='':
            return self.last
        letter = word[0]
        index = ord(letter) - ord('a')
        

        if letter =='.':
            present=False
            for i in self.Child:
                if i!=None:
                    present = present or i.search(word[1::])
            return present
        else:
            if self.Child[index] == None:
                return False
            else:
                return self.Child[index].search(word[1::])

        
