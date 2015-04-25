 #include<iostream>
using namespace std;
#include   <stdio.h>   
#include   <conio.h>   
#include   <math.h>  
#define QUEENS 8 //改变QUEENS的值可以设置棋盘
int   iCount=0;    //!记录解的序号的全局变量。  
int   Site[QUEENS];   //!记录皇后在各列上的放置位置的全局数组。
void Queen(int n);   //!递归求解的函数。
void Output();   //!输出一个解。
int IsValid(int n);   //!判断第n个皇后放上去之后，是否有冲突。
/*----------------------------Main：主函数。----------------------------*/  

void main()   
{   
   
Queen(0);         //!从第0行开始递归试探。
//getch(); 
system("pause"); //!按任意键返回。
}  

/*-----------------Queen：递归放置第n个皇后，程序的核心!----------------*/   
void Queen(int n)   
{   
int i;   
    

if(n==QUEENS)            //!参数n从0开始，等于8时便试出了一个解，将它输出并回溯。
{ 
  
   Output(); 
   return; 
}   
    

for(i=1;i<=QUEENS;i++)   //!n还没到8，在第n行的各个列上依次试探。
{   
   Site[n]=i;               //!在该行的第i列上放置皇后。 
  
   if(IsValid(n)) //!如果放置没有冲突，就开始下一行的试探。
    Queen(n+1);   
}   
}  
/*------IsValid：判断第n个皇后放上去之后，是否合法，即是否无冲突。------*/   
int IsValid(int n)   
{   
int i;   
    

for(i=0;i<n;i++)          //!将第n个皇后的位置依次于前面n－1个皇后的位置比较。
{   
  
   if(Site[i]==Site[n])      //!两个皇后在同一列上，返回0。 
    return 0;   
  
  
   if(abs(Site[i]-Site[n])==(n-i))   //!两个皇后在同一对角线上，返回0。 
    return 0;   
}   
    
    
return 1;           //!没有冲突，返回1。 
}  

/*------------Output：输出一个解，即一种没有冲突的放置方案。------------*/   
void Output()   
{   
int i;   
    int j;
int n;
cout<<"输出的结果为：(数字结果显示为每一行的第几列)"<<endl;
cout<< endl;
    cout<<"No."<<++iCount<<" 解法"<<"      ";
    for(i=0;i<QUEENS; i++)        //!依次输出各个行上的皇后的位置，即所在的列数。 
   cout<<Site[i];
   
cout<< endl;
cout<< endl;
cout<<"按任意键输出图形";
getch();
cout<< endl;
cout<< endl;
for(i=0;i<QUEENS;i++)
{   
     {n=Site[i];
     for(j=1;j<=QUEENS;j++)
        if(j==n)
        cout<<"☆"<<" ";
        else cout<<"■"<<" ";
      }
cout<<endl;
      } 
      cout<< endl;
      system("pause");
      system("cls");
}
