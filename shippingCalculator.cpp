#include <iostream>
#include <math.h>
#include <string>
#include <vector>

#include <Product.h>
#include <Catalogue.h>
#include <Shipping.h>

using namespace std;

struct ShippingRecord
{
	string prodName;	
	int packingFee;
	int weight;
	Location start;
	ShippingType type;
	int shippingCost;

};

void fillCatalogue(Catalogue& catalogue)
{
	// adding products to catalogue
	Product p1("p1", 250, 200,20,regular, Location(20,5));
	Product p2("p2", 250, 200,20,fragile, Location(20,5));
	Product p3("p3", 250, 200,20,inflammable, Location(20,5));
	Product p4("p4", 250, 200,20,inflammable, Location(20,5));

	catalogue.addProduct(p1);
	catalogue.addProduct(p2);
	catalogue.addProduct(p3);
	catalogue.addProduct(p4);
	
}

int main(int argc, char** argv) {
	
	Catalogue catalogue;

	fillCatalogue(catalogue);
	ShippingHandler shippingHandler;
	
	// get user input
	int N, id, x , y;
	string prodName;
	Product p;
	cout<<"enter deilvery x coord \n";
	cin>>x;
	cout<<"enter deilvery y coord \n";
	cin>>y;
	
	Location delLoc(x,y);
	cout<<"number of products\n";
	cin>>N;
	
	for(int i= 0; i< N; i++)
	{
		cout<<"name for product " <<i<<" ";
		cin>>prodName;
		cout<<catalogue.findProductOpt(prodName)<<"\n";
		if((id = catalogue.findProduct(prodName))>0)
		{
				p = catalogue.getProduct(id);
		}
		ShippingRecord sr;
		sr.prodName = p.getName();
		ShippingType st = shippingHandler.suggestMethod(delLoc.getDistance(p.getProcLoc()), p.getVolumetricWt());
		int fee = shippingHandler.shippingFee(delLoc.getDistance(p.getProcLoc()), p.getVolumetricWt(),st);
		cout<<"product id "<<p.getId()<<" "<<st<<"\n";
		cout<<fee;
	}
}


