/*
Name: Mariam Ashraf Amin          ID:20200520
Name: Reem Ayman Abd El-fattah    ID:20200186
*/

//This program checks credit card number validity
#include <iostream>
using namespace std;

//functions prototype
long long Credit_card();                   //checks number of digits(between 14,16)
int Number_of_digits (long long X);        //calculate number of digits
int Digit (int d);                         //check and make sum on digit
int Sum1 (int arr[],int S);                //sum odd digit*2
int Sum2 (int arr[],int S);                //sum even digit
string Validity_of_Credit_Card (int arr[],int S);       //display if credit card number valid or not

int main()
{
    long long card = Credit_card();          //Call Credit_card Function
    int size = Number_of_digits(card);       //Call Number_of_digits Function

    //Convert Card Number to Credit_Card Array starts from the right number of Credit Card
    //Array definition
    int Credit_Card[size];     //Size of Array = Number of Credit Card's digits
    for (int i = 0; i < size; i++)
    {
        Credit_Card[i] = card % 10;
        card /= 10;
    }

    //Call Validity_of_Credit_Card function
    cout<<Validity_of_Credit_Card(Credit_Card,size)<<endl;

    return 0;
}

//Credit_card Function
long long Credit_card()
{
    long long Card;
    cout << "Please enter your Credit Card Number: ";
    cin>>Card;

    //Check Digits number of Credit Card
    int Size = Number_of_digits (Card);       //Call Number_of_digits Function

    while (Card<=0 || Size <14 || Size > 16)
    {
        cout << "Invalid Credit Card Number, Please enter your Credit Card Number again \n";
        cin >> Card;
        Size = Number_of_digits(Card);
    }
    return Card;
}

//Number_of_digits Function
int Number_of_digits (long long X)
{
    int num = 0;
    //Calculate Number of Credit Card's digits
    while (X != 0)
    {
        num += 1;
        X /= 10;
    }
    return num;
}

//Digits Function
int Digit (int d)
{
    if (d/10==0)         //checking one digit
        return d;
    else
    {
        //if the number contains 2 digits
        int sum_digits =0;
        for (int j = 0; j < 2; j++)    //make number one digit
        {
            sum_digits+=d%10;
            d/=10;
        }
        return sum_digits;
    }
}

//Sum1 Function
int Sum1 (int arr[],int S)
{
    int sum1=0;
    for (int j=1;j<S;j+=2)
    {
        sum1+=Digit(arr[j]*2);         //sum odd digit*2
    }
    return sum1;
}

//Sum2 Function
int Sum2 (int arr[],int S)
{
    int sum2=0;
    for (int j=0;j<S;j+=2)              //sum even digit
    {
       sum2+=arr[j];
    }
    return sum2;
}

//Validity_of_Credit_Card Function
string Validity_of_Credit_Card (int arr[],int S)
{
    //check if sum1 and sum2 is divisible by 10 then the number is valid
    if ((Sum1(arr,S)+ Sum2(arr,S))%10==0) {
        return "Your Credit Card Number is True";
    }
    else {
        return "Your Credit Card Number is False";
    }
}

