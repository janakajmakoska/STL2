#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Kvadrat {
public:
    Kvadrat(int s = 0) : strana(s) {}
    int plostina() const { return strana * strana; }
    friend bool operator<(const Kvadrat& k1, const Kvadrat& k2) {
        return k1.plostina() < k2.plostina();
    }
    friend ostream& operator<<(ostream& os, const Kvadrat& k) {
        os << "Kvadrat(" << k.strana << ")";
        return os;
    }
private:
    int strana;
};

class Pravoagolnik {
public:
    Pravoagolnik(int s = 0, int d = 0) : sirina(s), dolzina(d) {}
    int plostina() const { return sirina * dolzina; }
    friend bool operator<(const Pravoagolnik& p1, const Pravoagolnik& p2) {
        return p1.plostina() < p2.plostina();
    }
    friend ostream& operator<<(ostream& os, const Pravoagolnik& p) {
        os << "Pravoagolnik(" << p.sirina << ", " << p.dolzina << ")";
        return os;
    }
private:
    int sirina;
    int dolzina;
};

template<typename T>
void pecatiPole(const vector<T>& pole) {
    for (const auto& elem : pole) {
        cout << elem << " ";
    }
    cout << endl;
}

template<typename T>
void sortirajPole(vector<T>& pole) {
    sort(pole.begin(), pole.end());
}

int main() {
    vector<Kvadrat> kvadrati{ Kvadrat(2), Kvadrat(4), Kvadrat(3) };
    vector<Pravoagolnik> pravoagolnici{ Pravoagolnik(2, 4), Pravoagolnik(3, 5), Pravoagolnik(1, 6) };

    cout << "Poleto od kvadrati pred sortiranje:" << endl;
    pecatiPole(kvadrati);
    sortirajPole(kvadrati);
    cout << "Poleto od kvadrati posle sortiranje:" << endl;
    pecatiPole(kvadrati);

    cout << "Poleto od pravoagolnici pred sortiranje:" << endl;
    pecatiPole(pravoagolnici);
    sortirajPole(pravoagolnici);
    cout << "Poleto od pravoagolnici posle sortiranje:" << endl;
    pecatiPole(pravoagolnici);

    return 0;
}
