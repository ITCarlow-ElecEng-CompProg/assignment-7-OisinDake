//Oisin DAke
//Lav 7
#include <iostream>
#include <math.h>

using namespace std;

//variable fuction declarations
void CtopCal ( float x, float y, float *ptr_rad, float *ptr_ang);//float the pointer address
void PtoCCal ( float rad, float ang, float *ptr_x, float *ptr_y);
char menu(void);
void ptoc(void);
void ctop(void);

int main()// main program
{
    char input;// store input value as a char

    cout << "Coordinate Conversion" << endl;//display to user

    do// do while loop with a switch case inside
    {
       input = menu();

        switch (input)
        {
            case 'p':   ctop();//calls ctop fuction
                        break;

            case 'c':   ptoc();//calls function
                        break;

            case 'q':   cout <<"End of program"<< endl;// by pressing q the program is ended and to close the
                                                       //window any key is pressed
                        break;

            default:    cout << "Choose the correct letter ,please:"<<endl;//shows if an incorrect letter is pressed
                        break;
        }
    }
    while (input != 'q');//while input is not equal to q

    return 0;
}

void CtopCal ( float x, float y, float *ptr_rad, float *ptr_ang)
{

    *ptr_rad = sqrt(pow(x,2)+ pow(y,2));//calculation
    *ptr_ang = 180.0 * (atan2(y,x))/M_PI;//calculation

    return;
}

void PtoCCal ( float rad, float ang, float *ptr_x, float *ptr_y)
{
    *ptr_x = rad * cos(ang);
    *ptr_y = rad * sin(ang);

    return;
}

char menu(void)
{
    char input;

    cout << "Choose conversion\n"<<
    "p = Cart to Pol\n"<<
    "c = Pol to Cart\n"<<
    "q = Leave program.\n" << endl ;
    cin >> input;// to get user input

    return input;
}

void ctop(void)
{
    float x =0, y=0, ang =0, rad =0;// initialise to 0
    float *ptr_ang, *ptr_rad;

    ptr_ang = &ang;// & means address
    ptr_rad = &rad;

    cout << "Enter numbers for x and y"<<endl;
    cin >> x >> y ;
    CtopCal ( x, y, ptr_rad,ptr_ang);//calling fuction
    cout << "\nThe Mag of the angle: " << *ptr_rad<< endl;//display results
    cout << "The angle is:"<< *ptr_ang<< endl << endl;//display results

    return;
}


void ptoc(void)
{
    float x =0, y=0, ang =0, rad =0;//initialise to 0
    float *ptr_x, *ptr_y;

    ptr_x = &x;
    ptr_y = &y;
    cout << "Enter the mag for R:"<<endl;
    cin >> rad;//take in value and store in rad
    cout << "Enter the angle:"<<endl;
    cin >> ang;
    PtoCCal (rad, ang*M_PI/180 ,ptr_x, ptr_y);//caling function
    cout <<"The x cordinate is :"<< *ptr_x<< endl;//display results
    cout << "The y cordinate is:" << *ptr_y << endl << endl;//display results

    return;
}
