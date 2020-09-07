namespace ysys
{
	/*
		Name :���鼯ģ�� 
		Need :<cstdio> 
		Code by:��������
		Update_Date: 2020/8/5 ��������Ŀ 
		Update_Date: 2020/8/9 Ƕ�����ֿռ�,�����ĽṹΪ class ,���� Union ��������ֵ(int->void)
		Update_Date: 2020/8/9 ������������Ϊָ�룬������Ȱ水�Ⱥϲ��Ĳ��鼯������ԭ���鼯����Ϊ Union_Find_Size��
							  Union �������� Unity 
	*/
	# define reg register
	
	class Union_Find_Size//��ͨ���鼯 
	{
		private:
			int *F,*Size;
		
		public:
			Union_Find_Size(){}
		
			Union_Find_Size(const int n){F = new int [n + 5];Size = new int [n + 5];for(reg int i = 1; i <= n ; ++i) *(F+i) = i,*(Size+i) = 1;}
	
			inline int Father(const int x){return *(F+x);}
	
			inline int Find(int x)
			{
				int cur = x;
			
				while(*(F+cur) ^ cur) cur = *(F+cur);
		
				*(F+x) = cur;
		
				while(x ^ *(F+x)) *(F + (x = *(F+x))) = cur;
		
				return cur;
			}
	
			inline void Unity(int x,int y)
			{
				x = Find(x);y = Find(y);
				
				if(*(Size + x) < *(Size + y)) *(Size + y) += *(Size + x),*(F + x) = y;
				else *(Size + x) += *(Size + y),*(F + y) = x; 
			}
	};
	
	class Union_Find_Deep
	{
		private:
			int *F,*Deep;
		
		public:
			Union_Find_Deep(){}
		
			Union_Find_Deep(const int n){F = new int [n + 5];Deep = new int [n + 5];for(reg int i = 1; i <= n ; ++i) *(F+i) = i,*(Deep+i) = 1;}
	
			inline int Father(const int x){return *(F+x);}
	
			inline int Find(int x)
			{
				int cur = x;
			
				while(*(F+cur) ^ cur) cur = *(F+cur);
		
				*(F+x) = cur;
		
				while(x ^ *(F+x)) *(F + (x = *(F+x))) = cur;
		
				return cur;
			}
	
			inline void Unity(int x,int y)
			{
				x = Find(x);y = Find(y);
				
				if(*(Deep + x) <= *(Deep + y))
				{
					*(F + x)= y;
						
					if(*(Deep + x) == *(Deep + y)) ++*(Deep + y);
				}
				else *(F + y) = x;
			}
	};
	
	# undef reg
}

