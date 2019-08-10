<h1 align="center">NYCTree</h1>
<p align="center"><strong>Description</strong>

<br>
<p align="center">This is a school project process a <a
href="https://data.cityofnewyork.us/Environment/2015-Street-Tree-Census-Tree-Data/uvpi-gqnh">dataset</a>
from NYC Open Data which includes information about more than 680,000
trees on the streets of New York City. It will allow a user to query
this data set to obtain information about selected aspects of the data,
such as how many trees of a given species are growing, borough by
borough, or which trees are within a given distance of a given GPS
location. The user will be able to specify a fragment of a species
common name, such as "oak" and the program will display the frequency of
occurrence of all types of oak trees throughout the city, such as pin
oaks, sawtooth oaks, scarlet oaks, and white oaks.</p> <br/>

<h2>Directory Structire</h2>
<pre>
.
├── bin
│   ├── NYCTreeInfoExe                
│   └── runAllCommands
├── CMakeLists.txt
├── commandfiles
├── inputfiles
├── README.md
└── src
    ├── AVLTree
    │   ├── AvlTree.cpp
    │   └── AvlTree.h
    ├── Command
    │   ├── command.cpp
    │   └── command.h
    ├── GPS
    │   ├── gps.cpp
    │   └── gps.h
    ├── main.cpp
    ├── Tree
    │   ├── tree.cpp
    │   └── tree.h
    ├── TreeCollection
    │   ├── tree_collection.cpp
    │   ├── __tree_collection.h
    │   └── tree_collection.h
    └── TreeSpecies
        ├── tree_species.cpp
        ├── __tree_species.h
        └── tree_species.h
<h2>Commands Description</h2>

> **tree_info** *tree _to_find* 
> > where tree_to_find is a string that might contain white space.This
> > command lists certain information about the trees whose common name
> > tree_to_find. Details about which information is output by the
> > command and the defnition of matches are in Section 6.1 below.

>  **listall_names** 
>  > Prints all tree common names found in the TreeCollection, one name
>  > per line. Prints the entire stored set of tree objects in sorted
>  > order, one per line. The tree objects are printed as a
>  > comma-separated-values file, with the ten stored fields of each
>  > tree printed one after the other on each line, in the order
>  > specified in Section 7.1 below.
							
>  **listall_inzip** *zipcode* 
> > where zipcode is an int type. Lists the common names of all trees
> > found in the given zipcode, together with how many of each occur in
> > that zipcode, in the form	common_name:	countone per line. For
> > example, if three red oaks, fourhemlocks, and two spruce are in the
> > given zipcode its output looks like	red oak: 3	hemlock: 4 spruce: 2

> **list_near** *latitude* *longitude* *dist* 
> >where latitude ,longitude , and dist are fixed point decimal numbers,
> >lists the common names and frequencies of all trees within dist
> >kilometers of the given GPS point (latitude,longitude ).

<h2>Usage</h2>

1. download this project as zip and extract it to preferred location

2. cd into the location and type : <pre> mkdir build </pre>
3. compile and link by typing: <pre> cd build && cmake .. && make</pre>
4. set path Variable: <pre>export PATH=$PATH:$PWD/../bin</pre>
5. execute the program: 
   *  with all commands in commandfile by typing: <pre>cd .. && runAllCommands </pre> 
   * or run custom command defined below: <pre> cd .. && NYCTreeInfoExe
     <*InputFilePath*> <*CommandFilePath*> </pre>

<h2></h2> 
<p1>Prease
     visit <a
     href="http://www.compsci.hunter.cuny.edu/~sweiss/course_materials/csci335/assignments_s19/project1.pdf">
     here</a> for more detailed specification</p>
