#ifndef _SHIPPING_H_
#define _SHIPPING_H_

class ShippingMethod
{
	virtual int isPossible(int distance, int weight) = 0;
	virtual int shippingCharges(int distance, int weight) = 0;
};
	
class LandShipping: public ShippingMethod
{
	public:
		int isPossible(int distance, int weight)
		{
			if(distance>1605 || weight >500)
				return 0;
			else
				return 1;	
		}
		int shippingCharges(int distance, int weight)
		{
						return (distance+weight)*10;
		}
};

class DroneShipping: public ShippingMethod
{
	public:
		int isPossible(int distance, int weight)
		{
			if(distance>100 || weight >50)
				return 0;
			else
				return 1;	
		}
		int shippingCharges(int distance, int weight)
		{
						return (distance+weight)*10;
		}
};

class AirShipping: public ShippingMethod
{
	public:
		int isPossible(int distance, int weight)
		{
			if(distance>1605 || distance < 50 || weight >100)
				return 0;
			else
				return 1;	
		}
		int shippingCharges(int distance, int weight)
		{
			return (distance+weight)*10;
		}
		
};	

class ShippingHandler
{
	LandShipping land;
	DroneShipping drone;
	AirShipping air;
	
	public:
		ShippingType suggestMethod(int distance, int weight)
		{
			if(air.isPossible(distance, weight))
			{
				return airType;
			}
			else if(drone.isPossible(distance, weight))
			{
				return droneType;
			}
			else
			{
				return landType;
			}
		}
		int shippingFee(int distance, int weight, ShippingType type)
		{
			if(type == airType)
			{
				return air.shippingCharges(distance, weight);
			}
			if(type== droneType)
			{
				return drone.shippingCharges(distance, weight);
			}
			if(type == landType)
			{
				return land.shippingCharges(distance, weight);				
			}
		}
};

#endif

