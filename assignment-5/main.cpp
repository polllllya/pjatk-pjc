#include <iostream>

using namespace std;

unsigned short koduj(int plec, int stan_cyw,
                     int grupa_wiek, int edu,
                     int zam, int region,
                     int odp);

void info(unsigned short kod);

int main() {
    unsigned short person1 = koduj(0, 0, 1, 3, 2, 11, 5);
    unsigned short person2 = koduj(1, 3, 3, 2, 1, 15, 7);

    cout<<"Person 1"<<endl;
    info(person1);

    cout<<endl;

    cout<<"Person 2 "<<endl;
    info(person2);

}

unsigned short koduj(int plec, int stan_cyw,
                     int grupa_wiek, int edu,
                     int zam, int region,
                     int odp) {
    unsigned short kod = 0;
    kod = kod | plec;
    kod = (kod << 2) | stan_cyw;
    kod = (kod << 2) | grupa_wiek;
    kod = (kod << 2) | edu;
    kod = (kod << 2) | zam;
    kod = (kod << 4) | region;
    kod = (kod << 3) | odp;

    return kod;
}

void info(unsigned short kod){
    int plec, stan_cyw, grupa_wiek, edu, zam, region, odp;

    odp = 0b111 & kod;
    kod = kod >> 3;

    region = 0b1111 & kod;
    kod = kod >> 4;

    zam = 0b11 & kod;
    kod = kod >> 2;

    edu = 0b11 & kod;
    kod = kod >> 2;

    grupa_wiek = 0b11 & kod;
    kod = kod >> 2;

    stan_cyw = 0b11 & kod;
    kod = kod >> 2;

    plec = 0b1 & kod;

    cout<<"plec:          "<<plec<<endl
        <<"stan cywilny:  "<<stan_cyw<<endl
        <<"grupa wiekowa: "<<grupa_wiek<<endl
        <<"wyksztalcenie: "<<edu<<endl
        <<"miejsce zam.:  "<<zam<<endl
        <<"region:        "<<region<<endl
        <<"odpowiedz:     "<<odp<<endl;
}
