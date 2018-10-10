// Simple one level deep array flattener
const arrayToFlatten = [["1", "2"], "3", ["4", "5"]];

const flatten = (array) => array.reduce((prev, current) => prev.concat(current), []);


console.log(flatten(arrayToFlatten));

// Deep flattener
const arrayToDeepFlatten = [[['a', 'b', 'c', 'd'], [32, 4, 5, 6, 2], [13, 112, 3]], [], [['dfsd', 'eff', 'jjf', 'grt', 'erth']]];
const deepFlatten = (result, array) => Array.isArray(array) ? array.reduce(deepFlatten, result) : result.concat(array);


const resultArray = arrayToDeepFlatten.reduce(deepFlatten, []);

console.log(resultArray);