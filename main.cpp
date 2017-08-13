#ifdef __cplusplus
#include <cstdlib>
#else
#include <stdlib.h>
#endif





#include"variables.h"
#include"SDL_system.h"

#include"console.h"
#include <ctype.h>
#include"flash_time.h"
#include"debug.h"

#include"flash_class.h"
#include"flash_windows.h"


int main(int argc, char **argv)
{
    DisplayMonitorResolution();

    init_SDL();

    int i,j;

    int size_x=screen->w-10,size_y=screen->h-10;

    t=clock();


         // thread = SDL_CreateThread( com_thread, NULL );
    sprintf(buffer_console[0],"Ingrese Numero de Puerto COM:");

    while (gameRunning)
    {

        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                gameRunning = false;
            }
            if( event.type ==SDL_KEYDOWN)
            {



               // console ();
               if(muestras_in<100){
                console ();
               }

                if (event.key.keysym.sym == SDLK_UP)
                {
                    buffer_c=strlen(buffer_comand);
                    strcpy(buffer_console[buffer_reglon],buffer_comand);

                }
                       if (event.key.keysym.sym == SDLK_SPACE)
                {
                  update_features();
                init_features();

                }


            }
            else if( event.type == SDL_VIDEORESIZE)
            {

                SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

                WINDOW_SIZE_W=event.resize.w;
                WINDOW_SIZE_H=event.resize.h;
                 screen = SDL_SetVideoMode( WINDOW_SIZE_W, WINDOW_SIZE_H, 0,
                                           SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE); //Redefinir screen para salvar RAM
                                        resize_all();


            }
        }

        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
        get_time(); //Reloj de tiempo de ejecucion



    // draw_primitive(5,5,10,4,WINDOW_SIZE_W-10,WINDOW_SIZE_H-10,color_txt);



      //  draw_graphic();



       /// graphic_fft(WINDOW_SIZE_W*0.1,WINDOW_SIZE_H-WINDOW_SIZE_H*0.1,WINDOW_SIZE_W*0.8,WINDOW_SIZE_H*0.7,com_datos,fft_datos,fft_n_datos,1,flag_db);

        main_Screen();
      //  HUD_Create_Space();
     //   HUD_working();
     //   HUD_Waiting();
     //   HUD_Logo();
        SDL_Flip(screen);

    }


    clean_up();

    return 0;
}
