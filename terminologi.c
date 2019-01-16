/*
 * Preprocessor directive
 */
#include <stdio.h> // Library header inclusion
#include <math.h>
#define PI 3.14159 // Konstant definitioner
#define E 2.71828 // Symbolske konstanter
#define MAX_NUM 5

/*
 * Erklæring (declaration)
 */
double log_two(double x); // Prototype (funktion der er erklæret)
double radius; // Dette er en global variabel

/*                     / enumeration konstant */
enum weekday {sunday, monday, tuesday, wednesday, thursday,
              friday, saturday};
typedef enum weekday weekday; // Typenavn (typedef)

/*
 * Struct (record i andre programmeringssprog)
 */
struct date {
    weekday day_of_week;
    int day; // Felt (field) / member
    int month;
    int year;
}

struct point {
    double x, y;
}

struct circle {
    struct point center;
    double radius;
}

struct rectangle {
    struct point upper_left, lower_right;
}

enum geometrict_kind {circle, rectangle};

struct geometrict_form {
    enum geometrict_kind kind;
    union {
        struct circle circle; // Felt (field)
        struct rectangle rectangle;
    } form
}

/* Union vs struct
 * 
 * I en union er felterne placeret oven i hinanden
 * I et struct er felterne placeret ved siden af hinanden (konsekutivt)
 * 
 * Så på dansk betyder det er en union kun kan tildeles én værdi af gangen
 * så ved f.eks. den union der hedder form kan den enten være circle eller rectangle
 * men ikke begge
 * En struct kan dog have begge værdier.
 */

