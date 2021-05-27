#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct movies_t {
  string title;
  int year;
} ;
movies_t films [30];
// film[x].title
void addmoviescreen(int x){
    cout << "Enter title: ";
    cin.ignore();
    getline (cin,films[x].title);
    cout << "Enter year: ";
    cin>>films[x].year;
    cout <<"\n";
    cout<<"Movie added successfully"<<endl;
}
void printmenu(){
        cout<<"================================"<<endl;
        cout<<"  Movie list Management System  "<<endl;
        cout<<"================================"<<endl;
        cout<<"           Options :            "<<endl;
        cout<<" 1) Show current movie list     "<<endl;
        cout<<" 2) Add movie to list           "<<endl;
        cout<<" 3) Delete movie from list      "<<endl;
        cout<<" 4) Modify movie data in list   "<<endl;
        cout<<" 5) Search by Title             "<<endl;
        cout<<" 6) Search by Year              "<<endl;
        cout<<" 0) END                         "<<endl;
        cout<<" Enter your option : ";
}
void printmovie (movies_t movie);
void printmovie (movies_t movie)
{
  cout << movie.title;
  cout << " (" << movie.year << ")\n";
}
int currentarrsize =15 ;
void deletemoviescreen(int x){
  string temptitle;
  int tempnum;
  for (int i= x-1; i < currentarrsize;i++){
    films[i].title = films[i+1].title;
    films[i].year = films[i+1].year;
  }
  cout<<"Movie deleted successfully"<<endl;
}
void modifymoviescreen(int x){
  string temptitle;
  int tempnum;
  int option_modify;
  cout<<x<<" "<<films[x-1].title<<"\t\t"<<films[x-1].year<<endl;
  cout<<"Which data do you want to modify? 1 for title, 2 for year, 3 for both. \n";
  cout<<"Enter option : ";
  cin>>option_modify;
  switch (option_modify){
    case 1 :
    {
      cout<<"Enter New title for movie : ";
      cin.ignore();
      getline(cin,films[x-1].title);
      cout<<"Title Updated!"<<endl;
      break;
    }
    case 2 :
    {
        cout<<"Enter New year value for movie : ";
        cin>>films[x-1].year;
        cout<<"Year Value Updated!"<<endl;
        break;
    }
    case 3 :
    {
      cout<<"Enter New title for movie : ";
      cin.ignore();
      getline(cin,films[x-1].title);
      cout<<"Enter New year value for movie : ";
      cin>>films[x-1].year;
      cout<<"Title & Year Value Updated !"<<endl;
      break;
    }
  }
}

int main ()
{

  string mystr;
  int n;
  int option;
  // Current Movies
  films[0].title = "Hitman: Agent Jun     ";
  films[0].year = 2020;
  films[1].title = "Vincenzo              ";
  films[1].year = 2021;
  films[2].title= "Burning                ";
  films[2].year = 2018;
  films[3].title ="Oldboy                 ";
  films[3].year =2003;
  films[4].title="Train to Busan          ";
  films[4].year =2016;
  films[5].title= "The Great Battle       ";
  films[5].year =2018;
  films[6].title ="I Saw the Devil        ";
  films[6].year= 2010;
  films[7].title= "Memories of Murder     ";
  films[7].year =2003;
  films[8].title ="The Host               ";
  films[8].year =2006;
  films[9].title = "On Your Wedding Day   ";
  films[9].year= 2018;
  films[10].title = "Silenced             ";
  films[10].year =2011;
  films[11].title = "Forgotten            ";
  films[11].year= 2017;
  films[12].title ="Miss Baek             ";
  films[12].year= 2018;
  films[13].title= "Be With You           ";
  films[13].year =2018;
  films[14].title= "Little Forest         ";
  films[14].year =2018;
  // Menu Screen and options
  do {
    printmenu();
    cin>>option;
    switch (option){
      case 1: {
        system("cls");
        for (int i = 0 ; i < currentarrsize;i++){
          printmovie (films[i]);
        }
        break;
      }
      case 2: {
        system("cls");
        addmoviescreen(currentarrsize);

        currentarrsize++;
        break;
      }
      case 3: {
       system("cls");
       int num_delete;
       for (int i = 0 ; i < currentarrsize;i++){
         printmovie (films[i]);
       }
       cout << "Which movie do you want to delete? Enter movie Number :  ";
       cin >> num_delete;
       deletemoviescreen(num_delete);
       currentarrsize--;
        break;
      }
      case 4: {
        system("cls");
        int num_modify;
        for (int i = 0 ; i < currentarrsize;i++){
          printmovie (films[i]);
        }
        cout<<"Which movie do you want to modify data? Enter Movie Number : ";
        cin>>num_modify;
        modifymoviescreen(num_modify);

        break;
      }
      case 5: {
        break;
      }
      case 6: {
        cout<<"Enter "
        break;
      }
      case 0: {
        return 0;
        break;
      }
    }
  }while (option = !0);


  return 0;
}
