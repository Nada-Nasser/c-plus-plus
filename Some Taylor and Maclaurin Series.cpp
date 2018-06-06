/**
Math II
Name : Nada Nasser Al Said           ID : 20170369   Group : 14
Name : Farah Mohamed Mostafa Afifi   ID : 20170351   Group : 13

*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{   char choice;
    cout << "What do you want to do : " <<
            "\n1- Sin(x)"    <<
            "\n2- Cos(x)"    <<
            "\n3- exp(x)"    <<
            "\n4- arctan(x)" <<
            "\n5- ln(x+1)"   << endl;

    cin>>choice;
///*************************************************************************
    if (choice=='1'){
        double input ,sum,term1,n=0,temp;
        cout<<endl <<"enter the number Sin("<<endl;
       // cin.ignore();
        cin>> input;
        double copy_in = input;
        input*=3.14159/180;
        term1=input;
        sum=input;
        while (true){
            temp=term1;
            term1=-term1*(input*input) / (2*n+3)*(2*n+2);
            n++;
            if( fabs(term1)>0.000000007){
                sum+=term1;
            }
            else{
                cout<<"sin("<<copy_in<<") = "<<sum<<endl;
                break;
            }
        }
    }
///*************************************************************************
    else if(choice =='2'){
        double input ,sum,term1,n=0;
        cout <<endl<<"enter the number Cos("<<endl;

        cin>> input;
        double copy_in = input;
        input*=3.14159/180;
        term1=1;
        sum=1;
        while (true){

            term1=-term1*(input*input) / (2*n+1)*(2*n+2);
            n++;
            if( fabs(term1)>0.000000007){
                sum+=term1;
            }
            else{
                cout<<"cos("<<copy_in<<") = "<<sum<<endl;
                break;
            }
        }
    }

///*************************************************************************
    else if (choice == '3')
    {
        double x ;
        cout <<"\n\nwrite the number you want to calculate its exponential : ";
        cin >> x;
        double copy_x = x;
        double term = 1.0;
        double result = term;

        for (int n = 1; term > 0.001 || term < -0.001; ++n)
        {
            term = term * x / n;

            result += term;
        }
        cout << "e^("<< x << ") = "<<result;
    }

///*************************************************************************
    else if(choice == '4'){
        double x;
        cout <<"arctan(";
        cin >> x;

        if (x<-1 || x>1){cout << "out of region\n";return 0;}
        double result = 0 , i = 1 , j=0;
        while (true)
        {
            double t=result;
            result += pow(-1,j)*(pow(x,i))/i;
            i+=2;j++;
            if(t==result)
                break;
        }
        cout << "in radian arctan("<<x<<") = "<<result<<endl;
    }
///*************************************************************************
    else if (choice == '5')
    {
        double x;
        cout <<"\n\nwrite the number you want to calculate its ln(1+.. ";
        cin >> x;
        double copy_x=x;
        if(fabs(x)>=1)
        {
            cout<<"out of region\n";
            return 0;
        }

        double temp = x,term1,t = x,n=1,error=0.0001;
        int charge=-1;

        do
        {
            term1 = x;
            t=t*temp;
            n++;
            x = term1+(t/n)*charge;
            charge=-charge;
        }
        while(fabs(x-term1)>=error);

        cout <<"ln("<<copy_x<<"+1) = "<<x<<endl;

    }

///*************************************************************************
    return 0;
}
