'''The general search scheme uses Python's yield mechanism, so you can use the 
earcher like an iterator, so every time you call the next function on that iterator,
a new solution (if there is one) get generated and returned. PrototypeDotBuilder
is a simple class that implements a callback handler that gets called by the
general search scheme when a new prototype was drawn out of the queue. The
class tracks every call to the handler by generating a short string that
represents an edge in DOT language, resulting in a tree in DOT representation
which contains the searched space. That tree will be printed to the console,
so you can use the execution of this script as a direct input (UNIX pipes)
for graphviz.

Example: python search.py --strategy=<strategy> | dot -T<fmt> > <output>.<fmt>
where strategy in (bfs|uniform_cost|dfs)
'''
__author__ = "Markus Guenther"

import Queue
import copy
import optparse
import sys
import math

goal_state = ['w', 'w', 'w', '_', 's', 's', 's']

class Prototype:
    '''Simple class that represents the prototypes of our solution space.
    A prototype becomes a solution, if its state matches a goal state.
    '''
    def __init__(self, parent, state, costs, level, id):
        self.parent = parent;
        self.state = state
        self.costs = costs
        self.level = level
        self.id = id
        
    def get_params(self):
        '''Returns those parameters that are relevant for the generalized
        search scheme.
        '''
        return self.state, self.costs, self.level
    
    def __str__(self):
        '''Returns the string representation of a prototype.
        '''
        return "prototype %s with costs %i at level %i" % \
        (self.state, self.costs, self.level)
    
class PrototypeAnalyzer:
    def __init__(self):
        self._dotstring = "strict graph {\n"
        self.states_visited = 0
    
    def prototype_callback_handler(self, prototype):
        if prototype.parent is not None:
            self._dotstring += "%i -- %i [label=\"%s\"]\n" %  \
            (prototype.parent.id, prototype.id, prototype.state)
            
        self.states_visited += 1
            
    def finalize_dotstring(self):
        return self._dotstring + "}"
    
def search(start_state, queue, get_from_queue, put_in_queue, prototype_callback, limit=-1):
    node_id = 0
    put_in_queue(queue, Prototype(None, start_state, 0, 1, node_id))
    
    while not queue.empty():
        prototype = get_from_queue(queue)
        prototype_callback(prototype)
        
        if is_goal_state(prototype):
            yield prototype
        
        state, costs, level = prototype.get_params()
        
        if level is limit:
            print "Reached the maximum search tree level. Search process aborted."
            break
        
        for token_idx in xrange(len(state)):
            if state[token_idx] is '_': continue
            
            for i in xrange(1,4):
                for j in (-1,1):
                    if is_possible_move(state, token_idx, j*i):
                        node_id += 1
                        put_in_queue(queue, generate_prototype(prototype, 
                                                               token_idx, 
                                                               j*i,
                                                               node_id))

def generate_prototype(prototype, token_idx, movement, node_id):
    token = prototype.state[token_idx]
    new_state = copy.deepcopy(prototype.state)
    new_state[token_idx] = '_'
    new_state[token_idx-movement] = token
    new_costs = prototype.costs + 1
    
    if abs(movement) is 3:
        new_costs += 1
        
    return Prototype(prototype, new_state, new_costs, prototype.level+1, node_id)

def is_possible_move(state, token_idx, move_by):
    to_idx = token_idx - move_by
    if to_idx > 6 or to_idx < 0:
        return False
    if state[to_idx] is not '_':
        return False
    return True

def is_goal_state(prototype):
    global goal_state
    return goal_state.__eq__(prototype.state)
    
def bfs(limit, how_many):
    def bfs_put_in_queue(queue, prototype):
        queue.put(prototype)
    
    def bfs_get_from_queue(queue):
        return queue.get()

    try:
        analyzer = PrototypeAnalyzer()
        iter_search = search(['w', 's', 'w', 'w', 's', 's', '_'], Queue.Queue(0), 
                             bfs_get_from_queue, bfs_put_in_queue, 
                             analyzer.prototype_callback_handler, limit)
        for i in xrange(how_many):
            iter_search.next()
    except StopIteration:
        print "BFS found no solution."
    finally:
        print analyzer.finalize_dotstring()

def uniform_cost(limit, how_many):
    def priority_put_in_queue(queue, prototype):
        queue.put((prototype.costs, prototype))

    def priority_get_from_queue(queue):
        costs, prototype = queue.get()
        return prototype
    
    try:
        analyzer = PrototypeAnalyzer()
        iter_search = search(['w', 's', 'w', 'w', 's', 's', '_'], Queue.PriorityQueue(0), 
                             priority_get_from_queue, priority_put_in_queue,
                             analyzer.prototype_callback_handler, limit)
        print dir(iter_search)
        for i in xrange(how_many):
            iter_search.next()
    except StopIteration:
        print "Uniform cost search found no solution."
    finally:
        print analyzer.finalize_dotstring()

def dfs(limit, how_many):
    def dfs_put_in_queue(queue, prototype):
        queue.put(prototype)
    
    def dfs_get_from_queue(queue):
        return queue.get()
    
    if limit is -1:
        # or else this won't terminate!
        limit = 20
    
    try:
        analyzer = PrototypeAnalyzer()
        iter_search = search(['w', 's', 'w', 'w', 's', 's', '_'], Queue.LifoQueue(0), 
                            dfs_get_from_queue, dfs_put_in_queue, 
                            analyzer.prototype_callback_handler, limit)
        for i in xrange(how_many+1):
            iter_search.next()
    except StopIteration:
        print "DFS found no solution."
    finally:
        print analyzer.finalize_dotstring()
    
def parse_options():
    parser = optparse.OptionParser(usage="USAGE: " + sys.argv[0] + " [options]",
                                   description="Mandatory options: strategy, " +
                                   "start_state")
    parser.add_option("-s", "--strategy",
                      action="store", dest="strategy", default=None,
                      help="Specifies the search strategy.")
    parser.add_option("-l", "--limit",
                      action="store", type="int", dest="limit", default=-1,
                      help="Specifies how deep the search tree can get at " +
                      "maximum.")
    parser.add_option("-n", "--how_many",
                      action="store", type="int", dest="how_many",
                      default=1,
                      help="Specifies the amount of solutions to be generated. " + \
                      "Be aware that this will only terminate if the search tree " + \
                      "is limited or if there are as many solutions within the " + \
                      "searched hierarchy as specified.")
    
    (options, args) = parser.parse_args()
    
    if options.strategy is None:
        print "Please specify a search strategy. Program aborted."
        parser.print_help()
        sys.exit()
        
    return options.strategy, options.limit, options.how_many

if __name__ == '__main__':
    strategy, limit, how_many = parse_options()
    
    if strategy == "bfs":
        bfs(limit, how_many)
    elif strategy == "uniform_cost_search":
        uniform_cost(limit, how_many)
    else:
        dfs(limit, how_many)
