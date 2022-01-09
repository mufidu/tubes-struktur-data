#include "mobil.h"

using namespace std;

int main()
{
    mobil m;

    m.first = NULL;
    m.last = NULL;

    cout << "Masukkan jumlah brand: ";
    int jumlahBrand;
    cin >> jumlahBrand;
    cout << endl;

    for (int i = 0; i < jumlahBrand; i++)
    {
        cout << "=================================================\n\n";
        string name, country;
        cout << "Masukkan nama brand ke-" << i + 1 << ": ";
        getline(cin>>ws, name);
        cout << "Masukkan negara brand: ";
        getline(cin>>ws, country);

        adr_brand P = createBrand(name, country);
        insertParent(m, P);
        cout << endl;

        cout << "Masukkan jumlah produk: ";
        int jumlahProduct;
        cin >> jumlahProduct;
        cout << endl;
        for (int j = 0; j < jumlahProduct; j++)
        {
            string name, type;
            unsigned long long int price;
            cout << "Masukkan nama produk ke-" << j + 1 << ": ";
            getline(cin>>ws, name);
            cout << "Masukkan harga produk: ";
            cin >> price;
            cout << "Masukkan tipe produk: ";
            getline(cin>>ws, type);
            cout << endl;

            adr_product C = createProduct(name, price, type);
            insertChild(m, P, C);
        }
    }
    cout << endl;

    showParent(m);
    showAll(m);
    showMinMaxProduct(m);
    showAveragePrice(m);

    cout << "=================================================\n\n";
    cout << "Silahkan hapus brand yang tidak diinginkan!\n";
    cout << "Ada brand yang ingin dihapus? (y/n): ";
    char jawab;
    cin >> jawab;
    while (jawab == 'y')
    {
        cout << "Masukkan nama brand yang ingin dihapus: ";
        string name;
        getline(cin>>ws, name);
        deleteParent(m, name);
        cout << "Ada lagi brand yang ingin dihapus? (y/n): ";
        cin >> jawab;
    }

    cout << "\n=================================================\n\n";
    cout << "Silahkan hapus produk yang tidak diinginkan!\n";
    adr_brand P = first(m);
    while (P != NULL)
    {
        adr_product C = product(P);
        if (C == NULL)
        {
            break;
        }
        
        // sebut nama produk dan brandnya
        // tanya apakah ada produk dari brand tersebut yang ingin dihapus
        // jika ya, minta nama produk yang ingin dihapus
        // jika tidak, lanjut ke brand berikutnya
        // jika ada produk yang ingin dihapus, hapus produk tersebut

        cout << "\nBrand " << name(P) << " memiliki produk berikut: \n";
        while (C != NULL)
        {
            cout << "Nama produk: " << name(C) << endl;
            cout << "Harga produk: " << price(C) << endl;
            cout << "Tipe produk: " << type(C) << endl << endl;
            C = next(C);
        }
        cout << "Ada produk yang ingin dihapus? (y/n): ";
        cin >> jawab;
        while (jawab == 'y')
        {
            cout << "Masukkan nama produk yang ingin dihapus: ";
            string name;
            getline(cin>>ws, name);
            deleteChild(m, P, name);
            cout << "Ada lagi produk yang ingin dihapus? (y/n): ";
            cin >> jawab;
        }
        P = next(P);
    }

    cout << "\n=================================================\n\n";
    cout << "Brand dan produk yang tersisa:\n";
    showAll(m);
    cout << "=================================================\n\n";
    cout << "Program selesai!\n";

    return 0;
    // Jenis Jenis Mobil
    // 1. Mobil Convertible
    // 2. Mobil Coupe
    // 3. Mobil Hatchback
    // 4. Mobil MPV
    // 5. Mobil SUV
    // 6. Mobil Sedan
    // 7. Mobil Station Wagon
    // 8. Mobil Double Cabin
    // 9. Mobil Sport
    // 10. Mobil Off Road
}
