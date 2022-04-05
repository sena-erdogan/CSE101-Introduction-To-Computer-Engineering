#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void puzzle();

void print_map(char puzzle[][21], int column, char word_list[10][20]);

void print_map(char puzzle[][21], int column, char word_list[10][20]){

    FILE *filep;
    filep = fopen("words.txt","rt");

    int rows[21]; 
    int i, j, direction, x, y, num=0, count;
    int row=20;
    char c = 'a';
    int word_order[10];
    int order, flag=0;
    char word[20];

    for(i=0;i<20;i++){ /* To print numbers above the puzzle */

        rows[i] = i + 1;

    }

    for(i=0;i<row;i++){ /* Fıllıng the puzzle with '.' */

        for(j=0;j<column;j++){

            puzzle[i][j] = '.';

        }

    }

    puzzle[0][0] = ' ';
    puzzle[1][0] = ' ';
    
    for(i=0; i<row; i++){ /* The first element of every row is the corresponding letter */

        puzzle[i][0] = c++;

    }

    srand(time(NULL));

    for(i=0; i<10; i++){ /* Taking random words from the file */

        order = rand() % 10;

        if( order == 0 ){

            getc(filep);

        }

        while(order != 0){

            while( getc(filep) != '\n' ){

            }

            order--;
                                
        }
                    
        fscanf(filep, "%[^\n]", word_list[i]); /* Storing the words in an array */

    }

    for(i=0;i<10;i++){ /* Fıllıng the remaining elements of the word array with '\0' indicating that the string is over */

        for(j=0;j<20;j++){

            if( word_list[i][j] < 'a' || word_list[i][j] > 'z' ){

                word_list[i][j] = '\0';

            }

        }

    }

    for(i=0; i<10; i++){ /* Placing the chosen words in the puzzle */

        flag = 0;
        num = 0;
        count = strlen( word_list[i] ) -1;
        j=0;

        direction = rand() % 8; /* A random direction is chosen */

        x = rand() % 20;
        y = rand() % 20;

        switch(direction){

            case 0: flag = 1;

                    while(flag != 0){

                        flag = 0;

                        x = rand() % 20 + 1;
                        y = rand() % 20 + 1;

                        while( y + count> 21 ){ /* If the word doesn't fit in the line, the starting point will be chosen again */

                            x = rand() % 20 + 1;
                            y = rand() % 20+1;
                            
                        }

                        for(j=y; j<y+count+2; j++){ /* If any of the letters overlap with a word that was already in the puzzle, the starting position will be chosen again */

                            if(puzzle[x][j] != '.')  flag++;

                        }

                    }

                    for(j=y; j<y+count+1; j++){ /* The word is placed in the puzzle */

                        puzzle[x][j] = word_list[i][num];
                        num++;

                    }

                break;

            case 1:  flag = 1;

                    while(flag != 0){

                        flag = 0;

                        x = rand() % 20 +1;
                        y = rand() % 20+1;

                        while( x + count > 21 ){

                            x = rand() % 20+1;
                            y = rand() % 20+1;
                            
                        }

                        for(j=x; j<x+count+2; j++){

                            if(puzzle[j][y] != '.')  flag++;

                        }

                    }

                    for(j=x; j<x+count+1; j++){

                        puzzle[j][y] = word_list[i][num];
                        num++;

                    }

                break;

            case 2:  flag = 1;

                    while(flag != 0){

                        flag = 0;

                        x = rand() % 20+1;
                        y = rand() % 20+1;

                        while( y - count < 0){

                            x = rand() % 20+1;
                            y = rand() % 20+1;
                            
                        }

                        for(j=y; j>y-count-2; j--){

                            if(puzzle[x][j] != '.')  flag++;

                        }

                    }

                    for(j=y; j>y-count-1; j--){

                        puzzle[x][j] = word_list[i][num];
                        num++;

                    }

                break;

            case 3:  flag = 1;

                    while(flag != 0){

                        flag = 0;

                        x = rand() % 20+1;
                        y = rand() % 20+1;

                        while( x - count < 0 ){

                            x = rand() % 20+1;
                            y = rand() % 20+1;
                            
                        }

                        for(j=x; j>x-count-2; j--){

                            if(puzzle[j][y] != '.')  flag++;

                        }

                    }

                    for(j=x; j>x-count-1; j--){

                        puzzle[j][y] = word_list[i][num];
                        num++;

                    }

                break;

            case 4:  flag = 1;

                    while(flag != 0){

                        count = strlen( word_list[i] ) -1;

                        flag = 0;

                        x = rand() % 20+1;
                        y = rand() % 20+1;

                        while( y + count> 21 || x + count> 21 ){

                            x = rand() % 20+1;
                            y = rand() % 20+1;
                        
                        }

                        while( count != -2 ){

                            if(puzzle[x][y] != '.'){
                                
                                flag++;

                            }
                            
                            x++;
                            y++;
                            count--;

                        }

                    }

                    count = strlen( word_list[i] ) -1;

                    while( count !=-1 ){

                            puzzle[x][y] = word_list[i][num];
                            
                            x++;
                            y++;
                            num++;{
                                
                                flag++;

                            }
                            count--;

                        }

                break;

            case 5:  flag = 1;

                    while(flag != 0){

                        count = strlen( word_list[i] ) -1;

                        flag = 0;

                        x = rand() % 20+1;
                        y = rand() % 20+1;

                        while( y - count < 0 || x - count < 0 ){

                            x = rand() % 20+1;
                            y = rand() % 20+1;
                        
                        }

                        while( count != -2 ){

                            if(puzzle[x][y] != '.'){
                                
                                flag++;

                            }    
                            
                            x--;
                            y--;
                            count--;

                        }

                    }

                    count = strlen( word_list[i] ) -1;

                    while( count !=-1 ){

                            puzzle[x][y] = word_list[i][num];
                            
                            x--;
                            y--;
                            num++;
                            count--;

                        }

                break;

            case 6:  flag = 1;

                    while(flag != 0){

                        count = strlen( word_list[i] ) -1;

                        flag = 0;

                        x = rand() % 20+1;
                        y = rand() % 20+1;

                        while( y + count > 21 || x - count < 0 ){

                            x = rand() % 20+1;
                            y = rand() % 20+1;
                        
                        }

                        while( count != -2 ){

                            if(puzzle[x][y] != '.'){
                                
                                flag++;

                            }    
                            
                            x--;
                            y++;
                            count--;

                        }

                    }

                    count = strlen( word_list[i] ) -1;

                    while( count != -1 ){

                            puzzle[x][y] = word_list[i][num];
                            
                            x--;
                            y++;
                            num++;
                            count--;

                        }

                break;

            case 7:  flag = 1;

                    while(flag != 0){

                        count = strlen( word_list[i] ) -1;

                        flag = 0;

                        x = rand() % 20+1;
                        y = rand() % 20+1;

                        while( y - count < 0 || x + count > 21 ){

                            x = rand() % 20+1;
                            y = rand() % 20+1;
                        
                        }

                        while( count != -2 ){

                            if(puzzle[x][y] != '.'){
                                
                                flag++;

                            }    
                            
                            x++;
                            y--;
                            count--;

                        }

                    }

                    count = strlen( word_list[i] ) -1 ;

                    while( count != -1 ){

                            puzzle[x][y] = word_list[i][num];
                            
                            x++;
                            y--;
                            num++;
                            count--;

                        }

        }

    }

    for(i=0;i<20;i++){ /* The points which has no letters will be replaced with a random letter */

        for(j=0;j<21;j++){

            if( puzzle[i][j] == '.' )  puzzle[i][j] = rand() % 26 + 97;

        }

    }

    for(i=0;i<10;i++){ /* Words are printed before the puzzle */

        printf("%s\n", word_list[i]);

    }

    printf("  ");

    for(i=0;i<10;i++){

        printf(" %d ", rows[i]);

    }

    for(i=10;i<20;i++){

        printf("%d ", rows[i]);

    }

    printf("\n");

    for(i=0;i<20;i++){

        for(j=0;j<21;j++){

            printf("%c  ", puzzle[i][j]);

        }

        printf("\n");

    }

    fclose(filep);

}

