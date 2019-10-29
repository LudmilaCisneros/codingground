#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "pedidos.h"
#include "subMenu.h"
#include "menu.h"


///////////////MENU.C///////////////

void menu(sCliente* listClient,sPedidos* listPedidos, int lenClient, int lenPedidos)
{
	int option, i, id;
	char respuesta[3];

	while(option!=10)
	{
		printf("\nQUE OPERACION QUIERE REALIZAR?(INGRESE LA OPCION DESEADA)");
		printf("\n1-*ALTA DE CLIENTE*");
		printf("\n2-*MODIFICAR DATOS DE CLIENTE*");
		printf("\n3-*BAJA DE CLIENTE*");
		printf("\n4-*CREAR PEDIDO DE RECOLECCION*");
		printf("\n5-*PROCESAR RESIDUOS*");
		printf("\n6-*IMPRIMIR CLIENTES*");
		printf("\n7-*IMPRIMIR PEDIDOS PENDIENTES*");
		printf("\n8-*IMPRIMIR PEDIDOS PROCESADOS*");
		printf("\n9-*INFORMES*");
		printf("\n10-*SALIR*");
		printf("\n------------------------------------------------------------\n");

		utn_getInt(&option,"\nSelecione una opcion: ","\nOpcion invalida",1,9,10);
		switch(option)
		{
		case 1:
			getCliente(listClient,lenClient);
			break;
			/////////////////////////////////////////
		case 2:
			if(existCliente(listClient,lenClient)==0)
			{
				printCliente(listClient,lenClient);//imprime para que el usuario sepa que id existen
				utn_getInt(&id,"\nIngrese el ID del cliente a modificar: ","\nError",0,99999,10);
				i = encontrarClienteById(listClient,id,lenClient);//return la posicion i en la cual es igual al id de cliente
				if(i>=0)
				{
					modificarCliente(listClient,lenClient,i);
				}
				else{
					printf("El id ingresado no existe.");
				}
			}
			else
			{
				printf("\nEl registro esta vacio.\n");
			}
			break;
			///////////////////////////////////////////////////////////////////////////////
		case 3:
			if(existCliente(listClient,lenClient)==0)
			{
				printCliente(listClient,lenClient);
				utn_getInt(&id,"\nIngrese ID del cliente que desea eliminar: ","\nError",0,100,10);
				if(encontrarClienteById(listClient,id,lenClient)!= -1 && id >= 0)
				{
					utn_getString(respuesta,"\nPara eliminar ingrese 'si': ","\nERROR",1,5,10);
					if(strcmp("si",respuesta)==0)
					{
						removeCliente(listClient,lenClient,id);
						printf("Cliente con el id %d ha sido eliminado\n",id);
					}
				}
				else
				{
					printf("\nEl registro esta vacio.\n");
				}
			}
			break;
			/////////////////////////////////////////////////////////////////////////////////
		case 4:
			if(existCliente(listClient,lenClient)==0)
			{
				getPedido(listPedidos,listClient,lenClient,lenPedidos);
			}
			else
			{
				printf("\nEl registro esta vacio\n");
			}
				break;
			/////////////////////////////////////////////////////////////////////////////////
		case 5:
			if(existCliente(listClient,lenClient)==0 && existPedidos(listPedidos,lenPedidos)==0)
			{
				printPedidos(listPedidos,lenPedidos);
				procesarResiduos(listPedidos,lenPedidos);

			}
			else
			{
				printf("\nEl registro esta vacio\n");
			}

			break;
			/////////////////////////////////////////////////////////////////////////////////
		case 6:
			if(existCliente(listClient,lenClient)==0 && existPedidos(listPedidos,lenPedidos)==0)
			{
				if(printClienteCantPedidos(listPedidos,listClient,lenClient,lenPedidos)==-1)
				{
					printf("No hay pedidos pendientes");
				}
			}
			else
			{
				printf("\nEl registro esta vacio\n");
			}

			break;
			/////////////////////////////////////////////////////////////////////////////////
		case 7:
			if(existCliente(listClient,lenClient)==0 && existPedidos(listPedidos,lenPedidos)==0)
			{
				if(printPedidosPendientes(listPedidos,listClient,lenClient,lenPedidos)==-1)
				{
					printf("No hay pedidos pendientes");
				}
			}
			else
			{
				printf("\nEl registro esta vacio\n");
			}

			break;
			/////////////////////////////////////////////////////////////////////////////////
		case 8:
			if(existCliente(listClient,lenClient)==0 && existPedidos(listPedidos,lenPedidos)==0)
			{
				if(printPedidosProcesados(listPedidos,listClient,lenPedidos,lenClient)==-1)
				{
					printf("No hay pedidos procesados");
				}
			}
			else
			{
				printf("\nEl registro esta vacio\n");
			}

			break;
			/////////////////////////////////////////////////////////////////////////////////
		case 9:
			if(existCliente(listClient,lenClient)==0 && existPedidos(listPedidos,lenPedidos)==0)
				{
					subMenu(listClient,listPedidos,lenClient,lenPedidos);
				}
				else
				{
					printf("\nEl registro esta vacio\n");
				}

				break;
		}
	}
	return;
}
