//https://codeforces.com/problemset/problem/4/C

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    unordered_map<string, int> username_count;
    
    for (int i = 0; i < n; i++) {
        string username;
        cin >> username;
        
        //aquí registramos al usuario nuevo
        if (username_count.find(username) == username_count.end()) {
            cout << "OK" << endl;
            username_count[username] = 1;
        } 
        else {
            int count = username_count[username]; //sacamos el recuento de veces que se ha metido
            
            /*checamos si el nuevo nombre de usuario ya existe en el mapa.
            Si sí existe, se le suma uno hasta que se encuentre uno único*/
            while (username_count.find(username + to_string(count)) != username_count.end()) {
                count++;
            }
            string new_username = username + to_string(count);
            cout << new_username << endl;
            username_count[new_username] = 1;
            username_count[username] = count + 1;
        }
    }
    
    return 0;
}
