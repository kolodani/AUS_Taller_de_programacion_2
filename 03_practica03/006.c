/*
    Practica 03
    Ejercicio 06
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    unsigned char R, G, B;
} RGB;

typedef struct
{
    int ancho, alto;
    RGB **pixel;
} ImagenRGB;

typedef unsigned char Gris;

typedef struct
{
    int ancho, alto;
    Gris **pixel;
} ImagenGris;

ImagenRGB *creaImagenRGB(int ancho, int alto);                       // crea y retorna una nueva imagenRGB
ImagenGris *creaImagenGris(int ancho, int alto);                     // crea y retorna una nueva imagenGris
void setPixelRGB(ImagenRGB *im, int fila, int columna, RGB *pix);    // asigna el pixel de la fila y columna dada
void setPixelGris(ImagenGris *im, int fila, int columna, Gris *pix); // asigna el pixel de la fila y columna dada
RGB *getPixelRGB(ImagenRGB *im, int fila, int columna);              // retorna el pixel de la fila y columna dada
Gris *getPixelGris(ImagenGris *im, int fila, int columna);           // retorna el pixel de la fila y columna dada
void destruyeImagenRGB(ImagenRGB *im);                               // libera la memoria asociadacon la imagen im
void destruyeImagenGris(ImagenGris *im);                             // libera la memoria asociadacon la imagen im
Gris RGBtoGris(RGB *pix);                                            // convierte un pixel RGB a uno Gris usando la formula: Gris = 0.299*R + 0.587*G + 0.114*B
ImagenGris *Transforma(ImagenRGB *im);                               // transforma la imagenRGB en una nueva ImagenGris

int main()
{

    return 0;
}

ImagenRGB *creaImagenRGB(int ancho, int alto)
{
    ImagenRGB *imagen = (ImagenRGB *)malloc(sizeof(ImagenRGB));
    imagen->ancho = ancho;
    imagen->alto = alto;
    imagen->pixel = (RGB **)malloc(sizeof(RGB *) * alto);
    for (int i = 0; i < alto; i++)
        imagen->pixel[i] = (RGB *)malloc(sizeof(RGB) * ancho);
    return imagen;
}

ImagenGris *creaImagenGris(int ancho, int alto)
{
    ImagenGris *imagen = (ImagenGris *)malloc(sizeof(ImagenGris));
    imagen->ancho = ancho;
    imagen->alto = alto;
    imagen->pixel = (Gris **)malloc(sizeof(Gris *) * alto);
    for (int i = 0; i < alto; i++)
        imagen->pixel[i] = (Gris *)malloc(sizeof(Gris) * ancho);
    return imagen;
}

void setPixelRGB(ImagenRGB *im, int fila, int columna, RGB *pix)
{
    im->pixel[fila][columna] = *pix;
}

void setPixelGris(ImagenGris *im, int fila, int columna, Gris *pix)
{
    im->pixel[fila][columna] = *pix;
}

RGB *getPixelRGB(ImagenRGB *im, int fila, int columna)
{
    return &im->pixel[fila][columna];
}

Gris *getPixelGris(ImagenGris *im, int fila, int columna)
{
    return &im->pixel[fila][columna];
}

void destruyeImagenRGB(ImagenRGB *im)
{
    for (int i = 0; i < im->alto; i++)
        free(im->pixel[i]);
    free(im->pixel);
    free(im);
}

void destruyeImagenGris(ImagenGris *im)
{
    for (int i = 0; i < im->alto; i++)
        free(im->pixel[i]);
    free(im->pixel);
    free(im);
}

Gris RGBtoGris(RGB *pix)
{
    return 0.299 * pix->R + 0.587 * pix->G + 0.114 * pix->B;
}

ImagenGris *Transforma(ImagenRGB *im)
{
    ImagenGris *imagen = creaImagenGris(im->ancho, im->alto);
    for (int i = 0; i < im->alto; i++)
        for (int j = 0; j < im->ancho; j++)
            imagen->pixel[i][j] = RGBtoGris(&im->pixel[i][j]);
    return imagen;
}
