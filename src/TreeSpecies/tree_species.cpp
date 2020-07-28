/**
    tree_species.cpp
    @author Keisuke Suzuki
    @version 1.0 7/28/20
    Purpose: To Implement tree_species class
    Modifications: Made by Keisuke Suzuki on 7/28/20
    
    License: Copyright (c) 7/28/20 Keisuke Suzuki
    	This program is free software: you can redistribute it and/or modify
    	it under the terms of the GNU General Public License as published by
    	the Free Software Foundation, either version 3 of the License, or
    	(at your option) any later version.
  
    	This program is distributed in the hope that it will be useful,
    	but WITHOUT ANY WARRANTY; without even the implied warranty of
    	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    	GNU General Public License for more details
*/

#include "tree_species.h"

/****************************Helper Functions**********************************/

//to lowercase string
string str_lower( string str )
{
    transform(str.begin(), str.end(), str.begin(),
              []( unsigned char c )
              { return tolower(c); });
    return str;
}

//for case insensitivity
bool str_match( const string &lhs, const string &rhs )
{
    return str_lower(lhs) == str_lower(rhs);
}

/****************************TreeSpecies Class*********************************/

TreeSpecies::TreeSpecies() = default;

void TreeSpecies::print_all_species( ostream &out ) const
{
    for(const auto &i:species_map)
    {
        out << i.first << '\n';
    }
}

int TreeSpecies::number_of_species() const
{
    return species_map.size();
}

int TreeSpecies::add_species( const string &species )
{
    string temp;
    list <string> _temp;
    
    //store specie name devided by white space or '-' but adding '-' as one
    //word so that it stores the specie name correctly
    for(auto it = species.begin(); it != species.end(); ++ it)
    {
        if(*it == ' ' || *it == '-')
        {
            _temp.push_back(temp);
            temp = "";
        }
        else if(*it == '-')
            _temp.push_back("-");
        else
        {
            temp += *it;
            if(species.length() - 1 == size_t(it - species.begin()))
                _temp.push_back(temp);
        }
    }
    auto it = species_map.find(species);
    species_map.insert(make_pair(species, _temp));
    
    return it == species_map.end();
}

list <string> TreeSpecies::get_matching_species(
const string &partial_name ) const
{
    
    set <string> result;
    list <string> _partial_name;
    list<string>::const_iterator p_it;
    stringstream ss(partial_name);
    string temp;
    
    if(partial_name.empty())
        return list<string>(result.begin(), result.end());
    
    //store input words in partial name excluding '-'
    while(getline(ss, temp, '-'))
    {
        stringstream tss(temp);
        tss >> temp;
        _partial_name.push_back(temp);
    }
    
    //look for matching list in species_map
    for(const auto &map_elem:species_map)
    {
        bool match = false;
        p_it = _partial_name.begin();
        
        //if one of the string from _partial_name matches any string in the
        //list in species map, start checking equality for following strings
        //for size of _partial_name ignoring '-' element in the list, and if all
        //strings in partial name match, store corresponding string element in
        //the map to result.
        for(auto l_it = map_elem.second.begin(); l_it != map_elem.second.end();
            ++ l_it)
        {
            if(str_match(*p_it, *l_it))
            {
                match = true;
                for(;
                p_it != _partial_name.end() && l_it != map_elem.second.end();
                ++ p_it, ++ l_it)
                {
                    if(*l_it == "-") l_it ++;
                    else if(! str_match(*p_it, *l_it))
                        match = false;
                }
                break;
            }
        }
        if(match) result.insert(map_elem.first);
    }
    return list<string>(result.begin(), result.end());
}