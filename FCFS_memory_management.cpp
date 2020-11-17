#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

int memory_first[101], memory_best[101], memory_worst[101];

int job[21];
int sizee;

 void allocate_first(int job_id,int memory)
 {
     int i,curr=0,cnt=0;
  for(i=1;i<=sizee;i++)
  {
      if(memory_first[i]==-1 && curr)
      {
          cnt++;
      }
      else if(memory_first[i]==-1 && curr==0)
      {
          curr=i;
          cnt=1;

      }
      else
      {
          curr=0;
          cnt=0;
      }
      if(cnt==memory)
      {
          for(i=curr;i<curr+memory;i++)
          {
              memory_first[i]=job_id;
          }
          return ;
      }
  }


  return ;
 }


      void  allocate_best(int job_id,int memory)
      {
        //  for(int i=0;i<sizee;i++)
         //   cout<<memory_best[i]<<" ";
          cout<<endl;
        int i,cnt=0, curr=0;
          int best_start=0, best_size=sizee+1;
          for(i=1;i<=sizee;i++)
          {
               if(memory_best[i]==-1 && curr)
            {
                cnt++;


            }
                else if(memory_best[i]==-1 && curr==0 )
                {


                curr=i;
                cnt=1;

                    }
      else
      {
          if(cnt>=memory)
                {
                if(best_size>cnt)
                {
                best_size=cnt;
                best_start = curr;
                }
                }
          curr=0;
          cnt=0;
      }
         if(cnt >=memory && i==sizee)
                {
                      if(best_size>cnt)
                {
                best_size=cnt;
                best_start = curr;
                }
                }
          }

          if(best_start>0)
          {
              for(i=best_start;i<best_start+memory;i++)
              {
                  memory_best[i]=job_id;
              }
          }
          return ;
      }


      //------------------------------------
      void  allocate_worst(int job_id,int memory)
      {
             int i,cnt=0, curr=0;
          int worst_start=0, worst_size=0;
          for(i=1;i<=sizee;i++)
          {
               if(memory_worst[i]==-1 && curr)
            {
                cnt++;


            }
                else if(memory_worst[i]==-1 && curr==0 )
                {


                curr=i;
                cnt=1;

                    }
      else
      {
          if(cnt>=memory)
                {
                if(worst_size<cnt)
                {
                worst_size=cnt;
                worst_start = curr;
                }
                }
          curr=0;
          cnt=0;
      }

       if(i==sizee)
                {
                      if(cnt>=memory && worst_size<cnt)
                {
                worst_size=cnt;
                worst_start = curr;
                }
                }


          }

          if(worst_start>0)
          {
              for(i=worst_start;i<worst_start+memory;i++)
              {
                  memory_worst[i]=job_id;
              }
          }
          return ;
      }

      //--------

void print_first()
{
     int i, curr=1, frag=0;
    memory_first[0]=memory_first[1];

  for(i=1;i<=sizee;i++)
  {
        if(memory_worst[i]==-1)
        frag++;

    if(memory_first[i]!=memory_first[i-1] )
    {
        cout<<curr<<" "<<"to "<<i-1<<"    \t  ";
            if(memory_first[i-1]==-1)
                cout<<"Hole\n";
            else
            {
                cout<<"job  "<<memory_first[curr]<<endl;
            }
            curr=i;
    }
    if(i==sizee)
    {
         cout<<curr<<" "<<"to "<<i<<"    \t  ";
            if(memory_first[i-1]==-1)
                cout<<"Hole\n";
            else
            {
                cout<<"job  "<<memory_first[curr]<<endl;
            }
            curr=i;
    }


  }

  cout<<"\n external fragmentation = "<<frag<<endl;

}




