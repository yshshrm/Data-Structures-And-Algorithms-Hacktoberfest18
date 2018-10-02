-module(forkjoin).

-export([parallel/2]).

%%%-----------------------------------------------------------------------------
%%% @doc Executes the given function on every task in tasks in parallel.
%%% @spec parallel(Function, Tasks) -> Results
%%%       where Results is a list matching the arity of input list Tasks
%%%       but contains the result of invoking Function on those tasks
%%% @end
%%%-----------------------------------------------------------------------------
parallel(Function, Tasks) ->
    Pids = fork(Function, Tasks),
    join(Pids).

%%------------------------------------------------------------------------------
%% @doc Forks all tasks in given list Tasks to new Erlang processes. Those
%%      processes invoke Function on forked tasks.
%% @spec fork(Function, Tasks) -> Pids
%%       where Pids is a list of process IDs
%% @end
%%------------------------------------------------------------------------------
fork(Function, Tasks) ->
    Parent = self(),
    Pids = lists:map(fun(Task) ->
                             spawn(fun() ->
                                           invoke(Parent, Function, Task)
                                   end)
                     end, Tasks),
    Pids.

join([P|Ps]) ->
    receive
        {P, Result} -> [Result|join(Ps)]
    end;
join([]) ->
    [].

invoke(Receiver, Function, Instance) ->
    Receiver ! {self(), (catch Function(Instance))}.
