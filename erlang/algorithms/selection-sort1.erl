select_sort([]) -> [];
select_sort(List) -> select_sort(List, []).

select_sort([], Sorted) -> Sorted;
select_sort([H|T], Sorted) ->
    {Max, Rest} = select_max(T, H, []),
    select_sort(Rest, [Max|Sorted]).

select_max([], Max, Rest) -> {Max, Rest};
select_max([H|T], Max, Rest) when H < Max ->
    select_max(T, Max, [H|Rest]);
select_max([H|T], Max, Rest) ->
    select_max(T, H, [Max|Rest]).
