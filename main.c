//
//  main.c
//  Fraction Structure Lab 1
//
//  Created by Pallavi Kanoor on 2/19/17.
//  Copyright © 2017 Pallavi Kanoor. All rights reserved.
//

#include <stdio.h>
struct fraction //defining structure
{
    int numerator; //members of the structure
    int denominator;
};

struct fraction simplifyIt(struct fraction var1); //prototype of simplifyIt function
int gcf(int n1, int n2); //prototype of gcf calculating function
struct fraction calcIt(struct fraction var1, struct fraction var2); //prototype of calcIt function

int main(int argc, const char * argv[]) {
    int n1;
    int n2;
    struct fraction simplified_result; //variables being used for printing
    struct fraction sum_result;
    struct fraction fraction1;
    struct fraction fraction2;
    
    printf("Please enter the first fraction with a comma in between the two integers:\n"); //asking for user input
    scanf("%i,%i", &n1,&n2);
    fraction1.numerator = n1;
    fraction1.denominator = n2;
    
    printf("Please enter the second fraction with a comma in between the two integers:\n");
    scanf("%i,%i", &n1,&n2);
    fraction2.numerator = n1;
    fraction2.denominator = n2;
    
    sum_result = calcIt(fraction1, fraction2);
   
    simplified_result = simplifyIt(sum_result);
    printf("The sum of your fractions is: %i/%i\n", sum_result.numerator, sum_result.denominator);
    printf("The simplified sum of your fraction is: %i/%i\n", simplified_result.numerator, simplified_result.denominator);
    return 0;
}

struct fraction simplifyIt(struct fraction var1)
{
    int my_gcf; //where the gcf when found is stored
    struct fraction result; //what is returned
   
    my_gcf = gcf(var1.numerator,var1.denominator);
    result.numerator = var1.numerator/my_gcf;
    result.denominator = var1.denominator/my_gcf;
    
    return result;
}

int gcf(int n1, int n2)
{
    //make the first value "start"
    int start = n1;
    int result = -1;
    
    //check for lowest number
    if(start > n2)
    {
        start = n2;
    }
    //start at the lowest number and subtract 1 until both remainders = 0, that is the gcf
    for(int i = start; i>0; i--)
    {
        if((n1%i) == 0 && (n2%i == 0))
        {
            result = i;
            break; //stops the loop once the gcf is found
        }
    }
    
    return result;
}

struct fraction calcIt(struct fraction var1, struct fraction var2)
{
    struct fraction result;
    result.numerator = (var1.numerator*var2.denominator) + (var1.denominator*var2.numerator);
    result.denominator = (var1.denominator*var2.denominator);
    return result;
}

/* output
 Please enter the first fraction with a comma in between the two integers:
 1,8
 Please enter the second fraction with a comma in between the two integers:
 1,7
 The sum of your fractions is: 15/56
 The simplified sum of your fraction is: 15/56
 Program ended with exit code: 0
 
 Please enter the first fraction with a comma in between the two integers:
 9,6
 Please enter the second fraction with a comma in between the two integers:
 4,3
 The sum of your fractions is: 51/18
 The simplified sum of your fraction is: 17/6
 Program ended with exit code: 0
 
 Please enter the first fraction with a comma in between the two integers:
 2,45
 Please enter the second fraction with a comma in between the two integers:
 1,36
 The sum of your fractions is: 117/1620
 The simplified sum of your fraction is: 13/180
 Program ended with exit code: 0
 */
