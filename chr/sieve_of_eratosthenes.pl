%Should be run with SWI-Prolog

:- use_module(library(chr)).
:- chr_constraint nums/1, prime/1.

%Prepare a list of constraints out of a single nums constraint, whereas A marks the upper boundary for finding primes.
r1 @ nums(A) <=> A < 2 | true.
r2 @ nums(A) <=> prime(A), A1 is A-1, nums(A1).

%Removes all numbers wrapped in a prime constraint which are a multiple of another number within the constraint list.
r3 @ prime(A) \ prime(B) <=> mod(B,A) =:= 0 | true.
