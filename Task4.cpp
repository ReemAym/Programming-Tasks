/*
Name: Mariam Ashraf Amin          ID:20200520
Name: Reem Ayman Abd El-fattah    ID:20200186
*/

#include <iostream>        //Preprocessor directive
using namespace std;       //Which namespace to use

//functions prototype
int Days_spent();
void Time();
double accommodation();
double rejected_accommodation();
double transport();
double rejected_expenses ();
double conference_fees();
double total_meals();
double rejected_meals(double breakfast,double lunch,double dinner);

//Variables definition
static int days, depart_hour,depart_min,arrive_hour,arrive_min;
static double accom_day,accom_fees=0,breakfast,lunch,dinner;
static double travel_cost1 = 0, travel_cost2 = 0, travel_cost3 = 0, taxi_days, rented_car_days;
static double means_price, parking_fees = 0, parking_per_day, ticket_price = 0, travel_cost, price_rent_car = 0;
static double price_rent_car_day, rejected_park_car_day, rejected_park_car = 0, rejected_park_car_day2, rejected_park_car2 = 0;
static double rej_means_price_all = 0, parking_per_day2, parking_fees2, rej_means_price;
static string time1,time2;

int main()
{
    //call function
    Days_spent();
    Time();

    double total =accommodation()+conference_fees()+transport()+total_meals();
    double total_rejected = rejected_accommodation()+rejected_expenses()+ rejected_meals(breakfast,lunch,dinner);

    cout<<"The total = "<<total<<endl;
    cout<<"The total rejected = "<<total_rejected<<endl;
    cout<<"The total that the company will pay = "<<(total-total_rejected)<<endl;

    return 0;
}

//Days_spent Function
//asking and entering days
int Days_spent()
{
    cout<<"Enter how many days were spent on the trip: " ;
    cin>>days;
    while (days<1)
    {
        cout<<"Invalid days. Please enter number of days again."<<endl;
        cin>>days;
    }
    return days;
}

//Time Function
//asking and entering time
void Time() {
    char ch = ':';

    cout << "What time did the employee depart on the first day of the trip? (hour:min Am/Pm)\n";
    cin >> depart_hour >> ch >> depart_min >> time1;
    while (depart_hour > 12 || depart_min > 59 || time1 != "am" && time1 != "Am" && time1 != "pm" && time1 != "Pm")
    {
        cout << "Invalid Time. Please enter depart time again." << endl;
        cin >> depart_hour >> ch >> depart_min >> time1;
    }

    cout << "What time did the employee arrive back home on the last day of the trip? (hour:min Am/Pm)\n";
    cin >> arrive_hour >> ch >> arrive_min >> time2;
    while (arrive_hour > 12 || arrive_min > 59 || time2 != "am" && time2 != "Am" && time2 != "pm" && time2 != "Pm")
    {
        cout << "Invalid Time. Please enter arrive time again." << endl;
        cin >> arrive_hour >> ch >> arrive_min >> time2;
    }
    while (arrive_hour<=depart_hour && time1==time2 && days==1)
    {
        cout << "Invalid Time. Please enter arrive time again." << endl;
        cin >> arrive_hour >> ch >> arrive_min >> time2;
    }
}

//accommodation Function
//asking and entering accommodation per day
double accommodation()
{
    cout << "How much was accommodation per day?\n";
    cin >> accom_day;
    while (accom_day < 0)
    {
        cout << "Invalid fees. Please enter accommodations fees again\n";
        cin >> accom_day;
    }
    accom_fees=accom_day*days;
    return accom_fees;
}
double rejected_accommodation()
{
    int num_days =days;
    double total_accom =accom_fees,rejected_accom=0;
    if (accom_day>500)
    {
        rejected_accom=total_accom - num_days*500;
    }
    return rejected_accom;
}

