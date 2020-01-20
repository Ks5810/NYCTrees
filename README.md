<h1 align="center">NYCTrees</h1>
<br>
<p align="center"><strong>Description</strong>
<p align="center">This school project process a <a href="https://data.cityofnewyork.us/Environment/2015-Street-Tree-Census-Tree-Data/uvpi-gqnh">dataset</a> from NYC Open Data which includes information about more than 680,000 trees on the streets of New York City. It will allow a user to query this data set to obtain information about selected aspects of the data, such as how many trees of a given species are growing, borough by borough, or which trees are within a given distance of a given GPS
location. The user will be able to specify a fragment of a species common name, such as "oak" and the program will display the frequency of
occurrence of all types of oak trees throughout the city, such as pin oaks, sawtooth oaks, scarlet oaks, and white oaks. <p></p> 


<h2>Command Description</h2>

> **tree_info**  *tree _to_find* 
> > where tree_to_find is a string that might contain white space.This
> > command lists certain information about the trees whose common name
> > tree_to_find. For details about which information is output by the
> > command, and definition of "match", please refer to the link at the 
> > bottom of this page.

>  **listall_names** 
>  > Prints all tree common names found in the TreeCollection, one name
>  > per line. Prints the entire stored set of tree objects in sorted
>  > order, one per line. The tree objects are printed as a
>  > comma-separated-values file, with the ten stored fields of each
>  > tree printed one after the other on each line, in the order
>  > specified in the link at the bottom.
							
>  **listall_inzip**  *zipcode* 
> > where zipcode is an int type. Lists the common names of all trees
> > found in the given zipcode, together with how many of each occur in
> > that zipcode, in the form common_name: countone per line. For
> > example, if three red oaks, fourhemlocks, and two spruce are in the
> > given zipcode its output looks like	red oak: 3	hemlock: 4 spruce: 2

> **list_near**  *latitude*  *longitude*  *dist* 
> >where latitude ,longitude , and dist are fixed point decimal numbers,
> >lists the common names and frequencies of all trees within dist
> >kilometers of the given GPS point (latitude,longitude ).

<h2>Usage</h2>

1. Download and extract or clone this repository, and cd into the directory.
2. There are two ways to build the project.
    - Using cmake:
        ```shell
        mkdir build && cd build
        ```
        ```shell
        cmake.. && make
        ```
    - Using make:
        ```shell
        make
        ```
3. Set PATH to bin:
    ```shell
         cd .. && export PATH=$PATH:$PWD/bin
    ```
4. Execute the program:
    - If the project is build by cmake:
        - To run all the commands in command-file by typing:
            ```shell
            runAll
            ```
        - or run a custom command defined above:
            ``` shell
            ./bin/NYCTreeInfoExe [InputFilePath] [CommandFilePath]
            ```
    - If the project is build by make:
        - To run all the commands in command-file by typing:
            ```shell
            make run
            ```
        - or run a custom command:
            ```shell
            ./bin/exe [InputFilePath] [CommandFilePath]
            ```


<h2></h2> 
<p>Please
     visit <a
     href="http://www.compsci.hunter.cuny.edu/~sweiss/course_materials/csci335/assignments_s19/project1.pdf">
     here</a> for more detailed specification</p>
