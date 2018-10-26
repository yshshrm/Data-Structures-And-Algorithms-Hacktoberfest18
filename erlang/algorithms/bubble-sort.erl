-module(bubblesort).
-export([sort/1]).
-import(lists, [reverse/1]).

sort(L) ->
  sort(L, [], true).

sort([], L, true) ->
  reverse(L);
  
sort([], L, false) ->
  sort(reverse(L), [], true);
  
sort([ X, Y | T ], L, _) when X > Y ->
  sort([ X | T ], [ Y | L ], false);
  
sort([ X | T ], L, Halt) ->
sort(T, [ X | L ], Halt).
