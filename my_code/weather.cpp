#include <iostream>
#include <string>
#include "weather.h"

using namespace std;

/*
 * A constructor for weather class.
 * */
Weather::Weather(std::string nm, GPS loc) :
    station_nm(nm), my_loc(loc) {
}


string Weather::get_name() const {
    return station_nm;
}

ostream& operator << (ostream& os, const GPS& gps) {
	cout << "(Latitude: " << gps.latitude << ", Longitude: "
		 << gps.longitude << ")";
	return os;
}

ostream& operator << (ostream& os, const Weather& w) {
	cout << w.station_nm << ": Has a rating of " << w.rating << " at "
		 << w.my_loc << endl;
	return os;
}
