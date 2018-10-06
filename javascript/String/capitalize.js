const capitalize = phrase => {
    const words = [];

    for (let word of phrase.split(" ")) {
        if (word[0]) {
            words.push(word[0].toUpperCase() + word.slice(1));
        }
    }

    return words.join(" ");
};

console.log(capitalize("this is a phrase. . .  "))