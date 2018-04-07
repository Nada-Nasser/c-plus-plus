/// FCI – Programming 1 – 2018 - Assignment 3
/// Program Name: Discrete Math Tool.cpp
/// Last Modification Date: 1/4/2014
/// Author1 and ID and Group: Nada Nasser Al-Said El-Azab    20170369  G.14
/// Author2 and ID and Group: Hanan Mohamed Abdelrahim       20170375  G.14
/// Author3 and ID and Group: Alaa Gamal Soliman Slim        20170376  G.14
/// Teaching Assistant: Eng. xxxxx
/// Purpose: Evaluate some Discrete Math Tools with two sets.
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

void starting();
int new_data_set(char file_name[] ,int& Size);
int load_data_set(char file_name[],int Set[],int Size);
void Display_data_sets(int Set[],int Size);

void  Union(int set_A[] , int set_B[],int size_A , int size_B);
void Intersection(int set_A[] , int set_B[],int size_A , int size_B);
void SubtractionA(int set_A[] , int set_B[],int size_A , int size_B);

void B_minus_A(int set_A[] , int set_B[] ,int size_A , int size_B ,char fileA_name[],char fileB_name[]);
void Cartesian_product(int set_A[] , int set_B[] ,int size_A , int size_B ,char fileA_name[],char fileB_name[]);
void PowerSet(int set_A[], int size_A);

void disjoint(int set_A[] , int set_B[],int size_A , int size_B);
void sorting_sets(int set_A[],int Size);
void is_equal(int set_A[] , int set_B[],int size_A , int size_B);
void proper_subset(int set_A[] , int set_B[] ,int size_A , int size_B ,char fileA_name[],char fileB_name[]);

int main()
{
    int Size_A=0 , Size_B=0;
    char fileA_name[200], fileB_name[200];
    int SetA[Size_A],SetB[Size_B];
    while(true){
        int choice;
        starting();
        int o=1;
        if(!cin || cin || o==1){
            cin >> choice;
            o--;
        }
        if(choice==1){
            cout << "Write a file name to A :";
            cin >> fileA_name;
            new_data_set(fileA_name,Size_A);
            cout << "Write a file name to B :";
            cin >> fileB_name;
            new_data_set(fileB_name,Size_B);
            cout <<endl;
         }
        else if(choice==2){
            cout << "Two data sets are loaded"<<endl;
            load_data_set( fileA_name, SetA, Size_A);
            load_data_set( fileB_name, SetB, Size_B);
            SetA[Size_A];
            SetB[Size_B];
            cout <<endl;
        }
        else if(choice==3){
            cout << "\nSet_A : ";
            Display_data_sets(SetA,Size_A);
            cout << "Set_B : ";
            Display_data_sets(SetB,Size_B);
            cout <<endl;
        }
        else if(choice==4){
            Union(SetA,SetB,Size_A ,Size_B);
        }
        else if(choice==5){
            Intersection(SetA,SetB,Size_A ,Size_B);
        }
        else if(choice==6){
            SubtractionA(SetA,SetB,Size_A ,Size_B);
        }
        else if(choice==7){
            B_minus_A(SetA,SetB,Size_A,Size_B,fileA_name,fileB_name);
        }
        else if(choice==8){
            Cartesian_product(SetA,SetB,Size_A,Size_B,fileA_name,fileB_name);
            cout<<"}"<<endl;
        }
        else if(choice==9){
            cout << "P(A) = ";
            PowerSet(SetA,Size_A);
            cout << "\nP(B) = ";
            PowerSet(SetB,Size_B);
            cout<<endl;
        }
        else if(choice==10){
            disjoint(SetA,SetB,Size_A,Size_B);
            cout <<endl;
        }
        else if(choice==11){
            sorting_sets(SetA,Size_A);
            sorting_sets(SetB,Size_B);
            is_equal(SetA ,SetB,Size_A,Size_B);
            cout <<endl;
        }
        else if(choice==12){
            //SetA[Size_A];
            //SetB[Size_B];
            proper_subset(SetA,SetB,Size_A,Size_B,fileA_name,fileB_name);
            proper_subset(SetB,SetA,Size_B,Size_A,fileB_name,fileA_name);
            cout <<endl;
        }
        else if(choice==13){
            break;
        }
        else{cout <<"Error\n";}
    }
    return 0;
}

void starting()
{
    cout << "Ahlan ya user ya habibi :) \n What do you like to do today?\n";
    cout << "1- Enter a new data set"                        << endl <<
            "2- Load two data sets"                          << endl <<
            "3- Display data sets "                          << endl <<
            "4- Union of A, B"                               << endl <<
            "5- Intersection of A, B"                        << endl <<
            "6- A - B"                                       << endl <<
            "7- B - A"                                       << endl <<
            "8- Cartesian product of A and B"                << endl <<
            "9- Power set of A"                              << endl <<
            "10- Check if A and B are disjoint"              << endl <<
            "11- Check if A and B are equal"                 << endl <<
            "12- Check if a set is a proper subset of other" << endl <<
            "13-end\n";
}
int new_data_set(char file_name[] ,int& Size)
{
    ofstream new_data_file;
    new_data_file.open(file_name);
    if(new_data_file.is_open()){
        int elements;
        Size=0;
        cout << "Write The elements of your Data , write any char if you finished your Data"<<endl;
        while (true){
            cin >> elements;
            if(cin){
                    new_data_file << elements << endl;
                    Size++;
                }
            else{
                cin.clear();
                cin.ignore(100,'\n');
                break;
            }
        }
    }
    else{cout<<"Error";}
    return Size;
}
int load_data_set(char file_name[],int Set[],int Size)
{
    int i=0;
    ifstream file;
    file.open(file_name);
    if(file.is_open()){
        while (!file.eof() && !file.fail() && Size>0){
            file >> Set[i++];
            Size--;
        }
    }
    else{
        cout << "Error";
    }
    return Size;
}
void Display_data_sets(int Set[],int Size)
{
    int element=0;
    cout << "[";
    while (Size>0){
        cout << Set[element];
        if(Size != 1){
            cout << " ,";
        }
        Size--;
        element++;
    }
    cout << "]"<<endl;
}

