
#include <stdio.h>
#include <string.h>
#include "assets.h"
#include "utilities.h"

/* Asset storage */
Asset assets[MAX_ASSETS];
int assetCount = 0;


/* Add Asset */
void addAsset(void)
{
    int i;

    if (assetCount >= MAX_ASSETS)
    {
        printf("Asset limit reached.\n");
        return;
    }

    assets[assetCount].id = readInt("Enter Asset ID: ");

    if (assets[assetCount].id <= 0)
    {
        printf("Invalid Asset ID. Must be a positive number.\n");
        return;
    }

    /* Check for duplicate Asset ID */
    for (i = 0; i < assetCount; i++)
    {
        if (assets[i].id == assets[assetCount].id)
        {
            printf("This Asset ID already exists.\n");
            return;
        }
    }

    printf("Enter Asset name: ");
    fgets(assets[assetCount].name, 50, stdin);
    assets[assetCount].name[strcspn(assets[assetCount].name, "\n")] = '\0';

    printf("Enter Asset type: ");
    fgets(assets[assetCount].type, 30, stdin);
    assets[assetCount].type[strcspn(assets[assetCount].type, "\n")] = '\0';

    assets[assetCount].purchaseValue = readDouble("Enter Purchase value: ");

    if (assets[assetCount].purchaseValue < 0)
    {
        printf("Purchase value cannot be negative.\n");
        return;
    }

    printf("Enter Department: ");
    fgets(assets[assetCount].department, 50, stdin);
    assets[assetCount].department[strcspn(assets[assetCount].department, "\n")] = '\0';

    printf("Enter Condition: ");
    fgets(assets[assetCount].condition, 30, stdin);
    assets[assetCount].condition[strcspn(assets[assetCount].condition, "\n")] = '\0';

    assetCount++;

    printf("Asset added successfully.\n");
}


/* Display Assets */
void displayAssets(void)
{
    int i;

    if (assetCount == 0)
    {
        printf("No assets available.\n");
        return;
    }

    for (i = 0; i < assetCount; i++)
    {
        printf("\nAsset ID: %d\n", assets[i].id);
        printf("Asset Name: %s\n", assets[i].name);
        printf("Asset Type: %s\n", assets[i].type);
        printf("Purchase Value: %.2f\n", assets[i].purchaseValue);
        printf("Department: %s\n", assets[i].department);
        printf("Condition: %s\n", assets[i].condition);
    }
}


/* Search Asset */
void searchAsset(void)
{
    int id;
    int i;
    int found = 0;

    if (assetCount == 0)
    {
        printf("No assets available to search.\n");
        return;
    }

    id = readInt("Enter Asset ID to search: ");

    for (i = 0; i < assetCount; i++)
    {
        if (assets[i].id == id)
        {
            printf("\nAsset found.\n");
            printf("Asset ID: %d\n", assets[i].id);
            printf("Asset Name: %s\n", assets[i].name);
            printf("Asset Type: %s\n", assets[i].type);
            printf("Purchase Value: %.2f\n", assets[i].purchaseValue);
            printf("Department: %s\n", assets[i].department);
            printf("Condition: %s\n", assets[i].condition);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Asset not found.\n");
    }
}


void saveAssets(void)
{
    FILE *file;
    int i;

    file = fopen("data/assets.txt", "w");

    if (file == NULL)
    {
        printf("Error opening assets file for saving.\n");
        return;
    }

    for (i = 0; i < assetCount; i++)
    {
        fprintf(file, "%d|%s|%s|%.2f|%s|%s\n",
                assets[i].id,
                assets[i].name,
                assets[i].type,
                assets[i].purchaseValue,
                assets[i].department,
                assets[i].condition);
    }

    fclose(file);

    printf("Assets saved successfully.\n");
}


void loadAssets(void)
{
    FILE *file;
    int count = 0;

    file = fopen("data/assets.txt", "r");

    if (file == NULL)
    {
        printf("No saved asset file found.\n");
        return;
    }

    while (count < MAX_ASSETS &&
           fscanf(file, "%d|%49[^|]|%29[^|]|%lf|%49[^|]|%29[^\n]\n",
                  &assets[count].id,
                  assets[count].name,
                  assets[count].type,
                  &assets[count].purchaseValue,
                  assets[count].department,
                  assets[count].condition) == 6)
    {
        count++;
    }

    assetCount = count;

    fclose(file);

    printf("%d asset record(s) loaded successfully.\n", assetCount);
}

/* Save assets to a binary file */
void saveAssetsBinary(void)
{
    FILE *file;

    file = fopen("data/assets.bin", "wb");

    if (file == NULL)
    {
        printf("Error opening binary asset file for saving.\n");
        return;
    }

    if (fwrite(&assetCount, sizeof(int), 1, file) != 1)
    {
        printf("Error saving asset count to binary file.\n");
        fclose(file);
        return;
    }

    if (fwrite(assets, sizeof(Asset), assetCount, file) != (size_t)assetCount)
    {
        printf("Error saving asset records to binary file.\n");
        fclose(file);
        return;
    }

    fclose(file);

    printf("Assets saved to binary file successfully.\n");
}

/* Load assets from a binary file */
void loadAssetsBinary(void)
{
    FILE *file;
    int count;

    file = fopen("data/assets.bin", "rb");

    if (file == NULL)
    {
        printf("No binary asset file found.\n");
        return;
    }

    if (fread(&count, sizeof(int), 1, file) != 1)
    {
        printf("Error reading asset count from binary file.\n");
        fclose(file);
        return;
    }

    if (count < 0 || count > MAX_ASSETS)
    {
        printf("Invalid asset count in binary file.\n");
        fclose(file);
        return;
    }

    if (fread(assets, sizeof(Asset), count, file) != (size_t)count)
    {
        printf("Error reading asset records from binary file.\n");
        fclose(file);
        return;
    }

    assetCount = count;

    fclose(file);

    printf("%d asset record(s) loaded from binary file successfully.\n", assetCount);
}