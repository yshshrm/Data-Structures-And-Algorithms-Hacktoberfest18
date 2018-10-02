-module(pqsort).

-export([pqsort/1]).

pqsort([]) -> [];
pqsort([Pivot]) -> [Pivot];
pqsort([Pivot|Rest]) ->
    io:format("+", []),
    L = [X || X <- Rest, X < Pivot],
    R = [Y || Y <- Rest, Y >= Pivot],
    [SL, SR] = forkjoin:parallel(fun pqsort/1, [L,R]),
    io:format("-", []),
    SL ++ [Pivot] ++ SR.

