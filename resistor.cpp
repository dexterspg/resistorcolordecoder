#include<iostream>
#include<string>

using namespace std;

void deCode(char,int&); // prototype for resistance values
void Ohm(int,string&); //prototype for units

///////////////////// HEADER //////////////////////////////////////////
void header()
{   system("Color F0");
	cout<<"\n\n\t**************************************************\n"
		<<"\t  COEN 243 Team Project: Evaluate the Value of a\n" 
		<<"\t\t Resistor from its Color Code\n"
		<<"\t\tProgrammers: Pagkaliwangan, Dexter\n"
		<<"\t\t             Galal, Ahmed\n"
		<<"\t\t             Ahsan Akim,Akash\n"
		<<"\t\tDate of Submission: April 21, 2014\n"
		<<"\t**************************************************\n\n\n\n";
}

/////////////////////////MENU/////////////////////////////// 
void menu()
{
	cout<<"\n\tResistor Color Code (RCC) Menu Desk\n"
		<<"\t====================================\n"
		<<"\t      Color and Value  Code\n"
		<<"\t      ---------------- ----\n"
		<<"\t      Black  (0) ---->  B\n"
		<<"\t      Brown  (1) ---->  N\n"
		<<"\t      Red    (2) ---->  R\n"
		<<"\t      Orange (3) ---->  O\n"
		<<"\t      Yellow (4) ---->  Y\n"
		<<"\t      Green  (5) ---->  G\n"
		<<"\t      Blue   (6) ---->  E\n"
		<<"\t      Violet (7) ---->  V\n"
		<<"\t      Gray   (8) ---->  A\n"
		<<"\t      White  (9) ---->  W\n"
		<<"\t====================================\n"
		<<"\t[Note: The letters are case insensitive]\n\n";
	
}

int main()
{

//////////////////////////////    DECLARATION VARAIABLES      ////////////////////
const int MAX_LETTERS=3; // the program only needs 3 letters

char colorCode[MAX_LETTERS];  //declares the array, which has 3 elements or letters
int value[MAX_LETTERS]; //values corresponding to the 3 elements of colorCode
string unit; //units in ohms, Kilo ohms, Mega ohms and Giga ohms
char excessLetter[10000]; // gets the 4th input character to 10000th

//used for repeat/exit program
bool done= false; 
char choice;  

while(!done) //repeat program unless !done=false;
{

/////////////////////////////////   INPUT CODES    ///////////////////////////////////
header(); ////function call to display header
menu(); //function call to display RCC Menu Desk

cout<<"Enter three valid color codes from the above menu: ";  

// The for loop reads only 3 elements
// The 3 letters inputted on the program will be assign to each element respectively
// The deCode function call checks if the correct letters are inputted, base on the RCC Menu Desk
// It will assign a value -1 if one element of an array has an incorrect letter
// Three values ranging from 0~9 is assigned to the letters
//This do-while will ask repeatedly to input 3 letters until there are exactly 3 and  valid letters
do
{
for (int i=0;i<MAX_LETTERS;i++)
{
cin>>colorCode[i];
deCode(colorCode[i],value[i]);
Ohm(value[2],unit); // units of the resistance depends on the third element of array value
}

cin.getline(excessLetter,10000); // get all the characters on the stream from 4th character till the nth character, i.e. 10000

/*****           VALIDITATE        *****/
if(cin.gcount()!=1) //character count is not 3
cout<<"Invalid Entry!!! Too many characters\nEnter "<<MAX_LETTERS<<" valid codes from the above menu: ";
else if (value[0]==-1 || value[1]==-1 || value[2]==-1) //at least one letters inputted are incorrect
	cout<<"Invalid Entry!!!,\nEnter "<<MAX_LETTERS<<" valid codes from the above menu: ";
else break; //escape loop when input is correct

}while(true); 


/////////////////////     OUTPUT CODES   ////////////////////////////////////////////////////

// The if-else statements tells which places the digits of the values,based on the remainder of value[3]/3
/* For instance, nn_ (unknown letter[2])
Value[2]   Letter[2]            Resistance         Units              Remainder
  0           B             11                      ohm					 0
  1			  N                  110                ohm					 1
  2			  R							1.1         k ohm				 2
  3           O				11						k ohm				 0
  4			  Y					 110				k ohm				 1
  5           G							1.1			M ohm				 2
  6			  E				11						M ohm				 0	
  7			  V					 110				M ohm				 1
  8			  A							1.1			G ohm				 2
  9			  W				11						G ohm				 0
  
*/
cout<<endl<<"\t=========================================\n";
cout<<"\t     Resistance value: ";
if(value[2]%3!=0) // If the value[2] is divisible by 3 it skips the if-statements and proceed to the outer else-statement
{
	if (value[2]%3==1)// remainder 1
      		//gets 1st and 2nd value, equation is to have a zero at the end of the resistance
			//display: 1st value in hundreds place, 2nd value in tens place,a 0 in the ones place and the unit
			// ex. nnv = 110 M ohm
			cout<<(value[0]*10+value[1])*10<<unit<<endl;
			 //second value is divided by 10 to have the decimal point shift to the right
			 //display: 1st value in ones place,2nd value in tenths place and units.
			 //ex. nna 1.1 G ohm 
	else cout<<value[0]+(float)value[1]/10<<unit<<endl; //remainder 2					
}
//display: 1st value in tens place,second value in ones place and units.
//ex. nnb 11 ohm
else cout<<value[0]*10+value[1]<<unit<<endl;
cout<<"\t=========================================\n";

////////////////////////   FOOTER   ////////////////////////////////////////////////////

//if 'y' or 'Y' is inputted, it repeats the program and asked for another three letters
//otherwise, it assigns true to the boolean variable done, which means the program is terminated
//A goodbye message is displayed upon termination.
cout<<"\nDo you want to continue?\n"
	<<"Press 'y' and hit Enter for \"yes\", and any other key and hit enter to Quit?: ";
     cin>>choice;
	
	 switch (choice)
	 {
		 case 'y':
		 case 'Y':  
			 break; //done = false
		 default:
		{
			done = true; 
			cout<<"\n\t*******************************************\n"
		        <<"\t  Good bye from the desk resistance menu!!\n"
				<<"\t*******************************************\n\n";
				    }
	 }
}

return 0;
}
////////// END MAIN /////// && /////////  DECODING FUNCTIONS  /////////////////////////////////

//assign a value depending on the inputted letters
//incorrect letter assign the color letter 'X'
void deCode(char color, int& value) //color = colorCode[i] , value = value[i]
{
	switch(color)
	   {
		case 'B': case 'b': 
			value=0; break;
		case 'N': case 'n':
			value=1; break;
		case 'R': case 'r':
			value=2;	break;
		case 'O': case 'o':
			value=3;	break;
		case 'Y': case 'y':
			value=4;	break;
		case 'G': case 'g':
			value=5;	break;
		case 'E': case 'e':
			value=6;	break;
		case 'V': case 'v':
			value=7;	break;
		case 'A': case 'a':
			value=8;	break;
		case 'W': case 'w':
			value=9;	break;
		default: value=-1;
	}
}
// unit depends on the value of the third letter
void Ohm(int val3, string& ohm) //val3 = value[2], ohm = unit
{
	if(val3==0 || val3==1)
		ohm=" ohms";
	else if (val3==2 || val3==3|| val3==4)
		ohm=" Kilo ohms";
	else if (val3==5 || val3==6|| val3==7)
		ohm=" Mega ohms";
	else
		ohm=" Giga ohms";
}


/////////////// END PROGRAM //////////////////////////////
