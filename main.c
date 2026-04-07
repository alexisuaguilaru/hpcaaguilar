#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argn, char **args)
{
        int rank , size; // nombre del proceso y numero de procesos
        int len; // numero de nodos
        char hostname[MPI_MAX_PROCESSOR_NAME];
        MPI_Status status;

        int result_i;
        int result = 0;
        
        MPI_Init(&argn,&args); // inicializar el entorno de mpi

        MPI_Barrier(MPI_COMM_WORLD);

        MPI_Comm_rank(MPI_COMM_WORLD, &rank); // numero de proceso
        MPI_Comm_size(MPI_COMM_WORLD, &size); // numero total de procesos

        MPI_Get_processor_name(hostname, &len); // recuperar nombre del proceso

        MPI_Barrier(MPI_COMM_WORLD);
        
        // printf("Hola mundo soy el proceso %i de %i en %s y mi resultado es: %i\n", rank, size, hostname, result);

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
                result_i = rank*rank;
                MPI_Send(&result_i, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        }

        MPI_Barrier(MPI_COMM_WORLD);

        MPI_Finalize(); // finalizar el entorno de mpi

        return 0;
}
