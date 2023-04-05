#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Vraboten {
private:
    string imeiprezime;
    int mat_br;
    int vozrast;
    string adresa;
    int kod;
public:
    Vraboten(string ime, int mat, int voz, string adr, int k) {
        imeiprezime = ime;
        mat_br = mat;
        vozrast = voz;
        adresa = adr;
        kod = k;
    }

    friend ostream& operator<<(ostream& out, const Vraboten& v) {
        out << v.imeiprezime << " " << v.mat_br << " " << v.vozrast << " " << v.adresa << " " << v.kod << endl;
        return out;
    }

    bool operator<(const Vraboten& v) const {
        return kod < v.kod;
    }
};

class Klient {
private:
    string imeiprezime;
    int mat_br;
    int vozrast;
    string adresa;
    string kod;
public:
    Klient(string ime, int mat, int voz, string adr, string k) {
        imeiprezime = ime;
        mat_br = mat;
        vozrast = voz;
        adresa = adr;
        kod = k;
    }

    friend ostream& operator<<(ostream& out, const Klient& k) {
        out << k.imeiprezime << " " << k.mat_br << " " << k.vozrast << " " << k.adresa << " " << k.kod << endl;
        return out;
    }

    bool operator<(const Klient& k) const {
        return kod < k.kod;
    }
};

template <class T>
class Lica {
private:
    vector<T> lista;
public:
    void dodadi(T obj) {
        lista.push_back(obj);
    }

    void pecati() const {
        for (const auto& obj : lista) {
            cout << obj;
        }
    }

    void sortiraj() {
        sort(lista.begin(), lista.end());
    }
};

int main() {
    Lica<Vraboten> vraboteni;
    Lica<Klient> klienti;

    int izbor;
    do {
        cout << "1. Vnesuvanje na podatoci za vraboten\n";
        cout << "2. Vnesuvanje na podatoci za klient\n";
        cout << "3. Pecatenje na lista na vraboteni\n";
        cout << "4. Pecatenje na lista na klienti\n";
        cout << "5. Kraj\n";
        cout << "Izbor: ";
        cin >> izbor;

        if (izbor == 1) {
            string ime;
            int mat, voz, kod;
            string adr;

            cout << "Vnesi ime i prezime: ";
            cin >> ime;
            cout << "Vnesi matichen broj: ";
            cin >> mat;
            cout << "Vnesi vozrast: ";
            cin >> voz;
            cout << "Vnesi adresa: ";
            cin >> adr;
            cout << "Vnesi kod: ";
            cin >> kod;

            Vraboten v(ime, mat, voz, adr, kod);
            vraboteni.dodadi(v);
        }
        else if (izbor == 2) {
            string ime;
            int mat, voz;
            string adr,kod;

            cout << "Vnesi ime i prezime: ";
            cin >> ime;
            cout << "Vnesi matichen broj: ";
            cin >> mat;
            cout << "Vnesi vozrast: ";
            cin >> voz;
            cout << "Vnesi adresa: ";
            cin >> adr;
            cout << "Vnesi kod: ";
            cin >> kod;

            Klient k(ime, mat, voz, adr, kod);
            klienti.dodadi(k);
        }
        else if(izbor==3)
        {
            vraboteni.pecati();
        }
        else if(izbor==5)
        {
            klienti.pecati();
        }
        else if(izbor==5)
        {
            break;
        }
    }
    while(izbor!=5);
    return 0;
}
