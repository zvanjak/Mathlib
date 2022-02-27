#if !defined  __MML_MATRIX_OPERATIONS_H
#define __MML_MATRIX_OPERATIONS_H

#include "Matrix.h"
#include "VectorN.h"

#include <vector>

namespace MML
{
    class MatrixOp
    {
        public:
            static bool gaussj(Matrix &a, Matrix &b)
            {
                int i,icol,irow,j,k,l,ll;
                double big,dum,pivinv;

                int n=a.RowNum();
                int m=b.ColNum();
                std::vector<int> indxc(n),indxr(n),ipiv(n);
                for (j=0;j<n;j++) ipiv[j]=0;
                for (i=0;i<n;i++) {
                    big=0.0;
                    for (j=0;j<n;j++)
                        if (ipiv[j] != 1)
                            for (k=0;k<n;k++) {
                                if (ipiv[k] == 0) {
                                    if (fabs(a[j][k]) >= big) {
                                        big=fabs(a[j][k]);
                                        irow=j;
                                        icol=k;
                                    }
                                }
                            }
                    ++(ipiv[icol]);
                    if (irow != icol) {
                        for (l=0;l<n;l++) std::swap(a[irow][l],a[icol][l]);
                        for (l=0;l<m;l++) std::swap(b[irow][l],b[icol][l]);
                    }
                    indxr[i]=irow;
                    indxc[i]=icol;
                    if (a[icol][icol] == 0.0) 
                        return false;
                        //nrerror("gaussj: Singular Matrix");
                    
                    pivinv=1.0/a[icol][icol];
                    a[icol][icol]=1.0;
                    for (l=0;l<n;l++) a[icol][l] *= pivinv;
                    for (l=0;l<m;l++) b[icol][l] *= pivinv;
                    for (ll=0;ll<n;ll++)
                        if (ll != icol) {
                            dum=a[ll][icol];
                            a[ll][icol]=0.0;
                            for (l=0;l<n;l++) a[ll][l] -= a[icol][l]*dum;
                            for (l=0;l<m;l++) b[ll][l] -= b[icol][l]*dum;
                        }
                }
                for (l=n-1;l>=0;l--) {
                    if (indxr[l] != indxc[l])
                        for (k=0;k<n;k++)
                            std::swap(a[k][indxr[l]],a[k][indxc[l]]);
                }
                return true;
            }

            static bool ludcmp(Matrix &a, std::vector<int> &indx, double &d)
            {
                const double TINY=1.0e-20;
                int i,imax,j,k;
                double big,dum,sum,temp;

                int n=a.RowNum();
                VectorN vv(n);
                d=1.0;
                for (i=0;i<n;i++) {
                    big=0.0;
                    for (j=0;j<n;j++)
                        if ((temp=fabs(a[i][j])) > big) big=temp;
                    if (big == 0.0) 
                        //nrerror("Singular matrix in routine ludcmp");
                        return false;

                    vv[i]=1.0/big;
                }
                for (j=0;j<n;j++) {
                    for (i=0;i<j;i++) {
                        sum=a[i][j];
                        for (k=0;k<i;k++) sum -= a[i][k]*a[k][j];
                        a[i][j]=sum;
                    }
                    big=0.0;
                    for (i=j;i<n;i++) {
                        sum=a[i][j];
                        for (k=0;k<j;k++) sum -= a[i][k]*a[k][j];
                        a[i][j]=sum;
                        if ((dum=vv[i]*fabs(sum)) >= big) {
                            big=dum;
                            imax=i;
                        }
                    }
                    if (j != imax) {
                        for (k=0;k<n;k++) {
                            dum=a[imax][k];
                            a[imax][k]=a[j][k];
                            a[j][k]=dum;
                        }
                        d = -d;
                        vv[imax]=vv[j];
                    }
                    indx[j]=imax;
                    if (a[j][j] == 0.0) a[j][j]=TINY;
                    if (j != n-1) {
                        dum=1.0/(a[j][j]);
                        for (i=j+1;i<n;i++) a[i][j] *= dum;
                    }
                }
                return true;
            }

            static void lubksb(Matrix &a, std::vector<int> &indx, VectorN &b)
            {
                int i,ii=0,ip,j;
                double sum;

                int n=a.RowNum();
                for (i=0;i<n;i++) {
                    ip=indx[i];
                    sum=b[ip];
                    b[ip]=b[i];
                    if (ii != 0)
                        for (j=ii-1;j<i;j++) sum -= a[i][j]*b[j];
                    else if (sum != 0.0)
                        ii=i+1;
                    b[i]=sum;
                }
                for (i=n-1;i>=0;i--) {
                    sum=b[i];
                    for (j=i+1;j<n;j++) sum -= a[i][j]*b[j];
                    b[i]=sum/a[i][i];
                }
            }

            static bool InvertMatrix(Matrix &a, Matrix &out)
            {
                int N = a.RowNum();

                VectorN col(N);
                std::vector<int> indx(N);
                double d = 0.0;

                ludcmp(a,indx,d);                // Decompose the matrix just once.
                for(int j=0;j<N;j++) {                 // Find inverse by columns.
                    for(int i=0;i<N;i++) 
                        col[i]=0.0;
                col[j]=1.0;
                lubksb(a,indx,col);
                for(int i=0;i<N;i++) 
                    out[i][j]=col[i];
                }
                return true;
            }

            static int LUDecomp( Matrix &a, int *indx, double *d )
            {
                return 0;
            }
            static void	LUBackSubst( Matrix &a, int *indx, VectorN &b )
            {

            }
    };
}

#endif