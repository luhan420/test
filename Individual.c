include<iostream.h>//数据流输入/输出
#include<iomanip.h>//参数化输入/输出
#include<stdlib.h>//定义杂项函数及内存分配函数
#include<stdio.h>//定义输入/输出函数


/*------------------------------------------------------*/
/*--------------方法一：递归法--------------------------*/
/*------------------------------------------------------*/
// static：   避免命名有冲突
//棋盘初始化时，空格的地方为*，放置皇后的地方为@ 
static char Queen[8][8]; 
static int a[8];    //数组a[i]：a[i]表示第i个皇后放置的列,i的范围：----8
static int b[15];  //主对角线数组
static int c[15];  //从对角线数组，根据程序的运行，去决定主从对角线是否放入皇后
static int iQueenNum=0;    //记录总的棋盘状态数
static int iNum=1;
void iQueen(int i);       //参数i代表行
void measure1()
{
	int iLine;            //横行
	int iColumn;          //纵行
    for(iLine=0;iLine<8;iLine++)
	{ 
    	a[iLine]=0;       //列标记初始化，表示无列冲突
	    for(iColumn=0;iColumn<8;iColumn++) 
			Queen[iLine][iColumn]='*'; 
	} 
	for(iLine=0;iLine<15;iLine++)     //主、从对角线标记初始化，表示没有冲突
		b[iLine]=c[iLine]=0; 
	iQueen(0);
};

void  iQueen(int i)                  //i为当前处理的行
{
	int   iColumn;
	for(iColumn=0;iColumn<8;iColumn++) 
    { 
		if(a[iColumn]==0&&b[i-iColumn+7]==0&&c[i+iColumn]==0)   //如果无冲突
		{ 
			Queen[i][iColumn]='@';   //放皇后
			a[iColumn]=1;            //标记，下一次该列上不能放皇后
            b[i-iColumn+7]=1;     //标记，下一次该主对角线上不能放皇后
            c[i+iColumn]=1;       //标记，下一次该从对角线上不能放皇后
			if(i<7)
				iQueen(i+1);        //如果行还没有遍历(沿着某条搜索路线，依次对树中每个结点均做一次且仅做一次访问)完，进入下一行
			else                  //否则输出
			{ 
				int iLine;        //输出棋盘状态
				int iColumn;
				cout<<"(递归法)皇后摆放方式的第"<<iNum<<"种情况为："<<endl; 
				for(iLine=0;iLine<8;iLine++) 
				{ 
					for(iColumn=0;iColumn<8;iColumn++) 
						cout<<setw(2)<<Queen[iLine][iColumn];
				cout<<endl;
                }
				cout<<iNum<<":  ";
				for(iLine=0;iLine<8;iLine++) 
				{ 
					for(iColumn=0;iColumn<8;iColumn++) 
					{
						if(Queen[iLine][iColumn]=='@')
							cout<<"("<<iLine+1<<','<<iColumn+1<<")";
					}
                }
				cout<<endl;
				system("pause>nul");         //从程序里调用pause命令,一个结果一个结果地看
				iNum++;	
				cout<<endl;
			}
//如果前次的皇后放置导致后面的放置无论如何都不能满足要求，则回溯，重新标记
			Queen[i][iColumn]='*'; 
			a[iColumn]=0; 
			b[i-iColumn+7]=0; 
			c[i+iColumn]=0; 
		}//   if   ends	
	}

}


/*----------------------------------------------------------*/
/*----------------------方法二：运用类----------------------*/
/*----------------------------------------------------------*/
//自定义一个类：CQueen
class cQueen {
	 int aQueen[8];        //可以在类外访问的私有成员(默认)
	 int sum; 
public:                    //只能被该类的成员函数所访问的公有成员
	cQueen();              //构造函数：确保每个对象正确地初始化
	int judge(int x,int y); 
	void show(); 
	void step(); 
}; 

cQueen::cQueen()//通过构造函数对aQueen[1---8]初始化
{ 
	sum=0; 
	for(int i=0;i<8;i++) 
		aQueen[i]=0; 
} 

int cQueen::judge(int x,int y) //判断皇后摆放位置是否有冲突，如果没有冲突，则返回；如果有冲突，则返回
{ 
	for(int i=0;i<x;i++) 
		if(aQueen[i]==y || aQueen[i]+x-i==y || aQueen[i]-x+i==y)
			return 0; 
		return 1; 
} 

void cQueen::step() //一步一步进行查找摆放
{ 
	int x=0,y=0;//标记皇后所在键盘位置，x代表列，y代表行（相当于坐标）
	while(aQueen[0]<8) 
	{ 
		while(y<8) 
		{ 
			if(judge(x,y))          //调用类函数judge(x,y),如果aQueen[1---8]都已经标记，则执行该语句
			{ 
				aQueen[x]=y;        //摆放皇后
				x++;                //进行下一列时
				y=0;                //y进行重置
			} 
			else                    //否则，进入下一行
				y++;
		}                           //当执行到最后一行时，继续执行下一个if语句
		if(y==8&&x!=8)              //最后一行，从第一列开始
		{
			if(aQueen[--x]!=7)      
				y=++aQueen[x]; 
			else if(aQueen[0]!=7) 
				y=++aQueen[--x]; 
			else 
				aQueen[0]=8; 
		} 
		if(x==8)                   //最后一列
		{ 
			show(); //x,y从至结束,大循环结束
			if(aQueen[--x]!=7) 
				y=++aQueen[x]; 
			else
				y=++aQueen[--x]; 
		} 
	} 
}

