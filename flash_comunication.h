#ifndef COMUNICATION_H_INCLUDED
#define COMUNICATION_H_INCLUDED

#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "variables.h"
#include"flash_signalproccs.h"

void start_comunication (unsigned int com_num);
void com_transmit (unsigned int paquete[4]);
bool com_get (unsigned int paquete[4]);

int com_thread( void *data);



void start_comunication (unsigned int com_num)
{

    char com_port[20]= {0};

    com_id = com_num;
    switch(com_num)
    {
    case 1:
        strcpy(com_port,"COM1:");
        break;
    case 2:
        strcpy(com_port,"COM2:");
        break;
    case 3:
        strcpy(com_port,"COM6:");
        break;
    case 4:
        strcpy(com_port,"COM4:");
        break;
    case 5:
        strcpy(com_port,"COM5:");
        break;
    case 6:
        strcpy(com_port,"COM6:");
        break;
    case 7:
        strcpy(com_port,"COM7:");
        break;
    case 8:
        strcpy(com_port,"COM8:");
        break;
    case 9:
        strcpy(com_port,"COM9:");
        break;
    case 10:
        strcpy(com_port,"\\\\.\\COM10");
        break;
    case 11:
        strcpy(com_port,"\\\\.\\COM11");
        break;
    case 12:
        strcpy(com_port,"\\\\.\\COM12");
        break;
    case 13:
        strcpy(com_port,"\\\\.\\COM13");
        break;
    case 14:
        strcpy(com_port,"\\\\.\\COM14");
        break;
    case 15:
        strcpy(com_port,"\\\\.\\COM15");
        break;
    case 16:
        strcpy(com_port,"\\\\.\\COM16");
        break;
    case 17:
        strcpy(com_port,"\\\\.\\COM17");
        break;
    case 18:
        strcpy(com_port,"\\\\.\\COM18");
        break;
    case 19:
        strcpy(com_port,"\\\\.\\COM19");
        break;
    case 20:
        strcpy(com_port,"\\\\.\\COM20");
        break;
    case 21:
        strcpy(com_port,"\\\\.\\COM21");
        break;
    case 22:
        strcpy(com_port,"\\\\.\\COM22");
        break;
    case 23:
        strcpy(com_port,"\\\\.\\COM23");
        break;
    case 24:
        strcpy(com_port,"\\\\.\\COM24");
        break;
    }

    hSer=CreateFile( com_port,                        /* Podría ser COM2:, COM3: o COM4: */
                     GENERIC_READ | GENERIC_WRITE,   /* para Tx y Rx */
                     0,                              /* el puerto es de uso exclusivo */
                     NULL,                           /* el handle no es heredable */
                     OPEN_EXISTING,                  /* el puerto debe existir */
                     0,                              /* no se aplica */
                     NULL);                          /* no se aplica */

    if(hSer == INVALID_HANDLE_VALUE)
    {
        //printf("Falló la apertura del puerto COM: %d\n", (int)GetLastError());
        sprintf(buffer_console[buffer_reglon],">>Fallo apertura puerto COM%d: %d",com_num,(int)GetLastError());
        flag_response[buffer_reglon]=1;
        reglon_manager();

    }
    else
    {
        com_connection=1;
        // thread = SDL_CreateThread( com_thread, NULL );
        sprintf(buffer_console[buffer_reglon],">>Conexion establecida con COM%d",com_num);
        flag_response[buffer_reglon]=1;
        reglon_manager();
    }
    // Configura los temporizados para lectura y escritura de los
    // puertos de transmisión y recepción
    // Lectura (recepción): si no hay ningún caracter recibido retorna inmediatemente
    serTimeOut.ReadIntervalTimeout = MAXDWORD;
    serTimeOut.ReadTotalTimeoutMultiplier = 0;
    serTimeOut.ReadTotalTimeoutConstant = 0;
    // Escritura (transmisión): no usa timeouts
    serTimeOut.WriteTotalTimeoutMultiplier = 0;
    serTimeOut.WriteTotalTimeoutConstant = 0;


    // Aplica la configuración de temporizados
    SetCommTimeouts(hSer, &serTimeOut);

    // Configura la velocidad de transmisión y demás parámetros
    // Obtiene la configuración actual
    serialPortCfg.DCBlength = sizeof(DCB);
    GetCommState(hSer, &serialPortCfg);
    // Modifica los parámetros de interés
    serialPortCfg.BaudRate = 38400;//CBR_9600;
    serialPortCfg.ByteSize = 8;
    serialPortCfg.Parity = NOPARITY;
    serialPortCfg.StopBits = ONESTOPBIT;
    // Aplica los cambios
    SetCommState(hSer, &serialPortCfg);


}

