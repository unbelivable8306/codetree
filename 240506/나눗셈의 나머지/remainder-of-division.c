#include <stdio.h>

int main(){
	int a, b, i, sum[100]={0}, arr[100]={0}, suum=0;
	scanf("%d %d", &a, &b);
	
	i=0;
	while(1)
	{
		if(a <= 0){
			break;
		}
		sum[i] = a % b;
		a /= b;
		arr[sum[i]]++;
		i++;
	}

    for (i=0;i<=9;i++)
        suum += arr[i] * arr[i];
	
	printf("%d", suum);
	return 0;
}