class Node(object):
    def __init__(self,value,next_node=None):
        self.value = value
        self.next_node = next_node
    def set_value(self,new_value):
        self.value = new_value
    def get_value(self):
        return value
    def set_next_node(self,node):
        self.next_node = node
    def get_next_node(self):
        return self.next_node
