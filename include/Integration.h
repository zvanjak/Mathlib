#define	FUNC_INT(X) ((*func)(x))

template < class T > T	trapzd( T (* func) (T), T a, T b, int n )
{
/*
		Funkcija raèuna n-ti korak proširenog trapezoidalnog pravila
		
		n - broj toèaka koji se koristi kod inteprolacije unutar intervala
*/
	T			x=0, tnm, sum, del;
	static T	s;
	int			it, j;

	if( n == 1 )
		return (s=0.5*(b-a)*(FUNC_INT(a)+FUNC_INT(b)));
	else
	{
		for( it=1,j=1; j<n-1; j++ )
			it <<=1;

		tnm = it;
		del = (b-a)/tnm;
		x = a+0.5*del;
		
		for( sum=0.0, j=1; j<=it; j++, x+=del )
			sum +=FUNC_INT(x);

		s=0.5 * (s+(b-a)*sum/tnm);
		return s;
	}
}

#define	NINTEGR_EPS		1.0e-5f
#define	JMAX					20

template < class T > T	qtrap(T (* func) (T), T a, T b )
{
/*
		Integrira funkciju 'func' koristeæi trapezoidalno pravilo

		NINETGR_EPS - željena relativna toènost
		JMAX - max. broj koraka
*/
	int			j;
	T	s, olds;


	olds = T(-1.e30f);
	for( j=1; j<=JMAX; j++ )
	{
		s = trapzd(func,a,b,j);
		if( fabs(s-olds) < NINTEGR_EPS*fabs(olds) )
			return s;
		if( s == 0.0 && olds == 0.0 && j > 6 )
			return s;
		olds = s;
	}

	printf("To many steps in NIntegrate !!!");

	return T();

}

template double		trapzd<double> ( double (*)(double), double, double, int );

template double		qtrap<double> ( double (*)(double), double, double );