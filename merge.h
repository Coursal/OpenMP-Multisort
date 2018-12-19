#ifndef _MERGEH_
#define _MERGEH_

#include <string.h>     //for memcpy()

//compare function for qsort()
int compare_function(const void *a, const void *b)
{
        return (*(int *)a - *(int *)b );
}

void merge(int *X, int N, int *temp)
{
        int i = 0;
        int j = N/2;
        int k = 0;

        while (i<N/2 && j<N)
        {
                if (X[i] < X[j])
                {
                        temp[k] = X[i];
                        i++;
                }
                else
                {
                        temp[k] = X[j];
                        j++;
                }

                k++;
        }

        while (i<N/2)   //finishing up the lower half
        {
                temp[k] = X[i];
                i++;
                k++;
        }

        while (j<N)     //finishing up the upper half
        {
                temp[k] = X[j];
                j++;
                k++;
        }

        //making sure no element was left out of order
        qsort(&temp[0], N, sizeof(int), compare_function);

        memcpy(X, temp, N*sizeof(int));
}

#endif
