class Solution:
    def numTrees(self, n: int) -> int:
        nodes = [ num for num in range(1, n+1) ]
        print("The list of nodes are: ", nodes)

        dp = [ 0 for _ in range(len(nodes)+1) ]
        dp[0], dp[1] = 1, 1
        print("The initial dp is: ", dp)
        print("\n\n")

        for i, total_num_of_nodes in enumerate(nodes):
            if i == 0:
                continue
            available_nodes = nodes[: total_num_of_nodes]
            print("The available nodes are : ", available_nodes)
            for j, root in enumerate(available_nodes):
                print("The root is: ", root)
                left_subtree = available_nodes[ : j]
                right_subtree = available_nodes[j+1 : ]
                print(f"The left sub tree is {left_subtree}, containing {len(left_subtree)} nodes, forming {dp[len(left_subtree)]} tree(s).")
                print(f"The left sub tree is {right_subtree}, containing {len(right_subtree)} nodes, forming {dp[len(right_subtree)]} tree(s).")
                dp[i+1] += ( dp[len(left_subtree)] * dp[len(right_subtree)] )
                print(dp)
                print("\n\n")
        print(dp[n])
        return dp[n]

def main():
    solution = Solution()
    solution.numTrees(6)

main()