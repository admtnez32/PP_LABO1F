#ifndef CLIENTES_H_
#define CLIENTES_H_
#include "Funciones.h"
#include "Pedidos.h"
#include "MenuClientes.h"
#include "Localidad.h"
#define TAM_EMPRESA 51
#define TAM_DIRECCION 51
#define TAM_LOCALIDAD 51
#define TAM_CUIT 51

typedef struct
{
	int id;
	char nombreEmpresa[TAM_EMPRESA];
	char cuit[TAM_CUIT];
	char direccion[TAM_DIRECCION];
	int localidad;
	int isEmpty;
}eCliente;

typedef struct
{
    int id;
    int contador;

}eAuxiliar;

int InicializarClientes(eCliente listaClientes[], int tam);

int BuscarLugarLibre(eCliente listaClientes[], int tam);

int AltaCliente(eCliente listaClientes[], int tamClientes, int* id);

int PrintCliente(eCliente listaCliente, eAuxiliar contador, eLocalidad localidad);

int PrintClientes(eCliente listaClientes[], int tam, ePedido listaPedidos[], int tamPedidos, eLocalidad localidades[]);

int BuscarClientePorId(eCliente listaClientes[], int tam, int id);

int SolicitarId(eCliente listaClientes[], int tam, ePedido listaPedidos[], int tamPedidos, eLocalidad localidades[]);

int ModificarCliente(eCliente listaClientes[], int tam, ePedido listaPedidos[], int tamPedidos, eLocalidad localidades[]);

int BajarCliente(eCliente listaClientes[], int tam, ePedido listaPedidos[], int tamPedidos, eLocalidad localidades[]);

int CrearPedido(eCliente listaClientes[], int tam, ePedido listaPedidos[], int tamPedidos, int* idPedido, eLocalidad localidades[]);

int ContarPedidosPendientes(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos, eAuxiliar contador[]);
#endif /* CLIENTES_H_ */
