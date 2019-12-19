#include<stdio.h>
#include <time.h>
#define N 10


int check_duplication(int list_A[], int max_index, int elem, int index){

    for(; index < max_index; index++){
	if(list_A[index] == elem){
	    return index;
	}else if(list_A[index] > elem){
	    break;
	}
    }
    return -index;
}


int main(void){
    
    int list_A[N] = {1, 3, 5, 10, 14, 17, 19, 22, 30, 38};
    int list_B[N] = {4, 5, 8, 9, 10, 19, 20, 22, 29, 30};
    
    int num = 10000000;
    
    clock_t clk_start, clk_end;
    clk_start = clock();
    
    int list_dup[N] = {};
    
    for(int i=0; i<num; i++){
	
	int count = 0;
	int a = 0;
	int b = 0;
	
	for(;b<N;b++){
	    a = check_duplication(list_A, N, list_B[b], a);
	    if(a<0){
		a *= -1;
	    }else{
		list_dup[count] = list_A[a];
		count++;
	    }
	}
    }
    clk_end = clock();
    printf("cpu = %11.6f [sec]\n", (double) (clk_end-clk_start)/CLOCKS_PER_SEC);

    clk_start = clock();

    for(int i=0; i<num; i++){
	
	int count = 0;
	int a = 0;
	int b = 0;
	
	for(;b<N;b++){
	    for(;a<N;a++){
		if(list_A[a]==list_B[b]){
		    list_dup[count] = list_A[a];
		    count++;
		}
	    }
	}
    }
    clk_end = clock();
    printf("cpu = %11.6f [sec]\n", (double) (clk_end-clk_start)/CLOCKS_PER_SEC);
    
    for(int k=0;k<N;k++){
	if(list_dup[k]==0){
	    break;
	}
	printf("%d\n", list_dup[k]);
    }
    return 0;
}
