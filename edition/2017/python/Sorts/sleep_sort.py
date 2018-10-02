from threading import Thread
from time import sleep
from random import randint

description = """
************************************************************************************
SLEEP SORT:
1. Create a thread for each array element
2. Each thread sleeps for an amount of time proportional to its array element's value
3. Each thread then appends its value to the sorted array after sleeping

- Works with negative numbers if you add (negation of lowest number in list) to every element in the list,
    run sleep sort, then subtract back the number to every element.
- Limitations include being extremely slow if input array has a huge number
************************************************************************************
"""

state = { 'sorted_list': [] }

def sleep_sort(numbers):
    state['sorted_list'] = []
    state['length'] = len(numbers)
    threads = [Thread(target=_appender, args=(number,)) for number in numbers]
    [t.start() for t in threads]
    [t.join() for t in threads]

    return state['sorted_list']

def _appender(number):
    sleep(number)
    state['sorted_list'].append(number)

def test():
    unsorted = [randint(0, 9) for _ in range(10)]
    print('Using randomly-generated unsorted list: [%s]' % ', '.join(str(i) for i in unsorted))
    sorted_list = sleep_sort(unsorted)
    print('Got sleep-sorted list: [%s]' % ', '.join(str(i) for i in sorted_list))
    print('This should print True: %s' % (sorted(unsorted) == sorted_list))

if __name__ == '__main__':
    print(description)
    print('This should take no more than 10 seconds')
    test()
