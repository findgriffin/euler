#! /usr/bin/nodejs
// sum of all the even numbers in the fibonacci sequence below four million

var FOUR_MILLION = 4000000

var n = 1
var total = 0
var n1 = 1
var n2 = 1
while (n < FOUR_MILLION) {
    if (n % 2 == 0){
        total += n
    }
    n2 = n1
    n1 = n
    n = n1 + n2
}
console.log(total)
