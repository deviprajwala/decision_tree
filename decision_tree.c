#include<stdio.h>
#include<stdlib.h>


struct info
{
 int id;
 char name[10];
 char body_temperature[10];
 char gives_birth[10];
 char aquatic_creature[10];
 char aerial_creature[10];
 char has_legs[10];
 char hibernates[10];
 char class_label[10];
 struct info *link;
};

typedef struct info *info;

struct node
{
 char test_condition[10];
 char label[10];
};
typedef struct node *node;


char l1[10]="mammal",l2[10]="reptile",l3[10]="fish",l4[10]="amphibian",l5[10]="bird";
float c[6];//gini index values stored in array
float c1,c2,c3,c4,c5,c6;
int mw=0,mc=0,rw=0,rc=0,fw=0,fc=0,aw=0,ac=0,bw=0,bc=0;

info getinfo();
void input(int n,info head);
void print(info head);
void find_best_split(info head);
float find_gini_index_binary(char *s1,char *s2,char *s3,info head);
void check_label_pos(info head,int value);
float calculate();
float smallest(float c[6],int n);

info getinfo()
{
  info x;
  x=(info)malloc(sizeof(struct info));
  x->link=NULL;
  return x;
}

void input(int n,info head)
{
 int i;
 info a,cur;
 for(i=1;i<=n;i++)
 {
  a=getinfo();
  //printf("Enter name:");
  scanf("%s",a->name);
  //printf("Body temperature:");
  scanf("%s",a->body_temperature);
  //printf("Gives birth yes/no:");
  scanf("%s",a->gives_birth);
  //printf("Aquatic_creature yes/no/semi:");
  scanf("%s",a->aquatic_creature);
  //printf("Aerial creature yes/no:");
  scanf("%s",a->aerial_creature);
  //printf("Has legs yes/no:");
  scanf("%s",a->has_legs);
  //printf("hibernates yes/no:");
  scanf("%s",a->hibernates);
  //printf("class label:");
  scanf("%s",a->class_label);

  if(head->link==NULL)
  {
    head->link=a;
  }
  else
  { 
    cur=head->link;
    while(cur->link!=NULL)
    {
     cur=cur->link;
    }
    cur->link=a;
  }
 }
}
 
void print(info head)
{
  info cur;
  cur=head;
  printf("DATA POINTS\n");
  while(cur!=NULL)
  {
    printf("%s   %s   %s  ",cur->name,cur->body_temperature,cur->gives_birth);
    printf("%s  %s  %s  %s  ",cur->aquatic_creature,cur->aerial_creature,cur->has_legs,cur->hibernates);
    printf("%s\n",cur->class_label);
    cur=cur->link;
  }
}
void find_best_split(info head)
{
  int i=1,k;
  float select;
  char s1[10]="warm";
  char s2[10]="cold";
  char s3[17]="body_temperature";
  char s4[10]="yes";
  char s5[10]="no";
  char s6[11]="gives_birth";
  char s7[16]="aquatic_creature";
  char s8[15]="aerial_creature";
  char s9[10]="has_legs";
  char s10[10]="hibernates";
  c[i]=find_gini_index_binary(s1,s2,s3,head);
  i++;
  c[i]=find_gini_index_binary(s4,s5,s6,head);
  i++;
  c[i]=find_gini_index_binary(s4,s5,s7,head);
  i++;
  c[i]=find_gini_index_binary(s4,s5,s8,head);
  i++;
  c[i]=find_gini_index_binary(s4,s5,s9,head);
  i++;
  c[i]=find_gini_index_binary(s4,s5,s10,head);
  
  select=smallest(c,i);
  
  for(k=1;k<=i;k++)
  {
    if(select==c[k])
    {
      if(k==1)
      {
         printf("condition is %s\n",s3);
      }
      else if(k==2)
      {
         printf("condition is %s\n",s6);
      }
      else if(k==3)
      {
         printf("condition is %s\n",s7);
      }
      else if(k==4)
      {
         printf("condition is %s\n",s8);
      }
      else if(k==5)
      {
         printf("condition is %s\n",s9);
      }
      else if(k==6)
      {
         printf("condition is %s\n",s10);
      }
    }
  }

}

