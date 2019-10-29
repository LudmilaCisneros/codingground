#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#include "cliente.h"

///////////////CLIENTE.C///////////////

/** \brief Generate and keep track of the ids.
 * \return int Return the next id to use.
 *
 */
static int idCliente=1;

static int autoIncremenIdCliente(void)
{

    return idCliente++;
}

/** \brief Find a free space in the array and return his position
 *
 * \param listClient Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - The index of a free position in the array
 *
 */

int encontrarLibre(sCliente* listClient,int len)
{
    int i;
    int ret = -1;

    for(i=0;i<len;i++)
    {

        if(listClient[i].isEmpty)
        {
            ret=i;
            break;
        }
    }
    return ret;
}

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param listClient Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */

int encontrarClienteById(sCliente* listClient, int idCliente,int len)
{
    int i;
    int ret= -1;

    if(listClient != NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            if(listClient[i].isEmpty==0 && listClient[i].idCliente==idCliente)
            {
                ret=i;
                break;
            }
        }
    }
    return ret;
}

//------------------------------------------//
//ALTA

/** \brief  To indicate that all position in the array are empty,
 * * this function put the flag (isEmpty) in TRUE in all
 * * position of the array
 * * \param listClient Pointer to array
 * * \param len int Array length
 * * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok * */

int initCliente(sCliente* listClient, int len)
{
	    int i;
	    int ret = -1;

	    if(listClient != NULL && len > 0)
	    {
	        for(i=0; i<len;i++)
	        {
	            listClient[i].isEmpty = 1;
	        }
	        return 0;
	    }
	    return ret;
}

/** \brief request to the users the information for a new phantom
 *
 * \param sCliente[] listClient
 * \param len
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int getCliente(sCliente* listClient,int len)
{
    int ret = -1;
    int espacioLibre;
    char auxName[51];
    char auxDireccion[51];
    char auxLocalidad[51];
    char auxCuit[16];


    espacioLibre = encontrarLibre(listClient,len);

    if(utn_getName(auxName,51,"\nIngrese nombre de la empresa: ","\nERROR",3,50,3)==0 &&
       utn_getString(auxCuit,"\nIngrese el cuit de la empresa: ","\nERR0R",1,16,12)==0 &&
	   utn_getAddress(auxDireccion,51,"\nIngrese la direccion: ","\nERR0R",1,51,3)==0 &&
       utn_getString(auxLocalidad,"\nIngrese la localidad: ","\nERROR",1,51,12)==0 &&
       espacioLibre >= 0)
    {
        addCliente(listClient, autoIncremenIdCliente(), len, auxName, auxCuit, auxDireccion, auxLocalidad);
        ret = 0;
    }
    else
    {
    	printf("OCURRIO UN ERROR");
    }
    return ret;
}

//-------------------------------------------------------------------------------------//
/** \brief add in a existing listClient of phantoms the values received as parameters
 * in the first empty position
 * \param sCliente[] listClient
 * \param len
 * \param id
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */

int addCliente(sCliente* listClient,
			   int idCliente,
			   int len,
			   char* name,
			   char* cuit,
			   char* direccion,
			   char* localidad)
{
    int i;
    int ret= -1;

    if(listClient!=NULL&&len>0)
    {
        i=encontrarLibre(listClient,len);
        if(i>=0)
        {
            listClient[i].idCliente = idCliente;
            listClient[i].isEmpty = 0;
            strncpy(listClient[i].name,name,sizeof(listClient[0].name));
            strncpy(listClient[i].direccion,direccion,sizeof(listClient[0].direccion));
            strncpy(listClient[i].localidad,localidad,sizeof(listClient[0].localidad));
            strncpy(listClient[i].cuit,cuit,sizeof(listClient[0].cuit));
            ret = 0;
        }
        else
        {
            printf("No hay espacio");
        }
    }
    return ret;
}
//MODIFICAR direccion y localidad
//-------------------------------------------------------------------------------------//

int modificarCliente(sCliente* listClient,int len,int i)
{
	int ret = -1;
	char auxDireccion[51];
	char auxLocalidad[51];


	if(listClient != NULL && len > 0 && i >= 0)
	{
		if(utn_getAddress(auxDireccion,51,"\nIngrese la direccion: ","\nERR0R",1,51,3)==0 &&
		   utn_getString(auxLocalidad,"\nIngrese la localidad: ","\nERROR",1,51,12)==0)
		{
			strcpy(listClient[i].direccion, auxDireccion);
			strcpy(listClient[i].localidad, auxLocalidad);
			ret = 0;
		}
		else
		{
			printf("ERROR");
		}
	}
	return ret;
}
int removeCliente(sCliente *listClient, int len, int idCliente)
{
    int i;
    int ret= -1;

    if(listClient != NULL && len>0)
    {
    	i = encontrarClienteById(listClient,idCliente,len);
        if(i>=0)
        {
        	listClient[i].isEmpty = 1;
        	ret = 0;
        }
    }
    return ret;
}

//-------------------------------------------------------------------------------------//
/** \brief print the content of client array
 * * \param listClient Client
 * * \param length int
 * * \return int * */

int printCliente(sCliente* listClient, int len)
{
    int i;
    int ret= -1;
    if(listClient!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            if(listClient[i].isEmpty==0)
            {
                printf("id: %d\nNombre de la empresa: %s\nDireccion: %s\nLocalidad %s\nCuit: %s\n*******************************\n", listClient[i].idCliente,
                                                                                       	   	   	   									 listClient[i].name,
																																	 listClient[i].direccion,
																																	 listClient[i].localidad,
																																	 listClient[i].cuit);
            }

        }
        ret=0;
    }
    return ret;
}

/** \brief Find if exist a register of client type
 *
 * \param listClient sClient* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int existCliente(sCliente* listClient,int len)
{//listClient no este vacia
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(listClient[i].isEmpty==0)
        {
            ret=0;
            break;
        }
    }
    return ret;
}








