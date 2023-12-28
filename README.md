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
   git clone https://github.com/your-username/your-repository.git

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


## Visual Studio Code Configuration

If you are using Visual Studio Code to develop and run your C++ project, you may find the following configuration files useful:

### tasks.json

The `tasks.json` file in the `.vscode` directory defines build and other tasks for your project. If you've included this file in your project, you can find predefined tasks for building and running your program.

### launch.json

The `launch.json` file in the `.vscode` directory is used for configuring the debugger settings. It defines how VSCode should start and debug your program. If you've included this file in your project, you can find predefined configurations for debugging.

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
### [v.1.1](https://github.com/ErikaKriks/project2/tree/v.1.1)
Script from previous exercise was adapted for the Class data structure.
<br>There are choices to choose how output data will be sorted.
<br>* Students categorization into Pass and Fail groups implemented using strategy number 3, because it eas the fastest in the previous version of the script.
* Experiment measuring time of each process performed.


#### Comparison of data Categorization

#### Comparison of different Structures
| Records | Struct | Class |
|--|--|--|
| 100 000 | 0.0397s  | 0.191s |
| 1 000 000 | 0.411s | 1.922s |


#### Comparison of Optimization flags
| Records | no flag | O1| O2 | O3 | 
|--|--|--|--|--|
| 100 000 | 0.0246s | 0.0251s | 0.0247s | 0.0240s | 
| 1 000 000 | 0.253s | 0.253s | 0.253s | 0.254s |



Strategy 3 and Vector structure was used for comparison, more information about strategies can be found [here](https://github.com/ErikaKriks/project1/tree/v.1.0).
<br>Script with Class implementation took more time for every experiment.
<br>Flag O3 performs best in case of 100 000 students, in other cases of flags are really close in terms of performance.



