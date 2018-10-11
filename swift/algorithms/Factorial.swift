func factorial(number: Double) -> Double {
    if number == 1 {
        return 1
    } else {
        return number * factorial(number: number - 1)
    }
}
