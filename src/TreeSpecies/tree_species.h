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

/** class __TreeSpecies is an abstract class encapsulating tree species names.
 *  This class provides methods to print all species names, to return how many
 *  species names have been found, but most importantly, it has a method, which
 *  when given a species partial name, returns a list of all species whose
 *  common names matches that partial name according to the Matching Rules above.
 */
class TreeSpecies: __TreeSpecies{
    public:
    
    TreeSpecies();
    
    /** print_all_species(out) prints all species names on out, one per line
     *  This writes the set of all common names found in the data set to the
     *  output stream out, one per line. The species names are printed in
     *  lexicographic order, using the default string comparison ordering
     *  @param ostream& [in,out]  out  the stream to be modified
     */
    void print_all_species(ostream &out) const override;
    
    /** number_of_species() returns the number of distinct species names
     *  This returns the total number of distinct species common names found in
     *  the data set.
     *  @return int  The number of species common names
     */
    int number_of_species() const override;
    
    /** add_species(s)  inserts species s into the container
     *  This adds the species to the TreeSpecies container.
     *  @param string s [in]  the string to be added.
     *  @return int It returns a 0 if the species was already in the
     *              TreeSpecies container and a 1 if it was not.
     */
    int add_species(const string &species) override;
    
    /** get_matching_species(s) returns a list of species that match s
     * @note This returns a list<string> object containing a list of all of the
     * actual tree species that match a given parameter string partial_name.
     * This method should be case insensitive. The list returned by this
     * function should not contain any duplicate names and may be empty.
     * The rules for matching are those described above.
     * @param string partial_name [in] string to match
     * @return list<string> list of matching species names
     */
    list<string> get_matching_species(const string &partial_name)const override;
    private:
    
    /** specie_map is a map that has specie common name as a first, and list
     * of strings containing divided by ' ' or '-'.
     * NOTE: second member has '-', for matching purpose, but ' '.
     */
    map<string, list<string>> species_map;
};

#endif //SW2_TREE_SPECIES_H
