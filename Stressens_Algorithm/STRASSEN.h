#define STRASSEN_H_

int n;
void strassen(int size,int a[][size], int b[][size], int c[][size]) 
{
    int new_size = floor(size/2);
    int m1[new_size][new_size], m2[new_size][new_size], m3[new_size][new_size], m4[new_size][new_size], m5[new_size][new_size], m6[new_size][new_size], m7[new_size][new_size];
    int a11[new_size][new_size], a12[new_size][new_size], a21[new_size][new_size], a22[new_size][new_size],b11[new_size][new_size],b12[new_size][new_size],b21[new_size][new_size],b22[new_size][new_size];
    int temp1[new_size][new_size],temp2[new_size][new_size];
    int  i, j;
  
    if(size >=2)
    {
        //Initializing a11,a12,a21,a22,b11,b12,b21,b22
        for(int i=0;i<new_size;i++)
        {
            for(int j=0;j<new_size;j++)
            {
              a11[i][j]=a[i][j];
              b11[i][j]=b[i][j];
              a12[i][j]=a[i][j+new_size];
              b12[i][j]=b[i][j+new_size];
              a21[i][j]=a[i+new_size][j];
              b21[i][j]=b[i+new_size][j];
              a22[i][j]=a[i+new_size][j+new_size];
              b22[i][j]=b[i+new_size][j+new_size];
            }
        }

        for(int i=0;i<new_size;i++)
        {
            for(int j=0;j<new_size;j++)
            {
                temp1[i][j]=a11[i][j]+a22[i][j];
                temp2[i][j]=b11[i][j]+b22[i][j];
            }
        }

        strassen(new_size,temp1, temp2, m1);

        for(int i=0;i<new_size;i++)
        {
            for(int j=0;j<new_size;j++)
            {
                temp1[i][j]=a21[i][j]+a22[i][j];
                temp2[i][j]=b11[i][j];
            }
        }
     
        strassen(new_size,temp1, temp2, m2);

        for(int i=0;i<new_size;i++)
        {
            for(int j=0;j<new_size;j++)
            {
                temp1[i][j]=a11[i][j];
                temp2[i][j]=b12[i][j]-b22[i][j];
            }
        }
    
        strassen(new_size,temp1, temp2, m3);

        for(int i=0;i<new_size;i++)
        {
            for(int j=0;j<new_size;j++)
            {
                temp1[i][j]=a22[i][j];
                temp2[i][j]=b21[i][j]-b11[i][j];
            }
        }
    
        strassen(new_size,temp1, temp2, m4); 

        for(int i=0;i<new_size;i++)
        {
            for(int j=0;j<new_size;j++)
            {
            temp1[i][j]=a11[i][j]+a12[i][j];
            temp2[i][j]=b22[i][j];
            }
        }
    
        strassen(new_size,temp1, temp2, m5);
        // To Calculate Part6 i.e. p6=(A10-A00)*(B00+B01)
        for(int i=0;i<new_size;i++)
        {
            for(int j=0;j<new_size;j++)
            {
                temp1[i][j]=a21[i][j]-a11[i][j];
                temp2[i][j]=b11[i][j]+b12[i][j];
            }
        }
    
        strassen(new_size,temp1, temp2, m6);

        for(int i=0;i<new_size;i++)
        {
            for(int j=0;j<new_size;j++)
            {
                temp1[i][j]=a12[i][j]-a22[i][j];
                temp2[i][j]=b21[i][j]+b22[i][j];
            }
        }
    
        strassen(new_size,temp1, temp2, m7);
        //To Calculate C11=p1+p4-p5+p7
     
        for(int i=0;i<new_size;i++)
        {
            for(int j=0;j<new_size;j++)
            {
                c[i][j] = m1[i][j] + m4[i][j] - m5[i][j] + m7[i][j];
                c[i][j+new_size] = m3[i][j] + m5[i][j];
                c[i+new_size][j] = m2[i][j] + m4[i][j];
                c[i+new_size][j+new_size] = m1[i][j] + m3[i][j] - m2[i][j] + m6[i][j];

            }
        }
    }
    else if(size==1)
      { 
        c[0][0]=a[0][0]*b[0][0];
      }
}
