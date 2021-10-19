#ifndef NEXO_H_
#define NEXO_H_
#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#include "MenuClientes.h"
#include "Pedidos.h"
#include "Clientes.h"
#include "Localidad.h"
typedef struct
{
	int idPedido;
	int hdpe;
	int ldpe;
	int pp;
	int isEmpty;
}eProcesado;



int inicializarProcesados(eProcesado listaProcesados[], int tam);

int SolicitarIdPedidos(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos);;

int PrintPedido(eCliente listaClientes, ePedido listaPedidos);

int PrintPedidos(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos);

//int MostrarPedido(eCliente listaClientes, ePedido listaPedidos);
int BuscarLocalidadPorId(eLocalidad localidades[], int tam, int id);
int MotrarPedidos(eCliente listaClientes, int tamClientes, ePedido listaPedidos, int tamPedidos);

int PrintPedidoProcesado(eCliente listaClientes, ePedido listaPedidos, eProcesado listaProcesados);

int PrintPedidosProcesados(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos, eProcesado listaProcesados[]);

int PrintPedidoPendiente(eCliente listaClientes, ePedido listaPedidos);

int PrintPedidosPendientes(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos);

int ProcesarResiduos(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tam, ePlastico listaPlasticos[], int tamPlasticos, eProcesado listaProcesados[]);

int ContarPedidosPendientesLocalidad(ePedido listaPedidos[], int tamPedidos, eLocalidad localidades[], eAuxiliar contador[]);

int PrintPedidosPendientesLocalidad(ePedido listaPedidos[], int tamPedidos, eLocalidad localidades[]);

//int PrintPPRecicladoPromedioPorCliente(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos);

int PrintClientesConMasPedidosProcesados(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos);

int PrintClientesConMasPedidosPendientes(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos);

#endif /* NEXO_H_ */
