#include <iostream>
#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <windows.h>
#include <math.h>


//using namespace std;
int initPast = 0;

int tab [11][4];
//store X/Y position in separate array2D.. maybe we will find better later :X
int tabPastilleX[11][4];
int tabPastilleY[11][4];

void init();

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

    // taille de la fen�tre
    int screenWidth=500;
    int screenHeight=700;
    // affiche la fen�tre avec le titre "MasterMind2021 - Leo Velloni"
    initwindow(screenWidth, screenHeight, "MasterMind2021 - Leo Velloni", 200, 100);


    //Affichage du plateau de jeu
    setBoard(topleftx, toplefty, bottomrightx, bottomrighty, LIGHTBLUE);


    init();
    while(1)
    {



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
        if(initPast != 1)
        {
            //Affiche les pastilles marquant les emplacements des pions de couleurs
            for(int y=0; y<=10; y++)
            {
                //Affiche les pastilles marquant les emplacements des pions de couleurs
                for(int y=0; y<=10; y++)
                {
                    for(int x=0; x<=3; x++)
                    {
                        setCircle(topleftx+45+(offsetPastilleX*x), toplefty+45+(offsetPastilleY*y), tab[y][x], 22);
                        //store Pastille Position in 2 seperate array
                        tabPastilleX[y][x] = topleftx+45+(offsetPastilleX*x);
                        tabPastilleY[y][x] = toplefty+45+(offsetPastilleY*y);
                        printf("x0: %d yo: %d\n", tabPastilleX[y][x], tabPastilleY[y][x]);
                    }
                    //setCircle(topleftx+45+(offsetPastilleX*x), toplefty+45+(offsetPastilleY*y), tab[y][x], 22);
                }
                initPast = 1;
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

        if(ismouseclick(WM_LBUTTONDOWN))
        {
            int x0, y0;
            getmouseclick(WM_LBUTTONDOWN, x0,y0);

            float a = sqrt(2);
            for(int y = 0; y < 11; y++)
            {
                for(int x = 0; x < 4; x++)
                {
                    if(sqrt(pow(x0-tabPastilleX[y][x],2) + pow((y0-tabPastilleY[y][x]),2)) < 22)
                    {
                        printf ("true y: %d x: %d", tabPastilleX[y][x], tabPastilleY[y][x]);
                        setCircle(tabPastilleX[y][x],tabPastilleY[y][x],RED,22);
                        break;
                    }
                }

            }

        }


    }
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

//couleurs pastilles
void init()
{
    int x, y;
    for(x=0; x<11; x++)
    {
        for(y=0; y<4; y++)
        {
            tab[x][y]=LIGHTMAGENTA;
        }
        //tab[0][0] = RED;
    }
}
