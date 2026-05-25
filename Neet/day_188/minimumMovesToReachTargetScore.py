class Solution(object):
    def minMoves(self, target, maxDoubles):
        if maxDoubles == 0:
            return target-1

        moves = 0
        while maxDoubles > 0 and target > 1:
            if target % 2 == 0:
                target /= 2
                maxDoubles -= 1
                moves += 1
            else:
                target -= 1
                moves += 1
        
        return moves + max(target-1, 0)

