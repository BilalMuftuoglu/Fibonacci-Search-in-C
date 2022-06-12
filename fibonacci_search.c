#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAX 100000

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main(){
    
    srand(time(NULL));
    
    int i,j,n,A[MAX],x,fib1,fib2,fib3,offset,isFound,yN,worstCase=0;
    float counter=0;
    
    printf("Dizinin eleman sayisini giriniz: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        A[i] = rand();
    }
    
    //Fibonacci search algoritmasýnda  sýralý bir dizi gerektiðinden dolayý önce sýralýyoruz
    qsort(A, n , sizeof(int), cmpfunc);
    
    //Sýralý dizinin elemanlarýný ve sýralarýný görmek için printf
    for(i=0;i<n;i++){
        printf("%d: %d | ",i+1,A[i]);
    }
    
    printf("\n\nAramak istediginiz elemani giriniz: ");
    scanf("%d",&x);
    
    fib1=0;
    fib2=1;
    fib3=1;
    
    //Dizi boyutundan büyük veya eþit en küçük fibonacci sayýsýný bulma
    while(fib3<n){
        fib1=fib2;
        fib2=fib3;
        fib3=fib1+fib2;
    }
    
    offset=-1;//Dizide aradýðýmýz elemandan küçük olduðunu garantilediðimiz elemanýn indisi
    isFound=0;
    
    while(isFound==0 && fib3>1){
        
        //Dizi dýþýna çýkmamak için kontrol
        if(offset+fib1 <= n-1){
            i = offset + fib1;
        }else{
            i = n-1;
        }
        //Fibonacci sayýlarýný 1 küçültüyoruz
        if(A[i]<x){
            fib3 = fib2;
            fib2 = fib1;
            fib1 = fib3 - fib2;
            offset = i;
        }else if(A[i]>x){//Fibonacci sayýlarýný 2 küçültüyoruz
            fib3 = fib1;
            fib2 = fib2 - fib1;
            fib1 = fib3 - fib2;
        }else{
            isFound=1;
        }
        counter++;
    }
    
    if(isFound==1){
        printf("\nEleman %d. sirada bulundu.",i+1);
    }else if(fib2!=0 && A[offset+1]==x){
        //Son elemanýn kontrolü
        printf("\nEleman %d. sirada bulundu.",i+1);
    }else{
        printf("\nEleman bulunamadi.");
    }
    
    printf(" Time complexity: %.0f : ",counter);
    //Karmaþýklýk sayýsýný bar grafiðinde göstermek için biraz küçültüp yuvarlýyoruz
    counter = counter/3;
    counter = round(counter);
    for(i=0;i<counter;i++){
        printf("*");
    }
    
    do{
        printf("\n\nDizinin elemanlari arasinda karmasiklik karsilastirmasi ister misiniz? (1/0): ");
        scanf("%d",&yN);
    }while(yN != 1 && yN !=0);
    
    // Yukarda yapýlan iþlemlerin aynýsý tüm elemanlar için yapýlýr
    if(yN == 1){
        for(j=0;j<n;j++){
            x=A[j];
            fib1=0;
            fib2=1;
            fib3=1;
            while(fib3<n){
                fib1=fib2;
                fib2=fib3;
                fib3=fib1+fib2;
            }
            offset=-1;
            isFound=0;
            counter = 0;
            while(isFound==0 && fib3>1){
                if(offset+fib1 <= n-1){
                    i = offset + fib1;
                }else{
                    i = n-1;
                }
                if(A[i]<x){
                    fib3 = fib2;
                    fib2 = fib1;
                    fib1 = fib3 - fib2;
                    offset = i;
                }else if(A[i]>x){
                    fib3 = fib1;
                    fib2 = fib2 - fib1;
                    fib1 = fib3 - fib2;
                }else{
                    isFound=1;
                }
                counter++;
            }
            if(isFound==1){
                printf("\nEleman %d. sirada bulundu.",i+1);
            }else if(fib2!=0 && A[offset+1]==x){
                printf("\nEleman %d. sirada bulundu.",i+1);
            }else{
                printf("\nEleman bulunamadi.");
            }
            printf(" Time complexity: %.0f : ",counter);
            if(counter>worstCase){
                worstCase=counter;
            }
            counter = counter/3;
            counter = round(counter);
            for(i=0;i<counter;i++){
                printf("*");
            }   
            printf("\n");           
        }
        printf("\nWorst case: %d",worstCase);
    }
    return 0;
}

