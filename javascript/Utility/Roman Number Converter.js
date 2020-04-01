const chars = ["I","V","X","L","C","D","M"];
const values = [1,5,10,50,100,500,1000];

function convertToRoman(num) {
    let Roman = "";

    for (let i = values.length-1; i >= 0;i--) {
        const currentValue = values[i];

        if (currentValue <= num) {
            Roman += chars[i];
            num -= currentValue;
            Roman = Roman
            .replace(chars[i + 1] + chars[i].repeat(4),chars[i] + chars[i + 2])
            .replace(chars[i].repeat(4), chars[i] + chars[i + 1]);
            i = values.length;
        }

    }

    console.log(Roman);
    return Roman;
}

convertToRoman(9);