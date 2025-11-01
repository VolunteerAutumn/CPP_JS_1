// task 1
n = prompt("Enter a number:");
alert(n*n)
// task 2
a = +prompt("Enter first number:");
b = +prompt("Enter second number:");
alert((a+b)/2)
// task 3
s = +prompt("Enter a side of a square:");
alert("Area of the square is " + s*s)
//task 4
kml = +prompt("Enter length in kms:")
alert(kml*0.621371 + " miles")
// task 5
n1 = +prompt("Enter first number:");
n2 = +prompt("Enter second number:");
alert(`${n1} + ${n2} = ${n1+n2}`)
alert(`${n1} - ${n2} = ${n1-n2}`)
alert(`${n1} * ${n2} = ${n1*n2}`)
alert(`${n1} / ${n2} = ${n1/n2}`)
// task 6
a = +prompt("Formula: a*x+b=0. Enter a:")
b = +prompt("Formula: a*x+b=0. Enter b:")
alert("x = " + (-b/a))
// task 7
h = +prompt("Enter current hour:")
m = +prompt("Enter current minute:")
s = +prompt("Enter current second:")
lh = 23 - h
lm = 59 - m
ls = 59 - s
alert(`Time left until the next day: ${lh} hours, ${lm} minutes, ${ls} seconds.`)
// task 8
nu3 = +prompt("Enter a three-digit number:")
d2 = Math.floor((nu3 % 100) / 10)
alert("The second digit is " + d2)
// task 9
nu5 = +prompt("Enter a five-digit number:")
lasdig = nu5 % 10
alert("Now it's " + lasdig + Math.floor(nu5/10))
// task 10
sum = +prompt("Enter the sum on money you got:")
alert("Your salary is $" + (250 + 0.1*sum))
