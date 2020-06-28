#include"stdafx.h"
#include"w32.h"
 
int Fact(int n)
{
	int F = 1;
	int i;
	for (int i = 1; i <= n; i++)
	{
		F = F*i;
	}
	return F;
}
