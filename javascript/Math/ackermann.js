// Implemented by itsjustmustafa
//
// The Ackermann Function
// https://en.wikipedia.org/wiki/Ackermann_function
// A(m, n) = {
//  n+1               if m = 0
//  A(m-1,1)          if m > 0 and n = 0
//  A(m-1, A(m, n-1)) if m > 0 and n > 0
//  }

function ackermann(m, n){
    if(m == 0){
        return(n+1);
    }
    
    if(n == 0){
        return(ackermann(m-1, 1));
    }
    
    return(ackermann(m-1, ackermann(m, n-1)));
}
