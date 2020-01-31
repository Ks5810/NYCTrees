/*******************************************************************************
Title           : tree_collection.h
Author          : Keisuke Suzuki
Created on      : Apr 03, 2019
Description     :
Modifications   : made by Keisuke Suzuki on Aug 06, 2019
*******************************************************************************/

#ifndef SW2_TREE_COLLECTION_H_
#define SW2_TREE_COLLECTION_H_

#include "__tree_collection.h"
#include"../Tree/tree.h"
#include "../TreeSpecies/tree_species.h"
#include "../AVLTree/AvlTree.h"

#define rep(i, n) for(int i=0;i<n;i++)

class TreeCollection: public __TreeCollection{
    public:
    
    explicit TreeCollection();
    
    TreeCollection(TreeCollection &rhs);
    
    int total_tree_count() override;
    
    int count_of_tree_species(const string &species_name) override;
    
    int count_of_tree_species_in_boro(const string &species_name,
                                      const string &boro_name) override;
    
    int get_counts_of_trees_by_boro(const string &species_name,
                                    boro tree_count[5]) override;
    
    int count_of_trees_in_boro(const string &boro_name) override;
    
    int add_tree(Tree &new_tree) override;
    
    void print_all_species(ostream &out) const override;
    
    void print(ostream &out) const override;
    
    list<string> get_matching_species(
        const string &species_name) const override;
    
    list<string> get_all_in_zipcode(int zipcode) const override;
    
    list<string> get_all_near(double latitude, double longitude,
                              double distance) const override;
    
    private:
    
    const Tree ITEM_NOT_FOUND;
    AvlTree<Tree> tree_collection;
    TreeSpecies species;
    unordered_map<string, array<int, 5>> boro_map;
    int count_by_boro[5]={};
    
    const string boro_name[5]={
        "Bronx", "Manhattan", "Brooklyn", "Queens", "Staten Island"
    };
};

#endif //SW2_TREE_COLLECTION_H_
