#include <iostream>
#include <cmath>
using namespace std;


/// LISEZ TOUS LES COMMENTAIRES AVEC ATTENTION !!!
/// Il y a un PDF à l'adresse ci-dessous comportant des explications à lire en 1er
/// https://perso.liris.cnrs.fr/alexandre.meyer/teaching/LIFAMI/2020_LIFAMI_15mai.pdf
///
/// Vous devez respecter scrupuleusement les sections de réponses aux questions. UNE REPONSE HORS CASE NE SERA PAS CORRIGEE !
/// Vous respecterez scrupuleusement les noms de fonctions données, les constantes données.
/// UNE CONSIGNE NON RESPECTEE ANNULERA LA REPONSE A LA QUESTION !


/// Commentez la ligne suivante si vous n'arrivez pas à compiler avec Grapic => vous passerez en version TEXTE
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





// ----------------------------------------- partie ALTITUDE --------------------------------------------------------------------------------------------------------------------------------------------------------- ID=44214
/// QUESTION 1) Définissez une constante ALTITUDE_MAX à 303
/// Définissez une structure Altitude qui stockera les valeurs d'une fonction discrète.
/// La structure comportera un tableau v de réels de taille ALTITUDE_MAX; un entier n indiquant combien de valeurs
/// sont utilisées dans le tableau.
/// (1 point)
/// DEBUT REPONSE ID=86037






/// FIN REPONSE ID=89465



/// QUESTION 2) Ecrivez la procédure altitudeInit qui initialisera les données d'une structure Altitude
/// à partir d'un entier indiquant combien de valeurs aléatoires doivent être tirées et rangées dans le tableau.
/// Cette fonction tirera les nombres aléatoires dans l'intervalle [0,1] et les rangera dans le tableau de valeurs.
/// (2 point)
/// DEBUT REPONSE ID=85520







/// FIN REPONSE ID=16936



/// QUESTION 3) Ecrivez la fonction altitudeEval qui calcule la valeur de la fonction à partir d'un réel.
/// La fonction est définie sur l'intervalle [0,1]. Les valeurs échantillonnées de la fonction sont stockées
/// dans le tableau de valeurs. Vous ferez une interpolation entre les 2 cases du tableau correspondantes.
/// (2 point)
/// DEBUT REPONSE ID=91685








/// FIN REPONSE ID=13065


/// QUESTION 4) Ecrivez la fonction altitudeDraw qui dessine à l'écran une carte d'Altitude.
/// Cette fonction prend en paramètre une structure Altitude et un réel Scale qui correspond à un factur d'agrandisement.
/// Rappel : le tableau de valeur est initialisé avec des valeurs entre 0 et 1
/// donc pour l'afficher dans la fenêtre GRAPIC de taille DIMW, il faudra appeler cette fonction avec un scale de DIMW.
///
/// Modifiez la fonction main pour afficher une carte d'altitude et être sûr que ce que vous avez
/// codé jusque là marche.
///
/// Si vous êtes avec GRAPIC, parcourez toutes les colonnes DIMW de la fenêtre et tracer une ligne
/// entre le bas de l'écran et l'altitude donnée par l'évaluation de la fonction Altitude.
/// Ramenez le numéro de la colonne i ç un réel 0.0 et 1.0, puis la fonction altitudeEval vous donnerra l'altitude.
///
/// Si vous êtes en mode TEXTE, la montagne sera affichée à l'horizontal avec des '*', pointe vers la droite.
/// La constante DIMW est déjà définie et correspond au nombre de lignes. Pour chaque ligne, vous
/// calculez l'altitude de la colonne (=la largeur à l'écran) avec la fonction altitudeEval.
/// Le réel à donner à altitudeEval correspond au numéro de la ligne ramené entre 0.0 et 1.0
///
/// (2 point)
/// DEBUT REPONSE ID=54425



























/// FIN REPONSE ID=95919



/// QUESTION 5) Ecrivez la fonction operator+ qui permet d'additionner deux variables de type Altitude.
/// Attention : les deux paramètres de type Altitude n'ont pas forcément le même nombre de valeurs.
/// La valeur de retour de cette addition sera une structure Altitude dont le nombre de valeurs sera la max entre
/// les deux nombres de valeurs des deux paramètres. Vous remplirez le tableau de valeurs de la variable résultat
/// en utilisant la fonction altitudeEval pour retrouver la valeur de la fonction altitude pour un réel x.
/// (2 point)
/// DEBUT REPONSE ID=44268













/// FIN REPONSE ID=15647



/// QUESTION 6) Ecrivez la fonction operator* qui multiplie une structure Altitude par un réel.
/// Cette fonction renvoie une variable de type Altitude dont les valeurs stockées auront été multipliées par le réel.
///
/// Si vous voulez être sur que ces deux fonctions sont ok, modifiez le main pour tester.
/// (1 point)
/// DEBUT REPONSE ID=21059









