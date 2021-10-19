/*
 ============================================================================
 Name        : PP_LABO.c
 Author      : Martinez Alexis
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Nexo.h"
#define TAM_CLIENTES 3
#define TAM_PEDIDOS 3
#define TAM_PLASTICOS 3
#define TAM_PROCESADOS 3
#define TAM_LOCALIDADES 3

int main(void) {
	setbuf(stdout, NULL);

	eLocalidad localidades[TAM_LOCALIDADES] = {{1, "Lanus"},{2, "Avella"},{3, "Caba"}};
	eCliente clientes[TAM_CLIENTES] = {{100, "IBM SRL", "30-11111111-1", "AV ALEM 345", 3, 0}, {101, "INTEL", "30-33333333-3", "AV CORDOB 222", 1, 0}, {102, "APPLE INC", "30-55555555-5", "MARIANO 90", 2, 0}};
	ePedido pedidos[TAM_PEDIDOS];// = {{50, 101, 1, 990, 1, "PENDIENTE", 0},{51, 101, 1, 450, 1, "PENDIENTE", 0},{52, 101, 1, 600, 1, "PENDIENTE", 0}};
	ePlastico plasticos[TAM_PLASTICOS] = {{1, "HDPE"}, {2, "LDPE"}, {3, "PP"}};
	eProcesado procesados[TAM_PROCESADOS];// = {{50, 900, 45, 45, FALSE},{51, 400, 25, 25, FALSE},{52, 500, 50, 50, FALSE}};

	int id = 100;
	int idPedido = 50;
	int flagCargaEmpleado = 1;
	int flagPedidosPendientes = 0;
	int flagPedidosProcesados = 0;
	int opcion;
	inicializarProcesados(procesados, TAM_PROCESADOS);
	inicializarPedidos(pedidos, TAM_PEDIDOS);
	//InicializarClientes(clientes, TAM_CLIENTES);

	do{
		PrintMenu(PRINCIPAL);
		opcion = -1;
		PedirNumero(&opcion, "Elija opcion: ");

		switch(opcion)
		{
			case 1:
				if(!AltaCliente(clientes, TAM_CLIENTES, &id))
				{
					printf("\n--- Alta cancelada ---\n--- Volviendo al menu principal ---\n");
				}
				else
				{
					flagCargaEmpleado = 1;
				}
				break;

			case 2:
				if(flagCargaEmpleado)
				{
					if(!ModificarCliente(clientes, TAM_CLIENTES, pedidos, TAM_PEDIDOS, localidades))
					{
						printf("\n--- Modificacion cancelada ---\n--- Volviendo al menu principal ---\n");
					}
				}
				else
				{
					printf("\n--- No hay clientes cargados ---\n\n");
				}
				break;

			case 3:
				if(flagCargaEmpleado)
				{
					if(!BajarCliente(clientes, TAM_CLIENTES, pedidos, TAM_PEDIDOS, localidades))
					{
						printf("\n--- Baja cancelada ---\n--- Volviendo al menu principal ---\n");
					}
				}
				else
				{
					printf("\n--- No hay clientes cargados ---\n\n");
				}
				break;

			case 4:
				if(flagCargaEmpleado && CrearPedido(clientes, TAM_CLIENTES, pedidos, TAM_PEDIDOS, &idPedido, localidades))
				{

					flagPedidosPendientes = 1;
				}
				else
				{
					printf("\n--- No hay clientes cargados ---\n\n");
				}

				break;

			case 5:
				if(flagPedidosPendientes)
				{
					ProcesarResiduos(clientes, TAM_CLIENTES, pedidos, TAM_PEDIDOS, plasticos, TAM_PLASTICOS, procesados);
					flagPedidosProcesados = 1;
				}
				else
				{
					printf("\n--- No hay pedidos pendientes ---\n\n");
				}

				break;

			case 6:
				if(flagCargaEmpleado)
				{
					PrintClientes(clientes, TAM_CLIENTES, pedidos, TAM_PEDIDOS, localidades);
				}
				else
				{
					printf("\n--- No hay clientes cargados ---\n\n");
				}

				break;

			case 7:
				if(flagPedidosPendientes && !PrintPedidosPendientes(clientes, TAM_CLIENTES, pedidos, TAM_PEDIDOS))
				{
					printf("\n--- No hay pedidos pendientes ---\n\n");
				}


				break;

			case 8:
				if(flagPedidosProcesados)
				{
					PrintPedidosProcesados(clientes, TAM_CLIENTES, pedidos, TAM_PEDIDOS, procesados);
				}
				else
				{
					printf("\n--- No hay pedidos procesados ---\n\n");
				}

				break;

			case 9:
				if(!PrintPedidosPendientesLocalidad(pedidos, TAM_PEDIDOS, localidades))
				{
					printf("\nLa localidad no contiene pedidos pendientes\n\n");
				}
				break;

			case 10:
				break;

			case 11:
				PrintClientesConMasPedidosPendientes(clientes, TAM_CLIENTES, pedidos, TAM_PEDIDOS);
				break;

			case 12:
				PrintClientesConMasPedidosProcesados(clientes, TAM_CLIENTES, pedidos, TAM_PEDIDOS);
				break;

			case 0:
				break;

			default:
				printf("\n--- Opcion incorrecta ---\n\n");
				break;
		}


	}while(opcion != 0);
return EXIT_SUCCESS;
}
