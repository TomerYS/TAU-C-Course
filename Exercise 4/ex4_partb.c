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
    Point q = { .x = -20, .y = 40 };
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
    print_point(t->p);
    printf(", ");
    print_point(t->q);
    printf(" and ");
    print_point(t->r);
}

double perimeter(Triangle const* t)
{
    double pri = 0;
    pri += distance(t->p, t->q);
    pri += distance(t->q, t->r);
    pri += distance(t->r, t->p);
    return pri;
}

double area(Triangle const* t)
{
    double semi = perimeter(t)/2;
    double a = distance(t->p, t->q);
    double b = distance(t->q, t->r);
    double c = distance(t->r, t->p);
    double area = sqrt(semi * (semi - a) * (semi - b) * (semi - c));
    return area;
}

bool is_right(Triangle const* t)
{
    double a, b, c;
    a = distance(t->p, t->q) * distance(t->p, t->q);
    b = distance(t->q, t->r) * distance(t->q, t->r);
    c = distance(t->r, t->p) * distance(t->r, t->p);
    if (a + b == c) return true;
    if (b + c == a) return true;
    if (c + a == b) return true;
    return false;
}