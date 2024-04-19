#include <stdio.h>
#include <stdlib.h>


int main (void)
{
    int *list=malloc(3*sizeof(int));
    if (list==NULL)
    {
        return 1;
    }
    list[0]=1;
    list[1]=2;
    list[2]=3;

    int *tmp=realloc(list,4*(sizeof(int)));
    // now by using realloc instead of malloc both temp and list are pointing at same chunk of memory and tmp is only
    // created to check whether the os provides memory or not
    //if we use just list instead of tmp ,then in case of os fails to provide memory list becomes null and we will lose
    // access to old elements viz.,1,2,3.  
    if(tmp==NULL)
    {
        free(list);
        return 1;
    }
//no need beacuse of realloc
    // for (int i = 0; i < 3; i++)
    // {
    //     tmp[i]=list[i];
    // }
    list=tmp;

    // tmp[3]=4;
    list[3]=4;

  
    
    

    
    for (int i = 0; i < 4; i++)
    {
        printf(" %i ",list[i]);
    }
    
    free(list);

// free(tmp);
//tmp is essentially an alias for the reallocated memory that was previously pointed to by list.
//When you call free(list) at the end of the code, it properly deallocates the memory that was allocated by the initial malloc.
//However, if you also call free(tmp) at the end of the code, you would be attempting to free the same block of memory that was already deallocated by free(list).
    
    
}