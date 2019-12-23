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
 struct node *lchild;
 struct node *rchild;
 int condition_id;
};
typedef struct node *node;

struct retur
{
  int stopping;
  char label[10];
};
typedef struct retur *ret;


char l1[10]="mammal",l2[10]="reptile",l3[10]="fish",l4[10]="amphibian",l5[10]="bird";
float c[6];//gini index values stored in array
float c1,c2,c3,c4,c5,c6;
int mw=0,mc=0,rw=0,rc=0,fw=0,fc=0,aw=0,ac=0,bw=0,bc=0;
int condition_id_1=1,condition_id_2=2,condition_id_3=3,condition_id_4=4,condition_id_5=5;
int condition_id_6=6;
node root;
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
ret r;

info getinfo();
node getnode();
ret getret(int id,int stopping,char *a);
void input(int n,info head);
void print(info head);
int find_best_split(info head);
float find_gini_index_binary(char *s1,char *s2,char *s3,info head);
void check_label_pos(info head,int value);
float calculate();
float smallest(float c[6],int n);
node tree_growth(info head);
ret stopping condition(head);
info split_record(int bin,int v,info head);

node tree_growth(info head)
{
   int v;
   ret s;
   info head_left,head_right;
   s=stopping condition(head);
   if(s->stopping==1)//if the stopping condition is met i.e all data points have same label
   {
     node leaf;
     leaf=getnode();
     leaf->label=s->label//leaf node is created and label is assigned
     return leaf
   }
   else
   {
   node rooot;
   rooot=getnode();
   v=find_best_split(head);// v is the condition id which is returned by best split function
   head_left=split_record(1,v,head);//spilt the the records which satisfies the condition
   head_right=split_record(0,v,head);//spilt the the records which does not satisfy the condition
   right_child=tree_growth(info head_right);//check foe further growth in child nodes
   left_child=tree_growth(info head_left);
   root->rchild=right_child;//assign the child nodes to the root
   root->lchild=left_child;
   }
return rooot;
}

ret stopping condition(info head)
{
 int p;
 ret r;
 char test[10];
 info cur;
 cur=head->link;
 strcpy(test,cur->class_label);
 while(cur!=NULL)
 {
   p=strcmp(test,cur->class_label);//to check whether all data points can be grouped under one label
   if(p!=0)
   {
     stopping=0;//this node has to be further splited ,it cannot be terminated
     r=getret(stopping,test);
     return r;
   }
   cur=cur->link;
 }
 
 r=getret(stopping,test);//stopping condition is met, leaf node has to be created
 return r;
}

info split_record(int bin,int v,info head)
{
 info head_new
 return head_new;
}
info getinfo()
{
  info x;
  x=(info)malloc(sizeof(struct info));
  x->link=NULL;
  return x;
}

node getnode()
{
  node x;
  x=(node)malloc(sizeof(struct node));
  x->link=NULL;
  return x;
}

ret getret(int id,int stopping,char *a)
{
  ret x;
  x=(ret)malloc(sizeof(struct retur));
  x->stopping=stopping;
  strcpy(x->label,a);
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
  //printf("id:");
  scanf("%d",&a->id);

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
int find_best_split(info head)//finding the best test attribute to spilt based on gini split
{
  int i=1,k;
  float select;

  c[i]=find_gini_index_binary(s1,s2,s3,head);//gini index for first attribute
  i++;
  c[i]=find_gini_index_binary(s4,s5,s6,head);//gini index for second attribute
  i++;
  c[i]=find_gini_index_binary(s4,s5,s7,head);//gini index for third attribute
  i++;
  c[i]=find_gini_index_binary(s4,s5,s8,head);//gini index for fourth attribute
  i++;
  c[i]=find_gini_index_binary(s4,s5,s9,head);//gini index for fifth attribute
  i++;
  c[i]=find_gini_index_binary(s4,s5,s10,head);//gini index for sixth attribute
  
  select=smallest(c,i);//best attribute is the one with least gini index value
  
  for(k=1;k<=i;k++)
  {
    if(select==c[k])
    {
      if(k==1)//if first attribute has least gini index value 
      {
         printf("condition is %d\n",condition_id_1);
         return condition_id_1;

      }
      else if(k==2)//if second attribute has least gini index value
      {
         
         printf("condition is %d\n",condition_id_2);
         return condition_id_2;
      }
      else if(k==3)//if third attribute has least gini index value
      {
         
         printf("condition is %d\n",condition_id_3);
         return condition_id_3;
      }
      else if(k==4)//if fourth attribute has least gini index value
      {
         
         printf("condition is %d\n",condition_id_4);
         return condition_id_4;
      }
      else if(k==5)//if fifth attribute has least gini index value
      {
         
         printf("condition is %d\n",condition_id_5);
         return condition_id_5;
      }
      else if(k==6)//if sixth attribute has least gini index value
      {
         
         printf("condition is %d\n",condition_id_6);
         return condition_id_6;
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
 root=getnode();
 //printf("enter the number of data points");
 scanf("%d",&n);
 input(n,head);
 //print(head);
 root=tree_growth(head);
 id=find_best_split(head);
 classify(head,id);
 
}
