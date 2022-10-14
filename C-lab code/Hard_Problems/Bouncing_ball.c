#include"common.h"
#define PRINT_LOCATION //printf("\nCurrent direction = %s, i = %d, j = %d", cur_dir, i, j);

#define CHECK_HOLE if(1 == check(num_holes, holes_x, holes_y, i, j)){free(holes_x);free(holes_y);break;}

int k;

int check(int num_holes, int *holes_x, int *holes_y, int i, int j)
{
	for(k=0;k<num_holes;k++)
	{
		//printf("\nCheck num_holes %d, holes x %d, holes y %d, i %d, j %d", num_holes, *(holes_x + k), *(holes_y + k), i, j);
		if((i == holes_x[k])&&(j == holes_y[k]))
		{
		printf("Falls through hole at (%d,%d)", i, j);
		return 1;
		}
	}
	return 0;
}
		
		

int main()
{
	char start_dir[3], cur_dir[3], inbuf[BUF_LEN], *s;
	int m, n, i, j, num_holes, count;
	FILE *fp;
	int start_x, start_y;
	int *holes_x;
	int *holes_y;

//Getting input and storing
	
	if(NULL == (fp = fopen("input4-2.txt", "r")))
		ERR_MESG("Error reading file\n");
	
	if (NULL == fgets(inbuf, BUF_LEN, fp))
	       	ERR_MESG("premature end of input\n");
	       		
	if (NULL == (s = strtok(inbuf, " ,\n")))
       		ERR_MESG("malformed line\n");
	m = atoi(s);
	
	s = strtok(NULL, " ,\n");
       	n = atoi(s);
       	
	if (NULL == fgets(inbuf, BUF_LEN, fp))
	       	ERR_MESG("premature end of input\n");
	       		
	if (NULL == (s = strtok(inbuf, ",\n")))
       		ERR_MESG("malformed line\n");
       	num_holes = atoi(s);
       	
       	//printf("\nm = %d, n = %d, holes = %d", m,n,num_holes);
       	
	if(NULL == (holes_x = Malloc(num_holes, int)))
		ERR_MESG("out of memory\n");
	if(NULL == (holes_y = Malloc(num_holes, int)))
		ERR_MESG("out of memory\n");
       	for(i=0;i<num_holes;i++)
       	{

       		if (NULL == fgets(inbuf, BUF_LEN, fp))
	       		ERR_MESG("premature end of input\n");
	       		
		if (NULL == (s = strtok(inbuf, " ,\n")))
       			ERR_MESG("malformed line\n");
       		
       		holes_x[i] = atoi(s);
       		
		s = strtok(NULL, " ,\n");
       		holes_y[i] = atoi(s);
       	
       	}
       	
     	/*for(i=0;i<num_holes;i++)
       	{
       		printf("\nHole %d -> x = %d, y = %d", i, holes_x[i], holes_y[i]);
       	}*/
	
	if (NULL == fgets(inbuf, BUF_LEN, fp))
       		ERR_MESG("premature end of input\n");
       		
	if (NULL == (s = strtok(inbuf, " ,\n")))
		ERR_MESG("malformed line\n");
	
	start_x = atoi(s);
	s = strtok(NULL, " ,\n");
	start_y = atoi(s);
	
	//printf("\nstart point -> x = %d, y = %d", start_x, start_y);
	
	if (NULL == fgets(inbuf, BUF_LEN, fp))
       		ERR_MESG("premature end of input\n");
	if (NULL == (s = strtok(inbuf, " ,\n")))
		ERR_MESG("malformed line\n");
	
	strncpy(start_dir, s, 2);

	//printf("\nstart direction ");
	//puts(start_dir);
       		fclose(fp);
 //input is stored...      		
              	

//Changing directions after bouncing

//Path tracing
	count = 0;
	strncpy(cur_dir, start_dir, 2);
	i = start_x;
	j = start_y;
	PRINT_LOCATION
while((i>=0)&&(i<m)&&(j>=0)&&(j<n))
{
	//printf("1");

	if((count!=0)&&(strcmp(cur_dir, start_dir)==0)&&(start_x == i)&&(start_y == j))
	{
		printf("Bounces forever");
		free(holes_x);
		free(holes_y);
		break;
	}
	if((strcmp(cur_dir, "NE")==0)&&(i>0)&&(j<n))
	{
		
		i--;
		j++;
		count++;
		PRINT_LOCATION
		CHECK_HOLE
		
		if ((i== 0)&&(j == n-1))
		{
			strcpy(cur_dir, "SW"); //after bouncing from top right corner
		PRINT_LOCATION
		CHECK_HOLE
		}
			// corner + 1 case start
		else if ((i==0)&&(j==n-2))
		{
			j++;
			PRINT_LOCATION
			CHECK_HOLE
			i++;
			PRINT_LOCATION
			CHECK_HOLE
			strcpy(cur_dir, "SW");
		}
		else if ((i==1)&&(j==n-1))
		{
			i--;
			PRINT_LOCATION
			CHECK_HOLE
			j--;
			PRINT_LOCATION
			CHECK_HOLE
			strcpy(cur_dir, "SW");
		}
			// corner + 1 case end
		else if (i==0)
		{
			j++;
			strcpy(cur_dir, "SE"); // after bouncing from top
			PRINT_LOCATION
			CHECK_HOLE
		}
		else if (j == n-1)
		{
			i--;
			strcpy(cur_dir, "NW"); //after bouncing from right
			PRINT_LOCATION
			CHECK_HOLE
		}
	}

	if((strcmp(cur_dir, "NW")==0)&&(i>0)&&(j>0))
	{
		i--;
		j--;
		count++;
		PRINT_LOCATION
		CHECK_HOLE
		if ((i== 0)&&(j == 0))
		{
			strcpy(cur_dir, "SE"); //after bouncing from top left corner
		PRINT_LOCATION
		CHECK_HOLE
		}
			// corner + 1 case start
		else if ((i==0)&&(j==1))
		{
			j--;
			PRINT_LOCATION
			CHECK_HOLE
			i++;
			PRINT_LOCATION
			CHECK_HOLE
			strcpy(cur_dir, "SE");
		}
		else if ((i==1)&&(j==0))
		{
			i--;
			CHECK_HOLE
			j++;
			CHECK_HOLE
			strcpy(cur_dir, "SE");
		}
			// corner + 1 case end
		else if (i==0)
		{
			j--;
			strcpy(cur_dir, "SW");//after bouncing from top
		PRINT_LOCATION
		CHECK_HOLE
		}
		else if (j == 0)
		{
			i--;
			strcpy(cur_dir, "NE"); //after bouncing from left
		PRINT_LOCATION
		CHECK_HOLE
		}
	}

	if((strcmp(cur_dir, "SE")==0)&&(i<m)&&(j<n))
	{
		i++;
		j++;
		count++;
		PRINT_LOCATION
		CHECK_HOLE
		if ((i== m-1)&&(j == n-1))
		{
			strcpy(cur_dir, "NW"); //after bouncing from bottom right corner
		PRINT_LOCATION
		CHECK_HOLE
		}
			// corner + 1 case start
		else if ((i==m-2)&&(j==n-1))
		{
			i++;
			PRINT_LOCATION
			CHECK_HOLE
			j--;
			PRINT_LOCATION
			CHECK_HOLE
			strcpy(cur_dir, "NW");
		}
		else if ((i==m-1)&&(j==n-2))
		{
			j++;
			PRINT_LOCATION
			CHECK_HOLE
			i--;
			PRINT_LOCATION
			CHECK_HOLE
			strcpy(cur_dir, "NW");
		}
			// corner + 1 case end
		else if (i== m-1)
		{
			j++;
			strcpy(cur_dir, "NE"); //after bouncing from bottom
		PRINT_LOCATION
		CHECK_HOLE
		}
		else if (j == n-1)
		{
			i++;
			strcpy(cur_dir, "SW"); //after bouncing from right
		PRINT_LOCATION
		CHECK_HOLE
		}

	}

	if((strcmp(cur_dir, "SW")==0)&&(i<m)&&(j>0))
	{
		i++;
		j--;
		count++;
		PRINT_LOCATION
		CHECK_HOLE
		if ((i== m-1)&&(j == 0))
		{
			strcpy(cur_dir, "NE"); //after bouncing from bottom left corner
		PRINT_LOCATION
		CHECK_HOLE
		}
	//corner + 1 case start
		else if ((i==m-2)&&(j==0))
		{
			i++;
			PRINT_LOCATION
			CHECK_HOLE
			j++;
			PRINT_LOCATION
			CHECK_HOLE
			strcpy(cur_dir, "NE");
		}
		else if ((i==m-1)&&(j==1))
		{
			j--;
			PRINT_LOCATION
			CHECK_HOLE
			i--;
			PRINT_LOCATION
			CHECK_HOLE
			strcpy(cur_dir, "NE");
		}
	// corner + 1 case end
		else if (i== m-1)
		{
			j--;
			strcpy(cur_dir, "NW"); //after bouncing from bottom
		PRINT_LOCATION
		CHECK_HOLE
		}
		else if (j == 0)
		{
			i++;
			strcpy(cur_dir, "SE"); //after bouncing from left
		PRINT_LOCATION
		CHECK_HOLE
		}
	}
}

   	
}		
