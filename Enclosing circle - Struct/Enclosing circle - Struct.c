#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct circle
{
    int x;
    int y;
    float radius;
};

void enclosing(struct circle *a, struct circle *b, struct circle *c)
{
    c->radius = 0.0;

    float distance = sqrt(pow((a->x - b->x), 2) + pow((a->y - b->y), 2));

    if (distance + a->radius <= b->radius)
    {
        c->x = b->x;
        c->y = b->y;
        c->radius = b->radius;
    }
    else if (distance + b->radius <= a->radius)
    {
        c->x = a->x;
        c->y = a->y;
        c->radius = a->radius;
    }
}

int main()
{
    struct circle a = {10, 8, 4.0}, b = {15, 10, 13.0}, c;

    enclosing(&a, &b, &c);

    printf("Enclosing Circle : %d  %d  %.2f", c.x, c.y, c.radius);

    return 0;
}
