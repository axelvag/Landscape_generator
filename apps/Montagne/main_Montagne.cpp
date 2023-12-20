#include <iostream>
#include <cmath>
using namespace std;


/// LISEZ TOUS LES COMMENTAIRES AVEC ATTENTION !!!
/// Il y a un PDF � l'adresse ci-dessous comportant des explications � lire en 1er
/// https://perso.liris.cnrs.fr/alexandre.meyer/teaching/LIFAMI/2020_LIFAMI_15mai.pdf
///
/// Vous devez respecter scrupuleusement les sections de r�ponses aux questions. UNE REPONSE HORS CASE NE SERA PAS CORRIGEE !
/// Vous respecterez scrupuleusement les noms de fonctions donn�es, les constantes donn�es.
/// UNE CONSIGNE NON RESPECTEE ANNULERA LA REPONSE A LA QUESTION !


/// Commentez la ligne suivante si vous n'arrivez pas � compiler avec Grapic => vous passerez en version TEXTE
#define TPNOTE_GRAPIC



#ifdef TPNOTE_GRAPIC
#include <Grapic.h>
using namespace grapic;
const int DIMW = 500;
#else
const int DIMW = 25;
float frand(float rmin, float rmax)
{
    float r = static_cast<float>(rand()) / RAND_MAX;
    return rmin + r * (rmax - rmin);
}

#endif // TPNOTE_GRAPIC





// ----------------------------------------- partie ALTITUDE --------------------------------------------------------------------------------------------------------------------------------------------------------- ID=85379
/// QUESTION 1) D�finissez une constante ALTITUDE_MAX � 445
/// D�finissez une structure Altitude qui stockera les valeurs d'une fonction discr�te.
/// La structure comportera un tableau v de r�els de taille ALTITUDE_MAX; un entier n indiquant combien de valeurs
/// sont utilis�es dans le tableau.
/// (1 point)
/// DEBUT REPONSE ID=39812

const int ALTITUDE_MAX = 445;

struct Altitude {
  float v[ALTITUDE_MAX];
  int n;
};


/// FIN REPONSE ID=83605



/// QUESTION 2) Ecrivez la proc�dure altitudeInit qui initialisera les donn�es d'une structure Altitude
/// � partir d'un entier indiquant combien de valeurs al�atoires doivent �tre tir�es et rang�es dans le tableau.
/// Cette fonction tirera les nombres al�atoires dans l'intervalle [0,1] et les rangera dans le tableau de valeurs.
/// (2 point)
/// DEBUT REPONSE ID=54276

void altitudeInit(Altitude& A,int R){
  A.n = R;
  for (int i = 0;i<R;i++){
    A.v[i] = frand(0,1);
  }
}





/// FIN REPONSE ID=45622



/// QUESTION 3) Ecrivez la fonction altitudeEval qui calcule la valeur de la fonction � partir d'un r�el.
/// La fonction est d�finie sur l'intervalle [0,1]. Les valeurs �chantillonn�es de la fonction sont stock�es
/// dans le tableau de valeurs. Vous ferez une interpolation entre les 2 cases du tableau correspondantes.
/// (2 point)
/// DEBUT REPONSE ID=70816

float altitudeEval(const Altitude& A,float x){
  int index = int(x*(A.n-1));
  float interp = (x*(A.n-1)) - index;
  if (x == 1){
    return A.v[A.n-1];//pour �viter segfault
  }
  return A.v[index] * (1-interp) + A.v[index+1]*(interp);
}

/// FIN REPONSE ID=31410


/// QUESTION 4) Ecrivez la fonction altitudeDraw qui dessine � l'�cran une carte d'Altitude.
/// Cette fonction prend en param�tre une structure Altitude et un r�el Scale qui correspond � un factur d'agrandisement.
/// Rappel : le tableau de valeur est initialis� avec des valeurs entre 0 et 1
/// donc pour l'afficher dans la fen�tre GRAPIC de taille DIMW, il faudra appeler cette fonction avec un scale de DIMW.
///
/// Modifiez la fonction main pour afficher une carte d'altitude et �tre s�r que ce que vous avez
/// cod� jusque l� marche.
///
/// Si vous �tes avec GRAPIC, parcourez toutes les colonnes DIMW de la fen�tre et tracer une ligne
/// entre le bas de l'�cran et l'altitude donn�e par l'�valuation de la fonction Altitude.
/// Ramenez le num�ro de la colonne i � un r�el 0.0 et 1.0, puis la fonction altitudeEval vous donnerra l'altitude.
///
/// Si vous �tes en mode TEXTE, la montagne sera affich�e � l'horizontal avec des '*', pointe vers la droite.
/// La constante DIMW est d�j� d�finie et correspond au nombre de lignes. Pour chaque ligne, vous
/// calculez l'altitude de la colonne (=la largeur � l'�cran) avec la fonction altitudeEval.
/// Le r�el � donner � altitudeEval correspond au num�ro de la ligne ramen� entre 0.0 et 1.0
///
/// (2 point)
/// DEBUT REPONSE ID=96761

