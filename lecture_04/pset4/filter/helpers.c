#include "helpers.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Sub image parts to be used
typedef struct grid
{
    int size;
    RGBTRIPLE *pixels;
}
 grid;

// Function declarations
void print_pixel(RGBTRIPLE pixel);

// Grayscale 
int gray_avg(RGBTRIPLE pixel);
void paint_gray(RGBTRIPLE *pixel);

// Blur
grid get_grid(int height, int width, RGBTRIPLE image[height][width], int r, int c, int n);
int *grid_r(grid g);
int *grid_g(grid g);
int *grid_b(grid g);
int cgrid_avg(int *cgrid, int size);
RGBTRIPLE grid_avg(grid g);


// -------------------- Grayscale filter --------------------
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

// Compute average of one pixel's RGB to turn into grayscale
int gray_avg(RGBTRIPLE pixel)
{
    // Extract all 3 colors and return rounded mean
    float r, g, b;
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
    int gray = gray_avg(*pixel);

    pixel->rgbtRed = gray;
    pixel->rgbtGreen = gray;
    pixel->rgbtBlue = gray;
}


// -------------------- Reflection filter --------------------
// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    
    int sym;    // symetric pixel location
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


// -------------------- Blur filter --------------------
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create temporal copy from which to take values
    RGBTRIPLE(*tmp)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    if (tmp == NULL)
    {
        printf("Not enough memory");
        return;
    }
    
    // Copy all the image to temporal
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tmp[i][j] = image[i][j];
        }
    }

    // Iterate over all pixels and calculate their mean
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            grid g = get_grid(height, width, tmp, i, j, 3);
            image[i][j] = grid_avg(g);
            free(g.pixels);
        }
    }
    free(tmp);
    return;
}

// Create a (n * n) grid of pixels in pixel (r, c) (row, column)
grid get_grid(int height, int width, RGBTRIPLE image[height][width], int r, int c, int n)
{ 
    // Grid boundaries, first & last, column & row
    int r0, r1, c0, c1;
    r0 = r - (n - 1)/2;
    r1 = r + (n - 1)/2;
    c0 = c - (n - 1)/2;
    c1 = c + (n - 1)/2;

    // Check for border collision
    r0 = r0 < 0 ? 0 : r0;
    r1 = r1 >= height ? height - 1: r1;
    c0 = c0 < 0 ? 0 : c0;
    c1 = c1 >= width ? width - 1 : c1;
    
    // Grid width & height
    int w = c1 - c0 + 1;
    int h = r1 - r0 + 1;

    RGBTRIPLE *pixels = malloc(w*h*(sizeof(RGBTRIPLE)));
    if (pixels == NULL)
    {
        printf("Not enough memory\n");
    }
    int ind = 0;
    for (int i = r0; i <= r1; i++)
    {
        for (int j = c0; j <= c1; j++)
        {
            pixels[ind] = image[i][j];
            ind++;
        }
    }
    grid g;
    g.pixels = pixels;
    g.size = w * h;
    return g;
}

// Obtain red color values from grid
int *grid_r(grid g)
{
    int *red = malloc(g.size * sizeof(int));
    if (red == NULL)
    {
        printf("Not enough space");
    }
    for (int i = 0; i < g.size; i++)
    {
        red[i] = g.pixels[i].rgbtRed;
    }
    return red;
}

// Obtain green color values from grid
int *grid_g(grid g)
{
    int *green = malloc(g.size * sizeof(int));
    if (green == NULL)
    {
        printf("Not enough space");
    }
    for (int i = 0; i < g.size; i++)
    {
        green[i] = g.pixels[i].rgbtGreen;
    }
    return green;
}

// Obtain blue color values from grid
int *grid_b(grid g)
{
    int *blue = malloc(g.size * sizeof(int));
    if (blue == NULL)
    {
        printf("Not enough space");
    }
    for (int i = 0; i < g.size; i++)
    {
        blue[i] = g.pixels[i].rgbtBlue;
    }
    return blue;
}

// Obtain mean value of a colorgrid's (cgrid) color (array) of size n
int cgrid_avg(int *cgrid, int size)
{
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += cgrid[i];
    }
    free(cgrid);
    float avg = sum / size;
    return round(avg);
}

// Calculate grid's mean for all colors and return pixel
RGBTRIPLE grid_avg(grid g)
{
    RGBTRIPLE p;
    p.rgbtRed = cgrid_avg(grid_r(g), g.size);
    p.rgbtGreen = cgrid_avg(grid_g(g), g.size);
    p.rgbtBlue = cgrid_avg(grid_b(g), g.size);
    return p;
}


// -------------------- Edge detection filter --------------------
// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}


// -------------------- Common functions --------------------
// Print a pixel's colors
void print_pixel(RGBTRIPLE pixel)
{
    int r, g, b;
    r = pixel.rgbtRed;
    g = pixel.rgbtGreen;
    b = pixel.rgbtBlue;

    printf("Pixel(R: %i, G: %i, B: %i)\n", r, g, b);
}








