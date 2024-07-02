/**
 * @author MoonLightLucrix
 * @link https://github.com/MoonLightLucrix
*/
#include "Animale.hpp"

Animale::Animale(std::string nome, float peso): nome(nome), peso(peso) {}

Animale::~Animale(){}

void Animale::setNome(std::string nome)
{
    this->nome=nome;
}

std::string Animale::getNome() const
{
    return nome;
}

void Animale::setPeso(float peso)
{
    this->peso=peso;
}

float Animale::getPeso() const
{
    return peso;
}

bool operator <(const Animale&a, const Animale&b)
{
    return (a.getPeso()!=b.getPeso())?a.getPeso()<b.getPeso():((dynamic_cast<const Gatto*>(&a)) && (dynamic_cast<const Cane*>(&b)));
}

bool operator >(const Animale&a, const Animale&b)
{
    return (a.getPeso()!=b.getPeso())?a.getPeso()>b.getPeso():((dynamic_cast<const Cane*>(&a)) && (dynamic_cast<const Gatto*>(&b)));
}

bool operator <=(const Animale&a, const Animale&b)
{
    return ((a<b) || (a==b));
}

bool operator >=(const Animale&a, const Animale&b)
{
    return ((a>b) || (a==b));
}

bool operator !=(const Animale&a, const Animale&b)
{
    return !(a==b);
}

bool operator ==(const Animale&a, const Animale&b)
{
    return ((a.getPeso()==b.getPeso()) && (((dynamic_cast<const Cane*>(&a)) && (dynamic_cast<const Cane*>(&b))) || ((dynamic_cast<const Gatto*>(&a)) && (dynamic_cast<const Gatto*>(&b)))));
}

std::ostream& operator <<(std::ostream &str, const Animale&a)
{
    str<<"Tipo: "<<((dynamic_cast<const Gatto*>(&a))?"Gatto":"Cane")<<" nome: "<<a.getNome()<<" peso: "<<a.getPeso();
    return str;
}

Gatto::Gatto(std::string nome, float peso): Animale(nome,peso) {}

Gatto::~Gatto(){}

std::string Gatto::verso() const
{
    return "Miao!";
}

Cane::Cane(std::string nome, float peso): Animale(nome,peso) {}

Cane::~Cane(){}

std::string Cane::verso() const
{
    return "Bau!";
}