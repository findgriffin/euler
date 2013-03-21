#! /usr/bin/nodejs
// add all the multiples of 3 and 5 below 1000

var TOTAL = 0;

for(i=0; i<1000; i++) {
    if (i % 3 === 0 || i % 5 === 0) {
        TOTAL += i
    }
}
console.log(TOTAL)
