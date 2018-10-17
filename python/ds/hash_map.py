class HashMap:
    def __init__(self, num_bucket):
        self.num_bucket = num_bucket
        self.keyset = [[] for i in range(self.num_bucket)]
        self.valset = [[] for i in range(self.num_bucket)]

    def hash(self, key):
        return key % self.num_bucket

    def get_key_index(self, key):
        hash_val = self.hash(key)
        for i, k in enumerate(self.keyset[hash_val]):
            if k == key:
                return i
        return -1

    def put(self, key, value):
        hash_val = self.hash(key)
        key_index = self.get_key_index(key)
        if  key_index != -1:
            self.valset[hash_val][key_index] = value
        else:
            self.keyset[hash_val].append(key)
            self.valset[hash_val].append(value)

    def get(self, key):
        key_index = self.get_key_index(key)
        if key_index != -1:
            return self.valset[self.hash(key)][key_index]
        else:
            return -1

    def remove(self, key):
        key_index = self.get_key_index(key)
        if key_index != -1:
            hash_val = self.hash(key)
            del self.keyset[hash_val][key_index]
            del self.valset[hash_val][key_index]

if __name__ == '__main__':
    test = HashMap(10000)
    test.put(15, 1111)
    print(test.get(15))
