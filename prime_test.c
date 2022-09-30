#include <stdio.h>

int main(){

	unsigned long long num, divisor=2;

	printf("Test whether a number is prime.\n Use 'CTRL-C' when done\n");

	while(1){
		printf("Enter a number > 1\n");
		scanf("%llu", &num);
		divisor = 2;
		if( num <= 1 ){
			printf(" The number must be > 1. Try again\n");
			continue;
		}
		while( divisor < num ) {
			if( 0==num%divisor ) {
				printf(" %llu is not a prime number\n", num);
				break;
			}
			divisor++;
		}
		if( divisor >= num ){
			printf(" %llu is a prime number\n", num);
		}
	}
}
		
