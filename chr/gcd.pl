%Should be run with SWI-Prolog

:- use_module(library(chr)).
:- chr_constraint gcd/2,res/1.

%r1 reduces one gcd constraint to a res constraint if the second parameter is 0.
r1 @ gcd(A,0) <=> res(A).
%r2 simplifies a gcd constraint
r2 @ gcd(A,B) <=> C is mod(A,B), gcd(B,C).
