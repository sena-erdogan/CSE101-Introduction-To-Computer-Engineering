#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

struct Hospital{

    char* name;
    char citiesServed[3];

};

struct Hospital results[4];

struct card{

    const char *face;
    const char *suit;

};

struct card deck[52];

int numPathsHome(int street, int avenue);

int does_cover_new_cities(char _cities[6], char possible_locations[4][3], struct Hospital results[4]);

int is_all_covered(char _cities[6], struct Hospital results[4]);

int canOfferCovidCoverage(char _cities[6], char _locations[4][3], int _numHospitals, struct Hospital results[4]);

int is_same_card(int i, struct card deck[52]);

void mix_deck(struct card deck[52]);

int numPathsHome(int street, int avenue){ /* Part 1 */

    if( street > 1 && avenue > 1 ){

        return numPathsHome(street - 1, avenue) + numPathsHome(street, avenue - 1);

    }else if( street == 1 && avenue > 1 ){

        return numPathsHome(street, avenue - 1);

    }else if( street > 1 && avenue == 1 ){

        return numPathsHome( street - 1, avenue );

    }else if(street == 1 && avenue == 1){

        return 1;

    }

}

int does_cover_new_cities(char _cities[6], char possible_locations[4][3], struct Hospital results[4]){

}

int is_all_covered(char _cities[6], struct Hospital results[4]){

}

int canOfferCovidCoverage(char _cities[6], char _locations[4][3], int _numHospitals, struct Hospital results[4]){ /* Part 2 */

    if( _numHospitals != 0 ){

        if(does_cover_new_cities( _cities, _locations, results ) == 1){

        }

    }

    if( is_all_covered(_cities, results) == 1 ){

        return 1;

    }else{

        return 0;

    }

}

int is_same_card(int i, struct card deck[52]){ /* Checking if a card has already been chosen to be in the deck */

    int flag = 0, j;

    for( j=0; j<i; j++ ){

        if( strcmp(deck[i].face, deck[j].face) == 0 && strcmp(deck[i].suit, deck[j].suit) == 0 ){

            flag++;

        }

    }

    return flag;
}

void mix_deck(struct card deck[52]){ /* Part 3 */

    int face_temp, suit_temp, i;

    srand(time(0));

    for(i=0; i<52; i++){

        face_temp = rand() % 13 + 1; /* A random card is assigned to the deck */
        suit_temp = rand() % 4 + 1;

        switch(face_temp){

            case 1: deck[i].face = "Ace";

                break;

            case 2: deck[i].face = "Deuce";

                break;

            case 3: deck[i].face = "Three";

                break;

            case 4: deck[i].face = "Four";

                break;

            case 5: deck[i].face = "Five";

                break;

            case 6: deck[i].face = "Six";

                break;

            case 7: deck[i].face = "Seven";

                break;

            case 8: deck[i].face = "Eight";

                break;

            case 9: deck[i].face = "Nine";

                break;

            case 10: deck[i].face = "Ten";

                break;

            case 11: deck[i].face = "Jack";

                break;

            case 12: deck[i].face = "Queen";

                break;

            case 13: deck[i].face = "King";

        }

        switch(suit_temp){

            case 1: deck[i].suit = "Hearts";

                break;
                        
            case 2: deck[i].suit = "Diamonds";

                break;
                        
            case 3: deck[i].suit = "Clubs";

                break;
                        
            case 4: deck[i].suit = "Spades";

        }

        while(is_same_card(i,deck) != 0){ /* If the chosen card is already in the deck, another card is chosen */

            face_temp = rand() % 13 + 1;
            suit_temp = rand() % 4 + 1;

            switch(face_temp){

                case 1: deck[i].face = "Ace";

                    break;

                case 2: deck[i].face = "Deuce";

                    break;

                case 3: deck[i].face = "Three";

                    break;

                case 4: deck[i].face = "Four";

                    break;

                case 5: deck[i].face = "Five";

                    break;

                case 6: deck[i].face = "Six";

                    break;

                case 7: deck[i].face = "Seven";

                    break;

                case 8: deck[i].face = "Eight";

                    break;

                case 9: deck[i].face = "Nine";

                    break;

                case 10: deck[i].face = "Ten";

                    break;

                case 11: deck[i].face = "Jack";

                    break;

                case 12: deck[i].face = "Queen";

                    break;

                case 13: deck[i].face = "King";

            }

            switch(suit_temp){

                case 1: deck[i].suit = "Hearts";

                    break;
                                
                case 2: deck[i].suit = "Diamonds";

                    break;
                                
                case 3: deck[i].suit = "Clubs";

                    break;
                                
                case 4: deck[i].suit = "Spades";

            }

        }

    }

    for(i=0; i<26; i++){ /* Aligning the output */

        if( strcmp(deck[i].suit, "Diamonds") == 0 ){

            printf("%5s of %s\t%7s of %s\n", deck[i].face, deck[i].suit, deck[i+26].face, deck[i+26].suit);

        }else{

            printf("%5s of %s\t%15s of %s\n", deck[i].face, deck[i].suit, deck[i+26].face, deck[i+26].suit);

        }

    }

}

void menu(){

    int choice, street, avenue, hospital_number, i;

    char cities[6] = {'A','B','C','D','E','F'};
    char locations[4][3] = {{'A','B','C'},{'A','C','D'},{'B','F'},{'C','E','F'}};

    printf("._________________________________.\n");
    printf("|                                 |\n");
    printf("|              MENU               |\n");
    printf("|                                 |\n");
    printf("|   1) Stay Home Problem          |\n");
    printf("|   2) COVID-19 Health Coverage   |\n");
    printf("|   3) Mix the Deck               |\n");
    printf("|   4) Exit                       |\n");
    printf("|                                 |\n");
    printf("|_________________________________|\n\n");
    printf("What is your choice?\n");
    scanf("%d", &choice);

    switch(choice){

        case 1: printf("Enter the street number: ");
                scanf("%d", &street);

                printf("street:%d\n", street);

                printf("Enter the avenue number: ");
                scanf("%d", &avenue);

                printf("avenue:%d\n", avenue);

                printf("Number of optimal paths to take back home: %d\n\n", numPathsHome(street,avenue));

                menu();

            break;

        case 2: printf("Enter the maximum number of hospitals that can be constructed:");
                scanf("%d", &hospital_number);

                if( canOfferCovidCoverage(cities,locations,hospital_number,results) == 0 ){

                    printf("No, some cities are not covered.\n\n");

                }else if( canOfferCovidCoverage(cities,locations,hospital_number,results) == 1 ){

                    printf("\nYes, can offer health to all!\n\n");

                    for(i=0; i<hospital_number; i++){

                        printf("Hospital - %d\n", i+1);
                        printf("Hospital locations:%s\n",results[i].citiesServed);

                    }

                } 

                menu();

            break;

        case 3: mix_deck(deck); 

                menu();

            break;

        case 4: 

            break;

        default: printf("\n\nInvalid choice\n\n");

                 menu();

    }

}

void main(){

    menu();

}