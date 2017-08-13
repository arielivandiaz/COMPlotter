#ifndef HUD_H_INCLUDED
#define HUD_H_INCLUDED

#include <SDL/SDL.h>
#include "SDL/SDL_gfxPrimitives.h"
#include<time.h>
#include"variables.h"
#include"flash_draw.h"
#include"debug.h"



//OLD
void main_Screen();
void HUD_console();
void HUD_working ();
void HUD_Logo ();
void HUD_Waiting();
void HUD_Create_Space();

///**************************************************************
//NEW
void HUD_static();
void HUD_grafic();
void HUD_buttons();
void HUD_dinamic();





void main_Screen()
{

    /* flag_working=0;
     if(flag_working && !flag_inactive)
         HUD_working();
     if(flag_waiting && flag_inactive)
         HUD_Waiting();
     if(flag_console  && !flag_inactive)
         HUD_console();
     if(flag_debug && !flag_inactive)
         HUD_debug();*/

    // HUD_working();

    //HUD_Waiting();
 if(muestras_in<100)
    HUD_console();
    HUD_static();
    HUD_grafic();
    HUD_buttons();
    HUD_dinamic();
   // HUD_debug();

}

void HUD_dinamic()
{

    SDL_Surface *buffer;
    char buffer_c[50]= {0};
    int size_w,size_h;
    int coord_x,coord_y;
    int size_wm,size_hm;
    unsigned int i;

    SDL_Color     color_text;






    for(i=0; i<signal_inputs; i++)

    {
        switch(i)
        {
        case 0:
            color_text=  color_red;
            break;
        case 1:
            color_text=  color_green;
            break;
        case 2:
            color_text=  color_blue;
            break;
        case 3:
            color_text=  color_yell;
            break;
        case 4:
            color_text=   color_pink;
            break;
        case 5:
            color_text=  color_cyan;
            break;

        }
        sprintf(buffer_c,"%d", i+1);
        buffer=TTF_RenderText_Solid( font_3, buffer_c, color_text);
        TTF_SizeText(font_3,buffer_c,&size_w,&size_h);
        coord_x=size_x+ WINDOW_SIZE_W*0.025;//size_w*2;
        coord_y=WINDOW_SIZE_H*0.08+2*i*size_h*2; //-WINDOW_SIZE_H*0.02;11

        apply_surface( coord_x, coord_y, buffer, screen );

        SDL_FreeSurface( buffer );

        draw_primitive(coord_x+size_w*2,coord_y+size_h/4,0,4,size_h/2,size_h/2,color_text);

        sprintf(buffer_c,"%0.2lf", signal_features[i][0]); //Actual Value
        buffer=TTF_RenderText_Solid( font_3, buffer_c, color_text);
        TTF_SizeText(font_3,buffer_c,&size_w,&size_h);
        coord_x=size_x+ WINDOW_SIZE_W*0.025;//size_w*2;
        coord_y=WINDOW_SIZE_H*0.08+2*i*size_h*2+size_h; //-WINDOW_SIZE_H*0.02;
        apply_surface( coord_x, coord_y, buffer, screen );
        SDL_FreeSurface( buffer );

        sprintf(buffer_c,"%0.2lf", signal_features[i][1]);  //Minimo
        buffer=TTF_RenderText_Solid( font_4, buffer_c, color_text);
        TTF_SizeText(font_4,buffer_c,&size_wm,&size_hm);
        coord_x=size_x+ WINDOW_SIZE_W*0.025+size_wm*0.1;//size_w*2;
        coord_y=WINDOW_SIZE_H*0.08+2*i*size_h*2+size_hm+size_hm/2+size_h; //-WINDOW_SIZE_H*0.02;
        apply_surface( coord_x, coord_y, buffer, screen );
        SDL_FreeSurface( buffer );

        sprintf(buffer_c,"%0.2lf", signal_features[i][2]);  //Maximo
        buffer=TTF_RenderText_Solid( font_4, buffer_c, color_text);
        TTF_SizeText(font_4,buffer_c,&size_wm,&size_hm);
        coord_x=size_x+ WINDOW_SIZE_W*0.025+size_wm*0.1;//size_w*2;
        coord_y=WINDOW_SIZE_H*0.08+2*i*size_h*2+2*size_hm+size_hm/2+size_h; //-WINDOW_SIZE_H*0.02;
        apply_surface( coord_x, coord_y, buffer, screen );
        SDL_FreeSurface( buffer );
/*
        sprintf(buffer_c,"%0.2lf", signal_features[i][3]);  //Promedio
        buffer=TTF_RenderText_Solid( font_4, buffer_c, color_text);
        TTF_SizeText(font_4,buffer_c,&size_wm,&size_hm);
        coord_x=size_x+ WINDOW_SIZE_W*0.025+size_wm*0.1;//size_w*2;
        coord_y=WINDOW_SIZE_H*0.08+2*i*size_h*2+3*size_hm+(size_hm/2+size_h); //-WINDOW_SIZE_H*0.02;
        apply_surface( coord_x, coord_y, buffer, screen );
        SDL_FreeSurface( buffer );

*/


        // draw_primitive(50,50,rell,vert,anc,alt,rgb_default);
    }

}


