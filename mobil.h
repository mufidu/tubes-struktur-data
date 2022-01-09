#ifndef MOBIL_H_INCLUDED
#define MOBIL_H_INCLUDED

#include<iostream>
#include<string>

using namespace std;

typedef struct brand *adr_brand;
typedef struct product *adr_product;

#define name(P) (P)->name
#define next(P) (P)->next
#define product(P) (P)->product
#define country(P) (P)->country
#define price(P) (P)->price
#define type(P) (P)->type
#define first(L) (L).first
#define last(L) (L).last

struct brand {
    string name;
    string country;
    adr_brand next;
    adr_product product;
};

struct product {
    string name;
    // Up to 1 quintillion (10^18)
    unsigned long long int price;
    string type;
    adr_product next;
};

struct mobil {
    adr_brand first;
    adr_brand last;
};

adr_brand createBrand(string name, string country);
void insertParent(mobil &M, adr_brand P);
void deleteParent(mobil &M, string name);
void showParent(mobil M);
adr_brand findParent(mobil M, string name);

adr_product createProduct(string name, unsigned long long int price, string type);
void insertChild(mobil &M, adr_brand P, adr_product C);
void deleteChild(mobil &M, adr_brand P, string name);
void showChild(mobil M, adr_brand P);
adr_product findChild(mobil M, adr_brand P, string name);

void showAll(mobil M);

void createRelation(mobil &M, adr_brand P, adr_product C);
void deleteRelation(mobil &M, adr_brand P, string name);

void showMinMaxProduct(mobil M);
void showAveragePrice(mobil M);

#endif // MOBIL_H_INCLUDED
