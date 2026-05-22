import heapq

class Leaderboard(object):
    def __init__(self):
        self.board = {}
        pass

    def addScore(self, playerId, score):
        if playerId in self.board:
            self.board[playerId] += score
        else:
            self.board[playerId] = score
            
    def top(self, K):
        min_heap = []
        top_k_sum = 0
        for _, score in self.board.items():
            heapq.heappush(min_heap, score)
            top_k_sum += score
            if len(min_heap) > K:
                top_k_sum -= heapq.heappop(min_heap)
        return top_k_sum
        
    def reset(self, playerId):
        if playerId in self.board:
            self.board[playerId] = 0

        
    