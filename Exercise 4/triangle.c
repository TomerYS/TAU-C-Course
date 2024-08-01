#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct point {
    double x, y;
} Point;

typedef struct triangle {
    Point p, q, r;
} Triangle;

void print_point(Point p);

double distance(Point p, Point q);

void print_triangle(Triangle const* t);

double perimeter(Triangle const* t);

double area(Triangle const* t);

bool is_right(Triangle const* t);


int main()
{
    Point p = { .x = 10, .y = 20 };
    Point q = { .x = -20, .y = 40};
    Point r = { .x = 5, .y = 5 };

    Triangle t = {
        .p = p,
        .r = r,
        .q = q
    }; 
    

    double per = perimeter(&t);
    double ar = area(&t);
    printf("The perimeter of a ");
    print_triangle(&t);
    printf(" is %g\n", per);

    printf("The area of a ");
    print_triangle(&t);
    printf(" is %g\n", ar);

    printf("The ");
    print_triangle(&t);
    if (is_right(&t))
    {
        printf(" is a right angle triangle\n");
    }
    else
        printf(" is not a right angle triangle\n");
    return 0;
}

void print_point(Point p)
{
    printf("(%g, %g)", p.x, p.y);
}

double distance(Point p, Point q)
{
    double dx = p.x - q.x;
    double dy = p.y - q.y;
    return sqrt(dx * dx + dy * dy);
}

void print_triangle(Triangle const* t)
{

    printf("triangle with corners ");
    printf(", ");
    printf(" and ");
}

double perimeter(Triangle const* t)
{


}

double area(Triangle const* t)
{

}

bool is_right(Triangle const* t)
{

}