#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argn, char **args)
{
        int rank , size; // nombre del proceso y numero de procesos
        int len; // numero de nodos
        char hostname[MPI_MAX_PROCESSOR_NAME];

        MPI_Init(&argn,&args); // inicializar el entorno de mpi

        MPI_Comm_rank(MPI_COMM_WORLD, &rank); // numero de proceo
        MPI_Comm_size(MPI_COMM_WORLD, &size); // numero total de procesos

        MPI_Get_processor_name(hostname, &len); // recuperar nombre del proceso

        printf("Hola mundo soy el proceso %i de %i en %s\n", rank, size, hostname);

        MPI_Finalize(); // finalizar el entorno de mpi

        return 0;
}
