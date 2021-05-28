#include <iostream>
#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <windows.h>

//using namespace std;


void setCircle(int x, int y, int color, int rayon);
void setBoard(int topleftx, int toplefty, int bottomrightx,int bottomrighty, int color);

int main()
{
    int topleftx = 25;
    int toplefty = 25;
    int bottomrightx = 475;
    int bottomrighty = 675;

    int offsetPastille = 80;


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
    for(int y=0; y<=10; y++)
    {
        for(int x=0; x<=3; x++)
        {
            setCircle(topleftx+45+(offsetPastille*x), toplefty+45+(offsetPastille*y), LIGHTMAGENTA, 20);
        }
    }

    //Garde la fenetre ouverte
    system("pause");


    return 0;
}

void setBoard(int topleftx, int toplefty, int bottomrightx,int bottomrighty, int color)
{
    // affiche un rectangle rouge
    setcolor(color);
    rectangle(topleftx, toplefty, bottomrightx, bottomrighty);
    setfillstyle(SOLID_FILL, color);
    floodfill( topleftx+1, toplefty+1, color );
}

void setCircle (int x, int y, int color, int rayon)
{
    setcolor(color);
    circle(x, y, rayon);
    setfillstyle(SOLID_FILL, color);
    //rempli la forme
    floodfill( x, y, color );

}