void altitudeDraw(const Altitude& A,float scale){
  for (int i = 0;i<DIMW;i++){
    line(i,0,i,altitudeEval(A,float(i)/DIMW)*scale);
  }
}


/// FIN REPONSE ID=57995



/// QUESTION 5) Ecrivez la fonction operator+ qui permet d'additionner deux variables de type Altitude.
/// Attention : les deux param�tres de type Altitude n'ont pas forc�ment le m�me nombre de valeurs.
/// La valeur de retour de cette addition sera une structure Altitude dont le nombre de valeurs sera la max entre
/// les deux nombres de valeurs des deux param�tres. Vous remplirez le tableau de valeurs de la variable r�sultat
/// en utilisant la fonction altitudeEval pour retrouver la valeur de la fonction altitude pour un r�el x.
/// (2 point)
/// DEBUT REPONSE ID=78349

Altitude operator+(const Altitude& A,const Altitude& B){
    Altitude C;
    C.n = max(A.n,B.n);
    float x;

    for (int i = 0;i<C.n;i++){
      x = float(i)/(C.n-1);
      C.v[i] = altitudeEval(A,x) + altitudeEval(B,x);
    }
    return C;
}


/// FIN REPONSE ID=48745



/// QUESTION 6) Ecrivez la fonction operator* qui multiplie une structure Altitude par un r�el.
/// Cette fonction renvoie une variable de type Altitude dont les valeurs stock�es auront �t� multipli�es par le r�el.
///
/// Si vous voulez �tre sur que ces deux fonctions sont ok, modifiez le main pour tester.
/// (1 point)
/// DEBUT REPONSE ID=60441

Altitude operator*(const Altitude& A,float k){
    Altitude C;
    C.n = A.n;

    for (int i = 0;i<C.n;i++){
      C.v[i] = A.v[i]*k;
    }
    return C;
}

/// FIN REPONSE ID=49297



/// Nous vous offrons une fonction qui affiche les valeurs de la structure Altitude pour vous aider � deboguer
/*
void altitudePrint(Altitude a)
{
    cout<<"n="<<a.n<<" ";
    int i;
    for(i=0;i<a.n;i++)
        cout<<a.v[i]<<" ";
    cout<<endl;
}
*/


// ----------------------------------------- partie COULEUR --------------------------------------------------------------------------------------------------------------------------------------------------------- ID=54344
/// QUESTION 7) Ecrivez la structure Couleur et la fonction make_couleur correspondante.
/// Si vous �tes avec Grapic, cette structure comportera 3 entiers r,g,b.
/// Si vous �tes en mode texte, cette structure comportera juste un caract�re c.
/// (1 point)
/// DEBUT REPONSE ID=71493


struct Couleur{
  int r;//je sais que ce serait mieux avec des unsigned char mais je suis le tp
  int g;
  int b;
};

Couleur  make_couleur(int r,int g,int b)
{
    Couleur C;
    C.r = r;
    C.g = g;
    C.b = b;
    return C;
}

/// FIN REPONSE ID=93479



// ----------------------------------------- partie MONTAGNE --------------------------------------------------------------------------------------------------------------------------------------------------------- ID=33408
/// QUESTION 8) Ecrivez une structure Montagne qui comporte un champ Altitude alt et une couleur col.
/// (1 point)
/// DEBUT REPONSE ID=43760

struct Montagne{
  Altitude alt;
  Couleur col;
};



/// FIN REPONSE ID=98859



/// QUESTION 9) Ecrivez la proc�dure montagneInit qui initialisera un param�tre Montagne m
/// � partir d'une couleur et d'un r�el alti_moyenne qui repr�sentera une altitude moyenne.
/// Voir le document PDF, notamment l'exemple de calcul sommant les diff�rents niveaux
/// pour obtenir une altitude. Il faut calculer les diff�rents niveaux d'Altitude dans
/// un tableau d'Altitude d�clar� en variable locale.
///
/// Vous pouvez faire une version simple de cette fonction qui calcule l'altitude
/// de m avec  0.5f * alti_moyenne * niveau_0  +  0.06f* alti_moyenne * niveau_5
/// en ayant initialis� niveau_0 avec 6 valeurs et niveau_5 avec 192 valeurs;
/// (4 point en version compl�te; 2 points la version simple)
/// DEBUT REPONSE ID=98705



