#include <stdio.h>
#include "List.h"

typedef struct {
  char* countyName;
  char* capital;
  char* language;
  unsigned int area;
  char* currency;
  char* headState;
} Country;

static void PrintCountry(const void* pObject){
    Country * country = (Country *) pObject;
    printf("%s \n", country->countyName);
}

static bool EqualsFunctionCountry(const void* o1,const void* o2) {
    Country * country1 = (Country *) o1;
    Country * country2 = (Country *) o2;
    return country1->countyName == country2->countyName;
}

int main() {

    Country Ukranian = {"Ukranian"};
    Country Usa = {"Usa"};
    Country Jupane = {"Jupane"};
    Country rushka = {"rushka"};

    Node* list = NULL;
    CreateNode(&list, &Ukranian, sizeof(Ukranian));

    AddTermBegin(&list, &Usa, sizeof(Usa));
    AddTermEnd(list, &rushka, sizeof(rushka));

    AddTermTag(list, EqualsFunctionCountry, &Usa, &Jupane, sizeof(Jupane));

    DisplayList(list, PrintCountry);

    printf("-------------------------------------------------------------------- \n");

    RemoveTermBegin(&list);
    RemoveTermEnd(&list);
    RemoveTermTag(&list, EqualsFunctionCountry, &Jupane);

    DisplayList(list, PrintCountry);
    FreeList(&list);

    printf("Glory to \n");
    printf("Glory to...Ukranian");
    return 0;
}
