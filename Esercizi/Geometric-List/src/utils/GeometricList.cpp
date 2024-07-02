/**
 * @author MoonLightLucrix
 * @link https://github.com/MoonLightLucrix
*/
GeometricList::GeometricList(){}

GeometricList::~GeometricList(){}

GeometricList* GeometricList::ins(Cerchio c)
{
    l.ins(c);
    return this;
}

double GeometricList::mediaArea()
{
    size_t size=l.getSize();
    
    return l.reduce<double>([size](Cerchio x, double y){return (x.getArea()/size)+y;}); //Metodo che usa una funzione lambda per calcolare la media delle aree dei cerchi presenti nella lista.
    
    /*double media=0; //Metodo che cicla la lista e calcola la media delle aree dei cerchi presenti nella lista.
    for(const Cerchio c:l)
    {
        media+=c.getArea()/size;
    }
    return media;*/
}

void GeometricList::stampa()
{
    l.stampa();
}
