/*******************************************************************************
Title           : gps.h
Author          : Keisuke Suzuki
Created on      : May 13, 2019
Description     :
Modifications   : made by Keisuke Suzuki on Aug 06, 2019
*******************************************************************************/
#ifndef __GPS_H__
#define __GPS_H__

using namespace std;

struct BadPoint{
    std::string what() const{
        return "BadPoint";
    }
};

struct BadCRS{
    std::string what() const{
        return "Failed to create process";
    }
};

class GPS{
    public:
    
    explicit GPS(double =0, double =0);
    
    GPS &operator =(const GPS &rhs);
    
    friend double distance_between(const GPS &point1, const GPS &point2);
    
    friend std::ostream &operator <<(std::ostream &out, const GPS &point);
    
    //friend GPS reproject_coords(double x, double y);
    
    private:
    double longitude;
    
    double latitude;
};

#endif /* __GPS_H__ */
