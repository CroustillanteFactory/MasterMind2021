#include <iostream>
#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <windows.h>
#include <math.h>

//using namespace std;

int tab [11][4];

void init();

void setCircle(int x, int y, int color, int rayon);
void setBoard(int topleftx, int toplefty, int bottomrightx,int bottomrighty, int color);
void setIndicators (int x, int y, int color, int rayon);

int main()
{
    //Variables pour la position du plateau de jeu
    int topleftx = 25;
    int toplefty = 25;
    int bottomrightx = 475;
    int bottomrighty = 675;

    //Gere l'espace entre les pastilles pour les pions de couleurs en x et y
    int offsetPastilleX = 75;
    int offsetPastilleY = 56;

    //Variables pour les changements de couleurs
    int pastilleColor = 1;
    int colorNumber = 1;

    //Gere l'espace entre les pastilles pour les indicateurs en x et y
    int offsetIndicatorX = 25;
    int offsetIndicatorY = 24;
    int offsetIndicatorSet = 56;

    // taille de la fen?tre
    int screenWidth=500;
    int screenHeight=700;



    // affiche la fen?tre avec le titre "MasterMind2021 - Leo Velloni"
    initwindow(screenWidth, screenHeight, "MasterMind2021 - Leo Velloni", 200, 100);


    //Affichage du plateau de jeu
    setBoard(topleftx, toplefty, bottomrightx, bottomrighty, LIGHTBLUE);



    init();
    while(1)
    {
        //Affiche les pastilles marquant les emplacements des pions de couleurs
        for(int y=0; y<=10; y++)
        {
            for(int x=0; x<=3; x++)
            {
                setCircle(topleftx+45+(offsetPastilleX*x), toplefty+45+(offsetPastilleY*y), tab[y][x], 22);
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



        //Check si le clique gauche a ete presse
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            int x0, y0;
            getmouseclick(WM_LBUTTONDOWN, x0,y0);
            printf("x0: %d yo: %d\n", x0, y0);

            //Controle si le clique gauche est presse sur l'une des pastilles de couleur
            for(int y=0; y<=10; y++)
            {
                for(int x=0; x<=3; x++)
                {
                    if(sqrt(((topleftx+45+(offsetPastilleX*x))-x0)*((topleftx+45+(offsetPastilleX*x))-x0)+((toplefty+45+(offsetPastilleY*y))-y0)*((toplefty+45+(offsetPastilleY*y))-y0))<22)
                    {
                        printf("YES\n");
                        tab [y][x]= pastilleColor;
                        colorNumber++;
                    }
                    else
                    {
                        printf("NO\n");
                    }
                }
            }



            //Ordre des couleurs BLUE GREEN RED YELLOW
            if(colorNumber==1)
            {
                pastilleColor=1;
            }

            if(colorNumber==2)
            {
                pastilleColor=2;
            }

            if(colorNumber==3)
            {
                pastilleColor=4;
            }

            if(colorNumber==4)
            {
                pastilleColor=14;
                colorNumber=0;
            }
        }



        //Remet la valeur de la couleur de base avec un clique droit
        if(ismouseclick(WM_RBUTTONDOWN))
        {
            int x1, y1;
            getmouseclick(WM_RBUTTONDOWN, x1, y1);
            printf("Clique Droit\n");
            pastilleColor=1;
        }



    }
    return 0;
}

//Fonction du plateau de jeu
void setBoard(int topleftx, int toplefty, int bottomrightx,int bottomrighty, int color)
{
    setcolor(color);
    rectangle(topleftx, toplefty, bottomrightx, bottomrighty);
    setfillstyle(SOLID_FILL, color);
    floodfill( topleftx+1, toplefty+1, color );
}

//Fonction des emplacement des pions de couleurs
void setCircle (int x, int y, int color, int rayon)
{
    setcolor(color);
    circle(x, y, rayon);
    setfillstyle(SOLID_FILL, color);
    //rempli la forme
    floodfill( x, y, color );
}

//Fonction des emplacement des indicateurs
void setIndicators (int x, int y, int color, int rayon)
{
    setcolor(color);
    circle(x, y, rayon);
    setfillstyle(SOLID_FILL, color);
    //rempli la forme
    floodfill( x, y, color );
}

//Fonction pour la couleur des pastilles
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
