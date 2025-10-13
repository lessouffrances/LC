from collections import defaultdict
class Solution:
    def rankTeams(self, votes) -> str:
        rankCounts = defaultdict(lambda: [0] * len(votes[0]))
        print(rankCounts)
        
        for vote in votes:
            for position, team in enumerate(vote):
                print(position)
                print(team)
                rankCounts[team][position] += 1 # this is a hashMap, not matrix
        print(rankCounts)
        
        sortedTeams = sorted(rankCounts.keys(), key=lambda team: (rankCounts[team], -ord(team)), reverse=True)
        return "".join(sortedTeams)
       
def main():
    self = Solution
    votes = ["ABC","ACB","ABC","ACB","ACB"]
    # votes = ["WXYZ","XYZW"]
    # votes = ["ZMNAGUEDSJYLBOPHRQICWFXTVK"]
    # votes = ["BCA","CAB","CBA","ABC","ACB","BAC"]
    # votes = ["FVSHJIEMNGYPTQOURLWCZKAX","AITFQORCEHPVJMXGKSLNZWUY","OTERVXFZUMHNIYSCQAWGPKJL","VMSERIJYLZNWCPQTOKFUHAXG","VNHOZWKQCEFYPSGLAMXJIUTR","ANPHQIJMXCWOSKTYGULFVERZ","RFYUXJEWCKQOMGATHZVILNSP","SCPYUMQJTVEXKRNLIOWGHAFZ","VIKTSJCEYQGLOMPZWAHFXURN","SVJICLXKHQZTFWNPYRGMEUAO","JRCTHYKIGSXPOZLUQAVNEWFM","NGMSWJITREHFZVQCUKXYAPOL","WUXJOQKGNSYLHEZAFIPMRCVT","PKYQIOLXFCRGHZNAMJVUTWES","FERSGNMJVZXWAYLIKCPUQHTO","HPLRIUQMTSGYJVAXWNOCZEKF","JUVWPTEGCOFYSKXNRMHQALIZ","MWPIAZCNSLEYRTHFKQXUOVGJ","EZXLUNFVCMORSIWKTYHJAQPG","HRQNLTKJFIEGMCSXAZPYOVUW","LOHXVYGWRIJMCPSQENUAKTZF","XKUTWPRGHOAQFLVYMJSNEIZC","WTCRQMVKPHOSLGAXZUEFYNJI"]
    Solution.rankTeams(self, votes)
main()