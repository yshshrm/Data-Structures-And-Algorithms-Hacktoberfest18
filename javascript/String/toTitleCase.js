// using string prototype, title case a given sentence with an extension method

Object.defineProperty(String.prototype, "toTitleCase", {
    value: function toTitleCase() {
        const letterArray = this.split('');
        let previousCharacter = null;
        let titleCaseArray = []
        letterArray.forEach((char, index) => {
            if (index === 0 || (previousCharacter && previousCharacter === ' ')) {
                titleCaseArray.push(char.toUpperCase())
            } else {
                titleCaseArray.push(char)
            }
            previousCharacter = char;
        })

        return titleCaseArray.join('');
    }
})


console.log('some string of things'.toTitleCase())
// expected output: Some String Of Things