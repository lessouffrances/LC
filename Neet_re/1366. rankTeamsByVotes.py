from collections import defaultdict
class Solution:
    def rankTeams(self, votes) -> str:
        rankCount = defaultdict(lambda: [0] * len(votes[0]))

        for vote in votes:
            for rank, team in enumerate(vote):
                rankCount[team][rank] += 1
        
        print(rankCount)
        sortedTeams = sorted(rankCount.keys(), key=lambda team: (rankCount[team], -ord(team)), reverse=True)
        print("".join(sortedTeams))
        return "".join(sortedTeams)
            

def main():
    self = Solution
    votes = ["ABC","ACB","ABC","ACB","ACB"]
    votes = ["WXYZ","XYZW"]
    # votes = ["ZMNAGUEDSJYLBOPHRQICWFXTVK"]
    Solution.rankTeams(self, votes)
main()

        
        