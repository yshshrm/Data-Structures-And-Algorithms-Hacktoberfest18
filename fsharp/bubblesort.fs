let bubblesort (l : 'a list) : 'a list = 
  let rec inner (l1: 'a list) (go : bool) (acc: 'a list) : 'a list =
    printfn "1) l1=%A acc=%A" l1 acc
    match (l1,go) with 
    | ([], false) -> acc
    | ([], true) -> inner acc false []   // restart again with the new list
    | ([x], _ ) -> inner [] go (acc @ [x])
    | (x::xs, _) when x > xs.Head ->  inner (x :: xs.Tail) true (acc @ [xs.Head])  // one swap happened, turn the flag to true
    | (x::xs, _) -> inner xs go (acc @ [x])

  inner l false []
