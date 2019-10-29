#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "cliente.h"
#include "pedidos.h"
#include "informes.h"

int printPedidosInformes(sCliente* listClient,int lenClient,int auxIndex,int contador,char* estado)
{
	int ret=-1;

	if(listClient != NULL && lenClient>0)
	{
		printf("id: %d\nNombre de la empresa: %s\nDireccion: %s\nLocalidad %s\nCuit: %s\n%s %d\n*******************************\n", listClient[auxIndex].idCliente,
			                                                                               	   	   	   									listClient[auxIndex].name,
																																		listClient[auxIndex].direccion,
																																		listClient[auxIndex].localidad,
																																		listClient[auxIndex].cuit,
																																		estado,
																																		contador);
		ret=0;
	}

	return ret;

}

/////////////////////////////////////////////////////////////////////////////////

int clienteMaxPedidosPendientes(sPedidos* listPedidos,sCliente* listClient,int lenPedidos,int lenClient)
{
	int i,j;
	int contadorPend=0;
	int contadorPedidosPendMax=0;
	int auxIndex;
	int ret=-1;

	if(listPedidos != NULL && listClient != NULL && lenPedidos >0 && lenClient>0)
	{
		for(i=0;i<lenClient;i++)
		{
			if(listClient[i].isEmpty==0)
			{
				contadorPend=0;

				for(j=0;j<lenPedidos;j++)
				{
					if(listPedidos[j].idCliente == listClient[i].idCliente && listPedidos[j].isEmpty==0 && strcmp(listPedidos[j].estado,"-Pendiente-")==0)
					{
						contadorPend++;
					}
				}
				if(contadorPend>contadorPedidosPendMax)
				{
					contadorPedidosPendMax=contadorPend;
					auxIndex=i;

				}
			}

		}
       if(printPedidosInformes(listClient,lenClient,auxIndex,contadorPedidosPendMax,"Pedidos pendientes: ")==0)
       {
           ret=0;
       }

	}

	return ret;

}
/////////////////////////////////////////////////////////////////////////////////

int clienteMaxPedidosCompletados(sPedidos* listPedidos,sCliente* listClient,int lenPedidos,int lenClient)
{
	int i,j;
	int contadorCompl=0;
	int contadorPedidosComplMax=0;
	int auxIndex;
	int ret=-1;

	if(listPedidos != NULL && listClient != NULL && lenPedidos >0 && lenClient>0)
	{
		for(i=0;i<lenClient;i++)
		{
			if(listClient[i].isEmpty==0)
			{
				contadorCompl=0;

				for(j=0;j<lenPedidos;j++)
				{
					if(listPedidos[j].idCliente == listClient[i].idCliente && listPedidos[j].isEmpty==0 && strcmp(listPedidos[j].estado,"-Completado-")==0)
					{
						contadorCompl++;
					}
				}
				if(contadorCompl>contadorPedidosComplMax)
				{
					contadorPedidosComplMax=contadorCompl;
					auxIndex=i;

				}
			}

		}
		if(printPedidosInformes(listClient,lenClient,auxIndex,contadorPedidosComplMax,"Pedidos Completados: ")==0)
		{
	        ret=0;
		}

	}

	return ret;

}

/////////////////////////////////////////////////////////////////////////////////

int clienteMaxPedidos(sPedidos* listPedidos,sCliente* listClient,int lenPedidos,int lenClient)
{
	int i,j;
	int contadorPedidos=0;
	int contadorPedidosMax=0;
	int auxIndex;
	int ret=-1;

	if(listPedidos != NULL && listClient != NULL && lenPedidos >0 && lenClient>0)
	{
		for(i=0;i<lenClient;i++)
		{
			if(listClient[i].isEmpty==0)
			{
				contadorPedidos=0;

				for(j=0;j<lenPedidos;j++)
				{
					if(listPedidos[j].idCliente == listClient[i].idCliente && listPedidos[j].isEmpty==0)
					{
						contadorPedidos++;
					}
				}
				if(contadorPedidos>contadorPedidosMax)
				{
					contadorPedidosMax=contadorPedidos;
					auxIndex=i;

				}
			}

		}
		if(printPedidosInformes(listClient,lenClient,auxIndex,contadorPedidosMax,"Pedidos: ")==0)
		{
			ret=0;
		}

	}

	return ret;

}
/////////////////////////////////////////////////////////////////////////////////

