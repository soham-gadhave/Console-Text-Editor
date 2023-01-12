#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Stack
{
 char data;
 struct Stack *next;
}stack;
stack *top=NULL;
FILE *p;
char s[25];
void PUSH(char c)
{
 stack *temp=(stack *)malloc(sizeof(stack));
 temp->data=c;
 temp->next=top;
 top=temp;
}
char POP()
{
 char c=top->data;
 stack *temp = top;
 if(top==NULL)
   {
    printf("\nSTACK is Empty...\n");
    return -1;
   }
   else
   {
     top=top->next;
     free(temp);
     return c;
   }
}
void display()
{
 stack *temp=top;
 if(temp==NULL)
    printf("\nStack is Empty\n");
 while(temp!=NULL)
 {
  printf("%c", temp->data);
  temp=temp->next;
 }
}
void Write()
{
 char c;
 int i=1,j=0,k=0,l,y,d=0,flag=0,flag1=0,flag2=0,flag3=0,flag4=0,flag5=0;
 printf("\nStart Writing\n");
 while((c=getchar())!=27)
      {
       if(c=='\r')
	 {
	  printf("\nPressed Enter");
	  fprintf(p,"\n");
	 }
       if(c==26)
	 {
	  flag2=1;
	  if(flag1==0)
	  {
	   fseek(p,-i,2);
	   PUSH(fgetc(p));
	   fseek(p,-i,2);
	   fputc(' ',p);
	   printf("\b \b");
	   i++;
	   k++;
	   flag=1;
	   flag3=1;
	  }
	  else
	  {
	 if(flag4==1&&flag5==1)
	   {
	    y=j;
	    while(y>0)
	    {
	     char ch1=POP();
	     y--;
	    }
	    while(d>0)
	    {
	     fseek(p,-i,2);
	     PUSH(fgetc(p));
	     fseek(p,-i,2);
	     fputc(' ',p);
	     d--;
	     i++;
	     printf("\b \b");
	    }
	    i=1;
	   }
	   else
	   {
	    l=j;
	    if(flag4==0&&flag5==0)
	       j++;
	    while(j>0)
	    {
	     char ch=POP();
	     printf("%c",ch);
	     fseek(p,-j,2);
	     fputc(ch,p);
	     j--;
	    }
	   i=1;
	   flag1=0;
	   }
	    flag4=0;
	    flag5=0;
	  }
	  continue;
	 }
       if(c==18&&flag2==1)
	 {
	  if(flag3==1)
	    {
	     while(k>0)
	     {
	      char ch=POP();
	      printf("%c",ch);
	      fseek(p,-k,2);
	      fputc(ch,p);
	      flag3=0;
	      k--;
	     }
	     i=1;
	    }
	  else if(flag1==0)
	    {
	     while(l>0)
	     {
	      fseek(p,-i,2);
	      PUSH(fgetc(p));
	      fseek(p,-i,2);
	      fputc(' ',p);
	      printf("\b \b");
	      i++;
	      l--;
	      flag=1;
	     }
	    }
	  continue;
	 }
       if(c==8)
	 {
	  char ch;
	  j++;
	  fseek(p,-i,2);
	  ch=fgetc(p);
	  PUSH(ch);
	  fseek(p,-i,2);
	  fputc(' ',p);
	  i++;
	  printf("\b \b");
	  flag=1;
	  flag1=1;
	  if(flag5==0)
	     flag4=1;
	  continue;
	 }
	if(flag==1)
	  {
	   fseek(p,-i+1,2);
	   i=1;
	   flag=0;
	  }
	if(flag4==1)
	  {
	   d++;
	   flag5=1;
	  }
//	printf("%c",c);
	fputc(c,p);
      }
}
void main()
{
 int opt;
 system("clear");
 printf("\n\t\t\t***EDITOR***\n");
 do
 {
  printf("\n1.)Create a File\n2.)Display Stack\n3.)Exit\n");
  printf("\nEnter the choice:");
  scanf("%d",&opt);
  printf("\nInstructions for User:\n1.)Press Ctrl+Z for Undo\n2.)Press Ctrl+R for Redo\n3.)Escape to exit from the Writing Pad (Escape + Enter on Linux-based Systems.)\nNote: Undo and Redo Might not work on Linux-based Systems\n");
  switch(opt)
  {
   case 1: printf("\nEnter the filename:");
	   scanf("%s",s);
	   strcat(s,".txt");
	   p=fopen(s,"w+");
	   Write();
	   break;
   case 2: printf("\n");
	   display();
	   break;
   case 3: printf("\nExited from the file %s \n",s);
	   break;
   default: break;
  }
 }while(opt!=3);
}
