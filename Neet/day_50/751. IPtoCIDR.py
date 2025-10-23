class Solution:
    def ipToCIDR(self, ip: str, n: int):
        eight_bits = ip.split(".")
        print(eight_bits)
        lowest_bit_start = bin(int(eight_bits[-1][-1]))[2: ]
        print(lowest_bit_start)

        highest_bit_n = bin(n)
        print(highest_bit_n)




def main():
    solution = Solution()
    ip = "255.0.0.7"
    n = 10
    #["255.0.0.7/32","255.0.0.8/29","255.0.0.16/32"]

    ip = "117.145.102.62"
    n = 8
    #["117.145.102.62/31","117.145.102.64/30","117.145.102.68/31"]
    solution.ipToCIDR(ip, n)
main()