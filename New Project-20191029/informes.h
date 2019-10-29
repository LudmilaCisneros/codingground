#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "cliente.h"
#include "pedidos.h"


#ifndef INFORMES_H_
#define INFORMES_H_

int printPedidosInformes(sCliente* listClient,int lenClient,int auxIndex,int contador,char* estado);
int clienteMaxPedidosPendientes(sPedidos* listPedidos,sCliente* listClient,int lenPedidos,int lenClient);
int clienteMaxPedidosCompletados(sPedidos* listPedidos,sCliente* listClient,int lenPedidos,int lenClient);
int clienteMaxPedidos(sPedidos* listPedidos,sCliente* listClient,int lenPedidos,int lenClient);
int clienteMaxKilos(sPedidos* listPedidos,sCliente* listClient,int lenPedidos,int lenClient);
int clienteMinKilos(sPedidos* listPedidos,sCliente* listClient,int lenPedidos,int lenClient);
int clienteMas1000Kilos(sPedidos* listPedidos,sCliente* listClient,int lenPedidos,int lenClient);
int clienteMenos100Kilos(sPedidos* listPedidos,sCliente* listClient,int lenPedidos,int lenClient);

#endif /* INFORMES_H_ */
