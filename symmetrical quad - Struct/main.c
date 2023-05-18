#include <stdio.h>
#include <stdlib.h>

struct quad
{
    int top_left_x;  //Dx
    int top_left_y;  //Dy
    int bottom_right_x; //Bx
    int bottom_right_y; //By
};

void symmetry (struct quad *origin , struct quad *symmetrical)
{
     symmetrical->bottom_right_x = -origin->top_left_x; //B'x = Dx
     symmetrical->bottom_right_y = -origin->top_left_y; //B'y = Dy
     symmetrical->top_left_x = -origin->bottom_right_x; //D'x = Bx
     symmetrical->top_left_y = -origin->bottom_right_y; //D'Y = By
};

int main()
{
    struct quad origin,symmetrical;

    printf("Enter the original cordinates (top left x,y and bottom right x,y ) :");
    scanf("%d%d%d%d",&origin.top_left_x,&origin.top_left_y,&origin.bottom_right_x,&origin.bottom_right_y);

    symmetry(&origin,&symmetrical);

    printf("\nSymmetrical Top Left x,y : %d %d\n",symmetrical.top_left_x,symmetrical.top_left_y);
    printf("\nSymmetrical Bottom Right x,y : %d %d\n",symmetrical.bottom_right_x,symmetrical.bottom_right_y);

    return 0;
}
