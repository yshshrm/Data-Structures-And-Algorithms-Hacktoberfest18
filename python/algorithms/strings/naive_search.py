# Implementation of naive search of substrings in string

def naive_search_while(string,sub):
    str_len = len(string)
    sub_len = len(sub)

    for i in range(str_len-sub_len +1):
        for j in range(sub_len):
            if string[i+j] == sub[j]:
                if j == sub_len-1:
                    return i
            else:
                break


def naive_search_for(string,sub):
    str_len = len(string)
    sub_len = len(sub)
    i = j = 0

    while i <= str_len-sub_len and j < sub_len:
        if string[i+j] == sub[j]:
            j += 1
        else:
            i += 1
            j = 0  
    return i if j == sub_len else None


if __name__ == '__main__':
    string = 'spamspam'
    sub = 'msp'
    
    res_for = naive_search_for(string, sub)
    res_while = naive_search_while(string, sub)
    assert res_for == res_while