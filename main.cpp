#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;


const string top = "<!doctype html>\n<html lang=\"en\">\n<head>\n<link href=\"https://cdn.jsdelivr.net/npm/bootstrap@5.1.1/dist/css/bootstrap.min.css\" rel=\"stylesheet\" integrity=\"sha384-F3w7mX95PdgyTmZZMECAngseQB83DfGTowi0iMjiWaeVhAn4FJkqJByhZMI3AhiU\" crossorigin=\"anonymous\">\n<meta charset=\"utf-8\">\n"
                   "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n<title>Asmeninis Projektas</title>\n</head>\n<body>";
string navigation;

string test("<button type=\"button\" class=\"btn btn-primary\">Primary</button>");
string post;
const string bottom = "\n</body>\n</html>";


void hero(ofstream &document) {

  string title;
  string description;
  string leftButtonTitle;
  string rightButtonTitle;
  cout << "-------------------------------------------------------------------" << endl;
  cout << "HERO" << "(tai elementas panašus į antraštę arba header)" << endl;
  cout << "Jis sudarytas iš šių dalių: \nPavadinimas.\nAprašymas.\n2 Mygtukai/Nuorodos." << endl;
  cout << "-------------------------------------------------------------------" << endl;

  document << "<div class=\"px-4 py-5 my-5 text-center\">\n";
  document << "<h1 class=\"display-5 fw-bold\">";

  cout << "Nurodykite svetainės pavadinimą:\n";
  getline(cin, title);
  document << title << "</h1>\n";
  document << "<div class=\"col-lg-6 mx-auto\">\n";
  document << "<p class=\"lead mb-4\">";

  cout << "Nurodykite svetainės aprašymą:\n";
  getline(cin, description);
  document << description << "</p>\n";
  document << "<div class=\"d-grid gap-2 d-sm-flex justify-content-sm-center\">\n";
  document << "<button type=\"button\" class=\"btn btn-primary btn-lg px-4 gap-3\">\n";

  cout << "Nurodykite pirmo mygtuko pavadinimą:\n";
  getline(cin, leftButtonTitle);
  document << leftButtonTitle << "</button>\n";
  document << "<button type=\"button\" class=\"btn btn-outline-secondary btn-lg px-4\">\n";

  cout << "Nurodykite antro mygtuko pavadinimą:\n";
  getline(cin, rightButtonTitle);
  document << rightButtonTitle << "</button>\n";
  document << "</div>\n</div>\n</div>";
}


int main() {
  SetConsoleOutputCP(CP_UTF8); // Konsolėje rodys lietuviškas raides. Funkcija iš windows.h bibliotekos
  ofstream file;


  file.open("index.html", ios::app);
  file << top;
  hero(file);
  file << bottom;
  file.close();


  return 0;
}