#include <stdio.h>

void draw(int);

int main(void)
{
    int height = 8;

    draw(height);
}

void draw(int h)
{
    if (h == 1)
    {
        printf("#\n");
        return;
    }
    else {
        draw(h - 1);
        for (int i = 0; i < h; i++)
        {
            printf("#");
        }
        printf("\n");
    }
    return;
}

// I am so proud of myself!