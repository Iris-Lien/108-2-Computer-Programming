#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

// definitions
#define FOR(i,a,b) for( int i=(a),_n=(b); i<=_n; ++i )
#define clr(x,v) memset( x, v, sizeof(x) )

// declarations
char buf[100005];
int sl;

// functions
int toNum( char c )
{
    if( '0' <= c && c <= '9' )
        return c-'0';
    else if( 'A' <= c && c <= 'Z' )
        return c-'A'+10;
    else
        return c-'a'+36;
}

int mod( int r )
{
    static int s, ret, tmp;
    static bool neg;

    s = 0;
    neg = false;
    if( buf[0]=='-' )
        neg = true;
    if( buf[s]=='+' || buf[s]=='-' )
        ++s;

    ret = 0;
    for( ; s < sl; ++s )
    {
        tmp = toNum(buf[s]);
        if( neg )
            tmp = -tmp;
        ret += (tmp+r)%r;
        ret = (ret+r)%r;
    }

    return ret;
}

// main function
int main( void )
{
    int r;

    // input
    while( scanf( "%s", buf )== 1 )
    {
        // solve
        sl = strlen( buf );

        if( buf[0]=='+' || buf[0]=='-' )
            r = 2;
        else
            r = toNum( buf[0] )+1;

        FOR( i, 1, sl-1 ) r = max( r, toNum(buf[i])+1 );

        if( r == 1 )
            r = 2;
        for( ; r <= 62 && mod(r-1)!=0; ++r );

        if( r > 62 )
            puts("such number is impossible!");
        else
            printf( "%d\n", r );
    }

    return 0;
}
