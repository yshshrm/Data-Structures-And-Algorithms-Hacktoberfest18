object linear_search{

def linear_search(arr : List[Int], ele : Int) : Int = {

  def go (l : List[Int], i : Int) : Int = {
    l match {
      //If list is empty return -1
      case List() => -1 
      //Return the index of element if found
      case x :: xs  if x == ele => i + 1
      //return -1 if not found
      case x :: Nil if x != ele => -1
      //else recursively call
      case x :: xs if x != ele => go(xs, i+1)
    }
  }

  go(arr, -1)

}

}
