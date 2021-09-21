
// @Author Marius Gžegoževskis
// PROJEKTO ŠABLONAS YRA SKIRTAS KAIP PAGALBINĖ PRIEMONĖ
// PAPILDOMAI TURITE SUKURTI KELETĄ SKIRTINGŲ FUNKCIJŲ
// KUR VARTOTOJAS GALĖTŲ ĮVESTI IŠ KONSOLĖS IR SUKURTI KOMPONENTUS:
// PVZ. TABLE, LIST, CARD, BUTTON GROUP ir pan.
// Puslapio generavimui naudojamas BOOTSTRAP CSS https://getbootstrap.com/docs/5.1/getting-started/introduction/
// Galite naudoti įprastą HTML vietoj bootstrap, pvz. plačiau rasite info: https://www.w3schools.com/html/default.asp

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

const string top = "<!doctype html>\n<html lang=\"en\">\n<head>\n<link href=\"https://cdn.jsdelivr.net/npm/bootstrap@5.1.1/dist/css/bootstrap.min.css\" rel=\"stylesheet\" integrity=\"sha384-F3w7mX95PdgyTmZZMECAngseQB83DfGTowi0iMjiWaeVhAn4FJkqJByhZMI3AhiU\" crossorigin=\"anonymous\">\n<meta charset=\"utf-8\">\n"
                   "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n<title>Asmeninis Projektas</title>\n</head>\n<body>\n";

const string bottom = "\n</body>\n</html>";

void hero(ofstream &document) {

  cout << "-------------------------------------------------------------------" << endl;
  cout << "HERO" << "(tai elementas panašus į antraštę arba header)" << endl;
  cout << "Jis sudarytas iš šių dalių: \nPavadinimas.\nAprašymas.\n2 Mygtukai/Nuorodos." << endl;
  cout << "-------------------------------------------------------------------" << endl;

  document << "<div class=\"px-4 py-5 my-5 text-center\">\n";
  document << "<h1 class=\"display-5 fw-bold\">";

  cout << "Nurodykite svetainės pavadinimą:\n";
  string title;
  getline(cin, title);
  document << title << "</h1>\n";
  document << "<div class=\"col-lg-6 mx-auto\">\n";
  document << "<p class=\"lead mb-4\">";

  cout << "Nurodykite svetainės aprašymą:\n";
  string description;
  getline(cin, description);
  document << description << "</p>\n";
  document << "<div class=\"d-grid gap-2 d-sm-flex justify-content-sm-center\">\n";
  document << "<button type=\"button\" class=\"btn btn-primary btn-lg px-4 gap-3\">\n";

  cout << "Nurodykite pirmo mygtuko pavadinimą:\n";
  string leftButtonTitle;
  getline(cin, leftButtonTitle);
  document << leftButtonTitle << "</button>\n";
  document << "<button type=\"button\" class=\"btn btn-outline-secondary btn-lg px-4\">\n";

  cout << "Nurodykite antro mygtuko pavadinimą:\n";
  string rightButtonTitle;
  getline(cin, rightButtonTitle);
  document << rightButtonTitle << "</button>\n";
  document << "</div>\n</div>\n</div>";
}

void navigationBar(ofstream &document) {

  document << "<nav class=\"navbar navbar-expand-lg navbar-dark bg-primary\">\n";
  document << "<div class=\"container-fluid\">\n";
  document << "<a class=\"navbar-brand\" href=\"#\">\n";

  string pageTitle;
  cout << "Nurodykite svetainės pavadinimą:\n";
  getline(cin, pageTitle);
  document << pageTitle << "</a>\n";
  document
      << "    <button class=\"navbar-toggler\" type=\"button\" data-bs-toggle=\"collapse\" data-bs-target=\"#navbarNavAltMarkup\" aria-controls=\"navbarNavAltMarkup\" aria-expanded=\"false\" aria-label=\"Toggle navigation\">\n"
         "      <span class=\"navbar-toggler-icon\"></span>\n"
         "    </button>\n";
  document << "<div class=\"collapse navbar-collapse\" id=\"navbarNavAltMarkup\">\n";
  document << "<div class=\"navbar-nav\">\n";
  document << "<a class=\"nav-link active\" aria-current=\"page\" href=\"#\">Pagrindinis</a>\n";

  // Nuorodų kūrimas dinamiškai
  int input = 1;
  string navItem;
  string navItemURL;
  while (input) {

    cout << "1. Sukurkite puslapio navigacijos mygtuką."<<endl;
    cout << "0. Išeiti." <<endl;
    cin >> input;
    cin.ignore();
    if (input) {
      cout << "Nurodykite pavadinimą:" << endl;
      getline(cin, navItem);
      cout << "Nurodykite URL adresą:" << endl;
      getline(cin, navItemURL);
      document << "<a target=\"blank\" class=\"nav-link\" href=\"" << navItemURL << "\">" << navItem << "</a>\n";
    }else{
      input = 0;
    }
  }

  document << "</div>\n</div>\n</div>\n";
  document << "</nav>\n";
}


void removeFile(bool isNeedToRemove, const string &filename) {
  if (isNeedToRemove)
    remove(filename.c_str());
}


int main() {

  SetConsoleOutputCP(CP_UTF8); // Konsolėje rodys lietuviškas raides. Funkcija iš windows.h bibliotekos
  ofstream file;

  removeFile(true, "index.html");

  file.open("index.html", ios::app);
  file << top;

  navigationBar(file);
  hero(file);

  file << bottom;
  file.close();

  // Atidaryti narsykleje
  ShellExecute(nullptr, "open", "index.html", nullptr, nullptr, SW_SHOWNORMAL);

  return 0;
}