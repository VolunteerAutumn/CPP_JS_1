alert("Hello! This is the sequence of my tasks.");
// ---------------------------------------------
alert("Task 1 - testing:");
age = prompt("Enter your age:");
if (age <= 12) {
    alert("You are a child.");
}
else if (age > 12 && age <= 18) {
    alert("You are a teenager.");
}
else if (age > 18 && age <= 60) {
    alert("You are an adult.");
}
else {
    alert("You are a senior.");
}

// ---------------------------------------------
alert("Task 2 - testing:");
num = prompt("Enter a number:");
switch (num) {
    case '1':
        alert("!");
        break;
    case '2':
        alert("@");
        break;
    case '3':
        alert("#");
        break;
    case '4':
        alert("$");
        break;
    case '5':
        alert("%");
        break;
    case '6':
        alert("^");
        break;
    case '7':
        alert("&");
        break;
    case '8':
        alert("*");
        break;
    case '9':
        alert("(");
        break;
    case '0':
        alert(")");
        break;
    default:
        alert("Invalid input.");
}

// ---------------------------------------------
alert("Task 3 - testing:");
tdn = prompt("Enter a three-digit number:");
d1 = tdn % 10;
d2 = Math.floor((tdn % 100) / 10);
d3 = Math.floor(tdn / 100);
if (d1 == d2 || d1 == d3 || d2 == d3) {
    alert("There are identical digits.");
} else {
    alert("All digits are different.");
}

// ---------------------------------------------
alert("Task 4 - testing:");
year = prompt("Enter a year:");
if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
    alert("The year is a leap year.");
} else {
    alert("The year is not a leap year.");
}

// ---------------------------------------------
alert("Task 5 - testing:");
fdg = prompt("Enter the five-digit number:");
d1 = Math.floor(fdg / 10000);
d2 = Math.floor((fdg % 10000) / 1000);
d3 = Math.floor((fdg % 1000) / 100);
d4 = Math.floor((fdg % 100) / 10);
d5 = fdg % 10;
if (d1 == d5 && d2 == d4) {
    alert("The number is a palindrome.");
} else {
    alert("The number is not a palindrome.");
}

// ---------------------------------------------
alert("Task 6 - testing:");
USD = prompt("Enter the amount in USD:");
currency = prompt("Enter the target currency (EUR, UAH, AZN):");
switch (currency) {
    case 'EUR':
        alert(USD * 0.91 + " EUR");
        break;
    case 'UAH':
        alert(USD * 36.93 + " UAH");
        break;
    case 'AZN':
        alert(USD * 1.7 + " AZN");
        break;
    default:
        alert("Invalid currency.");
}

// ---------------------------------------------
alert("Task 7 - testing:");
sum = prompt("Enter the purchase amount:");
if (sum >= 200 && sum < 300) {
    discount = 0.03;
} else if (sum >= 300 && sum < 500) {
    discount = 0.05;
} else if (sum >= 500) {
    discount = 0.07;
}
finalSum = sum - (sum * discount || 0);
alert("The final amount after discount is: " + finalSum);

// ---------------------------------------------
alert("Task 8 - testing:");
radiusOfCircle = prompt("Enter the radius of the circle:");
perimeterOfSquare = prompt("Enter the perimeter of the square:");
sideOfSquare = perimeterOfSquare / 4;
if (2 * Math.PI * radiusOfCircle <= sideOfSquare) {
    alert("The circle can fit inside the square.");
} else {
    alert("The circle cannot fit inside the square.");
}

// ---------------------------------------------
alert("Task 9 - testing:");
points = 0;
alert(`Question 1: What is a factorial?
a) The sum of all natural numbers up to a given number.
b) The product of all natural numbers up to a given number.
c) The difference between the largest and smallest natural numbers up to a given number.`);

answer1 = prompt("Enter your answer (a, b, or c):");
if (answer1.toLowerCase() === 'b') {
    alert("Correct!");
    points += 2;
}
else {
    alert("Incorrect. The correct answer is b) The product of all natural numbers up to a given number.");
}

alert(`Question 2: What is the name of Eevee's ice-type evolution?
a) Vaporeon
b) Sylveon
c) Glaceon`);

answer2 = prompt("Enter your answer (a, b, or c):");
if (answer2.toLowerCase() === 'c') {
    alert("Correct!");
    points += 2;
} else {
    alert("Incorrect. The correct answer is c) Glaceon.");
}

alert(`Question 3: Which planet is known as the strangest outcast planet?
    a) Neptune
    b) WasP-17b
    c) CFBDSIR 2149-0403`);

answer3 = prompt("Enter your answer (a, b, or c):");
if (answer3.toLowerCase() === 'c') {
    alert("Correct!");
    points += 2;
} else {
    alert("Incorrect. The correct answer is c) CFBDSIR 2149-0403.");
}

alert(`Your total points: ${points}/6`);

// ---------------------------------------------
alert("Task 10 - testing:");
day = parseInt(prompt("Enter the day of the month (1-31):"));
month = parseInt(prompt("Enter the month (1-12):"));
year = parseInt(prompt("Enter the year (e.g., 2023):"));

nextDay = day + 1;
nextMonth = month;
nextYear = year;
daysInMonth = [31, ( (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
if (nextDay > daysInMonth[month - 1]) {
    nextDay = 1;
    nextMonth += 1;
}
if (nextMonth > 12) {
    nextMonth = 1;
    nextYear += 1;
}
alert(`The next date is: ${nextDay}/${nextMonth}/${nextYear}`);
// ---------------------------------------------
alert("All tasks completed. TYSFM!!!");
