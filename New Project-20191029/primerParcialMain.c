#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "pedidos.h"
#include "menu.h"
#define QTY_CLIENTES 100
#define QTY_PEDIDOS 1000

int main(void)
{
	sCliente listClient[QTY_CLIENTES];
	initCliente(listClient,QTY_CLIENTES);


	addCliente(listClient,1,QTY_CLIENTES,"Telefonica","30-11223344-5","Lima 1234","CABA");
	addCliente(listClient,2,QTY_CLIENTES,"DATASOFT","30-44556677-6","Corrientes 2547","CABA");
	addCliente(listClient,3,QTY_CLIENTES,"NESTLE","30-88995521-9","cucha cucha 555","LANUS");
	addCliente(listClient,4,QTY_CLIENTES,"TERRABUSI","30-56781423-5","rocha 784","QUILMES");
	addCliente(listClient,5,QTY_CLIENTES,"DIA","31-54581253-3","Mitre 750","AVELLANEDA");
	addCliente(listClient,6,QTY_CLIENTES,"QUILMES","30-51485759-6","rocha 741","QUILMES");

	sPedidos listPedidos[QTY_PEDIDOS];
	initPedido(listPedidos,QTY_PEDIDOS);



	addPedido(listPedidos,1,QTY_PEDIDOS,1,"-Completado-",1000,200,145,230);
	addPedido(listPedidos,2,QTY_PEDIDOS,1,"-Completado-",800,210,45,30);
	addPedido(listPedidos,3,QTY_PEDIDOS,2,"-Pendiente-",100,0,0,0);
	addPedido(listPedidos,4,QTY_PEDIDOS,2,"-Pendiente-",300,0,0,0);
	addPedido(listPedidos,5,QTY_PEDIDOS,3,"-Completado-",1500,500,150,270);
	addPedido(listPedidos,6,QTY_PEDIDOS,4,"-Completado-",750,100,50,70);
	addPedido(listPedidos,7,QTY_PEDIDOS,1,"-Pendiente-",200,0,0,0);
	addPedido(listPedidos,8,QTY_PEDIDOS,5,"-Completado-",30,10,5,3);
	addPedido(listPedidos,9,QTY_PEDIDOS,6,"-Pendiente-",456,0,0,0);
	/*int addPedido(sPedidos* listPedidos,
			  int idPedido,
			  int lenPedidos,
			  int auxIdClient,
			  char* auxEstado,
			  int kilosTotales,
			  int PP,
			  int HDPE,
			  int LDPE)*/



	menu(listClient,listPedidos,QTY_CLIENTES,QTY_PEDIDOS);

	return 0;
}
