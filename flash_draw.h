#ifndef FLASH_DRAW_H_INCLUDED
#define FLASH_DRAW_H_INCLUDED

#include"variables.h"
#include<math.h>
#include "SDL/SDL_gfxPrimitives.h"
#include"flash_signalproccs.h"
//#include <SDL/SDL.h>
void draw_primitive(short x,short y,short relleno,short verices,short ancho,short alto,colour color);
void draw_line_clock(short x,short y,short largo, short angle,colour color);
void draw_graphic();
void advanced_graphic();
void graphic_fft(unsigned int pos_x,unsigned int pos_y,unsigned int size_xx,unsigned int size_yy,
                 double *input,int *input_format,unsigned int n_datos,unsigned int ejecucion, bool flag_db);

void draw_primitive(short x,short y,short relleno,short verices,short ancho,short alto,SDL_Color color)
{

    //x,y
    //relleno //Relleno=0,full relleno != => grosor
    //vertices
    //ancho,alto
    //r,g,b,alpha
    double fi,aux,aux2;

    switch(verices)
    {
    case 0:
        if(relleno==0)
            filledEllipseRGBA(screen,
                              x+ancho/2, y+alto/2,
                              ancho/2, alto/2,
                              color.r, color.g, color.b, color.unused);
        else if(relleno==1)

            ellipseRGBA(screen,
                        x+ancho/2, y+alto/2,
                        ancho/2, alto/2,
                        color.r, color.g, color.b, color.unused);
        else
        {
            filledEllipseRGBA(screen,
                              x+ancho/2, y+alto/2,
                              ancho/2, alto/2,
                              color.r, color.g, color.b, color.unused);
            filledEllipseRGBA(screen,
                              x+ancho/2, y+alto/2,
                              ancho/2-relleno/2, alto/2-relleno/2,
                              0, 0, 0, 255);
        }
        break;

    case 1:
        //Pixel
        pixelRGBA(screen,
                  x, y,
                  color.r, color.g, color.b, color.unused);
        break;
    case 2:   //Linea
        lineRGBA(screen,
                 x, y,
                 x+ancho, y+alto,
                 color.r, color.g, color.b, color.unused);

        break;
    case 3:   //Triangulo
        if(relleno==0)
            filledTrigonRGBA(screen,
                             x, y,
                             x+ancho, y,
                             x+ancho/2, y+alto,
                             color.r, color.g, color.b, color.unused);
        else if(relleno==1)

            trigonRGBA(screen,
                       x, y,
                       x+ancho, y,
                       x+ancho/2, y+alto,
                       color.r, color.g, color.b, color.unused);
        else
        {
            filledTrigonRGBA(screen,
                             x, y,
                             x+ancho, y,
                             x+ancho/2, y+alto,
                             color.r, color.g, color.b, color.unused);

            fi=asin(alto/sqrt((ancho/2)*(ancho/2)+alto*alto));
            aux=(relleno/tan(fi/2));
            aux2=relleno/sin(fi);

            //       printf("%dx%d\n",ancho,alto);
            //       printf("relleno=%d\n",relleno);
            //       printf("fi,%lf\n",fi);
            //       printf("aux=%lf\n\n",x+aux);

            filledTrigonRGBA(screen,
                             x+aux, y+relleno,
                             x+ancho-aux, y+relleno,
                             x+ancho/2, y+alto-aux2,
                             0, 0,0, 255);

        }
        break;
    case 4:
        if(relleno==0)
            boxRGBA(screen,
                    x, y,
                    x+ancho, y+alto,
                    color.r, color.g, color.b, color.unused);
        else if(relleno==1)
            rectangleRGBA(screen,
                          x, y,
                          x+ancho, y+alto,
                          color.r, color.g, color.b, color.unused);
        else
        {
            boxRGBA(screen,
                    x, y,
                    x+ancho, y+alto,
                    color.r, color.g, color.b, color.unused);


            boxRGBA(screen,
                    x+relleno, y+relleno,
                    x+ancho-relleno, y+alto-relleno,
                    0, 0,0, 255);
        }

        break;
    }


    /*
        //Triangulo
        trigonRGBA(screen,
                   500, 50,
                   550, 200,
                   600, 150,
                   r, g, b, alpha);

        filledTrigonRGBA(screen,
                         200, 200,
                         300, 50,
                         400, 200,
                         r, g, b, alpha);

        //Rectangulo
        rectangleRGBA(screen,
                      -10, 300,
                      100, 380,
                      r, g, b, alpha);

        boxRGBA(screen,
                210, 76,
                325, 300,
                r, g, b, alpha);

        //Eclipse
        ellipseRGBA(screen,
                    600, 400,
                    50, 90,
                    r, g, b, alpha);

        filledEllipseRGBA(screen,
                          600, 400,
                          25, 150,
                          r, g, b, alpha);

        short x[6] = { 350, 275, 300, 325, 350, 400 };
        short y[6] = { 325, 325, 390, 390, 375, 300 };

        //Poligono
        polygonRGBA(screen,
                    s, t,
                    lados,
                    r, g, b, alpha);


        short s[6] = { 50, 100, 150, 150, 100,50 };
        short t[6] = { 50, 0, 50, 100, 150,100};


        filledPolygonRGBA(screen,
                          s, t,
                          lados,
                          r, g, b, alpha);

    */


}

