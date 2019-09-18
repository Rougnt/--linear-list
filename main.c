#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
typedef struct 
{	//此结构体为表格的各种元素（列）
	int number;//序号
	char name[10];//姓名
	int score;//分数

}form;
typedef struct _list
{
	//此结构体为表格的各种属性，包括存在的地址，表格当前有数据的行数，表格的最大行数
	form *list;//存储空间基址
	int size;//当前长度	
	int MaxSize;//最大长度
}list;
form* malloc_init(int n)//分配内存空间
{
	return (form*)malloc(n * sizeof(form));//由于malloc函数返回的是void类型，因此需要强制转换成form*结构体指针，用于存储form的起始地址
}
void init(list *l, int maxsize)//初始化
{
	if (maxsize<0)//判断用户输入的长度是否正常
	{
		puts("长度非法!");
		exit(1);
	}
	l->MaxSize = maxsize;
	l->list = malloc_init(maxsize);
	if (!l->list)//防止无法分配内存
	{
		puts("分配地址失败！");
		exit(1);
	}
	l->size = 0;//初始化当前长度
	puts("初始化成功！\n按任意键继续");
	getch();
}
void adddat(list *l)
{
	int i;//for循环的循环变量
	char dat[10]; //用于转存字符串，目前暂无用处
	if (l->size>=l->MaxSize)//当判断当前的表格长度大于等于程序初始化时用户设置的表格长度（初始化分配了那么多的存储空间），判定为表格已满
	{
		puts("表格已满，无法添加\n按回车继续");
		getch();
	}
	else
	{

		//for (i = 0; l->list[i].number != -842150451; i++)//遍历表格，过掉有信息的  
		//{

		//}
		i = l->size; //当前表格长度赋给i，即从i个开始录入信息
		puts("请输入号码");
		scanf("%d", &l->list[i].number);
		getchar();//读scanf后的回车，防止无法输入姓名
		puts("请输入姓名");
		gets(dat);
		strcpy(l->list[i].name, dat);
		puts("请输入分数");
		scanf("%d", &l->list[i].score);
		l->size++;//表的长度+1
	}
	
}
int deletedata(list *l)
{
	//删除函数，按照用户输入的号码删除整个一行
	int sea_num, i;
	puts("你要删除的号码是什么");
	scanf("%d", &sea_num);
	for (i = 0; l->list[i].number != sea_num; i++)//循环的条件是判断序号是否等于要删除的序号
	{
		if (i==l->size)//当i于表的当前长度相等时，证明找到头儿了
		{
			puts("没有找到该号码\n按任意键返回");
			getch();
			return 0;
		}
	}
	//puts("信息已找到");
	//删除该值
	for ( ; i != l->MaxSize; i++)//遍历剩下的
	{
		l->list[i]= l->list[i + 1];//将下一个的信息向上覆盖
	}


	l->size--;//表长度减一

	return 0;
}
void correctdata(list *l)
{
	int sea_num, i;
	char dat[10];//用于暂存字符串
	puts("你要修改的号码时什么");
	scanf("%d", &sea_num);
	for (i = 0; l->list[i].number != sea_num; i++)//参考finddata（）函数的注释
	{
		if (i==l->size)
		{
			puts("没有找到该号码\n按任意键返回");
			getch();
			return 0;
		}
	}
	//信息已找到

	//puts("请输入新的序号");
	//scanf("%d", &l->list[i].number);//重新输入信息进行覆盖
	puts("请输入修改后姓名");
	getchar();//防止上个scanf（）运行后残留回车
	gets(dat);
	strcpy(l->list[i].name, dat);
	puts("请输入修改后分数");
	scanf("%d", &l->list[i].score);
}
int finddata(list *l)
{
	int sea_num,i;
	puts("你要找的号码时什么");
	scanf("%d", &sea_num);
	for (i = 0; l->list[i].number != sea_num; i++)//循环的条件是判断序号是否等于要查找的序号
	{
		if (i==l->size)//当i的值等于表格当前长度时，证明已经查找完当前表格有数据的行
		{
			puts("没有找到该号码\n按任意键返回");
			getch();
			return 0;
		}
	}
	puts("信息已找到");
	//进行数据输出
	printf("number:%d\n", l->list[i].number);
	printf("name:%s\n", l->list[i].name);
	printf("score:%d\n", l->list[i].score);
	puts("按回车继续");
	getch();
	return 0;
}
void resortdata(list *l)
{
	//冒泡法排序
	int i, j;form temp;//用于临时存储的是整个一行的数据
	//两个for循环，每次取出一个元素跟数组的其他元素比较
	//将最大的元素排到最后。
	for (j = 0; j < l->size - 1; j++) {
		//外循环一次，就排好一个数，并放在后面，
		//所以比较前面n-j-1个元素即可
		for (i = 0; i < l->size - j - 1; i++) {
			if (l->list[i].number > l->list[i + 1].number)//对序号进行判断
			{
				temp = l->list[i];//交换的是整个一行表格的数据
				l->list[i] = l->list[i + 1];
				l->list[i + 1] = temp;
			}
		}
	}
	puts("排序已完成\n按任意键继续");
	getch();
}
void printdata(list* l)
{
	int i;
	printf("号码\t姓名\t分数\n");// \t为制表 看着比较整齐
	for (i = 0; i<l->size; i++)//遍历表格，过掉有信息的
	{
		
		printf("%d\t%s\t%d\n",l->list[i].number,l->list[i].name,l->list[i].score);//格式字符输出
	}
	puts("打印已完成\n按任意键继续");
	getch();
}
int main()
{
	int n,choice;//n为链表最大长度，choice用于存储用户所选
	list l;//声明表格，及其属性
	puts("请输入线性表长度");
	scanf("%d", &n);
	init(&l, n);//将l表自身的地址和长度传给初始化函数，进行初始化，要求内存分配一串连续的n个结构体的空间，用于存储信息。
	for (;;)
	{
		system("cls");//即使清屏，防止屏幕过长
		puts("1.增加数据");
		puts("2.删除数据");
		puts("3.修改数据");
		puts("4.查找数据");
		puts("5.按号码排序数据");
		puts("6.打印表格");
		puts("0.退出程序");
		puts("请输入你的选择");
		_flushall;//清空缓存区，防止读入其他意外字符
		scanf("%d", &choice);
		if (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6 || choice == 0)
		{
			switch (choice)
			{
			case 1:adddat(&l);break;
			case 2:deletedata(&l); break;
			case 3:correctdata(&l); break;
			case 4:finddata(&l); break;
			case 5:resortdata(&l); break;
			case 6:printdata(&l); break;
			case 0:
				return 0;
			}
		}
		else
		{
			puts("输入错误，请重新输入");
		}

	}

}