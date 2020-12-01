#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef uint8_t BYTE;
typedef uint32_t DWORD;
typedef int32_t LONG;
typedef uint16_t WORD;

typedef struct
{
    BYTE rgbtRed;
    BYTE rgbtGreen;
    BYTE rgbtBlue;
} __attribute__((__packed__))
RGBTRIPLE;

void blur(int height, int width, RGBTRIPLE image[height][width]);
void edges(int height, int width, RGBTRIPLE image[height][width]);

    int main(void)
{
    RGBTRIPLE sample[3][3] =  {
                                {  {10, 20, 30},    {40, 50, 60},    {70, 80, 90}     },
                                {  {110, 130, 140}, {120, 140, 150}, {130, 150, 160}  },
                                {  {200, 210, 220}, {220, 230, 240}, {240, 250, 255}  },
                            };
    RGBTRIPLE edge_test[3][3] = {

        {{0, 10, 25},
        {0, 10, 30},
        {40, 60, 80}},
        {{20, 30, 90},
        {30, 40, 100},
        {80, 70, 90}},
        {{20, 20, 40},
        {30, 10, 30},
        {50, 40, 10}}
    };

    edges(3, 3, edge_test);
}
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    typedef struct
    {
        WORD red;
        WORD green;
        WORD blue;
    } RGBLong;

    RGBTRIPLE (*imagecopy)[width] = calloc(height, sizeof(RGBTRIPLE) * width);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            imagecopy[i][j] = image[i][j];
        }
    }
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBLong blur = {0, 0, 0};

            int lower_bound_width = (j == 0) ? 0 : j - 1;
            int upper_bound_width = (j == width - 1) ? (width - 1) : j + 1;
            int lower_bound_height = (i == 0) ? 0 : i - 1;
            int upper_bound_height = (i == height - 1) ? (height - 1) : i + 1;
            int counter = (upper_bound_width - lower_bound_width + 1) * (upper_bound_height - lower_bound_height + 1);
            
            for (int k = lower_bound_height; k <= upper_bound_height; k++)
            {
                for (int l = lower_bound_width; l <= upper_bound_width; l++)
                {
                    blur.blue += (LONG)imagecopy[k][l].rgbtBlue;
                    blur.red += (LONG)imagecopy[k][l].rgbtRed;
                    blur.green += (LONG)imagecopy[k][l].rgbtGreen;
                }
            }
            image[i][j].rgbtBlue = (BYTE)round((float)blur.blue / (float)counter);
            image[i][j].rgbtRed = (BYTE)round((float)blur.red / (float)counter);
            image[i][j].rgbtGreen = (BYTE)round((float)blur.green / (float)counter);
        }
    }
    return;
}

void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Convolution matrices
    const char Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    const char Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    
    typedef struct 
    {
        LONG x;
        LONG y;
    }Point;
    
    typedef struct
    {
        Point red; // might be negative numbers
        Point green;
        Point blue;
    } RGBLong;

    // keep a copy of the original image and add black frames around it
    RGBTRIPLE(*imagecopy)[width + 2] = calloc(height + 2, sizeof(RGBTRIPLE) * (width + 2));

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // add the image to the middle, leave the frame black (i.e. zeros)
            imagecopy[i + 1][j + 1] = image[i][j];
        }
    }

    for (int i = 1; i <= height; i++)
    {
        
        for (int j = 1; j <= width; j++)
        {

            RGBLong blur = {0};

            for (int k = i - 1, conIndX = 0; k <= i + 1; k++, conIndX++)
            {
                for (int l = j - 1, conIndY = 0; l <= j + 1; l++, conIndY++)
                {
                    blur.blue.x += (LONG)imagecopy[k][l].rgbtBlue * Gx[conIndX][conIndY];
                    blur.red.x += (LONG)imagecopy[k][l].rgbtRed * Gx[conIndX][conIndY];
                    blur.green.x += (LONG)imagecopy[k][l].rgbtGreen * Gx[conIndX][conIndY];

                    blur.blue.y += (LONG)imagecopy[k][l].rgbtBlue * Gy[conIndX][conIndY];
                    blur.red.y += (LONG)imagecopy[k][l].rgbtRed * Gy[conIndX][conIndY];
                    blur.green.y += (LONG)imagecopy[k][l].rgbtGreen * Gy[conIndX][conIndY];
                }
            }
            LONG tempBlue = round(sqrt(pow(blur.blue.x, 2) + pow(blur.blue.y, 2)));
            tempBlue = (tempBlue > 255) ? 255 : tempBlue;
            LONG tempRed = round(sqrt(pow(blur.red.x, 2) + pow(blur.red.y, 2)));
            tempRed = (tempRed > 255) ? 255 : tempRed;
            LONG tempGreen = round(sqrt(pow(blur.green.x, 2) + pow(blur.green.y, 2)));
            tempGreen = (tempGreen > 255) ? 255 : tempGreen;
            image[i-1][j-1].rgbtBlue = (BYTE)tempBlue;
            image[i-1][j-1].rgbtRed = (BYTE)tempRed;
            image[i-1][j-1].rgbtGreen = (BYTE)tempGreen;
        }
    }
    return;
}