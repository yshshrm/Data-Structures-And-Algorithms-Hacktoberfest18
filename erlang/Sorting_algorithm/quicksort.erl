-module(quicksort).
-export([quicksort/2]).

quicksort(_, []) ->
    [];
quicksort(P, [Pivot | T]) ->
    quicksort(P, [X || X <- T, P(X, Pivot)]) ++ [Pivot] ++ quicksort(P, [X || X <- T, not P(X, Pivot)]).
