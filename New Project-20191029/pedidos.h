#ifndef PEDIDOS_H_INCLUDED
#define PEDIDOS_H_INCLUDED

typedef struct {
	int idPedido;
	int idCliente;
	int HDPE;
	int LDPE;
	int PP;
	int kilosTotales;
	char estado[20];
	int isEmpty;

}sPedidos;
#include "cliente.h"

int encontrarLibrePed(sPedidos* listPedidos,int lenPedidos);
int initPedido(sPedidos* listPedidos, int len);
int existPedidos(sPedidos* listPedidos,int lenPedidos);
int getPedido(sPedidos* listPedidos,sCliente* listClient, int lenClient, int lenPedidos);
int addPedido(sPedidos* listPedidos,int idPedido,int lenPedidos,int auxIdClient,char* auxEstado,int kilosTotales,int PP,int HDPE,int LDPE);
int printPedidos(sPedidos* listPedidos,int lenPedidos);
int procesarResiduos(sPedidos* listPedidos,int lenPedidos);
int addReciclados(sPedidos* listPedidos,int lenPedidos,int PP,int HDPE,int LDPE,int i);
int printClienteCantPedidos(sPedidos* listPedidos,sCliente* listClient,int lenPedidos,int lenClient);
int printPedidosPendientes(sPedidos* listPedidos,sCliente* listClient,int lenClient,int lenPedidos);
int printPedidosProcesados(sPedidos* listPedidos,sCliente* listClient,int lenPedidos,int lenClient);

#endif /* PEDIDOS_H_ */
