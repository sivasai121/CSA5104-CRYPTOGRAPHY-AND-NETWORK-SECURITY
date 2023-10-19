#include <stdio.h>
#include <math.h>
int M,A,C;
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int modExp(int a, int b, int c) {
    int result = 1;
    while (b > 0) {
        if (b % 2 == 1)

		    result = (result * a) % c;
        a = (a * a) % c;
        b = b / 2;
    }
    return result;
}
int main() {
    int p, q, n, phi, e, d;
    printf("Enter prime number p: ");
    scanf("%d", &p);
    printf("Enter prime number q: ");
    scanf("%d", &q);
    n = p * q;
    phi = (p - 1) * (q - 1);
    for (e = 2; e < phi; e++) {
        if (gcd(e, phi) == 1)
            break;
    }
    for (d = 2; d < phi; d++) {
        if ((e * d) % phi == 1)
            break;
    }
    printf("Public Key (e, n): (%d, %d)\n", e, n);
    printf("Private Key (d, n): (%d, %d)\n", d, n);
    printf("enter M value:");
    scanf("%d",&M);    
    A= pow(M,e);
    
    C=A%n;
    printf("C value is %d\n",C);
    printf("M value is %d",M);

}
