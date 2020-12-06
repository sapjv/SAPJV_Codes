// p is prime
int jacobi(int n, int p)
{
	int legendre = 1;
	n = n % p;
	
	if(n==0)
	{
		legendre = 0;
		return legendre;
	}
	
	if(n%p == 0)
	{
		legendre = 0;
		return legendre;
	}
	
	if(n<0)
	{
		n = -1*n;
		if((p%4)==3)
		{
			legendre = -1;
		}
	}
	
	int count = 0;
	while(n%2==0)
	{
		n = n/2;
		count = 1 - count;
	}
		
	if((count*(p*p-1))%16 == 8) 
		legendre = -1*legendre;

	while(n>1)
	{
		if(((n-1)*(p-1))%8==4)
			legendre = -1*legendre;
		
		int temp = n;
		n = p%n;
		p = temp;
		
		count = 0;
		while(n%2==0)
		{
			n = n/2;
			count = 1-count;
		}
		if((count*(p*p-1))%16 == 8) 
			legendre = -1*legendre;
	}

	return legendre;
}