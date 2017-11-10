#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX_LEN (19)


char Buf[MAX_LEN], *Fd_In;
char SaveData[750][3];

void Svae_Data()
{
	FILE *Fd_In = fopen("irisdata.txt", "r");
	int Count=0;
	int Count_Comma=0;
    int Index=0;
    int Data=0;
	
	while (!feof(Fd_In))
    {
    	fgets(Buf, MAX_LEN, Fd_In);
    	if(Buf != NULL)
    	{
    		for(Count=0;Count<=19;Count++)
    		{
    			if(Buf[Count]!=',' && Count_Comma<5)
    			{
    				SaveData[Index][Data]=Buf[Count];
    				Data++;	
				}
			
				else if(Buf[Count]==',')
				{
					Count_Comma++;
					Index++;
					Data==0;
				}
				
				else if(Buf[Count]=='\0'&& Count_Comma==5)
				{
					Count_Comma==0;
				}
			}	
		}
	}
}

int main()
{
	Svae_Data();
	
} 