float find_gini_index_binary(char *s1,char *s2,char *s3,info head)
{
  int p,warm,yes;
  info cur;
  cur=head->link;
  char a[17]="body_temperature";
  char b[11]="gives_birth";
  char c[16]="aquatic_creature";
  char d[15]="aerial_creature";
  char e[10]="has_legs";
  char f[10]="hibernates";
  p=strcmp(a,s3);
  if(p==0)//if the attribute is body temperature
  {
     while(cur!=NULL)
      {
       warm=strcmp(s1,cur->body_temperature);
       if(warm==0)//if animal is a warm blooded  animal
       {
          check_label_pos(cur,0);
       }
       else//if animal is a cold blooded animal
       {
          check_label_pos(cur,1);    
       }
      cur=cur->link;
      }
      c1=calculate(mw,rw,fw,aw,bw,mc,rc,fc,ac,bc);
      return c1;
  }
  p=strcmp(b,s3);
  if(p==0)//if the attribute is gives birth
  {
     while(cur!=NULL)
      {
       yes=strcmp(s1,cur->gives_birth);
       if(yes==0)//if yes condition is satisfied
       {
          check_label_pos(cur,0);
       }
       else//if no condition is satisfied
       {
          check_label_pos(cur,1);    
       }
      cur=cur->link;
      }
      c2=calculate(mw,rw,fw,aw,bw,mc,rc,fc,ac,bc);
      return c2;
  }
  p=strcmp(c,s3);
  if(p==0)//if the attribute is aquatic creature
  {
     while(cur!=NULL)
      {
       yes=strcmp(s1,cur->gives_birth);
       if(yes==0)//if yes condition is satisfied
       {
          check_label_pos(cur,0);
       }
       else//if no conition is satisfied
       {
          check_label_pos(cur,1);    
       }
      cur=cur->link;
      }
      c3=calculate(mw,rw,fw,aw,bw,mc,rc,fc,ac,bc);
      return c3;
  }
  p=strcmp(d,s3);
  if(p==0)//if the attribute is aerial creature
  {
     while(cur!=NULL)
      {
       yes=strcmp(s1,cur->gives_birth);
       if(yes==0)//if yes condition is satified
       {
          check_label_pos(cur,0);
       }
       else//if no condition is satisfied
       {
          check_label_pos(cur,1);    
       }
      cur=cur->link;
      }
      c4=calculate(mw,rw,fw,aw,bw,mc,rc,fc,ac,bc);
      return c4;
  }
  p=strcmp(e,s3);
  if(p==0)//if the attribute is has legs
  {
     while(cur!=NULL)
      {
       yes=strcmp(s1,cur->gives_birth);
       if(yes==0)//if yes condition is satisfied
       {
          check_label_pos(cur,0);
       }
       else//if no condition is satisfied
       {
          check_label_pos(cur,1);    
       }
      cur=cur->link;
      }
      c5=calculate(mw,rw,fw,aw,bw,mc,rc,fc,ac,bc);
      return c5;
  }
  p=strcmp(f,s3);
  if(p==0)//if the attribute is hibernates
  {
     while(cur!=NULL)
      {
       yes=strcmp(s1,cur->gives_birth);
       if(yes==0)//if yes condition is satisfied
       {
          check_label_pos(cur,0);
       }
       else//if no condition is satisfied
       {
          check_label_pos(cur,1);    
       }
      cur=cur->link;
      }
      c6=calculate(mw,rw,fw,aw,bw,mc,rc,fc,ac,bc);
      return c6;
  }
}
void check_label_pos(info cur,int value)
{
  if(value==0)
  {
          int test;
          test=strcmp(l1,cur->class_label);
          if(test==0)//if the warm(yes) blooded animal is a mammal
          {
            mw++;
          }
          test=0;
          test=strcmp(l2,cur->class_label);
          if(test==0)//if the warm(yes) blooded animal is a reptile
          {
            rw++;
          }
          test=0;
          test=strcmp(l3,cur->class_label);
          if(test==0)//if the warm(yes) blooded animal is a fish
          {
            fw++;
          }
          test=0;

          test=strcmp(l4,cur->class_label);
          if(test==0)//if the warm(yes) blooded animal is an amphibian
          {
            aw++;
          }
          test=0;
     
          test=strcmp(l5,cur->class_label);
          if(test==0)//if the warm blooded animal is a bird
          {
            bw++;
          }
  }
  else if(value==1)
  {
    int test;
          test=strcmp(l1,cur->class_label);
          if(test==0)//if the cold(no) blooded animal is a mammal
          {
            mc++;
          }
          test=0;
          test=strcmp(l2,cur->class_label);
          if(test==0)//if the cold(no) blooded animal is a reptile
          {
            rc++;
          }
          test=0;
          test=strcmp(l3,cur->class_label);
          if(test==0)//if the cold(no) blooded animal is a fish
          {
            fc++;
          }
          test=0;

          test=strcmp(l4,cur->class_label);
          if(test==0)//if the cold(yes) blooded animal is an amphibian
          {
            ac++;
          }
          test=0;
     
          test=strcmp(l5,cur->class_label);
          if(test==0)//if the cold(no) blooded animal is a bird
          {
            bc++;
          }
  }
}


float calculate()
{  
float total,w_num,c_num,gini,v1,v2,w_num2,c_num2;
  w_num=mw+rw+fw+aw+bw;
  c_num=mc+rc+fc+ac+bc;

float mw2,mc2,rw2,rc2,fw2,fc2,aw2,ac2,bw2,bc2;
float a1,a2,a3,a4,a5;

  w_num2=w_num*w_num;
  c_num2=c_num*c_num;

  mw2=mw*mw;
  rw2=rw*rw;
  fw2=fw*fw;
  aw2=aw*aw;
  bw2=bw*bw;

  mc2=mc*mc;
  rc2=rc*rc;
  fc2=fc*fc;
  ac2=ac*ac;
  bc2=bc*bc;
  
  v1=1-(mw2/w_num2)-(rw2/w_num2)-(fw2/w_num2)-(aw2/w_num2)-(bw2/w_num2);

  v2=1-(mc2/c_num2)-(rc2/c_num2)-(fc2/c_num2)-(ac2/c_num2)-(bc2/c_num2);
  
  total=w_num+c_num;
 
 gini=((w_num/total)*v1)+((c_num/total)*v2);
  return gini;
}

float smallest(float c[6],int n)
{
  float min;
  min=c[1];
  int j;
  for(j=2;j<=n;j++)
  {
    if(min>c[j])
    {
       min=c[j];
    }
  }
  return min;
}
void main()
{
 int n;
 info head;
 head=getinfo();
 //printf("enter the number of data points");
 scanf("%d",&n);
 input(n,head);
 //print(head);
 find_best_split(head);
 
}
