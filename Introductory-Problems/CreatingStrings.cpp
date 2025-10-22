#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>

#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rep0(i, a) rep(i, 0, a)
#define rep1(i, a) rep(i, 1, a + 1)
#define repr(i, a, b) for (int i = (b) - 1; i >= (a); i--)

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

//complexidade total: O(n!)


//pelo & alteramos a ref da string
//funcao existe no c++ como next_permutation(RandomIt beg, RandomIt end). Iteradores, nao a propria string de ref.
bool proxima_per(string& atual) {
    int l = atual.size();
    int i = l - 2;


    //i carrega o elemento mais a direita tal que atual[i] < atual[i + 1]
    while(i >= 0 && atual[i] >= atual[i + 1]) i--;
    if(i < 0) {
        //volta pra string inicial. sim, redundante mas set<string> evita problemas
        reverse(atual.begin(), atual.end());
        return false;
    }

    //j carrega o elemento mais a direita tal que atual[j] > atual[i]. garantido que exista - por construção

    int j = l - 1;
    while(atual[j] <= atual[i]) j--;

    //swap lexicográfico
    swap(atual[i], atual[j]);

    //reverse a partir de i + 1. Por que? Não sei. Não entendi legal não. Mas é isso aí.  
    reverse(atual.begin() + i + 1, atual.end());

    return true;
}

void solve() {
    string s; cin >> s;
    int n = s.size();
    
    set<string> out;

    sort(all(s));
    
    do {
        out.insert(s);
    } while (proxima_per(s));

    cout << out.size() << endl;
    for(auto& st : out) {
        cout << st << endl;
    }
}

int main() {
    fastio;
    int t = 1;
    //cin >> t;
    while(t--) {
	    solve();
    }

    return 0;
}