void HUD_grafic()
{

    advanced_graphic();


    SDL_Surface *buffer;
    char buffer_c[50];
    int size_w,size_h;
    int coord_x,coord_y;


    sprintf(buffer_c,"Muestras en Pantalla: %d",muestras_screen);
    buffer=TTF_RenderText_Solid( font_2, buffer_c, color_resp);
    TTF_SizeText(font_2,buffer_c,&size_w,&size_h);
    coord_x=WINDOW_SIZE_W*0.01;
    coord_y=WINDOW_SIZE_H-size_h;
    apply_surface( coord_x, coord_y, buffer, screen );
    SDL_FreeSurface( buffer );

        sprintf(buffer_c,"Muestras Recibidas: %d",muestras_in);
    buffer=TTF_RenderText_Solid( font_2, buffer_c, color_resp);
    TTF_SizeText(font_2,buffer_c,&size_w,&size_h);
    coord_x=WINDOW_SIZE_W*0.2;
    coord_y=WINDOW_SIZE_H-size_h;
    apply_surface( coord_x, coord_y, buffer, screen );
    SDL_FreeSurface( buffer );

    sprintf(buffer_c,"%d" ,label_y0);  //Mitad del Eje
    buffer=TTF_RenderText_Solid( font_2, buffer_c, color_resp);
    TTF_SizeText(font_2,buffer_c,&size_w,&size_h);
    coord_x=pos_x-size_w-pos_x*0.3;
    coord_y=eje_y_1-size_h/2;
    apply_surface( coord_x, coord_y, buffer, screen );
    SDL_FreeSurface( buffer );

    sprintf(buffer_c,"%d" ,label_y2 );  //1/4 Arriba
    buffer=TTF_RenderText_Solid( font_2, buffer_c, color_resp);
    TTF_SizeText(font_2,buffer_c,&size_w,&size_h);
    coord_x=pos_x-size_w-pos_x*0.3;
    coord_y=eje_y_2-size_h/2;
    apply_surface( coord_x, coord_y, buffer, screen );
    SDL_FreeSurface( buffer );


    sprintf(buffer_c,"%d" ,label_y3);  //1/4 Abajo
    buffer=TTF_RenderText_Solid( font_2, buffer_c, color_resp);
    TTF_SizeText(font_2,buffer_c,&size_w,&size_h);
    coord_x=pos_x-size_w-pos_x*0.3;
    coord_y=eje_y_3-size_h/2;
    apply_surface( coord_x, coord_y, buffer, screen );
    SDL_FreeSurface( buffer );

    sprintf(buffer_c,"%d" ,label_y1 );  //1/2 Arriba
    buffer=TTF_RenderText_Solid( font_2, buffer_c, color_resp);
    TTF_SizeText(font_2,buffer_c,&size_w,&size_h);
    coord_x=pos_x-size_w-pos_x*0.3;
    coord_y=pos_y-size_h/2;
    apply_surface( coord_x, coord_y, buffer, screen );
    SDL_FreeSurface( buffer );

    sprintf(buffer_c,"%d" ,label_y4 );  //1/2 Abajo
    buffer=TTF_RenderText_Solid( font_2, buffer_c, color_resp);
    TTF_SizeText(font_2,buffer_c,&size_w,&size_h);
    coord_x=pos_x-size_w-pos_x*0.3;
    coord_y=size_y-size_h/2;
    apply_surface( coord_x, coord_y, buffer, screen );
    SDL_FreeSurface( buffer );

    /*
    sprintf(buffer_c,"COM: %lf",com_datos[0][p_com_datos+1] );  //1/2 Abajo
    buffer=TTF_RenderText_Solid( font_2, buffer_c, color_resp);
    TTF_SizeText(font_2,buffer_c,&size_w,&size_h);
    coord_x=500;
    coord_y=500;
    apply_surface( coord_x, coord_y, buffer, screen );
    SDL_FreeSurface( buffer );
    sprintf(buffer_c,"COM: %lf",com_datos[1][p_com_datos+1] );  //1/2 Abajo
    buffer=TTF_RenderText_Solid( font_2, buffer_c, color_resp);
    TTF_SizeText(font_2,buffer_c,&size_w,&size_h);
    coord_x=900;
    coord_y=500;
    apply_surface( coord_x, coord_y, buffer, screen );
    SDL_FreeSurface( buffer );


    sprintf(buffer_c,"COM: %d",p_com_datos);  //1/2 Abajo
    buffer=TTF_RenderText_Solid( font_2, buffer_c, color_resp);
    TTF_SizeText(font_2,buffer_c,&size_w,&size_h);
    coord_x=500;
    coord_y=550;
    apply_surface( coord_x, coord_y, buffer, screen );
    SDL_FreeSurface( buffer );

    */

}
void HUD_buttons()
{

    SDL_Surface *buffer;

    int size_w,size_h;
    int coord_x,coord_y;
    char buffer_c[50];
    sprintf(buffer_c,"COM: %d",com_id);

    buffer=TTF_RenderText_Solid( font_2, buffer_c, color_resp);


    TTF_SizeText(font_2,buffer_c,&size_w,&size_h);

    coord_x=WINDOW_SIZE_W-size_w*1.4;
    coord_y=size_h*0.1; //-WINDOW_SIZE_H*0.02;
    apply_surface( coord_x, coord_y, buffer, screen );
    SDL_FreeSurface( buffer );



}

