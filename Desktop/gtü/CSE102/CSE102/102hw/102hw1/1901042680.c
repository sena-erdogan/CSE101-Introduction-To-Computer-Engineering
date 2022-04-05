#include<stdio.h>
#include<math.h> /* This library is added to take the squareroot of the discriminant. */

 
void find_root(){

    double a, b, c, discriminant; /* All the variables are doubles since they all will be used in some calculations and the result may be a double number. */
    printf("Please enter the first coefficient: \n");
    scanf("%lf", &a); /* The main equation is ax^2 + b*x + c  */
    printf("Please enter the second coefficient: \n");
    scanf("%lf", &b);
    printf("Please enter the third coefficient: \n");
    scanf("%lf", &c);

    discriminant = b * b - 4 * a * c;

    if(discriminant > 0){ 

        double root1, root2;
        root1 = (- b + sqrt(discriminant) ) / 2 * a; /* If the discriminant is positive, the it's squareroot will be also positive. */
        root2 = (- b - sqrt(discriminant) ) / 2 * a; /* Since one of the equations involves +(square root of discriminant) and the other involves -(square root of discriminant) , we will have two separate values for the rroots of the equation. */
        
        if(root1 < root2){ /* The roots should be printed in descending order. Since the variable root1 will be printed first, if root2 is greater than root1, then we will swap the two variables so that the greater value will be printed frist anyway. */

            double temp;

            temp = root1;
            root1 = root2;
            root2 = temp;

        }

        printf("Your equation %.0lf x^2 + (%.0lf) x + (%.0lf) has real roots {%.2lf,%.2lf}.\n", a, b, c, root1, root2); /* The a, b, and c variables are double numbers. They are printed with %.0lf, so when they are printed, the decimal points won't be printed and they will be printed as integers */

    }
    else if(discriminant == 0){ /* If the discriminant is equal to 0, then square root of the discriminant will also be 0, then the equation will be (- b ) / 2 * a. So there will only be one root. */

        double only_root = ( - b ) / 2 * a ;
        printf("Your equation %.0lf x^2 + (%.0lf) x + (%.0lf) has one real root {%.2lf}. \n", a, b, c, only_root);

    }
    else{ /* If the discriminant is negative then the square root of it won't be real number. */
        printf("Your equation %.0lf x^2 + (%.0lf) x + (%.0lf) does not have any real roots. \n", a, b, c);
    }

}

void find_newtonian_root(){

    int a, b, c;
    double initial, root;

    printf("Please enter the first coefficient:\n"); /* The main equation is ax^2 + b*x + c  */
    scanf("%d", &a);
    printf("Please enter the second coefficient:\n");
    scanf("%d", &b);
    printf("Please enter the third coefficient:\n");
    scanf("%d", &c);
    printf("Please enter the initial:\n");
    scanf("%lf", &initial);


    int discriminant = b * b - 4 * a * c; /* We will find the roots of the  function first, to get the difference between the root closer to the initial value and the current x value. */

    if(discriminant > 0){ 

        double root1, root2;
        root1 = (- b + sqrt(discriminant) ) / 2 * a;
        root2 = (- b - sqrt(discriminant) ) / 2 * a;

        if( fabs(initial - root1) > fabs(initial - root2)){ /* Determining which root is closer to the initial value. fabs() is used since the variables are double. */

            root = root2; /* If root2 is closer to the initial value, then the root value will be root2 */

        }else{

            root = root1;/* If root1 is closer to the initial value or they both have the same distance from the initial value, then the root value will be root1 */

        }
        
    }
    else if(discriminant == 0){  /* If the discriminant is  0 then there will be only one root */

        root = ( - b ) / 2 * a ;
        
    }

    

    printf("Your equation is %d x ^ 2 + (%d) x + (%d) and iterations are\n\n", a, b, c);
    printf("Step\tx\tf(x)\tDifference\n\n");

    
  
    double x; /* x value represents the x values we will find during the application of the method. (x0 being the initial value.) */


    x = initial - ((a * initial * initial + b * initial + c) / (2 * a * initial + b)); /* Newtonian's Method is applied again to print the results to the user. */
  
    printf("x1\t%.4lf\t%.4lf\t%.4lf\n", x, (a * x * x + b * x + c), x - root); 

    x = x - ((a * x * x + b * x + c) / (2 * a * x + b)); /* After printing every step, x is assigned to the next x value to keep the method going and also to prevent having too many variables. */
  
    printf("x2\t%.4lf\t%.5lf\t%.4lf\n", x, (a * x * x + b * x + c), x - root);

    x = x - ((a * x * x + b * x + c) / (2 * a * x + b));
  
    printf("x3\t%.4lf\t%.5lf\t%.4lf\n", x, (a * x * x + b * x + c), x - root);

    x = x - ((a * x * x + b * x + c) / (2 * a * x + b));
  
    printf("x4\t%.4lf\t%.5lf\t%.4lf\n", x, (a * x * x + b * x + c), x - root);

    x = x - ((a * x * x + b * x + c) / (2 * a * x + b));
  
    printf("x5\t%.4lf\t%.5lf\t%.4lf\n", x, (a * x * x + b * x + c), x - root);

}  



int find_multiple_closest(int first, int second){ 

    int remainder = first % second; /* To see if the first value is divisible by the second value. */

    if(remainder == 0){ /* If the remainder is 0, then the closest number to the first number that is multiple of the second number is the first number itself. */

        return first;

    }
    else{

        if(remainder >= second - remainder){ /* This condition means that the closest number to the first number that is multiple of the second number is greater than the first number. */

            return ( first - remainder + second );

        }
        else if(remainder < second - remainder){ /* This condition means that the closest number to the first number that is multiple of the second number is less than the first number. */

            return ( first - remainder );

        }

    }

}

int main(){

    find_root();
    find_newtonian_root();

    int first_integer , second_integer;

    printf("Enter the first integer: ");
    scanf("%d", &first_integer);
    printf("Enter the second integer: ");
    scanf("%d", &second_integer);

    if(find_multiple_closest(first_integer , second_integer) == first_integer ){
        printf("Closest number to %d that is multiple of %d is itself.\n", first_integer, second_integer);

    }
    else{ 

        printf("Closest number to %d that is multiple of %d is %d.\n", first_integer, second_integer, find_multiple_closest(first_integer, second_integer));

    }
    
    return 0;    


}