#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> matrix;

matrix add(matrix arr , matrix brr,int n, int sign = 1)
{
    matrix res(n,vector<int>(n,0));

    for(int i  = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            res[i][j] = arr[i][j] + sign * brr[i][j];
        }
    }
    return res;
}

matrix mult(matrix arr, matrix brr)
{
    int n = arr.size();
    matrix res(n,vector<int>(n,0));

    if(n == 1)
    {
        res[0][0] = arr[0][0] * brr[0][0];
        return res;
    }

    int nwsz = n / 2;

    matrix a11(nwsz,vector<int>(nwsz,0));
    matrix a12(nwsz,vector<int>(nwsz,0));
    matrix a21(nwsz,vector<int>(nwsz,0));
    matrix a22(nwsz,vector<int>(nwsz,0));
    matrix b11(nwsz,vector<int>(nwsz,0));
    matrix b12(nwsz,vector<int>(nwsz,0));
    matrix b21(nwsz,vector<int>(nwsz,0));
    matrix b22(nwsz,vector<int>(nwsz,0));

    for(int i = 0; i < nwsz; i++)
    {
        for(int j  = 0; j < nwsz; j++)
        {
            a11[i][j] = arr[i][j];
            a12[i][j] = arr[i][j + nwsz];
            a21[i][j] = arr[i + nwsz][j];
            a22[i][j] = arr[i + nwsz][j+nwsz];
            b11[i][j] = brr[i][j];
            b12[i][j] = brr[i][j + nwsz];
            b21[i][j] = brr[i + nwsz][j];
            b22[i][j] = brr[i + nwsz][j+nwsz];
        }
    }

    matrix m1 = mult(add(a11,a22,nwsz),add(b11,b22,nwsz));
    matrix m2 = mult(add(a21,a22,nwsz),b11);
    matrix m3 = mult(a11,add(b12,b22,nwsz,-1));
    matrix m4 = mult(a22,add(b21,b11,nwsz,-1));
    matrix m5 = mult(add(a11,a12,nwsz),b22);
    matrix m6 = mult(add(a21,a11,nwsz,-1),add(b11,b12,nwsz));
    matrix m7 = mult(add(a12,a22,nwsz,-1),add(b21,b22,nwsz));

    matrix c11 = add(add(m1,m4,nwsz) , add(m7,m5,nwsz,-1),nwsz);
    matrix c12 = add(m3,m5,nwsz);
    matrix c21 = add(m2,m4,nwsz);
    matrix c22 = add(add(m1,m3,nwsz) , add(m6,m2,nwsz,-1),nwsz);

    for(int i = 0; i < nwsz; i++)
    {
        for(int j = 0; j < nwsz; j++)
        {
            res[i][j] = c11[i][j];
            res[i][j +  nwsz] =  c12[i][j];
            res[i+nwsz][j] = c21[i][j];
            res[i+ nwsz][j + nwsz] = c22[i][j];
        }
    }

    return res;


}

int main ()
{
    matrix arr = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}
};

matrix brr = {
    {16, 15, 14, 13},
    {12, 11, 10, 9},
    {8, 7, 6, 5},
    {4, 3, 2, 1}
};


    matrix res = mult(arr,brr);

    for(int i = 0; i < res.size(); i++)
    {
        for(int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }



}
