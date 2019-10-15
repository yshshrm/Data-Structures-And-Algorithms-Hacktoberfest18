'use strict';

async function sleepSort(unsortedArray) {
    let sortedArray = [];

    unsortedArray.forEach(v => {
        setTimeout(() => {
            console.log(v);
        }, v);
    });
}


console.log('SleepSort');
const array = [1, 6, 2, 10, 8, 5, 7, 3];
sleepSort(array);
console.log(array);