void com_getchar()
{

    static unsigned int i=0;
    unsigned int j=0;
    unsigned int g;
    static unsigned int dato=0;
    static char buff[200]= {'\b'};
    static int signal_numbers=0;
    static bool flag_init_feat=0;

    rc = ReadFile(hSer, &chr, 1, &cBytes, NULL);


    if(cBytes)
    {


        if(chr=='\n')
        {
            i=0;
            sprintf(debug_console[5],buff);

            switch(signal_inputs)
            {

            case 1:
                sscanf(buff, "%lf",
                       &com_datos[0][p_com_datos]
                      );
                break;

            case 2:
                sscanf(buff, "%lf %lf",
                       &com_datos[0][p_com_datos],
                       &com_datos[1][p_com_datos]
                      );
                break;

            case 3:
                sscanf(buff, "%lf %lf %lf",
                       &com_datos[0][p_com_datos],
                       &com_datos[1][p_com_datos],
                       &com_datos[2][p_com_datos]
                      );

                break;

            case 4:
                sscanf(buff, "%lf %lf %lf %lf",
                       &com_datos[0][p_com_datos],
                       &com_datos[1][p_com_datos],
                       &com_datos[2][p_com_datos],
                       &com_datos[3][p_com_datos]
                      );
                break;

            case 5:
                sscanf(buff, "%lf %lf %lf %lf %lf ",
                       &com_datos[0][p_com_datos],
                       &com_datos[1][p_com_datos],
                       &com_datos[2][p_com_datos],
                       &com_datos[3][p_com_datos],
                       &com_datos[4][p_com_datos]
                      );
                break;

            case 6:
                sscanf(buff, "%lf %lf %lf %lf %lf %lf",
                       &com_datos[0][p_com_datos],
                       &com_datos[1][p_com_datos],
                       &com_datos[2][p_com_datos],
                       &com_datos[3][p_com_datos],
                       &com_datos[4][p_com_datos],
                       &com_datos[5][p_com_datos]
                      );
                break;

            }
            update_features();

            if(flag_init_feat){
                init_features();
                flag_init_feat=0;
                }

                    get_axis_config();

            // signal_features

            //   signal_in


            printf(buff);
            //printf("%lf",com_datos[dato][p_com_datos]);
            p_com_datos++;
            muestras_in++;
            if(p_com_datos==muestras_screen)p_com_datos=0;


            for(j=0; j<i+1; j++)buff[j]=0;
            printf("\n");

            if(signal_inputs!=signal_numbers)
            {
                flag_init_feat=1;
                if(signal_numbers<=6)
                signal_inputs=signal_numbers;
                else
                    signal_inputs=6;
            }
            signal_numbers=0;
        }
        else if(chr=='\t')
        {
            signal_numbers++;
                buff[i]='\t';
                 i++;

        }
        else
        {
            buff[i]=chr;
            i++;
            printf("%c",chr);

        }



    }
}

int com_thread( void *data)
{
    while(1)
        if(com_connection)
            com_getchar();



}

/*



int com_transmit (void* data)  //Transmitir
{

    static unsigned int i=0;
    static char paquete[13]= {0};
    static char buff[5]= {0};
    static unsigned int checksum=0;

    paquete[0]=':';
    paquete[1]='0';
    paquete[2]='0';
    paquete[3]=',';
    sprintf(buff,"%d",power_motor);
    paquete[4]=buff[0];
    paquete[5]=buff[1];
    paquete[6]=buff[2];
    paquete[7]=buff[3];
    /* paquete[4]=(rcpwm_motor%10)+48;
     paquete[5]=((rcpwm_motor/10)%10)+48;
     paquete[6]=((rcpwm_motor/100)%10)+48;
     paquete[7]=((rcpwm_motor/1000)%10)+48;*/

/*
paquete[8]=',';
checksum=paquete[1]+paquete[2]+paquete[4]+paquete[5]+paquete[6]+paquete[7];

sprintf(buff,"%d",checksum);

paquete[9]=buff[0];
paquete[10]=buff[1];
paquete[11]=buff[2];
paquete[12]=';';
/*
paquete[11]=valor%10;
paquete[2]=(valor/10)%10;
paquete[1]=(valor/100)%10;
paquete[0]=(valor/1000)%10;
*/
/*
    for(i=0; i<13; i++)
    {
        rc = WriteFile(hSer, &paquete[i], 1, &cBytes, NULL);
        printf("%c",paquete[i]);
    }

    printf("\n");
    return 1;
}
int com_send (char data)  //Transmitir
{

    rc = WriteFile(hSer, &data, 1, &cBytes, NULL);
    printf("%c\n",data);

}

bool com_get (unsigned int paquete[4]) //Recibir
{

    static unsigned int i=0;
    // Verifica si hay algún caracter recibido, y lo obtiene
    rc = ReadFile(hSer, &chr, 1, &cBytes, NULL);

    if(cBytes)
    {
        if(chr==10 || chr ==13)
            i=i;
        else
        {
            paquete[i]=(chr-48); //Ascii to dec
            i++;
            //printf("%c",chr);
            //printf("%d\n",paquete[i]);
            if(i==4)
            {
                i=0;
                return true;
            }
        }

    }
    return false;

}

void int_to_paquete(unsigned int paquete[4],unsigned int valor)
{


    paquete[3]=valor%10;
    paquete[2]=(valor/10)%10;
    paquete[1]=(valor/100)%10;
    paquete[0]=(valor/1000)%10;


}
*/


#endif // COMUNICATION_H_INCLUDED
