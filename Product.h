#include<string>

#ifndef _PRODUCT_H_
#define _PRODUCT_H_

using namespace std;

enum HandlingType
{
		regular,
		fragile,
		inflammable
};

enum ShippingType
{
	landType,
	droneType,
	airType	
};

struct Location
{
	int x;
	int y;
	Location(int xCoord, int yCoord)
	{
		x=xCoord;
		y=yCoord;
	}
	Location()
	{
	}
	int getDistance(Location dest)
	{
		int distance = sqrt(pow(dest.x-x,2)+pow(dest.y-y,2));
		return distance;
	}
};

class Product
{
	private:
		string name;
		int id;
		int length;
		int breadth;
		int height;
		HandlingType handlingType;
		Location procureLoc;
		
	public:

		Product()
		{
		}
		Product(string n, int l, int b, int h, HandlingType ht, Location pl):name(n), length(l), breadth(b), height(h), handlingType(ht), procureLoc(pl)
		{
			id=0;
		}
		string getName() const
		{
			return name;
		}
		int getId()
		{
			return id;
		}
		
		void setId(int i)
		{
			id = i;
		}
		int getVolumetricWt()
		{
			return getVolume()/5000;
		}
		int getVolume()
		{
			return (length*breadth*height);
		}
		Location getProcLoc()
		{
			return procureLoc;
		}
};

#endif
