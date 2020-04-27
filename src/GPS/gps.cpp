/*******************************************************************************
Title           : gps.cpp
Author          : Keisuke Suzuki
Created on      : May 10, 2019
Description     :
Modifications   : made by Keisuke Suzuki on Aug 06, 2019

License        : Copyright 2020 Keisuke Suzuki
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
  
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
*******************************************************************************/

#include "gps.h"

const double R=6372.8;              // radius of earth in km
const double TO_RAD=M_PI/180.34;    // conversion of degree

/****************************Helper Function***********************************/

double haversine(double lat1, double lon1, double lat2, double lon2){
    lat1*=TO_RAD;
    lat2*=TO_RAD;
    lon1*=TO_RAD;
    lon2*=TO_RAD;
    double dLat=(lat2-lat1)/2;
    double dLon=(lon2-lon1)/2;
    double a=sin(dLat);
    double b=sin(dLon);
    return 2*R*asin(sqrt(a*a+cos(lat1)*cos(lat2)*b*b));
}

/******************************GPS class***************************************/

GPS::GPS(double lon, double lat): longitude(lon), latitude(lat){
    //if((lon<-180.0 || 180.0<lon) || (lat<-90.0 || 90.0<lat))
      //  throw BadPoint();
}

GPS &GPS::operator =(const GPS &rhs) = default;

double distance_between(const GPS &point1, const GPS &point2){
    return haversine(point1.latitude, point1.longitude,
                     point2.latitude, point2.longitude);
}

std::ostream &operator <<(std::ostream &out, const GPS &point){
    return out<<std::fixed<<"POINT("
              <<point.latitude<<" "<<point.longitude<<")"<<std::endl;
}

/**
GPS reproject_coords(double x, double y){
    
    PJ_CONTEXT *C;
    PJ  *P;
    PJ_COORD nad83=proj_coord(x,y,0,0);
    PJ_COORD wgs84;
    
    C=proj_context_create();
    std::string NAD83_LIC="+proj=lcc +lat_1=40.66666666666666 +lat_2="
                     "41.03333333333333 +lat_0=40.16666666666666 +lon_0=-74 "
                    "+x_0=300000 +y_0=0 +datum=NAD83 +units=us-ft +no_defs";
    
    std::string WGS84_LL="+proj=longlat +datum=WGS84";
    
    P=proj_create_crs_to_crs(C,NAD83_LIC.c_str(),WGS84_LL.c_str(), nullptr);
    
    if(nullptr==P){
        std::cerr<<"falid to create PROJ conversion"<<std::endl;
        throw BadCRS();
    }
    
    wgs84=proj_trans(P,PJ_FWD,nad83);
    x=wgs84.lp.lam;
    y=wgs84.lp.phi;
    
    return GPS(x,y);
}
*/
