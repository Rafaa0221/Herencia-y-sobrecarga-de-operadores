#include <iostream>
#include <string>

using namespace std;

class Mamifero{
    private:
        string raza;
        int anioNac;
        string lugarNac;
        string dieta;
    public:
        Mamifero();
        void set_raza(string);
        void set_anioNac(int);
        void set_lugarNac(string);
        void set_dieta(string);
        string get_raza();
        int get_anioNac();
        string get_lugarNac();
        string get_dieta();
        void printRaza();
        void printNac();
        void printDieta();
        bool operator==(Mamifero & );
        bool operator!=(Mamifero & );
        bool operator<(Mamifero & );
        bool operator>(Mamifero & );
        int operator+(Mamifero & );
        Mamifero( Mamifero &M1)
        {
        raza= M1.raza;
        }
        Mamifero &operator=( Mamifero &M1){
            if (this != &M1){
            raza = M1.raza;
            }
        return *this;
        }
        Mamifero(Mamifero &&other) : raza(move(other.raza)),anioNac(other.anioNac){
            other.anioNac=0;
        }
        Mamifero &operator=(Mamifero &&other){
            if(this!=&other){
                raza=move(other.raza);
                anioNac=other.anioNac;
                other.anioNac=0;
            }
            return *this;
        }
};

class Felino : public Mamifero{
    private:
        string circo;
    public:
        Felino();
        void set_circo(string);
        string get_circo();
        void cambiarCirco(string);
};

class GatoDomestico : public Felino{
    private:
        string nombreDuenio;
    public:
        GatoDomestico();
        void set_nomDuenio(string);
        string get_nomDuenio();
        void cambiarNomDuenio(string);
        void printDuenio();
};


Mamifero::Mamifero(){
    raza="";
    anioNac=0;
    lugarNac="";
    dieta="";
}

Felino::Felino(){
    Mamifero();
    circo="";
}

GatoDomestico::GatoDomestico(){
    Felino();
    nombreDuenio="";
}

void Mamifero::set_raza(string R){
    raza=R;
}

void Mamifero::set_dieta(string D){
    dieta=D;
}

void Mamifero::set_lugarNac(string LN){
    lugarNac=LN;
}

void Mamifero::set_anioNac(int AN){
    anioNac=AN;
}

string Mamifero::get_dieta(){
    return dieta;
}

string Mamifero::get_raza(){
    return raza;
}

string Mamifero::get_lugarNac(){
    return lugarNac;
}

int Mamifero::get_anioNac(){
    return anioNac;
}

void Felino::set_circo(string C){
    circo=C;
}

string Felino::get_circo(){
    return circo;
}

void GatoDomestico::set_nomDuenio(string ND){
    nombreDuenio=ND;
}

void Mamifero::printRaza(){
    cout<<raza<<endl;
}

void Mamifero::printDieta(){
    cout<<dieta<<endl;
}

void Mamifero::printNac(){
    cout<<"Lugar de Nacimiento: "<<lugarNac<<endl;
    cout<<"Anio de Nacimiento: "<<anioNac<<endl<<endl;
}

void GatoDomestico::printDuenio(){
    cout<<"Nombre de duenio: "<<nombreDuenio<<endl;
}

void GatoDomestico::cambiarNomDuenio(string _duenio){
    cout<<"Actual nombre de duenio: "<<nombreDuenio<<endl;
    nombreDuenio=_duenio;
    cout<<"Nuevo nombre de duenio: "<<nombreDuenio<<endl;
    cout<<"Nombre de Duenio actualizado correctamente."<<endl<<endl;
}

void Felino::cambiarCirco(string _circo){
    cout<<"Actual nombre de circo: "<<circo<<endl;
    circo=_circo;
    cout<<"Nuevo nombre de circo: "<<circo<<endl;
    cout<<"Nombre de circo actualizado correctamente."<<endl<<endl;
}

bool Mamifero::operator==(Mamifero & M1){
    return (Mamifero::get_raza()==M1.get_raza());
}

bool Mamifero::operator!=(Mamifero & M1){
    return (Mamifero::get_dieta()!=M1.get_dieta());
}

bool Mamifero::operator<(Mamifero & M1){
    return (Mamifero::get_anioNac()<M1.get_anioNac());
}

bool Mamifero::operator>(Mamifero & M1){
    return (Mamifero::get_anioNac()>M1.get_anioNac());
}

int Mamifero::operator+(Mamifero &M1){
    return (Mamifero::get_anioNac()+M1.get_anioNac());
}



int main()
{
    int suma;
    GatoDomestico Minino;
    Felino EstrellaCirco;
    Felino EstrellaCirco1=EstrellaCirco;
    GatoDomestico Minino2 = move(Minino);

    Minino.set_raza("Siames");
    EstrellaCirco.set_raza("Siames");
    Minino.set_dieta("comida de gato");
    EstrellaCirco.set_dieta("carne");
    Minino.set_lugarNac("Mexico");
    EstrellaCirco.set_lugarNac("Italia");
    Minino.set_anioNac(2010);
    EstrellaCirco.set_anioNac(2015);
    EstrellaCirco.set_circo("du solei");
    Minino.set_nomDuenio("Pepe");

    cout<<"Dieta de minino: ";
    Minino.printDieta();
    cout<<"Dieta de estrella de circo: ";
    EstrellaCirco.printDieta();
    cout<<endl<<"Datos de nacimiento de minino"<<endl;
    Minino.printNac();
    cout<<endl<<"Datos de nacimiento de estrella de circo"<<endl;
    EstrellaCirco.printNac();
    Minino.cambiarNomDuenio("Rafael");
    EstrellaCirco.cambiarCirco("Americas");
    cout<<"Raza de minino: ";
    Minino.printRaza();
    cout<<"Raza de estrella de circo: ";
    EstrellaCirco.printRaza();

    if(Minino==EstrellaCirco){
        cout<<"Son la misma raza"<<endl<<endl;
    }
    if(Minino!=EstrellaCirco){
        cout<<"No tienen la misma dieta"<<endl<<endl;
    }
    if(EstrellaCirco<Minino){
        cout<<"Minino es menor en anios que estrella de circo"<<endl<<endl;
    }
    if(EstrellaCirco>Minino){
        cout<<"Minino es mayor en anios que estrella de circo"<<endl<<endl;
    }
    suma=Minino+EstrellaCirco;
    cout<<suma;

    return 0;
}
