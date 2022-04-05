#include<stdio.h> /* This library is added to be able to use basic functions. */
#include<math.h> /* This library is added in order to take the square root of a number with sqrt() function. */

int isprime(int a){ 

    int flag = 0; /* There is a flag to check if the number divided with any of the numbers between 2 and itself. */

    for(int i=2; i <= sqrt(a); i++){ /* This will check if the number is prime by the equation. */

        if( a % i == 0 ){ /* This will check if the number is dividible by any number less than itself. */

            flag++; /* If the number divided with a number, then the flag will be incremented by 1 so the flag won't be 0 anymore. */

        }

    }

    if(flag == 0){ /* If the flag is still zero that means the number didn'tdivide by any of the numbers between 2 and itself so it's a prime number. */

        return flag; /* To let the main function know that the number is prime, the isprime function will return the flag which is 0. */

    }else{ /* If flag is something other than 0, that means the number was divided by one or more numbers, which means it's not a prime number. */

        int least = 2; /* In this case, the function is supposed to return the least divisor of that number. Since 1 can divide any number, least will start from 2. */

        for(; least < a ; least++){ /* This for function will make sure while we increment the least amount and check if the number is divisible by it, 
                                        that the least won't be greater than or equal to the number. */

            if( a % least == 0 ){ /* Checks if the number is dividible by the values of least. */

                return least; /* The function will return the least number the least value gets that can divide the number. */

            }

        }

    }

}

void main(){ /* This main function can be void since it doesn't need to return a value. */

    int num;

    printf("Please enter an integer: \n\n"); /* Taking the integer from the user. */
    scanf("%d", &num); /* Assigning that value to the num variable. */

    for(int i=2; i<num; i++){ /* This loop will go through every integer from 2 to the taken integer to determine which operation to be done. */

        if( isprime(i) == 0 ){ /* If the isprime function returns a 0, that means the integer is a prime number. */

            printf("%d is a prime number\n\n", i); /* If the integer is prime, the function will just print that the integer is a prime nummber. */

        }else{ /* If the isprime function doesn't return 0, it will return another number. */

            printf("%d is not a prime number, it is dividible by %d\n\n", i, isprime(i)); /* The number returned is the least divisor of that number, and the function will print that value. */

        }

    }


}

