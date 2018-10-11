#!/usr/bin/python3
# coding=utf-8
"""
Implementation of linear hashing
"""
from math import log2


class LinearHashing(object):
    def __init__(self, *args, **kwargs):
        self.threshold = kwargs.get('threshold', 0.7)
        self.data_capacity_per_bucket = kwargs.get('data_capacity_per_bucket', 2)  # capacity to store data per bucket
        self.total_data = 0  # keep count of total inserted record
        self.total_removal = 0  # keep count of total deleted record
        self.buffer = {key: [] for key in range(2)}  # initial buffer
        self.index_counter = 0  # keep index counter from where we are supposed to start split in phase
        self.previous_phase = 1  # keeping phase number to reset index counter

    @property
    def current_phase(self):
        return int(log2(len(self.buffer)))

    @property
    def buffer_capacity(self):
        return self.data_capacity_per_bucket * len(self.buffer)

    @property
    def threshold_outbound(self):
        return ((self.total_data + 1) / self.buffer_capacity) > self.threshold

    def hash_function(self, value, flag=0):
        """

        :param value: value on which hash function to be applied
        :param flag: set flag to 1 if splitting the bucket
        :return:
        """
        if not flag:
            # if no splitting require
            return value % (2 ** self.previous_phase)
        else:
            # if splitting require
            return value % (2 ** (self.current_phase + 1))

    def set_index_counter_if(self):
        """
        set index counter from where splitting to be done to 0 when phase changes
        :return: None
        """
        if self.current_phase != self.previous_phase:
            self.index_counter = 0
            self.previous_phase = self.current_phase

    def insert(self, value, print_status=0):
        """

        :param value: value to be inserted
        :param print_status: set to 1 if
        :return:
        """
        self.set_index_counter_if()

        if self.threshold_outbound:
            # buffer to be extend
            self.buffer[len(self.buffer)] = []
            buffer_index = self.hash_function(value)
            self.buffer[buffer_index] = self.buffer.setdefault(buffer_index, []) + [value]
            # bucket to be split
            bucket_to_split = self.buffer[self.index_counter]
            self.buffer[self.index_counter] = []
            for data in bucket_to_split:
                buffer_idx = self.hash_function(data, flag=1)
                self.buffer[buffer_idx] = self.buffer.setdefault(buffer_idx, []) + [data]
            self.index_counter += 1
        else:
            buffer_index = self.hash_function(value)
            # self.buffer[buffer_index].append(value)
            self.buffer[buffer_index] = self.buffer.setdefault(buffer_index, []) + [value]
        self.total_data += 1

        if print_status:
            print(self.buffer)
            print("INDEX: {}\nCURRENT PHASE: {} \t PREVIOUS PHASE: {}".format(self.index_counter, self.current_phase, self.previous_phase))
        return True

    def delete(self):
        return NotImplementedError

    def __repr__(self):
        return "\n".join("{} -> {}".format(k, v) for k, v in self.buffer.items())

    def __str__(self):
        return "\n".join("{} -> {}".format(k, v) for k, v in self.buffer.items())


if __name__ == "__main__":
    hash_bucket = LinearHashing(data_capacity_per_bucket=3, threshold=0.7)
    input_lis = [3, 2, 4, 1, 8, 14, 5, 10, 7, 24, 17, 13, 15]
    for i in input_lis:
        print("{2}\n{1} Inserting: {0:-3d} {1}".format(i, "#"*5, "-*"*50))
        result = hash_bucket.insert(i, print_status=1)
        if result:
            print("{} inserted successfully.\n{}".format(i, "-*"*50))
    print(hash_bucket)
