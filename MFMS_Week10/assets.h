
#ifndef ASSETS_H
#define ASSETS_H

#define MAX_ASSETS 100

typedef struct
{
    int id;
    char name[50];
    char type[30];
    double purchaseValue;
    char department[50];
    char condition[30];

} Asset;

/* Asset storage */
extern Asset assets[MAX_ASSETS];
extern int assetCount;

/* Asset functions */
void addAsset(void);
void displayAssets(void);
void searchAsset(void);
void assetReport(void);

void saveAssets(void);
void loadAssets(void);

void saveAssetsBinary(void);
void loadAssetsBinary(void);

#endif
