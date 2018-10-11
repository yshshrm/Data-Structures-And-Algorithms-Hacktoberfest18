func isPalindrome(text: String) -> Bool {
    var result = true
    
    let loweredText = text.lowercased()
    let reversedText = String(loweredText.reversed())
    
    if loweredText != reversedText {
        result = false
    }
    
    return result
}
