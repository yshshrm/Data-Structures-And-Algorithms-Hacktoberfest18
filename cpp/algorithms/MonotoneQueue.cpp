// Monotone queue
// This queue can tell the maximum element in O(1) time.
// Time complexities:
// - push: amortized O(1)
// - pop: O(1)
// - top: O(1)

template<class T> struct MaxQ {
  deque<T> D, Q;

  void push(T x) {
    while (!D.empty() && x > D.back()) D.pop_back(); // Change to `<` for MinQ
    D.push_back(x);
    Q.push_back(x);
  }

  void pop() {
    if (D.front() == Q.front()) D.pop_front();
    Q.pop_front();
  }

  T top()   { return D.front(); }
  T front() { return Q.front(); }
  T empty() { return Q.empty(); }
  T size()  { return Q.size();  }
};
