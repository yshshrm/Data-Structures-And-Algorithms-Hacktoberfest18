func isPrime(number: Int) -> Bool {
    var result = true
    
    if number == 0 || number == 1 {
        result = false
    } else {
        for i in 2...(number - 1) {
            if number % i == 0 {
                result = false
                break
            }
        }
    }
    
    return result
}
