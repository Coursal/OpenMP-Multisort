#ifndef _MULTISORTH_
#define _MULTISORTH_

#include <omp.h>

#include "merge.h"      //for merge() and compare_function used in qsort()

void multisort(int *array, int *space, int N)
{
        int quarter = N/4;

        if(quarter<4)  //if there are too few elements to work with threads, use quicksort
        {
                qsort(&array[0], N, sizeof(int), compare_function);
        }
        else
        {
                //split the input array to 4 subarrays
                #pragma omp task
                        multisort(&array[0], &space[0], quarter);
                #pragma omp task
                        multisort(&array[N/4], &space[N/4], quarter);
                #pragma omp task
                        multisort(&array[N/2], &space[N/2], quarter);
                #pragma omp task
                        multisort(&array[3*N/4], &space[3*N/4], quarter);

                #pragma omp taskwait

                //merge the 4 subarrays in couples
                #pragma omp task
                        merge(&array[0], N/2, &space[0]);
                #pragma omp task
                        merge(&array[N/2], N/2, &space[N/2]);

                #pragma omp taskwait

                //merge the couples together
                merge(&array[0], N, &space[0]);
        }
}

#endif
