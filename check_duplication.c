#include<stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000 // 配列のサイズ
#define NUM 10 // 試行回数
#define STEP_MIN 1
#define STEP_MAX 20

int check_duplication(int list_A[], int max_index, int elem, int *index){

    int i = *(index);
    for(; i < max_index; i++){
	if(list_A[i] > elem){
	    *(index)=i;
	    return -1;
	}else if(list_A[i] == elem){
	    *(index)=i;
	    return 1;
	}
    }
    return -1;
}


int main(void){
    
    int list_A[N] = {0};
    int list_B[N] = {0};

    int rnd_A = 0;
    int rnd_B = 0;

    // ソート済み配列の生成
    int count = 0;
    for(int i=0; i<N; i++){
	rnd_A += rand() % (STEP_MAX - STEP_MIN) + STEP_MIN;
	rnd_B += rand() % (STEP_MAX - STEP_MIN) + STEP_MIN;
	list_A[count] = rnd_A;
	list_B[count] = rnd_B;
	count++;
	//printf("%d\t%d\n", rnd_A, rnd_B);
    }
    
    clock_t clk_start, clk_end;
    clk_start = clock();
    
    int list_dup[N] = {};
    
    for(int i=0; i<NUM; i++){
	
	int count = 0;
	int a = 0;
	int b = 0;
	int bool_dup = 0;
	
	for(;b<N;b++){
	    bool_dup = check_duplication(list_A, N, list_B[b], &a);
	    if(bool_dup == 1){
		list_dup[count] = list_A[a];
		count++;
		a++;
	    }
	}
    }
    clk_end = clock();
    printf("[proposal] elapsed time: %11.6f [sec]\n",
	   (double) (clk_end-clk_start)/CLOCKS_PER_SEC);
    
    clk_start = clock();

    for(int i=0; i<NUM; i++){
	
	int count = 0;
	
	for(int b=0; b<N; b++){
	    for(int a=0; a<N; a++){
		if(list_A[a]==list_B[b]){
     		    list_dup[count] = list_A[a];
		    count++;
		}
	    }
	}
    }
    clk_end = clock();
    printf("[baseline] elapsed time: %11.6f [sec]\n",
	   (double) (clk_end-clk_start)/CLOCKS_PER_SEC);

    // dup配列の確認
    /*
    for(int k=0;k<N;k++){
	if(list_dup[k]==0){
	    break;
	}
	printf("%d\n", list_dup[k]);
    }
    return 0;
    */
}

// N=1000, NUM=10
// [proposal] elapsed time:    0.000130 [sec]
// [baseline] elapsed time:    0.015620 [sec]

// N=10000, NUM=10
// [proposal] elapsed time:    0.001676 [sec]
// [baseline] elapsed time:    1.453348 [sec]

// proposal O(N)
// baseline O(N^2)
