Cerchio::Cerchio(double r): r(r), d(calcolaDiametro()), perimetro(calcolaPerimetro()), area(calcolaArea()) {}

Cerchio::~Cerchio(){}

void Cerchio::setRaggio(double r)
{
    this->r=r;
    d=calcolaDiametro();
    perimetro=calcolaPerimetro();
    area=calcolaArea();
}

double Cerchio::getRaggio() const
{
    return r;
}

double Cerchio::calcolaDiametro()
{
    return r*2;
}

double Cerchio::getDiametro() const
{
    return d;
}

double Cerchio::calcolaPerimetro()
{
    return 2*M_PI*r;
}

double Cerchio::getPerimetro() const
{
    return perimetro;
}

double Cerchio::calcolaArea()
{
    return M_PI*r*r;
}

double Cerchio::getArea() const
{
    return area;
}

bool operator <(const Cerchio&a, const Cerchio&b)
{
    return (a.area<b.area);
}

bool operator >(const Cerchio&a, const Cerchio&b)
{
    return (a.area>b.area);
}

bool operator <=(const Cerchio&a, const Cerchio&b)
{
    return (a.area<=b.area);
}

bool operator >=(const Cerchio&a, const Cerchio&b)
{
    return (a.area>=b.area);
}

bool operator ==(const Cerchio&a, const Cerchio&b)
{
    return (a.area==b.area);
}

bool operator !=(const Cerchio&a, const Cerchio&b)
{
    return (a.area!=b.area);
}

std::ostream& operator <<(std::ostream &str, const Cerchio&a)
{
    str<<"raggio: "<<a.r<<" diametro: "<<a.d<<" perimetro: "<<a.perimetro<<" area: "<<a.area;
    return str;
}