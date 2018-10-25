#include<iostream>
using namespace std;
class fifo_alg
{
    char ref[100];
    int frame,fault,front,rear;
    char *cir_que;
public:
    fifo_alg()
    {
        front=rear=-1;
        fault=0;
    }
    void getdata();
    void page_fault();
};
void fifo_alg::getdata()
{
    cout<<"Enter Page reference string : ";
    cin.getline(ref,50);
    cout<<"Enter no. of frames : ";
    cin>>frame;
}
void fifo_alg::page_fault()
{
    cir_que=new char[frame];
    int flag=0;
    for(int i=0;ref[i]!=0;i++)
    {
        if(ref[i]==' ')
            continue;
        if(front==-1)
        {
            cir_que[0]=ref[i];
            front=rear=0;
            fault++;
        }
        else
        {
            for(int y=front%frame;y!=rear;y=(y+1)%frame)
                if(cir_que[y]==ref[i])
                {
                        flag=1;
                        break;
                }
                if(cir_que[rear]==ref[i])
                        flag=1;
            if(flag==0)
            {
                if((rear+1)%frame==front)
                    front=(front+1)%frame;
                rear=(rear+1)%frame;
                cir_que[rear]=ref[i];
                fault++;
            }
            flag=0;
        }
    }
    cout<<"Number of page faults : "<<fault;
}
int main()
{
    fifo_alg page;
    page.getdata();
    page.page_fault();
    return 0;
}
