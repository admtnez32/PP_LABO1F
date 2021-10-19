#ifndef PEDIDOS_H_
#define PEDIDOS_H_
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define PENDIENTE 1
#define PROCESADO 2

typedef struct
{
	int id;
	int idCliente;
	int idLocalidad;
	int kg;
	int estado;
	char descripcion[20];
	int isEmpty;

}ePedido;

typedef struct
{
	int id;
	char descripcion[10];

}ePlastico;

int inicializarPedidos(ePedido listaPedidos[], int tam);

int BuscarPedidoPorId(ePedido listaPedidos[], int tam, int id);


#endif /* PEDIDOS_H_ */
