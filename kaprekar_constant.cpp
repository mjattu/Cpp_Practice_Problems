#include<iostream>                          
using namespace std;
int cal(int);                   //function declaration


int main()                  //main function
{
    int number;             //input number
    cout<<"Enter any 4 digit number: (having no zeroes): ";
    cin>>number;

    int result =cal(number);            //executing calculation function for 1st time
    while(result != 6174)               // until result = 66174, the function will repeat (recurrsion)
    {
        result =cal(result);
    }
}


int cal(int number)                    // taking number input from main function
{
    int n[4];                           // separating digits in a array
    n[0]=number/1000;
    n[1]=(number%1000)/100;
    n[2]=(number%100)/10;
    n[3]=number%10;

    int asc[4] = {n[0],n[1],n[2],n[3]};     //asc is an array for ascending order digits
    int dsc[4] = {n[0],n[1],n[2],n[3]};     //dsc is an array for descending order digits
    int temp;
    
    int i,j;                                // declaring counter variables
    for(i=0;i<4;i++)                           //loop for sorting array in ascending order
    {
        for(j=i+1;j<4;j++)
        {
            if(asc[i]>asc[j])  
            {
                temp = asc[i];
                asc[i] = asc[j];
                asc[j]=temp;
            }  
            
        }
    }

    for(i=0;i<4;i++)                        //loop for sorting array in descending order
    {
        for(j=i+1;j<4;j++)
        {
            if(dsc[i]<dsc[j])  
            {
                temp = dsc[i];
                dsc[i] = dsc[j];
                dsc[j]=temp;
            }  
            
        }
    }

    int smaller = (asc[0]*1000)+(asc[1]*100)+(asc[2]*10)+(asc[3]);  // converting array into a integer variable
    int greater = (dsc[0]*1000)+(dsc[1]*100)+(dsc[2]*10)+(dsc[3]);  // converting array into a integer variable
    int result = greater - smaller;                             // defining the main arithmetic logic

    cout<<greater<<"   -   "<<smaller<<"   =   "<<result<<"\n";  // printing the values

    return(result);         // returning the result to the main function, so that we can reuse the result
    
}
