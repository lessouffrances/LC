import random
class RandomizedSet(object):
    def __init__(self):
        self.vals = []
        self.val_to_idx = {}
        pass

    def insert(self, val):
        if val in self.val_to_idx:
            return False
        
        self.vals.append(val)
        size = len(self.vals)
        self.val_to_idx[val] = size-1
        return True
        
    def remove(self, val):
        if val not in self.val_to_idx:
            return False

        size = len(self.vals)
        last_val = self.vals[size-1]
        idx = self.val_to_idx[val]
        # swap
        self.vals[idx], self.vals[size-1] = self.vals[size-1], self.vals[idx]
        self.vals.pop()
        self.val_to_idx[last_val] = idx
        del self.val_to_idx[val]
        return True

    def getRandom(self):
        random_idx = random.randrange(len(self.vals))
        return self.vals[random_idx]