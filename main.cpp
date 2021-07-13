#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int Sum(int arr[] ,int size){
    int i,sum=0;
    for(i=0;i<size;i++)
        sum+=arr[i];
    return sum;
}
float avg(int sum,int num){return (float)sum/num;}
float average(int arr[], int num)
{
    return avg(Sum(arr,num),num);
}

void FIFO(int requests[],int noOfRequests, int headPosition)
{
    int i,j;
    int traversed[noOfRequests];

    cout<<"Next track\tNumber of\n accessed\t tracks\n\t\tTraversed\n"<<endl;
    for(i=0;i<noOfRequests;i++){
        traversed[i]= abs(headPosition-requests[i]);
        cout<<"   "<<requests[i]<<"\t\t"<<"   "<<traversed[i]<<endl;
        headPosition = requests[i];
    }
    cout<<endl;

    cout<<"Total Head Movement = "<<Sum(traversed,noOfRequests)<<endl;
    cout<<"Average Head Movement = "<<average(traversed,noOfRequests)<<"\n"<<endl;
}

void SCAN(int requests[], int noOfRequests, int headPosition)
{

    sort(requests,(sizeof(requests)/sizeof(requests[0])+requests));
    int i,traversed[noOfRequests];
    for(i=0;i<noOfRequests;i++)
        if(headPosition-requests[i]<0)
            break;
    int next = i;
    int prev = i-1;
    int direction;
    cout<<"Enter Direction(1-increase 2-decrease) : ";
    cin>>direction;
    int j;
    cout<<"Next track\tNumber of\n accessed\t tracks\n\t\tTraversed\n"<<endl;

    if(direction == 1){     //increase
        for(i=next;i<noOfRequests;i++){
            traversed[i]= abs(headPosition-requests[i]);
            cout<<"   "<<requests[i]<<"\t\t"<<"   "<<traversed[i]<<endl;
            headPosition = requests[i];
        }
        for(i=prev;i>=0;i--){
            traversed[i]= abs(headPosition-requests[i]);
            cout<<"   "<<requests[i]<<"\t\t"<<"   "<<traversed[i]<<endl;
            headPosition = requests[i];
        }
    }
    else if(direction == 2){
        for(i=prev;i>=0;i--){
            traversed[i]= abs(headPosition-requests[i]);
            cout<<"   "<<requests[i]<<"\t\t"<<"   "<<traversed[i]<<endl;
            headPosition = requests[i];
        }
        for(i=next;i<noOfRequests;i++){
            traversed[i]= abs(headPosition-requests[i]);
            cout<<"   "<<requests[i]<<"\t\t"<<"   "<<traversed[i]<<endl;
            headPosition = requests[i];
        }
    }
    cout<<endl;

    cout<<"Total Head Movement = "<<Sum(traversed,noOfRequests)<<endl;
    cout<<"Average Head Movement = "<<average(traversed,noOfRequests)<<"\n"<<endl;
}

void C_SCAN(int requests[], int noOfRequests, int headPosition)
{

    sort(requests,(sizeof(requests)/sizeof(requests[0])+requests));
    int i,traversed[noOfRequests];
    for(i=0;i<noOfRequests;i++)
        if(headPosition-requests[i]<0)
            break;
    int itr;
    int direction;
    cout<<"Enter Direction(1-increase 2-decrease) : ";
    cin>>direction;
    int j;
    cout<<"Next track\tNumber of\n accessed\t tracks\n\t\tTraversed\n"<<endl;
    if(direction==1){   //increase
        itr = i;
        for(j=0;j<noOfRequests;j++){
            traversed[itr] = abs(headPosition-requests[itr]);
            cout<<"   "<<requests[itr]<<"\t\t"<<"   "<<traversed[itr]<<endl;
            headPosition = requests[itr];
            itr++;
            if(itr>=noOfRequests)
                itr = 0;
        }
    }
    else if(direction == 2){
        itr = i-1;
        for(j=0;j<noOfRequests;j++){
            traversed[itr] = abs(headPosition-requests[itr]);
            cout<<"   "<<requests[itr]<<"\t\t"<<"   "<<traversed[itr]<<endl;
            headPosition = requests[itr];
            itr--;
            if(itr<0)
                itr = noOfRequests-1;
        }
    }
    cout<<endl;

    cout<<"Total Head Movement = "<<Sum(traversed,noOfRequests)<<endl;
    cout<<"Average Head Movement = "<<average(traversed,noOfRequests)<<"\n"<<endl;
}


void menu()
{
    int noOfRequests;
    cout<<"number of requests : ";
    cin>>noOfRequests;
    int requests[noOfRequests];
    cout<<"Enter the requests : "<<endl;
    int i;
    for(i=0;i<noOfRequests;i++)
        cin>>requests[i];

    int headPos;
    cout<<"Enter initial position of the head : ";
    cin>>headPos;

    while(1){
    int choice;
    cout<<"1 - FIFO\n2 - SCAN\n3 - CSCAN\n4 - Reset Data\n0 - Exit\n"<<endl;
    cout<<"Choose a technique : ";
    cin>>choice;
    switch(choice)
        {
        case 1:
            FIFO(requests,noOfRequests,headPos);
            break;
        case 2:
            sort(requests,(sizeof(requests)/sizeof(requests[0])+requests));
            SCAN(requests,noOfRequests,headPos);
            break;
        case 3:
            sort(requests,(sizeof(requests)/sizeof(requests[0])+requests));
            C_SCAN(requests,noOfRequests,headPos);
            break;
        case 4:
            cout<<"Reset data"<<endl;
            menu();
            break;
        case 0:
            exit(0);
        default:
            cout<<"Invalid input"<<endl;
    }
    }

}

int main()
{
//    int requests[] = {27,129,110,186,147,41,10,64,120};
//    int noOfRequests = 9;
//    int n = sizeof(requests)/sizeof(requests[0]);
//    int headPos = 100;


    menu();
    //menu();
    //FIFO(requests,9,100);
    //SCAN(requests,noOfRequests,headPos);
    //C_SCAN(requests,noOfRequests,headPos);
    return 0;
}
