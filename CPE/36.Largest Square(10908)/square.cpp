#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,M,N,Q;
    int r,c;
    int i,j,k,l;
    int flag=0,round;
    char array[100][100];

    scanf("%d",&T);
    for(i=0; i<T; i++)
    {
        scanf("%d%d%d",&M,&N,&Q);
        printf("%d %d %d\n",M,N,Q);
        for(j=0; j<M; j++)
        {
            for(k=0; k<N; k++)
            {
                scanf(" %c",&(array[j][k]));    //eliminate space
            }
        }
        for(l=0; l<Q; l++)
        {
            scanf("%d%d",&r,&c);    //center point
            for(round=1; flag==0 && r+round<M && c+round<N && r-round>=0 && c-round>=0; round++)
            {
                for(j=r-round; j<=r+round; j++)
                {
                    for(k=c-round; k<=c+round; k++)
                    {
                        if(array[r][c]!=array[j][k])       //check whether the beside points are the same as the center point
                        {
                            flag=1;
                        }
                    }
                }
            }
            if(flag==1)
            {
                printf("%d", (round-1) * 2 - 1);
            }
            else
            {
                printf("%d", round * 2 - 1);
            }
            if ((i != T - 1) || (l != Q - 1))   //there is no \n in the last row
                printf("\n");
            flag=0;
        }

    }

    return 0;
}
