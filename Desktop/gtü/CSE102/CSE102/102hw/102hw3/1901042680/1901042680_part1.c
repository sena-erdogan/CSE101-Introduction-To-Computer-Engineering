#include<stdio.h> /* This library is added to be able to use basic functions. */

int sum(int n, int flag){ /* If the user enters 0 as the operation flag, this function will calculate the addition of the numbers in the interval [1,n] */

int sum=0 ,i=1; /* Sum is started from 0 to get the addition right, i is started from 1 so 0 won't be counted */

    if( flag == 0 ){ /* If the user enters 0 as the flag, the sum function will calculate the addition of the even numbers in the interval [1,n] */

        if( n % 2 == 0 ){ /* This if statement will do the operations below only if n is even */

            while( i <= n ){ /* The while statement will keep going until i is equal to n since n is an even number and the i's the function will add together should also be even numbers,
                                That means n will be added to sum as well since it is in teh interval [1,n]. */

                if(i % 2 == 0){ /* This if statement will check if i is even and if it is, it will add them together until the while statement is not satisfied anymore */

                    printf("%d", i); /* If i is even, it will be printed on the screen */

                    sum += i; /* i's are added together */

                        if( i == n ){ /* If i is equal to n, that means the function fullfilled its purpose */

                            return sum; /* The sum value is equal to the sum of the even numbers in the interval [1,n], so the function can return that value */
                        
                        }else{ /* If i is not equal to n, then the process will keep going */

                            printf(" + "); /* Since we are showing the numbers added to the sum value to the user, if the process is still going, 
                            the function should print ' + ' between the numbers being added so the user can clearly see which numbers are used in the addition */

                        }

                }

                i++; /* i will be incremented by 1 to keep the while loop going */

            }

        }else{ /* This else means n is an odd number */

            while( i <= n - 1 ){ /* The while statement will keep going until i is equal to n - 1 since n is an odd number and the i's the function will add together should be even numbers */

                if(i % 2 == 0){ /* This if statement will check if i is even and if it is, it will add them together until the while statement is not satisfied anymore */

                    printf("%d", i); /* If i is even, it will be printed on the screen */

                    sum += i; /* i's are added together */

                        if( i == n - 1 ){ /* If i is equal to n - 1,  that means the function fullfilled its purpose */

                            return sum; /* The sum value is equal to the sum of the even numbers in the interval [1,n], so the function can return that value */
                        
                        }else{ /* If i is not equal to n - 1, then the process will keep going */

                            printf(" + ");/* Since we are showing the numbers added to the sum value to the user, if the process is still going, 
                            the function should print ' + ' between the numbers being added so the user can clearly see which numbers are used in the addition */

                        }
                }

                i++; /* i will be incremented by 1 to keep the while loop going */

            }

        }

    }else if(flag == 1){ /* If the user enters 1 as the flag, the sum function will calculate the addition of the odd numbers in the interval [1,n] */

        if( n % 2 == 0 ){ /* This if statement will do the operations below only if n is even */

            while( i <= n -1 ){ /* The while statement will keep going until i is equal to n - 1 since n is an even number and the i's the function will add together should be odd numbers */

                if(i % 2 == 1){ /* This if statement will check if i is odd and if it is, it will add them together until the while statement is not satisfied anymore */

                    printf("%d", i); /* If i is odd, it will be printed on the screen */

                    sum += i; /* i's are added together */

                        if( i == n -1 ){ /* If i is equal to n - 1, that means the function fullfilled its purpose */

                            return sum; /* The sum value is equal to the sum of the odd numbers in the interval [1,n], so the function can return that value */
                        
                        }else{ /* If i is not equal to n - 1, then the process will keep going */

                            printf(" + "); /* Since we are showing the numbers added to the sum value to the user, if the process is still going, 
                            the function should print ' + ' between the numbers being added so the user can clearly see which numbers are used in the addition */

                        }   

                }

                i++; /* i will be incremented by 1 to keep the while loop going */

            }

        }else{ /* This else means n is an odd number */

            while( i <= n ){ /* The while statement will keep going until i is equal to n since n is an odd number and the i's the function will add together should also be odd numbers */

                if(i % 2 == 1){ /* This if statement will check if i is odd and if it is, it will add them together until the while statement is not satisfied anymore */

                    printf("%d", i); /* If i is odd, it will be printed on the screen */

                    sum += i; /* i's are added together */

                        if( i == n ){ /* If i is equal to n, that means the function fullfilled its purpose */

                            return sum; /* The sum value is equal to the sum of the odd numbers in the interval [1,n], so the function can return that value */
                        
                        }else{ /* If i is not equal to n, then the process will keep going */

                            printf(" + "); /* Since we are showing the numbers added to the sum value to the user, if the process is still going, 
                            the function should print ' + ' between the numbers being added so the user can clearly see which numbers are used in the addition */

                        }   

                }

                i++; /* i will be incremented by 1 to keep the while loop going */

            }

        }

    }

}



