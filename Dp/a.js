// // // let x = prompt("Enter a value for x in a.js:");
// // // console.log(typeof x); // output is
// // // rectify the give code to print smallest among them 

// // // let x = 2;
// // // let y = 3;
// // // let z = 1;

// // // if (x < y) {
// // //     if (x < z) {
// // //         console.log(x);
// // //     } else {
// // //         if (y > z) {
// // //             console.log(y);
// // //         } else {
// // //             console.log(z);
// // //         }
// // //     }
// // // } else {
// // //     if (y < z) {
// // //         console.log(y);
// // //     } else {
// // //         if (x < z) {
// // //             console.log(x);
// // //         } else {
// // //             console.log(z);
// // //         }
// // //     }
// // // }
// // // intput x is less than 10 
// // let x = parseInt(inputChar);
  
// // if (x == 1) {
// //     console.log("None");
// // } else if (x == 4 || x == 6 || x == 8 || x == 9) {
// //     console.log("non-prime number");
// // } else {
// //     console.log("prime number");
// // }

// // given n print its digits sum and product 
// let n = 1234; // Example input
// let sum = 0;
// let product = 1;
// while (n > 0) {
//     let digit = n % 10;
//     sum += digit;
//     product *= digit;
//     n = Math.floor(n / 10);
// }
// console.log("Sum of digits:", sum);
// console.log("Product of digits:", product);
 let n = parseInt(inputChar);
    
// Function to calculate power
 function calculatePower(base, len) {
   // Implement your code here
    let result = 1;
    for (let i = 0; i < len; i++) {
        result *= base;
    }
    return result;
 }

// Function to check if a number is Armstrong
 function checkArmstrong(n) {
 // Implement your code here
    let originalNumber = n;
    let sum = 0;
    let len = n.toString().length;
    while (n > 0) {
        let digit = n % 10;
        sum += calculatePower(digit, len);
        n = Math.floor(n / 10);
    }
    return sum === originalNumber;
 
 }
 
    if (checkArmstrong(n)) {
        console.log("YES");
    } else {
        console.log("NO");
    }
