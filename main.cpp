#include <iostream>
#include <vector>

using namespace std;

//function prototypes 
void display_menu(char&, vector <int>&);
void selection(char&, vector <int>&);
void print_num(vector <int>);
void add_num(vector <int>&, int&);
void mean(vector <int>, int&);
void smallest(vector <int>, int&);
void largest(vector <int>, int&);


//function declaration
void display_menu(char &c, vector <int> &x) {
    cout << "enter the letter of the operation you want to perform on the list!" << endl;
    cout << "P - print numbers" << endl;
    cout << "A - add a number" << endl;
    cout << "M - display mean of the numbers" << endl;
    cout << "S - display the smallest number" << endl;
    cout << "L - display the largest number" << endl;
    cout << "Q - quit" << endl;
    cin >> c;
    selection(c, x);
}

void selection(char &c, vector <int> &x) {
    
    if(c == 'p' || c == 'P') {
        if (x.size() == 0) 
            cout << "[], the list is empty" << endl;
        else {
            print_num(x);
        }
        cout << endl;
    } else if (c == 'a' || c == 'A') {
        int a;
        add_num(x, a);
    } else if (c == 'm' || c == 'M') {
        if (x.size() == 0) 
            cout << "unable to calculate average - no data found" << endl;
        else {
            int sum;
            mean(x, sum);
        }
    } else if (c == 's' || c == 'S') {
        if (x.size() == 0)
           cout << "unable to determinate the smallest number - list is empty" << endl;
        else {
            int lowest;
            smallest(x, lowest);
        }
    } else if (c== 'l' || c == 'L') {
        if (x.size() == 0)
           cout << "unable to determinate the smallest number - list is empty" << endl;
        else {
            int highest;
            largest(x, highest);
        }
    } 
}


void print_num(vector <int> x) {
    cout << "[ ";
    for (auto i:x) 
        cout << i << " ";
    cout << "]";
}

void add_num(vector <int> &x,int &n) {
    cout << "enter an integer to add to the list: ";
    cin >> n;
    x.push_back(n);
    cout << n << " added." << endl;
}

void mean(vector <int> x, int &add) {
        for (auto i:x) 
            add += i;
        cout << "the average of the elements is: " << static_cast<double>(add)/x.size() << endl;
}

void smallest(vector <int> x, int &lil) {
        lil = x.at(0);
            for (auto i:x) {
                if (i < lil)
                lil = i;
            }
        cout << "the smallest number in the list is: " << lil << endl;
}

void largest(vector <int> x, int &big) {
        big = x.at(0);
            for (auto i:x) {
                if (i > big)
                big = i;
        }
        cout << "the largest number in the list is: " << big << endl;
}


//main
int main() {
    vector <int> v {1, 2, 3, 4, 5};
    char c{};
    cout << "hello, this is your operation menu :)" << endl;
    do {
       display_menu(c, v);
  } while (c != 'q' && c != 'Q');
  
return 0;
} 
