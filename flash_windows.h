#ifndef FLASH_WINDOWS_H_INCLUDED
#define FLASH_WINDOWS_H_INCLUDED


#include <SDL/SDL.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include "variables.h"
void DisplayMonitorResolution();
void get_clipboard();
void set_clipboard(char *buffer);

void resize_all()
{

    FONT_SIZE= WINDOW_SIZE_W*28/1920+WINDOW_SIZE_W/300+1; //Size 1920=18; 1280=14; 800= 10;
    font = TTF_OpenFont( "GOTHIC.ttf", FONT_SIZE );
    if(font==NULL)puts("ERROR ABRIR FUENTE");

    FONT_SIZE_2= WINDOW_SIZE_W*20/1920+WINDOW_SIZE_W/300+1; //Size 1920=18; 1280=14; 800= 10;
    font_2 = TTF_OpenFont( "GOTHIC.ttf", FONT_SIZE_2 );
    if(font_2==NULL)puts("ERROR ABRIR FUENTE");


    FONT_SIZE_3= WINDOW_SIZE_W*18/1920+WINDOW_SIZE_W/300+1; //Size 1920=18; 1280=14; 800= 10;
    font_3 = TTF_OpenFont( "GOTHIC.ttf", FONT_SIZE_3 );
    if(font_3==NULL)puts("ERROR ABRIR FUENTE");

    FONT_SIZE_4= WINDOW_SIZE_W*12/1920+WINDOW_SIZE_W/300+1; //Size 1920=18; 1280=14; 800= 10;
    font_4 = TTF_OpenFont( "GOTHIC.ttf", FONT_SIZE_4 );
    if(font_4==NULL)puts("ERROR ABRIR FUENTE");
}







void DisplayMonitorResolution()
{
    SCREEN_W = GetSystemMetrics(SM_CXSCREEN);
    SCREEN_H = GetSystemMetrics(SM_CYSCREEN);

    //printf("Current Resolution is - Width: %d, Height: %d", nWidth, nHeight);
    // Current Resolution is - Width: 1920, Height: 1080
}
/*
void display_settings (){

   int numdisplays = SDL_GetNumVideoDisplays();
   std::vector< window_data > screens( numdisplays );
    for( int i = 0 ; i < numdisplays ; ++i )
    {
   SDL_GetDisplayBounds( i, &( screens[ i ].bounds ) );
   std::cout << "window # " << i << " : x = " << screens[ i ].bounds.x
        << " y = " << screens[ i ].bounds.y
        << " w = " << screens[ i ].bounds.w
        << " h = " << screens[ i ].bounds.h << std::endl;

    }

}

*/
void get_clipboard()
{
    HANDLE clip;
    if (OpenClipboard(NULL))
        clip = GetClipboardData(CF_TEXT);
    printf("%s\n",clip);
    CloseClipboard();
}

void set_clipboard(char *buffer)
{

    HANDLE clip;//For the data to send to the clipboard

    char *ptrData = NULL;//pointer to allow char copying

    int nStrLen = strlen(buffer);//length of phrase

    clip = GlobalAlloc(GMEM_MOVEABLE | GMEM_DDESHARE, nStrLen + 1);//get handle to memory to hold phrase

    ptrData = (char*)GlobalLock(clip);//get pointer from handle

    memcpy(ptrData,buffer,nStrLen + 1);//copy over the phrase

    GlobalUnlock(clip);//free the handle

    OpenClipboard(NULL);//allow you to work with clipboard

    EmptyClipboard();//clear previous contents

    SetClipboardData(CF_TEXT,clip);//set our data

    CloseClipboard();//finished!!

}

#endif // FLASH_WINDOWS_H_INCLUDED
