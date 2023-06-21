/*
Name: Mariam Ashraf Amin          ID:20200520
Name: Reem Ayman Abd El-fattah    ID:20200186
*/

//This program decides the winner candidate by using normal election system and new point system
#include <iostream>
using namespace std;

//functions prototype
void entering_candidates_of_1_voter(string c1,string c2,string c3,long n);  //entering candidates in order of preference
void old_system (string c1,string c2,string c3,string A,long n);            //calculating points in normal election system
void new_system (string c1,string c2,string c3,string A,string B,string C,long n); //calculating points in new system points
void Winner (string c1,string c2,string c3,long num1,long num2,long num3);    //displaying the winner after comparing points

int main()
{
    string candidate_1,candidate_2,candidate_3;       //variable definition
    long num_voters;

    cout<<"Please Enter the three candidates\n";   //Asking for enter candidates
    //First candidate
    cout<<"First candidate: ";
    cin>>candidate_1;

    //Second candidate
    cout<<"Second candidate: ";
    cin>>candidate_2;
    while (candidate_2==candidate_1)           //prevent repetitions
    {
        cout<<"The name is repeated. Enter the second candidate again\n";
        cout<<"Second candidate: ";
        cin>>candidate_2;
    }

    //Third candidate
    cout<<"Third candidate: ";
    cin>>candidate_3;
    while (candidate_3==candidate_2 || candidate_3==candidate_1)         //prevent repetitions
    {
        cout<<"The name is repeated. Enter the third candidate again\n";
        cout<<"Third candidate: ";
        cin>>candidate_3;
    }

    //number of voters
    cout<<"Enter the number of voters: ";   //Asking for entering number of voters
    cin>>num_voters;
    while (num_voters<0)
    {
        cout<<"Invalid number. the number of voters again: ";
        cin>>num_voters;
    }

    //calling the function
    entering_candidates_of_1_voter(candidate_1,candidate_2,candidate_3,num_voters);
    return 0;
}

//entering_candidates_of_1_voter Function
void entering_candidates_of_1_voter(string c1,string c2,string c3,long n)
{
    string frist_choice,second_choice,third_choice;          //variable definition
    for (long i=1;i<=n;i++)
    {
        cout << "Enter the 3 choices of candidates of voter no. "<<i<<endl;
        //First name
        cout << "1. ";
        cin >> frist_choice;
        //checking the entered name
        while (frist_choice != c1 && frist_choice != c2 && frist_choice != c3) {
            cout << "Invalid Name. Enter the name again\n";
            cout << "1. ";
            cin >> frist_choice;
        }

        //second name
        cout << "2. ";
        cin >> second_choice;
        //checking the entered name
        while (second_choice != c1 && second_choice != c2 && second_choice != c3 ) {
            cout << "Invalid Name. Enter the name again\n";
            cout << "2. ";
            cin >> second_choice;
        }
        //preventing repetition
        while (second_choice == frist_choice) {
            cout << "Repeated Name. Enter the name again\n";
            cout << "2. ";
            cin >> second_choice;
        }

        //Third name
        cout << "3. ";
        cin >> third_choice;
        //checking the entered name
        while (third_choice != c1 && third_choice != c2 && third_choice != c3) {
            cout << "Invalid Name. Enter the name again\n";
            cout << "3. ";
            cin >> third_choice;
        }
        //preventing repetition
        while (third_choice == second_choice || third_choice == frist_choice) {
            cout << "Repeated Name. Enter the name again\n";
            cout << "3. ";
            cin >> third_choice;
        }

        //calling the functions
        old_system(c1,c2,c3,frist_choice,n);
        new_system (c1,c2,c3,frist_choice,second_choice,third_choice,n);
    }

}

//old voting system
void old_system (string c1,string c2,string c3,string first,long n)
{
    static long Vote_1=0, Vote_2=0, Vote_3=0,i=0;     //variable definition

    //calculate the points for only one candidate
    if (c1==first) {
        Vote_1 += 1;
    } else if (c2==first) {
        Vote_2 += 1;
    } else if (c3==first) {
        Vote_3 += 1;
    }

    //Displaying candidates points in old system
    i++;
    if (i==n){
        cout<<"The votes in old system:\n";
        cout<<c1<<" = "<<Vote_1<<endl;
        cout<<c2<<" = "<<Vote_2<<endl;
        cout<<c3<<" = "<<Vote_3<<endl;
        Winner(c1,c2,c3,Vote_1,Vote_2,Vote_3);    //calling Winner function
    }
}

//new_system Function
void new_system (string c1,string c2,string c3,string first,string second,string third,long n)
{
    static long V_1=0,V_2=0,V_3=0,i=0;   //variable definition

    //calculating candidate's points in new system
    if (c1 == first) {
        V_1 += 3;
    }
    else if (c1 == second) {
        V_1 += 2;
    }
    else if (c1 == third) {
        V_1 += 1;
    }


    if (c2 == first) {
        V_2 += 3;
    }
    else if (c2 == second) {
        V_2 += 2;
    }
    else if (c2 == third) {
        V_2 += 1;
    }


    if (c3 == first) {
        V_3 += 3;
    }
    else if (c3 == second) {
        V_3 += 2;
    }
    else if (c3 == third) {
        V_3 += 1;
    }

    //Displaying candidates points in new system
    i++;
    if (i==n){
        cout<<"The votes in new system:\n";
        cout<<c1<<" = "<<V_1<<endl;
        cout<<c2<<" = "<<V_2<<endl;
        cout<<c3<<" = "<<V_3<<endl;
        Winner(c1,c2,c3,V_1,V_2,V_3);        //calling Winner function
    }
}

//Winner Function
void Winner (string c1,string c2,string c3,long num1,long num2,long num3)
{
    //comparing between points to know who the winner
    if(num1>num2 && num1>num3)
    {
        cout<<"The Winner is " <<c1<<endl;
    }
    else if(num2>num1 && num2>num3)
    {
        cout<<"The Winner is " <<c2<<endl;
    }
    else if(num3>num1 && num3>num2)
    {
        cout<<"The Winner is " <<c3<<endl;
    }
    else if(num1==num2==num3)
    {
        cout<<c1<<" and "<<c2<<" and " <<c3<<" are equal"<<endl;
    }
    else if(num1==num2)
    {
        cout<<c1<<" and " <<c2<<" are equal"<<endl;
    }
    else if(num1==num3)
    {
        cout<<c1<<" and " <<c3<<" are equal"<<endl;
    }
    else if(num2==num3)
    {
        cout<<c2<<" and " <<c3<<" are equal"<<endl;
    }
}