int mult(int n, int flag){ /* If the user enters 1 as the operation flag, this function will calculate the multiplication of the numbers in the interval [1,n] */

    int mult = 1, i = 1; /* Mult is started from 1 to get the multiplication right, i is started from 1 so 0 won't be counted */

    if( flag == 0 ){ /* If the user enters 0 as the flag, the mult function will calculate the multiplication of the even numbers in the interval [1,n] */

        if( n % 2 == 0 ){ /* This if statement will do the operations below only if n is even */

            while( i <= n ){ /* The while statement will keep going until i is equal to n since n is an even number and the i's the function will multiply should also be even numbers */

                if(i % 2 == 0){ /* This if statement will check if i is even and if it is, it will multiply them until the while statement is not satisfied anymore */

                    printf("%d", i); /* If i is even, it will be printed on the screen */

                    mult *= i; /* i's are multiplied */

                        if( i == n ){ /* If i is equal to n, that means the function fullfilled its purpose */

                            return mult; /* The mult value is equal to the multiplication of the even numbers in the interval [1,n], so the function can return that value */
                        
                        }else{ /* If i is not equal to n, then the process will keep going */

                            printf(" * "); /* Since we are showing the numbers multiplied by the mult value to the user, if the process is still going, 
                            the function should print ' * ' between the numbers being multiplied so the user can clearly see which numbers are used in the multiplication */

                        } 

                }

                i++; /* i will be incremented by 1 to keep the while loop going */

            }

        }else{ /* This else means n is an odd number */

            while( i <= n - 1 ){ /* The while statement will keep going until i is equal to n - 1 since n is an odd number and the i's the function will multiply should be even numbers */

                if(i % 2 == 0){ /* This if statement will check if i is even and if it is, it will multiply them until the while statement is not satisfied anymore */

                    printf("%d", i); /* If i is even, it will be printed on the screen */

                    mult *= i; /* i's are multiplied */

                        if( i == n - 1 ){ /* If i is equal to n - 1,  that means the function fullfilled its purpose */

                            return mult; /* The mult value is equal to the multiplication of the even numbers in the interval [1,n], so the function can return that value */
                        
                        }else{ /* If i is not equal to n - 1, then the process will keep going */

                            printf(" * "); /* Since we are showing the numbers multiplied by the mult value to the user, if the process is still going, 
                            the function should print ' * ' between the numbers being multiplied so the user can clearly see which numbers are used in the multiplication */

                        }

                }

                i++; /* i will be incremented by 1 to keep the while loop going */

            }

        }

    }else if(flag == 1){ /* If the user enters 1 as the flag, the mult function will calculate the multiplication of the odd numbers in the interval [1,n] */

        if( n % 2 == 0 ){ /* This if statement will do the operations below only if n is even */

            while( i <= n -1 ){ /* The while statement will keep going until i is equal to n - 1 since n is an even number and the i's the function will ultiply should be odd numbers */

                if(i % 2 == 1){ /* This if statement will check if i is odd and if it is, it will multiply them until the while statement is not satisfied anymore */

                    printf("%d", i); /* If i is odd, it will be printed on the screen */

                    mult *= i; /* i's are multiplied by each other */

                        if( i == n -1 ){ /* If i is equal to n - 1, that means the function fullfilled its purpose */

                            return mult; /* The mult value is equal to the multiplication of the odd numbers in the interval [1,n], so the function can return that value */
                        
                        }else{ /* If i is not equal to n - 1, then the process will keep going */

                            printf(" * "); /* Since we are showing the numbers multiplied by the mult value to the user, if the process is still going, 
                            the function should print ' * ' between the numbers being multiplied so the user can clearly see which numbers are used in the multiplication */

                        }

                }

                i++; /* i will be incremented by 1 to keep the while loop going */

            }

        }else{ /* This else means n is an odd number */

            while( i <= n ){ /* The while statement will keep going until i is equal to n since n is an odd number and the i's the function will multiply should also be odd numbers */

                if(i % 2 == 1){ /* This if statement will check if i is odd and if it is, it will multiply them until the while statement is not satisfied anymore */

                    printf("%d", i); /* If i is odd, it will be printed on the screen */

                    mult *= i; /* i's are multiplied by each other */

                        if( i == n ){ /* If i is equal to n, that means the function fullfilled its purpose */

                            return mult; /* The mult value is equal to the multiplication of the odd numbers in the interval [1,n], so the function can return that value */
                        
                        }else{ /* If i is not equal to n, then the process will keep going */

                            printf(" * "); /* Since we are showing the numbers multiplied by the mult value to the user, if the process is still going, 
                            the function should print ' * ' between the numbers being added so the user can clearly see which numbers are used in the multiplication */

                        }

                }

                i++; /* i will be incremented by 1 to keep the while loop going */

            }

        }

    }

}

