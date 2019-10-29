#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#include "cliente.h"
#include "pedidos.h"


///////////////PEDIDOS.C///////////////

/** \brief Generate and keep track of the ids.
 * \return int Return the next id to use.
 *
 */
static int idPedido=1;

static int autoIncremenIdPedido(void)
{

    return idPedido++;
}

//------------------------------------------//
/** \brief  To indicate that all position in the array are empty,
 * * this function put the flag (isEmpty) in TRUE in all
 * * position of the array
 * * \param listClient Pointer to array
 * * \param len int Array length
 * * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok * */

int initPedido(sPedidos* listPedidos, int len)
{
	    int i;
	    int ret = -1;

	    if(listPedidos!= NULL && len > 0)
	    {
	        for(i=0; i<len;i++)
	        {
	            listPedidos[i].isEmpty = 1;
	        }
	        return 0;
	    }
	    return ret;
}
//------------------------------------------//
/** \brief Find a free space in the array and return his position
 *
 * \param listClient Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - The index of a free position in the array
 *
 */

int encontrarLibrePed(sPedidos* listPedidos,int lenPedidos)
{
    int i;
    int ret = -1;

    for(i=0;i<lenPedidos;i++)
    {

        if(listPedidos[i].isEmpty)
        {
            ret=i;
            break;
        }
    }
    return ret;
}
//------------------------------------------//

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param listClient Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */

int encontrarPedidoById(sPedidos* listPedidos,int idPedido,int lenPedidos)
{
    int i;
    int ret= -1;

    if(listPedidos != NULL && lenPedidos > 0)
    {
        for(i=0;i<lenPedidos;i++)
        {
            if(listPedidos[i].isEmpty==0 && listPedidos[i].idPedido==idPedido)
            {
                ret=i;
                break;
            }
        }
    }
    return ret;
}
//------------------------------------------//

/** \brief Find if exist a register of client type
 * \param listPedidos sPedidos* Pointer to array of pedidos
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */

int existPedidos(sPedidos* listPedidos,int lenPedidos)
{//listpedidos no este vacia
    int i;
    int ret=-1;
    for(i=0;i<lenPedidos;i++)
    {
        if(listPedidos[i].isEmpty==0)
        {
            ret=0;
            break;
        }
    }
    return ret;
}

//------------------------------------------//
//ALTA

