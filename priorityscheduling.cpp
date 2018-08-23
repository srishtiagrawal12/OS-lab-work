#include<iostream>
using namespace std;

int main()
{
int bt[20],p[20],pid[20],wt[20],tat[20],n,pos,tot=0,temp;
float avgwt,avgtat;
cout<<"enter no of processes";
cin>>n;

cout<<"enter process id,burst time and priority";
for(int i=0;i<n;i++)
{
	cin>>pid[i]>>bt[i]>>p[i];
}

//sorting based on priority of processes
 for(int i=0;i<n;i++)
    {
        pos=i;
        for(int j=i+1;j<n;j++)
        {
            if(p[j]<p[pos])
                pos=j;
        }
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=pid[i];
        pid[i]=pid[pos];
        pid[pos]=temp;
    }
    

    
    //for average waiting time
    for(int i=1;i<n;i++)
    {
    	wt[i]=0;
    	for(int j=0;j<i;j++)
    	{
    		wt[i]=wt[i]+bt[j];
    	}
		tot=tot+wt[i];
   	}
   	avgwt=tot/n;
   	tot=0;
   	
   	cout<<"process    waiting time     burst time   turn around time ";
   	for(int i=0;i<n;i++)
   	{
   		tat[i]=bt[i]+wt[i];
   		tot= tot+tat[i];
   		cout<<"\n"<<pid[i]<<"    "<<wt[i]<<"       "<<bt[i]<<"      "<<tat[i]<<"\n";
	   }
	   avgtat=tot/n;
	   cout<<"average waiting time"<<avgwt;
	   cout<<"average turn around time"<<avgtat;
	   return 0;

}