void montagneInit(Montagne& m,const Couleur& C,float alti_moyenne){
  m.col = C;
  Altitude niveaux[6];
  for (int i = 0;i<6;i++){
    altitudeInit(niveaux[i],6*pow(2,i));
  }
  m.alt = niveaux[0]*alti_moyenne;
  for (int i = 1;i<6;i++){
    m.alt = m.alt + niveaux[i]*alti_moyenne*pow(0.5,i);
  }
}



/// FIN REPONSE ID=77132



/// QUESTION 10) Ecrivez la proc�dure montagneDraw qui dessine une montagne en appelant altitudeDraw.
/// Il faut bien r�gler le param�tre scale, en tenant compte du fait que la taille de l'�cran a �t� int�gr� dans montagneInit
/// et que normalement le tableau d'altitude comporte maintenant des hauteurs entre 0 et DIMW qui n�cessite un scale 'neutre'.
/// (0.5 point)
/// DEBUT REPONSE ID=93011

void montagneDraw(const Montagne& M){
    color(M.col.r,M.col.g,M.col.b);
    altitudeDraw(M.alt,1);
}

/// FIN REPONSE ID=40233



// ----------------------------------------- partie Monde/Paysage --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- ID=92671

/// QUESTION 11) D�clarez une constante MAX_NIV initialis�e � 290
/// D�clarez une structure Monde qui comportera un tableau de Montagne,
/// ainsi qu'un entier indiquant combien de Montagne sont affich�es.
/// (1 point)
/// DEBUT REPONSE ID=37177

const int MAX_NIV = 290;

struct Monde{
  Montagne rocks[MAX_NIV];
  int n;
};

/// FIN REPONSE ID=32694



/// QUESTION 12) Ecrivez la proc�dure mondeInit qui prends en param�tre le Monde � initialiser,
/// ainsi qu'un entier indiquant le nombre de plans se superposant.
/// Soyez inventif pour la couleur et l'altitude moyenne : les montagnes du fond sont plus hautes et
/// plus clair que celles de devant pour donner un effet de contre jour (soleil couchant).
/// Il faut ranger les montagnes du fond en premier dans le tableau.
/// (2 point)
/// DEBUT REPONSE ID=25499

void mondeInit(Monde& M,int planes){
  M.n = planes;
  Couleur C;
  float s;
  for (int i = 0;i<M.n;i++){
    s = (1-(float(i)/M.n));
    C = make_couleur(30  * s,176 * s,255 * s);
    montagneInit(M.rocks[i],C,0.5*s*DIMW);
  }
}

/// FIN REPONSE ID=15262



/// QUESTION 13) Ecrivez la fonction qui affiche un Monde
/// (0.5 point)
/// DEBUT REPONSE ID=27631

void mondeDraw(const Monde& M) {
  for (int i = 0;i<M.n;i++) {
    montagneDraw(M.rocks[i]);
  }
}

/// FIN REPONSE ID=69412



// ----------------------------------------- background (pas de question) --------------------------------------------------------------------------------------------------------------------------------------------------------- ID=38909
#ifdef TPNOTE_GRAPIC
void backgroundDraw()
{
    int i,x,y;
    for(i=0;i<DIMW;i++)
    {
        const float c = 0.28f;
        color(0.27f*(c*i+15), 1.35f*(c*i+15), 1.63f*(c*i+15));
        line( 0, DIMW-i, DIMW, DIMW-i);
    }
    srand(217);
    for(i=0;i<100;++i)
    {
        x = irand(0,DIMW);
        y = irand(DIMW/3, DIMW);
        int add = (DIMW-y)/3;
        color( 100+add, 130+add, 100+add);
        circleFill( x, y, 1);
    }
}
// ID=94910
#endif



// ----------------------------------------- main --------------------------------------------------------------------------------------------------------------------------------------------------------- ID=33500
/// QUESTION 14) Ecrivez le code de la fonction main : d�clarer un Monde (ou un Altitude pour debuguer la partie Altitude),
/// puis initialiser et afficher dans la boucle.
/// (0.5 point)
#ifdef TPNOTE_GRAPIC
int main(int, char ** )
{
    bool stop=false;
    winInit("Paysage", DIMW, DIMW);
    setKeyRepeatMode(false);
    backgroundColor( 27, 135, 163 );

/// DEBUT REPONSE ID=22903

    Monde M;
    mondeInit(M,20);

/// FIN REPONSE ID=37278

    while( !stop )
    {
        /// ID=60768
        winClear();
        backgroundDraw();

/// DEBUT REPONSE ID=76290

        mondeDraw(M);

/// FIN REPONSE ID=81040

        stop = winDisplay();
    }
    winQuit();
    return 0;
}
#else
int main()
{
/// DEBUT REPONSE ID=47312



/// FIN REPONSE ID=72061
}
#endif
