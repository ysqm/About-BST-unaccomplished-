namespace ysys
{
	/*
		Name :��״���� 
		Need :<cstdio> <cstring> 
		Code by:��������
		Update_Date: 2020/8/10   ��������Ŀ,����� TA ����
	*/
	
	namespace Tree_Arry
	{
		class TA
		{
			int *t;
			
			~TA(){}
			TA(const int n = 0){t = new int [n+5];memset(t,0,(sizeof int) * (n+5))}
			
			inline int lowbit(register const int x){return (x&(-x));}
			
			inline void updata(register int x,register const int data)
			{
				while(x <= n)
				{
					tr[x] += data; 
					x += (x & (-x));
				}
			}

			inline int getsum(register int x)
			{
				register int sum = 0;
				
				while(x)
				{
					sum += tr[x];
					x -= (x & (-x));
				}
				
				return sum;
			}
			
		};
	}
} 
