#ifndef FLASH_STRINGS_H_INCLUDED
#define FLASH_STRINGS_H_INCLUDED

#include"variables.h"
//#include "console.h"

int function_lenght(); //Devuelve la cantidad de caracteres de la funcion tratada
int input_analizer ();//Analiza la cantidad de parametros de entrada
double read_num(char *buffer); //Lee un string y devuelve un double
int detect_function(int lenght,char *function_name); //Compara el nombre de la funcion y detecta que funcion representa
int str_copy(char *buffer1,char *buffer2,int length); //Copia un strig a otro string
void clear_buffers(); //Borra buffer_comand y input_params
int str_comp(char *buffer1,char *buffer2); //Compara strings y devuelve el numero de coincidencias
void clear_string(char *b,int length); //Borra un arreglo

extern void reglon_manager();

///**********************************************************

int function_lenght() //Devuelve la cantidad de caracteres de la funcion tratada
{

    int i;


    for(i=0; i<20; i++)
        if(buffer_comand[i]=='|')break;
    bff_cmd_pointer+=i+1;
    return i;

}

int input_analizer () //Analiza la cantidad de parametros de entrada
{

    int i=0,j=0,g=0;

    while(1)
    {

        if(buffer_comand[i]==NULL)break;
        if(buffer_comand[i]=='|')
        {
            j++;
            g=0;
            printf("%s\n",input_params[j-1]);
        }
        if(buffer_comand[i]!='|')
        {
            input_params[j][g]=buffer_comand[i];
            i++;
            g++;
        }
        else i++;

    }
    num_input_par=j+1;

}

double read_num(char *buffer)  //Lee un string y devuelve un double
{

    int i=0,j=0;
    char buffer_aux[20]= {0};

    while(1)
    {
        printf("/%c",buffer[i]);
        if(isdigit(buffer[i]) || buffer[i]=='.')
        {
            buffer_aux[i]=buffer[i];
            i++;


        }
        else break;

    }
    bff_cmd_pointer+=i;

    return strtof(buffer_aux,NULL);
}



int detect_function(int lenght,char *function_name)  //Compara el nombre de la funcion y detecta que funcion representa
{

        return atoi(function_name);


}

int str_copy(char *buffer1,char *buffer2,int length) //Copia un strig a otro string
{

    int i;
    for(i=0; i<length; i++)
    {
        buffer2[i]=buffer1[i];

    }
    return 0;



}

void clear_buffers() //Borra buffer_comand y input_params
{

    int i,j;
    for(i=0; i<124; i++)
        buffer_comand[i]=0;
    for(j=0; j<6; j++)
        for(i=0; i<24; i++)
            input_params[j][i]=0;
}
int str_comp(char *buffer1,char *buffer2) //Compara strings y devuelve el numero de coincidencias
{

    int i,coincidencias=0;
    if(strlen(buffer1)>strlen(buffer2))
        for(i=0; i<strlen(buffer2); i++)
        {
            if(buffer1[i]==buffer2[i])coincidencias++;
        }
    else
        for(i=0; i<strlen(buffer1); i++)
        {
            if(buffer1[i]==buffer2[i])coincidencias++;
        }
    return coincidencias;


}
void clear_string(char *b,int length) //Borra un arreglo
{
    int i;
    for(i=0; i<length; i++)
        b[i]=0;

}
#endif // FLASH_STRINGS_H_INCLUDED
