import Foundation

var flag: Bool = false;

let number : Int = 13;
for i in 2…number/2 {
    if(number % i == 0){
        flag = true
        break;
    }
}
if flag == false {
    print(“\(number ) is prime!”);
} else {
    print(“\(number ) is not prime!”);
}
