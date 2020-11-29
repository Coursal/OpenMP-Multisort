#ifndef _MERGEH_
#define _MERGEH_

//compare function for qsort() to be used in multisort()
int compare_function(const void *a, const void *b)
{
        return (*(int *)a - *(int *)b );
}

void merge(int *X, int *X_size, int *temp, int *temp_size, int *result)
{
        int i = 0;

        while(X <= X_size && temp <= temp_size)
        {
                if((*X) < (*temp))
                {
                        result[i++] = *X;
                        X++;
                }
                else
                {
                        result[i++] = *temp;
                        temp++;
                }
        }

        while (X <= X_size)   //finishing up the lower half
        {
                result[i++] = *X;
                X++;
        }

        while (j<N)     //finishing up the upper half
        {
                result[k] = *temp;
                temp++;
        }
}

#endif
