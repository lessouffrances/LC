class Solution(object):
    def minMoves(self, target, maxDoubles):
        if maxDoubles == 0:
            return target-1

        moves = 0

        while target > 1 and maxDoubles > 0:
            if target % 2 == 0:
                target /= 2
                maxDoubles -= 1
            else:
                target -= 1
            moves += 1
        
        moves += max(0, target-1)
        return moves