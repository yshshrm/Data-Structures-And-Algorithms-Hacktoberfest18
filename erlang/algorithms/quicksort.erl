-module(quicksort).
-export([sort/1]).

sort([]) -> [];
sort([ H | List ]) ->
    [Smaller, Greater] = partition(H, List, [[], []]),
    SortedSmaller = quicksort(Smaller),
    SortedGreater = quicksort(Greater),
    SortedSmaller ++ [ H ] ++ SortedGreater.

partition(_, [], Parts) -> Parts;
partition(Pivot, [ H | List ], [Smaller, Greater]) when H < Pivot ->
    partition(Pivot, List, [[ H | Smaller ], Greater]);
partition(Pivot, [ H | List ], [Smaller, Greater]) ->
    partition(Pivot, List, [Smaller, [ H | Greater ]]).
