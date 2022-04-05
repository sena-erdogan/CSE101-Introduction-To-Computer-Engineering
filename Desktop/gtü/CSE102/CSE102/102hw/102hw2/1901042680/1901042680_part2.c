#include<stdio.h> /* To take values from the user and printing some messages to the screen, to basically talk to the user, stdio.h library is added. */
#include<math.h> /* To take the power and logarithm of some values, math.h is added. */

int number_length(int number){ /* This function finds the length of the number by taking its base 10 logarithm.  */

    return log10(number) + 1; /* If we take base 10 logarithm of 1000, the result will be 3, so the value found by taking the logarithm of the number should be incremented by 1. */

}

int find_digit(int number, int index){ /* This function will find the nth digit when the number given is written 100 times. */

    int result;
    
    if(index % number_length(number) == 0){ /* If the index corresponds to the last digit of the number, the method used below won't work since it gives 0. */

        result = number % 10; /* The digit should be the last digit of the number. The last number will be the remainder when the number is divided by 10. */

        return result; /* The last digit will be returned. */

    }else{

        result = (number / pow(10,number_length(number) - index % number_length(number))); /* The remainder of the index divided by the length of the number will be subtracted from 
                                                                                        the number's length. That will be the number of digits we should erase starting from the right of the
                                                                                        number. By taking the power of 10 to that number, we will have the number from start to the wanted digit. 
                                                                                        After this calculations, we will have a double number but since we want to fully erase that float part
                                                                                        of the new number, we will define a variable for that final number and it will be an integer. */

        return result % 10 ; /* The calculations done above will give the value until that digit.
                                For example if the number is 123456 and the digit we want is 3,
                                these calculations will give us 123. 
                                So we should divide that number by 10 and return the remainder. */

        }

    

}

void main(){ /* The main function doesn't need to return a value, so it can be a void function. */

    int num, row; 

    printf("Enter a number (maximum 6 digits):\n"); /* The number is taken from the user. */
    scanf("%d",&num);

    printf("Your number has %d digits\n", number_length(num)); /* We are letting the user know how many digits are there in the chosen number using the returned value from the function. */

    printf("When your number is written 100 times next to each other, which digit of this number would you like to see? :\n"); /* The digit number is taken from the user. */
    scanf("%d", &row);

    printf("%d.th digit of the big number sequence: %d\n", row, find_digit(num, row)); /* The number returned from the function is printed. */
    

}