#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

#define size 500
#define N 8

void generate_hofstadters_sequence(int *arr, int n);

int find_max(int arr[], int index, int max_value);

int sum_array(int arr[]);

double std_array(int arr[], double *mean, int n, int index);

void install_pipes(int visited[N][N], int x, int y, int orientation, int counter);

char* remove_duplicates(char* str);

void menu();

void generate_hofstadters_sequence(int *arr, int n){

    if( n >= 1 ){

        generate_hofstadters_sequence(&arr[0], n - 1);

        arr[n - 1] =  arr[((n - 3) - arr[(n - 2)])] + arr[((n - 1) - arr[n - 3])];


    }

}

int find_max(int arr[], int index, int max_value){

    if( index < size - 1 ){

        if( arr[index] > max_value ){ /* If the array's element is greater than the max value, that element will be assigned to the max value */

            max_value = arr[index];

        }

        find_max(arr, index + 1, max_value);

    }else{

        return max_value; /* Max value is returned when the program reaches the end of the array */

    }

}

int sum_array(int arr[]){

    int* ptr;

    ptr = arr;

    if( *ptr != 0 ){

        return *ptr + sum_array(ptr + 1); /* Pointer will keep increasing until it's 0 */

    }
}

double std_array(int arr[], double *mean, int n, int index){

    double result;

    int* ptr = arr;
    ptr = arr;
    
    if( arr[index] != 0 ){

        if( arr[size - 1] == 0 ){

            *mean += std_array(arr, mean, n + 1, index + 1);

        }

        if( arr[size - 1] == 1 ){

            result += pow( 2, *mean - arr[index] ) + std_array(arr, mean, n, index + 1);

        }

    }

    arr[ size - 1 ] = 1;

    result = sqrt( result / n );

    return result;

}

void install_pipes(int visited[N][N], int x, int y, int orientation, int counter){

    int direction;

    srand(time(0));

    direction = rand() % 7 + 1;

    if( visited[x][y] == 0 && counter != 10){
        
        switch( direction ){

            case 1: x += 1;
                    y += 2;

                    visited[x][y] = 1;

                    printf("O%d ", direction);

                    install_pipes(visited, x, y, orientation + 1, counter);

                break;

            case 2: x -= 2;
                    y += 1;

                    visited[x][y] = 1;

                    printf("O%d ", direction);

                    install_pipes(visited, x, y, orientation + 1, counter);

                break;

            case 3: x -= 1;
                    y -= 2;

                    visited[x][y] = 1;

                    printf("O%d ", direction);

                    install_pipes(visited, x, y, orientation + 1, counter);

                break;

            case 4: x += 2;
                    y -= 1;

                    visited[x][y] = 1;

                    printf("O%d ", direction);

                    install_pipes(visited, x, y, orientation + 1, counter);

                break;

            case 5: x += 2;
                    y += 1;

                    visited[x][y] = 1;

                    printf("O%d ", direction);

                    install_pipes(visited, x, y, orientation + 1, counter);

                break;

            case 6: x -= 1;
                    y += 2;

                    visited[x][y] = 1;

                    printf("O%d ", direction);

                    install_pipes(visited, x, y, orientation + 1, counter);

                break;

            case 7: x -= 2;
                    y -= 1;

                    visited[x][y] = 1;

                    printf("O%d ", direction);

                    install_pipes(visited, x, y, orientation + 1, counter);

                break;

            case 8: x += 1;
                    y -= 2;

                    visited[x][y] = 1;

                    printf("O%d ", direction);

                    install_pipes(visited, x, y, orientation + 1, counter);

                break;

        }

    }

}

char* remove_duplicates(char* str){

    int i = 1;

    if( str[0] != '\0' ){ 

        if( str[1] == str[0] ){ 

            while( str[i] != '\0' ){ /* Shifting */

                str[i] = str[i+1]; 

                i++;

            }

            remove_duplicates(&str[0]); /* If the two letters are the same we will check if the same letter is also the letter after shifting */ 

        }

        remove_duplicates(&str[1]); /* The following letter is checked */

    }

    return str;

}

void menu(){

    int menu_choice, hofstadter_choice, hofst_number;
    int hofstadter[size] = {0};

    hofstadter[0] = 1;
    hofstadter[1] = 1; 

    int* hofst;
    hofst = hofstadter;
    char string[size];
    char* str;
    str = string;

    int field[N][N] = {0}; /* Filed is filled with 0's */
    field[0][0] = 1;

    printf("\n\nWelcome to Homework 8, please choose one of the parts to continue\n\n");
    printf("------------------------\n\n");
    printf("1) Execute Part 1\n\n2) Execute Part 2\n\n3) Execute Part 3\n\n4) Exit\n\n\n");
    scanf("%d", &menu_choice);

    switch(menu_choice){

        case 1: printf("Please make your choice:\n\n");
                printf("-------------------\n\n");
                printf("1) Fill Array\n\n2) Find Biggest Number\n\n3) Calculate Sum\n\n4) Calculate Standard Deviation\n\n5) Exit\n\n");
                scanf("%d", &hofstadter_choice);

                switch(hofstadter_choice){

                    case 1: printf("Enter an integer number: ");
                            scanf("%d", &hofst_number);

                            generate_hofstadters_sequence(&hofst[0], hofst_number);

                            for(int i=0; i<size; i++){

                                printf("%d ", hofst[i]);

                            }

                            for(int i=0; i<size; i++){

                                hofstadter[i] = 0;

                            }

                            hofstadter[0] = 1;
                            hofstadter[1] = 1; 

                            menu();

                        break;

                    case 2: printf("%d\n\n", find_max(hofst, 0, 0));

                            menu();

                        break;

                    case 3: printf("%d\n\n", sum_array(hofst));

                            menu();

                        break;

                    case 4: printf("%lf\n\n", std_array(hofst, 0, 0, 0));

                            menu();

                        break;

                    case 5:  

                            menu();

                }
                

            break;

        case 2: install_pipes(field, 0, 0, 0, 0);
                menu();

            break;

        case 3: printf("Please enter the duplicated array: ");
                getchar();
                fgets(string, size, stdin);
                printf("%s\n\n", remove_duplicates(str));

                menu();

            break;

        case 4:

            break;

        default: printf("\n\n\nTRY AGAIN.\n\n\n");
                 menu();

    }

}

void main(){

    menu();

}