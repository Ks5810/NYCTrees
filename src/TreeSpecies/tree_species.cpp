/*******************************************************************************
Title           : tree_species.cpp
Author          : Keisuke Suzuki
Created on      : Apr 06, 2019
Description     :
Modifications   : made by Keisuke Suzuki on Aug 06, 2019
*******************************************************************************/

#include "tree_species.h"

TreeSpecies::TreeSpecies() = default;

void TreeSpecies::print_all_species(ostream &out) const{
    for(const auto &i:species_map){
        out<<i.first<<'\n';
    }
}

int TreeSpecies::number_of_species() const{
    return species_map.size();
}

int TreeSpecies::add_species(const string &species){
    string temp;
    list<string> _temp;
    
    for(auto it=species.begin(); it!=species.end(); ++it){
        if(*it==' ' || *it=='-'){
            _temp.push_back(temp);
            temp="";
        }
        else if(*it=='-')
            _temp.push_back("-");
        else{
            temp+=*it;
            if(it-species.begin()==species.length()-1)
                _temp.push_back(temp);
        }
    }
    auto it=species_map.find(species);
    species_map.insert(make_pair(species, _temp));
    
    return it==species_map.end();
}

list<string> TreeSpecies::get_matching_species(
    const string &partial_name) const{
    
    set<string> result;
    list<string> _partial_name;
    list<string>::const_iterator p_it;
    stringstream ss(partial_name);
    string temp;
    
    if(partial_name.empty())
        return list<string>(result.begin(), result.end());
    
    while(getline(ss, temp, '-')){
        stringstream tss(temp);
        tss>>temp;
        _partial_name.push_back(temp);
    }
    
    for(const auto &map_elem:species_map){
        bool match=false;
        p_it=_partial_name.begin();
        for(auto l_it=map_elem.second.begin(); l_it!=map_elem.second.end(); ++l_it){
            if(*p_it==*l_it){
                match=true;
                for(; p_it!=_partial_name.end() && l_it!=map_elem.second.end(); ++p_it,
                    ++l_it){
                    if(*l_it=="-") l_it++;
                    else if(*l_it!=*p_it)
                        match=false;
                }
                break;
            }
        }
        if(match) result.insert(map_elem.first);
    }
    return list<string>(result.begin(), result.end());
}