/**
Math II
Name : Nada Nasser Al Said           ID : 20170369   Group : 14
Name : Farah Mohamed Mostafa Afifi   ID : 20170351   Group : 13
*/

#include <iostream>
#include <cmath>
#include <iomanip>
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
        double input ,sum,term1,term2,num,n=2,fact,sign;
        int y=1;
        cout <<endl <<"enter the number Sin("<<endl;
        cin>> input;
        double copy_in = input;
        input*=3.141592654/180;
        num=input;
        term1=input;
        fact=1;
        sum=input;

        while (true){
            if (y%2==0)
                sign=1;
            else
                sign=-1;

            num*=(input*input);
            fact=fact*n*(n+1);
            n+=2;


            term2=(sign*num)/fact;
            sum+=term2;
            y++;
            if(fabs(term1-term2)<0.00000000000000000000000000000001){
                cout<<fixed<<"sin("<<copy_in<<") = "<<sum<<endl;
                break;
            }
            else
                term1=term2;
        }
    }
///*************************************************************************
    else if(choice =='2'){
        double input ,sum,term1,term2,num,n=1,fact,sign;
        int y=1;
        cout <<endl <<"enter the number cos("<<endl;
        cin>> input;
        double copy_in = input;
        input*=3.141592654/180;
        num=1;
        term1=1;
        fact=1;
        sum=1;

        while (true){
            if (y%2==0)
                sign=1;
            else
                sign=-1;

            num*=(input*input);
            fact=fact*n*(n+1);
            n+=2;

            term2=(sign*num)/fact;
            sum+=term2;
            y++;
            if(fabs(term1-term2)<0.00000000000000000000001){
                cout<<fixed<<"cos("<<copy_in<<") = "<<sum<<endl;
                break;
            }
            else
                term1=term2;
        }
    }
///************************************************************************
    else if (choice == '3')
    {
        double x ;
        cout <<"\n\nwrite the number you want to calculate its exponential : ";
        cin>> x;
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
        cout <<"\n\nwrite the number x (|x|<1) : ";
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
///******************** ln(x+1) **************************************
    else if (choice == '5')
    {
        double x;
        cout <<"\n\nwrite the number x (|x|<1) you want to calculate its ln(1+.. ";
        cin >> x;
        double copy_x=x;

        if(fabs(x)>=1)
        {
            cout<<"out of region\n";
            return 0;
        }

        double temp = x , term1 ,t = x , n=1,error=0.0001;
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

        cout <<"ln("<<copy_x<<"+1) = " << "ln("<<copy_x+1<<") = "<<x<<endl;

    }

///*************************************************************************
    return 0;
}
