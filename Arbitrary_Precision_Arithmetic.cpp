//From:Poj1001

//Require��ʵ�ָ߾��ȵļ���
//Author:��xly
//Process:
//		1��ʹ��char����baseNumber���洢������int�ͱ���exponential(ָ��)���洢ָ��
//		2��ͨ��forѭ���ҵ�������С�����λ�ã�����ֵ��pointPlace
//		3����char�����е��ַ�ת���ɶ�Ӧ�����ֲ�����һһ��ֵ��int������
//		4������������ʱ���������飬
		
#include<iostream>
using namespace std;

int main()
{
	int exponential = 0;        //���ָ��
	char char_baseNumber[100] = {0};        //���ַ��ʹ��ָ��
	int int_baseNumber[100] = {0};         //���ַ�������ת���ɵ�����������
	int int_temp_baseNumber[100] = {0};     
	int int_result_baseNumber[100] = {0};
	int pointPlace = 0;         //���С�����λ��
	int arrStrlen = 0;         //����ĳ���
	int int_baseNumber_strlen = 0;         //���ַ�������ת���ɵ�����������ĳ���
	int i = 0;            //ѭ������
	int j = 0;            //ѭ������
	int b = 0;            //
	int k = 0;            //
	int a = 0;            //
	int c = 0;            //
	int d = 0;            //
	int e = 0;            // 

	while(cin>>char_baseNumber>>exponential)
	{
		arrStrlen = strlen(char_baseNumber);

		//��char�����е��ַ�ת���ɶ�Ӧ�����ֲ�����һһ��ֵ��int������,�Լ��ҵ�С���ĸ���
		for (i = 0, j = 0; i < arrStrlen; i++, j++)
		{
			if (char_baseNumber[i] == '.')
			{
				pointPlace = arrStrlen - i - 1;
				j--;
			}
			else
			{
				int_baseNumber[j] = char_baseNumber[i] - 48;
				int_baseNumber_strlen++;
			}
		}

		//���������鸳ֵһ����ʱ����
		for (i = 0,j = (100-int_baseNumber_strlen); i < int_baseNumber_strlen; i++, j++)
			int_temp_baseNumber[j] = int_baseNumber[i];

		a = exponential;
		if (a != 1)
		{
			a--;        //
			while(a--)
			{
				b = 99;
				for (i = (int_baseNumber_strlen - 1); i > -1; i--, b--)                  //int_baseNumber[]
					for (j = 99, k = b; j > (99-exponential * int_baseNumber_strlen); j--, k--)                 //int_temp_baseNumber[]
					{
						int_result_baseNumber[k] += int_temp_baseNumber[j] * int_baseNumber[i];
					}
				for (i = 99; i > (99-exponential * int_baseNumber_strlen); i--)
				{
					int_result_baseNumber[i-1] += (int_result_baseNumber[i]-int_result_baseNumber[i] % 10)/10;
					int_result_baseNumber[i] %= 10;
				}

				for (i = (99-exponential * int_baseNumber_strlen); i < 100; i++)
					int_temp_baseNumber[i] = int_result_baseNumber[i];
				if (a != 0)
				{
					for (i = 0; i < 100; i++)
					int_result_baseNumber[i] = 0;
				}
			}
		}
		else
		{
			for (i = 0; i < 100; i++)
			int_result_baseNumber[i] = int_temp_baseNumber[i];
		}
		
		//������õ�int�������������������С������ĳһλ���
		/*for (i = 0; i <100; i++)
		{
			if (i == 100-pointPlace*exponential)
				{
					cout<<"."<<int_result_baseNumber[i];
				}
			else
				cout<<int_result_baseNumber[i];
		}
		cout<<endl
		*/

		/*
		for (i = 0; i <100; i++)
		{
			
			if (i == 100-pointPlace*exponential)
			{
				cout<<"."<<int_result_baseNumber[i];
			}
			else
				cout<<int_result_baseNumber[i];
				

			
			if (int_result_baseNumber[i] == 0)
			{
				c++;
			}
			if (i == 100-pointPlace*exponential && c == i)
			{
				
				for (e = pointPlace*exponential; e > 0 ; e --)
				cout<<"0";
				d = 1;
			}
			if (((c != (i + 1)) || d == 1))
			{
				if (i == 100-pointPlace*exponential)
				{
					cout<<"."<<int_result_baseNumber[i];
				}
				else
					cout<<int_result_baseNumber[i];
			}
		}
		*/


		for (i = 0; i < 100; i ++)
		{
			if (int_result_baseNumber[i] != 0 )
			{
				c = i;
				break;
			}
		}
		for (i = 99; i > 0; i --)
		{
			if (int_result_baseNumber[i] != 0 )
			{
				d = i;
				break;
			}
		}

		if (c < 100-pointPlace*exponential)
		{
			for (i = c; i < (d + 1); i++)
			{
				if (i == 100-pointPlace*exponential)
					cout<<"."<<int_result_baseNumber[i];
				else
					cout<<int_result_baseNumber[i];
			}
		}
		else
		{
			for (i = (100-pointPlace*exponential - 1); i < (d + 1); i++)
			{
				if (i == 100-pointPlace*exponential)
					cout<<"."<<int_result_baseNumber[i];
				else
					cout<<int_result_baseNumber[i];


			}
		}
		//Ϊ�˵ڶ��������׼ȷ�ԣ��ֽ����б�����ֵΪ��ʼֵ
		for (i = 0; i < 100; i++)
		{
			int_result_baseNumber[i] = 0;
			int_baseNumber[i] = 0;
			int_temp_baseNumber[i] = 0;
			exponential = 0;        
		}
		pointPlace = 0;
		arrStrlen = 0;
		int_baseNumber_strlen = 0;
		i = 0;
		j = 0;
		b = 0;
		k = 0;
		a = 0;
		c = 0;
		d = 0;
		cout<<endl;
	}
	return 0;
}