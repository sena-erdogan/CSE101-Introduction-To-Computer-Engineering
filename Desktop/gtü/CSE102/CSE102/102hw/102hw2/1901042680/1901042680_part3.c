#include<stdio.h> /* To take values from the user and printing some messages to the screen, to basically talk to the user, stdio.h library is added. */

void main(){ /* This main function doesn't need a return valueso it can be void. */

    printf("*****Welcome to ABC Exchange Office*****\n\n"); /* Greeting */

    double amount; /* The amount is taken in double since there will be calculations with double numbers. */

    printf("Enter your amount:\n");
    scanf("%lf", &amount);

    int currency;

    printf("\nPlease select your currency\n1. Turkish Lira\n2. Euro\n3. Dollar\n\n");
    scanf("%d", &currency);

    switch(currency){ /* This switch function prints the amount and the currency that the user currently has. */

        case 1: printf("You have %lf Turkish Liras\n", amount);

                break;

        case 2: printf("You have %lf Euros\n", amount);

                break;

        case 3: printf("You have %lf Dollars\n", amount);

                break;

        default: printf("Your selection is invalid!"); /* If the user enters something other than 1, 2 or 3, the default part will warn the user. */


    }

    int selection;

    printf("Choose which currency you want convert\n");
    scanf("%d", &selection);

    if(currency == 1){ /* If the currency the user chose is Turkish Lira, then the convertions will be made according to that. */

        switch(selection){

            case 1: printf("\nYou have %lf Turkish Liras\n", amount); 

                    break;

            case 2: printf("\nYou have %lf Euros\n", amount / 6.69); /* 1 Euro equals to 6.69 Turkish Lira, so in this case, the amount will be divided by 6.69 */

                    break;

            case 3: printf("\nYou have %lf Dollars\n", amount / 6.14); /* 1 Dollar equals to 6.14 Turkish Lira, so in this case, the amount will be divided by 6.14 */

                    break;

            default: printf("\nYour selection is invalid!\n"); 

        }

    }else if(currency == 2){ /* If the currency chosen is not Turkish Lira, we will first convert the currency to Turkish Lira and then to what currency the user wants to convert. */

        switch(selection){

            case 1: printf("\nYou have %lf Turkish Liras\n", amount * 6.69);

                    break;

            case 2: printf("\nYou have %lf Euros\n",amount);

                    break;

            case 3: printf("\nYou have %lf Dollars\n", (amount * 6.69) / 6.14);

                    break;

            default: printf("\nYour selection is invalid!\n"); 

        }

    }else if(currency == 3){

        switch(selection){

            case 1: printf("\nYou have %lf Turkish Liras\n", amount * 6.14);

                    break;

            case 2: printf("\nYou have %lf Euros\n", (amount * 6.14) / 6.69);

                    break;

            case 3: printf("\nYou have %lf Dollars\n", amount);

                    break;

            default: printf("\nYour selection is invalid!\n");

        }

    }

    

}