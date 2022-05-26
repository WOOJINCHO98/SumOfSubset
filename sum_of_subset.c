#include <stdio.h>
#include <stdbool.h> // 불 자료형 사용을 위함
int funCount =0;
int Weight = 13;
int item[7]={0,3,4,5,6,99,99};
char include[20];
bool promising(int i,int w, int total){
    bool value = (w+total>=Weight)&&(w==Weight||w+item[i+1]<=Weight);
    return value;
}

void sum_of_subsets(int i,int w, int total){
    funCount++;
    printf("sum_of_subsets 함수가 %d 번째 출력되었습니다.\n",funCount);
    printf("W%d 노드 확인중\n\n",i);
    int q;
    if (promising(i,w,total)){
                
        if (w == Weight)
        {
            printf("정답을 출력하는 부분입니다.\n");
            for(q=1;q<=4;q++){
                printf("|~%c~|",include[q]);
            }
            printf("\n\n");
        }
        else{
            include[i+1]='y';
            sum_of_subsets(i+1,w+item[i+1],total-item[i+1]);
            include[i+1]='n';
            sum_of_subsets(i+1,w,total);            
        }
    }

}



int main(void)
{
    printf("프로그램 시작\n");
    printf("합이 13인 부분집합을 구하는 프로그램 입니다.\n");
    sum_of_subsets(0,0,13);
    printf("프로그램 종료\n\n\n");

    return 0;
}