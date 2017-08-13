#ifndef DEBUG_H_INCLUDED
#define DEBUG_H_INCLUDED

#include"variables.h"


void HUD_debug();
void debug_interface();


void init_test()
{


    int i;
    for(i=0; i<1000; i++)
        test_datos[i]=rand()%100;


}

void HUD_debug()
{
    int i;
    // char buffer_c[20];

    int size_w,size_h;
    int coord_x,coord_y;
    SDL_Surface *buffer;

    if(flag_debug)
    {
        debug_interface();

        for(i=0; i<15; i++)
        {
            // sprintf(debug_console[i],"%0.2lf", 1852.6112);  //Maximo
            buffer=TTF_RenderText_Solid( font_3, debug_console[i], color_txt);
            TTF_SizeText(font_4,debug_console[i],&size_w,&size_h);
            coord_x=WINDOW_SIZE_W/2;
            coord_y=WINDOW_SIZE_H/2+size_h*i;
            apply_surface( coord_x, coord_y, buffer, screen );
            SDL_FreeSurface( buffer );
        }

        /*

                sprintf(buffer_c,"%0.2lf", 1852.6112);  //Maximo
                buffer=TTF_RenderText_Solid( font_4, buffer_c, color_text);
                TTF_SizeText(font_4,buffer_c,&size_w,&size_h);
                coord_x=size_x+ WINDOW_SIZE_W*0.025+size_wm*0.1;//size_w*2;
                coord_y=WINDOW_SIZE_H*0.1+2*i*size_h*2+2*size_hm+size_hm/2+size_h; //-WINDOW_SIZE_H*0.02;
                apply_surface( coord_x, coord_y, buffer, screen );
                SDL_FreeSurface( buffer );
        */


    }
}
void debug_interface()
{

    int i=0;
    // sprintf(debug_console[0],"input:'%s'",buffer_comand);
    sprintf(debug_console[0],"signal_inputs: %d", signal_inputs);  //Maximo

  //  sprintf(debug_console[1],"  signal_features[0][0]: %lf",   signal_features[0][0]);
//    sprintf(debug_console[2],"0 %lf ",com_datos[0][p_com_datos]);
  //  sprintf(debug_console[3],"1 %lf",com_datos[1][p_com_datos]);
   // sprintf(debug_console[4],"2 %lf",com_datos[2][p_com_datos]);
//    sprintf(debug_console[5],"3 %lf",com_datos[3][p_com_datos]);

    /*
      sprintf(debug_console[2],"param2:'%s'",input_params[1]);
      sprintf(debug_console[3],"param3:'%s'",input_params[2]);
      sprintf(debug_console[4],"param4:'%s'",input_params[3]);
      sprintf(debug_console[5],"param5:'%s'",input_params[4]);
      sprintf(debug_console[6],"param6:'%s'",input_params[5]);
      sprintf(debug_console[8],"param7:'%d'",buffer_reglon);
      sprintf(debug_console[9],"param8:'%d'",buffer_c);
       sprintf(debug_console[10],"param10:'%d'",SCREEN_W);
      sprintf(debug_console[11],"param11:'%d'",SCREEN_H);

    sprintf(debug_console[34],"%d,%d",mouse_pos_x,mouse_pos_y);
    */
    sprintf(debug_console[35],"%.2d:%.2d:%.2d",minutos,segundos,milis);

    if(debug_reglon>=36)debug_reglon=0;

}




#endif // DEBUG_H_INCLUDED