void print_best()
{

 int i, curr=1, frag=0;


    memory_best[0]=memory_best[1];
  for(i=1;i<=sizee;i++)
  {
          if(memory_best[i]==-1)
        frag++;
     // cout<<memory_best[i]<<" ";
    if(memory_best[i]!=memory_best[i-1] )
    {
        cout<<curr<<" "<<"to "<<i-1<<"   \t   ";
            if(memory_best[i-1]==-1)
                cout<<"Hole\n";
            else
            {
                cout<<"job  "<<memory_best[curr]<<endl;
            }
            curr=i;
    }
    if(i==sizee)
    {
         cout<<curr<<" "<<"to "<<i<<"    \t   ";
            if(memory_best[i-1]==-1)
                cout<<"Hole\n";
            else
            {
                cout<<"job  "<<memory_best[curr]<<endl;
            }
            curr=i;
    }


  }
  cout<<"\n external fragmentation = "<<frag<<endl;

}



void print_worst()
{
    int i, curr=1, frag=0;
    memory_worst[0]=memory_worst[1];

  for(i=1;i<=sizee;i++)
  {
      if(memory_worst[i]==-1)
        frag++;

    if(memory_worst[i]!=memory_worst[i-1] )
    {
        cout<<curr<<" "<<"to "<<i-1<<"    \t  ";
            if(memory_worst[i-1]==-1)
                cout<<"Hole\n";
            else
            {
                cout<<"job  "<<memory_worst[curr]<<endl;
            }
            curr=i;
    }
    if(i==sizee)
    {
         cout<<curr<<" "<<"to "<<i<<"    \t  ";
            if(memory_worst[i-1]==-1)
                cout<<"Hole\n";
            else
            {
                cout<<"job  "<<memory_worst[curr]<<endl;
            }
            curr=i;
    }


  }

  cout<<"\n external fragmentation = "<<frag<<endl;


}


void  terminate_first(int job_id)
{

    for(int i=1;i<=sizee;i++)
    {
        if(memory_first[i]==job_id)
            memory_first[i]=-1;
    }

}
    void    terminate_best(int job_id)
    {
        for(int i=1;i<=sizee;i++)
    {
        if(memory_best[i]==job_id)
            memory_best[i]=-1;
    }
    }
      void  terminate_worst(int job_id)
      {
          for(int i=1;i<=sizee;i++)
    {
        if(memory_worst[i]==job_id)
            memory_worst[i]=-1;
    }
      }


int main() {


cout<<"Simulation started\n";
cout<<"Please enter the memory size\n";

cin>>sizee;

int i;
int job_id,  memory;


for(i=-1;i<=sizee;i++)
{
   memory_first[i]=-1;
   memory_best[i]=-1;
    memory_worst[i]=-1;
}

for(i=1;i<=20;i++)
{
    job[i]=-1;
}


    while(1)
    {
        cout<<"enter the job_id and memory with a single space to separate\n";
        cout<<"job_id  memory\n";
        cin>>job_id>>memory;

        if(job_id==-1)
            {
                cout<<"Termination of simulation\n";
                return 0;
    }



    if( memory>0)
    {
        job[job_id]=1;
        allocate_first(job_id,memory);
        allocate_best(job_id,memory);
        allocate_worst(job_id,memory);

        cout<<"memory allocation in first fit------\n";
        cout<<"memory layout       content\n";
        print_first();
        cout<<"memory allocation in best fit------\n";
        cout<<"memory layout       content\n";
        print_best();
        cout<<"memory allocation in worst fit-----\n";
        cout<<"memory layout       content\n";
        print_worst();



    }
    else{

           if(job[job_id]==-1)
           {
               cout<<"no job found"<<endl;
               continue;
           }
           else
            {
                job[job_id]=-1;

       terminate_first(job_id);
        terminate_best(job_id);
        terminate_worst(job_id);
            }

        cout<<"memory allocation in first fit------\n";
        cout<<"memory layout       content\n";
        print_first();
        cout<<"memory allocation in best fit------\n";
        cout<<"memory layout       content\n";
        print_best();
        cout<<"memory allocation in worst fit-----\n";
        cout<<"memory layout       content\n";
        print_worst();
    }
    }


return 0;
}
