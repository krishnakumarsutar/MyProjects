#include<bits/stdc++.h>
using namespace std;

int min(int dis[],int mrk[],int n)
{
	int min=1000,ind;
	for(int i=0;i<n;i++)
	{
		if(mrk[i]==0 && dis[i]<min)
		{
			min=dis[i];
			ind=i;
		}
	}
	return ind;
}

int main()
{
	int gra[6][6]={{0,10,15,0,0,0},{0,0,0,12,0,15},{0,0,0,0,10,0},{0,0,0,0,2,1},{0,0,0,0,0,0},{0,0,0,0,5,0}};
	int n=6;
	for(int x=0;x<n;x++)
	{
	cout<<"\n"<<x<<" is the source.\n";
	int dis[n];
	int mrk[n];
	for(int i=0;i<n;i++)
	{
		dis[i]=1000;
		mrk[i]=0;
	}
	
	dis[x]=0;
	
	int min=1000,ind;
	
	for(int i=0;i<n;i++)
	{
	    for(int i=0;i<n;i++)
	    {
		 if(mrk[i]==0 && dis[i]<=min)
		  {
			min=dis[i];
			ind=i;
		  }
	    }
		
		//cout<<ind<<"\n";
		
		mrk[ind]=1;
		for(int j=0;j<n;j++)
		{
			if(gra[ind][j]!=0 && mrk[j]==0 && dis[j]>dis[ind]+gra[ind][j])
				dis[j]=dis[ind]+gra[ind][j];
		}
		min=1000;
	}
	cout<<"POINT   Distance\n";
	for(int m=0;m<n;m++)
	{
		cout<<m+1<<" - "<<dis[m]<<"\n";
	}
	}
	return 0;
}
