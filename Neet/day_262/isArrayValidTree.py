# -1的个数只能等于一个
    
#     如果没有-1， 必定有环：
#         相当于没有入度 = 0的点
#         topologic sort当还没有没有完图， 但是已经没有点入度等于0了
#         那么就是有环
#     如果有多个-1，连通分量可能有多个？
#         可能一个连通分量， 多个root指向同一个点
#         多个连通分量， 多个树
#      如果只有一个-1，是否一定是一个树？
#         保证图的连通无环的情况下，才是一个树
#         本题不保证连通，所以一定是一个树，有可能是两个连通分量： 一个树 + 一个环

from collections import deque,defaultdict
def judgeIsTree(parent: list[int]) -> bool:
    graph = defaultdict(list)
    root = -1
    rootCount = 0
    for childNode, parentNode in enumerate(parent):
        if parentNode == -1:
            root = childNode
            rootCount += 1
        else:
            graph[parentNode].append(childNode)
    if rootCount != 1:  # 只能有一个root
        return False
    queue = deque()
    vis = set()  # 记录已经访问过的点

    queue.append(root)
    vis.add(root)

    while queue:
        curNode = queue.popleft()
        for childNode in graph[curNode]:
            if childNode in vis:  # 之前遍历过了，现在又走到了 一个树往下走，不会走重复
                return False
            vis.add(childNode)
            queue.append(childNode)
    return len(vis) == len(parent)  # 判断是否走完了所有点，如果没有走完就是有多个连通分量

print(judgeIsTree([1, -1, 1, 2, 5, 2])) # true
print(judgeIsTree([-1, 0, -1, 2, 3])) # false
print(judgeIsTree([1, -1, 3, 4, 5, 2])) # false