//Bryslin Chavous
//Source: A  Restaurant Project Struct style Dr_T Dr. Tyson McMillan 10-2-2019

#include <iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<fstream>
using namespace std; 

struct MenuItem
{
  string name;
  double itemCost;
  double tip;
  string desc; 
  char addLetter; 
  char removeLetter;
  int count; 
};

//function definitions
void populateMenu(vector<MenuItem> &entireMenu)
{
  //put some default values in our Menu
  const int numItems = 7; 
  MenuItem Item1; 
  MenuItem Item2;
  MenuItem Item3; 
  MenuItem Item4;
  MenuItem Item5;
  MenuItem Item6;
  MenuItem Item7;    

  entireMenu.push_back(Item1); //add to the end of list the Item1
  entireMenu.push_back(Item2); //add to the end of list the Item2
  entireMenu.push_back(Item3); //add to the end of list the Item3
  entireMenu.push_back(Item4); //add to the end of list the Item4
  entireMenu.push_back(Item5); //add to the end of list the Item5
  entireMenu.push_back(Item6); //add to the end of list the Item6
  entireMenu.push_back(Item7); //add to the end of list the Item7

  vector<string> defaultMenuNames = {"Green Tea", "Burrito", "Item 3", "Item 4", "Item 5", "Item 6", "Item 7"}; 
  vector<char> defaultAddLetters = {'A', 'B', 'C', 'D', 'E', 'F', 'G'}; 
  vector<char> defaultRemoveLetters = {'a', 'b', 'c', 'd', 'e', 'f', 'g'}; 

  for(int i = 0; i < numItems; i++)
  {
    //add each item to the default list efficiently 
    entireMenu[i].name = defaultMenuNames[i]; 
    entireMenu[i].addLetter = defaultAddLetters[i]; 
    entireMenu[i].removeLetter = defaultRemoveLetters[i]; 
    entireMenu[i].itemCost = (3.00 + i); //set a random starter cost for each item
    entireMenu[i].count = 0; //initialze all counts to 0
    entireMenu[i].desc = "delicious"; //set all default desc to "delicous"
  }


}

void showMenu(vector<MenuItem> &m)
{
  cout << fixed << setprecision(2);//set doubles to 2 decimal places
  cout << "\x1B[36mDrT's Effcient Menu\033[0m" << endl; 
  cout << "\x1B[31mADD  \tNAME \t COST \tREMOVE\tCOUNT\tDESC\033[0m"<<endl; 
  for(int i = 0; i < m.size(); i++)
  {
    cout << m[i].addLetter << ")" << setw(10) << m[i].name 
    << setw(5) << "$" << m[i].itemCost << setw(5) << "(" << m[i].removeLetter
    << ")" << setw(7) << m[i].count << setw(13) << m[i].desc 
    <<endl; 
  }

}

double subtotal = 0.0; 


void acceptOrder(vector<MenuItem> &m)
{
  char option = '\0';// the user-selected menu item
  
  do
  {
    cout << "\nPlease choose an item (x to Exit): ";
    cin >> option; 

    for(int i=0; i < m.size(); i++)
    {
      if(option == m[i].addLetter)
      {
        cout << "\nMenu Item " << m[i].addLetter << " selected."; 
        m[i].count++; //increment the count by 1
        cout << "\033[2J\033[1;1H"; //clear screen 
        cout << "\n1 UP on " << m[i].name << endl;
        subtotal += m[i].itemCost; //increment the subtotal by the cost of the item 
        showMenu(m); //show the updated menu
        cout << "\nSubtotal: $" << subtotal << endl;  
      }
      else if(option == m[i].removeLetter)
      {
        cout << "\nRemove Item " << m[i].removeLetter << " selected."; 
        if(m[i].count > 0) //subtract if and only if the count is > 0
        {
          m[i].count--; //decrement the count by 1
          cout << "\033[2J\033[1;1H"; //clear screen 
          cout << "\n1 DOWN on " << m[i].name << endl;
          subtotal -= m[i].itemCost; //decrement the subtotal by the cost of the item
          showMenu(m); //show the updated menu
          cout << "\nSubtotal: $" << subtotal << endl;  
        }
        else //the the user why you blocked item removal 
        {
            
            cout << "\nItem count must be > 0 to remove: " << m[i].name << endl;
        }
      }
      else if(
                option != m[i].addLetter && 
                option != m[i].removeLetter &&
                option != 'x' &&
                option != 'X' 
            ) //test for all of my valid inputs
            {
              if(i == 0)
              {
                cout << "\nInvalid input (" << option << "). Please try again." << endl; 
              }  
            }
    }
  }while(option != 'x' && option != 'X'); 
  cout << "\nThank you for placing your order.\n" << endl; 
  //handle the tip process here
 
  string option1;
  double tip = 0.2 * subtotal;
  double total = subtotal + (subtotal * 0.09) + tip;

  cout << "Subtotal: \n" << subtotal << endl;
  cout << "\nPlease input your desired tip amount: " << endl;
  cout << "A) 20%: " << tip << endl;
  cout << "B) Enter custom amount." << endl;
  cin >> option1;

  if(option1 == "A" || option1 == "A")
      {
        cout << "\nTip: \n" << tip << endl;
      }
      else if(option1 == "B" || option1 == "b") {
        cin >> tip;
        cout << "\nTip: \n" << tip << endl;
      }


  //handle reciept generation here
  cout << "\n* * * Reciept * * *" << endl;
  cout << "\n  Subtotal: " << subtotal << endl;
  cout << "       Tax: " << subtotal * 0.09 << endl;
  cout << "       Tip: " << tip << endl;
  cout << "\n     Total: " << subtotal + (subtotal * 0.09) + tip << endl;

  cout << "\nPlease select payment type: " << endl;
  cout << "A) Cash" << endl;
  cout << "B) Credit Card" << endl;
  cin >> option1;

  double tender;
  double change;

  if(option1 == "A" || option1 == "A")
      {
        cout << "\nPlease enter the tender amount: " << endl;
        cin >> tender;

        if(tender >= total){
          change = tender - total;
          cout << "Change: " << change << endl;
        }else if (tender < total)
        {
          cout << "Not enough funds." << endl;
        }


      }
      else if (option1 == "B" || option1 == "b")
      {
        cout << "Please swipe card." << endl;
        cout << "..." << endl;
        cout << "Process complete." << endl;
      }


}

void printReceipt(vector<MenuItem>, double subtotal){
  ofstream print("receipt.txt");
  double tip = 0.2 * subtotal;
  double total = subtotal + (subtotal * 0.09) + tip;

  cout << "\n* * * Reciept * * *" << endl;
  print << "Subtotal: " << subtotal << endl;
  print << "Tax: " << subtotal * 0.09 << endl;
  print << "Tip: " << tip << endl;
  print << "Total: " << total << endl;
  print.close();

}

int main() 
{
  string option;

  do {
   vector<MenuItem> wholeMenu; 
    populateMenu(wholeMenu); //put some default values in the menu
    showMenu(wholeMenu); //print the current data of the menu on screen 
    acceptOrder(wholeMenu); 
    printReceipt(wholeMenu, subtotal);
    cout << "\nA: New order" << endl;
    cout << "B: Exit program" << endl;
    cin >> option;
    cout << "\n" << endl;
} 
while(option == "A" || option == "a");

cout << "PROGRAM TERMINATED" << endl;

  return 0; 
}