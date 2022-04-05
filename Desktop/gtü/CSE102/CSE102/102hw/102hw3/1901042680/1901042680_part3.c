#include<stdio.h> /* This library is added to be able to use the basic functions */

int andop(int a, int b){ /* This function calculates the bitwise and operation of two integers */

    if( a == b && a == 1 ){ /* If both a and b are 1, the and operation of them will be 1 */

        return 1; /* If the and operation gives 1, the function will return that value */

    }else{ /* If a and b are both 0 or they are different from each other, the and operation of those two numbers will give 0 */

        return 0; /* If that is the case, the function will return 0 */

    }

}

int get_first(){ /* This function gets the first integer from the user. It doesn't have any parameters since it will get the value from the user and return that value */

    int num; /* There is an integer variable to store the number in */

    printf("First Integer:\t"); 
    scanf("%d", &num); /* The number taken from the user is put in the address of the num variable */

    return num; /* The num variable is returned */

}

int get_second(){ /* This function takes the second variable from the user in the same way as the first one */

    int num;

    printf("Second Integer:\t");
    scanf("%d", &num);

    return num;

}

int length(int n){ /* This function calculates the length of a given number */
    
    int length = 0; /* The length value is zero at first */

    while( n != 0 ){ /* When the number becomes 0, the loop will stop */

        n = n / 10; /* n is divided by 10 to decrement it by one digit */

        length++; /* If the loop is able to divide the number by 10, that means the number has lost a digit, so the length value is incremented by 1 */

    }

    return length; /* The final length value is returned */

}

int is_binary(int n){ /* This function checks if a given integer consists of only 1's and 0's */

    while( n >= 9 ){ /* This loop goes on until the number is less than 9 because if it is, that means all digits of the number are checked */

        if( n % 10 == 0 || n % 10 == 1 ){ /* If the remainder from n divided by 10 is equal to 1 or 0, that means the last digit of that integer is 1 or 0. */

            n = n / 10; /* The loop will keep checking the last digit of the number and will divide the number by 10 to move on to the next digit */

        }else{ /* If the remainder from division by 10 is some value other than 1 or 0, that means the number contains a number that is not 1 or 0, which makes it a non-binary number */

		    return 0; /* If it is not a binary number, the function will return 0 */

	    }     

    }

    return 1; /* If the number can get out of the while loop, that means it is a binary number so the function will return 1 */

}

void main(){ /* The main function is void since it doesn't need to return a value */

    int num1, num2, first, second, and = 0, l, len; /* The variables num1 and num2 are the integers taken from the user, the first and second variables will carry the values of 
                                                        num1 and num2 in order. The and variable is the integer we get after doing the and operation between num1 and num2. 
                                                        Variables l and len are both realtes to the length of num1 and consequently num2. The variables that have the same values are used 
                                                        since there are operations that will be made on those values, so those values will change, and the values they have 
                                                        in the first place are going to be needed after the operations. Those numbers will carry temporary values. */

    num1 = get_first(); /* The numbers will be taken from the user using specific functions */
    num2 = get_second();

    while( length(num1) != length(num2) ){ /* If the numbers have different lengths */

        printf("Integers should have the same length, please enter 2 new integers.\n"); /* An error will be printed */

        num1 = get_first(); /* The function will keep asking for new integers until the numbers have the same length */
        num2 = get_second();

    }

    while( is_binary(num1) == 0 || is_binary(num2) == 0 ){ /* If either one of those integers has a digit other than 0 or 1 */

        printf("Integers should be binary, please enter 2 new integers.\n"); /* An error will be printed */

        num1 = get_first(); /* The function will keep asking for new integers until the numbers both only consist of 0's and 1's */
        num2 = get_second();

        while( length(num1) != length(num2) ){ /* If lengths are the same and the function checks if binary or not, if the user enters numbers with different lengths 
                                                the function will not be able to detect that error since the numbers are already passed the length-check. 
                                                So after the binary check is done, the numbers should be checked again length-wise to make sure that the numbers are binary and also 
                                                are the same length. */

            printf("Integers should have the same length, please enter 2 new integers.\n"); /* An error will be printed */

            num1 = get_first(); /* The function will keep asking for new integers until the numbers have the same length */
            num2 = get_second();

        }

    }

    len = length(num1); /* len variable will have the length of num1, therefore the length of num2 */

    while( len > 0 ){ /* Until len becomes 0, this while loop will keep going */

        l = len - 1 ; /* l is equal to length - 1 so the loops can go through all digits of the taken integers */

        first = num1; /* First has the value of num1 so the changes made on 'first' variable won't affect the value of num1. 
                        Since the loop starts doing the and operation from left, the rest of num1 will be lost. To do the and operation on the second digit, 
                        we will still need num1's first value. Same goes for num2. */
        second = num2;

        while( l > 0 ){ /* This while loop should keep going until it reaches the digit at the left end of the number, that also  means it should keep going until the l value is 0 */

            first = first / 10; /* The integers are divided by 10 until we reach the left end of numbers */
            second = second / 10;

            l--; /* l value should be decremented by 1 to keep this while loop going */

        }

        and = (and * 10) +  andop( first % 10, second % 10 ); /* Since we started the and operation from left end of the integers, the final number is started getting values from 
                                                                the left end too. */

        len--; /* len value is decremented by 1 to keep the while loop going */

    }

    printf("%d AND %d = %d\n", num1, num2, and); /* The integers and the result will be printed on the screen and the program will end */
    
}