int getPedido(sPedidos* listPedidos,sCliente* listClient, int lenClient, int lenPedidos)
{
	int ret = -1;
	int espacioLibre;
	char auxEstado[20];
	int auxIdClient;
	int auxKilosTotales;
//	int auxPP,auxHDPE,auxLDPE;


	espacioLibre = encontrarLibrePed(listPedidos,lenPedidos);
	printCliente(listClient,lenClient);

	if(utn_getInt(&auxIdClient,"\nIngrese ID del cliente que quiere realizar el pedido: ","\nError",0,100,10)==0 &&
	   utn_getInt(&auxKilosTotales,"\nIngrese la cantidad de kilos totales a reciclar: ","\nError",0,10000,10)==0 &&
       encontrarClienteById(listClient,auxIdClient,lenClient)!= -1 && espacioLibre >= 0)
	    {
			strncpy(auxEstado,"-Pendiente-",sizeof(auxEstado));
	        addPedido(listPedidos,autoIncremenIdPedido(),lenPedidos,auxIdClient,auxEstado,auxKilosTotales,0,0,0);

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

int addPedido(sPedidos* listPedidos,
			  int idPedido,
			  int lenPedidos,
			  int auxIdClient,
			  char* auxEstado,
			  int kilosTotales,
			  int PP,
			  int HDPE,
			  int LDPE)
{
    int i;
    int ret= -1;

    if(listPedidos != NULL && lenPedidos > 0)
    {
        i=encontrarLibrePed(listPedidos,lenPedidos);

        if(i>=0)
        {
            listPedidos[i].idPedido = idPedido;
            listPedidos[i].isEmpty = 0;
            listPedidos[i].idCliente = auxIdClient;
            listPedidos[i].kilosTotales = kilosTotales;
            strncpy(listPedidos[i].estado,auxEstado,sizeof(listPedidos[0].estado));

            ret = 0;
        }
        else
        {
            printf("No hay espacio");
        }
    }
    return ret;
}

//-------------------------------------------------------------------------------------//

int printPedidos(sPedidos* listPedidos,int lenPedidos)
{
	int i;
	int ret=-1;

	if(listPedidos != NULL && lenPedidos > 0)
	{
		for(i=0;i<=lenPedidos;i++)
		{
			if(listPedidos[i].isEmpty==0 && strcmp(listPedidos[i].estado,"-Pendiente-")==0)
			{
				 printf("idCliente: %d\nidPedido: %d\nCantidad de Kilos Totales: %d\nEstado: %s\n*******************************\n", listPedidos[i].idCliente,
						 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	  	  	  	  	  	  	  	  	  	  	  	  	 listPedidos[i].idPedido,
																																	 listPedidos[i].kilosTotales,
																																	 listPedidos[i].estado);
			}
			ret=0;
		}
	}
	else
	{
		printf("Ha ocurrido un error");
	}
	return ret;
}
//-------------------------------------------------------------------------------------//

int procesarResiduos(sPedidos* listPedidos,int lenPedidos)
{
	int i,auxId,auxPP,auxHDPE,auxLDPE;
	int ret=-1;

	utn_getInt(&auxId,"\nIngrese el id del pedido ha procesar: ","\nError",0,1000,10);
	i = encontrarPedidoById(listPedidos,auxId,lenPedidos);
	if(i>=0)
	{
		utn_getInt(&auxPP,"\nIngrese la cantidad de kilos de polipropileno(PP): ","\nError",0,10000,10);
 		utn_getInt(&auxHDPE,"\nIngrese la cantidad de kilos de polietileno de alta densidad(HDPE) : ","\nError",0,10000,10);
 	    utn_getInt(&auxLDPE,"\nIngrese la cantidad de kilos de polietileno de baja densidad(LDPE): ","\nError",0,10000,10);
 	    addReciclados(listPedidos,lenPedidos,auxPP,auxHDPE,auxLDPE,i);
 	    ret=0;
	}
	else
	{
		printf("No se encontro el pedido");
	}

	return ret;
}
//-------------------------------------------------------------------------------------//
int addReciclados(sPedidos* listPedidos,int lenPedidos,int PP,int HDPE,int LDPE, int i)
{
	int ret = -1;
	int auxKilosTotales=0;


	if(listPedidos != NULL && lenPedidos > 0)
	{
			listPedidos[i].PP = PP;
			listPedidos[i].HDPE = HDPE;
			listPedidos[i].LDPE = LDPE;
			auxKilosTotales = PP+HDPE+LDPE;

			if(auxKilosTotales < listPedidos[i].kilosTotales)
			{
				strncpy(listPedidos[i].estado,"-Completado-",sizeof(listPedidos[i].estado));
				ret=0;
			}
			else
			{
				printf("\nLa cantidad de kilos ingresados de cada categoria no concuerda con los kilos totales del pedido\n");
			}


	}
	return ret;
}
//-------------------------------------------------------------------------------------//
int printPedidosPendientes(sPedidos* listPedidos,sCliente* listClient,int lenClient,int lenPedidos)
{
	int i,j;
	int ret=-1;
	int contadorPendientes=0;

	if(listPedidos != NULL && listClient != NULL && lenPedidos > 0 && lenClient > 0)
	{
		for(i=0;i<=lenClient;i++)
		{
			if(listClient[i].isEmpty==0)
			{
				contadorPendientes=0;

				for(j=0;j<lenPedidos;j++)
				{
					if(listPedidos[j].isEmpty==0 && listPedidos[j].idCliente == listClient[i].idCliente && strcmp(listPedidos[j].estado,"-Pendiente-")==0)
					{
						contadorPendientes++;
					}
				}

			}
		}
		ret=0;
	}
	else
	{
		printf("Ha ocurrido un error");
	}
	return ret;
}
//-------------------------------------------------------------------------------------//
int printClienteCantPedidos(sPedidos* listPedidos,sCliente* listClient,int lenClient,int lenPedidos)
{
	int i,j;
	int ret=-1;
	int contadorPendientes=0;

	if(listPedidos != NULL && listClient != NULL && lenPedidos > 0 && lenClient > 0)
	{
		for(i=0;i<=lenClient;i++)
		{
			if(listClient[i].isEmpty==0)
			{
				contadorPendientes=0;

				for(j=0;j<lenPedidos;j++)
				{
					if(listPedidos[j].isEmpty==0 && listPedidos[j].idCliente == listClient[i].idCliente && strcmp(listPedidos[j].estado,"-Pendiente-")==0)
					{
						contadorPendientes++;
					}
				}

			}
		}
		ret=0;
	}
	else
	{
		printf("Ha ocurrido un error");
	}
	return ret;
}
//-------------------------------------------------------------------------------------//

int printPedidosProcesados(sPedidos* listPedidos,sCliente* listClient,int lenPedidos,int lenClient)
{
	int i,j;
	int ret=-1;

	if(listPedidos != NULL && listClient != NULL && lenPedidos > 0 && lenClient > 0)
	{
		for(i=0;i<lenClient;i++)
		{
			if(listClient[i].isEmpty==0)
			{
				 printf("idCliente: %d\nCliente: %s\nCuit: %s\nDireccion: %s\nLocalidad: %s\n*******************************\n",listClient[i].idCliente,
						 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	listClient[i].name,
																																listClient[i].cuit,
																																listClient[i].direccion,
																																listClient[i].localidad);
				 for(j=0;j<lenPedidos;j++)
				 {
						 if(listPedidos[j].idCliente==listClient[i].idCliente && strcmp(listPedidos[j].estado,"-Completado-")==0)
						 {
							printf("\nidPedido: %d\nPP: %d\nHDPE: %d\nLDPE: %d",listPedidos[i].idPedido,listPedidos[i].PP,listPedidos[i].HDPE,listPedidos[i].LDPE);
						 }
				 }
			}


		}
				ret=0;
	}
	else
	{
		printf("Ha ocurrido un error");
	}
	return ret;
}
//-------------------------------------------------------------------------------------//
