#include<stdio.h>
#include<math.h>
#include<conio.h>
float a,b,c,d;
float sign(float p){
    float test1=a*pow(p,3)+b*pow(p,2)+c*pow(p,1)+d;
    return test1;   
}

void quadratic(float a1,float b1,float c1){
float x1[2],x2[2];
float dis=(b1*b1)-(4*a1*c1);
if(dis==0){
    x1[0]=(-b1)/2*a1; x2[0]=(-b1)/2*a1; x1[1]=0;x2[1]=0;
    printf("The approximate second root is %f.\t\tThe error is %f\n",x1[0],sign(x1[0]));
    printf("The approximate second root is %f.\t\tThe error is %f\n",x2[0],sign(x2[0]));    
}
if(dis>0){
    x1[0]=(-b1)+(sqrt(dis))/(2*a1);  x2[0]=(-b1)-(sqrt(dis))/(2*a1); x1[1]=0; x2[1]=0;
    printf("The approximate second root is %f.\t\tThe error is %f\n",x1[0],sign(x1[0]));
    printf("The approximate second root is %f.\t\tThe error is %f\n",x2[0],sign(x2[0]));
}
else{
    x1[0]=(-b1)/2*a1;x1[1]=(sqrt(-dis))/(2*a1); x2[0]=(-b1)/2*a1; x2[1]=-((sqrt(-dis)))/(2*a1);
    printf("The approximate second root is %f + %f i.\n",x1[0],x1[1]);
    printf("The approximate second root is %f - %f i.\n",x2[0],x2[1]);}
}
void main(){
    printf("Enter the values of a,b,c,d:\n");
    scanf("%f %f %f %f",&a,&b,&c,&d);
    float high,mean,low,root=0,p=1,q=1;int con=1;
    if(a!=0){
        while(con!=5){
            if(sign(p)>0){
                while(1){
                    q-=1;
                    if(sign(q)<0){break;}
                }
                high=p;low=q;con=5;               
            }
            else if(sign(p)<0){
                while(1){
                    q+=1;
                    if(sign(q)>0){break;}
                }
                high=q;low=p;con=5;
            }
            else{
                root=p;
                high=p;low=p;
                con=5;
            }
               
        }
        printf("%f %f\n",high,low);
        for(int i=0;i<500;i++){
            int index;
            mean=(high+low)/2;
                        
            if(sign(mean)>0){
                high=mean;
                low=low;
            }            
            else if(sign(mean)<0){
                low=mean;
                high=high;
                
            }
            if(sign(mean)==0){break;}
                          
        }
        root=mean;        
    }
    float error=a*pow(root,3)+b*pow(root,2)+c*pow(root,1)+d;
printf("\n\nThe approximate first root is %f.\n",root);

float a1=a,b1=(a*root+b),c1=(a*root*root+b*root+c),x1[2],x2[2];
quadratic(a1,b1,c1);   

getch();
}
