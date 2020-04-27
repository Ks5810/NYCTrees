/*******************************************************************************
Title           : tree.cpp
Author          : Keisuke Suzuki
Created on      : Apr 01, 2019
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
    GNU General Public License for more details
*******************************************************************************/

#include "tree.h"

/****************************Helper Functions**********************************/

//checks if the string only has numeric value;
bool is_numeric(const char *string){
    int sizeOfString=strlen(string);
    int i=0;
    bool isNumeric=true;
    
    for(; i<sizeOfString; ++i){
        if(!(isdigit(string[i]) || string[i]=='.' || string[i]=='-')){
            isNumeric=false;
            break;
        }
    }
    return isNumeric;
}

//to lower case string
string lower(string str){
    transform(str.begin(), str.end(), str.begin(),
              [](unsigned char c){ return tolower(c); });
    return str;
}

//for case insensitivity
bool match(const string &lhs, const string &rhs){
    return lower(lhs)==lower(rhs);
}

/****************************Tree Class****************************************/

/** Tree(int=0, string="", double=0, double=0) is a default constructor */
Tree::Tree(int zip, string name, double lat, double lon):tree_id(0),
        tree_dbh(0),spc_common(name),zipcode(zip),latitude(lat),longitude(lon){}
        
/** Tree(str) is a constructor which processes a csv string and store
  * values to corresponding member variables */
Tree::Tree(const std::string &str){
    
    stringstream ss(str);
    string temp;
    char junk;
    bool valid_data=true;
    int i=0;
    
    while(!ss.eof()){
        if(ss.peek()=='"'){
            ss>>junk;           //ignore '"'
            getline(ss, temp, '"');
            ss>>junk;           //ignore ','
        }
        else getline(ss, temp, ',');
        
        switch(i++){            //set corresponding fields
            case 0:
                if(is_numeric(temp.c_str()))
                    tree_id=stoi(temp);
                else valid_data=false;
                break;
            case 1:
                if(is_numeric(temp.c_str()))
                    tree_dbh=stoi(temp);
                else valid_data=false;
                break;
            case 6:
                if(temp.empty() || temp=="Alive" || temp=="Dead" ||
                   temp=="Stump")
                    status=temp;
                else valid_data=false;
                break;
            case 7:
                if(temp.empty() || temp=="Good" || temp=="Fair" || temp=="Poor")
                    health=temp;
                else valid_data=false;
                break;
            case 9:spc_common=temp;
                break;
            case 24:address=temp;
                break;
            case 25:
                if(is_numeric(temp.c_str()) && stoi(temp)>=0 &&
                                                            stoi(temp)<100000)
                    zipcode=stoi(temp);
                else valid_data=false;
                break;
            case 29:
                if(temp=="Manhattan" || temp=="Queens" || temp=="Bronx" ||
                   temp=="Brooklyn" ||temp=="Staten Island")
                    boroname=temp;
                else{
                    valid_data=false;
                }
                break;
            case 37:
                if(is_numeric(temp.c_str())) latitude=stod(temp);
                else valid_data=false;
                break;
            case 38:
                if(is_numeric(temp.c_str())) longitude=stod(temp);
                else valid_data=false;
                break;
            default:break;
        }
    }
    //if data is not valid, set tree_id to 0
    if(!valid_data){
        tree_id=0;
    }
}

/* operator<<(os,t)  Overloaded stream insertion operator */
std::ostream &operator <<(ostream &os, const Tree &t){
    os<<fixed<<setprecision(5)<<t.spc_common<<", "<<t.tree_id
      <<", "<<t.tree_dbh<<", "<<t.status<<", "<<t.health<<", "<<t.zipcode
      <<", "<<t.address<<", "<<t.boroname<<", "<<t.latitude<<", "
      <<t.longitude;
    return os;
}

/* operator== (t1,t2)  compares two trees for key pair equality */
bool operator ==(const Tree &t1, const Tree &t2){
    return t1.tree_id==t2.tree_id && samename(t1, t2);
}

/* operator< (t1,t2)  checks if key pair of t1 is less than key pair of t2 */
bool operator <(const Tree &t1, const Tree &t2){
    return match(t1.spc_common, t2.spc_common)?t1.tree_id<t2.tree_id:
           lower(t1.spc_common)<lower(t2.spc_common);
}

/* samename(t1,t2)  checks if the names of t1 and t2 are identical */
bool samename(const Tree &t1, const Tree &t2){
    return match(t1.spc_common, t2.spc_common);
}

/* islessname(t1,t2)  checks if the name of t1 precedes name of t2 */
bool islessname(const Tree &t1, const Tree &t2){
    return lower(t1.spc_common)<lower(t2.spc_common);
}

/* issamezip(t1,t2)  checks if the zipcode of t1 and t2 are the same */
bool issamezip(const Tree &t1, const Tree &t2){
    return t1.zipcode==t2.zipcode;
}

/* isclose(t1, t2, distance) checks if t1 and t2 in the distance */
bool isclose(const Tree &t1, const Tree &t2, double distance){
    return distance_between(GPS(t1.latitude, t1.longitude),
                            GPS(t2.latitude, t2.longitude))<=distance;
}

/* A bunch of get-functions */
std::string Tree::common_name() const{
    return spc_common;
}

std::string Tree::borough_name() const{
    return boroname;
}

std::string Tree::nearest_address() const{
    return address;
}

std::string Tree::life_status() const{
    return status;
}

std::string Tree::tree_health() const{
    return health;
}

int Tree::id() const{
    return tree_id;
}

int Tree::zip_code() const{
    return zipcode;
}

int Tree::diameter() const{
    return tree_dbh;
}

void Tree::get_position(double &_latitude, double &_longitude) const{
    _latitude=latitude;
    _longitude=longitude;
}

   
    