void HUD_static()
{

    SDL_Surface *buffer;

    int size_w,size_h;
    int coord_x,coord_y;
    char buffer_c[50];

    buffer=TTF_RenderText_Solid( font, "Signal COM Plotter", color_resp);


    TTF_SizeText(font,"Signal COM Plotter",&size_w,&size_h);

    coord_x=WINDOW_SIZE_W/2-size_w/2;
    coord_y=size_h*0.1; //-WINDOW_SIZE_H*0.02;
    apply_surface( coord_x, coord_y, buffer, screen );
    SDL_FreeSurface( buffer );



    sprintf(buffer_c,"%s",SOFT_VERSION);
        buffer=TTF_RenderText_Solid( font_4, buffer_c, color_resp);


    TTF_SizeText(font_4,buffer_c,&size_w,&size_h);

    coord_x=WINDOW_SIZE_W-size_w*1.2;
    coord_y=WINDOW_SIZE_H-size_h;
    apply_surface( coord_x, coord_y, buffer, screen );
    SDL_FreeSurface( buffer );





}

void HUD_console()
{
    int i;
    char buffer[20];
    for(i=0; i<36; i++)
    {
        if(flag_response[i])
            message=TTF_RenderText_Solid( font_3, buffer_console[i], color_resp);
        else
            message=TTF_RenderText_Solid( font_3, buffer_console[i], color_txt);
        apply_surface( text_x, text_y+i*FONT_SIZE, message, screen );
        SDL_FreeSurface( message );
    }

}



void HUD_working ()
{

    static int i,j,g;
    static short int init_x=5,init_y=35;
    short prox_x=init_x,prox_y=init_y;
    short off_x,off_y;
    static long crono=t;

    short  x[6] = { off_x, off_x+40, off_x+80, off_x+80, off_x+40,off_x };
    short  y[6] = { off_y, off_y-23, off_y, off_y+46, off_y+69,off_y+46};

    static short xx[14][24][6]= {0};
    static short yy[14][24][6]= {0};
    static short opp[14][24]= {0};

    static bool flag=0;

    //void draw_primitive(short x,short y,short relleno,short verices,short ancho,short alto,short r,short g,short b,short alpha)
    static short rell=3,vert=3,anc=100,alt=100;
    static short chanfle=186;
    colour color;

    color.r=255;
    color.g=0;
    color.b=0;
    color.alpha=255;
    //  draw_primitive(50,50,rell,vert,anc,alt,rgb_default); //Dibujar figura aleatoria
    draw_line_clock(1920-250,1080-250,25,chanfle,color);//chanfle,color);
    // draw_line_clock(1000,150,alt,chanfle,color);
    // draw_line_clock(750,600,alt,chanfle,color);


    if(!flag) //Inicializar Hexas
    {

        for(j=0; j<14; j++)
        {

            for(i=0; i<24; i++)
            {

                off_x=prox_x;
                off_y=prox_y;
                short  x[6] = { off_x, off_x+40, off_x+80, off_x+80, off_x+40,off_x };
                short  y[6] = { off_y, off_y-23, off_y, off_y+46, off_y+69,off_y+46};
                for(g=0; g<6; g++)
                {
                    xx[j][i][g]=x[g];
                    yy[j][i][g]=y[g];

                }

                if((rand()%5)%2!=0)
                {
                    opp[j][i]=rand()%255;

                }
                else opp[j][i]=0;

                prox_x=off_x+80+6;
                prox_y=off_y;



            }
            if((j+1)%2==0)
            {
                prox_x=init_x;
                prox_y=init_y+(j+1)*74;
            }

            else
            {
                prox_x=init_x-40-2;
                prox_y=init_y+(j+1)*74;

            }

        }
        flag=1;
    }
    else
    {

        for(j=0; j<14; j++)
        {

            for(i=0; i<24; i++)
            {
                if(flag_hexas!=0)
                    polygonRGBA(screen,
                                xx[j][i], yy[j][i],
                                6,
                                79, 78, 235, opp[j][i]);

            }
        }
        if(t>=crono)
        {
            if(flag_hexas!=0 && flag_hexas!=2)
                for(j=0; j<14; j++)
                    for(i=0; i<24; i++)
                        if((rand()%5)%2!=0)
                            opp[j][i]=rand()%255;
                        else   opp[j][i]=0;

            crono=t+1000;

            rell=rand()%50+5;
            vert=rand()%5;
            anc=rand()%1000+100;
            alt=rand()%1000+100;
            chanfle-=6;
            if(chanfle==-174)chanfle=186; //Hace un segundero
            /*    rell=20;
            vert=3;
            anc=2000;
            alt=500;*/

        }
    }




}

