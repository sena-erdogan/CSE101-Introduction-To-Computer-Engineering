#include<stdio.h>
#include<string.h>

#define SIZE 500 /* The max size of a line in  */

struct point
{

    char name[3];

    double x;

    double y;

};

struct line
{

    char name[3];

    struct point start;

    struct point end;

};

struct point_polygon
{

    char name[102];

    struct point points[20];

};

struct line_polygon
{

    char name[102];

    struct line lines[20];

};

struct point all_points[100];

struct line all_lines[100];

struct point_polygon all_point_polygons[100];

struct line_polygon all_line_polygons[100];

void main(){

    char input[SIZE];
    char output_file[50];

    int object, action, i, j, x, y;

    FILE *filep;

    filep = fopen("commands.txt","r");

    fgets(input, SIZE, filep);

    while( strcmp(input, "data") != 1 ){

        input[0] = '\0';

        fgets(input, SIZE, filep);

    }

    printf("%s\n", input);

    input[0] = '\0';

    fscanf(filep, "%d", &object);

    for(i=0; i<object; i++){

        fgets(input, SIZE, filep);

    }

}