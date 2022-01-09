# include "mobil.h"

adr_brand createBrand(string name, string country)
{
    // I.S. Diberikan nama brand dan negara asal brand
    // F.S. Brand baru dibuat dan direturn
    adr_brand P = new brand;
    name(P) = name;
    country(P) = country;
    next(P) = NULL;
    product(P) = NULL;
    return P;
}

void insertParent(mobil &M, adr_brand P)
{
    // I.S. Diberikan list mobil M dan brand P
    // F.S. Brand P ditambahkan ke list mobil M
    if (first(M) == NULL)
    {
        first(M) = P;
        last(M) = P;
    }
    else
    {
        next(last(M)) = P;
        last(M) = P;
    }
}

void deleteParent(mobil &M, string name)
{
    // I.S. Diberikan list mobil M dan nama brand yang akan dihapus
    // F.S. Brand yang memiliki nama yang dicari dihapus dari list mobil M
    adr_brand P = findParent(M, name);

    if (P != NULL)
    {
        if (P == first(M))
        {
            first(M) = next(P);
        }
        else
        {
            adr_brand Q = first(M);
            while (next(Q) != P)
            {
                Q = next(Q);
            }
            next(Q) = next(P);
        }
        delete P;
    }
    else 
    {
        cout << "Brand " << name << " tidak ditemukan!\n";
    }
}

adr_brand findParent(mobil M, string name)
{
    // I.S. Diberikan list mobil M dan nama brand yang akan dicari
    // F.S. Brand yang memiliki nama yang dicari direturn
    adr_brand P = first(M);
    while (P != NULL)
    {
        if (name(P) == name)
        {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void showParent(mobil M)
{
    // I.S. Diberikan list mobil M
    // F.S. Semua brand dari list mobil M ditampilkan
    adr_brand P = first(M);
    cout << "=================================================\n\n";
    cout << "Semua brand:\n\n";
    while (P != NULL)
    {
        cout << "Nama brand: " << name(P) << endl;
        cout << "Asal negara: " << country(P) << endl << endl;
        P = next(P);
    }
}

adr_product createProduct(string name, unsigned long long int price, string type)
{
    // I.S. Diberikan nama produk, harga produk, dan tipe produk
    // F.S. Produk baru dibuat dan direturn
    adr_product P = new product;
    name(P) = name;
    price(P) = price;
    type(P) = type;
    next(P) = NULL;
    return P;
}

void insertChild(mobil &M, adr_brand P, adr_product C)
{
    // I.S. Diberikan list mobil M, brand P, dan produk C
    // F.S. Produk C ditambahkan ke brand P di list mobil M
    if (product(P) == NULL)
    {
        product(P) = C;
    }
    else
    {
        adr_product Q = product(P);
        while (next(Q) != NULL)
        {
            Q = next(Q);
        }
        next(Q) = C;
    }
}

void deleteChild(mobil &M, adr_brand P, string name)
{
    // I.S. Diberikan list mobil M, brand P, dan nama produk yang akan dihapus
    // F.S. Produk yang memiliki nama yang dicari dihapus dari brand P di list mobil M
    adr_product C = findChild(M, P, name);

    if (C != NULL)
    {
        if (C == product(P))
        {
            product(P) = next(C);
        }
        else
        {
            adr_product Q = product(P);
            while (next(Q) != C)
            {
                Q = next(Q);
            }
            next(Q) = next(C);
        }

        cout << "Produk " << name << " berhasil dihapus!\n";
        delete C;

    }
    else
    {
        cout << "Produk " << name << " tidak ditemukan!" << endl;
    }
}

adr_product findChild(mobil M, adr_brand P, string name)
{
    // I.S. Diberikan list mobil M, brand P, dan nama produk yang akan dicari
    // F.S. Produk yang memiliki nama yang dicari direturn, kalau tidak ditemukan, NULL direturn
    adr_product C = product(P);
    while (C != NULL)
    {
        if (name(C) == name)
        {
            return C;
        }
        C = next(C);
    }
    return NULL;
}

void showChild(mobil M, adr_brand P)
{
    // I.S. Diberikan list mobil M, brand P
    // F.S. Semua produk dari brand P di list mobil M ditampilkan
    adr_product C = product(P);
    if (C == NULL)
    {
        cout << "Brand " << name(P) << " tidak memiliki produk!\n";
    }
    else
    {
        while (C != NULL)
        {
            cout << "\tNama produk : " << name(C) << endl;
            cout << "\tHarga produk : " << price(C) << endl;
            cout << "\tTipe produk : " << type(C) << endl << endl;
            C = next(C);
        }
    }
    
}

void createRelation(mobil &M, adr_brand P, adr_product C)
{
    // I.S. Diberikan list mobil M, brand P, dan produk C
    // F.S. Relasi brand dan produk dibuat
    insertChild(M, P, C);
}

void deleteRelation(mobil &M, adr_brand P, string name)
{
    // I.S. Diberikan list mobil M, brand P, dan produk C
    // F.S. Relasi brand dan produk dihapus
    deleteChild(M, P, name);
}

void showAll(mobil M)
{
    // I.S. Diberikan list mobil M
    // F.S. Semua brand dan produk dari list mobil M ditampilkan
    cout << "=================================================\n\n";
    cout << "Semua brand dan produknya:\n\n";
    adr_brand P = first(M);
    while (P != NULL)
    {
        cout << "Nama brand: " << name(P) << endl;
        cout << "Asal negara: " << country(P) << endl << endl;
        showChild(M, P);
        P = next(P);
    }
}

void showMinMaxProduct(mobil M)
{
    // I.S. Diberikan list mobil M
    // F.S. Semua brand dan produk dari list mobil M ditampilkan
    cout << "=================================================\n\n";
    cout << "Produk termurah dan termahal dari setiap brand:\n\n";
    adr_brand P = first(M);
    while (P != NULL)
    {
        cout << "Nama brand: " << name(P) << endl;
        cout << "Asal negara: " << country(P) << endl;

        if (product(P) != NULL)
        {
        adr_product C = product(P);
        adr_product min = C;
        adr_product max = C;
        while (C != NULL)
        {
            if (price(C) < price(min))
            {
                min = C;
            }
            if (price(C) > price(max))
            {
                max = C;
            }
            C = next(C);
        }
        cout << "Produk termurah: " << name(min) << endl;
        cout << "Harga: " << price(min) << endl;
        cout << "Produk termahal: " << name(max) << endl;
        cout << "Harga: " << price(max) << endl << endl;
        }
        else 
        {
            cout << "Brand "<<  name(P) << " tidak memiliki produk!\n" << endl;
        }
        P = next(P);
    }
}

void showAveragePrice(mobil M)
{
    // I.S. Diberikan list mobil M
    // F.S. Semua brand dan produk dari list mobil M ditampilkan
    cout << "=================================================\n\n";
    cout << "Rata-rata harga dari produk-produk di setiap brand:\n\n";
    adr_brand P = first(M);
    while (P != NULL)
    {
        cout << "Nama brand: " << name(P) << endl;

        if (product(P) != NULL)
        {
        adr_product C = product(P);
        unsigned long long int total = 0;
        int count = 0;
        while (C != NULL)
        {
            total += price(C);
            count++;
            C = next(C);
        }
        cout << "Rata-rata harga: " << total / count << endl << endl;
        }
        else 
        {
            cout << "Brand "<<  name(P) << " tidak memiliki produk!\n\n";
        }
        P = next(P);
    }
}
