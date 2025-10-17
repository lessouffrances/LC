class Solution:
    def convert(self, s, numRows) -> str:
        intermediate = numRows-2
        if intermediate < 0:
            return s
        group_size = numRows+intermediate     
        num_group = len(s)//group_size+1
        hashMap = {}
        curr_char_index = 0

        for group in range(num_group):
            base_col = group + group*(intermediate)
            for i in range(group_size):
                if curr_char_index >= len(s):
                    break

                if i < numRows:
                    # Going down: row increases, column stays same
                    row = i
                    col = base_col
                    hashMap[curr_char_index] = [row, col]

                else:
                    # Diagonal up-right: intermediate elements
                    # i = numRows means 1st intermediate (row numRows-2, col+1)
                    # i = numRows+1 means 2nd intermediate (row numRows-3, col+2), etc.
                    offset = i - numRows + 1
                    row = numRows - 1 - offset
                    col = base_col + offset
                    hashMap[curr_char_index] = [row, col]
                
                curr_char_index += 1
        
        num_cols = hashMap[list(hashMap.keys())[-1]][1]

        matrix = [ [0 for _ in range(num_cols+1)] for _ in range(numRows) ]

        for char_index, position in hashMap.items():
            row, col = position[0], position[1]
            char = s[char_index]
            matrix[row][col] = char
        
        res = ""
        for row in range(len(matrix)):
            for col in range(len(matrix[0])):
                if matrix[row][col] != 0:
                    res += matrix[row][col]
        return res  
    
def main():
    solution = Solution()
    # s = "PAYPALISHIRING"
    # numRows = 3
    # s = "PAYPALISHIRING"
    # numRows = 4
    s = "A"
    numRows = 1 
    solution.convert(s, numRows)


main()