void draw_line_clock(short x,short y,short largo, short angle,colour color)
{


    lineRGBA(screen,
             x, y,
             x+largo*sin(angle/RADIAN), y+largo*cos(angle/RADIAN),
             color.r, color.g, color.b, color.alpha);




}

void draw_graphic()
{

    unsigned int eje_x=1000,eje_y=500,pos_x=500,pos_y=500,i,aux_ant=0,aux_y;
    static  int x[100],y[100];
    static bool flag=0;


    //Eje x
    lineRGBA(screen,
             pos_x, pos_y+eje_y,
             pos_x+eje_x, pos_y+eje_y,
             rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);

    //Eje y
    lineRGBA(screen,
             pos_x, pos_y,
             pos_x, pos_y+eje_y,
             rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);
    if(!flag)
    {
        for(i=0; i<100; i++)
        {
            y[i]=rand()%eje_y;
            //  y[i]=-100*sin(i*50)+200;
        }
        flag=1;
    }

    for(i=0; i<99; i++)
    {
        lineRGBA(screen,
                 pos_x+10*i, pos_y+eje_y-y[i],
                 pos_x+10+10*i, pos_y+eje_y-y[i+1],
                 rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);
        //Suavizado
        lineRGBA(screen,
                 pos_x+10*i, pos_y+eje_y-y[i]+1,
                 pos_x+10+10*i, pos_y+eje_y-y[i+1]+1,
                 rgb_default.r, rgb_default.g, rgb_default.b, 100);
        lineRGBA(screen,
                 pos_x+10*i, pos_y+eje_y-y[i]-1,
                 pos_x+10+10*i, pos_y+eje_y-y[i+1]-1,
                 rgb_default.r, rgb_default.g, rgb_default.b, 100);
        if(y[i]>y[i+1] && y[i-1]<y[i])  //Maximo
        {
            boxRGBA(screen,
                    pos_x+10*i-3, pos_y+eje_y-y[i]-3,
                    pos_x+10*i+3, pos_y+eje_y-y[i]+3,
                    rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);
        }
        else if(y[i]<y[i+1] && y[i-1]>y[i])  //Minimo
        {
            filledTrigonRGBA(screen,
                             pos_x+10*i-3, pos_y+eje_y-y[i]-3,
                             pos_x+10*i+3, pos_y+eje_y-y[i]-3,
                             pos_x+10*i, pos_y+eje_y-y[i]+3,
                             rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);
        }
        else
        {

            filledEllipseRGBA(screen,
                              pos_x+10*i, pos_y+eje_y-y[i],
                              3, 3,
                              rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);



        }

        /*    lineRGBA(screen,
                     pos_x+10*i, pos_y+eje_y-y[i],
                     pos_x+10+10*i+eje_x, pos_y+eje_y-y[i+1],
                     rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);
        */
    }


}

