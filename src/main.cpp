#include <iostream>
#include "Store.h"

using namespace std;

int main()
{
	Store movieStore;
	movieStore.initialize();

	movieStore.addCustomer(10, "GyuHo");

	movieStore.addType("HORROR", 4000);

	movieStore.addMovie("The Matrix1", "REGULAR");
	movieStore.addMovie("The Matrix2", "NEW_RELEASE");
	movieStore.addMovie("The Matrix3", "CHILDRENS");
	movieStore.addMovie("The Final Destination", "HORROR");

	movieStore.rental("GyuHo", "The Matrix1", 3);
	movieStore.rental("GyuHo", "The Matrix2", 2);
	movieStore.rental("GyuHo", "The Matrix3", 1);
	movieStore.rental("GyuHo", "The Final Destination", 2);

	movieStore.statement("GyuHo", OUTPUT_TYPE::E_OUT_JSON);

    return 0;
}
