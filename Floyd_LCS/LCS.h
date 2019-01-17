#define LCS_H_

void LCS(char str1[], char str2[])
{
//Printing length of the sequence
	int strLength1 = strlen(str1); //m <-length[X]
  int strLength2 = strlen(str2); //n <-length[Y]
	int length[strLength1 + 1][strLength2 + 1];

    int i, j, k;

//Initializing
    for(i=0; i <= strLength1; i++)
        length[i][0]=0;

    for(j=0; j <= strLength2; j++)
        length[0][j]=0;

		for(i = 0; i <= strLength1; i++) //for i <- 1 to m do
		{
          for(j = 0; j <= strLength2; j++) //for j <- 1 to n do
          	{
              if(i == 0 || j == 0) 
              {
                length[i][j] = 0; //ixj=0
              } 
              else if(str1[i-1] == str2[j-1]) // if x(i) = y(j)
											  // c[i, j] ← c[i-1, j-1]+1
              {
                length[i][j] = length[i-1][j-1] + 1;
              } 
              else 
              {
                if(length[i-1][j] > length[i][j-1])
                	length[i][j] = length[i-1][j];
                	//return (length[i-1][j]);
                else
                	length[i][j] = length[i][j-1];
                	//return length;
              }
            }
        }
        int lengthSize = length[strLength1][strLength2];
        printf("Length of the LCS: %d\n", lengthSize);

 //Printing the Sequence

        char LCS[(length[strLength1][strLength2])+1];
        LCS[(length[strLength1][strLength2])] = '\0'; // Terminating Character

        while(strLength1 > 0 && strLength2 > 0) 
        {
          if(str1[strLength1 - 1] == str2[strLength2 - 1])  
          {
            LCS[(length[strLength1][strLength2]) - 1] = str1[strLength1 - 1];
            (length[strLength1][strLength2]) = (length[strLength1][strLength2]) - 1;
            strLength1 = strLength1 - 1;
            strLength2 = strLength2 - 1;
          }
            
          else if(length[strLength1 - 1][strLength2] > length[strLength1][strLength2 - 1]) 
          {
            strLength1 = strLength1 - 1;
          }

          else 
            strLength2 = strLength2 - 1;
         }

        printf("LCS: %s\n", LCS);
}