void HUD_Logo ()
{

    static short opp=255;
    int off_x=960-150;
    int off_y=400;




    filledTrigonRGBA(screen,
                     0+off_x, 0+off_y,
                     300+off_x, 0+off_y,
                     150+off_x, 260+off_y,
                     79, 78, 235, opp);

    filledTrigonRGBA(screen,
                     0+off_x+2, 0+off_y-55,
                     300+off_x-2, 0+off_y-55,
                     150+off_x, 260+off_y-55-2,
                     79, 78, 235, opp);

    filledTrigonRGBA(screen,
                     0+off_x+4, 0+off_y-55+2,
                     300+off_x-4, 0+off_y-55+2,
                     150+off_x, 260+off_y-55-5,
                     0, 0, 0, 255);
    /*
    filledTrigonRGBA(screen,
    0+off_x+34, 0+off_y,
    300+off_x-34, 0+off_y,
    150+off_x, 260+off_y-55,
    0, 0, 0, 255);*/




    //SDL_Delay(50);

    opp-=2;
    if(opp<=0)opp=255;


}
void HUD_Waiting()
{

    int off_x=960;
    int off_y=500;
    int i,j;
    int rad_x,rad_y;
    int polar_r,polar_radio;
    static short opp=255,opp_flag=0,opp_aux;

    static int r_x=960,r_y=400,radio=130;
    static float radio_d=127.5;
    static int radio_d_flag=0;

    filledEllipseRGBA(screen,
                      off_x, off_y,
                      radio, radio,
                      79, 78, 235, opp);


    filledEllipseRGBA(screen,
                      off_x, off_y,
                      160, 160,
                      79, 78, 235, 255-opp*2/3);
    filledEllipseRGBA(screen,
                      off_x, off_y,
                      130, 130,
                      0, 0, 0, 255);

    filledEllipseRGBA(screen,
                      off_x, off_y,
                      radio, radio,
                      79, 78, 235, opp);
    filledEllipseRGBA(screen,
                      off_x, off_y,
                      radio-5, radio-5,
                      0, 0, 0, 255);



    radio=radio_d;

    if(radio_d_flag)
        radio_d+=0.5;
    else
        radio_d-=0.5;

    if(radio_d==0)
    {
        radio_d_flag=1;
    }
    if(radio_d>=127.5)
    {
        radio_d_flag=0;
    }

    for(i=0; i<15000; i++)
    {
        polar_r=rand()%255;
        opp_aux=opp-polar_r;
        if(opp_aux>255)opp_aux=polar_r;
        rad_x=(180+polar_r)*cos(i);
        rad_y=(180+polar_r)*sin(i);
        pixelRGBA(screen,
                  rad_x+off_x,rad_y+off_y,

                  79, 78, 235, opp_aux);
    }


    if(opp_flag)
    {
        opp++;
    }
    else
    {
        opp--;
    }
    if(opp==0)
    {
        opp_flag=1;
    }
    if(opp==255)
    {
        opp_flag=0;
    }

}
void HUD_Create_Space()
{

    int off_x=200;
    int off_y=200;
    int i,j;
    int rad_x,rad_y;
    int polar_r;
    static short opp=255,opp_aux;


    boxRGBA(screen,
            off_x-200, off_y-50,
            off_x+200,off_y+50,
            0, 250, 0, 200);





}
#endif // HUD_H_INCLUDED
