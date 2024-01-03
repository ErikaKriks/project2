# project1
Second exercise of Object Programming course, year 2.
<br>An educational application for managing and analyzing student data. It includes functionality for manual and automatic entry of student information, calculation of final marks based on different criteria (average or median), reading and sorting student data from files, and implementing various strategies for categorizing and saving student data. The application measures and displays execution times for key operations, providing insights into the performance of Class data structure. The code is written in C++ and utilizes features such as file I/O, sorting algorithms, and chrono for time measurement.

## Installation
Make sure you have the following software installed on your system:
- [Visual Studio Code](https://code.visualstudio.com/)
- [GCC (GNU Compiler Collection)](https://gcc.gnu.org/)

## Getting Started

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/ErikaKriks/project2.git

2. **Open project in Visual Studio Code**
3. **Install C/C++ Extension**
4. **Build and Run:**
    - Open the terminal in VSCode (`View` > `Terminal` or `Ctrl + ``) and navigate to your project directory.
    - Run the build command to compile your C++ program:
        ```bash
        g++ -std=c++11 main.cpp functions.cpp -o myprogram
        ```
    - Execute the program:
        ```bash
        ./myprogram
        ```


### How to Use

1. **Building Your Project:**
   - Open the command palette (`View` > `Command Palette` or `Ctrl + Shift + P`) and select `Run Build Task`.
   - Choose the build task corresponding to your project.

2. **Debugging Your Program:**
   - Open the `Run` sidebar (`View` > `Run` or `Ctrl + Shift + D`) and click on the "Run" button.
   - If you've set breakpoints in your code, the debugger will stop at those points.

Remember to customize these files according to your project structure and needs. If you don't have these files yet, you can create them manually or let VSCode generate them for you by running the corresponding tasks.

Technical Specifications of Computer:
* 6-core GPU,19-core GPU
* 200GB/s memory bandwidth
* 16 GB RAM
* 512GB SSD



## Releases
This project started as a project.

### [v.1.1](https://github.com/ErikaKriks/project2/tree/v.1.1)
Script from previous exercise was adapted for the Class data structure.
<br>There are choices to calculate final mark based on Average and Median.
<br>* Students categorization into Pass and Fail groups implemented using 2 strategies:
        * Strategy 1 - using two containers Fail and Pass to store information after categorization.
        * Strategy 2 - using initial container and Fail students container to store data (failing students are added to the new container and removed from the initial container).
* Experiment measuring time of each process performed.


#### Comparison of data Categorization

#### Comparison of different Structures
| Records | Struct | Class |
|--|--|--|
| 100 000 | 0.188s  | 0.374s |
| 1 000 000 | 2.214s | 0.682s |


#### Comparison of Optimization flags
| Records | no flag | O1| O2 | O3 | 
|--|--|--|--|--|
| 100 000 | 0.374s | 0.0587s | 0.0531s | 0.0497s | 
| 1 000 000 | 0.682s | 0.482s | 0.659s | 0.642s |


#### Comparison of Saving Categorized data

#### Comparison of different Structures
| Records | Struct | Class |
|--|--|--|
| 100 000 | 0.567s  | 0.571s |
| 1 000 000 | 5.435s | 5.689s |


#### Comparison of Optimization flags
| Records | no flag | O1| O2 | O3 | 
|--|--|--|--|--|
| 100 000 | 0.571s | 0.0587s | 0.487s | 0.470s | 
| 1 000 000 | 5.689s | 5.021s | 4.902s | 4.761s |

Strategy 1 and Vector structure was used for comparison, more information about strategies can be found [here](https://github.com/ErikaKriks/project1/tree/v.1.0).
Strategy 2 uses erase method, which is computationally expensive as it seems - O(n) complexity, as well modifying vector while iterating might be causing large time of completion.
<br>Script with Class implementation took more time for every experiment.
<br>Flag O3 performs best in both cases.


### [v.1.2](https://github.com/ErikaKriks/project2/tree/v.1.2)
Script updated including Rule of Three and overwritten input/output methods.

**Class Structure**
* Private Members: Includes name, surname, examMark, marks, and public members for final marks.
* Constructors: Default constructor and parameterized constructor for initializing member variables.
* Rule of Three: Implements copy constructor, copy assignment operator, and a destructor.
* Getter and Setter Methods: For accessing and modifying private members.
* Other Methods: Includes add_mark() to add marks to the marks vector.

**Additional Functionalities**
* Overloaded Stream Operators: Implements operator<< and operator>> for customized input and output stream operations. Input method works manually, output prints students data to the terminal.


### [v.1.5](https://github.com/ErikaKriks/project2/releases/tag/v.1.5)
An abstract Class Person introduced.

### [v.2.0](https://github.com/ErikaKriks/project2/releases/tag/v.2.0)
This release contains Doxygen documentation of the project additionally to all prior functionality.

### [v.3.0](https://github.com/ErikaKriks/project2/releases/tag/v.3.0)
This release contains dmg file for easier installation of the project.

