#include <stdio.h>
#include <math.h>

#include "helpers.h"

// Function declarations
void print_pixel(RGBTRIPLE pixel);

// grayscale 
int avg(RGBTRIPLE pixel);
void paint_gray(RGBTRIPLE *pixel);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate over all pixels and turn them gray
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            paint_gray(&image[i][j]);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    
    int sym;    // symetric pixel number
    RGBTRIPLE tmp;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            sym = width - j - 1;
            tmp = image[i][sym];
            image[i][sym] = image[i][j];
            image[i][j] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}


// Compute average of one pixel's RGB to turn into grayscale
int avg(RGBTRIPLE pixel)
{
    // Extract all 3 colors and return rounded mean
    int r, g, b;
    r = pixel.rgbtRed;
    g = pixel.rgbtGreen;
    b = pixel.rgbtBlue;

    float val = (r + g + b) / 3;
    return round(val);
}

// Convert pixel to grayscale
void paint_gray(RGBTRIPLE *pixel)
{
    // Compute gray color magnitude and apply to RGB
    int gray = avg(*pixel);

    //(*pixel).rgbtBlue = gray;
    //(*pixel).rgbtGreen = gray;
    //(*pixel).rgbtBlue = gray;

    pixel->rgbtRed = gray;
    pixel->rgbtGreen = gray;
    pixel->rgbtBlue = gray;
}

// Print a pixel's colors
void print_pixel(RGBTRIPLE pixel)
{
    int r, g, b;
    r = pixel.rgbtBlue;
    g = pixel.rgbtGreen;
    b = pixel.rgbtBlue;

    printf("Pixel(R: %i, G: %i, B: %i)\n", r, g, b);
}
