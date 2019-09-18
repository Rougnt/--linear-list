#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
typedef struct 
{	//�˽ṹ��Ϊ���ĸ���Ԫ�أ��У�
	int number;//���
	char name[10];//����
	int score;//����

}form;
typedef struct _list
{
	//�˽ṹ��Ϊ���ĸ������ԣ��������ڵĵ�ַ�����ǰ�����ݵ������������������
	form *list;//�洢�ռ��ַ
	int size;//��ǰ����	
	int MaxSize;//��󳤶�
}list;
form* malloc_init(int n)//�����ڴ�ռ�
{
	return (form*)malloc(n * sizeof(form));//����malloc�������ص���void���ͣ������Ҫǿ��ת����form*�ṹ��ָ�룬���ڴ洢form����ʼ��ַ
}
void init(list *l, int maxsize)//��ʼ��
{
	if (maxsize<0)//�ж��û�����ĳ����Ƿ�����
	{
		puts("���ȷǷ�!");
		exit(1);
	}
	l->MaxSize = maxsize;
	l->list = malloc_init(maxsize);
	if (!l->list)//��ֹ�޷������ڴ�
	{
		puts("�����ַʧ�ܣ�");
		exit(1);
	}
	l->size = 0;//��ʼ����ǰ����
	puts("��ʼ���ɹ���\n�����������");
	getch();
}
void adddat(list *l)
{
	int i;//forѭ����ѭ������
	char dat[10]; //����ת���ַ�����Ŀǰ�����ô�
	if (l->size>=l->MaxSize)//���жϵ�ǰ�ı�񳤶ȴ��ڵ��ڳ����ʼ��ʱ�û����õı�񳤶ȣ���ʼ����������ô��Ĵ洢�ռ䣩���ж�Ϊ�������
	{
		puts("����������޷����\n���س�����");
		getch();
	}
	else
	{

		//for (i = 0; l->list[i].number != -842150451; i++)//������񣬹�������Ϣ��  
		//{

		//}
		i = l->size; //��ǰ��񳤶ȸ���i������i����ʼ¼����Ϣ
		puts("���������");
		scanf("%d", &l->list[i].number);
		getchar();//��scanf��Ļس�����ֹ�޷���������
		puts("����������");
		gets(dat);
		strcpy(l->list[i].name, dat);
		puts("���������");
		scanf("%d", &l->list[i].score);
		l->size++;//��ĳ���+1
	}
	
}
int deletedata(list *l)
{
	//ɾ�������������û�����ĺ���ɾ������һ��
	int sea_num, i;
	puts("��Ҫɾ���ĺ�����ʲô");
	scanf("%d", &sea_num);
	for (i = 0; l->list[i].number != sea_num; i++)//ѭ�����������ж�����Ƿ����Ҫɾ�������
	{
		if (i==l->size)//��i�ڱ�ĵ�ǰ�������ʱ��֤���ҵ�ͷ����
		{
			puts("û���ҵ��ú���\n�����������");
			getch();
			return 0;
		}
	}
	//puts("��Ϣ���ҵ�");
	//ɾ����ֵ
	for ( ; i != l->MaxSize; i++)//����ʣ�µ�
	{
		l->list[i]= l->list[i + 1];//����һ������Ϣ���ϸ���
	}


	l->size--;//���ȼ�һ

	return 0;
}
void correctdata(list *l)
{
	int sea_num, i;
	char dat[10];//�����ݴ��ַ���
	puts("��Ҫ�޸ĵĺ���ʱʲô");
	scanf("%d", &sea_num);
	for (i = 0; l->list[i].number != sea_num; i++)//�ο�finddata����������ע��
	{
		if (i==l->size)
		{
			puts("û���ҵ��ú���\n�����������");
			getch();
			return 0;
		}
	}
	//��Ϣ���ҵ�

	//puts("�������µ����");
	//scanf("%d", &l->list[i].number);//����������Ϣ���и���
	puts("�������޸ĺ�����");
	getchar();//��ֹ�ϸ�scanf�������к�����س�
	gets(dat);
	strcpy(l->list[i].name, dat);
	puts("�������޸ĺ����");
	scanf("%d", &l->list[i].score);
}
int finddata(list *l)
{
	int sea_num,i;
	puts("��Ҫ�ҵĺ���ʱʲô");
	scanf("%d", &sea_num);
	for (i = 0; l->list[i].number != sea_num; i++)//ѭ�����������ж�����Ƿ����Ҫ���ҵ����
	{
		if (i==l->size)//��i��ֵ���ڱ��ǰ����ʱ��֤���Ѿ������굱ǰ��������ݵ���
		{
			puts("û���ҵ��ú���\n�����������");
			getch();
			return 0;
		}
	}
	puts("��Ϣ���ҵ�");
	//�����������
	printf("number:%d\n", l->list[i].number);
	printf("name:%s\n", l->list[i].name);
	printf("score:%d\n", l->list[i].score);
	puts("���س�����");
	getch();
	return 0;
}
void resortdata(list *l)
{
	//ð�ݷ�����
	int i, j;form temp;//������ʱ�洢��������һ�е�����
	//����forѭ����ÿ��ȡ��һ��Ԫ�ظ����������Ԫ�رȽ�
	//������Ԫ���ŵ����
	for (j = 0; j < l->size - 1; j++) {
		//��ѭ��һ�Σ����ź�һ�����������ں��棬
		//���ԱȽ�ǰ��n-j-1��Ԫ�ؼ���
		for (i = 0; i < l->size - j - 1; i++) {
			if (l->list[i].number > l->list[i + 1].number)//����Ž����ж�
			{
				temp = l->list[i];//������������һ�б�������
				l->list[i] = l->list[i + 1];
				l->list[i + 1] = temp;
			}
		}
	}
	puts("���������\n�����������");
	getch();
}
void printdata(list* l)
{
	int i;
	printf("����\t����\t����\n");// \tΪ�Ʊ� ���űȽ�����
	for (i = 0; i<l->size; i++)//������񣬹�������Ϣ��
	{
		
		printf("%d\t%s\t%d\n",l->list[i].number,l->list[i].name,l->list[i].score);//��ʽ�ַ����
	}
	puts("��ӡ�����\n�����������");
	getch();
}
int main()
{
	int n,choice;//nΪ������󳤶ȣ�choice���ڴ洢�û���ѡ
	list l;//������񣬼�������
	puts("���������Ա���");
	scanf("%d", &n);
	init(&l, n);//��l������ĵ�ַ�ͳ��ȴ�����ʼ�����������г�ʼ����Ҫ���ڴ����һ��������n���ṹ��Ŀռ䣬���ڴ洢��Ϣ��
	for (;;)
	{
		system("cls");//��ʹ��������ֹ��Ļ����
		puts("1.��������");
		puts("2.ɾ������");
		puts("3.�޸�����");
		puts("4.��������");
		puts("5.��������������");
		puts("6.��ӡ���");
		puts("0.�˳�����");
		puts("���������ѡ��");
		_flushall;//��ջ���������ֹ�������������ַ�
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
			puts("�����������������");
		}

	}

}