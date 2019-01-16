//13 Polynomials
#include <stdio.h>
#include <stdlib.h>
//poly[0].cof - number of terms // poly[i].cof - coefficient
//poly[0].exp - rhs		// poly[i].exp - exponent
struct poly
{
        int cof;
        int exp;
};

void get(struct poly p[])
{
        int i;
        for(i = 1; i <= p[0].cof; i++)
        {
        	printf("Element %d of %d :\n", i, p[0].cof);
			printf("Coefficient : ");
            scanf("%d", &p[i].cof);
			printf("Exponent : ");
            scanf("%d", &p[i].exp);
			printf("\n");
        }
        p[0].exp = 23; //x-23, a-1, z-26
        printf("\n");
        return;
}

void add(struct poly a[], struct poly b[], struct poly sum[])
{
	int i = 0, j = 0, k = 0;
	sum[0].exp = 23;//x
	//assuming polynomials have same number of terms
    while(i <= a[0].cof && j <= b[0].cof)
    {
		if(a[i].exp == b[j].exp)
		{
			sum[k].cof = a[i].cof + b[j].cof;
			sum[k].exp = a[i].exp;
			i++, j++, k++;
		}
		//else exponent not present in b[]
		else if(a[i].exp > b[j].exp)
		{
			sum[k].cof = a[i].cof;
			sum[k].exp = a[i].exp;
			i++, k++;
		}
		//else exponent not present in a[]
		else if(a[i].exp < b[j].exp)
		{
			sum[k].cof = b[j].cof;
			sum[k].exp = b[j].exp;
			j++, k++;
		}
    }
	sum[0].cof = k;
	return;
}

void show(struct poly p[])
{
        int i;
        for(i = 1; i <= p[0].cof; i++)
        {
			if(p[i].cof != 0 && p[i].exp != 0)
			{
            	printf(" %d", p[i].cof);
            	printf(" x^ ");
            	printf("%d ", p[i].exp);
				printf("\t");
			}
        }
        printf("\n");
        return;

}

int main(void)
{
        system("clear");
        printf("13 Polynomials\n\n");
        unsigned int s1, s2;

        printf("Size of polynomial a: ");
        scanf("%u", &s1);
        
		printf("Size of polynomial b: ");
        scanf("%u", &s2);

        struct poly a[s1], b[s2];
        a[0].cof = s1;
        b[0].cof = s2;
		//s3 = s1 > s2 ? s1 : s2;
		// shorthand for
		// if(s1 > s2)
		// 	s3 = s1;
		// else
		// 	s3 = s2;
		//s3 is so large for if the sum polynomial has more elements than either
		struct poly sum[s1+s2];

        printf("\nPloynomial a :\n");
        get(a);
        printf("\nPolynomial b :\n");
        get(b);

        add(a, b, sum);

        show(a);
        show(b);
printf("+ _____________________________________________________________________________\n");
        show(sum);

        return(0);
}
