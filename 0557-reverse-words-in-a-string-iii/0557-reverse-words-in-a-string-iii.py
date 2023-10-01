class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split(" ")
        w = ""
        for i in words:
            w += i[::-1] + " "
            
        return w[:-1]
        