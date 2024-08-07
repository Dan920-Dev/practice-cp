// Birthdates

//  https://onlinejudge.org/external/125/12541.pdf

#include <bits/stdc++.h>

using namespace std;

int count_days(int dd , int mm , int yy){
      // Crear la fecha dada en std::tm
    std::tm fecha_dada = {};
    fecha_dada.tm_mday = dd;
    fecha_dada.tm_mon = mm - 1; // Mes - 1
    fecha_dada.tm_year = yy - 1900; // Año - 1900

    // Convertir la fecha dada a tiempo en segundos desde epoch
    std::time_t tiempo_dada = std::mktime(&fecha_dada);

    // Obtener la fecha actual
    std::time_t tiempo_actual = std::time(nullptr);

    // Calcular la diferencia en días
    return static_cast<int>((std::difftime(tiempo_actual, tiempo_dada) / (60 * 60 * 24)));
    return 0;
}

int main() {

    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);
    
    // code
    int n, dd, mm, yy;
    string name;
    vector<pair<int,string>> persons;

    cin >> n;
    while (n--)
    {
        cin >> name >> dd >> mm >> yy;
        persons.push_back(make_pair(count_days(dd, mm, yy),name));
    }

    sort(persons.begin(), persons.end());

    if(persons.size() > 1){
        cout << persons[0].second << "\n" << persons[persons.size() - 1].second << "\n";
    }else{
        cout << persons[0].second << "\n";
    }
    
    return 0;
}
