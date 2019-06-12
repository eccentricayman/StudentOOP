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

//const double F_TO_C = 5 / 9;
const double C_TO_F = 9 / 5;

Image::Image(int w, int h, std::string flnm)
    : width(w), height(h)
{
    filename = flnm;
    image_buf = new char[image_sz()];
}

// copy constructor:
Image::Image(const Image& img2) {
	copy_fields(img2);
}

// destructor
Image::~Image() {
	if (image_buf != nullptr) {
		delete[] image_buf;
	}
}

// assignment operator:
Image& Image::operator=(const Image& img2) {
	if (this == &img2) {
		return *this;
	}
	else {
		if (image_buf != nullptr) {
			delete[] image_buf;
		}
		copy_fields(img2);
		return *this;
	}
}

int Image::image_sz() {
    return width * height;
}


void Image::copy_fields(const Image& img2) {
	width = img2.width;
	height = img2.height;
	filename = img2.filename;
	//using our image_sz cause same width/height
	image_buf = new char[image_sz()];
	for (int a = 0 ; a < image_sz() ; a++) {
		image_buf[a] = img2.image_buf[a];
	}
}


    /*
     * Setting `display() = 0` here makes this an abstract
     * class that can't be implemented.
     * */
string Image::display(std::string s) {
    return "Displaying image " + s;
}

double WReading::get_tempF() {
    return (temperature * C_TO_F) + 32;
}
