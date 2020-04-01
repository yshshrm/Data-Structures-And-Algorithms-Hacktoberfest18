class RunningLengthEncoder:
    @staticmethod
    def encode(s):
        if s is not None and len(s) > 0:
            i = 1
            result = ""
            last = s[0]
            count = 1
            while i < len(s):
                tmp = s[i]
                if tmp == last:
                    count = count + 1
                else:
                    result = result + last + str(count)
                    count = 1
                    last = tmp
                i = i + 1
            if i == len(s):
                result = result + last + str(count)
            return result
        else:
            return s


if __name__ == "__main__":
    s = input("Please enter string to encode\n")
    print("encoded string is " + RunningLengthEncoder.encode(s))