void cQueen::show()//输出棋盘状态
{ 	
	cout<<"(非递归法)皇后摆放方式的第"<<++sum<<"种情况："<<endl;  
	for(int i=0;i<8;i++) //输出八皇后的各种状态，有皇后的位置用@ 表示，没有皇后的位置用* 表示
	{  
		for(int j=0;j<aQueen[i];j++) 
			cout<<setw(2)<<"*"; 
		cout<<setw(2)<<"@"; 
		for(j++;j<8;j++) 
			cout<<setw(2)<<"*"; 
		cout<<endl;
	}
	cout<<sum<<":  ";
	for(int k=0;k<8;k++) 
		cout<<'('<<k+1<<','<<aQueen[k]+1<<")";	
	cout<<endl<<endl;	
//	system("pause");//从程序里调用pause命令,一个结果一个结果地看
} 

void measure2() 
{ 
	cQueen a; 
	a.step(); 
} 


/*--------------------------------------------------------------*/
/*------------------方法三:穷举法---------------------------*/
/*--------------------------------------------------------------*/
//使用优化后的穷举法,用递归实现N层穷举,每调用一次穷举函数则穷举一列
const int LINE=8;//const定义整新型常量LINE和ROW(8*8的棋盘)
const int ROW=8;
void queen(int row,int rec[]);//row为当前穷举的列，rec[]记录已穷举的信息，rec[3]=2代表(3,2)已放下棋子
bool isqueen(int i,int rec[],int row);//判断当前i是否与已放下的棋子能相互攻击
void printqueen(int rec[]);//输出符合条件的棋子摆放方式

void measure3()
{

	int rec[9]={0};//记录穷举信息数组
    queen(1,rec);//执行八皇后
	system("pause");
}

void queen(int row,int rec[])//八皇后函数
{
	int tmprec[ROW+1]={0};
//向下一列穷举传递信息时使用tmprec,不丢失rec的记录
	for(int i=1;i<=row;i++) tmprec[i]=rec[i];//复制数组
	if (row!=ROW)//不是最后一列时(第ROW列即为最后一列)
	{
		for (i=1;i<=ROW;i++)
		{
			if(isqueen(i,rec,row)) //i与已放下的棋子不能相互攻击时
			{
				tmprec[row]=i;
                queen(row+1,tmprec);//继续穷举下一列
			}
		}
	}
	else//最后一列时
		for (i=1;i<=ROW;i++)
			if(isqueen(i,rec,row))//i与已放下的棋子不能相互攻击时
			{
				tmprec[row]=i;
				printqueen(tmprec);//输出符合条件的棋子摆放方式
			}
}
bool isqueen(int i,int rec[],int row)//判断当前i是否与已放下的棋子能相互攻击
{//(row,i)即是此次穷举出来的棋子的坐标
	if (row==1) return 1;//第一列
	for(int j=1;j<row;j++)
	{
		if(rec[j]==i||rec[j]==i+row-j||rec[j]==i-row+j)//如果(有棋子在同一直线||有棋子在同一斜线)
			return 0;
	}
	return 1;
}
void printqueen(int rec[])//输出符合条件的棋子摆放方式
{
	char q[LINE+1][ROW+1]={'0'};
	static int num=1;//记录已输出符合条件的棋盘数量
	for (int i=1;i<=LINE;i++)
	{
		for (int j=1;j<=ROW;j++)
		{
			if(rec[i]!=j)
				q[i][j]='*';
			else
				q[i][j]='@';
		}
	}
			//将一维记录转换成LINE*ROW的矩阵，方便打印
			cout<<"(穷举法)皇后摆放方式第"<<num<<"种情况:"<<endl;//输出数量
			for (i=1;i<=ROW;i++)
			{
				for (int j=1;j<=ROW;j++) 
					cout<<setw(2)<<q[i][j];
				cout<<endl;
			}
			cout<<num<<":  ";
			for (i=1;i<=ROW;i++)
			{
				for (int j=1;j<=ROW;j++) 
					if (rec[i]==j)
						cout<<"("<<i<<','<<j<<")";
			}
			cout<<endl<<endl;
			num++;
		//	system("pause");
}  

void menu()   	//输出界面
{
	cout<<"\t"<<" _________________________________________ "<<endl;
	cout<<"\t"<<"‖----------------------------------------‖"<<endl;
	cout<<"\t"<<"‖                                        ‖"<<endl;
	cout<<"\t"<<"‖           八皇后问题                   ‖"<<endl;
	cout<<"\t"<<"‖        ====================            ‖"<<endl;
	cout<<"\t"<<"‖        1.方法一： 递归法               ‖"<<endl;
	cout<<"\t"<<"‖        2.方法二： 运用类               ‖"<<endl;
	cout<<"\t"<<"‖        3.方法三： 穷举法               ‖"<<endl; 
	cout<<"\t"<<"‖        0.后退                          ‖"<<endl;
	cout<<"\t"<<"‖                                        ‖"<<endl;
	cout<<"\t"<<"‖         请选择(1、2，或者0)：          ‖"<<endl;
   	cout<<"\t"<<"‖----------------------------------------‖"<<endl;
	cout<<"\t"<<"‖________________________________________‖"<<endl;
}

int main()//主函数
{
	for(;;)
	{
		menu();
	    cout<<endl;
	    cout<<"\t\t\t请从～中选择一个数：";
	    int number;
	    cin>>number;
	    switch(number)
		{
		case 1:  measure1();break;
	    case 2:  measure2();break;
	    case 3:  measure3();break;
	    case 0:  return 0;
	    default:
		   cout<<"抱歉，没有该选项，请重新作出选择!!"<<endl;
		}
	}
	return 0; 
}   