/// FIN REPONSE ID=11719



/// Nous vous offrons une fonction qui affiche les valeurs de la structure Altitude pour vous aider à deboguer
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


// ----------------------------------------- partie COULEUR --------------------------------------------------------------------------------------------------------------------------------------------------------- ID=58787
/// QUESTION 7) Ecrivez la structure Couleur et la fonction make_couleur correspondante.
/// Si vous êtes avec Grapic, cette structure comportera 3 entiers r,g,b.
/// Si vous êtes en mode texte, cette structure comportera juste un caractère c.
/// (1 point)
/// DEBUT REPONSE ID=71491













/// FIN REPONSE ID=11282



// ----------------------------------------- partie MONTAGNE --------------------------------------------------------------------------------------------------------------------------------------------------------- ID=95542
/// QUESTION 8) Ecrivez une structure Montagne qui comporte un champ Altitude alt et une couleur col.
/// (1 point)
/// DEBUT REPONSE ID=21835





/// FIN REPONSE ID=27252



/// QUESTION 9) Ecrivez la procédure montagneInit qui initialisera un paramètre Montagne m
/// à partir d'une couleur et d'un réel alti_moyenne qui représentera une altitude moyenne.
/// Voir le document PDF, notamment l'exemple de calcul sommant les différents niveaux
/// pour obtenir une altitude. Il faut calculer les différents niveaux d'Altitude dans
/// un tableau d'Altitude déclaré en variable locale.
///
/// Vous pouvez faire une version simple de cette fonction qui calcule l'altitude
/// de m avec  0.5f * alti_moyenne * niveau_0  +  0.06f* alti_moyenne * niveau_5
/// en ayant initialisé niveau_0 avec 6 valeurs et niveau_5 avec 192 valeurs;
/// (4 point en version complète; 2 points la version simple)
/// DEBUT REPONSE ID=12610





































































/// FIN REPONSE ID=68179



/// QUESTION 10) Ecrivez la procédure montagneDraw qui dessine une montagne en appelant altitudeDraw.
/// Il faut bien régler le paramètre scale, en tenant compte du fait que la taille de l'écran a été intégré dans montagneInit
/// et que normalement le tableau d'altitude comporte maintenant des hauteurs entre 0 et DIMW qui nécessite un scale 'neutre'.
/// (0.5 point)
/// DEBUT REPONSE ID=36193







/// FIN REPONSE ID=18402






// ----------------------------------------- partie Monde/Paysage --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- ID=19194

/// QUESTION 11) Déclarez une constante MAX_NIV initialisée à 222
/// Déclarez une structure Monde qui comportera un tableau de Montagne,
/// ainsi qu'un entier indiquant combien de Montagne sont affichées.
/// (1 point)
/// DEBUT REPONSE ID=47850






/// FIN REPONSE ID=16459



/// QUESTION 12) Ecrivez la procédure mondeInit qui prends en paramètre le Monde à initialiser,
/// ainsi qu'un entier indiquant le nombre de plans se superposant.
/// Soyez inventif pour la couleur et l'altitude moyenne : les montagnes du fond sont plus hautes et
/// plus clair que celles de devant pour donner un effet de contre jour (soleil couchant).
/// Il faut ranger les montagnes du fond en premier dans le tableau.
/// (2 point)
/// DEBUT REPONSE ID=26122























/// FIN REPONSE ID=99179



/// QUESTION 13) Ecrivez la fonction qui affiche un Monde
/// (0.5 point)
/// DEBUT REPONSE ID=20887








/// FIN REPONSE ID=49879



// ----------------------------------------- background (pas de question) --------------------------------------------------------------------------------------------------------------------------------------------------------- ID=12296
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
// ID=27328
#endif



// ----------------------------------------- main --------------------------------------------------------------------------------------------------------------------------------------------------------- ID=52070
/// QUESTION 14) Ecrivez le code de la fonction main : déclarer un Monde (ou un Altitude pour debuguer la partie Altiude),
/// puis initialiser et afficher dans la boucle.
/// (0.5 point)
#ifdef TPNOTE_GRAPIC
int main(int, char ** )
{
    bool stop=false;
    winInit("Paysage", DIMW, DIMW);
    setKeyRepeatMode(false);
    backgroundColor( 27, 135, 163 );

/// DEBUT REPONSE ID=93556


/// FIN REPONSE ID=30176

    while( !stop )
    {
        /// ID=10621
        winClear();
        backgroundDraw();

/// DEBUT REPONSE ID=44394

/// FIN REPONSE ID=15526

        stop = winDisplay();
    }
    winQuit();
    return 0;
}
#else
int main()
{
/// DEBUT REPONSE ID=91575



/// FIN REPONSE ID=46531
}
#endif
