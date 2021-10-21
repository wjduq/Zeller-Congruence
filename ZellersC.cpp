# include <iostream>
# include <string>
# include <locale>
# include <time.h>
# include <iomanip>
# include <cstdlib>
# include <cctype>
using namespace std;

int main(){

  int h, q, m, j, k;
  int runChoice;
  bool correctDate = false;


  cout << "There are three options (1) Enter a date (2) Generate a Random date (3) Exit" << endl;
  cin >> runChoice;

  if (runChoice == 1) {

    int year;

    cout << "Enter a date (yyyy mm dd): " << endl;
    cin >> year >> m >> q;
    string tempyearString = to_string(year);


    while (!correctDate){
      correctDate = true;
      tempyearString = to_string(year);
      if (m > 12){
        correctDate = false;
      }
      if (tempyearString.size() > 4) {
        correctDate = false;
      }
      if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && q > 31 ){
        correctDate = false;
      }
      if ((m == 4 || m == 6 || m == 9 || m == 11) && q > 30){
        correctDate = false;
      }

      if (m == 2 && q > 29){
        correctDate = false;
      }
      else if (m == 2 && (year % 4 != 0) && q > 28){
        correctDate = false;
      }
      else if ( m == 2 && (year % 4 == 0) && q == 29){
        if (year % 100 == 0){
          if (year % 400 == 0){
            correctDate = true;
          }
          else {
            correctDate = false;
          }
        }
        else {
          correctDate = true;
        }
      }

      if (!correctDate){
        cout << "Your date is entered incorectly!" << endl;
        cout << "Enter a date (yyyy mm dd): " << endl;
        cin >> year >> m >> q;


      }

    }

    if (m == 1){
      m = 13;
      year = year - 1;
    }
    if (m == 2){
      m = 14;
      year = year - 1;
    }

    j = year / 100;
    k = year % 100;


    h = (q + ((26 * (m + 1)) / 10) + k + (k / 4) + (j / 4) + (5 * j)) % 7;

    switch (h){
      case 0:
        cout << "Day of the week is Saturday" << endl;
        break;
      case 1:
        cout << "Day of the week is Sunday" << endl;
        break;
      case 2:
        cout << "Day of the week is Monday" << endl;
        break;
      case 3:
        cout << "Day of the week is Tuesday" << endl;
        break;
      case 4:
        cout << "Day of the week is Wednesday" << endl;
        break;
      case 5:
        cout << "Day of the week is Thursday" << endl;
        break;
      case 6:
        cout << "Day of the week is Friday" << endl;
        break;
    }

  }

  else if (runChoice == 2){

    srand(time(0));

    int tempJ;
    int thisYear;
    m = (rand() % 12 ) + 1;
    tempJ = (rand() % 12) + 2010;
    thisYear = tempJ;

    if (m == 1){
      tempJ = tempJ - 1;
    }
    if (m == 2){
      tempJ = tempJ - 1;
    }
    j = tempJ / 100; // should this be 2010 or 10
    k = tempJ % 100;

    if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)){
      q = (rand() % 31) + 1;
    }
    if (m == 4 || m == 6 || m == 9 || m == 11){
      q = (rand() % 30) + 1;
    }

    if (m == 2 && (tempJ % 4 != 0)){
      q = (rand() % 28) + 1;
    }
    else if ( m == 2 && (tempJ % 4 == 0)){
      if (tempJ % 100 == 0){
        if (tempJ % 400 == 0){
          q = (rand() % 29) + 1;
        }
        else {
          q = (rand() % 28) + 1;
        }
      }
      else {
        q = (rand() % 29) + 1;
      }
    }


    cout << "Computer Generated date: " << thisYear << " " << m << " " << q << endl;

    if (m == 1){
      m = 13;
    }
    if (m == 2){
      m = 14;
    }

    h = (q + ((26 * (m + 1)) / 10) + k + (k / 4) + (j / 4) + (5 * j)) % 7;

    switch (h){
      case 0:
        cout << "Day of the week is Saturday" << endl;
        break;
      case 1:
        cout << "Day of the week is Sunday" << endl;
        break;
      case 2:
        cout << "Day of the week is Monday" << endl;
        break;
      case 3:
        cout << "Day of the week is Tuesday" << endl;
        break;
      case 4:
        cout << "Day of the week is Wednesday" << endl;
        break;
      case 5:
        cout << "Day of the week is Thursday" << endl;
        break;
      case 6:
        cout << "Day of the week is Friday" << endl;
        break;
      }

  }
  else if (runChoice == 3){
    cout << "End!" << endl;
  }
  else {
    cout << "This is not a valid selection." << endl;
  }

}