void graphic_fft(unsigned int pos_x,unsigned int pos_y,     //Posicion del grafico, punto 0,0
                 unsigned int size_xx,unsigned int size_yy, //Tamaño del grafico
                 double *input,             //Arreglo de datos de entrada
                 int *input_format,         //Arreglo de datos de entrada formateados
                 unsigned int n_input,      //Cantidad de datos de entrada
                 unsigned int ejecucion,    //Numero de ejecucion, para redibujar
                 bool flag_db)              //Es en dB o no el grafico
{

    unsigned int eje_x=1000,eje_y=500,i,aux_ant=0,aux_y,size_x,size_y;
    char buffer[100];
    static bool flag=0;
    unsigned int n=500;
    int x1,x2,y1,y2;
    static unsigned int suavizado=1;
    static unsigned int flag_ejecucion=0;
    unsigned int offset_x;
    int maximo=-1,pmaximo=-1;
    SDL_Surface *sdl_text = NULL;
    unsigned int muestras,k;

    if(size_xx!=0)size_x=size_xx;
    if(size_yy!=0)size_y=size_yy;



    if(n_input*3>size_yy)suavizado=0;

    //Eje x
    lineRGBA(screen,
             pos_x, pos_y,
             pos_x+size_x+15, pos_y,
             rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);

    //Eje y
    lineRGBA(screen,
             pos_x, pos_y,
             pos_x, pos_y-size_y-0,
             rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);

    if(flag_zoom)
    {
        offset_x=(int) 2*(size_x/n_input);
        muestras=n_input/2;
    }
    else
    {
        offset_x=(int) size_x/n_input;
        muestras=n_input;
    }

    if(ejecucion!=flag_ejecucion)
        if(size_x<n_input)
        {
            sprintf(buffer_console[buffer_reglon],">No puedo graficar - Todas las muestras no entran en las dimensiones del grafico (%dvs%d)",n_input,size_x);
            flag_response[buffer_reglon]=1;
            reglon_manager();
            flag_ejecucion=ejecucion;
            return ;
        }

    if(flag_db)
    {
//        k=normalizar_arreglo_fft(com_datos,fft_datos,fft_n_datos,70,SCREEN_H*0.7,flag_db);
        for(i=1; i<6; i++)
            lineRGBA(screen,
                     pos_x, pos_y-i*k*14,
                     pos_x-20, pos_y-i*k*14,
                     rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);
    }
    else
    {
//        k=normalizar_arreglo_fft(com_datos,fft_datos,fft_n_datos,250,SCREEN_H*0.7,flag_db);
        for(i=1; i<6; i++)
            lineRGBA(screen,
                     pos_x, pos_y-i*k*50,
                     pos_x-20, pos_y-i*k*50,
                     rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);

    }





    for(i=0; i<muestras; i++)
    {
        x1=pos_x+offset_x*i;
        x2=pos_x+offset_x*i;

        y1=pos_y;
        y2=pos_y-input_format[i];

        lineRGBA(screen,
                 x1, y1,
                 x2, y2,
                 rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);

        if(offset_x>3)
            filledEllipseRGBA(screen,
                              x1, y2,
                              3, 3,
                              rgb_resp.r, rgb_resp.g, rgb_resp.b, rgb_resp.alpha);

        if(i%25==0 && i!=0) //Cotas de los ejes
        {
            lineRGBA(screen,
                     x1, y1,
                     x2, y1+10,
                     rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);

            sprintf(buffer,"%d",i*20);
            sdl_text=TTF_RenderText_Solid( font, buffer, color_resp);
            apply_surface( x2-15, y1+15, sdl_text, screen );
            SDL_FreeSurface( sdl_text );



        }

        if(suavizado)
        {
            x1=pos_x+offset_x*i;
            x2=pos_x+offset_x*i;
            y1=pos_y;
            y2=pos_y-input_format[i]+size_y*0.05;
            if(y2>pos_y)y2=pos_y;


            lineRGBA(screen,   //Suavizado
                     x1+1, y1,
                     x2+1, y2,
                     rgb_resp.r, rgb_resp.g, rgb_resp.b, rgb_resp.alpha);


            lineRGBA(screen,    //Suavizado
                     x1-1, y1,
                     x2-1, y2,
                     rgb_resp.r, rgb_resp.g, rgb_resp.b, rgb_resp.alpha);
        }
    }
    for(i=0; i<muestras; i++)
    {
        if(maximo<input[i])
        {
            pmaximo=i;
            maximo=input[i];
        }

    }
    if(pmaximo>0 && maximo>0)
    {

        x1=pos_x+offset_x*pmaximo;
        y2=pos_y-input_format[pmaximo];

        lineRGBA(screen,
                 x1, y2-5,
                 x1+50, y2-50,
                 255, 50, 50, rgb_default.alpha);
        lineRGBA(screen,   //Suavizado
                 x1, y2-5,
                 x1+50, y2-49,
                 255, 50, 50, rgb_default.alpha);
        lineRGBA(screen,   //Suavizado
                 x1, y2-5,
                 x1+50, y2-51,
                 255, 50, 50, rgb_default.alpha);
        if(flag_db==1)
            sprintf(buffer,"MAXIMO=%0.2lfdB FRECUENCIA=%d",20*log10(input[pmaximo]/1000),input[pmaximo],maximo,pmaximo*20);
        else
            sprintf(buffer,"MAXIMO=%dmV FRECUENCIA=%d",maximo,pmaximo*20);
        sdl_text=TTF_RenderText_Solid( font, buffer, color_red);

        apply_surface( x1+60, y2-51-FONT_SIZE, sdl_text, screen );
        SDL_FreeSurface( sdl_text );



    }
    /*
        unsigned int eje_x=1000,eje_y=500,i,aux_ant=0,aux_y,size_x,size_y;
        char buffer[100];
        static bool flag=0;
        unsigned int n=500;
        int x1,x2,y1,y2;
        static unsigned int suavizado=1;
        static unsigned int flag_ejecucion=0;
        unsigned int offset_x;
        int maximo=-1,pmaximo=-1;
        SDL_Surface *sdl_text = NULL;
        unsigned int muestras;

        if(size_xx!=0)size_x=size_xx;
        if(size_yy!=0)size_y=size_yy;



        if(n_input*3>size_yy)suavizado=0;

        //Eje x
        lineRGBA(screen,
                 pos_x, pos_y,
                 pos_x+size_x, pos_y,
                 rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);

        //Eje y
        lineRGBA(screen,
                 pos_x, pos_y,
                 pos_x, pos_y-size_y,
                 rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);

           if(flag_zoom)
        offset_x=(int) 2*(size_x/n_input);
        else
             offset_x=(int) size_x/n_input;

        if(ejecucion!=flag_ejecucion)
            if(size_x<n_input)
            {
                sprintf(buffer_console[buffer_reglon],">No puedo graficar - Todas las muestras no entran en las dimensiones del grafico (%dvs%d)",n_input,size_x);
                flag_response[buffer_reglon]=1;
                reglon_manager();
                flag_ejecucion=ejecucion;
                return ;
            }


        for(i=0; i<n_input; i++)
        {
            x1=pos_x+offset_x*i;
            x2=pos_x+offset_x*i;

            y1=pos_y;
            y2=pos_y-input_format[i];

            lineRGBA(screen,
                     x1, y1,
                     x2, y2,
                     rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);

            if(offset_x>3)
                filledEllipseRGBA(screen,
                                  x1, y2,
                                  3, 3,
                                  rgb_resp.r, rgb_resp.g, rgb_resp.b, rgb_resp.alpha);
            if(i%25==0 && i!=0){
                 lineRGBA(screen,
                     x1, y1,
                     x2, y1+10,
                     rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);

            }

            if(suavizado)
            {
                x1=pos_x+offset_x*i;
                x2=pos_x+offset_x*i;
                y1=pos_y;
                y2=pos_y-input_format[i]+size_y*0.05;
                if(y2>pos_y)y2=pos_y;


                lineRGBA(screen,   //Suavizado
                         x1+1, y1,
                         x2+1, y2,
                         rgb_resp.r, rgb_resp.g, rgb_resp.b, rgb_resp.alpha);


                lineRGBA(screen,    //Suavizado
                         x1-1, y1,
                         x2-1, y2,
                         rgb_resp.r, rgb_resp.g, rgb_resp.b, rgb_resp.alpha);
            }
        }
        for(i=0; i<n_input; i++)
        {
            if(maximo<input[i])
            {
                pmaximo=i;
                maximo=input[i];
            }

        }
        if(pmaximo>0 && maximo>0)
        {

            x1=pos_x+offset_x*pmaximo;
            y2=pos_y-input_format[pmaximo];

            lineRGBA(screen,
                     x1, y2-5,
                     x1+50, y2-50,
                     255, 50, 50, rgb_default.alpha);
            lineRGBA(screen,   //Suavizado
                     x1, y2-5,
                     x1+50, y2-49,
                     255, 50, 50, rgb_default.alpha);
            lineRGBA(screen,   //Suavizado
                     x1, y2-5,
                     x1+50, y2-51,
                     255, 50, 50, rgb_default.alpha);
            if(flag_db==1)
                sprintf(buffer,"MAXIMO=%lf /mV=%d  FRECUENCIA=%d",20*log10(input[pmaximo]),maximo,pmaximo*20);
            else
                sprintf(buffer,"MAXIMO=%d  FRECUENCIA=%d",maximo,pmaximo*20);
            sdl_text=TTF_RenderText_Solid( font, buffer, color_red);

            apply_surface( x1+60, y2-51-FONT_SIZE, sdl_text, screen );
            SDL_FreeSurface( sdl_text );



        }
    */

}