int clienteMaxKilos(sPedidos* listPedidos,sCliente* listClient,int lenPedidos,int lenClient)
{
	int i,j;
	int contadorKilos=0;
	int contadorKilosMax=0;
	int auxIndex;
	int ret=-1;

	if(listPedidos != NULL && listClient != NULL && lenPedidos >0 && lenClient>0)
	{
		for(i=0;i<lenClient;i++)
		{
			if(listClient[i].isEmpty==0)
			{
				contadorKilos=0;

				for(j=0;j<lenPedidos;j++)
				{
					if(listPedidos[j].idCliente == listClient[i].idCliente && listPedidos[j].isEmpty==0)
					{
						contadorKilos+=listPedidos[j].PP;
						contadorKilos+=listPedidos[j].HDPE;
						contadorKilos+=listPedidos[j].LDPE;

					}
				}
				if(contadorKilos>contadorKilosMax)
				{
					contadorKilosMax=contadorKilos;
					auxIndex=i;

				}
			}

		}
		if(printPedidosInformes(listClient,lenClient,auxIndex,contadorKilosMax,"Cantidad de kilos: ")==0)
		{
			ret=0;
		}

	}

	return ret;

}
/////////////////////////////////////////////////////////////////////////////////

int clienteMinKilos(sPedidos* listPedidos,sCliente* listClient,int lenPedidos,int lenClient)
{
	int i,j;
	int contadorKilos=0;
	int contadorKilosMin=0;
	int auxIndex;
	int ret=-1;

	if(listPedidos != NULL && listClient != NULL && lenPedidos >0 && lenClient>0)
	{
		for(i=0;i<lenClient;i++)
		{
			if(listClient[i].isEmpty==0)
			{
				contadorKilos=0;

				for(j=0;j<lenPedidos;j++)
				{
					if(listPedidos[j].idCliente == listClient[i].idCliente && listPedidos[j].isEmpty==0)
					{
						contadorKilos+=listPedidos[j].PP;
						contadorKilos+=listPedidos[j].HDPE;
						contadorKilos+=listPedidos[j].LDPE;
					}
				}
				if(contadorKilos<contadorKilosMin)
				{
					contadorKilosMin=contadorKilos;
					auxIndex=i;

				}
			}

		}
		if(printPedidosInformes(listClient,lenClient,auxIndex,contadorKilos,"Pedidos: ")==0)
		{
			ret=0;
		}

	}

	return ret;

}

/////////////////////////////////////////////////////////////////////////////////

int clienteMas1000Kilos(sPedidos* listPedidos,sCliente* listClient,int lenPedidos,int lenClient)
{
	int i,j;
	int contadorCliente=0;
	int contadorKilos=0;
	int ret=-1;

	if(listPedidos != NULL && listClient != NULL && lenPedidos >0 && lenClient>0)
	{
		for(i=0;i<lenClient;i++)
		{
			if(listClient[i].isEmpty==0)
			{
				contadorCliente=0;

				for(j=0;j<lenPedidos;j++)
				{
					if(listPedidos[j].idCliente == listClient[i].idCliente && listPedidos[j].isEmpty==0)
					{
						contadorKilos+=listPedidos[j].PP;
						contadorKilos+=listPedidos[j].HDPE;
						contadorKilos+=listPedidos[j].LDPE;

						if(contadorKilos>1000)
						{
							contadorCliente++;
						}
					}
				}
			}

		}
		printf("Existen %d cliente/s con mas de 1000 kilos",contadorCliente);

	}

	return ret;

}

/////////////////////////////////////////////////////////////////////////////////

int clienteMenos100Kilos(sPedidos* listPedidos,sCliente* listClient,int lenPedidos,int lenClient)
{
	int i,j;
	int contadorCliente=0;
	int contadorKilos=0;
	int ret=-1;

	if(listPedidos != NULL && listClient != NULL && lenPedidos >0 && lenClient>0)
	{
		for(i=0;i<lenClient;i++)
		{
			if(listClient[i].isEmpty==0)
			{
				contadorCliente=0;

				for(j=0;j<lenPedidos;j++)
				{
					if(listPedidos[j].idCliente == listClient[i].idCliente && listPedidos[j].isEmpty==0)
					{
						contadorKilos+=listPedidos[j].PP;
						contadorKilos+=listPedidos[j].HDPE;
						contadorKilos+=listPedidos[j].LDPE;

						if(contadorKilos<100)
						{
							contadorCliente++;
						}
					}
				}
			}

		}
		printf("Existen %d cliente/s con menos de 100 kilos",contadorCliente);

	}

	return ret;

}


