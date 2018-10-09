def prepare_pows(string,prime):
    pows = []
    for i in range(len(string)):
        pows.append(prime**i)     
    return pows       


def prepare_hashes(string,pows,prime):
    hashes = []
    for i,el in enumerate(string):
        if hashes:
            hashes.append(hashes[i-1] + pows[i] * ord(el))
        else:
            hashes.append(ord(el))
    return hashes


# method for getting substring hash based on earlier computed hashes
def get_sub_hash(hashes, left, right):
    result = hashes[right]
    if left > 0:
        result -= hashes[left-1]
    return result

# method for getting full string polynomial hash using currying
def get_string_hash(string):
    def prepare_pows(prime,q=None):
        pows = []
        for i in range(len(string)):
            pows.append(prime**i)     
        def prepare_hashes():
            hashes = []
            for i,el in enumerate(string):
                if hashes:
                    hashes.append(hashes[i-1] + pows[i] * ord(el))
                else:
                    hashes.append(ord(el))
            return hashes[len(string)-1]
        return prepare_hashes
    return prepare_pows    
        
# method for checking equality of two strings
def equals(first_str, second_str):
    first_len = len(first_str)
    second_len = len(second_str)
    if first_len != second_len or not (first_str or second_str):
        return False

    if get_string_hash(first_str)(101)() == get_string_hash(second_str)(101)():
        return True
    else:
        return False
# implementation of Rabin-Karp algorithm 
def rabinkarp(string,pattern):
    pows = prepare_pows(string,101)
    string_hashes = prepare_hashes(string,pows,101)
    hs = 0
    for i,el in enumerate(pattern):
        hs += pows[i]*ord(el)
    
    i = 0
    while i + len(pattern) <= len(string):
        if get_sub_hash(string_hashes,i,i+len(pattern)-1) ==  hs * pows[i]:
            print(f'element on position {i}')
        i += 1


if __name__ == '__main__':
    first_str = 'string'
    second_str = 'str'
    assert equals(first_str,second_str) == False

    first_str = ''
    second_str = ''
    assert equals(first_str,second_str) == False 

    first_str = ' '
    second_str = ' '
    assert equals(first_str,second_str) == True

    first_str = 'string'
    second_str = 'string'
    assert equals(first_str,second_str) == True  

    string = 'stritrng'
    substring = 'tr'
    rabinkarp(string,substring)
