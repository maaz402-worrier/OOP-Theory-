#include<iostream>
using namespace std;
class Ride_system{
	protected:
	string passengerName;
	int rideID;
	double baseFare;
	
	public:
		Ride_system(int id,string name,double Fare){
			passengerName=name;
			rideID=id;
			baseFare=Fare;
		}
		virtual void displayRideDetail(){	};
		virtual double calculateFare ()
		{
			return 0;
		}
		};
	class Economy_Ride:public Ride_system
	{
		double distanceKM;
		public:
			Economy_Ride(int id,string name,double Fare,double KM):Ride_system(id,name,Fare){
				distanceKM=KM;
				
			}
		
			 double calculateFare()override{
			 	return baseFare+(distanceKM * 8);
			 }
			 	void displayRideDetail()override{
				cout<<"\n~~~ Economhy Ride ~~~~\n";
			  	cout<<"Passanger Name = "<<passengerName<<endl;
			 	cout<<"Ride id        = "<<rideID<<endl;
				cout<<"Final Fare     = "<<calculateFare();
			 }
	};
		class Luxury_Ride:public Ride_system
	{
		double distanceKM;
		double serviceCharge;
		public:
			Luxury_Ride(int id,string name,double Fare,double KM,double Charge):Ride_system(id,name,Fare)
			{
				distanceKM=KM;
				serviceCharge=Charge;
				
			}
		
			 double calculateFare()override{
			 	return baseFare+(distanceKM * 8)+serviceCharge;
			 }
			 	void displayRideDetail()override{
			cout<<"\n~~~ Luxury Ride ~~~~\n";
			cout<<"Passanger Name = "<<passengerName<<endl;
			cout<<"Ride id        = "<<rideID<<endl;
			cout<<"Final Fare     = "<<calculateFare();
			 	
			 }
	};

int main(){
Economy_Ride E1(1,"Maaz",100,5);
Luxury_Ride L1(2,"Tasbeeh",1000,10,500);
E1. calculateFare();
E1.displayRideDetail();
L1. calculateFare();
L1.displayRideDetail();

return 0;
}

