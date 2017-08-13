#ifndef FLASH_TIME_H_INCLUDED
#define FLASH_TIME_H_INCLUDED

#include"variables.h"


long get_time(); //????
bool cronometro(int segs); //Cronometro basico
void cronometros(); //????


long get_time()
{

    t=clock();

    segundos=(t-10)/1000-minutos*60;
    milis=(t-segundos*1000-minutos*60000)/10-1;

    minutos=t/60000;
    cronometros();

}
void cronometros()
{

  if(crono_inactive<segundos)
    flag_inactive=1;


}
bool cronometro(int segs)
{

    static int crono=segundos+segs;
    static bool flag=0;
    if(flag)
    {
        crono=segundos+segs;
        flag=0;
    }
    if(segundos>=crono)
    {
        flag=1;
        return 1;

    }
    else return 0;
}
#endif // FLASH_TIME_H_INCLUDED
