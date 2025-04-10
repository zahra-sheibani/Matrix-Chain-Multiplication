# Matrix-Chain-Multiplication
This program implements the Matrix Chain Multiplication (MCM) algorithm using Dynamic Programming to determine the optimal order of multiplying matrices with the minimum number of scalar multiplications.\
code Overview:
1.	Input Generation\
o	The user inputs n, which determines a random number of matrices (1 to n).\
o	A random dimension array (d[]) is generated, where d[i] represents the number of rows and columns for each matrix.\
o	The user also inputs m, which defines the range of random values for the dimensions.\
2.	Dynamic Programming Solution (minmult function)\
o	A DP table m[][] stores the minimum number of multiplications required for each matrix subsequence.\
o	A table p[][] keeps track of the optimal split positions for constructing the parenthesization order.\
o	The function iterates diagonally over possible subproblems and updates m[i][j] accordingly.\
3.	Parenthesization Order (order function)\
o	Uses recursion to print the optimal way to multiply matrices.\
o	Follows the p[][] table to reconstruct the multiplication sequence.\
4.	Output\
o	Displays the randomly generated dimensions of the matrices.\
o	Prints the minimum number of multiplications needed to compute the product.\
o	Outputs the optimal parenthesization order.

