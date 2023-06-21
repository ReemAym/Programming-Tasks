/*
Name: Mariam Ashraf Amin          ID:20200520
Name: Reem Ayman Abd El-fattah    ID:20200186
*/

//This program calculate sin,cos and tan for angle using specific formula
#include <iostream>
#include <iomanip>
using namespace std;

//Functions (prototype) which used
double power(long double x,long double pow);
double factorial(long double n);
double absolute (long double x);
double Radians (long double x);
double Cos (long double x);
double Sin (long double x);
double Tan (long double x);

int main ()
{
    long double x;           //variable definition
    cout<<"Enter the angle in degree: ";    //Asking for entering
    cin>>x;                                 // Entering angle (x)

    //Displaying cos(x)
    cout << "cos(x) = ";
    cout << fixed << setprecision(5) << Cos(x) << endl;

    //Displaying sin(x)
    cout << "sin(x) = ";
    cout << fixed << setprecision(5) << Sin(x) << endl;

    //check if x = 90 or 270 in tan angle
    if (absolute(x) == 90 || absolute(x) == 270)
    {
        cout << "tan(x) = ";
        cout << "undefined\n";
    }
    else
    {
        //Displaying tan(x)
        cout << "tan(x) = ";
        cout << fixed << setprecision(5) << Tan(x) << endl;
    }

    return 0;
}

//power Function
double power(long double num,long double pow)
{
    long double res=1;         //variable definition and initialization
    for (int i =0;i<pow;i++)   //loop to calculate power
        res*=num;
    return res;
}

//factorial Function
double factorial(long double n)
{
    long double fac=1;           //variable definition and initialization
    for (int i =1;i<=n;i++)      //loop to calculate factorial
        fac*=i;
    return fac;
}

//absolute Function
double absolute (long double x)
{
    if (x<0)
        return x*-1;
    else
        return x;
}

//Radians Function
double Radians (long double x)
{
    x*=3.14/180;        //transformation into radians
    return x;
}

//cos(x) Function
double Cos (long double x)
{
    long double cos_x = 0;       //variable definition

    if (absolute(x)==270){
        cos_x=0;
    }
    else {
        x = Radians(x);            //transformation into radians
        for (int n = 0; n <= 15; n++)
        {
            cos_x += power(-1, n) / factorial(2 * n) * power(x, 2 * n);       //cos(x) formula
        }
    }
    return cos_x;

}


//Sin(x) Function
double Sin (long double x)
{
    long double sin_x=0;     //variable definition

    if (x== -180|| x==360)
    {
        sin_x=0;
    }
    else
    {
        x = Radians(x);          //transformation into radians
        for (int n = 0; n <= 15; n++)
            {
                sin_x += power(-1, n) / factorial((2 * n) + 1) * power(x, (2 * n) + 1);     //sin(x) formula
        }
    }
    return sin_x;
}


//Tan(X) Function
double Tan (long double x)
{
    //list of Bernoulli Number
    long double B[16] = {1.0 / 6, -1.0 / 30, 1.0 / 42, -1.0 / 30, 5.0 / 66, -691.0 / 2730, 7.0 / 6, -3617.0 / 510,
                         43867.0 / 798, -174611.0 / 330, 854513.0 / 138,-236364091.0 / 2730, 8553103.0 / 6,
                         -23749461029.0 / 870, 8615841276005.0 / 14322,-7709321041217.0 / 510};

    long double tan_x = 0;    //variable definition

    //-90 to 90
    if (absolute(x) >= 0 && absolute(x) < 90)
    {
        x = Radians(x);        //transformation into radians
        int i = 0;
        for (int n = 0; n <= 15; n++)
        {
            tan_x += power(-1, n) * power(2, (2 * n) + 2) * ((power(2, (2 * n) + 2)) - 1) * B[i] /
                     factorial((2 * n) + 2) * power(x, (2 * n) + 1);     //tan(x) formula

            i = i + 1;   //the index of Bernoulli list
        }
    }
    else
    {
        //x>360
        while (x > 360) {
            x -= 360;
        }
        //x<0
        while (x < 0) {
            x += 360;
        }

        //0-90
        if (x >= 0 && x < 90)
        {
            x = Radians(x);       //transformation into radians(first quarter)
            int i = 0;
            for (int n = 0; n <= 15; n++)
            {
                tan_x += power(-1, n) * power(2, (2 * n) + 2) * ((power(2, (2 * n) + 2)) - 1) * B[i] /
                         factorial((2 * n) + 2) * power(x, (2 * n) + 1);
                i = i + 1;
            }
        }

        //90-180
        if (x > 90 && x <= 180)
        {
            x = Radians(x - 180);        //transformation into radians(second quarter)
            int i = 0;
            for (int n = 0; n <= 15; n++)
            {
                tan_x += power(-1, n) * power(2, (2 * n) + 2) * ((power(2, (2 * n) + 2)) - 1) * B[i] /
                         factorial((2 * n) + 2) * power(x, (2 * n) + 1);
                i = i + 1;
            }
        }

        //180-270
        else if (x > 180 && x < 270)
        {
            x = Radians(x - 180);         //transformation into radians(third quarter)
            int i = 0;
            for (int n = 0; n <= 15; n++)
            {
                tan_x += power(-1, n) * power(2, (2 * n) + 2) * ((power(2, (2 * n) + 2)) - 1) * B[i] /
                         factorial((2 * n) + 2) * power(x, (2 * n) + 1);
                i = i + 1;
            }
        }

        //270-360
        else if (x > 270 && x <= 360)
        {
            x = Radians(x - 360);         //transformation into radians(fourth quarter)
            int i = 0;
            for (int n = 0; n <= 15; n++)
            {
                tan_x += power(-1, n) * power(2, (2 * n) + 2) * ((power(2, (2 * n) + 2)) - 1) * B[i] /
                         factorial((2 * n) + 2) * power(x, (2 * n) + 1);
                i = i + 1;
            }
        }
    }
    return tan_x;
}
