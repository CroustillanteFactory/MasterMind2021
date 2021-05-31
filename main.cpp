#include <iostream>
#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <windows.h>

//using namespace std;


void setCircle(int x, int y, int color, int rayon);
void setBoard(int topleftx, int toplefty, int bottomrightx,int bottomrighty, int color);
void setIndicators (int x, int y, int color, int rayon);

int main()
{
    int topleftx = 25;
    int toplefty = 25;
    int bottomrightx = 475;
    int bottomrighty = 675;

    //Gere l'espace entre les pastilles pour les pions de couleurs en x et y
    int offsetPastilleX = 75;
    int offsetPastilleY = 56;

    //Gere l'espace entre les pastilles pour les indicateurs en x et y
    int offsetIndicatorX = 25;
    int offsetIndicatorY = 24;
    int offsetIndicatorSet = 56;

    // taille de la fenêtre
    int screenWidth=500;
    int screenHeight=700;
    // affiche la fenêtre avec le titre "MasterMind2021 - Leo Velloni"
    initwindow(screenWidth, screenHeight, "MasterMind2021 - Leo Velloni", 200, 100);


    //Affichage du plateau de jeu
    setBoard(topleftx, toplefty, bottomrightx, bottomrighty, LIGHTBLUE);


    //Affiche un cercle rose
    /*
    setCircle(topleftx+45, 150, LIGHTMAGENTA);
    setCircle(topleftx+125, 150, LIGHTMAGENTA);
    setCircle(topleftx+205, 150, LIGHTMAGENTA);
    setCircle(topleftx+285, 150, LIGHTMAGENTA);

    setCircle(topleftx+45, 230, LIGHTMAGENTA);
    setCircle(topleftx+45, 310, LIGHTMAGENTA);
    setCircle(topleftx+45, 390, LIGHTMAGENTA);
    setCircle(topleftx+45, 470, LIGHTMAGENTA);
    setCircle(topleftx+45, 550, LIGHTMAGENTA);
    setCircle(topleftx+45, 630, LIGHTMAGENTA);
    setCircle(topleftx+45, 710, LIGHTMAGENTA);
    setCircle(topleftx+45, 790, LIGHTMAGENTA);
    */

    //Affiche les pastilles marquant les emplacements des pions de couleurs
    for(int y=0; y<=10; y++)
    {
        for(int x=0; x<=3; x++)
        {
            setCircle(topleftx+45+(offsetPastilleX*x), toplefty+45+(offsetPastilleY*y), LIGHTMAGENTA, 22);
        }
    }

    //Affiche les pastilles pour les emplacements de indicateurs
    for(int i=0; i<=9; i++)
    {
        for(int y=0; y<=1; y++)
        {
            for(int x=0; x<=1; x++)
            {
                setCircle(topleftx+350+(offsetIndicatorX*x), toplefty+89+(offsetIndicatorY*y)+(i*offsetIndicatorSet), LIGHTGREEN, 8);
            }
        }
    }





    //Garde la fenetre ouverte
    system("pause");


    return 0;
}

//fonction du plateau de jeu
void setBoard(int topleftx, int toplefty, int bottomrightx,int bottomrighty, int color)
{
    setcolor(color);
    rectangle(topleftx, toplefty, bottomrightx, bottomrighty);
    setfillstyle(SOLID_FILL, color);
    floodfill( topleftx+1, toplefty+1, color );
}

//fonction des emplacement des pions de couleurs
void setCircle (int x, int y, int color, int rayon)
{
    setcolor(color);
    circle(x, y, rayon);
    setfillstyle(SOLID_FILL, color);
    //rempli la forme
    floodfill( x, y, color );

}

//fonction des emplacement des indicateurs
void setIndicators (int x, int y, int color, int rayon)
{
    setcolor(color);
    circle(x, y, rayon);
    setfillstyle(SOLID_FILL, color);
    //rempli la forme
    floodfill( x, y, color );

}

