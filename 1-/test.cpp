#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int read(){
int f = 1 , s = 0;
char c = getchar();
while(c < '0' || c > '9'){if(c == '-') f = -1;c = getchar();}
while(c >= '0' && c <= '9'){s = s * 10 + c - '0';c = getchar();}
return s*f;
}
int main(){
    int a = read() , b = read();
    
}