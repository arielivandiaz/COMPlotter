#ifndef LINE_FUCTIONS_H_INCLUDED
#define LINE_FUCTIONS_H_INCLUDED

#include"variables.h"
#include<time.h>
#include<windows.h>
#include"flash_comunication.h"
#include"flash_draw.h"

void start_comunication (unsigned int com_num);
void open_url();
int local_time();
int flash_math();
void play();
void juliet();
void hexas();
void debug_settings();
void graficar_fft();



void hexas()
{

    if(0==strcmp(input_params[1],"off"))
    {
        flag_hexas=0;
        sprintf(buffer_console[buffer_reglon],">Hexas are off");
        flag_response[buffer_reglon]=1;
        reglon_manager();
    }
    else if(0==strcmp(input_params[1],"on"))
    {
        flag_hexas=1;
        sprintf(buffer_console[buffer_reglon],">Hexas are on");
        flag_response[buffer_reglon]=1;
        reglon_manager();
    }
    else if(0==strcmp(input_params[1],"stop"))
    {
        flag_hexas=2;
        sprintf(buffer_console[buffer_reglon],">Hexas are stoped");
        flag_response[buffer_reglon]=1;
        reglon_manager();

    }
    else
    {
        sprintf(buffer_console[buffer_reglon],">Syntax Error");
        flag_response[buffer_reglon]=1;
        reglon_manager();
    }
}
int local_time()
{
    time_t t;
    struct tm *tm;
    static char buffer[50]= {0};

    t=time(NULL);
    tm=localtime(&t);
    strftime(buffer, 50, "%H:%M - %d/%m", tm);
    // sprintf(buffer,"%d",t);
    sprintf(buffer_console[buffer_reglon],buffer);
    reglon_manager();




}

int flash_math()
{

    double n1,n2,r;
    char op;
    n1=read_num(buffer_comand+bff_cmd_pointer);
    op=buffer_comand[bff_cmd_pointer];
    bff_cmd_pointer++;
    n2=read_num(buffer_comand+bff_cmd_pointer);




    switch(op)
    {

    case '+':
        sprintf(buffer_console[buffer_reglon]," >%lf",n1+n2);
        flag_response[buffer_reglon]=1;
        break;
    case '-':
        sprintf(buffer_console[buffer_reglon]," >%lf",n1-n2);
        flag_response[buffer_reglon]=1;
        break;

    case '*':
        sprintf(buffer_console[buffer_reglon]," >%lf",n1*n2);
        flag_response[buffer_reglon]=1;
        break;

    case '/':
        sprintf(buffer_console[buffer_reglon]," >%lf",n1/n2);
        flag_response[buffer_reglon]=1;
        break;
    default:
        sprintf(buffer_console[buffer_reglon]," >Error de Sintasis");
        flag_response[buffer_reglon]=1;
        break;


    }
    reglon_manager();
}



void open_url()
{

    if(strcmp("Cumbiancha",input_params[1])==0)
        ShellExecute(NULL, "open", "http://stackoverflow.com/questions/982266/launch-ie-from-a-c-program", NULL, NULL, SW_SHOWNORMAL);

}
void debug_settings(){

     if(0==strcmp(input_params[1],"on"))
    {
        flag_debug=1;
        sprintf(buffer_console[buffer_reglon],">>Debug Service are On");
        flag_response[buffer_reglon]=1;
        reglon_manager();
    }
    else if(0==strcmp(input_params[1],"off"))
    {
        flag_debug=0;
        sprintf(buffer_console[buffer_reglon],">Debug Service are Off");
        flag_response[buffer_reglon]=1;
        reglon_manager();

    }
    else
    {
        sprintf(buffer_console[buffer_reglon],">Syntax Error");
        flag_response[buffer_reglon]=1;
        reglon_manager();
    }


}

#endif // LINE_FUCTIONS_H_INCLUDED
