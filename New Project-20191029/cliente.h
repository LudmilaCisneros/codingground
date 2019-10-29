#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

///////////////CLIENTE.H///////////////

typedef struct {
	int idCliente;
	int isEmpty;
	//----//
	char name[51];
	char cuit[51];
	char direccion[51];
	char localidad[20];

} sCliente;

int encontrarLibre(sCliente *listClient, int len);
int initCliente(sCliente *listClient, int len);
int getCliente(sCliente *listClient, int len);
int addCliente(sCliente *listClient, int idCliente, int len, char *auxName,
		char *auxCuit, char *auxDireccion, char *auxLocalidad);
int encontrarClienteById(sCliente *listClient, int idCliente, int len);
//int sortCliente(sCliente* listClient, int len, int order);
//void swapCliente(sCliente* listClient,int i);
int removeCliente(sCliente *listClient, int len, int idCliente);
int printCliente(sCliente *listClient, int len);
int existCliente(sCliente *listClient, int len);
int modificarCliente(sCliente *listClient, int len, int i);

#endif /* CLIENTE_H_ */
