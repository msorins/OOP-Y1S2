/*
 3. a. Print the Pascal triangle of dimension n of all combinations C(m,k) of m objects taken by k, k =
 0, 1, ..., m, for line m, where m = 1, 2, ..., n.
 b. Given a vector of numbers, find the longest contiguous subsequence of prime numbers

 7. Decompose a given even natural number, greater than 2, as a sum of two prime numbers
(Goldbach’s conjecture).
*/

#include <stdio.h>


void readPascal(int *n) {
    /*
     * READS the number n
     */
    printf("n: \n");
    scanf("%d", &*n);
}

void pascalTriangle() {
    /*
     *
     * Computes and prints the pascal triangle
     *
     */
    int n, i, j, crt = 1, last;
    int mat[2][101];

    // Call the read function 2
    readPascal(&n);

    //Initialised the matrix with 0
    for(i=0; i<2; i++)
        for(j=0; j<100; j++)
            mat[i][j] = 0;

    //First row initialised with 1
    mat[0][0] = 1;

    for(int i=1; i<=n; i++, crt = 1 - crt){
        last = 1 - crt;
        mat[crt][0] = 1;
        printf("%d ", mat[crt][0]);
        for(int j=1; j<i; j++)
        {
            mat[crt][j] = mat[last][j-1] + mat[last][j];
            printf("%d ", mat[crt][j]);
        }
        printf("\n");
    }


}

int prim(int nr) {
    /*
     * nr: int number
     * return: 1 if the number is prime or zero otherwise
     */
    if( nr <= 1)
        return 0;

    for(int i = 2; i * i <= nr; i++)
        if ( nr % i == 0 )
            return 0;

    return 1;
}

void readLargestSubsequence(int *n, int v[]) {
    printf("n: \n");
    scanf("%d", &*n);

    //Reads the number
    for(int i = 0; i < *n; i++) {
        scanf("%d", &v[i]);
    }
}

void printLargestSubsequence(int v[], int pozStart, int maxLength) {
    /*
     * v[]: the array
     * pozStart: integer, the starting pozition of the longest subsequence
     * maxLength: integer, number of elements in the resulted subsequence
     */
    for(int i = pozStart; i < pozStart + maxLength; i++)
        printf("%d ", v[i]);
}

void largestSubsequence() {
    /*
     * Reads and computes the longest subsequence of prime numbers
     */
    int n, pozStart = 0, length = 0, i, maxLength = 0;
    int v[101];


    //Call the read function
    readLargestSubsequence(&n, v);

    //Computes the longest subsequence with the given property
    for(i = 0; i < n; i++) {
        if(prim(v[i]))
            length++;
        else
            length=0;
        if(length > maxLength) {
            maxLength = length;
            pozStart = i - length + 1;
        }
    }

    printLargestSubsequence(v, pozStart, maxLength);
}

void readDecompose(int *n) {
    printf("Give a number\n");
    scanf("%d", &*n);
}

void printDecompose(int a, int b) {
    printf("Result is: %d %d", a, b);
}

void decompose() {
    //Solves the decomposition problem

    int n, isSol = 0, a, b;
    //Call the read function
    readDecompose(&n);

    //Here do the computation
    for(int i = 2; i <= n / 2; i++)
        if(prim(i) && prim(n-i)) {
            isSol = 1l;
            a = i;
            b = n - i;
        }

    //Call the print function if problem is solved
    if(isSol)
        printDecompose(a, b);
    else
        printf("No solution found");
}

void decide() {
    /*
     * MENU SUBPROGRAM
     */
    int n;
    printf("1. Pascal triangle \n2. Largest contiguous subsequence of prime numbers \n3. Decompose a number as the sum of two another numbers");
    scanf("%d", &n);
    if(n == 1 )
        pascalTriangle();
    if( n == 2 )
        largestSubsequence();
    if( n == 3 )
        decompose();
}

int main(int argc, const char * argv[]) {
    /*
     * MAIN FUNCTION WHICH CALLS THE MENU DECISION FUNCTION
     */
    decide();
    return 0;
}

