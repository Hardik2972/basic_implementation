// #include<stdio.h>

// struct Matrix{
//     int rno;
//     int cno;
//     int val;
// };

// typedef struct Matrix sparse;

// void convert(sparse arr[],int mat[][3],int* top,int r,int c){
//     (*top)++;
//     arr[*top].rno=r;
//     arr[*top].cno=c;
//     for(int i=0;i<r;i++){
//         for(int j=0;j<c;j++){
//            if(mat[i][j]!=0){
//             (*top)++;
//              arr[*top].rno=i;
//              arr[*top].cno=j;
//              arr[*top].val=mat[i][j];
//            }
//         }
//     }
//     arr[0].val=*top;
//     return;
// }

// void display(sparse arr[],int top){
//    printf("rno  cno  val\n");
//    for(int i=0;i<=top;i++){
//       printf("%d  %d  %d\n",arr[i].rno,arr[i].cno,arr[i].val);
//    }
//    return;
// }

// void transpose(sparse sp1[],sparse sp2[]){
//    int count[sp1[0].cno],start[sp1[0].cno];
//    for(int i=0;i<sp1[0].cno;i++) count[i]=0;
//    for(int i=1;i<=sp1[0].val;i++) count[sp1[i].cno]++;
//    start[0]=1;
//    for(int i=1;i<sp1[0].cno;i++){
//      start[i]=start[i-1]+count[i-1];
//    }
//    sp2[0].rno=sp1[0].cno;
//    sp2[0].cno=sp1[0].rno;
//    sp2[0].val= sp1[0].val;
//    for(int i=1;i<=sp1[0].val;i++){
//      sp2[start[sp1[i].cno]].rno=sp1[i].cno;
//      sp2[start[sp1[i].cno]].cno=sp1[i].rno;
//      sp2[start[sp1[i].cno]].val=sp1[i].val;
//      start[sp1[i].cno]++;
//    }
// }


// void append(sparse sp[],int* top,int r,int c,int s){
//    int flag=0;
//    for(int i=1;i<= *top;i++){
//      if(sp[i].rno == r & sp[i].cno == c){
//         sp[i].val+= s;
//         flag=1;
//         break;
//      }
//    }
//    if(flag==0){
//      (*top)++;
//      sp[*top].rno=r;
//      sp[*top].cno=c;
//      sp[*top].val=s;
//    }
// }


// void multiply(sparse sp1[],sparse sp3[],sparse sp4[],int* top){
//     sp4[0].rno=sp1[0].rno;
//     sp4[0].cno=sp3[0].cno;
//     *top=0;
//     int cnt1[sp1[0].rno],cnt2[sp3[0].rno];
//     int start1[sp1[0].rno],start2[sp3[0].rno];
//     for(int i=0;i<sp1[0].rno;i++){
//       cnt1[i]=0;
//     }
//     for(int i=0;i<sp3[0].rno;i++){
//       cnt2[i]=0;
//     }
//     for(int i=1;i<=sp1[0].val;i++){
//       cnt1[sp1[i].rno]++;
//     }
//     for(int i=1;i<=sp3[0].val;i++){
//       cnt2[sp3[i].rno]++;
//     }
//     start1[0]=1;
//     for(int i=1;i<sp1[0].rno;i++){
//       start1[i]=cnt1[i-1]+start1[i-1];
//     }
//     start2[0]=1;
//     for(int i=1;i<sp3[0].rno;i++){
//       start2[i]=cnt2[i-1]+start2[i-1];
//     }
//     for(int i=0;i<sp1[0].rno;i++){
//       if(cnt1[i]==0) continue;
//       for(int j=0;j<sp3[0].rno;j++){
//          if(cnt2[j]==0) continue;
//          int sum=0;
//          for(int x=start1[i];x<(start1[i]+cnt1[i]);x++){
//             for(int y=start2[j];y<(start2[j]+cnt2[j]);y++){
//                if(sp1[x].cno == sp3[y].cno) sum+= sp1[x].val*sp3[y].val;
//             }
//          }
//          if(sum == 0) continue;
//          sp4[++(*top)].rno=i;
//          sp4[*top].cno=j;
//          sp4[*top].val=sum;
//       }
//     }
// }


// void main(){
//     int mat1[4][3]={{1,1,0},{0,6,0},{0,90,0},{0,0,900}};
//     int mat2[4][3]={{1,0,10},{-1,0,0},{0,90,0},{0,0,900}};
//     sparse sp1[100],sp2[100],sp3[100],sp4[100];
//     int top1=-1,top2=-1,top3=-1;
//     convert(sp1,mat1,&top1,4,3);
//     convert(sp2,mat2,&top2,4,3);
//     display(sp1,top1);
//     display(sp2,top2);
//     transpose(sp2,sp3);
//     display(sp3,top2);
//     multiply(sp1,sp3,sp4,&top3);
//     display(sp4,top3);
//     return;
// }
class Silly{
public:
   int data;
   static int constructed;
   static int destructed;
   static int active;

   Silly(){
     data=0;
     active++;
     constructed++;
   }


   Silly(int val);

   Silly(Silly& x){
    data=x.data*2;
    active++;
   }

   void destruct(){
     this->Silly::~Silly();
   }

   ~Silly(){
      destructed++;
      active--;
    }
}