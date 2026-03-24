#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argn, char **args)
{
        int rank , size; // nombre del proceso y numero de procesos
//      char hostname[];

        MPI_Init(&argn,&args); // inicializar el entorno de mpi

        MPI_Comm_rank(MPI_COMM_WORLD, &rank); // numero de proceo
        MPI_Comm_size(MPI_COMM_WORLD, &size); // numero total de procesos

        printf("HOla mundo soy el proceso %i de %i\n",rank,size);

        MPI_Finalize(); // finalizar el entorno de mpi

        return 0;
}