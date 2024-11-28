//https://codeforces.com/problemset?order=BY_RATING_ASC&tags=data+structures

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void merge(vector<pair<int, int>>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    vector<pair<int, int>> L(n1), R(n2); //definimos los arreglos temporales
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    //aquí es el merge de los arreglos temporales
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].first <= R[j].first) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    //por si faltan elementos
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    //por si faltan elementos
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void merge_sort(vector<pair<int, int>>& arr, int left, int right) {
    if (left >= right) return;
    
    int mid = left + (right - left) / 2;
    
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    
    merge(arr, left, mid, right);
}

void solve_berland_music() {
    int n;
    cin >> n;
    
    vector<int> original_ratings(n); //mete ratings originales al vector
    for (int i = 0; i < n; i++) {
        cin >> original_ratings[i];
    }
    
    string likes; //likes o dislikes
    cin >> likes;
    
    
    vector<pair<int, int>> liked, disliked; //separar like y dislike
    for (int i = 0; i < n; i++) {
        if (likes[i] == '1') {
            liked.push_back({original_ratings[i], i});
        } else {
            disliked.push_back({original_ratings[i], i});
        }
    }
    
    
    if (!disliked.empty())
        merge_sort(disliked, 0, disliked.size() - 1);
    if (!liked.empty())
        merge_sort(liked, 0, liked.size() - 1);
    
    
    vector<int> new_ratings(n); //nueva permutación
    
    for (int i = 0; i < disliked.size(); i++) {
        new_ratings[disliked[i].second] = i + 1;
    }
    
    for (int i = 0; i < liked.size(); i++) {
        new_ratings[liked[i].second] = disliked.size() + i + 1;
    }
    
    for (int rating : new_ratings) {
        cout << rating << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        solve_berland_music();
    }
    
    return 0;
}