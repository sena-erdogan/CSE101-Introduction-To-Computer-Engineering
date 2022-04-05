#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void menu();

void genre_list(char genre[2000][20]); /* PART 0 */

void platform_list(char platform[2000][20]); /* PART 1 */

void games_through_years(char name[2000][100], float data[2000][7]); /* PART 2 */

void info_of_game(char name[2000][100], char genre[2000][20], char platform[2000][20], float data[2000][7]); /* PART 3 */

void average_user_score(float data[2000][7]); /* PART 4 */

void geo_info_of_game(float data[2000][7], char name[2000][100]); /* PART 5 */

void freq_of_genre(char genre[2000][20], float data[2000][7]); /* PART 6 */

void freq_of_platform(char platform[2000][20], float data[2000][7]); /* PART 7 */

void genre_list(char genre[2000][20]){

    int i;

    printf("\n\n\n");

    for(i=0; i<2000; i++){  /* Genre array has all the different genre names so that array will be printed */

        if(genre[i][0] != '\0'){

            printf("%s\n", genre[i]);

        }

    }

    printf("\n\n\n");

}

void platform_list(char platform[2000][20]){

    int i;

    printf("\n\n\n");

    for(i=0; i<2000; i++){ /* Platform array has all the different platform names so that array will be printed */

        if(platform[i][0] != '\0'){

            printf("%s\n", platform[i]);

        }

    }

    printf("\n\n\n");

}

void games_through_years(char name[2000][100], float data[2000][7]){

    int year, until_or_since, i, j;

    printf("Enter a year:\n");
    scanf("%d", &year);

    printf("Until (0) or Since (1) %d: ", year);
    scanf("%d", &until_or_since);

    printf("\n\n\n");

    switch(until_or_since){

        case 0: if( year <=  1985 ){ /* The oldest game came out in 1985 so if the user wants to print the games until a year that is before 1985, the program will ask for another year to work with */

                    printf("TRY AGAIN.\n\n\n");

                    games_through_years(name,data);

                }else{ 

                    for(i=0; i<2000; i++){ 

                        if( data[i][2] < year ){ /* If any game from the 2000 we have came out in the year interval wanted, that game will be printed */

                            printf("%s\n", name[i]);

                        }

                    }

                }

            break;

        case 1: if( year >= 2005 ){ /* The newest game came out in 2005 so if the user wants to print the games since a year that is after 2005, the program will ask for another year to work with */

                    printf("TRY AGAIN.\n\n\n");

                    games_through_years(name,data);

                }else{

                    for(i=0; i<2000; i++){

                        if( data[i][2] > year ){

                            printf("%s\n", name[i]);

                        }

                    }

                }

    }

    printf("\n\n\n");

}

void info_of_game(char name[2000][100], char genre[2000][20], char platform[2000][20], float data[2000][7]){

    char game[100];
    int flag = 0, count = 0, i, temp_platform, temp_genre;

    printf("Please enter the name of the game:\n");
    scanf("%s", game);

    for(i=0; i<2000; i++){

        if( strcmp(name[i], game) == 0 )    count++;

        if( count == 1 ){

            flag++;
            temp_genre = (int)data[i][0]; /* The genre and platform information of the game is assigned to a float value to get the right index from the genre and platform arrays */
            temp_platform = (int)data[i][1];

            printf("Name:\t\t\t%s\n", game);
            printf("Genre:\t\t\t%s\n", genre[temp_genre]);
            printf("Platform:\t\t%s\n", platform[temp_platform]);
            printf("Year:\t\t\t%.0lf\n", data[i][2]);
            printf("Sales In NA:\t\t%lf\n", data[i][3]);
            printf("Sales In EU:\t\t%lf\n", data[i][4]);
            
            if( data[i][5] == 0 ){ /* strtod function will return 0 if the global sales data is a string */

                printf("Total Sales:\t\tNot Available\n");

            }else{

                printf("Total Sales:\t\t%lf\n", data[i][5]);

            }

            printf("User Score:\t\t%lf\n\n\n", data[i][6]);

            count++;


        }

    }

    if(flag == 0){

        printf("TRY AGAIN.\n\n\n");
        info_of_game(name, genre, platform, data);

    }

}

void average_user_score(float data[2000][7]){

    float sum = 0;

    for(int i=0; i<2000; i++){

        sum += data[i][6];

    }

    printf("\n\nAverage: %lf\n\n\n", sum/2000.0); /* 2000 is denoted with 2000.0 so there's no errors with the dividing */

}

