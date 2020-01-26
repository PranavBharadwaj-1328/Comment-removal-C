#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// C program to remove comments submitted by K Pranav Bharadwaj (17MCME06)
// Output comes as out.c
int substring(char * str, char * sub);
void multirem(char *filename);
int main()
{
  FILE *fp,*fp1;
  char line[100],filename[32];
  int i,pos;
  printf("Enter Filename: ");
  scanf("%s",filename);
  fp = fopen(filename,"r");
  fp1 = fopen("out1.c","w");
  if(fp == NULL)
  {
    printf("No such file\n");
  }
  else
  {
    // To remove single line comments starting with double slash
    while(fgets(line,100,fp) != NULL)
    {
      if((pos = substring(line,"//")) > -1)
      {
	for(i=0;i<pos;i++)
	{
	  fputc(line[i],fp1);
	}
	fputs("\n",fp1);
      }
      else
      {
        fputs(line,fp1);
      }
    }
  }
  multirem("out1.c"); //This output is given as input to multiremove command
  remove("out1.c");
}
// To remove multi line comments that lie in between '/* and */'
void multirem(char *filename)
{
  int flag = 0,pos,i;
  FILE *fp1,*fp2;
  char line[100];
  fp1 = fopen(filename,"r");
  fp2 = fopen("out.c","w");
  if(fp1 == NULL)
  {
    printf("There is some problem");
  }
  else
  {
    while(fgets(line,100,fp1) != NULL)
    {
      if(substring(line,"/*") == -1 && flag == 0)
      {
        fputs(line,fp2);
      }
      else
      {
        if((pos = substring(line,"/*")) > -1)
	{
	  flag = 1;
	  for(i=0;i<pos;i++)
	  {
	    fputc(line[i],fp2);
	  }
	}
	if((pos = substring(line,"*/")) > -1)
	{
	  flag = 0;
	  for(i=pos+2;i < strlen(line);i++)
	  {
	    fputc(line[i],fp2);
	  }
	}
      }
    }
  }    
}
/* To Identify substrings */
int substring(char * str, char * sub)
{
  int flag = 0;
  int i=0,len1=0,len2=0;
  len1 = strlen(str);
  len2 = strlen(sub);
  while(str[i] != '\0')
  {
    if(str[i] == sub[0])
    {
      if((i+len2)>len1)
        break;
      if(strncmp(str+i,sub,len2)==0)
      {
        flag = 1;
	break;
      }
    }
    i++;
  }
  if (flag == 1)
  {
    return i;
  }
  else
  {
    return -1;
  }
}


