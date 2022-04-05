#include<stdio.h> /* To take values from the user and printing some messages to the screen, to basically talk to the user, stdio.h library is added. */
#include<math.h> /* To take the squareroot of some values, math.h is added. */

int draw_triangle(int side1, int side2, int side3){ /* This function decides whether a triangle can be drawn or not using the triangle inequality. */

    if( (side1 + side2) > side3 && (side1 + side3) > side2 && (side3 + side2) > side1 ){ /* The triangle equality states that a triangle's side's length
                                                                                            can't be greater than the sum of the other two sides' lengths. */

        return 1; /* If the triangle inequality is satisfied, this function wil return 1, meaning that the triangle can be drawn. */

    }else{

        return 0; /* If the triangle inequality is not satisfied, the triangle can't be drawn and to let the user know that, the function will return 0. */

    }

}

void type_triangle(int side1, int side2, int side3){ /* This function will determine the type of the function. */

    if( side1 == side2 && side2 == side3 ){ /* If all three sides of the triangle have the same length, then that triangle is an equilateral triangle. */

        printf("It is an Equilateral Triangle.\n");

    }else if(side1 == side2 && side2 != side3 || side1 == side3 && side3 != side2 || side2 == side3 && side3 != side1 ){ /* If any two sides of the triangle has the same length, 
                                                                                                                            different than the third side, that triangle is an isosceles triangle. */

        printf("It is an Isosceles Triangle.\n");

    }else if(side1 != side2 && side1 != side3 && side2 != side3 ){ /* If all three sides of the triangle have different lengths, then that triangle is a scalene triangle. */

        printf("It is a Scalene Triangle.\n");

    }

}

int perimeter_triangle(int side1, int side2, int side3){ /* This function returns the perimeter of the triangle given. */

    return ( side1 + side2 + side3 ); /* The function returns the sum of all three sides' lengths. */

}

double area_triangle(int side1, int side2, int side3){ /* This function returns the area of the triangle given, calculating it with the formula given. */

    double p = ((side1 + side2 + side3) / 2.0); /* This formula gives the area of the triangle. The side values are all integers and we need to divide that value by 2 to find the area, 
                                                which is a double number. When C operates with two integers, there may be some mistakes when that value is converted to a double number.
                                                To prevent that, at least one of the operands should be double. So 2 is written as 2.0. */

    return (sqrt( p * (p - side1) * (p - side2) * (p - side3) )); /* This formula gives the area of a triangle. */

}

int main(){

    int num1, num2, num3;

    printf("The length of first side:\n"); /* The side lengths of the triangle will be taken from the user. */
    scanf("%d", &num1);
    printf("The length of second side:\n");
    scanf("%d", &num2);
    printf("The length of third side:\n");
    scanf("%d", &num3);
    
    draw_triangle(num1, num2, num3); /* The functions will work in order. */

    if( draw_triangle(num1, num2, num3) == 1 ){ /* The draw_triangle function will return 1 if the triangle can be drawn. If the triangle can be drawn, 
                                                    the other functions will be called to find what type of a triangle the triangle is, the perimeter and the area of the triangle. */

        printf("\nAccording to the triangle inequality theorem, this triangle can be drawn.\n\n"); /* This line lets the user know that the triangle given can be drawn. */

        type_triangle(num1, num2, num3); /* The function that decides the type of the triangle is called. */

        printf("The perimeter of the triangle: %d\n", perimeter_triangle(num1, num2, num3)); /* Since the perimeter function will return the perimeter, 
                                                                                                this line directly prints that perimeter value. */

        printf("The area of the triangle: %lf\n", area_triangle(num1, num2, num3));/* The area value will also be returned when the function is called. */

        return 0;

    }else{

        printf("\nAccording to the triangle inequality theorem, this triangle cannot be drawn.\n\n"); /* If the draw_triangle function returns 0, that means the triangle cannot be drawn. */

        return 0; /* If the triangle cannot be drawn, the code will end here. and since the main function returns an integer value, returning 0 will make the whole process stop. */


    }

}