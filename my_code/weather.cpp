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
	os << w.station_nm << ": Has a rating of " << w.rating << " at "
		 << w.my_loc << endl;
	for (WReading wr : w.wreadings) {
		os << wr;
	}
	return os;
}

ostream& operator << (ostream& os, const WReading& wr) {
	os << wr.date << ": " << "Temp: " << wr.temperature << "; "
	   << "Humidity: " << wr.humidity << "; "
	   << "Windspeed: " << wr.windspeed << endl;
	return os;
}

int Weather::get_rating() const {
	return rating;
}

void Weather::set_rating(int new_rating) {
	rating = new_rating;
}

void Weather::add_reading(WReading wr) {
	wreadings.push_back(wr);
}
