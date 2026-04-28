#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argn, char **args)
{
        int rank , size; // nombre del proceso y numero de procesos
        int len; // numero de nodos
        char hostname[MPI_MAX_PROCESSOR_NAME];
        MPI_Status status;

        int result_i , base;
        int result = 0;

        sscanf(&base,"%i",args[1]); // Este valor solo el nodo maestro lo puede acceder o usar
        
        MPI_Init(&argn,&args); // inicializar el entorno de mpi

        MPI_Barrier(MPI_COMM_WORLD);

        MPI_Comm_rank(MPI_COMM_WORLD, &rank); // numero de proceso
        MPI_Comm_size(MPI_COMM_WORLD, &size); // numero total de procesos

        MPI_Get_processor_name(hostname, &len); // recuperar nombre del proceso

        MPI_Barrier(MPI_COMM_WORLD);
        
        // enviar datos, dominio
        if (rank == 0) // nodo maestro
        {
                for (int i=1; i<size; i++)
                {
                        MPI_Send(&base, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
                        base = base+1;
                }
        }
        else // nodos esclavos
        {       
                MPI_Recv(&base, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        }

        MPI_Barrier(MPI_COMM_WORLD);        

        // recopilar resultados
        if (rank == 0) // nodo maestro
        {
                for (int i=1; i<size; i++)
                {
                        MPI_Recv(&result_i, 1, MPI_INT, i, 0, MPI_COMM_WORLD, &status);
                        result = result + result_i;
                }
                printf("Suma = %i\n", result);
        }
        else // nodos esclavos
        {       
                result_i = base*base;
                MPI_Send(&result_i, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        }

        MPI_Barrier(MPI_COMM_WORLD);

        MPI_Finalize(); // finalizar el entorno de mpi

        return 0;
}
