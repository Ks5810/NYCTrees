/*******************************************************************************
Title           : tree_collection.cpp
Author          : Keisuke Suzuki
Created on      : Apr 03, 2019
Description     :
Modifications   : made by Keisuke Suzuki on Aug 06, 2019
*******************************************************************************/

#include "tree_collection.h"

TreeCollection::TreeCollection(): ITEM_NOT_FOUND(0, "ITEM_NOT_FOUND"), tree_collection
    (ITEM_NOT_FOUND), species(TreeSpecies()){
}

TreeCollection::TreeCollection(TreeCollection &rhs): tree_collection
                                                         (rhs.tree_collection){}

int TreeCollection::total_tree_count(){
    int return_val=0;
    for(auto i:count_by_boro) return_val+=i;
    return return_val;
}

int TreeCollection::count_of_tree_species(const string &species_name){
    return species.number_of_species();
}

int TreeCollection::count_of_tree_species_in_boro(const string &species_name,
                                                  const string &_boro_name){
    int return_val=0;
    rep(i, 5)
        if(boro_name[i]==_boro_name){
            auto it=boro_map.find(species_name);
            if(it!=boro_map.end()){
                return_val=it->second[i];
            }
        }
    return return_val;
}

int TreeCollection::get_counts_of_trees_by_boro(const string &species_name,
                                                boro tree_count[5]){
    int return_val=0;
    auto it=boro_map.find(species_name);
    
    if(it!=boro_map.end()){
        rep(i, 5){
            tree_count[i].count+=it->second[i];
            return_val+=it->second[i];
        }
    }
    return return_val;
}

int TreeCollection::count_of_trees_in_boro(const string &_boro_name){
    int return_val=0;
    rep(i, 5){
        if(boro_name[i]==_boro_name)
            return_val=count_by_boro[i];
    }
    return return_val;
}

int TreeCollection::add_tree(Tree &new_tree){
    string new_name=new_tree.common_name();
    array<int, 5> temp={};
    int new_boro=0;
    rep(i, 5){
        if(new_tree.borough_name()==boro_name[i])
            new_boro=i;
    }
    if(tree_collection.find(new_tree)==ITEM_NOT_FOUND){
        count_by_boro[new_boro]++;
        tree_collection.insert(new_tree);
        if(species.add_species(new_name)){
            temp[new_boro]++;
            boro_map.insert(make_pair(new_name, temp));
        }
        else{
            for(auto i:boro_name){
                if(i==new_tree.borough_name())
                    boro_map[new_name][new_boro]++;
            }
        }
        return 1;
    }
    return 0;
}

void TreeCollection::print_all_species(ostream &out) const{
    species.print_all_species(out);
}

void TreeCollection::print(ostream &out) const{
    tree_collection.printTree();
}

list<string> TreeCollection::get_matching_species(
    const string &species_name) const{
    return species.get_matching_species(species_name);
}

list<string> TreeCollection::get_all_in_zipcode(int zipcode) const{
    list<string> result;
    Tree target(zipcode);
    
    //get trees from Avl and insert the names to set
    for(const auto &tree:tree_collection.getSameZip(target))
        result.push_back(tree.common_name());
    
    return result;
}

list<string> TreeCollection::get_all_near(double latitude, double longitude,
                                          double distance) const{
    list<string> result;
    Tree center(0, "", latitude, longitude);
    
    for(auto tree:tree_collection.getCloseElem(center,distance))
        result.push_back(tree.common_name());
    
    return result;
}





