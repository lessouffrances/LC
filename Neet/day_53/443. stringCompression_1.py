class Solution:
    def compress(self, chars) -> int:
        write, read = 0, 0
        curr_count = 0

        while read < len(chars):
            if read == 0:
                curr_count += 1
                read += 1
                continue
            if chars[read] == chars[read-1]:
                read += 1
                curr_count += 1
            else:
                chars[write] = chars[read-1]
                write += 1
                if curr_count > 1:
                    curr_count_list = list(str(curr_count))
                    for char in curr_count_list:
                        chars[write] = char
                        write += 1

                curr_count = 1
                read += 1
        
        if read > 0:
            chars[write] = chars[read-1]
            write += 1
            if curr_count > 1:
                curr_count_list = list(str(curr_count))
                for char in curr_count_list:
                    chars[write] = char
                    write += 1
        
        print(chars[: write])
        return write

def main():
    solution = Solution()
    chars = ["a","a","a","b","b","c","c","c"]
    # chars = ["a"]
    # chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
    solution.compress(chars)
main()