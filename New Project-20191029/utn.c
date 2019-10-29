#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"


/////////////////////////////OBTENER/////////////////////////////

int utn_getString(char* pResultado,char* mensaje,char* mensajeError,int min,int max,int intentos)
{
    int ret=-1;
    char auxStr[4096];
    while(intentos>0)
    {
        printf("%s",mensaje);
        fgets(auxStr,sizeof(auxStr),stdin);
        auxStr[strlen(auxStr)-1] = '\0';

        if( pResultado != NULL && strlen(auxStr) >= min && strlen(auxStr) <= max)
        {
            strncpy(pResultado,auxStr,max);
            ret=0;
            break;
        }
        else
        {
            printf("%s",mensajeError);
        }
        intentos--;
    }

    return ret;
}

//-----------------------------------------------------------//

int utn_getInt(int* pResultado,char* mensaje,char* mensajeError,int min,int max,int intentos)
{
    int ret = -1;
    char auxStr[4096];
    int auxInt;
    while(intentos>0)
    {
        if(pResultado != NULL)
        {
            if(utn_getString(auxStr,mensaje,mensajeError,1,7,1)==0 &&
                utn_isValidInt(auxStr))
            {
                auxInt = atoi(auxStr);
                if(auxInt >= min && auxInt <= max)
                {
                    ret = 0;
                    *pResultado = auxInt;
                    break;
                }
                else
                {
                    printf("%s",mensajeError);
                }
            }
        }
    }
    return ret;
}
//-----------------------------------------------------------//

int utn_getFloat(float* pResultado,char* mensaje,char* mensajeError,int min,int max,int intentos)
{
    int ret = -1;
    char auxStr[4096];
    float auxFloat;
    while(intentos>0)
    {
        if(pResultado != NULL)
        {
            if(utn_getString(auxStr,mensaje,mensajeError,1,7,10)==0 &&
                utn_isValidFloat(auxStr))
            {
                auxFloat = atoi(auxStr);
                if(auxFloat >= min && auxFloat <= max)
                {
                    ret = 0;
                    *pResultado = auxFloat;
                    break;
                }
                else
                {
                    printf("%s",mensajeError);
                }
            }
        }
    }
    return ret;
}

//-----------------------------------------------------------//

int utn_getName(char* pResultado,int len,char* mensaje,char* mensajeError,int minChars,int maxChars,int intentos)
{
    int ret = -1;
    char auxStr[6000];
    while(intentos>0)
    {
        if(pResultado != NULL)
        {
            if(utn_getString(auxStr,mensaje,mensajeError,minChars,maxChars,1)==0 &&
                utn_isValidName(auxStr)&&strlen(auxStr)<=len)
            {
                strncpy(pResultado,auxStr,len);
                ret=0;
                break;
            }
        }
    }
    return ret;
}

//-----------------------------------------------------------//

int utn_getAddress(char* pResultado,int len,char* mensaje,char* mensajeError,int minChars,int maxChars,int intentos)
{
    int ret = -1;
    char auxStr[6000];
    while(intentos>0)
    {
        if(pResultado != NULL)
        {
            if(utn_getString(auxStr,mensaje,mensajeError,minChars,maxChars,1)==0 &&
                utn_isValidAddress(auxStr) && strlen(auxStr)<=len)
            {
                strncpy(pResultado,auxStr,len);
                ret=0;
                break;
            }
        }
    }
    return ret;
}

//-----------------------------------------------------------//



/////////////////////////////////VALIDAR////////////////////////////////

int utn_isValidInt (char* string)
{
    int ret = 1;
    int i=0;
    if(string!=NULL)
    {
        if(string[i] == '-')
        {
            i++;
        }
        for(;string[i] != '\0';i++)
        {
            if(string[i] < '0' || string[i] > '9')
            {
                ret=0;
                break;
            }
        }
    }
    return ret;
}
//-----------------------------------------------------------//

int utn_isValidFloat(char* string)
{
    int contadorPunto=0;
    int contadorSigno=0;
    int ret=1;
    int i=0;
    if(string!=NULL)
    {
        for(;string[i] != '\0';i++)
        {
            if(string[i] == '-')
            {
                i++;
            }
            if(string[i]=='.')
            {
                if(contadorSigno>0&&i==1)
                {
                    ret=0;
                    break;
                }
                contadorPunto++;
                i++;
            }
            if(((string[i]<'0' || string[i]>'9') && string[i]!='.') || contadorPunto>1)
            {
                ret=0;
                break;
            }
        }
    }
    return ret;
}
//-----------------------------------------------------------//

int utn_isValidName(char* string)
{
    int ret=1;
    int i=0;
    for(;string[i] != '\0';i++)
    {
        if(!isalpha(string[i]) && string[i] != ' ')
        {
            ret=0;
            break;
        }
    }
    return ret;
}
//-----------------------------------------------------------//

int utn_isValidAddress(char* string)
{
    int ret=1;
    int i=0;
    for(;string[i] != '\0';i++)
    {
        if(!isalnum(string[i]) && string[i] != ' ')
        {
            ret=0;
            break;
        }
    }
    return ret;
}

//-----------------------------------------------------------//