void geo_info_of_game(float data[2000][7], char name[2000][100]){

    char game[100];
    int count = 0, i;

    printf("Please enter the name of the game:\n");
    scanf("%s", game);

    for(i=0; i<2000; i++){

        if( strcmp(name[i], game) == 0 )    count++;

        if( count == 1 ){ /* If the game name is found for the first time in the name array, that value will be used */

            if( data[i][3] > data[i][4] ){

                printf("\n\nThis game was more popular in North America.\n\n");

            }else if( data[i][3] < data[i][4] ){

                printf("\n\nThis game was more popular in Europe.\n\n");

            }else{

                printf("\n\nThis game was equally popular in North America and Europe.\n\n");

            }

            count++;

        }

    }

    if(count == 0){

        printf("TRY AGAIN.\n\n\n");
        geo_info_of_game(data, name);

    }

}

void freq_of_genre(char genre[2000][20], float data[2000][7]){

    int i, j, count;

    printf("\n\n\n");

    for(i=0; i<2000; i++){

        count = 0;

        for(j=0; j<2000; j++){

            if( data[j][0] == (float)i ){

                count++;

            }

        }

        if( genre[i][0] != '\0' ){

            if( strlen(genre[i]) <= 7 ){

                printf("%s\t\t%d\n", genre[i], count);

            }else{

                printf("%s\t%d\n", genre[i], count);

            }

        }

    }

    printf("\n\n\n");

}

void freq_of_platform(char platform[2000][20], float data[2000][7]){

    int i, j, count;

    printf("\n\n\n");

    for(i=0; i<2000; i++){

        count = 0;

        for(j=0; j<2000; j++){

            if( data[j][1] == (float)i ){

                count++;

            }

        }

        if( platform[i][0] != '\0' ){

            printf("%s\t%d\n", platform[i], count);

        }

    }

    printf("\n\n\n");

}

