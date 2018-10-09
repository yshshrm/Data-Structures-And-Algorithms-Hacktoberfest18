const countLetters = (string) => {
  return string.split("").reduce((accumulator, currentValue) => {
      accumulator.hasOwnProperty(currentValue) ? 
      accumulator[currentValue]++ :
      accumulator[currentValue] = 1
      return accumulator
  }, {})
}

console.log(countLetters('abbcccddddeeeee'))