void  Union(int set_A[] , int set_B[],int size_A , int size_B)
{
    cout<<"[";
    for(int c = 0; c<size_B; c++){
        cout<<set_A[c]<<",";
    }
    for(int a = 0; a<size_B; a++){
        for (int b = 0; b<size_A; b++){
            if (set_B[a] != set_A[b]){
                if ( b == (size_A-1))
                    cout<<set_B[a]<<",";
            }
            else
                break;
        }
    }
    cout<<"]"<<endl;
}
void Intersection(int set_A[] , int set_B[],int size_A , int size_B)
{
    cout<<"The intersection is: {";
    for(int a = 0; a<size_A; a++){
        for(int b = 0; b<size_B; b++){
            if(set_A[a] == set_B[b])
                cout<<set_A[a]<<",";
        }
    }
    cout<<"}"<<endl;
}
void SubtractionA(int set_A[], int set_B[], int size_A,int size_B)
{
    cout<<"{";
    for(int a = 0; a<size_A; a++){
        for (int b = 0; b<size_B; b++){
            if (set_A[a] != set_B[b]){
                if ( b == (size_B-1))
                    cout<<set_A[a]<<",";
            }
            else
                break;
            }
    }
    cout<<"}"<<endl;
}

void B_minus_A(int set_A[] , int set_B[] ,int size_A , int size_B ,char fileA_name[],char fileB_name[])
{
    cout << "B-A = {";
    for(int i=0;i<size_B;i++){
        bool is_ex=false;
        for(int j=0;j<size_A;j++){
            if(set_B[i]==set_A[j]){
                is_ex =true;
            }
        }
        if(!is_ex)
            cout << set_B[i]<<" ";
    }
    cout<<"}"<<endl;
}
void Cartesian_product(int set_A[] , int set_B[] ,int size_A , int size_B ,char fileA_name[],char fileB_name[])
{
    cout<<"}\n\nCartesian product A and B = {";
    for(int i=0;i<size_A;i++){
        for(int j=0;j<size_B;j++)
            cout <<"("<<set_A[i]<<","<<set_B[j]<<")" <<" ";
    }
}
void PowerSet(int set_A[], int size_A)
{
    int nloop = pow(2, size_A);
    for(int i = 0; i < nloop;i++)
    {
        cout<<"{";
        for( int j = 0; j < size_A; j++)
        {
            if(i & (1<<j))
            cout<< set_A[j]<<" ";
        }
        cout << "},";
    }
    cout << "}";
}

void disjoint(int set_A[] , int set_B[] ,int size_A , int size_B)
{
    bool is_disjoint=false;
    for(int i=0;i<size_A;i++){
        for(int j=0;j<size_B;j++){
            if(set_A[i]==set_B[j])
                is_disjoint=true;}}
    if(!is_disjoint)
        cout << "The Sets are disjoint" <<endl;
    else
        cout << "The Sets are not disjoint"<<endl;
}

void sorting_sets(int set_A[],int Size)
{
    int t=0;
    for(int i=0;i<Size;i++){
        for(int j=0;j<Size;j++){
            if(set_A[i]>set_A[j]){
                 t = set_A[i];
                 set_A[i] = set_A[j];
                 set_A[j]=t;}}}
}

void is_equal(int set_A[] , int set_B[] , int size_A , int size_B) ///Size_A==Size_B ???????????????
{
    bool is_equal=true;
    if(size_A==size_B){
        for(int i=0;i<size_A;i++){
            if(set_A[i]!=set_B[i])
                is_equal=false;
        }
        if(is_equal)
            cout << "The Sets are equal" <<endl;
        else
            cout << "The Sets are not equal"<<endl;
        }
        else
            cout << "The Sets are not equal"<<endl;
}

void proper_subset(int set_A[] , int set_B[] ,int size_A , int size_B ,char fileA_name[],char fileB_name[])   ///Size_A < Size_B ????????????????
{
    bool is_subset = true;
    if(size_A<size_B){
        for(int i=0;i<size_A;i++){
            int x=0;
            for(int j=0;j<size_B;j++){
                if(set_A[i]==set_B[j])
                    x++;
            }
            if(x<=0)   /// &&  x >= Size_A
                is_subset=false;
        }
        if(is_subset)
            cout << fileA_name <<" is proper subset of "<< fileB_name <<endl;
        else
            cout << fileA_name<< " is not proper subset of "<< fileB_name<<endl;
    }
    else
        cout << fileA_name<< " is not proper subset of "<< fileB_name<<endl;
}
