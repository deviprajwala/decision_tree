#include<stdio.h>
#include<stdlib.h>


struct info
{
 int id;
 char name[10];
 char body_temperature[10];
 char skin_cover[10];
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
  //printf("Skin cover:");
  scanf("%s",a->skin_cover);
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
    printf("%s   %s   %s    %s  ",cur->name,cur->body_temperature,cur->skin_cover,cur->gives_birth);
    printf("%s  %s  %s  %s  ",cur->aquatic_creature,cur->aerial_creature,cur->has_legs,cur->hibernates);
    printf("%s\n",cur->class_label);
    cur=cur->link;
  }
}
void find_best_split(info head)
{
  int c1,c2,c3,c4,c5,c6,c7;
  char s1[10]="warm";
  char s2[10]="cold";
  char s3[10]="body_temperature";
  char s4[10];
  c1=find_gini_index_binary(s1,s2,s3);
  
}

int find_gini_index_binary(char *s1,char *s2,char *s3,info head)
{
  int p,warm,mw=0,mc=0,rw=0,rc=0,fw=0,fc=0,aw=0,ac=0,bw=0,bc=0;
  info cur;
  cur=head->link;
  char a1[10]="body_temperature";
  p=strcmp(a1,s3);
  if(p==0)//if the attribute is body temperature
  {
     while(cur!=NULL)
      {
       warm=strcmp(s1,cur->body_temperature);
       if(warm==0)//if animal is a warm blooded(/yes) animal
       {
          int test;
          test=strcmp(l1,cur->class_label);
          if(test==0)//if the warm(yes) blooded animal is a mammal
          {
            mw++;
            goto label;
          }
          test=0;
          test=strcmp(l2,cur->class_label);
          if(test==0)//if the warm(yes) blooded animal is a reptile
          {
            rw++;
            goto label;
          }
          test=0;
          test=strcmp(l3,cur->class_label);
          if(test==0)//if the warm(yes) blooded animal is a fish
          {
            fw++;
            goto label;
          }
          test=0;

          test=strcmp(l4,cur->class_label);
          if(test==0)//if the warm(yes) blooded animal is an amphibian
          {
            aw++;
            goto label;
          }
          test=0;
     
          test=strcmp(l5,cur->class_label);
          if(test==0)//if the warm blooded animal is a bird
          {
            bw++;
            goto label;
          }
       }
       else//if animal is a cold(no) blooded animal
       {
          
          int test;
          test=strcmp(l1,cur->class_label);
          if(test==0)//if the cold(no) blooded animal is a mammal
          {
            mc++;
            goto label;
          }
          test=0;
          test=strcmp(l2,cur->class_label);
          if(test==0)//if the cold(no) blooded animal is a reptile
          {
            rc++;
            goto label;
          }
          test=0;
          test=strcmp(l3,cur->class_label);
          if(test==0)//if the cold(no) blooded animal is a fish
          {
            fc++;
            goto label;
          }
          test=0;

          test=strcmp(l4,cur->class_label);
          if(test==0)//if the cold(yes) blooded animal is an amphibian
          {
            ac++;
            goto label;
          }
          test=0;
     
          test=strcmp(l5,cur->class_label);
          if(test==0)//if the cold(no) blooded animal is a bird
          {
            bc++;
            goto label;
          }
       }
    label:
      cur=cur->link;
      }
  }
  printf("%d %d",mw,rc);
  return p;
}

void main()
{
 int n;
 info head;
 head=getinfo();
 //printf("enter the number of data points");
 scanf("%d",&n);
 input(n,head);
 print(head);
 find_best_split(head);
}
