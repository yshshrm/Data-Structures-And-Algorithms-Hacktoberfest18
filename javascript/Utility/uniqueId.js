const uniqueIdGenerator = (length = 32) => {
    let uniqueIdArray = [];
    let allCharacters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789';    
    for (let i = 0; i < length; i++) {
        uniqueIdArray[i] = allCharacters.charAt(Math.floor(Math.random() * allCharacters.length));
    }
    return uniqueIdArray.join('');
}

console.log(uniqueIdGenerator());  
console.log(uniqueIdGenerator(15));