#include <iostream>
#include <string>
#include <vector>

// Clasa abstracta Contact
class Contact {
protected:
    std::string nume;

public:
    Contact(const std::string& nume) : nume(nume) {}

    virtual ~Contact() {}

    std::string getNume() const {
        return nume;
    }
};

// Enumerare pentru tipul de contact
enum class TipContact {
    Prieten,
    Cunoscut,
    Coleg
};

// Clasa Prieten derivata din clasa Contact
class Prieten : public Contact {
private:
    std::string dataNastere;
    std::string numarTelefon;
    std::string adresa;

public:
    Prieten(const std::string& nume, const std::string& dataNastere, const std::string& numarTelefon, const std::string& adresa)
        : Contact(nume), dataNastere(dataNastere), numarTelefon(numarTelefon), adresa(adresa) {}

    std::string getDataNastere() const {
        return dataNastere;
    }

    std::string getNumarTelefon() const {
        return numarTelefon;
    }

    std::string getAdresa() const {
        return adresa;
    } 
};

// Clasa Cunoscut derivata din clasa Contact
class Cunoscut : public Contact {
private:
    std::string numarTelefon;

public:
    Cunoscut(const std::string& nume, const std::string& numarTelefon)
        : Contact(nume), numarTelefon(numarTelefon) {}

    std::string getNumarTelefon() const {
        return numarTelefon;
    }
};

// Clasa Coleg derivata din clasa Contact
class Coleg : public Contact {
private:
    std::string numarTelefon;
    std::string firma;
    std::string adresa;

public:
    Coleg(const std::string& nume, const std::string& numarTelefon, const std::string& firma, const std::string& adresa)
        : Contact(nume), numarTelefon(numarTelefon), firma(firma), adresa(adresa) {}

    std::string getNumarTelefon() const {
        return numarTelefon;
    }

    std::string getFirma() const {
        return firma;
    }

    std::string getAdresa() const {
        return adresa;
    }
};

// Clasa Agenda
class Agenda {
private:
    std::vector<Contact*> contacte;

public:
    ~Agenda() {
        for (Contact* contact : contacte) {
            //delete contact;
        }
    }

    Contact* cautareContact(const std::string& nume) {
        for (Contact* contact : contacte) {
            if (contact->getNume() == nume) {
                return contact;
            }
        }
        return nullptr;
    }

    std::vector<Prieten*> getPrieteni() {
        std::vector<Prieten*> prieteni;
        for (Contact* contact : contacte) {
            if (dynamic_cast<Prieten*>(contact)) {
                prieteni.push_back(static_cast<Prieten*>(contact));
            }
        }
        return prieteni;
    }

    void stergeContact(const std::string& nume) {
        for (auto it = contacte.begin(); it != contacte.end(); ++it) {
            if ((*it)->getNume() == nume) {
                delete* it;
                contacte.erase(it);
                break;
            }
        }
    }

    void adaugaContact(Contact* contact) {
        contacte.push_back(contact);
    }
};

int main() {
    // Exemplu de utilizare

    // Creare un obiect de tipul Agenda
    Agenda agenda;

    // Adaugare de contacte
    Prieten* prieten1 = new Prieten("Ion", "01/01/1990", "1234567890", "Adresa1");
    agenda.adaugaContact(prieten1);

    Cunoscut* cunoscut1 = new Cunoscut("Valeria", "9876543210");
    agenda.adaugaContact(cunoscut1);

    Coleg* coleg1 = new Coleg("Bob", "5555555555", "FirmaX", "Bulevardul Stefan cel Mare 2");
    agenda.adaugaContact(coleg1);

    // Cautare contact dupa nume
    Contact* contact = agenda.cautareContact("Valeria");
    if (contact != nullptr) {
        std::cout << "Am gasit contactul cu numele " << contact->getNume() << std::endl;
    }
    else {
        std::cout << "Nu am gasit contactul cu numele Valeria" << std::endl;
    }

    // Obtinere lista de prieteni
    std::vector<Prieten*> prieteni = agenda.getPrieteni();
    std::cout << "Lista de prieteni:" << std::endl;
    for (const auto& prieten : prieteni) {
        std::cout << "- " << prieten->getNume() << std::endl;
    }

    // Stergere contact dupa nume
    agenda.stergeContact("Bob");

    // Eliberare memorie
    delete prieten1;
    delete cunoscut1;

    return 0;
}
