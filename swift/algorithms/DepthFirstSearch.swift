

import Foundation

//Dfs for a connected graph
//Parameters
//-----------
//data: A Dictionary that maps keys to strings
//adjacency_list: a graph of keys
//visited: a dictionary to check if the key nodes were visited or not
//key:  the key to search for in the graph
//source node key

func dfs(_ data:[Int:String],_ adjacencyList:[Int:[Int]],_ visited:inout [Int:Bool],_ key:Int,_ source:Int)->(Bool,String){
    
   
    if source == key{
        return (true,data[source]!)
    }
    var d = ""
    var result = false
   
    visited[source] = true
    if(adjacencyList[source] == nil){ return (false,"")
    }
    for i in adjacencyList[source]!{
        
        if !visited[i]!{
            (result,d) = dfs(data,adjacencyList,&visited,key,i)
            if result{ return (result,d)
            }
        }
        
    }
        
    return (result,d)
    
}


//Testing code
//-------------

var data=[0:"ab",23:"gh",56:"rt"]
var adjacency_list=[0:[23],23:[56]]
var visited = [0:false,23:false,56:false]

let (result,d) = dfs(data,adjacency_list,&visited,56,0)

if result{
    print(d)
}

var visited2 = [0:false,23:false,56:false]

let (result2,d2) = dfs(data,adjacency_list,&visited2,40,0)

if !result2{
    print("Key not found")
}
