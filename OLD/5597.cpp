#include <iostream>
int v[31];int main(){int i=0;for(;i<28;i++){int a;std::cin>>a;v[a]++;}for(i=1;i<31;i++)if(v[i]==0)std::cout<<i<<'\n';}