void advanced_graphic()
{

    //  unsigned int eje_x=1000,eje_y=500,i,aux_ant=0,aux_y;
    ///    static  int x[100],y[100];
    //   static bool flag=0;

    // draw_primitive(5,5,10,4,WINDOW_SIZE_W-10,WINDOW_SIZE_H-10,color_txt);

    static int i=0;

    size_x =WINDOW_SIZE_W- WINDOW_SIZE_W*0.1;
    size_y=WINDOW_SIZE_H- WINDOW_SIZE_H*0.05;
    pos_x=WINDOW_SIZE_W*0.05;
    pos_y= WINDOW_SIZE_H*0.05;
    /*
        lineRGBA(screen,
                 size_x, pos_y,
                 size_x, size_y,
                 rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);

        lineRGBA(screen,
                 pos_x, pos_y,
                 size_x, pos_y,
                 rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);

    */
    //Eje y

    int flag_negativo=0; //1,2,3,4 = TODO NEGATIVO

    eje_y_1=pos_y+(size_y- pos_y)/2;
    eje_y_2=pos_y+(size_y- pos_y)/4;
    eje_y_3=eje_y_1+(size_y- pos_y)/4;

    muestras_screen=size_x-pos_x;  //Muestras en pantalla

    switch(flag_negativo)
    {

    case 0:
        //Eje y
        lineRGBA(screen, pos_x,   pos_y,   pos_x,            size_y,   rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);

        //Aux y

        /*1*/ lineRGBA(screen, pos_x,   size_y,  pos_x-pos_x*0.15, size_y,   rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);
        /*2*/ lineRGBA(screen, pos_x,   eje_y_2, pos_x-pos_x*0.15, eje_y_2,  rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);
        /*3*/ lineRGBA(screen, pos_x+5, eje_y_1, pos_x-pos_x*0.25, eje_y_1,  rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);
        /*4*/ lineRGBA(screen, pos_x,   eje_y_3, pos_x-pos_x*0.15, eje_y_3,  rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);
        /*5*/ lineRGBA(screen, pos_x,   pos_y,   pos_x-pos_x*0.15, pos_y,    rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);

        //Eje x
        lineRGBA(screen,pos_x, size_y,size_x, size_y,rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);
        break;

    case 1:
        //Eje y
        lineRGBA(screen, pos_x,   pos_y,   pos_x,            size_y,   rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);

        //Aux y

        /*1*/ lineRGBA(screen, pos_x,     size_y,  pos_x-pos_x*0.15, size_y,   rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);
        /*2*/ lineRGBA(screen, pos_x+5,   eje_y_2, pos_x-pos_x*0.25, eje_y_2,  rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);
        /*3*/ lineRGBA(screen, pos_x,     eje_y_1, pos_x-pos_x*0.15, eje_y_1,  rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);
        /*4*/ lineRGBA(screen, pos_x+5,   eje_y_3, pos_x-pos_x*0.25, eje_y_3,  rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);
        /*5*/ lineRGBA(screen, pos_x,     pos_y,   pos_x-pos_x*0.15, pos_y,    rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);

        //Eje x
        /*4*/ lineRGBA(screen, pos_x,   eje_y_3,size_x, eje_y_3,  rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);
        break;
    case 2:
        //Eje y
        lineRGBA(screen, pos_x,   pos_y,   pos_x,            size_y,   rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);

        //Aux y
        /*1*/ lineRGBA(screen, pos_x+5,     size_y,  pos_x-pos_x*0.25, size_y,   rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);
        /*2*/ lineRGBA(screen, pos_x,       eje_y_2, pos_x-pos_x*0.15, eje_y_2,  rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);
        /*3*/ lineRGBA(screen, pos_x+5,     eje_y_1, pos_x-pos_x*0.25, eje_y_1,  rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);
        /*4*/ lineRGBA(screen, pos_x,       eje_y_3, pos_x-pos_x*0.15, eje_y_3,  rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);
        /*5*/ lineRGBA(screen, pos_x+5,     pos_y,   pos_x-pos_x*0.25, pos_y,    rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);

        //Eje x

        /*3*/ lineRGBA(screen, pos_x,   eje_y_1,size_x, eje_y_1,  rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);
        break;
    case 3:
        //Eje y
        lineRGBA(screen, pos_x,   pos_y,   pos_x,            size_y,   rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);

        //Aux y
        /*1*/ lineRGBA(screen, pos_x,     size_y,  pos_x-pos_x*0.15, size_y,   rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);
        /*2*/ lineRGBA(screen, pos_x+5,       eje_y_2, pos_x-pos_x*0.25, eje_y_2,  rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);
        /*3*/ lineRGBA(screen, pos_x,     eje_y_1, pos_x-pos_x*0.15, eje_y_1,  rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);
        /*4*/ lineRGBA(screen, pos_x+5,       eje_y_3, pos_x-pos_x*0.25, eje_y_3,  rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);
        /*5*/ lineRGBA(screen, pos_x,     pos_y,   pos_x-pos_x*0.15, pos_y,    rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);

        //Eje x

        /*2*/ lineRGBA(screen, pos_x,   eje_y_2,size_x, eje_y_2,  rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);
        break;
    case 4:
        //Eje y
        lineRGBA(screen, pos_x,   pos_y,   pos_x,            size_y,   rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);

        //Aux y
        /*1*/ lineRGBA(screen, pos_x,     size_y,  pos_x-pos_x*0.15, size_y,   rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);
        /*2*/ lineRGBA(screen, pos_x+5,       eje_y_2, pos_x-pos_x*0.25, eje_y_2,  rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);
        /*3*/ lineRGBA(screen, pos_x,     eje_y_1, pos_x-pos_x*0.15, eje_y_1,  rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);
        /*4*/ lineRGBA(screen, pos_x+5,       eje_y_3, pos_x-pos_x*0.25, eje_y_3,  rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);
        /*5*/ lineRGBA(screen, pos_x,     pos_y,   pos_x-pos_x*0.15, pos_y,    rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);

        //Eje x
        /*5*/ lineRGBA(screen, pos_x,   pos_y,size_x, pos_y,  rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);
        break;
    }
    int j=p_com_datos;
    bool flag_relleno=0;
    offset_y=(float ) label_y0;
    //offset_div=fabs(0.4);//90/size_y;
    offset_div=(fabs(label_y1)+fabs(label_y4))/(size_y);//90/size_y;
     sprintf(debug_console[4],"asd: %lf",offset_div);
 sprintf(debug_console[7],"asd: %d",size_y);

    for(i=0; i<muestras_screen-1; i++)

    {
        if(flag_relleno)
        {

            for(int k=0; k<signal_inputs; k++)
                switch(k)
                {
                case 0:
                    lineRGBA(screen, size_x-i,   eje_y_1+(offset_y)/offset_div,size_x-i, eje_y_1+(offset_y-com_datos[k][j])/offset_div,  color_red.r, color_red.g, color_red.b, color_red.unused);

                        sprintf(debug_console[5],"Y: %lf",eje_y_1+(offset_y-com_datos[k][j])/offset_div);
                      //  sprintf(debug_console[6],"Y2: %lf",eje_y_1+(offset_y)/offset_div);
                        sprintf(debug_console[6],"%d + %d / %0.2lf",eje_y_1,(offset_y+com_datos[k][5]),offset_div);
                    break;
                case 1:
                    lineRGBA(screen, size_x-i,  eje_y_1+( offset_y)/offset_div,size_x-i, eje_y_1+(offset_y-com_datos[k][j])/offset_div,  color_green.r, color_green.g, color_green.b, color_green.unused);
               // lineRGBA(screen, size_x-i,  eje_y_1+( offset_y)/offset_div,size_x-i, eje_y_1+(offset_y+50)/offset_div,  color_green.r, color_green.g, color_green.b, color_green.unused);
                    break;
                case 2:
                    lineRGBA(screen, size_x-i,  eje_y_1+( offset_y)/offset_div,size_x-i, eje_y_1+(offset_y-com_datos[k][j])/offset_div,  color_blue.r, color_blue.g, color_blue.b, color_blue.unused);
                    //lineRGBA(screen, size_x-i,  eje_y_1+( offset_y)/offset_div,size_x-i, eje_y_1+(offset_y+57)/offset_div,  color_yell.r, color_yell.g, color_yell.b, color_yell.unused);
                    break;
                case 3:
                    lineRGBA(screen, size_x-i,  eje_y_1+( offset_y)/offset_div,size_x-i, eje_y_1+(offset_y-com_datos[k][j])/offset_div,  color_yell.r, color_yell.g, color_yell.b, color_yell.unused);
                    break;
                case 4:
                    lineRGBA(screen, size_x-i,  eje_y_1+( offset_y)/offset_div,size_x-i, eje_y_1+(offset_y-com_datos[k][j])/offset_div,  color_pink.r, color_pink.g, color_pink.b, color_pink.unused);
                    break;
                case 5:
                    lineRGBA(screen, size_x-i,  ( offset_y+eje_y_1)/offset_div,size_x-i, (offset_y+eje_y_1-com_datos[k][j])/offset_div,  color_cyan.r, color_cyan.g, color_cyan.b, color_cyan.unused);
                    break;

                }

        }
        else
        {
            if(i!=0)
            {
                for(int k=0; k<signal_inputs; k++)
                    switch(k)
                    {
                    case 0:
                        lineRGBA(screen, size_x-i+1,    eje_y_1+(offset_y-com_datos[k][j-1])/offset_div,size_x-i, eje_y_1+(offset_y-com_datos[k][j])/offset_div,   color_red.r, color_red.g, color_red.b, color_red.unused);
                        break;
                    case 1:
                        lineRGBA(screen, size_x-i+1,    eje_y_1+(offset_y-com_datos[k][j-1])/offset_div,size_x-i,eje_y_1+(offset_y-com_datos[k][j])/offset_div,  color_green.r, color_green.g, color_green.b, color_green.unused);
                        //lineRGBA(screen, size_x-i+1,    eje_y_1+(offset_y+110)/offset_div,size_x-i,eje_y_1+(offset_y+110)/offset_div,  color_green.r, color_green.g, color_green.b, color_green.unused);
                        break;
                    case 2:
                        lineRGBA(screen, size_x-i+1,   eje_y_1+ (offset_y-com_datos[k][j-1])/offset_div,size_x-i,eje_y_1+(offset_y-com_datos[k][j])/offset_div,   color_blue.r, color_blue.g, color_blue.b, color_blue.unused);
                        break;
                    case 3:
                        lineRGBA(screen, size_x-i+1,   eje_y_1+(offset_y+-com_datos[k][j-1])/offset_div,size_x-i,eje_y_1+(offset_y-com_datos[k][j])/offset_div,  color_yell.r, color_yell.g, color_yell.b, color_yell.unused);
                        break;
                    case 4:
                        lineRGBA(screen, size_x-i+1,   eje_y_1+(offset_y-com_datos[k][j-1])/offset_div,size_x-i, eje_y_1+(offset_y-com_datos[k][j])/offset_div,  color_pink.r, color_pink.g, color_pink.b, color_pink.unused);
                        break;
                    case 5:
                        lineRGBA(screen, size_x-i+1,  eje_y_1+(offset_y-com_datos[k][j-1])/offset_div,size_x-i,eje_y_1+(offset_y-com_datos[k][j])/offset_div,  color_cyan.r, color_cyan.g, color_cyan.b, color_cyan.unused);
                        break;

                    }
                //  lineRGBA(screen, size_x-i+1,    eje_y_1-com_datos[0][j-1]/2,size_x-i, eje_y_1-com_datos[0][j]/2,  color_red.r, color_red.g, color_red.b, color_red.unused);
                //  lineRGBA(screen, size_x-i+1,    eje_y_1-com_datos[1][j-1]/2,size_x-i, eje_y_1-com_datos[1][j]/2,  color_green.r, color_green.g, color_green.b, color_red.unused);
                // lineRGBA(screen, size_x-i+1,    eje_y_1-com_datos[2][j-1]/2,size_x-i, eje_y_1-com_datos[2][j]/2,  color_blue.r, color_blue.g, color_blue.b, color_blue.unused);
            }
            else
            {
                for(int k=0; k<signal_inputs; k++)
                    switch(k)
                    {
                    case 0:
                        pixelRGBA(screen, size_x-i,eje_y_1+(offset_y-com_datos[k][j])/offset_div,   color_red.r, color_red.g, color_red.b, color_red.unused);
                        break;
                    case 1:
                        pixelRGBA(screen, size_x-i,eje_y_1+(offset_y+-com_datos[k][j])/offset_div,  color_green.r, color_green.g, color_green.b, color_green.unused);
                        break;
                    case 2:
                        pixelRGBA(screen, size_x-i,eje_y_1+(offset_y-com_datos[k][j])/offset_div,   color_blue.r, color_blue.g, color_blue.b, color_blue.unused);
                        break;
                    case 3:
                        pixelRGBA(screen, size_x-i,eje_y_1+(offset_y+-com_datos[k][j])/offset_div, color_yell.r, color_yell.g, color_yell.b, color_yell.unused);
                        break;
                    case 4:
                        pixelRGBA(screen, size_x-i, eje_y_1+(offset_y-com_datos[k][j])/offset_div,  color_pink.r, color_pink.g, color_pink.b, color_pink.unused);
                        break;
                    case 5:
                        pixelRGBA(screen, size_x-i,eje_y_1+(offset_y+-com_datos[k][j])/offset_div,  color_cyan.r, color_cyan.g, color_cyan.b, color_cyan.unused);
                        break;

                    }

                //pixelRGBA(screen, size_x-i, eje_y_1-com_datos[k][j]/2, color_red.r, color_red.g, color_red.b, color_red.unused);
                //  pixelRGBA(screen, size_x-i, eje_y_1-com_datos[1][j]/2, color_green.r, color_green.g, color_green.b, color_green.unused);
                // pixelRGBA(screen, size_x-i, eje_y_1-com_datos[2][j]/2, color_blue.r, color_blue.g, color_blue.b, color_blue.unused);
            }

        }
        j++;
        if(j>=muestras_screen-1)j=1;
    }








    /*
            //Eje x
            lineRGBA(screen,
                     pos_x, pos_y+eje_y,
                     pos_x+eje_x, pos_y+eje_y,
                     rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);

            //Eje y
            lineRGBA(screen,
                     pos_x, pos_y,
                     pos_x, pos_y+eje_y,
                     rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);
      /*      if(!flag)
            {
                for(i=0; i<100; i++)
                {
                    //y[i]=rand()%eje_y;
                    y[i]=-100*sin(i*50)+200;
                }
                flag=1;
            }

            for(i=0; i<99; i++)
            {
                lineRGBA(screen,
                         pos_x+10*i, pos_y+eje_y-y[i],
                         pos_x+10+10*i, pos_y+eje_y-y[i+1],
                         rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);
                if(y[i]>y[i+1] && y[i-1]<y[i])  //Maximo
                {
                    boxRGBA(screen,
                            pos_x+10*i-3, pos_y+eje_y-y[i]-3,
                            pos_x+10*i+3, pos_y+eje_y-y[i]+3,
                            rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);
                }
                else if(y[i]<y[i+1] && y[i-1]>y[i])  //Minimo
                {
                    filledTrigonRGBA(screen,
                                     pos_x+10*i-3, pos_y+eje_y-y[i]-3,
                                     pos_x+10*i+3, pos_y+eje_y-y[i]-3,
                                     pos_x+10*i, pos_y+eje_y-y[i]+3,
                                     rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);
                }
                else
                {

                    filledEllipseRGBA(screen,
                                      pos_x+10*i, pos_y+eje_y-y[i],
                                      3, 3,
                                      rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);



                }

                /*    lineRGBA(screen,
                             pos_x+10*i, pos_y+eje_y-y[i],
                             pos_x+10+10*i+eje_x, pos_y+eje_y-y[i+1],
                             rgb_default.r, rgb_default.g, rgb_default.b, rgb_default.alpha);
                */
    //  }


}




#endif // FLASH_DRAW_H_INCLUDED