//total_meals Function
//calculate meals cost
double total_meals()
{
    double total_meals_cost =0;
    cout<<"Please enter the cost of the breakfast meal: ";
    cin>>breakfast;
    cout<<"Please enter the cost of the lunch meal: ";
    cin>>lunch;
    cout<<"Please enter the cost of the dinner meal: ";
    cin>>dinner;

    int num_day = days;

    total_meals_cost+= (breakfast+lunch+dinner)*(num_day-2);

    //depart time
    if (time1=="Am"||time1=="am" && depart_hour<8){
        total_meals_cost+=breakfast+lunch+dinner;
    }
    else if (time1=="Am" ||time1=="am" && depart_hour>=8 && depart_hour<=11)
    {
        total_meals_cost+=lunch+dinner;
    }
    else if (time1=="Pm" ||time1=="pm" && depart_hour<6 || depart_hour==12)
    {
        total_meals_cost+=dinner;
    }

    //arrive time
    if (time2=="Am"||time2=="am" && arrive_hour>9 || arrive_hour==9 && arrive_min!=0)
    {
        total_meals_cost+=breakfast;
    }
    else if (time2=="Pm"|| time2=="pm" && arrive_hour==12 ||arrive_hour==1 && arrive_min==0)
    {
        total_meals_cost+=breakfast;
    }
    else if (time2=="Pm" ||time2=="pm" && arrive_hour>1 || arrive_hour==1 && arrive_min!=0 && arrive_hour<7)
    {
        total_meals_cost+=lunch+breakfast;
    }
    else if (time2=="Pm" ||time2=="pm" && arrive_hour==7 && arrive_min==0)
    {
        total_meals_cost+=lunch+breakfast;
    }
    else if (time2=="Pm" ||time2=="pm" && arrive_hour==7 && arrive_min!=0)
    {
        total_meals_cost+=dinner+lunch+breakfast;
    }
    else if (time2=="Pm" ||time2=="pm" && arrive_hour>7)
    {
        total_meals_cost+=dinner+lunch+breakfast;
    }

    return total_meals_cost;
}

//rejected meals Function
//calculate rejected meals cost
double rejected_meals(double breakfast,double lunch,double dinner)
{
    double rejected_meal_cost=0;
    if (breakfast>40) {
        breakfast -= 40;
    }
    else{
        breakfast=0;
    }
    if (lunch>60) {
        breakfast -= 60;
    }
    else{
        lunch=0;
    }
    if (dinner>80) {
        dinner -= 80;
    }
    else{
        dinner=0;
    }

    int n_day = days;

    rejected_meal_cost+= (breakfast+lunch+dinner)*(n_day-2);

    //depart time
    if (time1=="Am"||time1=="am" && depart_hour<8){
        rejected_meal_cost+=breakfast+lunch+dinner;
    }
    else if (time1=="Am" ||time1=="am" && depart_hour>=8 && depart_hour<=11)
    {
        rejected_meal_cost+=lunch+dinner;
    }
    else if (time1=="Pm" ||time1=="pm" && depart_hour<6 || depart_hour==12)
    {
        rejected_meal_cost+=dinner;
    }

    //arrive time
    if (time2=="Am"||time2=="am" && arrive_hour>9 || arrive_hour==9 && arrive_min!=0)
    {
        rejected_meal_cost+=breakfast;
    }
    else if (time2=="Pm"|| time2=="pm" && arrive_hour==12 ||arrive_hour==1 && arrive_min==0)
    {
        rejected_meal_cost+=breakfast;
    }
    else if (time2=="Pm" ||time2=="pm" && arrive_hour>1 || arrive_hour==1 && arrive_min!=0 && arrive_hour<7)
    {
        rejected_meal_cost+=lunch+breakfast;
    }
    else if (time2=="Pm" ||time2=="pm" && arrive_hour==7 && arrive_min==0)
    {
        rejected_meal_cost+=lunch+breakfast;
    }
    else if (time2=="Pm" ||time2=="pm" && arrive_hour==7 && arrive_min!=0)
    {
        rejected_meal_cost+=dinner+lunch+breakfast;
    }
    else if (time2=="Pm" ||time2=="pm" && arrive_hour>7)
    {
        rejected_meal_cost+=dinner+lunch+breakfast;
    }
    return rejected_meal_cost;
}


