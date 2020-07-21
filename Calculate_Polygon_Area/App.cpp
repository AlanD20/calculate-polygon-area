#include<iostream>
#include<fstream>
#include<vector>
#include<string>


std::ifstream infile; //defining input file stream from fstream library at the top to be able use it for all functions.

struct Pos {

public:
    std::string filename, sfiletext;
    char readinput, cont = 'N';
    double polygonarea = 0, area = 0, xm = 0, yn = 0, storedvar = 0;
    unsigned int cx = 0, cy = 0;
    std::vector<double> x;
    std::vector<double> y;

    void ypos()
    {
        infile >> storedvar; //inputs the number into stored variable
        yn += storedvar; //saving the number after "," character with positive sign
        x.push_back(xm); //inserting the positive x number into our vector
        y.push_back(yn); //inserting the positive y number into our vector
    }
    void xpos()
    {
        infile >> storedvar;//inputs the number into stored variable
        xm += storedvar; //saving the number after "," character with positive sign
        x.push_back(xm); //inserting the positive x number into our vector
        y.push_back(yn); //inserting the positive y number into our vector
    }
    void yneg()
    {
        infile >> storedvar;//inputs the number into stored variable
        yn -= storedvar; //saving the number after "," character with negative sign
        x.push_back(xm); //inserting the positive x number into our vector
        y.push_back(yn); //inserting the positive y number into our vector
    }
    void xneg()
    {
        infile >> storedvar;//inputs the number into stored variable
        xm -= storedvar; //saving the number after "," character with negative sign
        x.push_back(xm); //inserting the positive x number into our vector
        y.push_back(yn); //inserting the positive y number into our vector
    }

    double FindingArea(std::vector<double> x, std::vector<double> y)
    {
        polygonarea = 0;
        cy = (x.size() - 1);
        for (cx = 0; cx < x.size(); cx++) //the loop will continue until it gets the size of the x position.
        {
            polygonarea += (y[cy] - y[cx]) * (x[cy] + x[cx]); //calculating the polygons.
            cy = cx;
        }
        return abs(polygonarea / 2.0);
    }

};

int main()
{
    Pos po;
    do { //allow the user to calculate another file without quitting the program.

        bool wrongdesc = false;
        po.area = 0, po.xm = 0, po.yn = 0, po.storedvar = 0; //setting vlaues to zero in case the user wants to do new calculation.

        do { // an input shows the user to write the file name in the same directory of the program.
            po.filename = "";
            std::cout << "Write the file name: " << std::endl;
            std::cin >> po.filename;
            infile.open(po.filename);

        } while (infile.fail());//the user can not proceed to next step until a file will be read.

        while (!infile.eof())
        { //the file content will be read till the end of the file.
            infile >> po.readinput; //reading the content of the file one character by one character.
            if (po.readinput == '(') //if the character is == ( then proceed to next line
            {
                infile.get(po.readinput); //get a new character..
                if (po.readinput == 'N' || po.readinput == 'n') //if it's north then
                {
                    infile.get(po.readinput);  //get a new character..
                    if (po.readinput == ',') //if the new character is "," then proceed to the next line
                    {
                        po.ypos();//calling function
                    }
                    else { wrongdesc = true; break; } //if not break the loop and show the error.
                }
                else if (po.readinput == 'E' || po.readinput == 'e')//if it's east then
                {
                    infile.get(po.readinput); //get a new character..
                    if (po.readinput == ',')//if the new character is "," then proceed to the next line
                    {
                        po.xpos();//calling function
                    }
                    else { wrongdesc = true; break; } //if the description is wrong break the loop for the next condition
                }
                else if (po.readinput == 'S' || po.readinput == 's')//if it's south then
                {
                    infile.get(po.readinput); //get a new character..
                    if (po.readinput == ',')//if the new character is "," then proceed to the next line
                    {
                        po.yneg();//calling function
                    }
                    else { wrongdesc = true; break; }//if the description is wrong break the loop for the next condition
                }
                else if (po.readinput == 'W' || po.readinput == 'w')//if it's west then
                {
                    infile.get(po.readinput); //get a new character..
                    if (po.readinput == ',')//if the new character is "," then proceed to the next line
                    {
                        po.xneg(); //calling function
                    }
                    else { wrongdesc = true; break; }//if the description is wrong break the loop for the next condition
                }
            }
            else if (wrongdesc == true) { std::cout << "\nThe file description is wrong! "; break; }
            else if (po.readinput == ')') { continue; } //if the pointer gets there it will continue the loop from the start.
            else if (po.readinput == ',') { continue; }//if the pointer gets there it will continue the loop from the start.
        }
        if (wrongdesc == true) { std::cout << "\nThe file description is wrong!"; } //if description of the file is wrong.
        else
        {
            std::cout << "\nThe Polygon Area: " << po.FindingArea(po.x, po.y);//if the description is correct the function will return the area of the polygon.
        }

        infile.close();  //free up memorpo.y.
        po.x.clear(); //clearing the vector if the user wills to do a new calculation.
        po.y.clear();//clearing the vector if the user wills to do a new calculation.
        std::cout << "\nWant to do a new calculation with different file? Y/N: ";
        std::cin >> po.cont;

    } while (po.cont == 'Y' || po.cont == 'y'); //if the user wants to do a new calculation.

    return 0;

}
