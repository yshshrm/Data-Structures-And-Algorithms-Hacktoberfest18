// Find sum of all even fibonacci numbers from 1 through 4,000,000

let a = 2, 
    b = 1, 
    c;

const cap = 4000000
let sum = 0;

while (a < cap){

    a % 2 === 0 ? sum+= a: sum += 0;
    c = a;
    a = a+b;
    b = c;

}
console.log(sum);