void puzzle(){

    char map[20][21];
    char input[20];
    char word[20];
    char words[10][20];
    char row;
    int column, score = 0, i, j;
    int flag_1 = 0, flag_2 = 0, flag_3 = 0, flag_4 = 0, flag_5 = 0, flag_6 = 0, flag_7 = 0, flag_8 = 0;
    int rows[21];
    char c = 'a';

    for(i=0;i<20;i++){

        rows[i] = i + 1;

    }

    map[0][0] = ' ';
    map[1][0] = ' ';
    
    for(i=0; i<row; i++){ 

        map[i][0] = c++;

    }

    print_map(map, 21, words);
    
    while( score != 10 ){

        printf("Please enter the coordinate and the word.\n");
        scanf("%c%d %s", &row, &column, word);

        if(word == "Exit"){

            printf("\n\nGoodbye\n\n");

        }else{

            row -= 65;

            for(i=0;i<strlen(word);i++){

                if( word[i] == map[row][column + i] ){

                    flag_1++;

                }else if( word[i] == map[row + i][column] ){

                    flag_2++;

                }else if( word[i] == map[row + i][column + i] ){

                    flag_3++;

                }else if( word[i] == map[row - i][column] ){

                    flag_4++;

                }else if( word[i] == map[row][column - i] ){

                    flag_5++;

                }else if( word[i] == map[row + i][column - i] ){

                    flag_6++;

                }else if( word[i] = map[row - i][column - i] ){

                    flag_7++;

                }else if( word[i] = map[row][column + i] ){

                    flag_8++;

                }

            }

            if( flag_1 == strlen(word) ){

                score++;

                for(i=0;i<strlen(word);i++){

                    map[row][column + i] += 32;

                }

            }else if( flag_2 == strlen(word) ){

                score++;

                for(i=0;i<strlen(word);i++){

                    map[row + i][column] += 32;

                }

            }else if( flag_3 == strlen(word) ){

                score++;

                for(i=0;i<strlen(word);i++){

                    map[row + i][column + i] += 32;

                }

            }else if( flag_4 == strlen(word) ){

                score++;

                for(i=0;i<strlen(word);i++){

                    map[row - i][column] += 32;

                }

            }else if( flag_5 == strlen(word) ){

                score++;

                for(i=0;i<strlen(word);i++){

                    map[row][column - i] += 32;

                }

            }else if( flag_6 == strlen(word) ){

                score++;

                for(i=0;i<strlen(word);i++){

                    map[row + i][column - i] += 32;

                }

            }else if( flag_7 == strlen(word) ){

                score++;

                for(i=0;i<strlen(word);i++){

                    map[row - i][column - i] += 32;

                }

            }else if( flag_8 == strlen(word) ){

                score++;

                for(i=0;i<strlen(word);i++){

                    map[row][column + i] += 32;
                }

            }

    
    printf("  ");

    for(i=0;i<10;i++){

        printf(" %d ", rows[i]);

    }

    for(i=10;i<20;i++){

        printf("%d ", rows[i]);

    }

    printf("\n");

    for(i=0;i<20;i++){

        for(j=0;j<21;j++){

            printf("%c  ", map[i][j]);

        }

        printf("\n");

        }

    }

    printf("\n\nCONGRATULATIONS\n\n");

}

}


void main(){

    puzzle();

}