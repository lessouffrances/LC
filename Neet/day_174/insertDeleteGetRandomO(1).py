import random

class RandomizedSet(object):

    def __init__(self):
        self.vals = []
        self.val_to_idx = {}
        
    def insert(self, val):
        if val in self.val_to_idx:
            return False
        self.vals.append(val)
        idx = len(self.vals)-1
        self.val_to_idx[val] = idx
        return True
        
    def remove(self, val):
        if val not in self.val_to_idx:
            return False
        
        # swap the value
        last_idx = len(self.vals)-1
        last_val = self.vals[last_idx]
        idx = self.val_to_idx[val]
        self.vals[last_idx], self.vals[idx] = self.vals[idx], self.vals[last_idx]
        self.vals.pop()
        self.val_to_idx[last_val] = idx
        del self.val_to_idx[val]
        
        return True
        
    def getRandom(self):
        random_idx = random.randrange(len(self.vals))
        return self.vals[random_idx]
