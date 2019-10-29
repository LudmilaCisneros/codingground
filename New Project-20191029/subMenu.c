#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "pedidos.h"
#include "menu.h"
#include "informes.h"
#include "subMenu.h"

void subMenu(sCliente* listClient,sPedidos* listPedidos,int lenClient,int lenPedidos)
{
	int option;

	while(option != 12)
	{
		printf("\nQUE INFORME QUIERE REALIZAR?(INGRESE LA OPCION DESEADA)");
		printf("\n1-*CLIENTE CON MAS PEDIDOS PENDIENTES*");
		printf("\n2-*CLIENTE CON MAS PEDIDOS COMPLETADOS*");
		printf("\n3-*CLIENTE CON MAS PEDIDOS*");
		printf("\n4-*CLIENTE QUE RECICLO MAS KILOS*");
		printf("\n5-*CANTIDAD DE CLIENTES QUE RECICLARON MAS DE 1000K*");
		printf("\n6-*CANTIDAD DE CLIENTES QUE RECICLARON MENOS DE 100K*");
		printf("\n7-*IMPRIMIR LOS PEDIDOS COMPLETADOS*");
		printf("\n8-*VER PEDIDOS PENDIENTES DE UNA LOCALIDAD*");
		printf("\n9-*CANTIDAD DE K DE PP PROMEDIO POR CLIENTE*");
		printf("\n10-*VER POR CUIT LA CANTIDAD RECICLADA POR TIPO*");
		printf("\n------------------------------------------------------------\n");

		utn_getInt(&option,"\nSelecione una opcion: ","\nOpcion invalida",1,9,11);

		switch(option)
		{
		case 1:
			if(existCliente(listClient,lenClient)==0 && existPedidos(listPedidos,lenPedidos)==0)
			{
				clienteMaxPedidosPendientes(listPedidos,listClient,lenPedidos,lenClient);
			}
			else
			{
				printf("No se han cargado clientes o pedidos");
			}
			break;
			/////////////////////////////////////////////////////////////////////////////////
		case 2:
			if(existCliente(listClient,lenClient)==0 && existPedidos(listPedidos,lenPedidos)==0)
			{
				clienteMaxPedidosCompletados(listPedidos,listClient,lenPedidos,lenClient);
			}
			else
			{
				printf("No se han cargado clientes o pedidos");
			}
			break;
			/////////////////////////////////////////////////////////////////////////////////
		case 3:
			if(existCliente(listClient,lenClient)==0 && existPedidos(listPedidos,lenPedidos)==0)
			{
				clienteMaxPedidos(listPedidos,listClient,lenPedidos,lenClient);
			}
			else
			{
				printf("No se han cargado clientes o pedidos");
			}
			break;
			/////////////////////////////////////////////////////////////////////////////////
		case 4:
			if(existCliente(listClient,lenClient)==0 && existPedidos(listPedidos,lenPedidos)==0)
			{
				clienteMaxKilos(listPedidos,listClient,lenPedidos,lenClient);
			}
			else
			{
				printf("No se han cargado clientes o pedidos");
			}
			break;
			/////////////////////////////////////////////////////////////////////////////////
		case 5:
			if(existCliente(listClient,lenClient)==0 && existPedidos(listPedidos,lenPedidos)==0)
			{
				clienteMinKilos(listPedidos,listClient,lenPedidos,lenClient);
			}
			else
			{
				printf("No se han cargado clientes o pedidos");
			}
			break;
			/////////////////////////////////////////////////////////////////////////////////
		case 6:
			if(existCliente(listClient,lenClient)==0 && existPedidos(listPedidos,lenPedidos)==0)
			{
				clienteMas1000Kilos(listPedidos,listClient,lenPedidos,lenClient);
			}
			else
			{
				printf("No se han cargado clientes o pedidos");
			}
			break;
			/////////////////////////////////////////////////////////////////////////////////
		case 7:
			if(existCliente(listClient,lenClient)==0 && existPedidos(listPedidos,lenPedidos)==0)
			{
				clienteMenos100Kilos(listPedidos,listClient,lenPedidos,lenClient);
			}
			else
			{
				printf("No se han cargado clientes o pedidos");
			}
			break;
			/////////////////////////////////////////////////////////////////////////////////
		/*case 8:
			if(existCliente(listClient,lenClient)==0 && existPedidos(listPedidos,lenPedidos)==0)
			{
				clienteMinKilos(listPedidos,listClient,lenPedidos,lenClient);
			}
			else
			{
				printf("No se han cargado clientes o pedidos");
			}
			break;*/



		}
	}
}
