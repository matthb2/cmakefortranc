#include <stdio.h>
#include <assert.h>
#include <FCMangle.h>
#define access_array FC_GLOBAL_(access_array,ACCESS_ARRAY)

float calculate_x()
{
	return 6.42;
}
#define COLMAJ3D(a,b,c,amax,bmax,cmax) a+amax*(b+bmax*c)
void access_array(double* array,int* boundx,int* boundy,int* boundz, int* lmax)
{
	int i,j,k,l=1;
	//printf("C!\n");
	for(i=0;i<*boundx;i++)
	{
		for(j=0;j<*boundy;j++)
		{
			for(k=0;k<*boundz;k++)
			{
				assert(
				  array[COLMAJ3D(i,j,k,*boundx,*boundy,*boundz)]
				  == l);
				//printf("%d\n",l);
				l++;
			}
		}
	}
	assert(l==*lmax);
}
