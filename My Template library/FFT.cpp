namespace FFT
{
	/*
		Name :���ٸ���Ҷ�任
		Need :<cmath> 
		Code by:��������
		Update_Date: 2020/8/? ��������Ŀ 
		Update_Date: 2020/8/9 Ƕ�����ֿռ�,������Complex�ṹΪ class , 
	*/
	
	# define cos std::cos
	# define sin std::sin 
	
	class Complex
	{   
		public:
 	   		double x,y;
	
    		Complex(const double x_=0,const double y_=0):x(x_),y(y_){}
	
   			inline Complex operator + (const Complex& b) const{return Complex(x+b.x,y+b.y);}
    		inline Complex operator - (const Complex& b) const{return Complex(x-b.x,y-b.y);}
    		inline Complex operator * (const Complex& b) const{return Complex(b.x*x-b.y*y,x*b.y+y*b.x);}
	};

	inline void Swap(Complex& a,Complex& b){Complex c = a;a = b;b = c;}

	# define reg register 

	const double Pi = cos(-1); 

	void FFT(Complex *A,const int *rev,const int Limit,const int Type)
	{
	
	
		for(reg int i = 1; i <= Limit ; ++i) if(rev[i] > i) Swap(A[i],A[rev[i]]);
	
		reg Complex Wn,W,x,y;
	
		for(reg int mid = 1; mid < Limit ; mid<<=1)
		{
			reg int Len = mid<<1;
		
			Wn = Complex(cos(Pi/mid),Type*sin(Pi/mid));
		
			for(reg int i = 0; i < Limit ; i += Len)
			{
				W = Complex(1,0);
			
				for(reg int j = 0; j < mid ; ++j)
				{
					x = A[i|j];y = W*A[i|j|mid];
					
					A[i|j] = x+y;
					A[i|j|mid] = x-y;
				
					W = W * Wn;
				}	
			}
		}
		if(Type == -1) for(reg int i = 0; i <= Limit ; ++i)/*{A[i].x = A[i].x/Limit;*/A[i].y = A[i].y/Limit;//}
	
	
	}

	void FFT_Pre(int *rev,const int Limit,const int L)
	{
		for(reg int i = 1; i <= Limit; ++i) rev[i] = (rev[i>>1]>>1) | ((i&1)<<L); 
	}

	# undef reg
}
