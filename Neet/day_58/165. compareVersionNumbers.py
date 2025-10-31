class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        def delimiter(string):
            dimension = {}
            string_list = string.split(".")
            for i, char in enumerate(string_list):
                list_char = list(char)
                for item in list_char:
                    if item == "0":
                        list_char.remove(item)
                    else:
                        char = "".join(list_char)
                        break
                dimension[i] = int(char)
            return dimension
        
        def alignment(dimension1, dimension2):
            if dimension1.keys() == dimension2.keys():
                return 
            elif len(dimension1.keys()) < len(dimension2.keys()):
                diff_keys = dimension2.keys()-dimension1.keys()
                list_diff_keys = list(diff_keys)
                for key in list_diff_keys:
                    dimension1[key] = 0
            else:
                diff_keys = dimension1.keys()-dimension2.keys()
                list_diff_keys = list(diff_keys)
                for key in list_diff_keys:
                    dimension2[key] = 0
                    
            return [dimension1, dimension2]
            
        dim_1_dict = delimiter(version1)
        dim_2_dict = delimiter(version2)
        aligned = alignment(dim_1_dict, dim_2_dict)
        if aligned is None:
            dim_1, dim_2 = dim_1_dict, dim_2_dict
        else:
            dim_1, dim_2 = aligned
        
        for key, value in zip(dim_1, dim_2):
            if dim_1[key] > dim_2[key]:
                return 1
            elif dim_1[key] < dim_2[key]:
                return -1
        return 0

def main():
    solution = Solution()
    version1 = "1.2"
    version2 = "1.10" #-1

    # version1 = "1.01"
    # version2 = "1.001" #0

    # version1 = "1.0"
    # version2 = "1.0.0.0" #0
    print(solution.compareVersion(version1, version2))
main()