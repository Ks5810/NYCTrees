/*******************************************************************************
  Title          : tree.h
  Author         : Stewart Weiss
  Created on     : February  16, 2019
  Description    : The interface file for the Tree class
  Usage          :
  Modifications  : Modified by Keisuke Suzuki
*******************************************************************************/
#ifndef __Tree_H__
#define __Tree_H__

#include "../GPS/gps.h"

using namespace std;

/** class Tree
 *  The Tree class represents an individual tree from the NYC Open Data
 *  2015 Tree Census. Only ten of the data members are stored in an object of
 *  class Tree, as described above.
 */
class Tree{
    public:
    
    /** Tree() is a default constructor with default value which can initialize
     *  field of zipcode, spc_common, latitude and/or longitude.
     */
    explicit Tree(int zip=0, string="", double lat=0, double lon=0);
    
    /** Tree(str) is a constructor that expects a csv string.
     *  The string must contain 41 fields, separated by commas, in the order 
     *  specified in the Data Dictionary from the NYC Open Data website. The
     *  constructor extracts the ten fields listed above, validating each
     *  of them. Each field is expected to be of the correct type. If any are 
     *  invalid, it creates an empty tree.
     */
    explicit Tree(const string &str);
    
    /** operator<<(os,t)  Overloaded stream insertion operator
     *  writes the Tree t onto the stream os as a comma-separated-values string
     *  converting the floats to fixed decimals with precision 5 digits.
     *  The members of the Tree object are  printed in the same 
     *  order as they are described in the Data Dictionary above, EXCEPT THAT
     *  the species common name is printed FIRST.
     *  @param ostream os [inout] 
     *  @param Tree    t  [in]    
     *  @return ostream&   
     */
    friend ostream &operator <<(ostream &os, const Tree &t);
    
    /** operator== (t1,t2)  compares two trees for key pair equality
     *  @param Tree   t1  [in] 
     *  @param Tree   t2  [in]
     *  @return bool  true iff t1 and t2 have the same common name and id 
     *                      case-insensitively
     */
    friend bool operator ==(const Tree &t1, const Tree &t2);
    
    /** operator< (t1,t2)  checks if key pair of t1 is less than key pair of t2
     *  @param Tree   t1  [in] 
     *  @param Tree   t2  [in]
     *  @return bool  true if  the common name of t1 < common name of t2 
     *                case insensitively or they are the same but 
     *                t1's id < t2's id. 
     */
    friend bool operator <(const Tree &t1, const Tree &t2);
    
    /** samename(t1,t2)  checks if the names of t1 and t2 are identical
     *  @param Tree   t1  [in] 
     *  @param Tree   t2  [in]
     *  @return bool  true if  the common name of t1 equals common name of t2 
     *                case insensitively. 
     */
    friend bool samename(const Tree &t1, const Tree &t2);
    
    /** islessname(t1,t2)  checks if the name of t1 precedes name of t2 
     *  @param Tree   t1  [in] 
     *  @param Tree   t2  [in]
     *  @return bool  true if  the common name of t1 precedes common name of t2 
     *                case insensitively. 
     */
    friend bool islessname(const Tree &t1, const Tree &t2);
    
    /** issamezip() is a friend function that returns true if zip codes of lhs
     *  and rhs are identical otherwise return false.
     */
    friend bool issamezip(const Tree &t1, const Tree &t);
    
    friend bool isclose(const Tree &t1, const Tree &t2, double distance);
    
    /** A bunch of get-functions
     *  The next nine methods are accessor functions that retrieve the value
     *  of the corresponding private data member. Their meaning should be
     *  clear, possibly except for life_status(), which returns the tree's status
     *  member, and the tree_health() which returns its health member.
     */
    string common_name() const;
    
    string borough_name() const;
    
    string nearest_address() const;
    
    string life_status() const;
    
    string tree_health() const;
    
    int id() const;
    
    int zip_code() const;
    
    int diameter() const;
    
    void get_position(double &latitude, double &longitude) const;
    
    private:
    
    int tree_id;
    int tree_dbh;
    string status;
    string health;
    string spc_common;
    int zipcode;
    string address;
    string boroname;
    double latitude;
    double longitude;
};

#endif /* __Tree_H__ */


