#include "Informes.h"

int PrintPedidosPendientesLocalidad(ePedido listaPedidos[], int tamPedidos, eLocalidad localidades[])
{
	eAuxiliar contador[tamPedidos];
	int localidad;
	int indiceLocalidad;
	int retorno = 0;
	ContarPedidosPendientesLocalidad(listaPedidos, tamPedidos, localidades, contador);
	printf("\nC1: %d - %d\nC2: %d - %d\nC3: %d - %d\n", contador[0].id, contador[0].contador,contador[1].id, contador[1].contador ,contador[2].id, contador[2].contador);
	if(PedirNumeroConReintentosConRango(&localidad, "Ingrese localidad:\n\n 1) Lanus\n 2) Avella\n 3) Caba\n Opcion: ", 1, 3, 3))
	{
		indiceLocalidad = BuscarLocalidadPorId(localidades, tamPedidos, localidad);

		printf("\nIdLoc: %d\nIndiceloc: %d\n", localidad, indiceLocalidad);
		for(int i = 0; i < tamPedidos; i++)
		{
			for(int j = 0; j < tamPedidos; j++)
			{
				if(listaPedidos[i].isEmpty == FALSE && listaPedidos[i].estado == PENDIENTE && listaPedidos[i].idLocalidad == localidad && listaPedidos[i].idLocalidad == contador[j].id )
				{
					printf("\nIdLocLista: %d\n", listaPedidos[i].idLocalidad);
					printf("\n--- La localidad %s tiene %d pedido/s pendiente/s ---\n\n", localidades[indiceLocalidad].descripcion, contador[j].contador);
					retorno = 1;
				}
			}
		}
	}
return retorno;
}

/*int PrintPPRecicladoPromedioPorCliente(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos){

	int retorno = -1;
	int i,j;
	int idCliente;
	int kilosPPTotales = 0;
	int cantidadClientes = 0;
	float promedioPPporCliente = 0;


	if(tamPedidos > 0 && listaPedidos != NULL && tamClientes > 0 && listaClientes != NULL)
	{
		retorno = 0;

		for(i=0;i<tamClientes;i++){

			if (!listaClientes[i].isEmpty){

				idCliente = listaClientes[i].id;

				for(j=0;j<tamPedidos;j++){

					if (!listaPedidos[j].isEmpty && listaPedidos[j].idCliente == idCliente){

						kilosPPTotales = kilosPPTotales + listaPedidos[j];
					}
				}
				cantidadClientes++;
			}
		}

		promedioPPporCliente = (float)kilosPPTotales/cantidadClientes;

		printf("\nCantidad de kilos de polipropileno reciclado promedio por cliente: %2.f",promedioPPporCliente);
	}

	return retorno;
}*/

int PrintClientesConMasPedidosProcesados(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos)
{
	int retorno = -1;
    int contadorPedidos = 0;
    int contadorPedidosMax;
    int idCliente;

    if(tamClientes > 0 && listaClientes != NULL && tamPedidos > 0 && listaPedidos != NULL)
	{
        for(int i=0;i<tamClientes;i++)
        {
			for(int j=0;j<tamPedidos;j++)
			{
				if(listaClientes[i].isEmpty == FALSE && listaPedidos[j].idCliente == listaClientes[i].id && listaPedidos[j].estado == PROCESADO)
				{
					contadorPedidos++;
				}
            }

            if(contadorPedidos > contadorPedidosMax)
            {
                contadorPedidosMax = contadorPedidos;
                idCliente = listaClientes[i].id;
                retorno = 1;
            }

            contadorPedidos = 0;
        }

        for(int i = 0; i < tamClientes; i++)
        {
        	if(idCliente == listaClientes[i].id)
        	{
        		printf("\nEl cliente con mas pedidos procesados es %s\n\n",listaClientes[i].nombreEmpresa);
        	}
        }
	}
	return retorno;
}


int PrintClientesConMasPedidosPendientes(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos)
{
	int retorno = -1;
    int contadorPedidos = 0;
    int contadorPedidosMax;
    int idCliente;

    if(tamClientes > 0 && listaClientes != NULL && tamPedidos > 0 && listaPedidos != NULL)
	{
        for(int i=0;i<tamClientes;i++)
        {
			for(int j=0;j<tamPedidos;j++)
			{
				if(listaClientes[i].isEmpty == FALSE && listaPedidos[j].idCliente == listaClientes[i].id && listaPedidos[j].estado == PENDIENTE)
				{
					contadorPedidos++;
				}
            }

            if(contadorPedidos > contadorPedidosMax)
            {
                contadorPedidosMax = contadorPedidos;
                idCliente = listaClientes[i].id;
                retorno = 1;
            }

            contadorPedidos = 0;
        }

        for(int i = 0; i < tamClientes; i++)
        {
        	if(idCliente == listaClientes[i].id)
        	{
        		printf("\nEl cliente con mas pedidos pendientes es %s\n\n",listaClientes[i].nombreEmpresa);
        	}
        }
	}
	return retorno;
}

