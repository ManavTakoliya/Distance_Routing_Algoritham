#include<iostream>
#include<conio.h>
#include<fstream>

using namespace std;

int main()
{   

    fstream fout;

    fout.open("rt.csv", ios::out | ios::trunc);

    int graph[50][50];
    int i,j,k,t;
    int n;
 
    cout<<"\nHow many number of nodes do you want to enter:";
    cin>>n;
 
    /* Initialize graph*/
    for (i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            graph[i][j]=-1;
        }
    }
 
    // Vertex names
    string ch[7]={"N1","N2","N3","N4","N5","N6","N7"};

    // Get input
    for (i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            {
                graph[i][j]=0;
            }
            if(graph[i][j]==-1)
            {
                cout<<"\nEnter Distance between "<<ch[i]<<" - "<<ch[j]<<" : ";
                cin>>t;
                graph[i][j]=graph[j][i]=t;
            }
        }
    }
 
    // Initializing next
    int next[50][50];
    for (i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            next[i][j]=-1;
        }
    }
 
    //Display Routing table 
    cout<<"\nRouting Tables";
    for (i=0;i<n;i++)
    {
        cout<<"\n"<<ch[i]<<" Table";
        cout<<"\node\tDist\tnext";
        for(j=0;j<n;j++)
        {
            cout<<"\n"<<ch[j]<<"\t"<<graph[i][j]<<"\t"<<next[i][j];
        }
    }
 
    //Neighbours tables
    int sh[50][50][50];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for (k=0;k<n;k++)
            {
                // Check if edge is present or not
                if((graph[i][j]>-1)&&(graph[j][k]>-1))
                {
                    sh[i][j][k]=graph[j][k]+graph[i][j];
                }
                else
                {
                    sh[i][j][k]=-1;
                }
            }
        }
    }
 
    //displaying shared table
    for(i=0;i<n;i++)
    {
        cout<<"\n\n For "<<ch[i];
        for (j=0;j<n;j++)
        {
            cout<<"\n From "<<ch[j];
            for(k=0;k<n;k++)
            {
                cout<<"\n "<<ch[k]<<" "<<sh[i][j][k];
            }
        }
    }
     
    // Updating tables
    int final_graph[50][50];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            final_graph[i][j]=graph[i][j];
            next[i][j]=i;
             
            
            for(k=0;k<n;k++)
            {
                 
                if((final_graph[i][j]>sh[i][k][j]) || (final_graph[i][j] == -1))
                {
                    if(sh[i][k][j]>-1)
                    {
                        final_graph[i][j]=sh[i][k][j];
                        next[i][j]=k;
                    }
                }
            }
 
            if(final_graph[i][j]==-1)
            {
                for(k=0;k<n;k++)
                {
 
                    if((final_graph[i][k]!=-1)&&(final_graph[k][j]!=-1))
                    {
                        if((final_graph[i][j]==-1) || ((final_graph[i][j]!=-1) &&(final_graph[i][j]>final_graph[i][k]+final_graph[k][j]))) 
                        {
                            if(final_graph[i][k]+final_graph[k][j]>-1)
                            {
                                final_graph[i][j]=final_graph[i][k]+final_graph[k][j];
                                next[i][j]=k;
                            }
                        }
                    }
                     
                }
            }
        }
    }
 
    cout<<"\nAfter Update :";
    //Display table Updation
    fout<<n<<"\n";
    for (i=0;i<n;i++)
    {
        cout<<"\n"<<ch[i]<<" Table";
        cout<<"\node\tDist\tnext";
        for(j=0;j<n;j++)
        {   
            fout << ch[j] << ", "
             << final_graph[i][j] << ", ";

            cout<<"\n"<<ch[j]<<"\t"<<final_graph[i][j]<<"\t";
            if(i==next[i][j]){
                cout<<"-";
                fout<<"-";
            }
            else{
                cout<<ch[next[i][j]];
                fout<<ch[next[i][j]];
            }
            fout<<"\n";
        }

        fout<<i+1<<"\n";
        
    }

    return 0;
}
 
