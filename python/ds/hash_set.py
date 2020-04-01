class HashSet:
    def __init__(self, num_bucket):
        self.num_bucket = num_bucket
        self.hashset = [[] for i in range(self.num_bucket)]

    def __str__(self):
        temp = []
        for bucket in self.hashset:
            temp.extend(bucket)
        return temp.__str__()
        
    def __len__(self):
        temp = []
        for bucket in self.hashset:
            temp.extend(bucket)
        return len(temp)

    def hash(self, key):
        return key % self.num_bucket

    def add(self, key):
        if self.contains(key):
            return
        else:
            hash_val = self.hash(key)
            self.hashset[hash_val].append(key)

    def remove(self, key):
        if self.contains(key):
            hash_val = self.hash(key)
            self.hashset[hash_val].remove(key)

    def contains(self, key):
        hash_val = self.hash(key)
        if key in self.hashset[hash_val]:
            return True
        else:
            return False


if __name__ == '__main__':
    test = HashSet(10000)
    test.add(1)
    test.add(11)
    test.add(111)
    print(test, "length:", len(test))
    print(test.contains(1))
    test.remove(111)
    print(test, "length:", len(test))
