#include<iostream>
#include<cstdio>
using namespace std;
int main(){
  int T;
  int N, P, h[105];
  int lose_day;
  while( scanf( "%d", &T ) != EOF ){
    for( int i = 0 ; i < T ; i++ ){
      scanf( "%d%d", &N, &P );
      for( int j = 0 ; j < P ; j++ )
        scanf( "%d", &h[j] );
      lose_day = 0;
      bool day[3700] = {0};
      for( int j = 0 ; j < P ; j++ )
        for( int k = h[j] ; k <= N ; k += h[j] )
          if( !day[k] && ((k-1) % 7 < 5) ){
            lose_day++;
            day[k] = 1;
          }
      printf( "%d\n", lose_day );
    }
  }
  return 0;
}
