#include "Pedidos.h"

int inicializarPedidos(ePedido listaPedidos[], int tam)
{
	int retorno;
	retorno = -1;

	if(listaPedidos != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			listaPedidos[i].isEmpty = TRUE;
		}

		retorno = 0;
	}

return retorno;
}

int BuscarPedidoPorId(ePedido listaPedidos[], int tam, int id)
{
	int retorno;
	retorno = -1;

	if(listaPedidos != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(listaPedidos[i].isEmpty == FALSE && listaPedidos[i].id == id)
			{
				retorno = i;
				break;
			}
		}
	}

return retorno;
}




















