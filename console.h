#ifndef CONSOLE_H_INCLUDED
#define CONSOLE_H_INCLUDED


#include "Keyboard.h"
#include"variables.h"
#include"flash_strings.h"
#include"line_fuctions.h"
#include"HUD.h"

int console (); //Kernel de la consola
int call_fuction(int f); //Llama la funcion con el numero indicado
void reorg_console(); //Mover lineas de consola cuando se llena
void reglon_manager();


int console ()
{
    unsigned int function_length=0;
    char buffer[25]= {0};

    ch_console=map_keyboard(event) ; //Obtiene el caracter ingresado


    if(ch_console==8 && buffer_c>0)
    {
        buffer_console[buffer_reglon][buffer_c]=0;
        buffer_c--;
        buffer_console[buffer_reglon][buffer_c]='♀';


    }
    else if(ch_console>0)
    {
        if(ch_console=='\n')
        {
            clear_buffers();
            //   buffer_console[buffer_reglon][buffer_c]='\r';
            buffer_c=0;
            str_copy( buffer_console[buffer_reglon],buffer_comand,strlen(buffer_console[buffer_reglon]));

            input_analizer ();
            flag_new_command=1;
            reglon_manager();

        }
        else
        {
            buffer_console[buffer_reglon][buffer_c]=ch_console;
            buffer_c++;
        }
    }
    else buffer_console[buffer_reglon][buffer_c]='♀';

    if( buffer_reglon>=MAX_LINES)
        reorg_console();


    if(flag_new_command) //Debug/Run command
    {

        function_length=function_lenght(); //La longitud del nombre de la funcion

        dbg_lenght=function_length;
        str_copy(buffer_comand,buffer,function_length);


        strcpy(dbg_fuction,buffer);
        function_id=detect_function(function_length,buffer);

        flag_function=function_id;

        call_fuction(function_id);

        bff_cmd_pointer=0;
        flag_new_command=0;
    }

}





int call_fuction(int f)
{
    char math_operator=0;




    start_comunication (atoi(input_params[0]));

    thread = SDL_CreateThread( com_thread, NULL );


    /* else
    {
        sprintf(buffer_console[buffer_reglon],">No se reconocio la orden");
        flag_response[buffer_reglon]=1;
        reglon_manager();
    }*/


}

void reorg_console()
{

    int i=0;

    for(i=0; i<buffer_reglon; i++)
    {
        strcpy(buffer_console[i],buffer_console[i+1]);
        flag_response[i]=flag_response[i+1];

    }
    sprintf(debug_console[9],"buffer reglon:'%d'",buffer_reglon);
    buffer_reglon--;
    clear_string(buffer_console[buffer_reglon],128);



}


void reglon_manager()
{

    buffer_reglon++;
    if(buffer_reglon>=MAX_LINES)  reorg_console();



}

#endif // CONSOLE_H_INCLUDED
