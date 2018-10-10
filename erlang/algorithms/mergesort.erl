-module(mergesort).
-export([sort/1]).

sort([ A | [] ]) -> [A];
sort(List) ->
    [SubLst1, SubLst2] = partition(List, 0, length(List) div 2, [[], []]),
    io:format("~w ~n", [[SubLst1, SubLst2]]),
    merge(sort(SubLst1), sort(SubLst2)).

partition([], _, _, [SubList1, SubList2]) -> [SubList1, SubList2];
partition([ H | Rest ], Index, Pivot, [Lst1, Lst2]) when Index < Pivot ->
    partition(Rest, Index + 1, Pivot, [[H | Lst1], Lst2]);
partition([ H | Rest ], Index, Pivot, [Lst1, Lst2]) ->
    partition(Rest, Index + 1, Pivot, [Lst1, [H | Lst2]]).

merge([], Y) -> Y;
merge(X, []) -> X;
merge([ X1 | Xs ], [ Y1 | Ys ]) when X1 < Y1 ->
    [ X1 | merge(Xs, [Y1 | Ys]) ];
merge([ X1 | Xs ], [ Y1 | Ys ]) ->
    [ Y1 | merge([X1 | Xs], Ys) ].