//fees of conference or seminar Function
double conference_fees()
{
    string flag;
    int num_conf;
    double confer_fees=0,confer_fees_day;
    cout << "Did employee attend any conference or seminar? (Yes or No)\n";
    cin >> flag;
    if (flag == "yes" || flag == "Yes")
    {
        cout << "How many conferences and seminars did you attend?\n";
        cin >> num_conf;
        for (int i = 0; i < num_conf; i++)
        {
            cout << "Enter entry fees to conference or seminar per day\n";
            cin >> confer_fees_day;
            while (confer_fees_day < 0)
            {
                cout << "Invalid fees. Please enter entry fees to any conference or seminar again." << endl;
                cin >> confer_fees_day;
            }
            confer_fees+=confer_fees_day;
        }
    }
    return confer_fees;
}

//transport Function
double transport() {
    string means, answer,Answer;
    int kilometers, n;

    cout << "Did the employee travel by plane? (yes or no)\n";
    cin >> answer;
    if (answer == "yes" || answer == "Yes") {
        cout << "How much did the plane ticket cost?\n ";
        cin >> ticket_price;

        while (ticket_price < 0) {
            cout << "Invalid ticket price. Please enter ticket price again\n";
            cin >> ticket_price;
        }
    }

    cout << "Did the employee rent a car? (yes or no)\n";
    cin >> answer;
    if (answer == "yes" || answer == "Yes") {
        cout << "How many times did employee rent car?\n";
        cin >> rented_car_days;
    }
    for (int i = 0; i < rented_car_days; i++) {
        cout << "How much did employee pay for renting a car?\n";
        cin >> price_rent_car_day;

        while (price_rent_car < 0) {
            cout << "Invalid price. Please enter How much employee paid for renting a car again\n";
            cin >> price_rent_car;
        }

        price_rent_car += price_rent_car_day;

        cout << "How much did employee pay for parking per day?\n";
        cin >> parking_per_day;

        if (parking_per_day <= 25 && parking_per_day > 0) {
            parking_fees += parking_per_day;
        }

        if (parking_per_day > 25) {
            rejected_park_car_day = parking_per_day - 25;
            parking_fees += parking_per_day;
            rejected_park_car += rejected_park_car_day;
        }

    }
    travel_cost1 = parking_fees + price_rent_car;

    cout << "Did the employee use their own vehicle? \n";
    cin >> answer;
    if (answer == "yes" || answer == "Yes") {
        cout << "how many kilometers were driven? \n";
        cin >> kilometers;
    }

    while (kilometers < 0) {
        cout << "Invalid kilometers. Please enter kilometers again\n";
        cin >> kilometers;
    }
    means_price = kilometers * 0.775;

    cout << "How many days did employee park the car? \n";
    cin >> n;
    for (int i = 0; i < n; i++) {

        cout << "How much did employee pay for parking per day?\n";
        cin >> parking_per_day2;

        if (parking_per_day2 <= 25 && parking_per_day2 > 0) {
            parking_fees2 += parking_per_day2;
        }

        if (parking_per_day2 > 25) {
            rejected_park_car_day2 = parking_per_day2 - 25;
            parking_fees2 += parking_per_day2;
            rejected_park_car2 += rejected_park_car_day2;
        }
    }
    travel_cost2 = means_price + parking_fees2;

    cout<<"Did you take a taxi"<<endl;
    cin>>Answer;
    if (Answer=="Yes"|| Answer=="yes") {

        cout << "How many days was taxi been used?\n";
        cin >> taxi_days;
    }
    for (int i = 0; i < taxi_days; i++) {

        cout << "How much did employee pay for using a taxi per day?\n";
        cin >> means_price;

        if (means_price <= 100 && means_price > 0) {
            travel_cost3 += means_price;
        }
        if (means_price > 100) {
            rej_means_price = means_price - 100;
            travel_cost3 += means_price;
            rej_means_price_all += rej_means_price;
        }
    }

    travel_cost = ticket_price + travel_cost1 + travel_cost2 + travel_cost3;
    return travel_cost;
}

double rejected_expenses ()
{
    double rejected=0;
    rejected+=rejected_park_car+ rejected_park_car2+ rej_means_price_all;
    return rejected;
}

