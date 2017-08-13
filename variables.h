#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED

#include <SDL/SDL.h>
#include "SDL/SDL_ttf.h"
#include<time.h>
#include<windows.h>

#define RADIAN 57.2958

#define MAX_DATOS 2000

const char* WINDOW_TITLE = "Signal COM Plotter | Laguna Software";
const char* SOFT_VERSION = "v1.0.1";
SDL_Surface* screen = NULL;

bool gameRunning = true;


///SETTINGS
unsigned int MAX_LINES=4;
unsigned int SCREEN_W,SCREEN_H;
unsigned int WINDOW_SIZE_W,WINDOW_SIZE_H;
///FFT
bool flag_db=0,flag_zoom=0;

///VARIABLES DE DATOS
int fft_datos[600];
double com_datos[6][MAX_DATOS];
//double com_datos[MAX_DATOS];
int p_com_datos=0;


unsigned int muestras_screen=0;
unsigned int muestras_in=0;

///GRAPHIC
int  size_x =WINDOW_SIZE_W- WINDOW_SIZE_W*0.05;
int  size_y=WINDOW_SIZE_H- WINDOW_SIZE_H*0.05;
int  pos_x=WINDOW_SIZE_W*0.05;
int  pos_y= WINDOW_SIZE_H*0.05;
int eje_y_1,eje_y_2,eje_y_3,eje_y_4;
int  label_y1,label_y2,label_y3,label_y4,label_y0;

double offset_y;
double offset_div;


///SIGNALS
double signal_in[6][MAX_DATOS];
double signal_features[6][4];
int signal_inputs=0;

///SDL
SDL_Event event;
SDL_Thread *thread = NULL;

///COMUNICATION
bool com_connection=0;
HANDLE hSer;
COMMTIMEOUTS serTimeOut;
DCB serialPortCfg;
DWORD cBytes;
int com_id=0;
int rc;
char cht=0, //Caracter a transmitir
     chr=0; //Caracter recibido

///SDL TTF
TTF_Font *font = NULL;
TTF_Font *font_2 = NULL;
TTF_Font *font_3 = NULL;
TTF_Font *font_4 = NULL;
unsigned int FONT_SIZE=22;
unsigned int FONT_SIZE_2=16;
unsigned int FONT_SIZE_3=12;
unsigned int FONT_SIZE_4=20;


///TIPOS
typedef struct
{
    short r,g,b,alpha;
} colour;

///COLORES
SDL_Color color_txt = { 255, 255, 235, 255},
          color_resp = { 255, 255, 240,255 },
          color_red= {255,100,100,255},
          color_green= {100,255,100,255},
         color_blue= {0,90,255,255},
         color_yell= {230,255,0,255},
          color_pink= {255,0,200,255},
         color_cyan= {0,255,255,255};

colour rgb_default= { 255, 255, 255, 255},
       rgb_resp= { 255, 255, 255, 255};



///TEXT

SDL_Surface *message = NULL;


///KEYBOARD
Uint8 *keystates = SDL_GetKeyState( NULL ); //Mapea el teclado constantemente









///TIME
clock_t t;
long segundos, minutos, milis;
unsigned short crono_inactive=0;

///CONSOLE
int text_x=100, text_y=50;
bool flag_response[36]= {0}; //Cambia el color de la fuente identificandola como una respuesta
char buffer_console[36][128]= {'>'};
int buffer_c=0,buffer_reglon=1;
int ch_console;

///DEBUG COMMAND
char buffer_comand[128]= {0};
unsigned int bff_cmd_pointer=0;
short unsigned flag_new_command=0;
char input_params[6][128]= {0};
unsigned int num_input_par=0;
unsigned int flag_function=0;

int com_info=0;


///DEBUG
int num1,num2,dbg_lenght,function_id;

char debug_console[36][128];
unsigned int debug_reglon=0;

char dbg_operator;
char dbg_fuction[20];

int data[2000];

int test_datos[1000];


///HUD
int flag_working=1,flag_waiting=1,flag_console=1,flag_debug=1,flag_inactive=1;
int flag_key_press=0;
unsigned int flag_hexas=2; //Off=0  On=1 Stop=2
///MUSIC
char playlist[24][24]= {"Depre","Rock","Inspire","Cumbiancha","Rock Nacional","Avicii","ElectroParty","House","Old School","KunFury","Power","Gaga","Classic","Muscia Punchi"};


///ARCHIVOS

FILE *file;

#endif // VARIABLES_H_INCLUDED
