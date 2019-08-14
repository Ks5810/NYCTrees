/*******************************************************************************
Title           : tree_species.h
Author          : Keisuke Suzuki
Created on      : Apr 13, 2019
Description     :
Modifications   : made by Keisuke Suzuki on Aug 13, 2019
                  added header comment
*******************************************************************************/

#ifndef SW2_TREE_SPECIES_H
#define SW2_TREE_SPECIES_H

#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <map>
#include <set>
#include <vector>

#include"__tree_species.h"
#include "../Tree/tree.h"

using namespace std;


class TreeSpecies: __TreeSpecies{
    public:
    
    TreeSpecies();
    
    void print_all_species(ostream &out) const override;

    int number_of_species() const override;
    
    int add_species(const string &species) override;
    
    /** get_matching_species(s) returns a list of species that match s
     * @note this returns a list<string> object containing a list of all of the
     * actual tree species that match a given parameter string partial_name.
     * This method should be case insensitive. The list returned by this
     * function should not contain any duplicate names and may be empty.
     */
    list<string> get_matching_species(const string &partial_name)const override;
    private:
    
    /** specie_map is a map that has specie common name as a first, and list
     * of strings containing divided by ' ' or '-'.
     * @note second elements have '-' for matching purpose, but ' '.
     */
    map<string, list<string>> species_map;
};

#endif //SW2_TREE_SPECIES_H
