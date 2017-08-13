#ifndef SDL_SYSTEM_H_INCLUDED
#define SDL_SYSTEM_H_INCLUDED


#include <string>
//#include "SDL/SDL.h"
//#include "SDL/SDL_image.h"
//#include "SDL/SDL_ttf.h"


SDL_Surface *load_image( std::string filename );

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL );

bool init_SDL ();

void clean_up();

void clean_up()
{

    TTF_CloseFont( font );
    TTF_CloseFont( font_2 );
    TTF_CloseFont( font_3 );
    TTF_CloseFont( font_4 );

    //Quit SDL_ttf
    TTF_Quit();

    //Stop the thread
    SDL_KillThread( thread );

    SDL_Quit();

}
bool init_SDL ()
{




    SDL_Init( SDL_INIT_VIDEO );


    // display_settings ();

    /*
    printf("Checking mode 640x480@16bpp.\n");
    bpp=SDL_VideoModeOK(640, 480, 16, SDL_HWSURFACE);

    if(!bpp){
      printf("Mode not available.\n");
      exit(-1);
    }

    printf("SDL Recommends 640x480@%dbpp.\n", bpp);
    screen=SDL_SetVideoMode(640, 480, bpp, SDL_HWSURFACE);
    */

    WINDOW_SIZE_W=SCREEN_W;
    WINDOW_SIZE_H=SCREEN_H;
    screen = SDL_SetVideoMode( SCREEN_W-200, SCREEN_H-200, 0,
                               SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);


    /*
    SDL_SWSURFACE	Create the video surface in system memory
    SDL_HWSURFACE	Create the video surface in video memory
    SDL_ASYNCBLIT	Enables the use of asynchronous updates of the display surface. This will usually slow down blitting on single CPU machines, but may provide a speed increase on SMP systems.
    SDL_ANYFORMAT	Normally, if a video surface of the requested bits-per-pixel (bpp) is not available, SDL will emulate one with a shadow surface. Passing SDL_ANYFORMAT prevents this and causes SDL to use the video surface, regardless of its pixel depth.
    SDL_HWPALETTE	Give SDL exclusive palette access. Without this flag you may not always get the the colors you request with SDL_SetColors or SDL_SetPalette.
    SDL_DOUBLEBUF	Enable hardware double buffering; only valid with SDL_HWSURFACE. Calling SDL_Flip will flip the buffers and update the screen. All drawing will take place on the surface that is not displayed at the moment. If double buffering could not be enabled then SDL_Flip will just perform a SDL_UpdateRect on the entire screen.
    SDL_FULLSCREEN	SDL will attempt to use a fullscreen mode. If a hardware resolution change is not possible (for whatever reason), the next higher resolution will be used and the display window centered on a black background.
    SDL_OPENGL	Create an OpenGL rendering context. You should have previously set OpenGL video attributes with SDL_GL_SetAttribute.
    SDL_OPENGLBLIT	Create an OpenGL rendering context, like above, but allow normal blitting operations. The screen (2D) surface may have an alpha channel, and SDL_UpdateRects must be used for updating changes to the screen surface. NOTE: This option is kept for compatibility only, and is not recommended for new code.
    SDL_RESIZABLE	Create a resizable window. When the window is resized by the user a SDL_VIDEORESIZE event is generated and SDL_SetVideoMode can be called again with the new size.
    SDL_NOFRAME	If possible, SDL_NOFRAME causes SDL to create a window with no title bar or frame decoration. Fullscreen modes automatically have this flag set.
    */

    SDL_WM_SetCaption( WINDOW_TITLE, 0 );


    TTF_Init();

    font = TTF_OpenFont( "GOTHIC.ttf", FONT_SIZE );
    if(font==NULL)puts("ERROR ABRIR FUENTE");

    font_2 = TTF_OpenFont( "GOTHIC.ttf", FONT_SIZE_2 );
    if(font_2==NULL)puts("ERROR ABRIR FUENTE 2");

    font_3 = TTF_OpenFont( "GOTHIC.ttf", FONT_SIZE_3 );
    if(font_3==NULL)puts("ERROR ABRIR FUENTE 3");

    font_4 = TTF_OpenFont( "GOTHIC.ttf", FONT_SIZE_4 );
    if(font_4==NULL)puts("ERROR ABRIR FUENTE 4");
}
/*
SDL_Surface *load_image( std::string filename )
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized surface
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old surface
        SDL_FreeSurface( loadedImage );

        //If the surface was optimized
        if( optimizedImage != NULL )
        {
            //Color key surface
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );
        }
    }

    //Return the optimized surface
    return optimizedImage;
}
*/
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}

#endif // SDL_SYSTEM_H_INCLUDED