void menu(){

    int choice, i, j, count, element = 0, element_temp, flag;
    char games[2000][200];
    char name[2000][100];
    char genre[2000][20];
    char platform[2000][20];
    char temp[20];
    float data[2000][7];
    char *ptr;

    FILE *filep;
    filep = fopen("Video_Games.txt", "rt");

    if( filep == NULL ){

        printf("File failed to open.\n\n");

    }else{

        while( !feof(filep) ){

            fgetc(filep);

            while( fgetc(filep) != '\n' ){ /* The first row is skipped since it just gives information of what category is where */

                fgetc(filep);

            }

            for(i=0; i<2000; i++){

                fscanf(filep, "%[^\n]", games[i]); /* Every row is scanned in the array */
                fgetc(filep);

            }

        }

        fclose(filep);

    }

    for(i=0; i<2000; i++){

        j = 0;

        while( games[i][j] != ',' ){ /* In every row, the characters until the first comma is the name of the game */

            name[i][j] = games[i][j];
            j++;

        }

    }

    genre[0][0] = '\0'; /* The genre array is set to NULL */

    for(i=0; i<2000; i++){

        count = 0;
        flag = 0;
        element_temp = 0;

        for(j=0; j<strlen(games[i]); j++){

            if(games[i][j] == ','){ /* Every character in between the first and second commas is scanned in a temporary array */

                count++;

            }

            if(count == 2){

                temp[element_temp] = games[i][j];
                element_temp++;

            }

            if(games[i][j] == ','){

                count++;

            }

        }

        temp[element_temp] = '\0';

        for(j=0; j<2000; j++){

            if( strcmp(genre[j], temp) == 0 )    flag++;

        }

        if( flag == 0 ){ /* The string iinn temporary array will only be transferred to the genre array if it's not already an element of the genre array to prevent overlapping */

            strcpy(genre[element], temp);
            element++;

        }

        memset(temp, 0, 20); /* Temporary array is set to NULL */

    }

    for(i=0; i<2000; i++){

        count = 0;
        flag = 0;
        element_temp = 0;

        for(j=0; j<strlen(games[i]); j++){

            if(games[i][j] == ','){

                count++;

            }

            if(count == 4){

                temp[element_temp] = games[i][j];
                element_temp++;

            }

            if(games[i][j] == ','){

                count++;

            }

        }

        for(j=0; j<2000; j++){

            if( strcmp(platform[j], temp) == 0 )    flag++;

        }

        if( flag == 0 ){

            strcpy(platform[element], temp);
            element++;

        }

        memset(temp, 0, 20);

    }

    for(i=0; i<2000; i++){

        count = 0;
        element_temp = 0;

        for(j=0; j<200; j++){

            if(games[i][j] == ','){

                count++;

            }

            if(count == 2){

                temp[element_temp] = games[i][j];
                element_temp++;

            }

            if(games[i][j] == ','){

                count++;

            }

        }

        temp[element_temp] = '\0';

        for(j=0; j<2000; j++){

            if( strcmp(genre[j], temp) == 0 ){ 

                data[i][0] = (float)j; /* The genre information of the game will have whichever index that genre has in the genre array */

            }

        }

        memset(temp, 0, 20);

    }

    for(i=0; i<2000; i++){

        count = 0;
        element_temp = 0;

        for(j=0; j<strlen(games[i]); j++){

            if(games[i][j] == ','){

                count++;

            }

            if(count == 4){

                temp[element_temp] = games[i][j];
                element_temp++;

            }

            if(games[i][j] == ','){

                count++;

            }

        }

        for(j=0; j<2000; j++){

            if( strcmp(platform[j], temp) == 0 ){ 

                data[i][1] = (float)j; /* The platform information of the game will have whichever index that platform has in the platform array */

            }

        }

        memset(temp, 0, 20);

    }

    for(i=0; i<2000; i++){

        count = 0;
        element_temp = 0;

        for(j=0; j<strlen(games[i]); j++){

            if(games[i][j] == ','){

                count++;

            }

            if(count == 6){

                temp[element_temp] = games[i][j];
                element_temp++;

            }

            if(games[i][j] == ','){

                count++;

            }

        }

        data[i][2] = strtod(temp, &ptr); /* The release year is transferred to the data array */
        memset(temp, 0, 20);

    }

    for(i=0; i<2000; i++){

        count = 0;
        element_temp = 0;

        for(j=0; j<strlen(games[i]); j++){

            if(games[i][j] == ','){

                count++;

            }

            if(count == 8){

                temp[element_temp] = games[i][j];
                element_temp++;

            }

            if(games[i][j] == ','){

                count++;

            }

        }

        data[i][3] = strtod(temp, &ptr); /* The NA sales is transferred to the data array */
        memset(temp, 0, 20);

    }

    for(i=0; i<2000; i++){

        count = 0;
        element_temp = 0;

        for(j=0; j<strlen(games[i]); j++){

            if(games[i][j] == ','){

                count++;

            }

            if(count == 10){

                temp[element_temp] = games[i][j];
                element_temp++;

            }

            if(games[i][j] == ','){

                count++;

            }

        }

        data[i][4] = strtod(temp, &ptr); /* The EU sales is transferred to the data array */
        memset(temp, 0, 20);

    }

    for(i=0; i<2000; i++){

        count = 0;
        element_temp = 0;

        for(j=0; j<strlen(games[i]); j++){

            if(games[i][j] == ','){

                count++;

            }

            if(count == 12){

                temp[element_temp] = games[i][j];
                element_temp++;

            }

            if(games[i][j] == ','){

                count++;

            }

        }

        data[i][5] = strtod(temp, &ptr); /* The global sales is transferred to the data array. If the global sales value is "not available", that element will be 0 */
        memset(temp, 0, 20);

    }

    for(i=0; i<2000; i++){

        count = 0;
        element_temp = 0;

        for(j=0; j<strlen(games[i]); j++){

            if(games[i][j] == ','){

                count++;

            }

            if(count == 14){

                temp[element_temp] = games[i][j];
                element_temp++;

            }

            if(games[i][j] == ','){

                count++;

            }

        }

        data[i][6] = strtod(temp, &ptr); /* The user score is transferred to the data array */
        memset(temp, 0, 20);

    }

    printf("0: List of the Genres\n1: List of the Platforms\n2: List of the Games Through the Years\n3: All Informations of a Single Game\n4: Average of the User Scores\n5: Georographical Information of a Single Game\n6: Frequence of the Genres\n7: Frequence of the Platforms\n8: Exit\n\n");

    printf("Please select an operation: ");
    scanf("%d", &choice);

    switch(choice){

        case 0: genre_list(genre);
                menu();

            break;

        case 1: platform_list(platform);
                menu();

            break;

        case 2: games_through_years(name, data);
                menu();

            break;

        case 3: info_of_game(name, genre, platform, data);
                menu();

            break;

        case 4: average_user_score(data);
                menu();

            break;

        case 5: geo_info_of_game(data, name);
                menu();

            break;

        case 6: freq_of_genre(genre, data);
                menu();

            break;

        case 7: freq_of_platform(platform, data);
                menu();

            break;

        case 8: printf("\n\n\nGoodbye!\n\n\n");

            break;

        default: printf("\n\n\nTRY AGAIN.\n\n\n");
                 menu();

    }

}

void main(){

    menu();

}