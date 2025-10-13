from collections import defaultdict

class Solution:
    def rankTeams(self, votes) -> str:
        rankCounter = defaultdict(lambda: [0]*len(votes[0]))
        print(rankCounter)

        for vote in votes:
            for position, team in enumerate(vote):
                rankCounter[team][position] += 1
        
        print(rankCounter)
        sortedTeams = sorted(rankCounter.keys(), key=lambda team: (rankCounter[team], -ord(team)), reverse=True)
        print(sortedTeams)
        return "".join(sortedTeams)

def main():
    self = Solution
    votes = ["ABC","ACB","ABC","ACB","ACB"]
    # votes = ["WXYZ","XYZW"]
    # votes = ["ZMNAGUEDSJYLBOPHRQICWFXTVK"]
    Solution.rankTeams(self, votes)
main()