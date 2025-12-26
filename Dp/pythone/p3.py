#John is trying to solve the arithmetic series(AP). He wants to find two things in the series
#1. He wants to find nth terms in the series
#2. He wants to find the sum up to the nth term.
a = int(input("Enter the first term of the AP series: "))
d = int(input("Enter the common difference: "))
n = int(input("Enter the number of terms: "))
nth_term = a + (n - 1) * d
sum_n_terms = (n / 2) * (2 * a + (n - 1) * d)
print("The nth term of the AP series is:", nth_term)
print("The sum of the first n terms of the AP series is:", sum_n_terms)