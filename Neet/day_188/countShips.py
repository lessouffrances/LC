# """
# This is Sea's API interface.
# You should not implement it, or speculate about its implementation
# """
# class Sea(object):
#    def hasShips(self, topRight, bottomLeft):
#        """
#        :type topRight: Point
# 		 :type bottomLeft: Point
#        :rtype bool
#        """

# class Point(object):
# 	def __init__(self, x, y):
# 		self.x = x
# 		self.y = y

class Solution(object):
    def countShips(self, sea, topRight, bottomLeft):
        if topRight.x < bottomLeft.x or topRight.y < bottomLeft.y:
            return 0
        
        if not sea.hasShips(topRight, bottomLeft):
            return 0
        
        if topRight.x == bottomLeft.x and topRight.y == bottomLeft.y: return 1

        mid_x = (topRight.x + bottomLeft.x) // 2
        mid_y = (topRight.y + bottomLeft.y) // 2

        count = 0
        count += self.countShips(sea, Point(mid_x, mid_y), bottomLeft)
        count += self.countShips(sea, Point(topRight.x, mid_y), Point(mid_x+1, bottomLeft.y))
        count += self.countShips(sea, Point(mid_x, topRight.y), Point(bottomLeft.x, mid_y+1))
        count += self.countShips(sea, topRight, Point(mid_x+1, mid_y+1))
        return count
    