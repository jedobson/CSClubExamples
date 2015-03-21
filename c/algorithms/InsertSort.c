#include <stdio.h>
void insertionSort(int ar_size, int *  ar) {

          int j = 0;
          for(j=1; j< ar_size; j++)
          {
              int key = ar[j];
              int k = j-1;
                                          
              while(k >= 0 && ar[k] > key)
              {
                  ar[k+1] = ar[k];
                  k=k-1;
              }
              int val;
                                                              
              ar[k+1] = key;
              for( val=0; val < ar_size; val++)
              {
                  printf("%d(number %d) ", ar[val], val);
              }
              printf("\n");
            
          }
              
             

}
int main(void) {
     
     int _ar_size;
     scanf("%d", &_ar_size);
     int _ar[_ar_size], _ar_i;
     for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
          scanf("%d", &_ar[_ar_i]); 
     }

     insertionSort(_ar_size, _ar);
        
        return 0;
}

