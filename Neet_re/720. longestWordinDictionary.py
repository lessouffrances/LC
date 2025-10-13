from collections import defaultdict
from collections import deque
from string import ascii_lowercase
class Trie:
    class TrieNode(defaultdict):
        def __init__(self):
            super().__init__(Trie.TrieNode)
            self.endOfWord = False

    def __init__(self):
        self.root = Trie.TrieNode()
        self.root.endOfWord = True

    def insert(self, word):
        node = self.root
        for char in word: node = node[char]
        node.endOfWord = True

class Solution:
    def longestWord(self, words) -> str:
        trie = Trie()

        for word in words: trie.insert(word)
        candidate, l = [], 0
        tour = deque([(trie.root, [''])])
        while tour:
            node, path = tour.pop()
            if not node.endOfWord: continue
            if len(path)>= l:
                candidate = path
                l = len(path)
            for char in ascii_lowercase:
                if char in node:
                    tour.append((node[char], path+[char]))

        return "".join(candidate)

def main():
    self = Solution
    words = ["w","wo","wor","worl","world"]
    words = ["a","banana","app","appl","ap","apply","apple"]
    Solution.longestWord(self, words)
main()