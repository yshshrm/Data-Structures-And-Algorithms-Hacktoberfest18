const BMICalculator = (weight, height) => (
  Math.round(weight / Math.pow(height, 2) * 100) / 100
);

const weight = 60; // kilogram
const height = 1.74; // meter

const myBMI = BMICalculator(weight, height);
console.log(myBMI); // 19.82
