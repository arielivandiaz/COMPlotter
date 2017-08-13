#ifndef KEYBOARD_H_INCLUDED
#define KEYBOARD_H_INCLUDED

int map_keyboard(SDL_Event evento)
{

    if (evento.key.keysym.sym == SDLK_ESCAPE) //Salir si se aprieta ESC
        gameRunning = false;

    if(evento.key.keysym.sym == 13)
        return '\n';
    if(evento.key.keysym.sym == SDLK_LSHIFT)
        return -1;
    if(evento.key.keysym.sym == SDLK_UP)
        return -1;
    if(evento.key.keysym.sym == SDLK_CAPSLOCK)
        return -1;
    if(evento.key.keysym.sym == SDLK_RSHIFT)
        return -1;
    if(evento.key.keysym.sym == 300)
        return -1;
    if(evento.key.keysym.sym == 306)
        return -1;
    if(evento.key.keysym.sym == 308)
        return -1;
    if(evento.key.keysym.sym == SDLK_RALT)
        return -1;
    if(evento.key.keysym.sym == 113)
        if(keystates[ SDLK_RALT ] || keystates[ SDLK_LALT ] )
            return '@';




    if(evento.key.keysym.sym == 44)
    {
        if(keystates[ SDLK_LSHIFT ] || keystates[ SDLK_RSHIFT ])
            return ';';
        else
            return ',';
    }
    if(evento.key.keysym.sym == 45)
    {
        if(keystates[ SDLK_LSHIFT ] || keystates[ SDLK_RSHIFT ])
            return '?';
        else   if(keystates[ SDLK_RALT ] )
            return 92;
        else
            return 39;
    }
    if(evento.key.keysym.sym == 46)
    {
        if(keystates[ SDLK_LSHIFT ] || keystates[ SDLK_RSHIFT ])
            return ':';
        else
            return '.';
    }
    if(evento.key.keysym.sym == 47)
    {
        if(keystates[ SDLK_LSHIFT ] || keystates[ SDLK_RSHIFT ])
            return '_';
        else
            return '-';
    }
    if(evento.key.keysym.sym == 61)
    {
        if(keystates[ SDLK_LSHIFT ] || keystates[ SDLK_RSHIFT ])
            return '¡';
        else
            return '¿';
    }
    if(evento.key.keysym.sym == 49)
    {
        if(keystates[ SDLK_LSHIFT ] || keystates[ SDLK_RSHIFT ])
            return '!';

    }
    if(evento.key.keysym.sym == 50)
    {
        if(keystates[ SDLK_LSHIFT ] || keystates[ SDLK_RSHIFT ])
            return '"';
    }
    if(evento.key.keysym.sym == 51)
    {
        if(keystates[ SDLK_LSHIFT ] || keystates[ SDLK_RSHIFT ])
            return '#';
    }
    if(evento.key.keysym.sym == 52)
    {
        if(keystates[ SDLK_LSHIFT ] || keystates[ SDLK_RSHIFT ])
            return '$';
    }
    if(evento.key.keysym.sym == 53)
    {
        if(keystates[ SDLK_LSHIFT ] || keystates[ SDLK_RSHIFT ])
            return '%';
    }
    if(evento.key.keysym.sym == 54)
    {
        if(keystates[ SDLK_LSHIFT ] || keystates[ SDLK_RSHIFT ])
            return '&';
    }
    if(evento.key.keysym.sym == 55)
    {
        if(keystates[ SDLK_LSHIFT ] || keystates[ SDLK_RSHIFT ])
            return '/';
    }
    if(evento.key.keysym.sym == 56)
    {
        if(keystates[ SDLK_LSHIFT ] || keystates[ SDLK_RSHIFT ])
            return '(';
    }
    if(evento.key.keysym.sym == 57)
    {
        if(keystates[ SDLK_LSHIFT ] || keystates[ SDLK_RSHIFT ])
            return ')';
    }
    if(evento.key.keysym.sym == 48)
    {
        if(keystates[ SDLK_LSHIFT ] || keystates[ SDLK_RSHIFT ])
            return '=';
    }
    if(evento.key.keysym.sym == 96)
    {
        if(keystates[ SDLK_LSHIFT ] || keystates[ SDLK_RSHIFT ])
            return '°';
        else
            return '|';
    }
    if(evento.key.keysym.sym == 39)
    {
        if(keystates[ SDLK_LSHIFT ] || keystates[ SDLK_RSHIFT ])
            return '[';
        else
            return '{';
    }
    if(evento.key.keysym.sym == 92)
    {
        if(keystates[ SDLK_LSHIFT ] || keystates[ SDLK_RSHIFT ])
            return ']';
        else
            return '}';
    }
    if(evento.key.keysym.sym == 91)
    {
        if(keystates[ SDLK_LSHIFT ] || keystates[ SDLK_RSHIFT ])
            return '¨';
        else
            return '´';
    }
    if(evento.key.keysym.sym == 93)
    {
        if(keystates[ SDLK_LSHIFT ] || keystates[ SDLK_RSHIFT ])
            return '*';
        else
            return '+';
    }
    if(evento.key.keysym.sym == 60)
    {
        if(keystates[ SDLK_LSHIFT ] || keystates[ SDLK_RSHIFT ])
            return '>';
    }
    if(evento.key.keysym.sym == 256)    return '0';
    if(evento.key.keysym.sym == 257)    return '1';
    if(evento.key.keysym.sym == 258)    return '2';
    if(evento.key.keysym.sym == 259)    return '3';
    if(evento.key.keysym.sym == 260)    return '4';
    if(evento.key.keysym.sym == 261)    return '5';
    if(evento.key.keysym.sym == 262)    return '6';
    if(evento.key.keysym.sym == 263)    return '7';
    if(evento.key.keysym.sym == 264)    return '8';
    if(evento.key.keysym.sym == 265)    return '9';
    if(evento.key.keysym.sym == 266)    return '.';
    if(evento.key.keysym.sym == 267)    return '/';
    if(evento.key.keysym.sym == 268)    return '*';
    if(evento.key.keysym.sym == 269)    return '-';
    if(evento.key.keysym.sym == 270)    return '+';
    if(evento.key.keysym.sym == 271)    return '\n';


    if(keystates[ SDLK_LSHIFT ] || keystates[ SDLK_RSHIFT ] )
    {
        if(isalpha(evento.key.keysym.sym))
            return evento.key.keysym.sym-32;
        else
            return evento.key.keysym.sym;


    }
    if(keystates[ SDLK_CAPSLOCK ])
    {
        if(isalpha(evento.key.keysym.sym))
            return evento.key.keysym.sym-32;

        else
            return evento.key.keysym.sym;
    }
    else
        return evento.key.keysym.sym;

}


#endif // KEYBOARD_H_INCLUDED
