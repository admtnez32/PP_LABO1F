#ifndef INFORMES_H_
#define INFORMES_H_
#include "Nexo.h"
int PrintPedidosPendientesLocalidad(ePedido listaPedidos[], int tamPedidos, eLocalidad localidades[]);

//int PrintPPRecicladoPromedioPorCliente(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos);

int PrintClientesConMasPedidosProcesados(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos);

int PrintClientesConMasPedidosPendientes(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos);

#endif /* INFORMES_H_ */