void main(){ /* This main function doesn't need to return a value so it can be a void function */

    int num, op_flag, _flag;

    printf("Enter an integer: "); /* The integer is taken from the user */
    scanf("%d", &num);

    printf("Please enter '0' for sum, '1' for multiplication\n"); /* The operation flag is taken from the user */
    scanf("%d",&op_flag);

    printf("Please enter '0' to work on even numbers, '1' to work on odd numbers\n"); /* The even / odd flag is taken from the user */
    scanf("%d",&_flag);

    switch(op_flag){ /* This switch-case function will determine the operation should be done on the number taken */

        case 0: if( _flag == 0 || _flag == 1 ){ /* If the operation flag is 0 and flag is 0 or 1 then the number and flag will be sent to the sum function */

            printf(" = %d\n", sum(num, _flag)); /* The result from the sum function will be returned to the main function and the sum will be printed with an '=' in front of it 
                                                to show the user what is the operation the function is doing */

        }else{ /*Something other than 0 or 1 is entered for the flag. There's no operation that can be done if the flag is not 0 or 1 */

            printf("Invalid value for odd/even selection.\n"); /* So the function will print an error to let the user know that he/she entered an invalid number for the flag */

        }

        break; /* If case 0 is not satisfied, break lets the switch-case function to control the other cases without executing case 0 */

        case 1: if( _flag == 0 || _flag == 1 ){ /* If the operation flag is 1 and flag is 0 or 1 then the number and flag will be sent to the mult function */

            printf(" = %d\n", mult(num, _flag)); /* The result from the mult function will be returned to the main function and the multiplication will be printed with an '=' in front of it 
                                                to show the user what is the operation the function is doing */

        }else{ /*Something other than 0 or 1 is entered for the flag. There's no operation that can be done if the flag is not 0 or 1 */

            printf("Invalid value for odd/even selection.\n"); /* So the function will print an error to let the user know that he/she entered an invalid number for the flag */

        } /* If case 1 is not satisfied, break lets the switch-case function to control the other cases without executing case 1 */

        break;

        default:  if( _flag == 1 || _flag == 0 ){ /* If neither case 0 nor case 1 is satisfied, which means the user entered some number other than 0 or 1 as the operation flag, the switch-case function will execute the default case */

            printf("Unsupported operation.\n"); /* If the user entered an invalid number for operation flag but entered a valid number for the flag, 
                                                the function will print an error message letting the user know that he/she entered an invalid value just for the opereation flag */

        }else{

            printf("Unsupported operation and also invalid value for odd/even selection.\n"); /* If the user entered an invalid number for both the operation flag and the flag, 
                                                                                            the function will print an error message to let the user know that he/she entered invalid values 
                                                                                            for both the operation flag and the flag */

        }

    }

}