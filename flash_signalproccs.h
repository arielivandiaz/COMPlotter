#ifndef FLASH_SIGNALPROCCS_H_INCLUDED
#define FLASH_SIGNALPROCCS_H_INCLUDED

#include"variables.h"

void update_features();
void init_features();

void get_axis_config();

void get_axis_config()
{
    float maximo=0;
    float minimo=0;
    int i=0;

    for( i=0; i<signal_inputs; i++){
        if( maximo<signal_features[i][2]) maximo=signal_features[i][2];
        if( minimo>signal_features[i][1]) minimo=signal_features[i][1];

        }
    i=-10000;
    while(i<10000){
 //   for( i=0;i<10000;i+=10);
      if(maximo<i){maximo=i;break;}
      i+=2;
    }
        sprintf(debug_console[1],"MAD max: %lf", maximo);

     i=10000;
    while(i>-10000){
 //   for( i=0;i<10000;i+=10);
      if(minimo>i){minimo=i;break;}
      i-=2;
    }
    sprintf(debug_console[2],"MAD min: %lf", minimo);

    label_y0=(int )(maximo+minimo)/2;

      sprintf(debug_console[3],"MAD 0: %d", label_y0);

      label_y1=maximo;
      label_y4=minimo;
      label_y2=(int ) (label_y0+maximo)/2;
      label_y3=(int ) (label_y0-minimo)/2;


}



void init_features()
{

    for(int j=1; j<4; j++)
        for(int i=0; i<signal_inputs; i++)
        {
            signal_features[i][j]= signal_features[i][0];
        }

}


void update_features()
{


    switch(signal_inputs)
    {

    case 1:
        signal_features[0][0]=com_datos[0][p_com_datos];

        break;

    case 2:
        signal_features[0][0]=com_datos[0][p_com_datos];
        signal_features[1][0]=com_datos[1][p_com_datos];

        break;

    case 3:
        signal_features[0][0]=com_datos[0][p_com_datos];
        signal_features[1][0]=com_datos[1][p_com_datos];
        signal_features[2][0]=com_datos[2][p_com_datos];


        break;

    case 4:
        signal_features[0][0]=com_datos[0][p_com_datos];
        signal_features[1][0]=com_datos[1][p_com_datos];
        signal_features[2][0]=com_datos[2][p_com_datos];
        signal_features[3][0]=com_datos[3][p_com_datos];

        break;

    case 5:
        signal_features[0][0]=com_datos[0][p_com_datos];
        signal_features[1][0]=com_datos[1][p_com_datos];
        signal_features[2][0]=com_datos[2][p_com_datos];
        signal_features[3][0]=com_datos[3][p_com_datos];
        signal_features[4][0]=com_datos[4][p_com_datos];

        break;

    case 6:

        signal_features[0][0]=com_datos[0][p_com_datos];
        signal_features[1][0]=com_datos[1][p_com_datos];
        signal_features[2][0]=com_datos[2][p_com_datos];
        signal_features[3][0]=com_datos[3][p_com_datos];
        signal_features[4][0]=com_datos[4][p_com_datos];
        signal_features[5][0]=com_datos[5][p_com_datos];

        break;

    }

    for(int i=0; i<signal_inputs; i++)
    {
        float sum=0;
        if( signal_features[i][0]<signal_features[i][1]) signal_features[i][1]=signal_features[i][0];
        if( signal_features[i][0]>signal_features[i][2]) signal_features[i][2]=signal_features[i][0];
        int muestra=p_com_datos;
        for(int j=0; j<muestras_screen; j++)
        {

            sum+=com_datos[i][muestra];
            muestra++;
            if(muestra>muestras_screen)muestra=0;

        }
        if(muestras_in<=muestras_screen)
            signal_features[i][3]=sum/p_com_datos;
        else
            signal_features[i][3]=sum/muestras_screen;

    }

}



#endif // FLASH_SIGNALPROCCS_H_INCLUDED