int main(void) {
    /*
     * Lokale variabler
     * De er initialiseret (Tildelt en start-værdi) Dette er god kutyme
     */
    double rad1 = 4.0, d = 0;
    const double rad2 = 1.5; // Konstant - kan ikke ændres efter den er blevet initialiseret
    int i = 0, x = 1, y = 2, res1, res2, res3, res4, res5;

    /* int      heltal
     * char     karakter
     * double   floating-point tal (kommatal)
     * float    floating-point tal (kommatal)
     * enum     enumeration type
     * double[] array (elementtype: double)
     */

    double table[3] = {5.3, 7.7, 2.0};
    /* \_ type   \_ Størrelse på array */
    // table[0] == 5.3
    // table[1] == 7.7
    // table[2] == 2.0
    /* Array tilgåes vha subscripting (table[i]) */

    /*         Formateringsstreng      print list */     
    printf("%d examples with log2: \n", MAX_NUM);
    /*       \_placeholder */
    /*
     * Følgende er et iterativt kontrolstruktur (for-løkker og while-loops)
     */
    // for(initialisering; fortsættelsesbetingelse; opdateringsudtryk)
    for(i=1, d=2.0; i<=MAX_NUM; i++, d*= 2)
        printf("log2(%f) = %f\n", d, 1.0 / log(2.0) * log(d));

    /*     | Udtryk (expression) |
           |                     | */
    res1 = x + y * 3 >= y & x - 5;
    // '>=' er en sammenlignings-operator
    // Følgende er operator i ovenstående udtryk: + * >= & -
    // Følgende er operander i ovenstående udtryk: x y 3 5
    /*
     * Rent udtryk
     * Er et udtryk hvor ingen af de ingående variabler ændrer værdi.
     * Eksempel: Udtrykket på højre side af lighedstegnet ^
     * 
     * Urent udtryk
     * Er et udtryk hvor der er variabler der ændrer værdi ved følge af
     * at udtrykket bliver beregnet
     * Eksempel: Hele ovenstående udtryk.
     * res1 ændrer værdi, da '=' er en assignment operator
     * 
     * Logisk udtryk
     * Er et udtryk som retunerer en bolsk værdi (0 eller ikke 0 i C)
     * Logiske udtryk indgår typisk i selective og iterative kontrolstrukturer
     * 
     * L-udtryk
     * Den venstre side af lighedstegnet i ovenstående udtryk er
     * et L-udtryk, fordi det betegner en plads/indeholdet i lagret.
     * Eksempler:
     * tbl[0]
     * *(tbl + 4) (er det samme som tbl[4])
     */

    /* Betinget udtryk
     * Betinget opreator ?:
     * udtryk ? sand : falsk */
    res3 = (x + y * 3 >= y % x - 5) ? 10 : 20;

    // Selectiv kontrolstruktur
    if(x + y * 3 >= y % - 5)
        printf("Yes\n");
    else
        printf("No\n");
    
    /*
     * Binær operator
     * + er et eksempel på en binær operator,
     * da den tager 2 operander. x + y
     * 
     * Infix operator
     * Er en operator der står mellem operanter
     * 
     * Unær operator
     * Er en operator der kun tager 1 operant
     * eksempel:
     * y++
     * ++y
     * 
     * Prefix/Postfix operator
     * y++ er en postfix operator
     * ++y er en prefix operator
     * 
     * Short circuited (kortsluttet) operator
     * Eksempel på operator: && (og) og || (eller)
     */
    res4 = x + y >= 10 && x % 2 == 0;
    /* Her skal både højre og venstre side være true for at udtrykket bliver sandt
     * Dog hvis den venstre side er falsk bliver udtrykket kortsluttet
     * og udtrykket bliver falsk uden at beregne den højre side.
     */

    /* Prioritering af operatorer ???????????????????????? */


    /* Associering af operatorer
     * Postfix increment: Først udtaget værdien og derefter tælles værdien over.
     * Prefix increment: Først bliver værdien talt op hvor derefter værdien udtaget. */
    res2 = y++; // res2 = y; y++;
    res5 = ++y; // y++; res5 = y;

    /* Assignment */
    res1 = 1;
    /* Compount assignment */
    res1 += 1;
    /* Increment / decrement */
    res++; res--;

    /* Hop (jump) kommando
     * break; continue; return; goto;
     */

    scanf("%3lf %lf", &x, &y);
    /*      \_ kontrolstreng */

    date d1 = { tuesday, 8, 11, 2011 };
    date *pd = &d1; // pd er en pointer til en date struct, den er initialiseret til en bestemt pointer
    /* felter i et struct tilgåes vha. dotnotation (direkte komponentselektion) */
    d1.day = monday;
    /* indirekte komponentselektion når struct er en pointer */
    pd->day = tuesday;

    /* Adresse operator: &
    * Returnerer en pointer til det givne plads i lagret
    */
    /* Dereferencing operator: *
    * også kaldet indirection operator og er det modsatte af adresse operator
    * Den giver os den værdi som pointeren peger på
    */

    int i = 3, j = 4;
    weekday wd = tuesday, we;
    wd = i; // Implicit typekonvertering
    we = (weekday)j; // eksplicit typekonvertering
    /*     \_ typecast */

    double res6;
    res6 = log_two(10.5); // Procedurekald / funktionskald
    solveSomething(1.0, 2.0, 3.0) // Dette funktionskald er en kommando (pga void)
    /*             \_ aktuelle parametrer */
}

/* Procedure / Funktion
 * Indkapsler et antal kommandoer
 * 
 * Struktur:
 * retur-type procedure-navn(parametre) {
 *      KROP
 * }
 * 
 * Når der står void i parameterfeltet er den
 * Parameterløs. 
 */

/* double funktion (indkapser et udtryk) */
double log_two(double x) {
    return 1.0 / log(2.0) * log(X);
}
/* Kaldet af ovenstående funktion er selv et udtryk */

/* Void funktion med tre parametre */
void solveSomething(double a, double b, double c) {
/*                         \_ formel parameter */
    // Do something
}

/* Overførsel af en parameter fra kaldet til selve funktionen 
 * kaldes en parameter overførsel 
 * Sammenhænget mellem den første parameter når den bliver kaldet
 * og i funktionen kaldes parameter korrespondance.
 * 
 * Det er positionel koorespondance da det er positionerne der afgør
 * bindingerne der finder sted
 */

void solveThis(const double a, double *res) {
/*              \_ input parameter     \_ output parameter */
}